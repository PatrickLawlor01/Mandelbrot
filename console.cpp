#include "console.h"


Console::Console() {

	//this->setGeometry(1200, 1600, 400, 400);

	text = new QTextEdit();
	text->setReadOnly(true);

	QPushButton* clearButton = new QPushButton("Clear");
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

}

void Console::clear() {
	this->text->clear();
}

void Console::cout(std::string newText) {
	this->text->append(QString::fromStdString(newText));
}

void Console::clicked_clear() {
	this->clear();
}