#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<int> st;
multiset<int> ms;

void push(int x) {
	st.push(x);
	ms.insert(x);
}

void pop() {
	ms.erase(st.top());
	st.pop();
}

int top() {
	return st.top();
}

int getMin() {
	return *ms.begin();
}
