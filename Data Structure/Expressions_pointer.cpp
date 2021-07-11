#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Implement ExpressionTree

struct node{
	char c;
	node* left;
	node* right;
	node(char x){
		c = x;
		left = NULL;
		right = NULL;
	};
};

class ExpressionTree{
	private:
		node* root;

		node* _makeEmpty(node* t){
			if (t == NULL) return NULL;
			_makeEmpty(t->left);
			_makeEmpty(t->right);
			delete t;
			return NULL;
		}

		bool _isOpt(char c){
			return (c >= 'A' && c <= 'Z');
		} 

		node* _buildTree(const string& postfix){
			stack<node*> st;
			node *opt, *u1, *u2;

			for (int i = 0; i < postfix.size(); i++)
				if (!_isOpt(postfix[i])){
					opt = new node(postfix[i]);
					st.push(opt); 
				}
				else{
					opt = new node(postfix[i]);

					u1 = st.top();
					st.pop();

					u2 = st.top();
					st.pop();

					opt->left = u1;
					opt->right = u2;

					st.push(opt);
				}

			opt = st.top();
			st.pop();

			return opt;
		}

		string _bfs(node* t){
			if (t == NULL) return "";
			string ans = "";
			queue<node*> q;
			q.push(t);

			node* u;
			while (!q.empty()){
				u = q.front();
				ans.push_back(u->c);
				q.pop();
				if (u->right != NULL) q.push(u->right);
				if (u->left != NULL) q.push(u->left);
			}
			return ans;
		}


	public:
		ExpressionTree(){
			root = NULL;
		}

		~ExpressionTree(){
			root = _makeEmpty(root);
		}

		void makeEmpty(){
			root = _makeEmpty(root);
		} 

		void buildTree(const string& postfix){
			root = _buildTree(postfix);
		}

		string get_ans(){
			string t = _bfs(root);
			reverse(t.begin(),t.end());
			return t;
		}
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