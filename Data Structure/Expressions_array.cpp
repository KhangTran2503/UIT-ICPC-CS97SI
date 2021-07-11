#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//Expression Tree using array
struct node{
	char c;
	int left;
	int right;
	node(char x='*',int l=-1,int r=-1): c(x),left(l),right(r){};
};

class ExpressionTree{

private:
	vector<node> et;
	int curidx;
	bool _isOpt(char c){
		return (c >= 'A' && c <= 'Z');
	}
	int root;

public:
	ExpressionTree(){
		curidx = -1;
		root = -1;
	};
	~ExpressionTree(){};

	void buildTree(const string& postfix){
		stack<int> st;

		for (int i = 0; i < postfix.size(); i++){
			if (!_isOpt(postfix[i])){
				et.push_back(node(postfix[i]));
				st.push(++curidx);
			}
			else{
				int u1, u2;
				u1 = st.top();
				st.pop();

				u2 = st.top();
				st.pop();

				et.push_back(node(postfix[i],u1,u2));
				st.push(++curidx);
			}
		}
		root = st.top();
	}

	string get_ans(){
		if (curidx == -1) return "";
		string ans = "";

		queue<int> q;
		q.push(root);
		while (!q.empty()){
			int u = q.front();
			q.pop();

			ans.push_back(et[u].c);
			if (et[u].right != -1) q.push(et[u].right);
			if (et[u].left != -1) q.push(et[u].left);
		}

		reverse(ans.begin(),ans.end());
		return ans;
	}

	void makeEmpty(){
		et.clear();
		curidx = -1;
		root = -1;
	};

};




int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	
	ExpressionTree ET;
	string s;
	while (T--){
		cin >> s;
		ET.buildTree(s);
		cout << ET.get_ans() << '\n';

		ET.makeEmpty();
	}
	return 0;
}