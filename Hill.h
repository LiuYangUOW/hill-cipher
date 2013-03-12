#include <string>
#include <iostream>
#include "Eigen/Core"
#include "Eigen/Dense"

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
        double getMatrix(int, int);
        MatrixXd getKey();
        void setMatrix(int, int, int);
        
        //prepare
        std::string prepare(std::string);
        
        void encryption();
        void decryption();                
};
