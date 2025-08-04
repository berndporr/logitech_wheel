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

    void start(std::string device = "/dev/input/by-id/usb-Logitech_Logitech_Racing_Wheel-event-joystick") {
        fd = open(device.c_str(), O_RDONLY);
	
	if (fd == -1) {
	    perror("Could not open joystick");
	    return;
	}
	if (running) return;
//	run();
	eventThread = std::thread(&LogiWheel::run, this);
    }
    
    void run() {
	running = true;
	while (running) 
	{
	    int r = read(fd, &event, sizeof(event));
	    printf("e = %d ",event.type);
	    if (r < 0) {
		fprintf(stderr,"Error = %d\n",r);
		running = false;
		return;
	    }
	    if (event.type == EV_ABS && event.code < ABS_TOOL_WIDTH)
		{
		    int n = event.code;
		    int v = event.value;
		    printf("Axis: %d %d\n",n,v);
		}
	    fflush(stdout);
	}
	running = false;
    }
    
    
    
    void stop() {
	running = false;
	close(fd);
	eventThread.join();
    }
    
};
