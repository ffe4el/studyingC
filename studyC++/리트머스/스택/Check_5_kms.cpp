// 띄어쓰기가 처리되지 않는 후위 수식계산 코드
// #pragma once
#include <iostream>
#include <cstdlib>
#define MAX_STACK_SIZE 25

using namespace std;

class OperandStack {
private:
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack()
	{
		top = -1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == MAX_STACK_SIZE - 1;
	}
	void push(double e)
	{
		if (isFull())
		{
			cout << "Stack is Overflow" << '\n';
			return;
		}
		data[++top] = e;
	}
	double pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << '\n';
		}
		return data[top--];
	}
	int size()
	{
		return top + 1;
	}
	double Top()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << '\n';
			return 0;
		}
		return data[top];
	}
};

#include <cstring>

int main()
{
	string str;
	cin >> str;

	int index = 0;
	OperandStack stack_num, stack_op;
	stack_num.push(str[index++] - '0');

	while (index < str.length()) //!stack_num.empty()
	{
		if (str[index] == '+' || str[index] == '-' || str[index] == '*' || str[index] == '/')
		{
			double num1 = stack_num.Top();
			stack_num.pop();

			if (str[index] == '+')
				stack_num.push(stack_num.pop() + num1);
			else if (str[index] == '-')
				stack_num.push(stack_num.pop() - num1);
			else if (str[index] == '*')
				stack_num.push(stack_num.pop() * num1);
			else if (str[index] == '/')
				stack_num.push(stack_num.pop() / num1);
		}

		else
			stack_num.push(str[index] - '0');
		index++;
	}
	cout << stack_num.Top()<<endl;


}