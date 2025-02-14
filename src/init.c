/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:55:28 by ego               #+#    #+#             */
/*   Updated: 2025/02/14 15:02:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Convert the two given strings
 * to double numbers and assigns them to the
 * fractal structure. If the converted values
 * are considered incorrect (either an invalid string
 * or not interesting values), returns 0.
 * 
 * @param cr First string corresponding the real part.
 * @param ci Second string corresponding to the imaginary part.
 * @param f Pointer to the fractal structure.
 * 
 * @return 1 if the conversion is successful, 0 otherwise.
 */
static int	get_julia_values(char *cr, char *ci, t_fractal *f)
{
	t_complex	c;

	c.x = ft_atof(cr);
	c.y = ft_atof(ci);
	if (ft_abs(c.x) > 1.5 || ft_abs(c.y) > 1.5 || (c.x == 0 && c.y == 0))
	{
		put_help_message();
		return (0);
	}
	f->c = c;
	return (1);
}

/**
 * @brief Initializes the set and func elements of the
 * fractal structure. For Julia, tries to get the c
 * value if two other arguments are given, sets them
 * to default values otherwise.
 * 
 * @param ac Number of arguments.
 * @param av The array of arguments.
 * @param f Pointer to the fractal structure.
 * @param set Character corresponding to the set.
 * 
 * @return 1 if the conversion for Julia was successful,
 * 0 otherwise.
 */
int	init_set(int ac, char **av, t_fractal *f, char set)
{
	if (set == 'J')
	{
		f->set = JULIA;
		f->func = julia;
		if (ac == 2)
			f->c = (t_complex){-0.745429, 0.05};
		else
			return (get_julia_values(av[2], av[3], f));
	}
	else if (set == 'M')
	{
		f->set = MANDELBROT;
		f->func = mandelbrot;
	}
	else if (set == 'B')
	{
		f->set = BURNING_SHIP;
		f->func = burning_ship;
	}
	else if (set == 'N')
	{
		f->set = NEWTON;
		f->func = newton;
	}
	return (1);
}

/**
 * @brief Sets the fractal structure to
 * default values.
 * 
 * @param f Pointer to the fractal structure.
 */
void	init_fractal(t_fractal *f)
{
	if (f->set == JULIA)
	{
		f->min = (t_complex){-1.5, -1.5};
		f->max = (t_complex){1.5, 1.5};
	}
	else if (f->set == MANDELBROT)
	{
		f->min = (t_complex){-2.0, -1.5};
		f->max = (t_complex){1.0, 1.5};
	}
	else if (f->set == BURNING_SHIP)
	{
		f->min = (t_complex){-2.0, -1.8};
		f->max = (t_complex){1.5, 0.7};
	}
	else if (f->set == NEWTON)
	{
		f->min = (t_complex){-2.0, -1.5};
		f->max = (t_complex){1.0, 1.5};
	}
	f->max_iter = 80;
	f->zoom = 1.0;
}

/**
 * @brief Initializes the fractal structure.
 * First connects to mlx, then creates a new
 * window and and a new image.
 * 
 * @param f Pointer to an empty fractal structure.
 */
void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(f, "MLX: connection to mlx failed.\n", 1);
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	if (!f->window)
		clean_exit(f, "MLX: window creation failed.\n", 1);
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image)
		clean_exit(f, "MLX: image creation failed.\n", 1);
	f->addr = mlx_get_data_addr(f->image, &f->bpp,
			&f->size_line, &f->endian);
}
