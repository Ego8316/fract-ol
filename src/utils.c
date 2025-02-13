/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:55:46 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:07:20 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Compares the first n bytes of the two strings s1 and s2.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @param n The number of bytes to compare.
 * 
 * @return - 0 if the first n bytes of both strings are equal,
 * a signed value otherwise.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff)
			return (diff);
		i++;
	}
	return (0);
}

/**
 *	@brief Exits the program cleanly with given exit code
 *			after freeing the fractal structure.
 *
 *	@param f Pointer to the fractal structure.
 *	@param msg Message to be printed.
 *	@param exit_code Exit code.
 */
void	clean_exit(t_fractal *f, char *msg, int exit_code)
{
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (!f)
		exit(exit_code);
	if (f->image)
		mlx_destroy_image(f->mlx, f->image);
	if (f->window)
		mlx_destroy_window(f->mlx, f->window);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}
