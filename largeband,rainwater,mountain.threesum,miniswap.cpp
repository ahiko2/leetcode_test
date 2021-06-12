int largestBand(vector<int> a){
	
	unordered_set<int> s;
	
	//input value into s
	for(auto x : a){
		s.insert(x);
	}
	int Largestnum=1;
	//run through the entire loop
	for(auto element : s){
	//placing first index to a number
		int parent=element-1;
		
	//search start form parent (index)	
		if(s.find(parent)==s.end()){
			int next_no=element+1;
			int count=1;
		//condition where next number is bigger than 1 or next number is not 0
		//if yes, ++;
			while(s.find(next_no)!=s.end()){
				next_no++;
				count++;
			}
			//update the num
			if(count>Largestnum){
				Largestnum = count;
			}
		}
		
	}
	return Largestnum;


}
int rainwaterr(vector<int> a){
	//get size
	int n=a.size();
	//set left, right
	vector<int> left(n,0),right(n,0);
	left[0]=a[0];
	
	right[n-1]=a[n-1];
	//make left and right max
	for(int i=1;i<n;i++){
		left[i]=max(left[i-1],a[i]);
		right[n-i-1]=max(right[n-i],a[n-i-1]);
	}
	
	
	//add water
	int water=0;
	for(int i=0;i<n;i++){
 		water += min(left[i],right[i]) - a[i];
 	}
	 return water;
	
}
int mountain(vector<int> a){

	int n=a.size();
	int result=1;

	
	
	for(int i=1;i<=n-2;){
		//check it is peak or not
		if(a[i]>a[i-1] and a[i]>a[i+1]){
			//do some work
			int cnt = 1;
			int j = i;
			//cnt backwards (left)
			while(j>=1 and a[j]>a[j-1]){
				j--;
				cnt++;
			}
			//cnt forwards (right)
			while(i<=n-2 and a[i]>a[i+1]){
				i++;
				cnt++;
			}
			result = max(result,cnt);

		}

		else{
			i++;
		}
	}


	return result;
}
class subarray{
	public:
		int sortsubarray(vector<int> &nums){

		//create temporary vector
		vector<int> temp(nums);
		//sort it
		sort(temp.begin(),temp.end());
		int n=nums.size();
		int left=0, right=n-1;
		
		//scan from left and right, while everything is in order, 
		//left++, right--

		//nums is unsorted and temp is sorted, compare those 2
		while(left<n && nums[left]==temp[left]){
			left++;
		}
		while(right>left and nums[right]==temp[right]){
			right--;
		}
		//show total
		auto result=right-left+1;
		return result;

		}

//since it is too 2 index, we are gonna used pair
int outororder(vector<int> arr, int i){
	int x=arr[i];
	if(i==0){
		//trigger when this 
		return x > arr[i];
	}
	int n=arr.size();

	if(i==n-1){
		return x < arr[i-1];
	}
	return (x > arr[i+1]) or (x < arr[i-1]);
}
pair<int,int> subarraysort_showindex(vector<int> arr){

	//get smallest and largest
	int smallest=	INT_MAX;
	int largest=	INT_MIN;

	int n=arr.size();

	for(int i=0;i<n;i++){
		//mark on arr[i] and comparison
		int x=arr[i];
		//check condition 
		if(outororder(arr,i)){
			smallest=min(smallest,x);
			largest=max(largest,x);
		}

	}
	if(smallest==INT_MAX){
		return {-1,-1};
	}
	int left=0;
	while(smallest>=arr[left]){
		left++;
	}
	int right=arr.size()-1;
	while(largest<=arr[right]){
		right--;
	}
	//return those value
	return {left,right};
	return {left,right};

}

};
class minimumswap{
	public:

	int countswap(vector<int> arr){
		//get size
		int n=arr.size();
		
		//we are going to value in and take those index value as well in second
		//arr to ap
		pair<int,int> ap[n];
		//for example,
		//unsorted arry is 
		//value	 5 4 3 2 1
		//index	 0 1 2 3 4
		for(int i=0;i<n;i++){
			//value
			ap[i].first=arr[i];
			//index
			ap[i].second=i;
		
		}
		//sort it
		sort(ap,ap+n);

		//main logic
		vector<bool> visited(n,false);
		int ans=0;
		for(int i=0;i<n;i++){
			//check if element is visited or that is in right position
			int old_pos=ap[i].second;
			if(visited[i]==true or old_pos==i){
				//skip it
				continue;
			}
			int node=	i;
			int cycle=	0;

			while(!visited[node]){
				//when get to node, mark as visited
				visited[node]=true;
				//search for next node by looking the sorted ap
				int next_node=ap[node].second;
				//then next_node become current node
				node=next_node;
				cycle+=1;

			}
			ans+=(cycle-1);
			
		}
		
		return ans;

	}
};
class threesum{
	public:
	//method 1
	vector<vector<int>> threeSum(vector<int>& a) {
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
	//method 2
	vector< vector <int>> triplet(vector<int> a){
	int tar=0;
	int n=a.size();
	sort(a.begin(),a.end());
	vector< vector <int>> result;
	for(int i=0;i<n-3;i++){
		int j=i+1;
		int k=n-1;

		//check
		while(j<k){
			int current_sum=a[i];
			current_sum+=a[j];
			current_sum+=a[k];

			if(current_sum==tar){
				result.push_back({a[i],a[j],a[k]});
				j++;
				k--;
			}
			else if(current_sum>tar){
				k--;
			}
			else{
				j++;
			}
		}
	}
	return result;
}


};
