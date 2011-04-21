FIND_PACKAGE( SDL REQUIRED )
FIND_PACKAGE( SDL_image REQUIRED )
FIND_PACKAGE( OpenGL REQUIRED)


LIST(APPEND SOURCES
	Maemo/main.cpp
	Maemo/EAGLView.cpp
)

LIST(APPEND HEADERS
)

SET( MOC_HEADERS
	Maemo/EAGLView.h
)


LIST(APPEND LIBRARIES
	${SDL_LIBRARY}
	${SDLIMAGE_LIBRARY}
	${OPENGL_gl_LIBRARY}
)
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})

