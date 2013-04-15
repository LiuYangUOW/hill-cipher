#include "Hill.cpp"
using namespace std;

int main()
{    
        
    Hill h;
    int size;
    
    cout<<"Please enter size of matrix: ";
    cin>>size;
        
    h.setSize(size);
    
    h.setKey(0,1,4);
    h.setKey(1,0,1); h.setKey(1,1,3);
    
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            int value;
            cout<<"enter key["<<i+1<<"]["<<j+1<<"]: ";
            cin>>value;
            h.setKey(j,i,value);
        }
    
    cout<<endl<<endl;
    cout<<"your key is:"<<endl;
    cout<<h.getKey()<<endl<<endl;
    
    char choice;
    cout<<"encryption or decryption (e/d)? ";
    cin>>choice;
    
    if ( choice == 'e' )
        h.encryption();
    else if ( choice == 'd' )
        h.decryption();
     
    return 0;
}
