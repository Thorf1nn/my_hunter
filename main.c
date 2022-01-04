/*
** EPITECH PROJECT, 2021
** bs_initcsfml
** File description:
** main.c
*/

#include "hunter.h"

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0) {
            helping();
            return 0;
        }
    }
    game_t *game = create_game((sfVideoMode){1920, 1080, 32}, "my_hunter");
    Base_Structs(game);
    game->vitesse = (sfVector2f){4, 0};
    game->clock = sfClock_create();
    create_texture(game);
    while (sfRenderWindow_isOpen(game->window)) {
        create_time(game);
        analyse_events(game);
        end_window(game);
    }
    destroy_game(game);
    return 0;
}

void helping(void)
{
    my_putstr(" ''' Welcome to Bird Hunter : '''\n \n");
    my_putstr("To play enter : ./my_hunter \n \n");
    my_putstr("Controls : \n");
    my_putstr("          [MOUSE CLICK] -> kill.\n");
    my_putstr("          [ESCAPE] -> quit.\n");
}
