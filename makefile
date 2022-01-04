##
## EPITECH PROJECT, 2021
## bs_initcsfml
## File description:
## makefile
##

CC 				= gcc

CFLAGS 			= -W -Wall -Wextra

CPPFLAGS 		= -I/usr/local/include

LDFLAGS 		= -L/usr/local/lib -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

SRC 			= $(wildcard *.c)

OBJ			 	= $(SRC:.c=.o)

TARGET 			= my_hunter

all 			: 	$(TARGET)

$(TARGET) 		: 	$(OBJ)
				$(CC) -o $@ $^ $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			: clean
				$(RM) $(TARGET)

re				: fclean all
