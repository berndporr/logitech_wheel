# Remote control using fastDDS

FastDDS is a realtime protocol which broadcasts to your local
ethernet network so you can for example remote control a
robot via WIFI. There is no need to specify an IP address. fastDDS
subscriber find automatically the publishers.

## Prereqisites

Fast CDR
```
apt install libfastcdr-dev
```

Fast RTPS
```
apt install libfastrtps-dev
```

Fast DDS tools
```
apt install fastddsgen fastdds-tools
```

## How to compile

```
cmake .
make
```


## How to run

Transmitter: Open a terminal and type
```
./remote
```

Test receiver: Open another terminal and type

```
./demo_subscriber
```

```
Button: 102 RECEIVED.
Button: 102 RECEIVED.
Steering: 0 RECEIVED.
Steering: 0.00195312 RECEIVED.
Steering: 0.00390625 RECEIVED.
Steering: -0.00585938 RECEIVED.
Steering: -0.0078125 RECEIVED.
Steering: -0.00976562 RECEIVED.
Steering: -0.0195312 RECEIVED.
Steering: -0.0214844 RECEIVED.

```
