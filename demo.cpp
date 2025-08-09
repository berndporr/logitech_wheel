#include "logiwheel.h"

// Dummy printer class to show how we can do event callbacks into a class.
class Printer {
public:
    
    void steering(float v) {
	printf("Steering = %f\n",v);
    }
    
    void throttle(float v) {
	printf("Throttle = %f\n",v);
    }
    
    void braking(float v) {
	printf("Braking = %f\n",v);
    }

    void button(int d) {
	printf("Button = %d\n",d);
    }
};

int main(int argc, char *argv[]) {
	LogiWheel logiwheel;
	Printer printer;
	logiwheel.registerSteeringCallback([&](float v){printer.steering(v);});
	logiwheel.registerThrottleCallback([&](float v){printer.throttle(v);});
	logiwheel.registerBrakeCallback([&](float v){printer.braking(v);});
	logiwheel.registerButtonCallback([&](int v){printer.button(v);});
	if (!logiwheel.start()) {
	    fprintf(stderr,"Could not start the wheel. Is it plugged in?\n");
	    return -1;
	};
	printf("Press any key to stop it.\n");
	getc(stdin);
	logiwheel.stop();
	return 0;
}
