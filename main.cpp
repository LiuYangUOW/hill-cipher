#include "Hill.cpp"
using namespace std;

int main()
{    
        
    Hill h;
        
    h.setSize(2);    
    
    h.setKey(0,0,3); h.setKey(0,1,4);
    h.setKey(1,0,1); h.setKey(1,1,3);
    
    //h.encryption();
    h.decryption();
     
    return 0;
}
