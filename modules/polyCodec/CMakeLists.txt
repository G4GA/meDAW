project(polyCodec)

set(PROJECT_SOURCES
        src/decoded_audio.cpp)

    set(LIB_NAME ${PROJECT_NAME})

add_library(${LIB_NAME} STATIC ${PROJECT_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

function (add_ut bin_name)
    add_executable(${bin_name} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${bin_name}.cpp)

    include_directories(${bin_name} ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_link_libraries(${bin_name} PRIVATE ${PROJECT_NAME})
endfunction()

add_ut(UT_decoded_audio)
