//Euclid's algorithm
//both x and y are non negative

int gcd( int x, int y ) {
    if( y == 0 )      return x;
    else if( x >= y ) return gcd( y, x%y );
    else              return -1;
}
