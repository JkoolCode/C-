#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

bool binarySearch(const int *arr, int n, int val){
	int l = 0;
	int r = n-1;
	int ind;
	while(l <= r){
		ind = (l+r) * 0.5;
		if(arr[ind] > val)
			r = ind - 1;
		else
			if(arr[ind] < val)
				l = ind + 1;
			else
				return 1;
	}
	return 0;
}

int main()
{
	int arr[] = {1, 7, 5, 9, 2, 12, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	signed int c = 0;
	const signed short k = 2;
	
	sort(arr, arr+n);
	FOR(i, n)
		if(binarySearch(arr, n,arr[i]+k)) c++;
	
	cout << c << endl;
	
	return 0;
}
