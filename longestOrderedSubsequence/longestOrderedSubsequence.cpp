int longestOrderedSubsequence( const vector<int>& seq ) {
    if( seq.size() == 0 ) return 0;
    
    vector<int> dp(seq.size(), 1);
    int longestDistance = 1;
    
    for( int i = 1; i < seq.size(); ++i ) {
        
	int tempLongest = 1;
        int currNum = seq[i];

        for( int j = 0; j < i; ++j ) {
            if( currNum > seq[j] ) {
                tempLongest = max( tempLongest, dp[j] );
            }
        }
         
        dp[i] = tempLongest+1;
        longestDistance = max( longestDistance, dp[i] );
    }
    return longestDistance;
}

