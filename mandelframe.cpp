#include "mandelframe.h"
#include "consts.h"

MandelFrame::MandelFrame(double x_left, double x_right, double y_top, double y_bottom)
	: _x_left(x_left), _x_right(x_right), _y_top(y_top), _y_bottom(y_bottom),
		x_delta(x_right - x_left), y_delta(y_top - y_bottom),
		x_tick(x_delta/SIZE_X), y_tick(y_delta/SIZE_Y)
{

	int index;
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {

			index = z.getIndex(x, y);
			z.setElement(index, (x_left + (x_tick * x)), (y_bottom + (y_tick * y)));

			z.setCount(index, mandelIterate(z.getElement(index), ITERATIONS, MAX_ABS));

		}

	}
}


MandelFrame::~MandelFrame() {

}

int MandelFrame::mandelIterate(Complex& c, int max_iterations, double max_abs) {
	
	Complex temp;
	int counter = 0;
	bool escaped{ false };

	for (int i = 0; i < max_iterations; i++) {
		counter++;
		temp *= temp;
		temp += c;
		if (temp.abs() > max_abs) {
			escaped = true;
			break;
		}
	}
	c.re = temp.re;
	c.im = temp.im;
	if (!escaped) counter = -1;
	return counter;

}