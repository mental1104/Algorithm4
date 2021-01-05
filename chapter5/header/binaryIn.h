#ifndef BINARY_IN_ESPEON
#define BINARY_IN_ESPEON

#include<iostream>
#include<fstream>
#include<string>
#include<exception>
#include<stdexcept>
#include<bitset>
#include<vector>

using namespace::std;

class BinaryIn {
public:
    BinaryIn(string name) {
        inFile.open(name, ios_base::binary|ios_base::in);
        fillBuffer();
    }

    ~BinaryIn() {inFile.close(); }

    void fillBuffer() {
        if(inFile.eof())
            buffer = EOF;
        else{
            buffer = inFile.get();//read one character.;
            n = 8;
        }
    }

    bool readBool() {
        n--;
        bool bit = ((buffer >> n) & 1) == 1;
        if (n == 0) fillBuffer();
        return bit;
    }

    bitset<8> readChar() {

        // special case when aligned byte
        if (n == 8) {
            int x = buffer;
            fillBuffer();
            bitset<8> temp(x);
            return temp;
        }

        // combine last N bits of current buffer with first 8-N bits of new buffer
        int x = buffer;
        x <<= (8 - n);
        int oldN = n;
        fillBuffer();
        if (isEmpty()){
            return bitset<8>(x);
        }
        n = oldN;
        unsigned int temp = *(unsigned int*)&buffer;
        x |= (temp >> n);
        return bitset<8>(x);
        // the above code doesn't quite work for the last character if N = 8
        // because buffer will be -1
    }

    vector<bitset<8>> readInt() {
        vector<bitset<8>> x;
        for (int i = 0; i < 4; i++) {
            bitset<8> c = readChar();
            x.push_back(c);
        }
        return x;
    }

    vector<bitset<8>> readString() {

        vector<bitset<8>> sb;
        while (!isEmpty()) {
            bitset<8> c = readChar();
            sb.push_back(c);
        }
        return sb;
    }

    bool isEmpty() {
        return buffer == EOF;
    }

private:
    int buffer;// one character buffer
    ifstream inFile;// the input stream                 
    int n = 0;      // number of bits left in buffer
    
};

#endif