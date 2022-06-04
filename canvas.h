#pragma once
#include "widgets.h"
#include "mandelframe.h"
#include "console.h"

class Canvas : public QWidget {

public:

	MandelFrame* _mf;

	Console* console {nullptr};

	double _x_left, _x_right, _y_top, _y_bottom;
	
	
	
	

	const QColor white = QColor(255, 255, 255, 255);
	const QColor white3red1 = QColor(255, 191, 191, 255);
	const QColor white2red2 = QColor(255, 127, 127, 255);
	const QColor white1red3 = QColor(255, 63, 63, 255);
	const QColor red = QColor(255, 0, 0, 255);

	const QColor red3green1 = QColor(191, 63, 0, 255);
	const QColor red2green2 = QColor(127, 127, 0, 255);
	const QColor red1green3 = QColor(63, 191, 0, 255);
	const QColor green = QColor(0, 255, 0, 255);

	const QColor green3blue1 = QColor(0, 191, 63, 255);
	const QColor green2blue2 = QColor(0, 127, 127, 255);
	const QColor green1blue3 = QColor(0, 63, 191, 255);
	const QColor blue = QColor(0, 0, 255, 255);

	const QColor blue3black1 = QColor(0, 0, 191, 255);
	const QColor blue2black2 = QColor(0, 0, 127, 255);
	const QColor blue1black3 = QColor(0, 0, 63, 255);

	const QColor black = QColor(0, 0, 0, 255);


	const QPen blackPen = QPen(black);
	const QPen whitePen = QPen(white);
	const QPen white3red1Pen = QPen(white3red1);
	const QPen white2red2Pen = QPen(white2red2);
	const QPen white1red3Pen = QPen(white1red3);
	const QPen redPen = QPen(red);
	const QPen red1green3Pen = QPen(red1green3);
	const QPen red2green2Pen = QPen(red2green2);
	const QPen red3green1Pen = QPen(red3green1);
	const QPen greenPen = QPen(green);
	const QPen green3blue1Pen = QPen(green3blue1);
	const QPen green2blue2Pen = (green2blue2);
	const QPen green1blue3Pen = (green1blue3);
	const QPen bluePen = QPen(blue);
	const QPen blue3black1Pen = QPen(blue3black1);
	const QPen blue2black2Pen = QPen(blue2black2);
	const QPen blue1black3Pen = QPen(blue1black3);


	QPainter* painter = nullptr;

	Canvas(MandelFrame* mf, double x_left, double x_right, double y_top, double y_bottom);
	~Canvas();

	void paintEvent(QPaintEvent* event);

	void mousePressEvent(QMouseEvent* event) override;

};