#include "canvas.h"
#include "consts.h"

Canvas::Canvas(MandelFrame* mf, double x_left, double x_right, double y_top, double y_bottom)
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

	// colour each point depending on its corresponding count value 
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = _mf->z->getIndex(x, y);
			count = _mf->z->getCount(index);
			// if -1, point was in Mandelbrot set - use black
			if (count == -1)
				painter->setPen(blackPen);
			else if (count > 50)
				painter->setPen(whitePen);
			else {
				// define colour scheme linked to count
				r = (5 * count);
				g = (4 * count)+50;
				b = (3 * count)+100;
	
				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
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
	double new_x_left = _x_left + (((x - (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	double new_x_right = _x_left + (((x + (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	double new_y_bottom = _y_bottom + (((y - (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));
	double new_y_top = _y_bottom + (((y + (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));

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

	this->setCursor(*cursorNormal);
}