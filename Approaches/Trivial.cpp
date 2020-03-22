#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

int main()
{
	int arr[] = {1, 7, 5, 9, 2, 12, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	signed int c = 0;
	const signed short k = 2;
	
	FOR(i, n)
		FOR(j, n)
			if(arr[i] - arr[j] == k) c++;
	
	cout << c << endl;
	
	return 0;
}
