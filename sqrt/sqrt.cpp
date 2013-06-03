double sqrt( double x ) {
    if( x < numeric_limits<double>::epsilon() &&
        x > -numeric_limits<double>::epsilon() ) {
        return x;
    }

    //allowable error, estimation
    double epsilon = 0.0001; //or numeric_limits<double>::epsilon()

    double low = 0;
    double upper = x/2 + 1;

    while( low <= upper ) {
        double mid = low + (upper-low)/2;

	if( mid*mid <= x + epsilon && mid*mid >= x - epsilon ) {
	    return mid;
	}
	else if( mid*mid < x ) low   = mid;
	else                   upper = mid;
    }

    return upper; //always return end b/c upper*upper < x
}
