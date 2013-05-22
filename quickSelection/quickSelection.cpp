int partition( int* arr, int low, int high ) {
   int pivot = arr[low+(high-low)/2];
   
   while( low < high ) {
       while( arr[low]  < pivot ) ++low;
       while( arr[high] > pivot ) --high;

       if( arr[low] == arr[high] ) ++low; //both equal pivot, advance low
       else( low < high )          swap(arr[low], arr[high]);
   }
   return high;
}

int quickSelect( int* arr, int low, int high, int kth ) {
    if( low == high ) return arr[low];

    int pivotIdx = patition( arr, low, high );
    if( pivotIdx == kth-1 ) return arr[pivotIdx];
    else if( pivotIdx < kth-1 ) 
        return quickSelect( arr, pivotIdx+1, high );
    else
        return quickSelect( arr, low, pivotIdx-1 );
}

int quickSelect( int* arr, int len, int kth ) {
    if( !arr ) return INT_MIN;
    if( len < kth ) return INT_MIN;
    
    return quickSelect( arr, 0, len-1, kth );
}
