/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 21:42:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	gnl_parse(int fd, char **line, t_ctx *ctx)
{
	while (ctx->ret > 0 && !ctx->residu)
	{
		ctx->ret = read(fd, ctx->buff, BUFFER_SIZE);
		if (ctx->ret == ERROR)
			gnl_free_n_set_ret(ctx, ERROR);
		ctx->buff[ctx->ret] = 0;
		ctx->residu = gnl_strchr(ctx->buff, '\n');
		if (ctx->residu)
		{
			++ctx->residu;
			ctx->ret = LINE_READ;
			ctx->new_fd = false;
		}
		ctx->dent = *line;
		*line = gnl_strjoin(*line, ctx->buff);
		free(ctx->dent);
	}
	if (!ctx->ret)
	{
		ctx->new_fd = true;
		gnl_free_n_set_ret(ctx, EOF_REACHED);
	}
}

int	get_next_line(int fd, char **line)
{
	static t_ctx	ctx = {true, NULL, NULL, NULL, 42};

	if (!ctx.buff)
		ctx.buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ctx.buff)
		return (ERROR);
	*line = NULL;
	if (ctx.new_fd == true)
		ctx.ret = 42;
	else
	{
		*line = gnl_strjoin(*line, ctx.residu);
		ctx.residu = gnl_strchr(ctx.residu, '\n');
		if (ctx.residu)
		{
			++ctx.residu;
			ctx.ret = LINE_READ;
		}
	}
	gnl_parse(fd, line, &ctx);
	return (ctx.ret);
}
