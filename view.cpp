#include "view.h"
#include "consts.h"
#include "canvas.h"

View::View(double x_left, double x_right, double y_top, double y_bottom)
	: QMainWindow()
{

	mf = new MandelFrame(x_left, x_right, y_top, y_bottom);

	setGeometry(100, 100, SIZE_X, SIZE_Y);

	mainWidget = new Canvas(mf, x_left, x_right, y_top, y_bottom);
	this->setCentralWidget(mainWidget);

	show();

}


View::~View() {
	
	delete mainWidget;
	mainWidget = nullptr;
}
