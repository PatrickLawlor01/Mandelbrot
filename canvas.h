#pragma once
#include "widgets.h"
#include "mandelframe.h"

class Canvas : public QWidget {

public:

	MandelFrame* _mf;

	const QColor red = QColor(255, 0, 0, 255);
	const QColor blue = QColor(0, 0, 255, 255);
	const QColor green = QColor(0, 255, 0, 255);
	const QColor black = QColor(0, 0, 0, 255);
	const QColor white = QColor(255, 255, 255, 255);

	const QPen redPen = QPen(red);
	const QPen bluePen = QPen(blue);
	const QPen greenPen = QPen(green);
	const QPen blackPen = QPen(black);
	const QPen whitePen = QPen(white);


	QPainter* painter = nullptr;

	Canvas(MandelFrame* mf);
	~Canvas();

	void paintEvent(QPaintEvent* event);

};