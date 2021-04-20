/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 01:57:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*gnl_strchr(char const *s, char const c)
{
	while (*s && *s != c)
		++s;
	if (*s == c)
		return (s);
	return (NULL);
}

char	*gnl_strdup(char const *s)
{
	char	*output;
	char	*p;

	if (!s)
		return (NULL);
	output = malloc((gnl_strchr(s, 0) - s) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*s)
		*p++ = *s++;
	*p = 0;
	return (output);
}

char	*gnl_strjoin(char const *line, char const *buff)
{
	char	*output;
	char	*p;

	if (!line && !buff)
		return (NULL);
	if (!line)
		return (gnl_strdup(buff));
	if (!buff)
		return (gnl_strdup(line));
	output = malloc((gnl_strchr(line, 0) - line
				+ gnl_strchr(buff, 0) - buff + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*line)
		*p++ = *line++;
	while (*buff)
		*p++ = *buff++;
	*p = 0;
	return (output);
}

void	gnl_free_n_set_ret(t_ctx *ctx, int ret)
{
	free(ctx->buff);
	ctx->buff = NULL;
	ctx->ret = ret;
}
