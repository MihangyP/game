#include "game.h"

int	main(void) {
	Display *display;
	Window window;
	display = XOpenDisplay(NULL);
	if (!display) {
		fprintf(stderr, "Error: cannot connect to X server\n");
		return (1);
	}
	int background_color = 0x181818;
	window = XCreateSimpleWindow(display, DefaultRootWindow(display),
			0, 0,
			W_WIDTH, W_HEIGHT,
			0,
			0, background_color);
	XSelectInput(display, window, ExposureMask | KeyPressMask | KeyReleaseMask);
	XMapWindow(display, window);
	while (1) {
		XEvent event;
		XNextEvent(display, &event);
		if (event.type == KeyPress) {
			if (event.xkey.keycode == 0x09) {
				break ;
			}
		}
	}
	XFlush(display);
	XCloseDisplay(display);
	return (0);
}
