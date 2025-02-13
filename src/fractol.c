/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:25 by ego               #+#    #+#             */
/*   Updated: 2025/02/13 20:30:22 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Tries to convert the two given strings
 * into double numbers and assigns them to the
 * fractal structure.
 * 
 * @param cr First string corresponding the real part.
 * @param ci Second string corresponding to the imaginary part.
 * @param f Pointer to the fractal structure.
 * 
 * @return 1 if the conversion is successful, 0 otherwise.
 */
int	get_julia_value(char *cr, char *ci, t_fractal *f)
{
	t_complex	c;

	cr[0] = 0;
	ci[0] = 0;
	c.x = 2;
	c.y = 2;
	f->c = c;
	return (1);
}

/**
 * @brief Parses the argument and prints the help message in case
 * of wrong argument. Also gets Julia starting values if provided.
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
	if (!ft_strscmp(J1, J2, J3, av[1]) && (ac == 2 || ac == 4))
		return (init_set(ac, av, f, 'J'));
	else if (!ft_strscmp(M1, M2, M3, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'M'));
	else if (!ft_strscmp(B1, B2, B3, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'B'));
	else if (!ft_strscmp(N1, N2, N3, av[1]) && ac < 3)
		return (init_set(ac, av, f, 'N'));
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
