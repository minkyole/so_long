/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_custom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumoon <sumoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:35:27 by sumoon            #+#    #+#             */
/*   Updated: 2023/05/27 15:34:50 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CUSTOM_H
# define MLX_CUSTOM_H

#include "mlx.h"
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/*
** It takes mlx_ptr, but it doesn't use it.
** This function can only get Main Screen,
** you should be careful when you use multiple monitors...
*/

#endif
