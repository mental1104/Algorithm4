file(COPY ${PROJECT_SOURCE_DIR}/src/chapter2/testfile 
     DESTINATION ${PROJECT_BINARY_DIR}/bin/chapter2/)

add_executable(sortTest sortTest.cpp)