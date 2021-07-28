#include "bits/stdc++.h"
using namespace std;


#define ff first
#define ss second
#define bug cout<<__LINE__<<" bug"<<endl;

template<typename T1, typename T2>ostream& operator<<(ostream& out, pair<T1, T2> a) {out << "{" << a.ff << " ," << a.ss << "}"; return out;}

#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

//VECTORS
template <typename T>
void pr(vector <T> v) {
	cout << "[ ";
	for (T i : v)
	{cout << i; cout << " ";}
	cout << "]";
	cout << endl;
}

//vector<vector<T>>
template <typename T>
void pr(vector<vector<T>> v) {
	for (auto i : v)
		pr(i);
	cout << endl;
}

//SETS
template <typename T>
void pr(set <T> v) {
	cout << "[ ";
	for (T i : v)
	{cout << i; cout << " ";}
	cout << "]";
	cout << endl;
}
//MULTISETS
template <typename T>
void pr(multiset <T> v) {
	cout << "[ ";
	for (T i : v)
	{cout << i; cout << " ";}
	cout << "]";
	cout << endl;
}
//MAPS
template <typename T , typename V>
void pr(map<T , V> v) {
	cout << "[ ";
	for (auto i : v)
	{cout << i; cout << " ";}
	cout << "]";
	cout << endl;
}
// UnORDERED MAPS
template <typename T , typename V>
void pr(unordered_map<T , V> v) {
	cout << "[ ";
	for (auto i : v)
	{cout << i; cout << " ";}
	cout << "]";
	cout << endl;
}

// Stack / QUEUES / DEQUE
template <typename T>
void pr(stack<T> v) {
	vector<T> ans;
	while (!v.empty()) {
		ans.push_back(v.top());
		v.pop();
	}
	reverse(ans.begin(), ans.end());
	pr(ans);
}

template <typename T>
void pr(queue<T> v) {
	vector<T> ans;
	while (!v.empty()) {
		ans.push_back(v.back());
		v.pop_back();
	}
	reverse(ans.begin(), ans.end());
	pr(ans);
}

template <typename T>
void pr(deque<T> v) {
	vector<T> ans;
	while (!v.empty()) {
		ans.push_back(v.back());
		v.pop_back();
	}
	reverse(ans.begin(), ans.end());
	pr(ans);
}


