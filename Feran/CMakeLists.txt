set(HEADER_FILES 
	include/Feran.h
	FeranApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	placeholder.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DFR_DEBUG=2)
add_definitions(-DFERAN_LIB)

include_directories(../Feran)
include_directories(../glfw/include)

add_library(Feran SHARED ${HEADER_FILES} ${SOURCE_FILES}) 

target_precompile_headers(Feran PRIVATE pch.h)

target_link_libraries(Feran glfw)