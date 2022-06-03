#include "canvas.h"
#include "consts.h"

Canvas::Canvas(MandelFrame* mf)
	: QWidget()
{
	_mf = mf;
}

Canvas::~Canvas() {
	
}

void Canvas::paintEvent(QPaintEvent* event) {

	painter = new QPainter(this);

	int index{ 0 };

	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = _mf->z->getIndex(x, y);
			if (_mf->z->getCount(index) < 0) {
				painter->setPen(redPen);
				painter->drawPoint(x, y);
			}
			else {
				painter->setPen(blackPen);
				painter->drawPoint(x, y);
			}
			if (index == TEST_INDEX) {
				painter->setPen(whitePen);
				painter->drawPoint(x, y);
			}
		}
	}


	delete painter;
	painter = nullptr;
}