#include <thread>
#include <atomic>
#include <functional>
#include <string>

/**
 * https://www.kernel.org/doc/Documentation/input/joystick-api.txt
 **/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/joystick.h>

class LogiWheel {

    bool running = false;
    int fd = -1;
    input_event event;
    std::thread eventThread;

public:

    void start(std::string device = "/dev/input/by-id/usb-Logitech_Logitech_Racing_Wheel-joystick") {
        fd = open(device.c_str(), O_RDONLY);
	
	if (fd == -1) {
	    perror("Could not open joystick");
	    return;
	}
	if (running) return;
	eventThread = std::thread(&LogiWheel::run, this);
    }
    
    void run() {
	running = true;
	while (running) 
	{
	    int r = read(fd, &event, sizeof(event));
	    if (r < 0) {
		fprintf(stderr,"Error = %d\n",r);
		running = false;
		return;
	    }
	    switch (event.type) {
            case JS_EVENT_BUTTON:
                break;
            case JS_EVENT_AXIS:
		int n = event.code;
		int v = event.value;
		printf("%d %d\n",n,v);
                break;
	    }
	    fflush(stdout);
	}
	running = false;
    }
    
    
    
    void stop() {
	running = false;
	close(fd);
    }
    
};
