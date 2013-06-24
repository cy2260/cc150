void mergeSort( int* arr, int* tmpArr, int left, int right ) {
    if( left < right ) {
        int mid = left + ( right - left )/2;
	mergeSort( arr, tmpArr, left, mid );
	mergeSort( arr, tmpArr, mid+1, right );
	merge( arr, tmpArr, left, mid, right );
    }
}

void merge( int* arr, int* tmpArr, int left, int mid, int right ) {
    int leftEnd  = mid;
    int rightEnd = right;
    int leftIdx  = left;
    int rightIdx = mid+1;
    int tmpIdx   = left;

    while( leftIdx <= leftEnd || rightIdx <= rightEnd ) {
        if( leftIdx <= leftEnd && rightIdx <= rightEnd ) {
	    if( arr[leftIdx] <= arr[rightIdx] ) {
	        tmpArr[tmpIdx] = arr[leftIdx];
		++leftIdx;
	    }
	    else {
	        tmpArr[tmpIdx] = arr[rightIdx];
		++rightIdx;
	    }
	}
	else if( leftIdx <= leftEnd ) {
	    tmpArr[tmpIdx] = arr[leftIdx];
            ++leftIdx;
        }
	else {
	    tmpArr[tmpIdx] = arr[rightIdx];
	    ++rightIdx;
	}
	++tmpIdx;
    }

    while( left <= right ) {
        arr[left] = tmpArr[left];
	++left;
    }
}

void mergeSort( int* arr, int len ) {
    int* tmpArr = new int[len];
    mergeSort( arr, tmpArr, 0, len-1 );
    delete[] tmpArr;
}
