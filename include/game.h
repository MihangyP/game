#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define W_WIDTH 800
# define W_HEIGHT 600
# define K_w 0x19
# define K_s 0x27
# define K_a 0x26
# define K_d 0x28

typedef struct {
	int	x;
	int y;
}	Point;

#endif //GAME_H
