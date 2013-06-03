string longestRepeatedSubstring( const string& str ) {
    set<string> substrSet;
    int len = str.size();

    for( int substrLen = len - 1; substrLen > 0; --substrLen ) {
        for( int startIdx = 0; startIdx <= len - substrLen; ++startIdx ) {
            string substr = str.substr( startIdx, substrLen );
            if( substrSet.count( substr ) == 0 ) {
                substrSet.insert( substr );
            }
            else {
                return substr;
            }
        }
    }
    return "";
}

string longestRepeatedSubstring( const string& str ) {
    int len = str.size();
    if( len < 2 ) return "";
    
    vector<string> suffixArray;
    for( int i = 0; i < len; ++i ) {
        suffixArray.push_back( str.substr(i) );
    }
    
    sort( suffixArray.begin(), suffixArray.end() );
    
    int maxLen = 0;
    string longestSubstr = "";
    for( int i = 0; i < suffixArray.size()-1; ++i ) {
        string substr1 = suffixArray[i];
        string substr2 = suffixArray[i+1];
        int minLen = min( substr1.size(), substr2.size() );
        for( int i = 0; i < minLen; ++i ) {
            if( substr1[i] == substr2[i] ) {
                if( maxLen < i+1 ) {
                    maxLen = i+1;
                    longestSubstr = substr1.substr(0, i+1);
                }
            }
            else {
                break;
            }
        }
    }
    return longestSubstr;
}

