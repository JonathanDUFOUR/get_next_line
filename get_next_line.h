/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:52:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 20:05:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdio.h>

# define BUFFER_SIZE 20

enum	e_ret
{
	ERROR = -1,
	EOF_REACHED,
	LINE_READ
};

typedef struct s_ctx
{
	bool	new_fd;
	char	*buff;
	char	*residu;
	char	*dent;
	int		ret;
}	t_ctx;

int		get_next_line(int fd, char **line);
void	gnl_free_n_set_ret(t_ctx *ctx, int ret);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, char c);

#endif
