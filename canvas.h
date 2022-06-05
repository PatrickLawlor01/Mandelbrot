#pragma once
#include "widgets.h"
#include "mandelframe.h"
#include "console.h"

// central widget and drawing object

class Canvas : public QWidget {

private:

	QCursor* cursorWait;
	QCursor* cursorNormal;
	MandelFrame* _mf;

	// track number of zooms, current RGB values for point colouring
	int zooms{ 0 };
	int r{ 1 }, g{ 1 }, b{ 1 };

	double _x_left, _x_right, _y_top, _y_bottom;

	const QColor white = QColor(255, 255, 255, 255);
	const QColor red = QColor(255, 0, 0, 255);
	const QColor green = QColor(0, 255, 0, 255);
	const QColor blue = QColor(0, 0, 255, 255);
	const QColor black = QColor(0, 0, 0, 255);

	const QPen blackPen = QPen(black);
	const QPen whitePen = QPen(white);
	const QPen redPen = QPen(red);
	const QPen greenPen = QPen(green);
	const QPen bluePen = QPen(blue);

	QPainter* painter = nullptr;

	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* event) override;

public:

	Canvas(MandelFrame* mf, double x_left, double x_right, double y_top, double y_bottom);
	~Canvas();

};