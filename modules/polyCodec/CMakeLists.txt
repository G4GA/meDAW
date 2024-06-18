project(polyCodec)

set(PROJECT_SOURCES
        src/decoded_audio.cpp)

set(LIB_NAME polyCodec)

add_library(${LIB_NAME} STATIC ${PROJECT_SOURCES})

# find_package(ALSA REQUIRED)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)