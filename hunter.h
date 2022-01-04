/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-luca.orelli
** File description:
** hunter.h
*/

#ifndef HUNTER_H_
#define HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>

typedef struct game_s
{
    sfEvent event;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f vitesse;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture* background;
    sfTexture* texture;
    sfSprite *sprite;
    sfSprite *sprite2;
    float second;
    sfClock *clock;
    sfTime time;
    sfMusic *music;

} game_t;

int my_strcmp(char const *s1, char const *s2);
int my_putstr(char *str);
int my_putchar(char c);
void manage_mouse_click(sfRenderWindow *window, game_t *game);
void close_window(game_t *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void destroy_game(game_t *game);
void analyse_events(game_t *game);
void create_texture(game_t *game);
void create_time(game_t *game);
void end_window(game_t *game);
game_t *Base_Structs(game_t *game);
game_t *create_game(sfVideoMode mode, char const *title);
void helping(void);

#endif
