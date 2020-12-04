#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/blog/entry/76087
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}


#ifndef ONLINE_JUDGE
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

void print(int arr[], int n){
	cout << "[";
	for(int i=0; i<n; i++)
		cout << arr[i] << ", ";
	cout << "]\n";
}
void print(long long int arr[], long long int n){
	cout << "[";
	for(int i=0; i<n; i++)
		cout << arr[i] << ", ";
	cout << "]\n";
}
void print(long double arr[], long long int n){
	cout << "[";
	for(int i=0; i<n; i++)
		cout << arr[i] << ", ";
	cout << "]\n";
}



void print(double arr[], int n){
	cout << "[";
	for(int i=0; i<n; i++)
		cout << arr[i] << ", ";
	cout << "]\n";
}


void print(vector<int> v){
	cout << "[";
	for(auto x: v)
		cout << x << ", ";
	cout << "]\n";
}
void print(vector<long long int> v){
	cout << "[";
	for(auto x: v)
		cout << x << ", ";
	cout << "]\n";
}


void print(vector<double> v){
	cout << "[";
	for(auto x: v)
		cout << x << ", ";
	cout << "]\n";
}

void print(vector<string> v){
	cout << "[";
	for(auto x: v)
		cout << x << ", ";
	cout << "]\n";
}


void print(vector<char> v){
	cout << "[";
	for(auto x: v)
		cout << x << ", ";
	cout << "]\n";
}

void print(vector<vector<char>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		for(auto y: x)
			cout << y << ", ";
		cout << "], ";
	}
	cout << "]\n";
}

void print(vector<vector<int>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		for(auto y: x)
			cout << y << ", ";
		cout << "], ";
	}
	cout << "]\n";
}

void print(vector<vector<double>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		for(auto y: x)
			cout << y << ", ";
		cout << "], ";
	}
	cout << "]\n";
}

void print(vector<vector<string>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		for(auto y: x)
			cout << y << ", ";
		cout << "], ";
	}
	cout << "]\n";
}

void print(vector<pair<long long int, long long int>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		cout << x.first << ", " << x.second << "], ";
	}
	cout << "]\n";
}

void print(vector<pair<int, int>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		cout << x.first << ", " << x.second << "], ";
	}
	cout << "]\n";
}


void print(vector<pair<double, double>> v){
	cout << "[";
	for(auto x: v){
		cout << "[";
		cout << x.first << ", " << x.second << "], ";
	}
	cout << "]\n";
}

void print(pair<int, int> p){
	cout << "[";
	cout << p.first << ", " << p.second << "]\n";
}

void print(pair<string, string> p){
	cout << "[";
	cout << p.first << ", " << p.second << "]\n";
}

void print(pair<string, int> p){
	cout << "[";
	cout << p.first << ", " << p.second << "]\n";
}

void print(pair<int, string> p){
	cout << "[";
	cout << p.first << ", " << p.second << "]\n";
}

void print(set<int> v){
	cout << "{";
	for(auto x: v)
		cout << x << ", ";
	cout << "}\n";
}

void print(set<pair<int, int>> sp){
	cout << "{ ";
	for(auto x: sp)
		cout << "[" << x.first << ", " << x.second << "]" << ", ";
	cout << "}\n";
}

void print(set<string> v){
	cout << "{";
	for(auto x: v)
		cout << x << ", ";
	cout << "}\n";
}

void print(multiset<int> v){
	cout << "{";
	for(auto x: v)
		cout << x << ", ";
	cout << "}\n";
}

void print(multiset<string> v){
	cout << "{";
	for(auto x: v)
		cout << x << ", ";
	cout << "}\n";
}

void print(map<int, int> mp){
	cout << "{";
	for(auto x: mp){
		cout << x.first << ":" << x.second << ", ";
	}
	cout << "}\n";
}
