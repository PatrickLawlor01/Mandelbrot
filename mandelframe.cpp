#include "mandelframe.h"
#include "consts.h"

MandelFrame::MandelFrame(double x_left, double x_right, double y_top, double y_bottom)
	: _x_left(x_left), _x_right(x_right), _y_top(y_top), _y_bottom(y_bottom),
		x_delta(x_right - x_left), y_delta(y_top - y_bottom),
		x_tick(x_delta/SIZE_X), y_tick(y_delta/SIZE_Y)
{
	z = new ZMatrix;

	this->setPlaneValues();

}


void MandelFrame::setPlaneValues() {


	int index;
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {

			index = z->getIndex(x, y);

			if (index == TEST_INDEX) {
				if (!console) {
					console = new Console();
					console->show();
					console->cout("x: " + std::to_string(x));
					console->cout("y: " + std::to_string(y));
					console->cout("x in plane: " + std::to_string(_x_left + (x_tick * x)));
					console->cout("y in plane: " + std::to_string(_y_bottom + (y_tick * y)));

				}
			}
				z->setElement(index, (_x_left + (x_tick * x)), (_y_bottom + (y_tick * y)));


				z->setCount(index, mandelIterate(index, ITERATIONS, MAX_ABS));


		}

	}
}

void MandelFrame::setDeltasAndTicks(double x_left, double x_right, double y_top, double y_bottom) {

	_x_left = x_left;
	_x_right = x_right;
	_y_top = y_top;
	_y_bottom = y_bottom;
	x_delta = _x_right - _x_left;
	y_delta = _y_top - _y_bottom;
	x_tick = x_delta / SIZE_X; 
	y_tick = y_delta / SIZE_Y;

}

MandelFrame::~MandelFrame() {
	delete z;
	z = nullptr;

	if (TEST_INDEX > 0) {
		delete console;
		console = nullptr;
	}

}

int MandelFrame::mandelIterate(int index, int max_iterations, double max_abs) {
	
	Complex c = z->getElement(index);
	Complex temp;
	int counter = 0;
	bool escaped{ false };

	for (int i = 0; i < max_iterations; i++) {

		if (index == TEST_INDEX) {
			console->cout("iteration(a): " + std::to_string(i) + ", re: " + std::to_string(temp.re) + ", im: " + std::to_string(temp.im));

		}

		counter++;
		temp = temp*temp;
		if (index == TEST_INDEX) console->cout("iteration(b): " + std::to_string(i) + ", re: " + std::to_string(temp.re) + ", im: " + std::to_string(temp.im));
		temp += c;
		if (index == TEST_INDEX) console->cout("iteration(c): " + std::to_string(i) + ", re: " + std::to_string(temp.re) + ", im: " + std::to_string(temp.im));
		
		if (temp.abs() > max_abs) {
			escaped = true;
			break;
		}
	}
	//c.re = temp.re;
	//c.im = temp.im;
	if (!escaped) counter = -1;
	return counter;

}