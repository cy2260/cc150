void randomPermutation( vector<int>& vec ) {
    if( vec.size() < 2 ) return;

    srand(time(NULL));

    for( int i = vec.size() - 1; i >= 0; --i ) {
        int idx = rand()%(i+1);
	swap( &vec[i], &vec[idx] );
    }
}
