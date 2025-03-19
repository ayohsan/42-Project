# 42 Piscine Projects - BSQ & Rushes

Ce repository contient les projets réalisés lors de la piscine 42 : **BSQ**, **Rush00** et **Rush01**. Ces projets ont été développés en **C** et permettent d'explorer différentes logiques d'algorithmie et de gestion d'affichage ASCII.

1. Cloner le repository :
   ```bash
   git clone https://github.com/ayohsan/42-Project.git
   cd 42-Project
   ```

2. Augmenter les permissions si nécessaire :
   ```bash
   chmod +x
   ```
   
## 🟢 BSQ (Biggest Square)

### 🔹 Description
BSQ est un programme qui permet de trouver le plus grand carré possible dans une grille contenant des obstacles. L'objectif est d'analyser une carte et de marquer la plus grande zone continue possible sans rencontrer d'obstacles.

### 📌 Compilation & Exécution
1. Compiler le programme :
   ```bash
   cc main.c -o bsq
   ```
2. Générer une carte et exécuter BSQ :
   ```bash
   ./generate_map.pl 20 20 5 | ./bsq
   ```
   - **20 20** : Taille de la grille (20x20)
   - **5** : Nombre d'obstacles

---

## 🔵 RUSH00 - Interface ASCII

### 🔹 Description
Rush00 est un projet de création d'interfaces ASCII en C. Il permet de générer des motifs ASCII à l'écran en fonction des paramètres donnés en entrée.

### 📌 Compilation & Exécution
1. Compiler le projet :
   ```bash
   cc main.c ft_putchar.c rush00.c -o rush-00
   ```
   - Remplacez `rush00.c` par `rush01.c`, `rush02.c`, etc., selon la variante souhaitée.

2. Exécuter avec des dimensions spécifiques :
   ```bash
   ./rush-00 20 20
   ```
   - **20 20** : Largeur et hauteur du motif ASCII

---

## 🔴 RUSH01 - Résolveur de Skyscrapers

### 🔹 Description
Rush01 est un programme permettant de résoudre le puzzle des **Skyscrapers** en utilisant un algorithme de **backtracking**. Le but est de placer des immeubles dans une grille en respectant les contraintes de vision données en entrée.

### 📌 Compilation & Exécution
1. Compiler le programme :
   ```bash
   cc *.c -o rush-01
   ```
2. Lancer le solveur avec des indices de vision :
   ```bash
   ./rush-01 "up1 up2 up3 up4 down1 down2 down3 down4 left1 left2 left3 left4 right1 right2 right3 right4"
   ```
   - Chaque valeur représente la visibilité depuis un bord de la grille.

---

## 💡 Remarque
Ces projets ont été réalisés dans le cadre de la **piscine 42**, et sont basés sur des algorithmes fondamentaux. Ils sont un bon entraînement pour la gestion de la mémoire, la récursivité et l'affichage structuré.

📌 **Contributions & améliorations sont les bienvenues !**

🚀 Bon coding !
