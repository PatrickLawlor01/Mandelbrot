#pragma once

static const int SIZE_X = 1200;						// dimensions of viewer window in pixels - x
static const int SIZE_Y = 1200;						// dimensions of viewer window in pixels - y
static const int ARR_SIZE = SIZE_X * SIZE_Y;		// size of 1d array to store required number of z
static const int MAX_ITERATIONS = 50;				// base # of iterations before z confirmed member of Mandelbrot
static const int ITERATIONS_INCREMENT = 10;			// how much to increase iterations each zoom 
static const double MAX_ABS = 2.0;					// cutoff magnitude for z to be excluded from Mandebrot

static const int TEST_INDEX = -1;					// for debugging

static const int ZOOM_FACTOR = 7;					// how much to zoom in when user zooms
static const int RESIZE_X = SIZE_X / ZOOM_FACTOR;	// for remapping process
static const int RESIZE_Y = SIZE_Y / ZOOM_FACTOR;	// for remapping process