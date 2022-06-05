#include "root.h"
#include "view.h"


int main(int argc, char* argv[]) {

	QApplication app = QApplication(argc, argv);

	View root(-3, 1, 2, -2);


	return app.exec();


}