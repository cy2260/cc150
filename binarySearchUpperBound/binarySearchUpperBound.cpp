int binarySearchUpperBound( int A[], int n, int target ) {
    int low  = 0;
    int high = n-1;
    while( low <= high ) {
        int mid = low + (high-low)/2;
        if( A[mid] <= target ) low  = mid + 1;
        else                   high = mid - 1;
    }
    return (low-1);
}
