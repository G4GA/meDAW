function (add_ut bin_name)
    add_executable(${bin_name} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${bin_name}.cpp)

target_include_directories(${bin_name} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

    target_link_libraries(${bin_name} PRIVATE ${PROJECT_NAME})
endfunction()

add_subdirectory(polyCodec)
