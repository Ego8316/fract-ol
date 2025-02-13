/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:25 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:44:32 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	put_help_message()
{
	ft_putstr_fd("Usage:\t./fractol mandelbrot\n", STDOUT_FILENO);
	return (0);
}

/**
 * @brief Parses the argument and prints the help message in case
 * of wrong argument. Also gets Julia starting values if provided.
 * 
 * @param argc Number of arguments.
 * @param argv The array of arguments.
 * @param f Pointer to the fractal structure.
 * 
 * @return 1 if the argument is correct, 0 otherwise.
 */
static int	parse_argument(int argc, char **argv, t_fractal *f)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0])
			return (put_help_message());
	}
	if (argc < 2 || argc > 4 || !ft_strncmp("help", argv[1], 5))
		return (put_help_message());
	if (!ft_strncmp("J", argv[1], 2) || !ft_strncmp(J, argv[1], 6))
	{
		f->set = JULIA;
		f->func = julia;
	}
	else if (!ft_strncmp("M", argv[1], 2) || !ft_strncmp(M, argv[1], 11))
	{
		f->set = MANDELBROT;
		f->func = mandelbrot;
	}
	else
		return (put_help_message());
	printf("%i\n", f->set);
	return (1);
}


/**
 * @brief Calls the clean exit function
 * and returns 0.
 * 
 * @param f Pointer to the fractal structure.
 * 
 * @return 0.
 */
static int	exit_fractal(t_fractal *f)
{
	clean_exit(f, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_argument(argc, argv, &fractal))
		return (1);
	init_mlx(&fractal);
	init_fractal(&fractal);
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, CLOSE_BUTTON, 0, exit_fractal, &fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
