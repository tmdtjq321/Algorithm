#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
    int child[2];
    Node() {
        child[0] = child[1] = -1;
    }
};
class Trie {
public:
    int root;
    vector<Node> v;
    Trie() {
        root = New();
    }
    int New() {
        Node temp;
        v.push_back(temp);
        return v.size() - 1;
    }
    int get(int node, int i, int index) {
        if (index == -1){
        	return 0;
		}
        bool n = ((i & (1 << index)) > 0);	
        bool m = !n;
        if (v[node].child[m] != -1) {
            return get(v[node].child[m], i, index - 1) + (1 << index);
        }
        if (v[node].child[n] != -1) {
            return get(v[node].child[n], i, index - 1);
        }
        return 0;
    }
    void add(int node, int i, int index) {
        if (index == -1)
            return;
        bool n = ((i & (1 << index)) > 0);
        if (v[node].child[n] == -1) {
            int next = New();
            v[node].child[n] = next;
        }
        int child = v[node].child[n];
        add(child, i, index - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res = 0;
    Trie trie;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int val = trie.get(0, t, 31);
        res = max(res, val);
        trie.add(0, t, 31);
    }
    cout << res;
    return 0;
}
