cmake_minimum_required(VERSION 3.2.0)
project(Algorithm CXX)

set(CMAKE_C_COMPILER "which gcc")
set(CMAKE_CXX_COMPILE_FEATURES "which g++")
set(CMAKE_CXX_STANDARD 20)
set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR}/)

# 递归包含头文件
function(include_sub_directories_recursively root_dir)
    if (IS_DIRECTORY ${root_dir})               # 当前路径是一个目录吗，是的话就加入到包含目录
        message("include dir: " ${root_dir})
        include_directories(${root_dir})
    endif()

    file(GLOB ALL_SUB RELATIVE ${root_dir} ${root_dir}/*) # 获得当前目录下的所有文件，让如ALL_SUB列表中
    foreach(sub ${ALL_SUB})
        if (IS_DIRECTORY ${root_dir}/${sub})
            include_sub_directories_recursively(${root_dir}/${sub}) # 对子目录递归调用，包含
        endif()
    endforeach()
endfunction()


include_sub_directories_recursively(${PROJECT_SOURCE_DIR}/src/include)

add_subdirectory(src bin)