int numOfSquares( int rows, int cols ) {
    int result = 0;
    while( rows && cols ) {
        result += rows*cols;
        --rows;
        --cols;
    }
    return result;
}
