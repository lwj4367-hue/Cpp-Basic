#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

//class Student
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		// ...
//	}
//	// 学习
//	void study()
//	{
//		// ...
//	}
//protected:
//	string _name = "peter"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//	int _age = 18; // 年龄
//	int _stuid; // 学号
//};
class Teacher
{
public:
	// 进入校园/图书馆/实验室刷二维码等身份认证
	void identity()
	{
		// ...
	}
	// 授课
	void teaching()
	{
		//...
	}
protected:
	string _name = "张三"; // 姓名
	int _age = 18; // 年龄
	string _address; // 地址
	string _tel; // 电话
	string _title; // 职称
};
class Person
{
public:
	// 进入校园/图书馆/实验室刷二维码等身份认证
	void identity()
	{
		cout << "void identity()" << _name << endl;
	}
protected:
	string _name = "张三"; // 姓名
	string _address; // 地址
	string _tel; // 电话
	int _age = 18; // 年龄

};
class Student : public Person{


public:
	// 学习
	void study()
	{
		// ...
	}
protected:
	int _stuid; // 学号
};
class Teacher : public Person
{
public:
	// 授课
	void teaching()
	{
		//...
	}
protected:
	string title; // 职称
};
void test2() {

}
int main()
{
	Student s;
	Teacher t;
	s.identity();
	t.identity();
	return 0;
}

