#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;
bool OutofOrder(vector<int> arr,int i){
	int x=arr[i];
	//check if arr[i+1] is bigger than arr[0]
	if(i==0){
		//trigger when this 
		return x > arr[i];
	}
	//check last place
	int n=arr.size();
	if(i==n-1){

		//trigger when this, if last place is lesser than last-n

		return x < arr[i-1];
	}
	//middle condition, while x is bigger than next num, or lesser than previous num
	return (x > arr[i+1]) or (x < arr[i-1]);

}
pair<int,int> subarraysort(vector<int> &arr){
	
	//set smallest and largest
	int smallest=	INT_MAX;
	int largest=	INT_MIN;

	int n=arr.size();
	
	//run through loop
	for(int i=0;i<n;i++){
		//mark on arr[i] and comparison
		int x=arr[i];
		//check condition 
		if(OutofOrder(arr,i)){
			smallest=min(smallest,x);
			largest=max(largest,x);
		}

	}
	
	//locate the smallest and largest
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

}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraysort(arr);
    cout<< p.first <<" and "<<p.second <<endl;

    return 0;
}
