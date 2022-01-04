/*
** EPITECH PROJECT, 2017
** put
** File description:
** char
*/

#include "hunter.h"

int my_putchar(char c)
{
    write(1 , &c, 1);
    return (1);
}
