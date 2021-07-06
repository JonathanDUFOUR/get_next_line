/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:50:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/06 12:51:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ELEM_H
# define T_ELEM_H

typedef struct s_elem	t_elem;

struct s_elem
{
	int		fd;
	char	*rest;
	t_elem	*next;
};

#endif
