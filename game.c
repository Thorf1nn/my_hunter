/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** game.c
*/

#include "hunter.h"

game_t *Base_Structs(game_t *game)
{
    game->rect.height = 160;
    game->rect.width = 160;
    game->rect.left = 0;
    game->rect.top = 0;
    game->pos.x = 10.0;
    game->pos.y = 250.0;

    return game;
}

game_t *create_game(sfVideoMode mode, char const *title)
{
    game_t *game = malloc(sizeof(game_t));
    game->window = sfRenderWindow_create(mode, title,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 144);
    return game;
}

void destroy_game(game_t *game)
{
    sfSprite_destroy(game->sprite);
    sfSprite_destroy(game->sprite2);
    sfTexture_destroy(game->texture);
    sfTexture_destroy(game->background);
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->window);
    free(game);
}

void create_texture(game_t *game)
{
    game->background = sfTexture_createFromFile("rcs/back.jpg", NULL);
    game->texture = sfTexture_createFromFile("rcs/bird.png", NULL);
    game->music = sfMusic_createFromFile("rcs/forest.ogg");
    game->sprite = sfSprite_create();
    game->sprite2 = sfSprite_create();
    sfSprite_setTexture(game->sprite2, game->background, sfTrue);
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(game->sprite, game->rect);
    if (game->music)
        sfMusic_play(game->music);
}

void create_time(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds/100000.0;
    game->pos.x += game->vitesse.x;
    if (game->second > 1) {
        move_rect(&game->rect, 160, 1280);
        sfClock_restart(game->clock);
        sfSprite_setTextureRect(game->sprite, game->rect);
        if (game->pos.x >= 1920) {
            game->pos.x = 0;
            game->pos.y = 0;
            game->pos.y = rand() % 950;
        }
    }
}
