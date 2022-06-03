#include "pix.h"

Pix::Pix(MandelFrame* mf)
	: QPixmap(SIZE_X, SIZE_Y)
{
	_mf = mf;
}

Pix::~Pix() {}

void Pix::paintEvent(QPaintEvent* event) {
	int index{ 0 };


	painter = new QPainter(this);

	painter->setPen(redPen);
	painter->drawPoint(600, 600);

	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = _mf->z->getIndex(x, y);
			if (_mf->z->getCount(index) < 0) {
				painter->setPen(black);
				painter->drawPoint(x, y);
			}
			else {
				painter->setPen(red);
				painter->drawPoint(x, y);
			}
		}
	}
	painter->end();
}