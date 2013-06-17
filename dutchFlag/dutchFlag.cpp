void dutchFlag( vector<int>& nums ) {
    if( nums.empty() ) return;
    
    int low  = 0;
    int high = nums.size()-1;
    int idx  = 0;
    
    while( idx <= high ) {
        if( nums[idx] == 0 ) {
            swap( nums[idx], nums[low] );
            ++low;
            ++idx;
        }
        else if( nums[idx] == 2 ) {
            swap( nums[idx], nums[high] );
            --high;
        }
        else {
            ++idx;
        }
    }
}
