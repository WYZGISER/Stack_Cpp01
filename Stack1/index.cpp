#include<iostream>
#include<stdlib.h>
#define STACK_INIT_SIZE 100//定义栈的初始化大小为100
#define STACKINCREMENT 10//如果不够就加10个
using namespace std;

typedef int SElemType;//定义SelemType的类型


typedef struct {
	SElemType* base;//栈底
	SElemType* top;//栈顶
	int staclzize;//记录栈的总大小
}SqStack;

//初始化函数
void InitStack(SqStack &st) {//形参引用内存的东西（直接操控内存）
	st.base = new SElemType[STACK_INIT_SIZE];
	//栈顶指向第一个空间
	st.top = st.base;
	//初始化栈的总大小
	st.staclzize = STACK_INIT_SIZE;//栈目前所占用空间的大小，而不是存多少数
	int num;//定义要存入栈的数量
	cin >> num;//输入要存入栈的数量 

	//空间不够用的情况下
	while (num>st.staclzize) {
		cout << "你输入的大小不能超过我的初始化大小" << endl;
		cin >> num;//重新输入
		
	}
	for (int i = 0; i < num; i++)
	{
		cin >> *st.top;//因为st.top是一个指针，所以要取指针
		st.top++;//每输入一个栈顶往上走一格
	}
}

//入栈操作
void Push(SqStack &st, SElemType put) {//st需要操控内存，put不需要操控内存
	if (st.top-st.base>=st.staclzize)//栈溢出
	{
		st.base = (SElemType*)realloc(st.base, ((st.top - st.base) + STACKINCREMENT) * sizeof(SElemType));//栈扩充空间(扩充st.base)
		if (!st.base)//分配内存失败
		{
			return;
		}
		//开辟内存成功
		st.top = st.base + st.staclzize;
		st.staclzize += STACKINCREMENT;

	}

	*st.top++ = put;
}

//出栈操作
void Pop(SqStack &st,SElemType get) {
	get = *(st.top - 1);
	st.top--;

}

//查找操作
void GetTop(SqStack& st,SElemType read) {
	read = *(st.top - 1);
}

//判断栈是否为空栈
bool StackEmpty(SqStack &st) {
	if (st.top == st.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearStack(SqStack& st) {
	st.top = st.base;
}


int main()
{	
	//创建一个栈
	SqStack st;
	//初始化
	InitStack(st);

	SElemType put;//增
	Push(st,put);//入栈(添加数据)

	SElemType get;//删
	Pop(st, get);//出栈(删除数据)
	cout << get << endl;

	SElemType read;
	GetTop(st,read);//查

	//判断栈是否为空栈
	if (StackEmpty(st))
	{
		cout << "栈空" << endl;
	}
	else
	{
		cout << "栈不空" << endl;
	}

	//清空栈
	ClearStack(st);

	system("pause");
	return 0;
}

