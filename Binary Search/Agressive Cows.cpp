#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
bool canPlaceCows(int a[], int n, int cows, int mid ){
 
	int count = 1, coord = a[0];
	for(int i = 1; i<n; i++){
		if((a[i] - coord) >= mid){
			coord = a[i];
			count++;
		}
 
	}
	if(count >= cows){
			return true;
	}
	return false;
 
}
 
int main() {
	// your code goes here
 
	int t;
	cin>>t;
	while(t--){
 
		int cows, n;
		cin>>n>>cows;
		int a[n];
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
 
		sort(a, a+n);
 
		int low = 1, high = a[n-1] - a[0];
 
		while(low <= high){
			int mid = (low + high)>>1;
 
			if(canPlaceCows(a, n, cows, mid)){
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		cout<<high<<endl;
 
	}
 
	return 0;
}
