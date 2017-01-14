#include "App.h"

int main(int argc, char **argv) {
	const unsigned int WIDTH = 1000;
	const unsigned int HEIGHT = 500;
	const unsigned int MENUHEIGHT = 200;

	App app(WIDTH, HEIGHT, MENUHEIGHT);
	app.Start();

	return 1;
}


