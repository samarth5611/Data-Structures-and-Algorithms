#include "bits/stdc++.h"
using namespace std;


struct trie
{
	int is_end ;
	map< char , trie*> mp;

	trie() {
		is_end = 1;
	}
};

trie *root;

void insert(string s)
{
	trie*cur = root;
	for (char x : s)
	{
		if (cur->mp.count(x) == 0)
			cur->mp[x] = new trie;
		cur = cur->mp[x];
	}
	cur->is_end = 1;
}

int search(string s)
{
	trie *cur = root;
	for ( char x : s)
	{
		if (cur->mp.count(x) == 0)
			return 0;
		cur = cur->mp[x];
	}
	return cur->is_end;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	root = new trie;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		insert(s);
		// cout << s << endl;
	}

	string sx;
	cin >> sx;
	if (search(sx))
	{
		cout << "YEs" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0 ;
}
