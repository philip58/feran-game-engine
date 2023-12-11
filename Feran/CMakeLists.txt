set(HEADER_FILES 
	include/Feran.h
	FeranApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	GLFWCode/OpenGLPicture.h
	Events.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Keys.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLShader.cpp
	Events.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DFR_DEBUG=2)
add_definitions(-DFERAN_LIB)

include_directories(../Feran)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Feran SHARED ${HEADER_FILES} ${SOURCE_FILES}) 

target_precompile_headers(Feran PRIVATE pch.h)

target_link_libraries(Feran glfw)

target_link_libraries(Feran glad)

target_link_libraries(Feran stbi)