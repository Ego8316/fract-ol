/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:07:13 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 02:13:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Frees the four palettes only if necessary. This function is to be
 * used in case one of the three last palettes' allocation failed during
 * color palette initialisation, because they will not be accessible anymore
 * since they are not linked at this point.
 * 
 * @param f Pointer to the first palette.
 * @param o Pointer to the second palette.
 * @param c Pointer to the third palette.
 * @param p Pointer to the fourth palette.
 * 
 * @return Returns 0.
 */
int	free_pals(t_palette *f, t_palette *o, t_palette *c, t_palette *p)
{
	if (f && f->colors)
		free(f->colors);
	if (o && o->colors)
		free(o->colors);
	if (c && c->colors)
		free(c->colors);
	if (p && p->colors)
		free(p->colors);
	if (f)
		free(f);
	if (o)
		free(o);
	if (c)
		free(c);
	if (p)
		free(p);
	return (0);
}

/**
 * @brief Frees the linked list of color palettes.
 * This one is to be used in the clean exit function,
 * i.e. it is expected the linked list is indeed linked.
 * 
 * @param f Pointer to the fractal structure.
 */
void	free_color_palette(t_fractal *f)
{
	t_palette	*start;
	t_palette	*current;
	t_palette	*next;

	start = f->palette;
	current = start;
	while (current)
	{
		next = current->next;
		if (current->colors)
			free(current->colors);
		if (current)
			free(current);
		current = next;
		if (current == start)
			break ;
	}
	f->palette = NULL;
}

/**
 * @brief Frees the three maps only if necessary. This function is to be
 * used in case one of the three last maps' allocation failed during
 * color map initialisation, because they will not be accessible anymore
 * since they are not linked at this point.
 * 
 * @param l Pointer to the first map.
 * @param s Pointer to the second map.
 * @param n Pointer to the third map.
 * 
 * @return Returns 0.
 */
int	free_maps(t_map *l, t_map *s, t_map *n)
{
	if (l)
		free(l);
	if (s)
		free(s);
	if (n)
		free(n);
	return (0);
}

/**
 * @brief Frees the linked list of color maps.
 * This one is to be used in the clean exit function,
 * i.e. it is expected the linked list is indeed linked.
 * 
 * @param f Pointer to the fractal structure.
 */
void	free_color_map(t_fractal *f)
{
	t_map	*start;
	t_map	*current;
	t_map	*next;

	start = f->map;
	current = start;
	while (current)
	{
		next = current->next;
		if (current)
			free(current);
		current = next;
		if (current == start)
			break ;
	}
	f->map = NULL;
}
