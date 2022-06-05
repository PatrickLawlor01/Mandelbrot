#include "mandelframe.h"
#include "consts.h"

MandelFrame::MandelFrame(long double x_left, long double x_right, long double y_top, long double y_bottom)
	: _x_left(x_left), _x_right(x_right), _y_top(y_top), _y_bottom(y_bottom),
		x_delta(x_right - x_left), y_delta(y_top - y_bottom),
		x_tick(x_delta/SIZE_X), y_tick(y_delta/SIZE_Y)
{
	z = new ZMatrix;

	this->setPlaneValues();
}


MandelFrame::~MandelFrame() {
	delete z;
	z = nullptr;
}


// set the complex numbers in ZMatrix as interpolated grid based on MandelFrame dimensions and SIZE_X, SIZE_Y
void MandelFrame::setPlaneValues() {


	int index;
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {

			index = z->getIndex(x, y);

				z->setElement(index, (_x_left + (x_tick * x)), (_y_bottom + (y_tick * y)));

				// compute iteration cutoff point for each z in ZMatrix->plane[], store result in ZMatrix->count[] 
				z->setCount(index, mandelIterate(index, iterations, MAX_ABS));
		}

	}
}


// reset dimensions, deltas and ticks values upon initialisation and after zoom
void MandelFrame::setDeltasAndTicks(long double x_left, long double x_right, long double y_top, long double y_bottom) {

	_x_left = x_left;
	_x_right = x_right;
	_y_top = y_top;
	_y_bottom = y_bottom;
	x_delta = _x_right - _x_left;
	y_delta = _y_top - _y_bottom;
	x_tick = x_delta / SIZE_X; 
	y_tick = y_delta / SIZE_Y;
}


// calculate iteration cutoff point - z is excluded from Mandelbrot set as soon as magnitude > 2, iteration count is recorded
int MandelFrame::mandelIterate(int index, int max_iterations, double max_abs) {
	
	Complex c = z->getElement(index);
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

	// record -1 if max_iterations reached and z is still in set - assumed member of Mandelbrot set
	if (!escaped) 
		counter = -1;
	return counter;

}