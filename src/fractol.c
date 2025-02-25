/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:25 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 01:22:54 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Parses the argument and prints the help message in case
 * of wrong argument. Changes the data structure if the argument
 * is correct. Also gets Julia starting values if provided.
 * 
 * @param ac Number of arguments.
 * @param av The array of arguments.
 * @param f Pointer to the fractal structure.
 * 
 * @return 1 if the argument is correct, 0 otherwise.
 */
static int	parse_argument(int ac, char **av, t_fractal *f)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!av[i][0])
			return (put_help_message());
	}
	if (ac < 2 || ac > 4 || !ft_strcmp("help", av[1]))
		return (put_help_message());
	if (!ft_strscmp(J1, J2, av[1]) && (ac == 2 || ac == 4))
		return (init_set(ac, av, f, 'J'));
	else if (!ft_strscmp(M1, M2, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'M'));
	else if (!ft_strscmp(B1, B2, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'B'));
	else if (!ft_strscmp(N1, N2, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'N'));
	else
		return (put_help_message());
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
	if (!init_palette(&fractal) || !init_map(&fractal))
		clean_exit(&fractal, "malloc: allocation failed\n", 1);
	init_mlx(&fractal);
	init_fractal(&fractal);
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, CLOSE_BUTTON, 0, exit_fractal, &fractal);
	put_controls_message();
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
