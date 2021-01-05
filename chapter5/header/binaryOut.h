#ifndef BINARY_OUT_ESPEON
#define BINARY_OUT_ESPEON

#include<iostream>
#include<fstream>
#include<string>
#include<exception>
#include<stdexcept>
#include<cassert>
#include<bitset>
#include<vector>

using namespace::std;

class BinaryOut {
private:
    ofstream out;  // the output stream
    int buffer = 0;                // 8-bit buffer of bits to write out
    int n = 0;                     // number of bits remaining in buffer
    vector<bitset<8>> sum;
public:

    BinaryOut(string filename) {   out.open(filename, ios::out|ios::binary);  }
    ~BinaryOut()    {   out.close();  }

    void writeBit(bool x) {
        // add bit to buffer
        buffer <<= 1;
        if (x) buffer |= 1;

        // if buffer is full (8 bits), write out as a single byte
        n++;
        if (n == 8) clearBuffer();
    } 

   
    void writeByte(bitset<8> x) {

        if (n == 0) {
            unsigned long n = x.to_ulong();
            out.write(reinterpret_cast<const char*>(&n), sizeof(char));
            return;
        }
        

        // otherwise write one bit at a time
        for (int i = 0; i < 8; i++) {
            bool bit = x[7-i];
            writeBit(bit);
        }
    }

    // write out any remaining bits in buffer to the binary output stream, padding with 0s
    void clearBuffer() {
        if (n == 0) return;
        if (n > 0) buffer <<= (8 - n);
        bitset<8> temp(buffer);
        out.write(reinterpret_cast<const char*>(&temp),sizeof(char));

        n = 0;
        buffer = 0;
    }

    void write(bool x) {
        writeBit(x);
    } 

    void write(vector<bitset<8>> x) {
        for(bitset<8> i:x)
            writeByte(i);
    }

    void write(bitset<8> x) {
        writeByte(x);
    }

    void write(string s) {
        for (int i = 0; i < s.length(); i++)
            write(s[i]);
    }

};

#endif