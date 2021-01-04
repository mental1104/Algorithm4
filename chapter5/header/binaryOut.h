#ifndef BINARY_OUT_ESPEON
#define BINARY_OUT_ESPEON

#include<iostream>
#include<fstream>
#include<string>
#include<exception>
#include<stdexcept>
#include<cassert>

using namespace::std;

class BinaryOut {
private:
    ofstream out;  // the output stream
    char buffer = 0;                // 8-bit buffer of bits to write out
    int n = 0;                     // number of bits remaining in buffer
public:

    BinaryOut(string filename) {   out.open(filename, ios::binary|ios::out);  }
    ~BinaryOut()    {   out.close();  }

    void writeBit(bool x) {
        // add bit to buffer
        buffer <<= 1;
        if (x) buffer |= 1;

        // if buffer is full (8 bits), write out as a single byte
        n++;
        if (n == 8) clearBuffer();
    } 

   
    void writeByte(char x) {
        assert(x >= 0 && x < 256);

        // optimized if byte-aligned
        if (n == 0) 
            out.write(&x, sizeof(char));
        return;

        // otherwise write one bit at a time
        for (int i = 0; i < 8; i++) {
            bool bit = ((*(unsigned*)&x >> (8 - i - 1)) & 1) == 1;
            writeBit(bit);
        }
    }

    // write out any remaining bits in buffer to the binary output stream, padding with 0s
    void clearBuffer() {
        if (n == 0) return;
        if (n > 0) buffer <<= (8 - n);
        out.write(&buffer,sizeof(char));

        n = 0;
        buffer = 0;
    }

    void write(bool x) {
        writeBit(x);
    } 

    void write(int x) {
        unsigned temp = *(unsigned*)&x;
        writeByte((temp >> 24) & 0xff);
        writeByte((temp >> 16) & 0xff);
        writeByte((temp >>  8) & 0xff);
        writeByte((temp >>  0) & 0xff);
    }

    void write(char x) {
        if (x < 0 || x >= 256) throw runtime_error("Illegal 8-bit char = ");
        writeByte(x);
    }

    void write(string s) {
        for (int i = 0; i < s.length(); i++)
            write(s[i]);
    }

};

#endif