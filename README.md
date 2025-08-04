# Logitech Racing Wheel C++ driver

Compile with

```
cmake .
make
```

Run the demo:

```
./demo
```

It has three callbacks for throttle, braking and steering.

```
    void registerSteeringCallback(CallbackFunction cb)
    void registerThrottleCallback(CallbackFunction cb)
    void registerBrakeCallback(CallbackFunction cb)

```

where every callback needs to be a standard function or lambda function receiving a float.
Breaking and throttle are between 0 and 1. Steering between -1 and +1.

Start the program with:
```
start();
```
and stop it with
```
stop();
```

## Credit: Bernd Porr
