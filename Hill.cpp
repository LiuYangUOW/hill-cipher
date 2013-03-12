#include "Hill.h"
#include <cctype>

//using namespace std;

/*************************Constructors*********************************/
Hill::Hill()
{
    size = 2;
    key = MatrixXd::Random(size, size);    
}

Hill::Hill(int sz)
{   
    size = sz; 
    key = MatrixXd::Random(sz, sz);
}
/*************************Constructors*********************************/

/*********************setters and getters******************************/
void Hill::setKey(int col, int row, int val)
{
    key(row, col) = val;
}

void Hill::setSize(int sz)
{
    size = sz;
    key = MatrixXd::Random(sz, sz);
}

MatrixXd Hill::getKey()
{
    return key;
}
/*********************setters and getters******************************/

std::string Hill::prepare(std::string plain)
{
    std::string str="";
    for(unsigned int i=0;i<plain.length();i++)
        if( isalpha(plain.at(i)) )
            str += std::tolower( plain.at(i) );
                                            
    return str;
}

void Hill::encryption()
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string tmp;
    std::string buffer="";
    
    inputFile.open("plaint.txt");
    outputFile.open("cipher.txt");
    
    while( getline(inputFile, tmp) )
    {
        tmp = prepare(tmp);
        for(unsigned int i=0;i<tmp.length();i+=size)
        {
            MatrixXd p= MatrixXd(size,1);
            MatrixXd c;
            for(int j=0;j<size;j++)
                if( i+j < tmp.length() )
                    p(j,0) = tmp.at(i+j)-'a';            
            
            c = key*p;            
            buffer="";
            for(int i=0;i<size;i++)
                buffer += int(c(i,0))%26+'a';
            
            std::cout<<buffer<<std::endl;
            outputFile << buffer;
        }
        outputFile << '\n';
    }        
}

void Hill::decryption()
{
    
}
