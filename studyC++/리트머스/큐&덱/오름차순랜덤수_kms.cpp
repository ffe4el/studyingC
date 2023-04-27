//큐랑 스택 클래스를 내가 직접 만든거
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 30
using namespace std;


template <class T>
class queue {
private:
    int frt;
    int back;
    T data[MAX_SIZE];
public:
   queue() : frt(0), back(0) {
        for (int i = 0; i < MAX_SIZE; i++) {
            data[i] = 0;
        }
   }
    
    void enqueue(T val) {
        data[back++] = val;
    }

    void dequeue() {
        frt++;
    }

    T front() {
        return data[frt];
    }
    
    bool empty() {
        if (frt == back)
            return true;
        else
            return false;
    }
};

template <class T>
class stack {
private:
    int t;
    T data[MAX_SIZE];
public:
    stack() : t(0){
        for (int i = 0; i < MAX_SIZE; i++) {
            data[i] = 0;
        }
    }
    void push(T val) {
        data[t++] = val;
    }
    void pop() {
        t--;
    }
    T top() {
        return data[t - 1];
    }
    bool empty() {
        if (t == 0)
            return true;
        else
            return false;
    }

};


int main() {
    int N;      //숫자 개수
    char ad;    //오름차순인지 내림차순인지

    cin >> N >> ad;

    queue<int> input;
    stack<int> temp;
    queue<int> output;

    int getNum;         //입력받을 정수

    for (int i = 0; i < N; i++) {        //입력큐에 전부 저장
        cin >> getNum;
        input.enqueue(getNum);
    }

    bool flag = false;

    if (ad == 'a') {
        while (!input.empty()) {
            if (temp.empty()) {         //스택이 비어있으면 스택에 넣기
                temp.push(input.front());
                input.dequeue();
            }
            else if (temp.top() < input.front()) {           //스택에 있는 값보다 큰 값이 들어오면
                while (!temp.empty() && temp.top() < input.front()) {    //들어오는 값보다 작은 스택 요소들
                    output.enqueue(temp.top());            //출력큐에 넣기
                    temp.pop();
                }
                temp.push(input.front());           //스택에 넣기
                input.dequeue();
            }
            else if (temp.top() > input.front()) {           //스택에 있는 값보다 작은 값이 들어오면
                temp.push(input.front());                   //스택에 넣기
                input.dequeue();
            }
        }
        while (!temp.empty()) {
            output.enqueue(temp.top());            //출력큐에 넣기
            temp.pop();
        }

        int prev = output.front();
        output.dequeue();
        while (!output.empty()) {
            if (prev > output.front()) {
                flag = true;
                break;
            }
            prev = output.front();
            output.dequeue();
        }

    }
    else if (ad == 'd') {
        while (!input.empty()) {
            if (temp.empty()) {         //스택이 비어있으면 스택에 넣기
                temp.push(input.front());
                input.dequeue();
            }
            else if (temp.top() > input.front()) {           //스택에 있는 값보다 작은 값이 들어오면
                while (!temp.empty() && temp.top() > input.front()) {    //들어오는 값보다 큰 스택 요소들
                    output.enqueue(temp.top());            //출력큐에 넣기
                    temp.pop();
                }
                temp.push(input.front());           //스택에 넣기
                input.dequeue();
            }
            else if (temp.top() < input.front()) {           //스택에 있는 값보다 큰 값이 들어오면
                temp.push(input.front());                   //스택에 넣기
                input.dequeue();
            }
        }
        while (!temp.empty()) {
            output.enqueue(temp.top());            //출력큐에 넣기
            temp.pop();
        }

        int prev = output.front();
        output.dequeue();
        while (!output.empty()) {
            if (prev < output.front()) {
                flag = true;
                break;
            }
            prev = output.front();
            output.dequeue();
        }

    }
    if (flag)   cout << "No";
    else        cout << "Yes";

}