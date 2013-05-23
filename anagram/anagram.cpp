bool isAnagram( char* a, char* b ) {
    if( !a || !b ) return false;

    int aLen = strlen(a);
    int bLen = strlen(b);

    if( aLen != bLen ) return false;

    int* charMap = new int[128];

    for( int i = 0; i < aLen; ++i ) {
        charMap[a[i]] += 1;
	charMpa[b[i]] -= 1;
    }

    for( int i = 0; i < aLen; ++i ) {
        if( charMap[i] != 0 ) return false;
    }

    return true;
}
