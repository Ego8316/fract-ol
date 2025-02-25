/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:31:23 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 02:28:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Creates the fire color palette which consists in
 * red, orange, yellow and white.
 * 
 * @return The allocated fire palette, NULL if an allocation fails.
 */
static t_palette	*get_fire_palette(void)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette));
	if (!palette)
		return (NULL);
	palette->colors = (t_color *)malloc(4 * sizeof(t_color));
	if (!palette->colors)
	{
		free(palette);
		return (NULL);
	}
	palette->colors[0] = (t_color){255, 0, 0};
	palette->colors[1] = (t_color){255, 165, 0};
	palette->colors[2] = (t_color){255, 255, 0};
	palette->colors[3] = (t_color){255, 255, 255};
	return (palette);
}

/**
 * @brief Creates the ocean color palette which consists in
 * deep blue, turquoise, sea green and light aqua.
 * 
 * @return The allocated ocean palette, NULL if an allocation fails.
 */
static t_palette	*get_ocean_palette(void)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette));
	if (!palette)
		return (NULL);
	palette->colors = (t_color *)malloc(4 * sizeof(t_color));
	if (!palette->colors)
	{
		free(palette);
		return (NULL);
	}
	palette->colors[0] = (t_color){0, 30, 150};
	palette->colors[1] = (t_color){0, 200, 200};
	palette->colors[2] = (t_color){0, 128, 128};
	palette->colors[3] = (t_color){173, 216, 230};
	return (palette);
}

/**
 * @brief Creates the cyberpunk color palette which consists in
 * neon magenta, electric blue, deep purple and neon green.
 * 
 * @return The allocated cyberpunk palette, NULL if an allocation fails.
 */
static t_palette	*get_cyberpunk_palette(void)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette));
	if (!palette)
		return (NULL);
	palette->colors = (t_color *)malloc(4 * sizeof(t_color));
	if (!palette->colors)
	{
		free(palette);
		return (NULL);
	}
	palette->colors[0] = (t_color){255, 0, 150};
	palette->colors[1] = (t_color){0, 255, 255};
	palette->colors[2] = (t_color){75, 0, 130};
	palette->colors[3] = (t_color){0, 255, 100};
	return (palette);
}

/**
 * @brief Creates the psychedelic color palette which consists in
 * electric blue, neon pink, lime green and bright yellow.
 * 
 * @return The allocated psychedelic palette, NULL if an allocation fails.
 */
static t_palette	*get_psychedelic_palette(void)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette));
	if (!palette)
		return (NULL);
	palette->colors = (t_color *)malloc(4 * sizeof(t_color));
	if (!palette->colors)
	{
		free(palette);
		return (NULL);
	}
	palette->colors[0] = (t_color){255, 0, 255};
	palette->colors[1] = (t_color){0, 255, 255};
	palette->colors[2] = (t_color){0, 255, 0};
	palette->colors[3] = (t_color){255, 255, 0};
	return (palette);
}

/**
 * @brief Creates the four arrays of colors corresponding to each palette,
 * links them between them and puts the fire palette as the default one
 * for the fractal structure.
 * 
 * @param f Pointer to the fractal structure.
 * 
 * @return 0 if allocation fails, 1 otherwise.
 */
int	init_palette(t_fractal *f)
{
	t_palette	*fire;
	t_palette	*ocean;
	t_palette	*cyberpunk;
	t_palette	*psychedelic;

	f->palette = NULL;
	fire = get_fire_palette();
	ocean = get_ocean_palette();
	cyberpunk = get_cyberpunk_palette();
	psychedelic = get_psychedelic_palette();
	if (!fire || !ocean || !cyberpunk || !psychedelic)
		return (free_pals(fire, ocean, cyberpunk, psychedelic));
	fire->next = ocean;
	fire->prev = psychedelic;
	ocean->next = cyberpunk;
	ocean->prev = fire;
	cyberpunk->next = psychedelic;
	cyberpunk->prev = ocean;
	psychedelic->next = fire;
	psychedelic->prev = cyberpunk;
	f->palette = fire;
	return (1);
}
