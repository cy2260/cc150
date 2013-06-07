
int getLeftChild( int idx ) {
    return 2*idx+1;
}
int getRightChild( int idx ) {
    return 2*idx+2;
}
int getParent( int idx ) {
    return (idx-1)/2;
}

void siftUp( int* arr, int rootIdx, int endIdx ) {
    if( !arr ) return;

    while( getLeftChild(rootIdx) < endIdx ) {
        int leftIdx  = getLeftChild( rootIdx );
        int rightIdx = getRightChild( rootIdx );
        int swapIdx  = rootIdx;
        
        if( arr[leftIdx] > arr[rootIdx] ) {
            swapIdx = leftIdx;
        } 
        if( rightIdx <= endIdx && arr[rightIdx] > arr[swapIdx] ) {
            swapIdx = rightIdx;
        }
        
        if( rootIdx == swapIdx ) {
            break; //root is the max value
        }
        else {
            swap( arr[rootIdx], arr[swapIdx] );
            rootIdx = swapIdx; //check if its subtree satisfy heap property
        }
    }    
}

void maxHeapify( int* arr, int startIdx, int endIdx ) {
    if( !arr ) return;
    
    //this is the last node that has child/children
    //last element is either its left child or right child
    int rootIdx = ( endIdx - startIdx ) / 2;
    while( rootIdx >= 0 ) {
        siftUp( arr, rootIdx, endIdx );
        --rootIdx;
    }
}

void heapSort( int* arr, int len ) {
    if( !arr ) return;
    
    maxHeapify( arr, 0, len-1 );
    
    int i = len - 1;
    while( i > 0 ) {
        swap( arr[i], arr[0] );
        --i;
        siftUp( arr, 0, i );
    }
}

