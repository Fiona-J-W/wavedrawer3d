project(wavedrawer3d)
cmake_minimum_required(VERSION 2.8)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
	message("creating Debug-Version")
	add_definitions( -DDEBUG )
	set( CMAKE_CXX_FLAGS "-std=c++11 -O0 -Wall -Wextra -pedantic -Werror -g" )
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
	message("creating Release-Version with Debug-information")
	add_definitions( -DDEBUG )
	set( CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Wextra -pedantic -Werror -g" )
else()
	message("creating Release-Version")
	set( CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Wextra -pedantic -Werror" )
endif()

set(BOOST_LIBS thread system)
find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)

find_library(LIBPNG png)

add_subdirectory(src)
