#pragma once
#include "widgets.h"
#include "mandelframe.h"

class View : public QMainWindow {

	MandelFrame* mf;

	QColor red = QColor(255, 0, 0, 255);
	QColor blue = QColor(0, 0, 255, 255);
	QColor green = QColor(0, 255, 0, 255);
	QColor black = QColor(0, 0, 0, 255);
	QColor white = QColor(255, 255, 255, 255);

	QPainter* painter;
	

	QWidget* mainWidget;
	QVBoxLayout* mainLayout;
	QLabel* canvasLabel;
	QPixmap* canvas;

public:

	View(double x_left, double x_right, double y_top, double y_bottom);
	~View();

	void paintEvent(QPaintEvent event);

};