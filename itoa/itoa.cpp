void itoa(char *s, int i)  {
    assert( s != NULL );
    int numOfChars = 0;
    if( i < 0 ) {
        s[0] = '-';
        numOfChars = 1;
    }
    
    int n = i;
    do {
        ++numOfChars;
        n /= 10;
    }
    while( n );
    
    int idx = numOfChars-1;
    while( i != 0 || idx == numOfChars-1 ) {
        s[idx--] = abs(i%10) + '0';
        i /= 10;
    } 
    s[numOfChars] = '\0';
    return;
}
