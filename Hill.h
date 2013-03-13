#include <string>
#include <iostream>
#include <fstream>
#include "Eigen/Core"

using namespace Eigen;

class Hill
{
    private:
        int size;//size of matrix key        
        MatrixXd key;        
        
    public:        
        //setter and getter
        Hill();
        Hill(int);
        
        double getKey(int, int);
        MatrixXd getKey();
        
        void setKey(int, int, int);
        void setSize(int);
                
        std::string prepare(std::string);        
        int check_key(int);
        void encryption();
        void decryption();                
};
