/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** analyse_event.c
*/

#include "hunter.h"

void analyse_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            manage_mouse_click(game->window, game);
        if (game->event.type == sfEvtClosed)
            close_window(game);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code
        == sfKeyEscape)
            close_window(game);
    }
}

void end_window(game_t *game)
{
    sfSprite_setPosition(game->sprite, game->pos);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    sfRenderWindow_display(game->window);
}
