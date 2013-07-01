#include <iostream>
#include <vector>
using namespace std;

void printPrimes( int max )
{
    if( max < 2 ) return;
    
    vector<bool> flags( max+1, true );
    int prime = 2;
    
     while( prime <= max ) {
         for( int i = 2*prime; i <= max; i += prime ) {
             flags.at(i) = false;
         }
         
         int next = prime+1;
         while( next <= max && flags.at(next) == false ) ++next;
         prime = next;
         
     }

    for( unsigned int i = 2; i < flags.size(); ++i ) {
        if( flags.at(i) == true ) cout << i << ", ";
    }
    cout << endl;
}

int main()
{
   printPrimes( 20 ); 
   
   return 0;
}
