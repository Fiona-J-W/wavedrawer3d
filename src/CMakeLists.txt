add_executable( wavedrawer
divide_string.cpp
draw.cpp
help.cpp
main.cpp
point3d.cpp
settings.cpp
stimulator.cpp
)

target_link_libraries( wavedrawer
	${Boost_LIBRARIES}
	${LIBPNG}
)
