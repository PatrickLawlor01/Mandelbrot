#pragma once

#include "widgets.h"
#include <string>

class Console : public QWidget {


	QTextEdit* text;
	QVBoxLayout* layout;

public:
	Console();
	~Console();

	void clear();
	void cout(std::string newText);

	void clicked_clear();

};