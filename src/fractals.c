/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:54:32 by ego               #+#    #+#             */
/*   Updated: 2025/02/14 14:11:26 by ego              ###   ########.fr       */
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
 * @brief Checks if a complex number belongs to the Newton set.
 * 
 * @param z Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	newton(t_complex z, t_fractal *f)
{
	t_complex	c;
	int			iter;

	c.x = 0;
	c.y = 0;
	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = addition(multiplication(z, z), addition(c, f->c));
		iter++;
	}
	return (iter);
}
