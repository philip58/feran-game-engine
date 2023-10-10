set(HEADER_FILES
)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_PF ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_PF Feran)

include_directories(../Feran/include)
