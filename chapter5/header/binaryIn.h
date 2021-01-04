#ifndef BINARY_IN_ESPEON
#define BINARY_IN_ESPEON

#include<iostream>
#include<fstream>
#include<string>
#include<exception>
#include<stdexcept>

using namespace::std;

class BinaryIn {
public:
    BinaryIn(string name) {
        inFile.open(name, ios_base::binary|ios_base::in);
        fillBuffer();
    }

    ~BinaryIn() {inFile.close(); }

    void fillBuffer() {
        buffer = inFile.get();//read one character;
        n = 8;
    }

    bool readBool() {
        if (isEmpty()) throw runtime_error("Reading from empty input stream");
        n--;
        bool bit = ((buffer >> n) & 1) == 1;
        if (n == 0) fillBuffer();
        return bit;
    }

    char readChar() {
        if (isEmpty()) throw runtime_error("Reading from empty input stream");

        // special case when aligned byte
        if (n == 8) {
            char x = buffer;
            fillBuffer();
            return (char) (x & 0xff);
        }

        // combine last N bits of current buffer with first 8-N bits of new buffer
        char x = buffer;
        x <<= (8 - n);
        int oldN = n;
        fillBuffer();
        if (isEmpty()) throw runtime_error("Reading from empty input stream");
        n = oldN;
        x |= *(unsigned char*)&buffer >> n;
        return (char) (x & 0xff);
        // the above code doesn't quite work for the last character if N = 8
        // because buffer will be -1
    }

    int readInt() {
        int x = 0;
        for (int i = 0; i < 4; i++) {
            char c = readChar();
            x <<= 8;
            x |= c;
        }
        return x;
    }

    string readString() {
        if (isEmpty()) throw runtime_error("Reading from empty input stream");

        string sb("");
        while (!isEmpty()) {
            char c = readChar();
            sb+=c;
        }
        sb+='\0';
        return sb;
    }

    bool isEmpty() {
        return inFile.peek() == EOF;
    }

private:
    char buffer;// one character buffer
    ifstream inFile;// the input stream                 
    int n;      // number of bits left in buffer
    
};

#endif