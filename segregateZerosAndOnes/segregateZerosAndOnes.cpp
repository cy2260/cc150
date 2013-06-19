void segregateZerosAndOnes( vector<int>& nums )
{
    if( nums.empty() ) return;
    int low  = 0;
    int high = nums.size()-1;
    
    while( low < high ) {
        while( nums[low] == 0 && low < high )  ++low;
        while( nums[high] == 1 && low < high ) --high;
        
        if( low < high ) {
            swap( nums[low], nums[high]);
        }
    }
}
