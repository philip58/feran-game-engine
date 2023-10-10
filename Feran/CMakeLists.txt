set(HEADER_FILES 
	include/Feran.h
	FeranApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DFR_DEBUG=2)
add_definitions(-DFERAN_LIB)

include_directories(../glfw/include)

add_library(Feran SHARED ${HEADER_FILES} ${SOURCE_FILES}) 

target_precompile_headers(Feran PRIVATE pch.h)

target_link_libraries(Feran glfw)