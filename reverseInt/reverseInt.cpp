int reverse( int n ) {
    int res = 0;
    bool isPositive = n >= 0;
    n = abs(n);
    while( n > 0 ) {
        res = 10*res + n%10;
	n = n/10;
    }

    return isPositive ? n : -n;
}
