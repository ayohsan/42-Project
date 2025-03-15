#include <stdlib.h>
#include <unistd.h>

struct s_carte {
    int hauteur;        // Nombre de lignes
    int largeur;        // Nombre de colonnes
    char vide;          // Caractère pour case vide
    char obstacle;      // Caractère pour obstacle
    char plein;         // Caractère pour le carré trouvé
    char **grille;      // Carte 2D
};

// Structure pour le carré
struct s_carre {
    int taille;         // Taille du carré
    int x;              // Position x
    int y;              // Position y
};

int lire_premiere_ligne(int fd, struct s_carte *carte)
{
    char buffer[100];
    int i = 0;
    
    while (read(fd, &buffer[i], 1) > 0 && buffer[i] != '\n')
        i++;
    
    carte->plein = buffer[i-1];
    carte->obstacle = buffer[i-2];
    carte->vide = buffer[i-3];
    carte->hauteur = 0;
    int j = 0;
    while (j < i-3)
    {
        carte->hauteur = carte->hauteur * 10 + (buffer[j] - '0');
        j++;
    }
    
    return 1;
}

char **creer_grille(int hauteur, int largeur)
{
    char **grille = malloc(sizeof(char *) * hauteur);
    int i = 0;
    
    while (i < hauteur)
    {
        grille[i] = malloc(sizeof(char) * (largeur + 1));
        i++;
    }
    
    return grille;
}

int lire_carte(int fichier, struct s_carte *carte)
{
    char c;
    int i = 0;
    int j;
    
    j = 0;
    while (read(fichier, &c, 1) > 0 && c != '\n')
    {
        carte->grille[0][j] = c;
        j++;
    }
    carte->largeur = j;
    
    i = 1;
    while (i < carte->hauteur)
    {
        j = 0;
        while (read(fichier, &c, 1) > 0 && c != '\n')
        {
            carte->grille[i][j] = c;
            j++;
        }
        i++;
    }
    
    return 1;
}

int peut_placer_carre(struct s_carte *carte, int y, int x, int taille)
{
    int i = 0;
    int j;
    
    while (i < taille)
    {
        j = 0;
        while (j < taille)
        {
            if (y + i >= carte->hauteur || x + j >= carte->largeur || 
                carte->grille[y + i][x + j] == carte->obstacle)
                return 0;
            j = j + 1;
        }
        i = i + 1;
    }
    return 1;
}

struct s_carre trouver_grand_carre(struct s_carte *carte)
{
    struct s_carre carre;
    carre.taille = 0;
    carre.x = 0;
    carre.y = 0;
    
    int y = 0;
    while (y < carte->hauteur)
    {
        int x = 0;
        while (x < carte->largeur)
        {
            int taille = 1;
            while (peut_placer_carre(carte, y, x, taille))
            {
                if (taille > carre.taille)
                {
                    carre.taille = taille;
                    carre.y = y;
                    carre.x = x;
                }
                taille = taille + 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
    
    return carre;
}

void dessiner_carre(struct s_carte *carte, struct s_carre carre)
{
    int i = 0;
    while (i < carre.taille)
    {
        int j = 0;
        while (j < carre.taille)
        {
            carte->grille[carre.y + i][carre.x + j] = carte->plein;
            j = j + 1;
        }
        i = i + 1;
    }
}

void afficher_carte(struct s_carte *carte)
{
    int i = 0;
    while (i < carte->hauteur)
    {
        write(1, carte->grille[i], carte->largeur);
        write(1, "\n", 1);
        i = i + 1;
    }
}

void liberer_grille(char **grille, int hauteur)
{
    int i = 0;
    while (i < hauteur)
    {
        free(grille[i]);
        i = i + 1;
    }
    free(grille);
}

int main()
{
    struct s_carte carte;
    struct s_carre carre;
    int fichier = 0;
    
    lire_premiere_ligne(fichier, &carte);
    
    carte.grille = creer_grille(carte.hauteur, carte.largeur);

    lire_carte(fichier, &carte);
    
    carre = trouver_grand_carre(&carte);
    
    dessiner_carre(&carte, carre);
    
    afficher_carte(&carte);
    
    liberer_grille(carte.grille, carte.hauteur);
    
    return 0;
}
