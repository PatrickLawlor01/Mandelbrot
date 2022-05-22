#include "complex.h"
#include <iostream>
#include <string>

#include "widgets.h"
#include "console.h"




int main(int argc, char* argv[]) {

	
	

	Complex z1(12, 3), z2(-4, -5), z3;



	QApplication app = QApplication(argc, argv);

	Console cons;
	cons.cout(z1.toString());
	cons.cout(z2.toString());

	z3 = z1 * z2;
	cons.cout(z3.toString());


	return app.exec();

}