/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:10:59 by ego               #+#    #+#             */
/*   Updated: 2025/02/11 19:23:52 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Prints a character into given file descriptor.
 * 
 * @param c Character to be printed.
 * @param fd File descriptor.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

/**
 * @brief Prints a string into given file descriptor.
 * 
 * @param c Character to be printed.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(const char *s, int fd)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
		write(fd, s, len);
	}
	return ;
}

/**
 * @brief Prints a number into given file descriptor.
 * 
 * @param c Character to be printed.
 * @param fd File descriptor.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	ft_putchar_fd('0' + n, fd);
	return ;
}

// int	put_help_message(void)
// {
// 	ft_putstr_fd(HELP1, STDERR_FILENO);
// 	ft_putstr_fd(HELP2, STDERR_FILENO);
// 	return (1);
// }
