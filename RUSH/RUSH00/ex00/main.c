/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:16:33 by vafavard          #+#    #+#             */
/*   Updated: 2025/02/27 06:43:11 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int max_x, int max_y);
void	ft_putchar(char c);
void	ft_print(int max_x, int max_y, int x, int y);
void	check_values(int max_x, int max_y);

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	j;
	int	resultat;

	j = 0;
	resultat = 0;
	while (str[j])
	{
		resultat = resultat * 10;
		resultat += str[j] - 48;
		j++;
	}
	return (resultat);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		return (1);
	if (!check_str(argv[1]) || !check_str(argv[2]))
		return (1);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}

/*
int	main(void)
{
	rush(5, 5);
	return (0);
}*/
