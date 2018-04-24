#include<iostream>
using namespace std;
class B;

class A{
	int a[5]={1,2,5,4,5};
	friend bool comp(A a_obj, B b_obj);
};

class B{
	int b[5]={1,2,3,4,5};
	friend bool comp(A a_obj, B b_obj);
};

bool comp(A a_obj, B b_obj){
	bool result=true;
	for(int i=0; i<5; i++){
		if(a_obj.a[i]!=b_obj.b[i])
			result = false;
	}
	return result;
}

int main(){
	A a_obj ;
	B b_obj ;
	if(comp(a_obj, b_obj)){
		cout<<"Equal.";
	}
	else{
		cout<<"defferent.";
	}
	return 0;
}
