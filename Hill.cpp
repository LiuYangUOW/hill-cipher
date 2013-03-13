#include "Hill.h"
#include <cctype>
#include "Eigen/LU"
#include "Eigen/Dense"

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
    
    inputFile.open("plain.txt");
    outputFile.open("cipher.txt");
        
    if(!check_key(key.determinant()))
        {
            std::cout<<"invalid key";
            return;
        }
    
    while( getline(inputFile, tmp) )
    {
        tmp = prepare(tmp);
        
        if( tmp.length()%size != 0)
            for(unsigned int i=0;i<(tmp.length()%size);i++)
                tmp+='a';
                
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
            {
                float temp2 = c(i,0);
                buffer += int(temp2)%26+'a';
            }
            
            outputFile << buffer;
        }
        outputFile << '\n';        
    }        
}

void Hill::decryption()
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string tmp;
    std::string buffer="";
    
    inputFile.open("cipher.txt");
    outputFile.open("plain.txt");
    
    while( getline(inputFile, tmp) )
    {
        for(unsigned int i=0;i<tmp.length();i+=size)
        {
            MatrixXd c= MatrixXd(size,1);
            MatrixXd p;
            MatrixXd adj_key;            
            int det_1;              
            int det = key.determinant();
            int temp;
            buffer="";
                                    
            if(det<0)
                det += 26;
            
            det_1 = check_key(det);
            if(det_1==0)
            {
                std::cout<<"invalid key";
                return;
            }
            
            for(int j=0;j<size;j++)
                if( i+j < tmp.length() )
                    c(j,0) = tmp.at(i+j)-'a';
            
            
                
            adj_key = (det_1*det)*key.inverse();
            p = adj_key*c;
                                    
            for(int i=0;i<size;i++)
            {
                float temp2 = p(i,0);
                temp = int(temp2)%26;
                if( temp >= 0)
                    buffer += temp+'a';
                else
                    buffer += temp+26+'a';
            }
            outputFile << buffer;
        }        
        outputFile << '\n';
    }
}

int Hill::check_key(int det)
{
    for(int cnt=1;cnt<26;cnt++)
    {
        if( ((cnt*det)%26) == 1)
            return cnt;
        if(cnt==25)
            return 0;
    }
    return 0;
}
