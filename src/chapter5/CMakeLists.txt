file(COPY ${PROJECT_SOURCE_DIR}/src/chapter5/testfile 
     DESTINATION ${PROJECT_BINARY_DIR}/bin/chapter5/)

add_executable(BM BM.cpp)
add_executable(grep grep.cpp)
add_executable(huffman huffman.cpp)
add_executable(KMP KMP.cpp)
add_executable(LSD LSD.cpp)
add_executable(MSD MSD.cpp)
add_executable(quick3way quick3way.cpp)
add_executable(RK RK.cpp)
add_executable(Tries Tries.cpp)
add_executable(TST TST.cpp)