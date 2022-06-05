#pragma once

#include "widgets.h"
#include <string>

// separate window for writing out text, for debugging

class Console : public QWidget {

	QTextEdit* text;
	QVBoxLayout* layout;
	QPushButton* clearButton;

public:
	Console();
	~Console();

	void cout(std::string newText);

	void clicked_clear();

};