int partition( int* arr, int low, int high ) {
    int pivot = arr[low+(high-low)/2];

    while( low < high ) {
        while( arr[low]  < pivot ) ++low;
	while( arr[high] > pivot ) --high;

	if( arr[low] == arr[high] ) ++low;
	else if( low < high ) swap(arr[low], arr[high]);
    }
    return high;
}

void quickSort( int* arr, int low, int high ) {
    if( low < high ) {
        int pivodIdx = pivot( arr, low, high );
	quickSort( arr, low, pivotIdx-1 );
	quickSort( arr, pivot+1, high );
    }
}

void quickSort( int* arr, int len ) {
    if( !arr ) return;

    quickSort( arr, 0, len-1 );
}

