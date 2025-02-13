/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:10:59 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:25:32 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

// int	put_help_message(void)
// {
// 	ft_putstr_fd(HELP1, STDERR_FILENO);
// 	ft_putstr_fd(HELP2, STDERR_FILENO);
// 	return (1);
// }
