/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:54:50 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:06:17 by ego              ###   ########.fr       */
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
static void	translation(t_fractal *f, char d)
{
	double	shift;

	shift = 0.1 / f->zoom;
	if (d == 'U')
	{
		f->min.y -= shift;
		f->max.y -= shift;
	}
	else if (d == 'D')
	{
		f->min.y += shift;
		f->max.y += shift;
	}
	else if (d == 'R')
	{
		f->min.x += shift;
		f->max.x += shift;
	}
	else if (d == 'L')
	{
		f->min.x -= shift;
		f->max.x -= shift;
	}
	return ;
}

/**
 * @brief Converts the mouse position into complex coordinates
 * to compute the new center, height and width of the view.
 * Updates the ranges of the view accordingly and updates the
 * view's zoom of the fractal structure. If the zoom is already
 * below one, only updates it if the ratio is greater than one
 * and does not change the view to avoid zooming out purposelessly.
 * 
 * @param f Pointer to the fractal structure.
 * @param x Mouse x coordinate.
 * @param y Mouse y coordinate.
 * @param ratio Zoom ratio. If greater than one, zooms in.
 * Zooms out otherwise.
 */
static void	zoom(t_fractal *f, int x, int y, double ratio)
{
	double		new_width;
	double		new_height;
	t_complex	new_center;

	if (f->zoom >= 1.0)
	{
		new_width = f->max.x - f->min.x;
		new_height = f->max.y - f->min.y;
		new_center.x = f->min.x + (double)x * (f->max.x - f->min.x) / WIDTH;
		new_center.y = f->min.y + (double)y * (f->max.y - f->min.y) / HEIGHT;
		f->min.x = new_center.x - new_width / (2 * ratio);
		f->max.x = new_center.x + new_width / (2 * ratio);
		f->min.y = new_center.y - new_height / (2 * ratio);
		f->max.y = new_center.y + new_height / (2 * ratio);
		f->zoom *= ratio;
	}
	if (f->zoom < 1 && ratio > 1)
	{
		f->zoom = 1.0;
		zoom(f, x, y, ratio);
	}
}

/**
 * @brief Links keycodes to different events.
 * 	- ESC: exits the program cleanly.
 * 	- W: moves the fractal up.
 * 	- S: moves the fractal down.
 * 	- A: moves the fractal left.
 * 	- D: moves the fractal right.
 * 	- UP: moves the fractal view up.
 * 	- DOWN: moves the fractal view down.
 * 	- LEFT: moves the fractal view left.
 * 	- RIGHT: moves the fractal view right.
 * 	- R: resets the fractal view.
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
 * 	- MOUSE_WHEEL_UP: zooms in.
 * 	- MOUSE_WHEEL_DOWN: zooms out.
 * 
 * @param mouse_code Mouse code corresponding to the action.
 * @param x Mouse x coordinate.
 * @param y Mouse y coordinate.
 * @param f Pointer to the fractal structure.
 * 
 * @return 0.
 */
int	mouse_hook(int mouse_code, int x, int y, t_fractal *f)
{
	if (mouse_code == MOUSE_WHEEL_UP)
		zoom(f, x, y, 1.2);
	if (mouse_code == MOUSE_WHEEL_DOWN)
		zoom(f, x, y, 0.7);
	render_fractal(f);
	return (0);
}
