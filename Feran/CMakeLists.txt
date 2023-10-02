set(HEADER_FILES 
	include/Feran.h
	FeranApp.h
	Utilities.h
)

set(SOURCE_FILES
)

add_definitions(-DFR_DEBUG=2)
add_definitions(-DFERAN_LIB)

if(WIN32)
	add_definitions(-DFERAN_MSCPP)
elseif(LINUX)
	add_definitions(-DFERAN_LINUX)
elseif(APPLE)
	add_definitions(-DFERAN_APPLE)
endif()

add_library(Feran SHARED ${HEADER_FILES} ${SOURCE_FILES}) 

target_precompile_headers(Feran PRIVATE pch.h)