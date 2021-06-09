/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/29 16:57:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		indexof(char const *s, char const c);
char	*gnl_concat(char const *s1, char const *s2, int n);
int		get_fd_line(int const fd, char **line, char **rest);

static t_lst	*get_lst(void)
{
	static t_lst	lst = {0, NULL, NULL};

	return (&lst);
}

bool	gnl_fd_del(int fd)
{
	t_lst *const	lst = get_lst();
	t_elem			*curr;
	t_elem			*prev;

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
	t_lst *const	lst = get_lst();
	t_elem			*next;

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
	t_lst *const	lst = get_lst();
	t_elem			*curr;
	int				ret;

	curr = lst->head;
	while (curr && curr->fd != fd)
		curr = curr->next;
	if (!curr)
	{
		curr = malloc(sizeof(t_elem));
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
