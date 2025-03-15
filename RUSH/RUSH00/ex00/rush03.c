/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:32:55 by vafavard          #+#    #+#             */
/*   Updated: 2025/02/23 14:21:02 by abarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int max_x, int max_y, int x, int y)
{
	if (((y == 0 && x == 0) || (y == max_y - 1 && x == 0))
		&& max_y != 1)
		ft_putchar('A');
	else if ((y == max_y - 1 && x == max_x - 1) || (y == 0 && x == max_x - 1))
		ft_putchar('C');
	else if ((y == 0 || y == max_y - 1) && (x != 0 || x != max_x - 1))
		ft_putchar('B');
	else if ((x == 0 || x == max_x - 1) && (y != 0 || y != max_y - 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
	if (x == max_x - 1)
		ft_putchar('\n');
}

int	check_value_x(int max_x)
{
	if (max_x < 0)
		max_x *= -1;
	if (max_x > 350)
		max_x = 350;
	return (max_x);
}

int	check_value_y(int max_y)
{
	if (max_y < 0)
		max_y *= -1;
	if (max_y > 350)
		max_y = 350;
	return (max_y);
}

void	rush(int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (max_x == 0 || max_y == 0)
	{
		write (1, "ERROR NO NULL VALUE EXPECTED\n", 29);
		return ;
	}
	max_x = check_value_x(max_x);
	max_y = check_value_y(max_y);
	while (y < max_y)
	{
		while (x < max_x)
		{
			ft_print(max_x, max_y, x, y);
			x++;
		}
		x = 0;
		y += 1;
	}
}
