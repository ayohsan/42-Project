/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:57:45 by abarchan          #+#    #+#             */
/*   Updated: 2025/03/02 22:42:48 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*revrow(int row[4])
{
	int	*new_tab;

	new_tab = malloc(4 * sizeof(int));
	new_tab[0] = row[3];
	new_tab[1] = row[2];
	new_tab[2] = row[1];
	new_tab[3] = row[0];
	return (new_tab);
}

int	isuniquerow(int row[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (row[j] == row[i] && i != j && row[j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	countvisible(int row[4])
{
	int	max_height;
	int	visible;
	int	i;

	max_height = 0;
	i = 0;
	visible = 0;
	while (i < 4)
	{
		if (max_height < row[i])
		{
			visible++;
			max_height = row[i];
		}
		i++;
	}
	return (visible);
}

int	isrowfull(int row[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (row[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
