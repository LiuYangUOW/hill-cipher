#include "Hill.h"
#include <cctype>

using namespace std;

Hill::Hill()
{
    size = 2;
    key = MatrixXd::Random(size, size);
}

Hill::Hill(int size)
{    
    key = MatrixXd::Random(size, size);
}

void Hill::setMatrix(int col, int row, int val)
{
    //key(row, col) = val;
}

string Hill::prepare(string plain)
{
    string str="";
    for(unsigned int i=0;i<plain.length();i++)
        if( isalpha(plain.at(i)) )
            str += tolower( plain.at(i) );
                                            
    return str;
}

MatrixXd Hill::getKey()
{
    return key;
}
