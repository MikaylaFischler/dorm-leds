#include "LocalStack.cpp"
#include <iostream>
#include <stdlib.h> 

using namespace std;

int main(){
	LocalStack* stack = new LocalStack();
	
	long int a = 0;
	char b = 'c';
	bool c = false;
	bool d[3] = {false,false,true};
	
	//{false, false, true};
	
//	cout << &a << endl;
	
	stack->push(&a);
	stack->push(&b);
	stack->push(&c);
	stack->push(&d);
	/*for(int i = 0; i < 61685135; i++){
		stack->push(&c);
		//stack->drop(0);
	}
	cout << stack->get(0) << endl;
	cout << stack->get(1) << endl;
	cout << stack->get(2) << endl;
	
	
	void* z = stack->get(0);
	
	int* x = (int*) z;
	
	cout << *x << endl;
	*/
	for(int i = 0; i < 100; i++){
		int val = stack->getInt(0);
		val++;
		stack->update(0, &val);
	}
	cout << stack->getInt(0) << endl;
	cout << stack->getChar(1) << endl;
	cout << stack->getBool(2) << endl;
	/*
	bool* x = stack->getBoolArray(3);
	
	for(int i = 0; i < 3; i++){
		cout << x[i] << endl;
	}
	*/
	//stack->drop(0);
	
	free(stack);
	
	return 0;
}
