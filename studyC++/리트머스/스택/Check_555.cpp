#include <iostream>
#include <stack>
using namespace std;
 
int precedence(char ch) { // 연산자 우선순위 구하기 (괄호가 없을 때 연산자 우선순위 구분 위해)
	if (ch == '(') // ( 라면
	{
		return 0;
	}
	if (ch == '+' || ch == '-' ) // 연산자 ( +, - )라면
	{
		return 1;
	}
	else // 연산자 ( *, / )라면
	{
		return 2;
	}
}
 
 
int main() {
	string infix; // 중위표기법
	getline(cin, infix);
	string posfix; // 후위표기법(결과)
 
	stack <char> s; // 괄호 및 연산자 담기
 
	for (char ch : infix) {
		if ('0' <= ch && ch <= '9') // 알파벳을 만났을 때
		{
			posfix += ch; // 결과값에 넣기
		}
		else if (ch == '(') // (를 만났을 때
		{
			s.push(ch);
		}
		else if (ch == ')') // )를 만났을 때
		{
			while (!s.empty())
			{
				if (s.top() == '(')
				{
					s.pop();
					break;
				}
				posfix += s.top();
				s.pop();
			}
		}
		else // 기호를 만났을 때
		{
			while (!s.empty() && precedence(s.top()) >= precedence(ch))
				// 스택이 비어있지 않고, 스택의 맨 윗 부분이 현재 연산자보다 우선순위가 높다면
				// ex. 스택의 맨 윗 부분(*) >= 현재 연산자 (+)
				// ex 1. a*b+c의 경우에는 ab*c+로 출력되도록 해야하기 때문에 이를 실행 O
				// ex 2. a+b*c의 경우에는 abc*+으로 출력되도록 해야하기 때문에 이를 실행 X 
                // 후위표기식은 a+b-c와 같은 경우에도, 같은 우선순위라도 ab+c-로 표시. (꺼내야함)
			{
				posfix += s.top(); // 우선순위 연산자를 출력
				s.pop();
			}
			s.push(ch); // 현재 연산자 push
		}
	}
 
	while (!s.empty()) // 반복문을 다 돌고도 스택이 비어있지 않은 경우, 남은 연산자들을 문자열에 추가해준다.
	{
		posfix += s.top();
		s.pop();
	}
 
	cout << posfix;
	return 0;
}