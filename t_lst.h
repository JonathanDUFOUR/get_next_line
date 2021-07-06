/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:48:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/06 12:51:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LST_H
# define T_LST_H

# include <string.h>
# include "t_elem.h"

typedef struct s_lst	t_lst;

struct s_lst
{
	size_t	size;
	t_elem	*head;
	t_elem	*tail;
};

#endif
