/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:05:59 by abarchan          #+#    #+#             */
/*   Updated: 2025/03/02 23:22:04 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*revrow(int row[4]);
int	isuniquerow(int row[4]);
int	countvisible(int row[4]);
int	isrowfull(int row[4]);

int	canstillberow(int row[4], int indexright, int indexleft)
{
	int	leftvisible;
	int	rightvisible;
	int	empty;
	int	i;
	int	*reversed;

	i = 0;
	empty = 0;
	while (i < 4)
	{
		if (row[i] == 0)
			empty++;
		i++;
	}
	leftvisible = countvisible(row);
	reversed = revrow(row);
	rightvisible = countvisible(reversed);
	free(reversed);
	return ((leftvisible + empty >= indexleft)
		&& (rightvisible + empty >= indexright));
}

int	isvalidrow(int row[4], int indexright, int indexleft)
{
	int	leftvisible;
	int	rightvisible;
	int	*reversed;

	if (!isuniquerow(row))
		return (0);
	if (!isrowfull(row))
		return (canstillberow(row, indexright, indexleft));
	leftvisible = countvisible(row);
	reversed = revrow(row);
	rightvisible = countvisible(reversed);
	free(reversed);
	return (leftvisible == indexleft && rightvisible == indexright);
}

int	*extractcol(int grille[4][4], int index)
{
	int	i;
	int	j;
	int	*col;

	i = 0;
	col = malloc(4 * sizeof(int));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j == index)
				col[i] = grille[i][j];
			j++;
		}
		i++;
	}
	return (col);
}

int	placenumber(int grille[4][4], int pov[16], int pos, int k)
{
	int	i;
	int	j;
	int	isvalid;
	int	*col;

	i = pos / 4;
	j = pos % 4;
	grille[i][j] = k;
	col = extractcol(grille, j);
	isvalid = isvalidrow(grille[i], pov[i + 12], pov[i + 8]);
	isvalid *= isvalidrow(col, pov[j + 4], pov[j]);
	free(col);
	grille[i][j] = 0;
	return (isvalid);
}

int	solve(int grille[4][4], int pov[16], int pos)
{
	int	i;
	int	j;
	int	k;

	if (pos == 16)
		return (1);
	i = pos / 4;
	j = pos % 4;
	if (grille[i][j] != 0)
		return (solve(grille, pov, pos + 1));
	k = 1;
	while (k < 5)
	{
		if (placenumber(grille, pov, pos, k))
		{
			grille[i][j] = k;
			if (solve(grille, pov, pos + 1))
				return (1);
			grille[i][j] = 0;
		}
		k++;
	}
	return (0);
}
