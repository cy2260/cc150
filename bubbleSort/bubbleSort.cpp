void bubbleSort( int* arr, int len ) {
    if( !arr ) return;
    
    for( int i = 1; i < len; ++i ) {
        bool isSwapped = false;
        for( int j = len - 1; j >= i; --j ) {
            if( arr[j-1] > arr[j] ) {
                swap( arr[j-1], arr[j] );
                isSwapped = true;
            }
        }
	//invariant: arr[1..i] is sorted
        if( !isSwapped ) break; //if nothing swapped, array is sorted
    }
}
