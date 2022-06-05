#include "root.h"

Root::Root() {
	screen = new View(-3, 1, 2, -2);
}

Root::~Root() {
	delete screen;
	screen = nullptr;
}