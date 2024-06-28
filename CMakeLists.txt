cmake_minimum_required(VERSION 3.16)

project(CPP-Examples)

if (CMAKE_SIZEOF_VOID_P LESS 8)
	message(FATAL_ERROR "only 64bit supported")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)

set(SRCS
	main.cpp
	example-ptr/example-ptr-unique_ptr.cpp
	example-base/example-base-lambda.cpp
	example-base/example-base-variant.cpp
	example-base/example-base-friend.cpp
	example-base/example-base-new.cpp
	example-base/example-base-uniform_initialization.cpp
	example-base/example-base-reference.cpp
	example-base/example-base-lock.cpp
	example-templete/example-templete-function.cpp
	example-templete/example-templete-member-function.cpp
	example-templete/example-templete-class.cpp
	example-templete/example-templete-explicit-instantiation.cpp
	example-templete/example-templete-explicit-specialization.cpp
	example-templete/example-template-varargs.cpp
	example-class/example-class-move-constructor.cpp
	example-class/example-class-copy-constructor.cpp
	example-class/example-class-delegate-constructor.cpp
	example-class/example-class-inheriting-constructor.cpp
	example-class/example-class-destructor.cpp
	example-thread/example-thread-thread.cpp
)

add_executable(CPP-Examples ${SRCS})