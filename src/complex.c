/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:35:23 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 14:47:20 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Computes the modulus squared of a complex number.
 * 
 * @param z The complex number.
 * 
 * @return The modulus squared.
 */
double	modulus_squared(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}

/**
 * @brief Computes the addition of two complex numbers.
 * 
 * @param z1 The first complex number.
 * @param z2 The second complex number.
 * 
 * @return The complex number that is the addition of z1 and z2.
 */
t_complex	addition(t_complex z1, t_complex z2)
{
	t_complex	add;

	add.x = z1.x + z2.x;
	add.y = z1.y + z2.y;
	return (add);
}

/**
 * @brief Computes the substraction of two complex numbers.
 * 
 * @param z1 The first complex number.
 * @param z2 The second complex number.
 * 
 * @return The complex number that is the substraction of z1 by z2.
 */
t_complex	substraction(t_complex z1, t_complex z2)
{
	t_complex	sub;

	sub.x = z1.x - z2.x;
	sub.y = z1.y - z2.y;
	return (sub);
}

/**
 * @brief Computes the multiplication of two complex numbers.
 * 
 * @param z1 The first complex number.
 * @param z2 The second complex number.
 * 
 * @return The complex number that is the multiplication of z1 by z2.
 */
t_complex	multiplication(t_complex z1, t_complex z2)
{
	t_complex	mult;

	mult.x = z1.x * z2.x - z1.y * z2.y;
	mult.y = z1.x * z2.y + z2.x * z1.y;
	return (mult);
}
