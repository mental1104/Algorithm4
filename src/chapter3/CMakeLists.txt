file(COPY ${PROJECT_SOURCE_DIR}/src/chapter3/testfile 
     DESTINATION ${PROJECT_BINARY_DIR}/bin/chapter3/)

add_executable(frequency frequency.cpp)