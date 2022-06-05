#pragma once
#include "widgets.h"
#include "mandelframe.h"
#include "consts.h"
#include "pix.h"

// main viewer widget

class View : public QMainWindow {

	MandelFrame* mf;
	QWidget* mainWidget;

public:

	View(double x_left, double x_right, double y_top, double y_bottom);
	~View();
};