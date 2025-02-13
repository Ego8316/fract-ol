/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:55:46 by ego               #+#    #+#             */
/*   Updated: 2025/02/13 20:24:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Compares the two strings s1 and s2.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * 
 * @return - 0 if both strings are equal, 1 otherwise.
 */
int	ft_strcmp(char *s1, char *s2)
{
	int		diff;
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Compares the string s to the three other strings.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @param s3 Pointer to the third string.
 * @param s Pointer to the string to be compared with others.
 * 
 * @return - 0 if the string s is not equal to any of the others, 1 otherwise.
 */
int	ft_strscmp(char *s1, char *s2, char *s3, char *s)
{
	return (ft_strcmp(s1, s) & ft_strcmp(s2, s) & ft_strcmp(s3, s));
}

/**
 * @brief Computes the absolute value of a double.
 * 
 * @param x Number whose absolute value is to be computed.
 * 
 * @return The absolute value.
 */
double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
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
