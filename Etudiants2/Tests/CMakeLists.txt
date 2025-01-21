add_executable(TestCPlusPlus StdAfxTestCPlusPlus.cpp TestCPlusPlus.cpp)

target_include_directories(TestCPlusPlus
				PUBLIC C:/MesProgrammes/MSYS2/usr/local/include
				PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Error
				PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../VectorAndMatrix
				PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../RegArchLib
				PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           )
target_link_directories(TestCPlusPlus
				PUBLIC C:/MesProgrammes/MSYS2/usr/local/lib/x64
			)
target_link_libraries(TestCPlusPlus PUBLIC RegArchLib VectorAndMatrix Error gsl gslcblas )
