#include "game.h"

void	clear_background(Display *display, Window window, GC gc) {
	int x;
	int y = 0;
	while (y < W_HEIGHT) {
		x = 0;
		while (x < W_WIDTH) {
			XDrawPoint(display, window, gc, x, y);
			++x;
		}
		++y;
	}
}

double point_distance(Point a, Point b) {
	return (sqrt(((a.x - b.x) * (a.x - b.x)) +((a.y - b.y) * (a.y - b.y))));
}

void	draw_circle(Display *display, Window window, GC gc , Point center, double radius) {
	Point	start;
	start.y = center.y - radius;

	while (start.y < center.y + radius) {
		start.x = center.x - radius;
		while (start.x < center.x + radius) {
			if (point_distance(start, center) <= radius) {
				XDrawPoint(display, window, gc, start.x, start.y);
			}
			++(start.x);
		}
		++(start.y);
	}
}

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

	int screen = DefaultScreen(display);
	GC gc = DefaultGC(display, screen);

	while (1) {
		XEvent event;
		XNextEvent(display, &event);
		if (event.type == KeyPress) {
			if (event.xkey.keycode == 0x09) {
				break ;
			}
		} 
		XSetForeground(display, gc, 0x181818);
		clear_background(display, window, gc);
		XSetForeground(display, gc, 0xFF0000);
		draw_circle(display, window, gc, (Point){W_WIDTH/2, W_HEIGHT/2}, 42);
	}
	XFlush(display);
	XCloseDisplay(display);
	return (0);
}
