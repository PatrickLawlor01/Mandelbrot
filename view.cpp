#include "view.h"
#include "consts.h"
#include "canvas.h"

View::View(double x_left, double x_right, double y_top, double y_bottom)
	: QMainWindow()
{

	mf = new MandelFrame(x_left, x_right, y_top, y_bottom);

	setGeometry(100, 100, SIZE_X, SIZE_Y);

	mainWidget = new Canvas(mf);
	this->setCentralWidget(mainWidget);

	//mainLayout = new QVBoxLayout();
	//mainWidget->setLayout(mainLayout);

	//canvasLabel = new QLabel();
	//mainLayout->addWidget(canvasLabel);

	//canvas = new Pix(mf);
	//canvasLabel->setPixmap(*canvas);

	//painter = nullptr;

	show();

}


View::~View() {
	
	delete mf;
	mf = nullptr;

	//delete canvas;
	//canvas = nullptr;

	//delete canvasLabel;
	//canvasLabel = nullptr;

	//delete mainLayout;
	//mainLayout = nullptr;

	delete mainWidget;
	mainWidget = nullptr;

}


//void View::paintEvent(QPaintEvent* event) {
//
//
//
//
//	//delete painter;
//	//painter = nullptr;
//
//}
