vector<vector<int>> threeSum(vector<int>& a) 
{
  sort(a.begin(),a.end());
	int n=a.size();
	if(n==0) return {};
	vector< vector <int>> result;

	for(int i=0;i<n-2;i++){
		int left=i+1;
		int right=n-1;

		if(i!=0 and a[i]==a[i-1])
			continue;
		while(left<right){

			int tar=a[i]+a[left]+a[right];
			if(tar==0){
				result.push_back(vector<int>{a[i],a[left],a[right]});
        //check right and left are duplicated
				while(right-1>=left and a[right-1]==a[right]) right--;
        while(left+1<right && a[left+1]==a[left] ) left++;
				left++;
				right--;
			}
			else if(tar>0){
				right--;
			}
			else{
				left++;
			}
		}
		
		
	}
	
        return result;
}
