#pragma once
#include "zmatrix.h"

class MandelFrame {

	ZMatrix z;
	
	double _x_left, _x_right, _y_top, _y_bottom;
	double x_delta, y_delta, x_tick, y_tick;

	

public:


	MandelFrame(double x_left, double x_right, double y_top, double y_bottom);
	~MandelFrame();

	int mandelIterate(Complex& c, int max_iterations, double max_abs);

};