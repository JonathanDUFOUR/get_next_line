/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:52:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 01:53:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>

# ifndef GNL_BUFF_SIZE
#  define GNL_BUFF_SIZE 4096
# endif

int		get_next_line(int fd, char **line);
bool	gnl_fd_del(int fd);
void	gnl_clear(void);

#endif
