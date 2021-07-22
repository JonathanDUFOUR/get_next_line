/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fd_lst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:48:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 01:47:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FD_LST_H
# define T_FD_LST_H

# include <string.h>
# include "t_fd.h"

typedef struct s_fd_lst	t_fd_lst;

struct s_fd_lst
{
	t_fd	*head;
	t_fd	*tail;
	size_t	size;
};

#endif
