cmake_minimum_required(VERSION 3.10)

project(Steering)

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

set (CMAKE_CXX_STANDARD 17)

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
add_executable(remote remote.cpp)
target_link_libraries(remote fastcdr fastrtps FastDDSMsg)


# Subscriber
add_executable(demo_receiver demo_receiver.cpp)
target_link_libraries(demo_receiver fastcdr fastrtps FastDDSMsg)
