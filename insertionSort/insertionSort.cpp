void insertionSort( int* arr, int len ) {
    if( !arr ) return;

    for( int i = 1; i < len; ++i ) {
        int j = i;
	//invariant: arr[1..i] is sorted
	while( j > 0 && arr[j-1] > arr[j] ) {
	    swap( arr[j-1], arr[j] );
	    --j;
	}
    }
}
