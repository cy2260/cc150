
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
        
    }    
}

void maxHeapify( int* arr, int len ) {
    if( !arr ) return;
    
    //this is the last node that has child/children
    //last element is either its left child or right child
    int rootIdx = ( len - 1 ) / 2;
    while( rootIdx >= 0 ) {
        siftUp( arr, rootIdx, len-1 );
        --rootIdx;
    }
}
