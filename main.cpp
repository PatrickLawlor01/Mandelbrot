#include "complex.h"
#include <iostream>
#include <string>

#include "widgets.h"
#include "console.h"
#include "zmatrix.h"



int main(int argc, char* argv[]) {

	
	

	Complex z1(12, 3), z2(-4, -5), z3;

	ZMatrix* zplane = new ZMatrix();
	zplane->setElement(500, z1.re, z1.im);
	z3 = zplane->getElement(500);


	QApplication app = QApplication(argc, argv);

	Console cons;
	cons.cout(z1.toString());
	cons.cout(z2.toString());

	z3 = z1 * z2;
	cons.cout(z3.toString());

	delete zplane;

	return app.exec();

	//test change

}