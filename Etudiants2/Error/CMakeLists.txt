if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    add_compile_options(-D_DEBUG)
    option(_DEBUG "#define _DEBUG as for MSVC" ON)
else()
    option(_DEBUG "#define _DEBUG as for MSVC" OFF)
endif()

add_library(Error cError.cpp StdAfxError.cpp)

target_include_directories(Error
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           )
