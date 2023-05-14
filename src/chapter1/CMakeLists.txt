file(COPY ${PROJECT_SOURCE_DIR}/src/chapter1/testfile 
     DESTINATION ${PROJECT_BINARY_DIR}/bin/chapter1/)

add_executable(1_1-stack 1_1-stack.cpp)
add_executable(1_2-stack_List 1_2-stack_List.cpp)
add_executable(1_3-queue 1_3-queue.cpp)
add_executable(1_5-UnionFind 1_5-UnionFind.cpp)