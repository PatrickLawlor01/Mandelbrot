#pragma once
#include "zmatrix.h"
#include "console.h"

// class handles ZMatrix object, maps ZMatrix array to dimensions of view, and carries out computations

class MandelFrame {

	Console* console;
	
	// dimensions of viewer window in complex plane terms - start with (-3, 1)x(2, -2), user can then zoom in
	long double _x_left, _x_right, _y_top, _y_bottom;
	// for mapping array elements into points on the complex plane
	long double x_delta, y_delta, x_tick, y_tick;

public:

	ZMatrix* z;

	MandelFrame(long double x_left, long double x_right, long double y_top, long double y_bottom);
	~MandelFrame();

	void setDeltasAndTicks(long double x_left, long double x_right, long double y_top, long double y_bottom);
	void setPlaneValues();

	int mandelIterate(int index, int max_iterations, double max_abs);

};