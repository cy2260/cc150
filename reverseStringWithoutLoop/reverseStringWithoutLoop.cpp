void reverseWithoutLoop( string& str, int idx ) {
    if( str.size() < 2 || idx > str.size()/2 - 1) return;

    swap( str[idx], str[str.size()-1-idx] );

    reverseWithoutLoop( str, idx+1 );
}

