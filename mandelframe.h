#pragma once
#include "zmatrix.h"
#include "console.h"

class MandelFrame {

	Console* console;
	
	double _x_left, _x_right, _y_top, _y_bottom;
	double x_delta, y_delta, x_tick, y_tick;

	

public:

	ZMatrix* z;

	MandelFrame(double x_left, double x_right, double y_top, double y_bottom);
	~MandelFrame();

	void setDeltasAndTicks(double x_left, double x_right, double y_top, double y_bottom);
	void setPlaneValues();

	int mandelIterate(int index, int max_iterations, double max_abs);

};