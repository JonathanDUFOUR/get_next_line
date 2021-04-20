/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:52:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 01:54:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>

# define BUFFER_SIZE 4096

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
	int		ret;
}	t_ctx;

int		get_next_line(int fd, char **line);
void	gnl_free_n_set_ret(t_ctx *ctx, int ret);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif
