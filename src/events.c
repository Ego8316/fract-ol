/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:54:50 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 16:50:13 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Changes values for the axis ranges
 * according to the direction given. The direction
 * indicates the movement of the view of the fractal.
 * 
 * @param f Pointer to the fractal structure.
 * @param dir Direction: 'U' for up, 'D' for down,
 * 'L' for left and 'R' for right.
 */
void	translation(t_fractal *f, char d)
{
	double	modifier;

	modifier = 0.05;
	if (d == 'U')
	{
		f->min.y -= modifier;
		f->max.y -= modifier;
	}
	else if (d == 'D')
	{
		f->min.y += modifier;
		f->max.y += modifier;
	}
	else if (d == 'R')
	{
		f->min.x += modifier;
		f->max.x += modifier;
	}
	else if (d == 'L')
	{
		f->min.x -= modifier;
		f->max.x -= modifier;
	}
	return ;
}

/**
 * @brief Links keycodes to different events.
 * 	- ESC: exits the program cleanly.
 * 	- W: moves the fractal up.
 * 	- S: moves the fractal down.
 * 	- A: moves the fractal left.
 * 	- D: moves the fractal right.
 * 	- UP: moves the fractal up.
 * 	- DOWN: moves the fractal down.
 * 	- LEFT: moves the fractal left.
 * 	- RIGHT: moves the fractal right.
 * 	- R: resets the fractal to default values.
 * 	- PLUS: raises the number of max iterations.
 * 	- MINUS: decreases the number of max iterations.
 * Rerenders the fractal afterwards.
 * 
 * @param keycode Keycode corresponding to the action.
 * @param f Pointer to the fractal structure.
 * 
 * @return 0.
 */
int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESC)
		clean_exit(f, 0, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		translation(f, 'U');
	if (keycode == KEY_S || keycode == KEY_DOWN)
		translation(f, 'D');
	if (keycode == KEY_A || keycode == KEY_LEFT)
		translation(f, 'L');
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		translation(f, 'R');
	if (keycode == KEY_R)
		init_fractal(f);
	if ((keycode == KEY_PLUS || keycode == NUMPAD_PLUS) && f->max_iter < 100)
		f->max_iter += 5;
	if ((keycode == KEY_MINUS || keycode == NUMPAD_MINUS) && f->max_iter > 10)
		f->max_iter -= 5;
	render_fractal(f);
	return (0);
}

/**
 * @brief	Links mouse codes to events.
 * 	- 
 */
// int	mouse_hook(int mouse_code, int x, int y, t_fractal *f)
// {

// 	return (0);
// }