project(polyCodec)

set(PROJECT_SOURCES
        src/decoded_audio.cpp)

    set(LIB_NAME ${PROJECT_NAME})

add_library(${LIB_NAME} STATIC ${PROJECT_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_ut(UT_decoded_audio)
