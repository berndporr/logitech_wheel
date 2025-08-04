#include "logiwheel.h"

int main(int argc, char *argv[]) {
	LogiWheel logiwheel;
	logiwheel.start();
	getc(stdin);
	logiwheel.stop();
	return 0;
}
