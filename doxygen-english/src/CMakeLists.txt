include_directories (${doxygen_shape_demo_SOURCE_DIR}/src)
link_directories (${doxygen_shape_demo_BINARY_DIR}/src)
set (LIBS circle point rectangle shape shapefactory triangle)
foreach (lib ${LIBS})
	add_library (${lib} ${lib}.cpp)
endforeach (lib)
set (CORELIBS  )
add_executable (shape_demo main.cpp)
target_link_libraries (shape_demo ${CORELIBS} ${LIBS} )
