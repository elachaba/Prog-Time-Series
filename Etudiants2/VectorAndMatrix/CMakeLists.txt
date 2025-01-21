if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    add_compile_options(-D_DEBUG)
    option(_DEBUG "#define _DEBUG as for MSVC" ON)
else ()
    option(_DEBUG "#define _DEBUG as for MSVC" OFF)
endif()

add_library(VectorAndMatrix StdAfxVectorAndMatrix.cpp cGSLVector.cpp cGSLMatrix.cpp)

target_include_directories(VectorAndMatrix
			  	            PUBLIC C:/MesProgrammes/MSYS2/usr/local/include
				            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Error
                           	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           )

