FIND_PACKAGE( Qt4 REQUIRED )
SET(QT_USE_QTOPENGL TRUE)
INCLUDE( ${QT_USE_FILE} )

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(PythonLibs REQUIRED)

INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIR} )

LIST(APPEND SOURCES
	Desktop/main.cpp
	Desktop/EAGLView.cpp
	Desktop/ResourceLoader.cpp
	Desktop/Sound.cpp
)

LIST(APPEND HEADERS
	Desktop/ResourceLoader.h
)

SET( MOC_HEADERS
	Desktop/EAGLView.h
)

SET_SOURCE_FILES_PROPERTIES(${SOUNDS} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

QT4_WRAP_CPP(  MOC_SOURCES  ${MOC_HEADERS} )
QT4_AUTOMOC (  ${SOURCES} )

LIST(APPEND LIBRARIES
	${QT_LIBRARIES}
	${OPENGL_gl_LIBRARY}
	${PYTHON_LIBRARY}
)

LIST(APPEND HEADERS ${MOC_HEADERS})
LIST(APPEND HEADERS ${MOC_SOURCES})

FILE(WRITE ${CMAKE_BINARY_DIR}/resources.qrc "<RCC>\n<qresource prefix='/' >\n" )
FOREACH(r ${RESOURCES})
	FILE(APPEND ${CMAKE_BINARY_DIR}/resources.qrc "<file alias='${r}'>${CMAKE_SOURCE_DIR}/${r}</file>\n")
ENDFOREACH(r)
FILE(APPEND ${CMAKE_BINARY_DIR}/resources.qrc "</qresource>\n</RCC>\n")

QT4_ADD_RESOURCES(RSRCS ${CMAKE_BINARY_DIR}/resources.qrc)

LIST(APPEND SOURCES ${RSRCS})
