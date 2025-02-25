/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:10:59 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 01:34:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Prints a string into given file descriptor.
 * 
 * @param c Character to be printed.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(const char *s, int fd)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
		write(fd, s, len);
	}
	return ;
}

/**
 * @brief Displays the help message.
 * 
 * @return 0.
 */
int	put_help_message(void)
{
	ft_putstr_fd("========================================\n", STDOUT_FILENO);
	ft_putstr_fd("           Welcome to Fractol!\n", STDOUT_FILENO);
	ft_putstr_fd("          ✨ Explore fractals ✨\n", STDOUT_FILENO);
	ft_putstr_fd("========================================\n\n", STDOUT_FILENO);
	ft_putstr_fd("Usage: ./fractol <set>\n", STDOUT_FILENO);
	ft_putstr_fd("Available fractals:\n", STDOUT_FILENO);
	ft_putstr_fd(" - M / mandelbrot \n", STDOUT_FILENO);
	ft_putstr_fd(" - J / julia\n", STDOUT_FILENO);
	ft_putstr_fd(" - B / burning_ship\n", STDOUT_FILENO);
	ft_putstr_fd(" - N / newton\n", STDOUT_FILENO);
	ft_putstr_fd("For Julia, you may specify values for c.\n", STDOUT_FILENO);
	ft_putstr_fd("Values must be between -1.5 and 1.5.\n", STDOUT_FILENO);
	ft_putstr_fd("Example:\n", STDOUT_FILENO);
	ft_putstr_fd("\t./fractol mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("\t./fractol julia -0.7 0.27015\n", STDOUT_FILENO);
	return (0);
}

/**
 * @brief Displays the controls.
 */
void	put_controls_message(void)
{
	ft_putstr_fd("========================================\n", STDOUT_FILENO);
	ft_putstr_fd("                Controls          \n", STDOUT_FILENO);
	ft_putstr_fd("========================================\n", STDOUT_FILENO);
	ft_putstr_fd("View controls:\n", STDOUT_FILENO);
	ft_putstr_fd(" - WASD / ↑←↓→ : move up/left/down/right\n", STDOUT_FILENO);
	ft_putstr_fd(" - Mouse scroll : zoom in/out\n", STDOUT_FILENO);
	ft_putstr_fd(" - R : reset to default view\n", STDOUT_FILENO);
	ft_putstr_fd("Fractal selection:\n", STDOUT_FILENO);
	ft_putstr_fd(" - M : select Mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd(" - J : select Julia\n", STDOUT_FILENO);
	ft_putstr_fd(" - B : select Burning Ship\n", STDOUT_FILENO);
	ft_putstr_fd(" - N : select Newton\n", STDOUT_FILENO);
	ft_putstr_fd("Color selection:\n", STDOUT_FILENO);
	ft_putstr_fd(" - 1/2 : previous/next color palette\n", STDOUT_FILENO);
	ft_putstr_fd(" - 3/4 : previous/next color map\n", STDOUT_FILENO);
	ft_putstr_fd("Other commands:\n", STDOUT_FILENO);
	ft_putstr_fd(" - + / - : raise/decrease max iterations\n", STDOUT_FILENO);
	ft_putstr_fd(" - ESC : exit the program\n", STDOUT_FILENO);
}
