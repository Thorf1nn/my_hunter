/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** manage_mouse_click.c
*/

#include "hunter.h"

void manage_mouse_click(sfRenderWindow *window, game_t *game)
{
    int posx = sfMouse_getPosition(window).x;
    int posy = sfMouse_getPosition(window).y;

    if (posx >= game->pos.x && posx <= game->pos.x + 160) {
        if (posy >= game->pos.y && posy <= game->pos.y + 160) {
            game->pos.x = 0;
            game->pos.y = 0;
            game->pos.y = rand() % 980;
        }
    }
}

void close_window(game_t *game)
{
    sfRenderWindow_close(game->window);
}
