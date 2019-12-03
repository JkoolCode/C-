#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#define FOR(i, x) for(int i=0; i<x; i++)
using namespace std;

template<class T>
struct Nodo{
	Nodo *left, *right;
	T value;
	Nodo(){ left = right = nullptr; }
};
Nodo<string> *root;

signed int getINT(const string n){
	signed int rs = 0, len = n.size();
	FOR(i, len) rs = rs*10+(n[i]-'0');
	return rs;
}

string getStr(const int i)	
{
	stringstream s;
	s << i;
	return s.str();
}

void create(Nodo<string> *root){
	signed short r;
	cout << "Ingrese valor: "; cin >> root->value;
	cout << "Crear nodo IZQ (1. Si, 2. No): "; cin >> r;
	if(r & 1){
		root->left = new Nodo<string>();
		create(root->left);
	}else{
		root->left = nullptr;
	}
	cout << "Crear nodo DER (1. Si, 2. No): "; cin >> r;
	if(r & 1){
		root->right = new Nodo<string>();
		create(root->right);
	}else{
		root->right = nullptr;
	}
}

void operation(Nodo<string> *root){
	if(root->value == "+")
			root->value = getStr(getINT(root->left->value) + getINT(root->right->value));
	if(root->value == "-")
		root->value = getStr(getINT(root->left->value) - getINT(root->right->value));
	if(root->value == "*")
	root->value = getStr(getINT(root->left->value) * getINT(root->right->value));
	if(root->value == "/")
		root->value = getStr(getINT(root->left->value) / getINT(root->right->value));
	if(root->value == "^")
		root->value = getStr(pow(getINT(root->left->value), getINT(root->right->value)));
}

void solve(Nodo<string> *root){
	if(root != nullptr){
		solve(root->left);
		solve(root->right);
		operation(root);
	}
}

int main()
{
	root = new Nodo<string>();
	create(root);
	solve(root);
	cout << "Result: " << root->value << endl;
	
	return 0;
}
