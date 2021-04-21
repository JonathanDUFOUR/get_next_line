/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 20:21:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	get_from_new_fd(int fd, char **line, t_ctx *ctx)
{
	ctx->ret = 1;
	while (ctx->ret > 0 && !ctx->residu)
	{
		ctx->ret = read(fd, ctx->buff, BUFFER_SIZE);
		if (ctx->ret == ERROR)
			gnl_free_n_set_ret(ctx, ERROR);
		ctx->buff[ctx->ret] = 0;
		printf("buff   == \"%s\"\n", ctx->buff);
		ctx->residu = gnl_strchr(ctx->buff, '\n');
		if (ctx->residu)
		{
			++ctx->residu;
			printf("residu == \"%s\"\n", ctx->residu);
			ctx->ret = LINE_READ;
			ctx->new_fd = false;
		}
		ctx->dent = *line;
		*line = gnl_strjoin(*line, ctx->buff);
		printf("*line == \"%s\"\n", *line);
		free(ctx->dent);
	}
	if (!ctx->ret)
		gnl_free_n_set_ret(ctx, EOF_REACHED);
}

static void	get_from_known_fd(int fd, char **line, t_ctx *ctx)
{
	free(*line);
	*line = NULL;
	*line = gnl_strjoin(*line, ctx->residu);
	ctx->residu = gnl_strchr(ctx->residu, '\n');
	if (ctx->residu)
	{
		++ctx->residu;
		ctx->ret = LINE_READ;
	}
	ctx->dent = *line;
	*line = gnl_strjoin(*line, ctx->buff);
	free(ctx->dent);
	gnl_free_n_set_ret(ctx, EOF_REACHED);
}

int	get_next_line(int fd, char **line)
{
	static t_ctx	ctx = {true, NULL, NULL, NULL, 42};

	if (!ctx.buff)
		ctx.buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ctx.buff)
		return (ERROR);
	if (ctx.new_fd == true)
	{
		get_from_new_fd(fd, line, &ctx);
	}
	else
	{
		get_from_known_fd(fd, line, &ctx);
	}
	return (ctx.ret);
}
