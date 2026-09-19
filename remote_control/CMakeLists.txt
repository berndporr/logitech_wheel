cmake_minimum_required(VERSION 3.20)

project(Steering)

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

set (CMAKE_CXX_STANDARD 17)

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Create a library for the message / topic

set(LIBDDSIDL ${CMAKE_SOURCE_DIR}/brake.idl  ${CMAKE_SOURCE_DIR}/steering.idl  ${CMAKE_SOURCE_DIR}/throttle.idl ${CMAKE_SOURCE_DIR}/button.idl)

execute_process(COMMAND fastddsgen ${LIBDDSIDL})

add_library(FastDDSMsg STATIC
	      brake.cxx brakePubSubTypes.cxx
	      steering.cxx steeringPubSubTypes.cxx
	      throttle.cxx throttlePubSubTypes.cxx
	      button.cxx buttonPubSubTypes.cxx
	      )

include_directories(. ..)

add_custom_target(
    ddsmessages
    COMMAND fastddsgen ${LIBDDSIDL}
)

add_dependencies(FastDDSMsg ddsmessages)


# Publisher
add_executable(remote_publisher remote_publisher.cpp)
target_link_libraries(remote_publisher fastcdr fastrtps FastDDSMsg)


# Subscriber
add_executable(demo_subscriber demo_subscriber.cpp)
target_link_libraries(demo_subscriber fastcdr fastrtps FastDDSMsg)
