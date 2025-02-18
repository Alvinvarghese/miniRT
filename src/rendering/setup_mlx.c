/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:37:06 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/17 13:43:54 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/elements.h"


void *initialize_mlx(void)
{
    void *mlx = mlx_init();
    if (mlx == NULL)
    {
        fprintf(stderr, "Error initializing MLX\n");
        exit(1);
    }
    return mlx;
}

void *create_window(void *mlx, int width, int height, char *title)
{
    void *win = mlx_new_window(mlx, width, height, title);
    if (win == NULL)
    {
        fprintf(stderr, "Error creating window\n");
        mlx_destroy_display(mlx);
        free(mlx);
        exit(1);
    }
    return win;
}

void setup_mlx_hooks_and_loop(void *mlx, void *win)
{
    mlx_hook(win, 17, 0, close_window, NULL); // 17 is the event code for the close button
    mlx_key_hook(win, key_hook, NULL); // Register key hook
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
}