/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:13:14 by abarchan          #+#    #+#             */
/*   Updated: 2025/03/02 23:27:51 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initgrille(int grille[4][4]);
void	printgrille(int grille[4][4]);
int		solve(int grille[4][4], int pov[16], int pos);

int	*read_input(char *str, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && i < 31 && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (!str[i + 1] || str[i + 1] == ' ')
			{
				numbers[j] = str[i] - '0';
				j++;
			}
		}
		else if (str[i] != ' ')
			return (numbers[0] = -1, numbers);
		i++;
	}
	if (j != 16 || str[i])
		numbers[0] = -1;
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	grille[4][4];
	int	pov[16];
	int	valid;

	if (argc != 2)
		return (1);
	read_input(argv[1], pov);
	initgrille(grille);
	valid = solve(grille, pov, 0);
	if (!valid)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	printgrille(grille);
	return (0);
}
