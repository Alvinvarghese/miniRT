/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:19:56 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/17 13:40:38 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/elements.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    (void)argc;
    (void)argv;

    mlx = initialize_mlx();
    win = create_window(mlx, 800, 600, "miniRT");

    initialize_and_render(mlx, win);

    setup_mlx_hooks_and_loop(mlx, win);

    return (0);
}