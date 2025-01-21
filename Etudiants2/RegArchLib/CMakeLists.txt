if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
	add_compile_options(-D_DEBUG)
	option(_DEBUG "#define _DEBUG as for MSVC" ON)
else()
	option(_DEBUG "#define _DEBUG as for MSVC" OFF)
endif()

message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
if (_DEBUG)
	add_compile_definitions(_DEBUG)
endif()

add_library(RegArchLib
		StdAfxRegArchLib.cpp
		cAbstCondMean.cpp
		cAbstCondVar.cpp
		cAbstResiduals.cpp
		cAr.cpp
		cArch.cpp
		cCondMean.cpp
		cConst.cpp
		cConstCondVar.cpp
		cGarch.cpp
		cMa.cpp
		cNormResiduals.cpp
		cRegArchModel.cpp
		cRegArchValue.cpp
		cRegArchGradient
		cStudentResiduals.cpp
		RegArchCompute.cpp
	)

target_include_directories(RegArchLib
							PUBLIC C:/MesProgrammes/MSYS2/usr/local/include
							PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Error
 							PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../VectorAndMatrix
                          	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           )

