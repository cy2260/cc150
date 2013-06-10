int findMax( int a, int b ) {
    int delta = a - b;
    int isDeltaNegative = (delta >> 31) & 1;
    return a - isDeltaNegative * delta;
}
