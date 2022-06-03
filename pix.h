#pragma once
#include "widgets.h"
#include "consts.h"
#include "mandelframe.h"

class Pix : public QPixmap {
public:
	Pix(MandelFrame* mf);
	~Pix();

	MandelFrame* _mf;

	const QColor red = QColor(255, 0, 0, 255);
	QColor blue = QColor(0, 0, 255, 255);
	QColor green = QColor(0, 255, 0, 255);
	QColor black = QColor(0, 0, 0, 255);
	QColor white = QColor(255, 255, 255, 255);

	QPen redPen = QPen(red);

	QPainter* painter = nullptr;

	void paintEvent(QPaintEvent* event);

};