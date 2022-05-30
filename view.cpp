#include "view.h"
#include "consts.h"

View::View(double x_left, double x_right, double y_top, double y_bottom)
	: QMainWindow()
{

	mf = new MandelFrame(x_left, x_right, y_top, y_bottom);

	setGeometry(SIZE_X, SIZE_Y, 100, 100);

	mainWidget = new QWidget();
	this->setCentralWidget(mainWidget);

	mainLayout = new QVBoxLayout();
	mainWidget->setLayout(mainLayout);

	canvasLabel = new QLabel();
	mainLayout->addWidget(canvasLabel);

	canvas = new QPixmap();
	canvasLabel->setPixmap(*canvas);

}


View::~View() {
	
	delete mf;
	mf = nullptr;

	delete canvas;
	canvas = nullptr;

	delete canvasLabel;
	canvasLabel = nullptr;

	delete mainLayout;
	mainLayout = nullptr;

	delete mainWidget;
	mainWidget = nullptr;

}


void View::paintEvent(QPaintEvent event) {

	int index{ 0 };

	painter = new QPainter();
	painter->begin(&(canvasLabel->pixmap()));

	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			index = mf->z->getIndex(x, y);
			if (mf->z->getCount(index) < 0) {
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
	delete painter;
	painter = nullptr;

}
