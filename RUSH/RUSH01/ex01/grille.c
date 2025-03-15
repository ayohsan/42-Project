/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:11:08 by abarchan          #+#    #+#             */
/*   Updated: 2025/03/02 18:12:42 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	initgrille(int grille[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grille[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	printgrille(int grille[4][4])
{
	int		i;
	int		j;
	char	to_print;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			to_print = grille[i][j] + '0';
			write(1, &to_print, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
