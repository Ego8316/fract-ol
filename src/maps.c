/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:37 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 02:49:13 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Given the color palette, does a linear interpolation
 * to get the color based on the logarithmic ratio of iter and
 * max_iter.
 * 
 * @param iter Number of iterations before divergence.
 * @param max_iter Maximum number of iterations.
 * @param colors Color set.
 * 
 * @return The interpolated color.
 */
int	linear_mapping(int iter, int max_iter, t_color *colors)
{
	t_color	color;
	int		i;
	double	t;

	if (iter == max_iter)
		return (0x000000);
	t = log((double)iter + 1) / log((double)max_iter + 1);
	i = (t > 0.33) + (t > 0.67);
	color.r = (1 - t) * (double)colors[i].r + t * (double)colors[i + 1].r;
	color.g = (1 - t) * (double)colors[i].g + t * (double)colors[i + 1].g;
	color.b = (1 - t) * (double)colors[i].b + t * (double)colors[i + 1].b;
	return (color.r << 16 | color.g << 8 | color.b);
}

/**
 * @brief Given the color palette, does a sinusoidal interpolation
 * to get the color based on the logarithmic ratio of iter and
 * max_iter.
 * 
 * @param iter Number of iterations before divergence.
 * @param max_iter Maximum number of iterations.
 * @param colors Color set.
 * 
 * @return The interpolated color.
 */
int	sinusoidal_mapping(int iter, int max_iter, t_color *colors)
{
	t_color	color;
	double	t;

	if (iter == max_iter)
		return (0x000000);
	t = log((double)iter + 1) / log((double)max_iter + 1);
	t = (1 - cos(t * M_PI)) / 2.0;
	color.r = (1 - t) * (double)colors[0].r + t * (double)colors[3].r;
	color.g = (1 - t) * (double)colors[0].g + t * (double)colors[3].g;
	color.b = (1 - t) * (double)colors[0].b + t * (double)colors[3].b;
	return (color.r << 16 | color.g << 8 | color.b);
}

/**
 * @brief Given the color palette, does a noise interpolation
 * to get the color based on the logarithmic ratio of iter and
 * max_iter.
 * 
 * @param iter Number of iterations before divergence.
 * @param max_iter Maximum number of iterations.
 * @param colors Color set.
 * 
 * @return The interpolated color.
 */
int	noise_mapping(int iter, int max_iter, t_color *colors)
{
	t_color	color;
	int		i;
	double	t;
	double	noise;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / (double)max_iter;
	noise = ((double)rand() / RAND_MAX) * 0.2 - 0.1;
	t = fmin(fmax(t + noise, 0.0), 1.0);
	i = (t > 0.33) + (t > 0.67);
	color.r = (1 - t) * (double)colors[i].r + t * (double)colors[i + 1].r;
	color.g = (1 - t) * (double)colors[i].g + t * (double)colors[i + 1].g;
	color.b = (1 - t) * (double)colors[i].b + t * (double)colors[i + 1].b;
	return (color.r << 16 | color.g << 8 | color.b);
}

/**
 * @brief Creates a linked list of functions.
 * 
 * @param f Pointer to the fractal structure.
 * 
 * @return 0 if allocation fails, 1 otherwise.
 */
int	init_map(t_fractal *f)
{
	t_map	*linear;
	t_map	*sinusoidal;
	t_map	*noise;

	f->map = NULL;
	linear = (t_map *)malloc(sizeof(t_map));
	sinusoidal = (t_map *)malloc(sizeof(t_map));
	noise = (t_map *)malloc(sizeof(t_map));
	if (!linear || !sinusoidal || !noise)
		return (free_maps(linear, sinusoidal, noise));
	linear->func = linear_mapping;
	sinusoidal->func = sinusoidal_mapping;
	noise->func = noise_mapping;
	linear->next = sinusoidal;
	linear->prev = noise;
	sinusoidal->next = noise;
	sinusoidal->prev = linear;
	noise->next = linear;
	noise->prev = sinusoidal;
	f->map = linear;
	return (1);
}
