#include "canvas.h"
#include "consts.h"
#include <cmath>

Canvas::Canvas(MandelFrame* mf, long double x_left, long double x_right, long double y_top, long double y_bottom)
	: QWidget(),
	_x_left(x_left), _x_right(x_right), _y_top(y_top), _y_bottom(y_bottom),
	_mf(mf)
{ 
	cursorWait = new QCursor(Qt::WaitCursor);
	cursorNormal = new QCursor(Qt::ArrowCursor);
}


Canvas::~Canvas() {
	delete _mf;
	_mf = nullptr;

	delete cursorWait;
	delete cursorNormal;
	cursorWait = nullptr;
	cursorNormal = nullptr;
}


void Canvas::paintEvent(QPaintEvent* event) {

	painter = new QPainter(this);

	int index{ 0 };
	int count{ 0 };
	double iterations{ 0 };
	double dcount{ 0 };
	double iter_resize{ 0 };

	// colour each point depending on its corresponding count value 
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = _mf->z->getIndex(x, y);
			count = _mf->z->getCount(index);
			dcount = (double)count;
			iterations = (double)_mf->iterations;
			iter_resize = iterations * 0.1667;
			// if -1, point was in Mandelbrot set - use black
			if (count == -1)
				painter->setPen(blackPen);
			else if (count > iterations)
				painter->setPen(whitePen);
			else {
				// define colour scheme linked to count
				//g = (5 * count);
				//b = (4 * count)+50;
				//r = (3 * count)+100;

				whiteBracket = (std::fmax(dcount - (iterations * 0.8333), 0)/iter_resize)*255;

				if (count <= iterations * 0.8333)
					yellowBracket = (std::fmax(dcount - (iterations * 0.6667), 0) / iter_resize)*255;
				else
					yellowBracket = (std::fmax(iterations - dcount, 0) / iter_resize)*255;

				if (count <= iterations * 0.6667)
					orangeBracket = (std::fmax(dcount - (iterations * 0.5), 0) / iter_resize) * 255;
				else
					orangeBracket = (std::fmax((iterations*0.8333) - dcount, 0) / iter_resize) * 255;

				if (count <= iterations * 0.5)
					redBracket = (std::fmax(dcount - (iterations * 0.3333), 0) / iter_resize)*255;
				else
					redBracket = (std::fmax((iterations*0.6667) - dcount, 0) / iter_resize) * 255;

				if (count <= iterations * 0.3333)
					purpleBracket = (std::fmax(dcount - (iterations * 0.1667), 0) / iter_resize) * 255;
				else
					purpleBracket = (std::fmax((iterations * 0.5) - dcount, 0) / iter_resize) * 255;

				if (count <= iterations * 0.1667)
					blueBracket = (std::fmax(dcount, 0) / iter_resize) * 255;
				else
					blueBracket = (std::fmax((iterations * 0.3333) - dcount, 0) / iter_resize) * 255;

				greenBracket = (std::fmax((iterations * 0.1667) - dcount, 0) / iter_resize) * 255;

				r = std::fmin(whiteBracket + orangeBracket + redBracket + purpleBracket + yellowBracket, 255);
				g = std::fmin(whiteBracket + yellowBracket + greenBracket + (0.5*orangeBracket), 255);
				b = std::fmin(whiteBracket + purpleBracket + blueBracket + greenBracket, 255);

				painter->setPen(QPen(QColor(r, g, b)));

			}
			painter->drawPoint(x, y);

		}
	}

	delete painter;
	painter = nullptr;
}


// zoom in on point when user clicks on image
void Canvas::mousePressEvent(QMouseEvent* event) {

	this->setCursor(*cursorWait);

	double x = (double)event->pos().x();
	double y = (double)event->pos().y();

	double d_resize_x = (double)RESIZE_X;
	double d_resize_y = (double)RESIZE_Y;
	double d_size_x = (double)SIZE_X;
	double d_size_y = (double)SIZE_Y;

	// if user clicked too close to edge of screen, make adjustment
	if (x < d_resize_x / 2)
		x = d_resize_x / 2;
	if (x > (d_size_x - (d_resize_x / 2)))
		x = d_size_x - (d_resize_x / 2);
	if (y < d_resize_y / 2)
		y = d_resize_y / 2;
	if (y > (d_size_y - (d_resize_y / 2)))
		y = d_size_y - (d_resize_y / 2);

	// figure out new dimensions for MandelFrame based on where user clicked and the zoom factor defined in consts.h
	long double new_x_left = _x_left + (((x - (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	long double new_x_right = _x_left + (((x + (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	long double new_y_bottom = _y_bottom + (((y - (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));
	long double new_y_top = _y_bottom + (((y + (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));

	// overwrite dimension values held locally
	_x_left = new_x_left;
	_x_right = new_x_right;
	_y_bottom = new_y_bottom;
	_y_top = new_y_top;


	// write new values back to MandelFrame object and initiate recalculation
	_mf->setDeltasAndTicks(new_x_left, new_x_right, new_y_top, new_y_bottom);
	_mf->setPlaneValues();

	update();
	zooms++;
	_mf->iterations += ITERATIONS_INCREMENT;

	this->setCursor(*cursorNormal);
}