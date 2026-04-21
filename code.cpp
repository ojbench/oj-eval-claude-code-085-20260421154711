#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    bool keep; // whether subtree contains a 1
    Node(int v): val(v), left(nullptr), right(nullptr), keep(false) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) {
        if (x == -2) break;
        a.push_back(x);
    }

    // Build tree from (possibly truncated) extended preorder sequence using an explicit stack
    Node* root = nullptr;
    struct Frame { Node* node; int state; }; // state: 0 expect left, 1 expect right
    vector<Frame> st;

    auto attach_null = [&](){
        if (st.empty()) return;
        if (st.back().state == 0) {
            st.back().node->left = nullptr;
            st.back().state = 1;
        } else {
            st.back().node->right = nullptr;
            st.pop_back();
        }
    };

    for (size_t i = 0; i < a.size(); ++i) {
        long long v = a[i];
        if (v == -1) {
            attach_null();
            continue;
        }
        // Create node
        Node* cur = new Node((int)v);
        if (!root) {
            root = cur;
        } else if (!st.empty()) {
            if (st.back().state == 0) {
                st.back().node->left = cur;
                st.back().state = 1;
            } else {
                st.back().node->right = cur;
                st.pop_back();
            }
        } else {
            // stray node without parent; treat as new root only if root null; otherwise ignore
            // But per problem input this should not happen
        }
        st.push_back({cur, 0});
    }
    // Pad missing null children implied at end
    while (!st.empty()) {
        if (st.back().state == 0) {
            st.back().node->left = nullptr;
            st.back().state = 1;
        } else {
            st.back().node->right = nullptr;
            st.pop_back();
        }
    }

    // Postorder traversal to compute keep flags and prune subtrees without 1
    if (root) {
        vector<pair<Node*, bool>> stk;
        stk.reserve(100000);
        stk.push_back({root, false});
        while (!stk.empty()) {
            auto [n, vis] = stk.back();
            stk.pop_back();
            if (!n) continue;
            if (!vis) {
                stk.push_back({n, true});
                stk.push_back({n->right, false});
                stk.push_back({n->left, false});
            } else {
                bool lkeep = n->left ? n->left->keep : false;
                bool rkeep = n->right ? n->right->keep : false;
                n->keep = (n->val == 1) || lkeep || rkeep;
                if (n->left && !lkeep) {
                    // delete left subtree
                    vector<Node*> del;
                    del.push_back(n->left);
                    while (!del.empty()) {
                        Node* t = del.back(); del.pop_back();
                        if (!t) continue;
                        del.push_back(t->left);
                        del.push_back(t->right);
                        delete t;
                    }
                    n->left = nullptr;
                }
                if (n->right && !rkeep) {
                    vector<Node*> del;
                    del.push_back(n->right);
                    while (!del.empty()) {
                        Node* t = del.back(); del.pop_back();
                        if (!t) continue;
                        del.push_back(t->left);
                        del.push_back(t->right);
                        delete t;
                    }
                    n->right = nullptr;
                }
            }
        }
        if (!root->keep) {
            // Entire tree pruned
            // delete root
            vector<Node*> del;
            del.push_back(root);
            while (!del.empty()) {
                Node* t = del.back(); del.pop_back();
                if (!t) continue;
                del.push_back(t->left);
                del.push_back(t->right);
                delete t;
            }
            root = nullptr;
        }
    }

    // Output extended preorder of pruned tree
    vector<int> out;
    out.reserve(a.empty() ? 1 : (int)a.size()*2 + 3);
    if (!root) {
        out.push_back(-1);
    } else {
        vector<Node*> st2;
        st2.push_back(root);
        while (!st2.empty()) {
            Node* n = st2.back();
            st2.pop_back();
            if (!n) {
                out.push_back(-1);
            } else {
                out.push_back(n->val);
                // push right then left to process left first
                st2.push_back(n->right);
                st2.push_back(n->left);
            }
        }
    }

    // Print space-separated
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';

    // Delete remaining tree to avoid leaks
    if (root) {
        vector<Node*> del;
        del.push_back(root);
        while (!del.empty()) {
            Node* t = del.back(); del.pop_back();
            if (!t) continue;
            del.push_back(t->left);
            del.push_back(t->right);
            delete t;
        }
        root = nullptr;
    }

    return 0;
}
