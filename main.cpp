#include "view.h"


int main(int argc, char* argv[]) {

	QApplication app = QApplication(argc, argv);

	View root(-2.5, 1.5, 2, -2);


	return app.exec();


}