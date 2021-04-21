/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 20:20:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*gnl_strchr(char *s, char c)
{
	while (*s && *s != c)
		++s;
	if (*s == c)
		return (s);
	return (NULL);
}

char	*gnl_strdup(char *s)
{
	char	*output;
	char	*p;

	if (!s)
		return (NULL);
	p = gnl_strchr(s, '\n');
	if (p)
		output = malloc((p - s + 1) * sizeof(char));
	else
		output = malloc((gnl_strchr(s, 0) - s + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*s && *s != '\n')
		*p++ = *s++;
	*p = 0;
	return (output);
}

char	*gnl_strjoin(char *line, char *buff)
{
	char	*output;
	char	*p;

	if (!line && !buff)
		return (NULL);
	if (!line)
		return (gnl_strdup(buff));
	if (!buff)
		return (gnl_strdup(line));
	p = gnl_strchr(buff, '\n');
	if (p)
		output = malloc((gnl_strchr(line, 0) - line
					+ p - buff + 1) * sizeof(char));
	else
		output = malloc((gnl_strchr(line, 0) - line
					+ gnl_strchr(buff, 0) - buff + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*line)
		*p++ = *line++;
	while (*buff && *buff != '\n')
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
