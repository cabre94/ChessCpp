#include <iostream>
#include <vector>

using namespace std;

class A{
public:
	vector<int> v;
};

class B{
public:
	B(vector<int>& v_){
		pv = &v_;
	}
	vector<int>* pv;
};

void foo(vector<int>* v){
	for(int i=0; i < v->size(); ++i){
		cout << v->at(i) << endl;
	}
}

int main(){

	A a;
	for(int i=0; i < 5; ++i){
		a.v.push_back(i);
	}

	cout << "kk" << endl;

	B b(a.v);

	cout << "kk" << endl;

	for(int i=5; i < 10; ++i){
		a.v.push_back(i);
	}

	cout << "kk" << endl;

	for(int i=0; i < b.pv->size(); ++i){
		cout << b.pv->at(i) << endl;;
	}




	// vector<int> kk{0,1,2,3,4,5};

	// foo(&kk);


	return 0;
}