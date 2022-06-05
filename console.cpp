#include "console.h"

Console::Console() {

	this->setGeometry(10, 10, 400, 400);

	text = new QTextEdit();
	text->setReadOnly(true);

	clearButton = new QPushButton("Clear");
	clearButton->connect(clearButton, &QPushButton::clicked, this, &Console::clicked_clear);

	layout = new QVBoxLayout();
	this->setLayout(layout);
	layout->addWidget(text);
	layout->addWidget(clearButton);

	this->show();

}


Console::~Console() {

	delete text;
	delete layout;
	delete clearButton;

}


// send new message to console
void Console::cout(std::string newText) {
	this->text->append(QString::fromStdString(newText));
}


// erase contents of console
void Console::clicked_clear() {
	this->text->clear();
}