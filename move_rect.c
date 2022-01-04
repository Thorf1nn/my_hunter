/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** move_rect.c
*/

#include "hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}
