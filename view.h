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

	View(long double x_left, long double x_right, long double y_top, long double y_bottom);
	~View();
};