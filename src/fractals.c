/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:54:32 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 03:14:31 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Checks if a complex number belongs to the Julia set.
 * The c number is stocked in the fractal structure.
 * 
 * @param z Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	julia(t_complex z, t_fractal *f)
{
	int			iter;

	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = addition(multiplication(z, z), f->c);
		iter++;
	}
	return (iter);
}

/**
 * @brief Checks if a complex number belongs to the Mandelbrot set.
 * 
 * @param c Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	mandelbrot(t_complex c, t_fractal *f)
{
	t_complex	z;
	int			iter;

	z = (t_complex){0.0, 0.0};
	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = addition(multiplication(z, z), c);
		iter++;
	}
	return (iter);
}

/**
 * @brief Checks if a complex number belongs to the Burning Ship set.
 * 
 * @param c Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	burning_ship(t_complex c, t_fractal *f)
{
	t_complex	z;
	int			iter;

	z = (t_complex){0.0, 0.0};
	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = (t_complex){ft_abs(z.x), ft_abs(z.y)};
		z = addition(multiplication(z, z), c);
		iter++;
	}
	return (iter);
}

/**
 * @brief Finds to which polynom root the given complex number
 * is the closest.
 * 
 * @param z The complex number.
 * 
 * @return The root index.
 */
static int	newton_roots(t_complex z)
{
	t_complex	roots[3];
	double		min_dist;
	double		dist;
	int			root_index;
	int			i;

	roots[0] = (t_complex){1.0, 0.0};
	roots[1] = (t_complex){-0.5, sqrt(3.0) / 2.0};
	roots[2] = (t_complex){-0.5, -sqrt(3.0) / 2.0};
	root_index = 0;
	min_dist = distance(z, roots[0]);
	i = -1;
	while (++i < 3)
	{
		dist = distance(z, roots[i]);
		if (dist < min_dist)
		{
			min_dist = dist;
			root_index = i;
		}
	}
	return (root_index);
}

/**
 * @brief Checks if a complex number belongs to the Newton set.
 * Chosen Newton set is the polynom f : z -> z^3 - 1
 * 
 * @param z Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Returns the right color depending on which root the
 * point converges.
 */
int	newton(t_complex z, t_fractal *f)
{
	t_complex	minus_one;
	t_complex	fx;
	t_complex	dfx;
	int			iter;
	int			root_index;

	iter = 0;
	minus_one = (t_complex){-1.0, 0.0};
	while (iter < f->max_iter)
	{
		fx = addition(multiplication(multiplication(z, z), z), minus_one);
		dfx = multiplication((t_complex){3.0, 0.0}, multiplication(z, z));
		if ((dfx.x == 0 && dfx.y == 0) || modulus_squared(fx) < 1e-6)
			break ;
		z = addition(z, multiplication(minus_one, division(fx, dfx)));
		iter++;
	}
	root_index = newton_roots(z);
	if (root_index == 0)
		return (0xFF0000);
	else if (root_index == 1)
		return (0x00FF00);
	else
		return (0x0000FF);
}
