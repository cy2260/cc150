int binarySearchLowerBound( int A[], int n, int target ) {
    if( !A ) return -1;

    int low = 0;
    int high = n-1;

    while( low <= high ) {
        int mid = low+(high-low)/2;
        if( A[mid] >= target ) high = mid - 1;
        else                   low  = mid + 1;
    }

    return high+1;
}

