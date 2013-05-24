void reverseSentense( char* str, int len ) {
    if( !str ) return;

    reverse( str, len );

    int startIdx = 0;
    int endIdx   = 0;

    while( startIdx < len ) {
        while( str[endIdx] != '\0' && str[endIdx] != ' ' ) 
	    ++endIdx;

	reverse( str+startIdx, endIdx-startIdx );
	
	++endIdx;
	startIdx = endIdx;
    }
}

