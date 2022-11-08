/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/08 15:38:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "type/t_fd_lst.h"

int		indexof(char const *s, char const c);
char	*gnl_concat(char const *s1, char const *s2, int n);
int		get_fd_line(int const fd, char **line, char **rest);

static t_fd_lst	*get_fd_lst(void)
{
	static t_fd_lst	lst = {NULL, NULL, 0LU};

	return (&lst);
}

bool	gnl_fd_del(int fd)
{
	t_fd_lst *const	lst = get_fd_lst();
	t_fd			*curr;
	t_fd			*prev;

	curr = lst->head;
	prev = NULL;
	while (curr && curr->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (false);
	if (prev)
		prev->next = curr->next;
	else
		lst->head = curr->next;
	if (curr == lst->tail)
		lst->tail = prev;
	--lst->size;
	free(curr->rest);
	free(curr);
	return (true);
}

void	gnl_clear(void)
{
	t_fd_lst *const	lst = get_fd_lst();
	t_fd			*next;

	while (lst->head)
	{
		next = lst->head->next;
		free(lst->head->rest);
		free(lst->head);
		lst->head = next;
	}
	lst->size = 0;
	lst->tail = NULL;
}

int	get_next_line(int fd, char **line)
{
	t_fd_lst *const	lst = get_fd_lst();
	t_fd			*curr;
	int				ret;

	curr = lst->head;
	while (curr && curr->fd != fd)
		curr = curr->next;
	if (!curr)
	{
		curr = malloc(sizeof(t_fd));
		if (!curr)
			return (-1);
		curr->fd = fd;
		curr->rest = NULL;
		curr->next = lst->head;
		if (!lst->tail)
			lst->tail = curr;
		lst->head = curr;
		++lst->size;
	}
	ret = get_fd_line(curr->fd, line, &curr->rest);
	if (ret <= 0)
		gnl_fd_del(curr->fd);
	return (ret);
}
