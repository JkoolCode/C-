#include <iostream>
#include <list>
#include <functional>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

template <typename T1>
class HashTable{
private:
	int BUCKET;
	list<T1> *table;
	int sizeCount;
public:
	HashTable(int n): sizeCount(0) {
		this->BUCKET = n;
		table = new list<T1>[n]; //It's an Array List of Pairs
	}
	int size(){ return sizeCount; }

	int hashFunction(T1 key){
		std::hash<T1> hash_fn;
		size_t rs_hash = hash_fn(key);
		return (rs_hash % this->BUCKET);
	}
	
	void insert(T1 item){
		int index = hashFunction(item);
		auto it = table[index].begin();
		for(; it != table[index].end(); it++){
			if(*it == item)
				break;
		}
		if(it == table[index].end()){
			table[index].push_back(item);
			this->sizeCount++;
		}else{
			*it = item;
		}
		//If load factor goes beyond threshold, then double hash table size 
		 if((size()*1.0) / this->BUCKET >= 0.7){
			 list<T1> *tmp;
			 this->BUCKET *= 2;
			 tmp = table;
			 table = new list<T1>[BUCKET]; //This is an Array of List 
			 this->sizeCount = 0;
			 
			 for(int i=0; i < this->BUCKET/2; i++)
				 for(auto it : tmp[i])
					 insert(it);
		 }
	}
	
	const T1 get(T1 key){
		int index = hashFunction(key);
		auto it = table[index].begin();
		for(; it != table[index].end(); it++){
			if(*it == key)
				return *it;
		}
		return *it;
	}
};

int main()
{
	int arr[] = {1, 7, 5, 9, 2, 12, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	signed int c = 0;
	const signed short k = 2;
	HashTable<int> h(n);
	FOR(i, n) h.insert(arr[i]);
	
	FOR(i, n)
		if(h.get(arr[i]+k)) c++;
	
	cout << c << endl;
	
	return 0;
}
