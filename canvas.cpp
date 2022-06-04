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

	if (console) {
		console->close();
		delete console;
		console = nullptr;
	}

	delete cursorWait;
	delete cursorNormal;
	cursorWait = nullptr;
	cursorNormal = nullptr;
}

void Canvas::paintEvent(QPaintEvent* event) {

	painter = new QPainter(this);

	int index{ 0 };
	int count{ 0 };

	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = _mf->z->getIndex(x, y);
			count = _mf->z->getCount(index);
			if (count == -1)
				painter->setPen(blackPen);
			else if (count > 255)
				painter->setPen(whitePen);
			
			
			else {

				//switch (_mf->z->getCount(index)-zooms) {
				//case 0:
				//	painter->setPen(blue1black3Pen);
				//	break;
				//case 1:
				//	painter->setPen(blue2black2Pen);
				//	break;
				//case 2:
				//	painter->setPen(blue3black1Pen);
				//	break;
				//case 3:
				//	painter->setPen(bluePen);
				//	break;
				//case 4:
				//	painter->setPen(green1blue3Pen);
				//	break;
				//case 5:
				//	painter->setPen(green2blue2Pen);
				//	break;
				//case 6:
				//	painter->setPen(green3blue1Pen);
				//	break;
				//case 7:
				//	painter->setPen(greenPen);
				//	break;
				//case 8:
				//	painter->setPen(red1green3Pen);
				//	break;
				//case 9:
				//	painter->setPen(red2green2Pen);
				//	break;
				//case 10:
				//	painter->setPen(red3green1Pen);
				//	break;
				//case 11:
				//	painter->setPen(redPen);
				//	break;
				//case 12:
				//	painter->setPen(white1red3Pen);
				//	break;
				//case 13:
				//	painter->setPen(white2red2Pen);
				//	break;
				//case 14:
				//	painter->setPen(white3red1Pen);
				//	break;
				//default:
				//	painter->setPen(whitePen);
				//	break;
				//}

				r = (5 * count) + 10 - (3*zooms);
				g = (4 * count) + 30 - (2*zooms);
				b = (3 * count) + 50 - zooms;
	
				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
				painter->setPen(QPen(QColor(r, g, b)));

			}
			painter->drawPoint(x, y);



			if (index == TEST_INDEX) {
				painter->setPen(whitePen);
				painter->drawPoint(x, y);
			}
		}
	}


	delete painter;
	painter = nullptr;
}

void Canvas::mousePressEvent(QMouseEvent* event) {

	this->setCursor(*cursorWait);
	

	double x = (double)event->pos().x();
	double y = (double)event->pos().y();

	double d_resize_x = (double)RESIZE_X;
	double d_resize_y = (double)RESIZE_Y;
	double d_size_x = (double)SIZE_X;
	double d_size_y = (double)SIZE_Y;

	//if (!console) 
	//	console = new Console();

	//console->cout("coords: x=" + std::to_string(x) + ", y=" + std::to_string(y));

	if (x < d_resize_x / 2)
		x = d_resize_x / 2;
	if (x > (d_size_x - (d_resize_x / 2)))
		x = d_size_x - (d_resize_x / 2);
	if (y < d_resize_y / 2)
		y = d_resize_y / 2;
	if (y > (d_size_y - (d_resize_y / 2)))
		y = d_size_y - (d_resize_y / 2);

	double new_x_left = _x_left + (((x - (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	double new_x_right = _x_left + (((x + (d_resize_x / 2)) / d_size_x) * (_x_right - _x_left));
	double new_y_bottom = _y_bottom + (((y - (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));
	double new_y_top = _y_bottom + (((y + (d_resize_y / 2)) / d_size_y) * (_y_top - _y_bottom));

	_x_left = new_x_left;
	_x_right = new_x_right;
	_y_bottom = new_y_bottom;
	_y_top = new_y_top;


	_mf->setDeltasAndTicks(new_x_left, new_x_right, new_y_top, new_y_bottom);
	_mf->setPlaneValues();

	update();
	zooms++;

	this->setCursor(*cursorNormal);

}