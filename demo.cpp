#include "logiwheel.h"

void printSteering(float v) {
    printf("Steering = %f\n",v);
}

void printThrottle(float v) {
    printf("Throttle = %f\n",v);
}

void printBraking(float v) {
    printf("Braking = %f\n",v);
}

int main(int argc, char *argv[]) {
	LogiWheel logiwheel;
	logiwheel.registerSteeringCallback(printSteering);
	logiwheel.registerThrottleCallback(printThrottle);
	logiwheel.registerBrakeCallback(printBraking);
	logiwheel.start();
	getc(stdin);
	logiwheel.stop();
	return 0;
}
