#pragma once
#include<iostream>
using namespace std;
#include<assert.h>


namespace jiao {
	template<class T>
	struct List_Node {
		T _data;
		List_Node* _next;
		List_Node* _prev;
		
	};
}
