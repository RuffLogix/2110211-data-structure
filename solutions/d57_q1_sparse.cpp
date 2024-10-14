#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <set>

using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        n = 3;
        adj = vector<set<int> >(n, set<int>());
    }

    SparseGraph(int n_in) {
        n = n_in;
        adj = vector<set<int> >(n, set<int>());
    }

    SparseGraph(const SparseGraph& G) {
        n = G.n;
        adj = G.adj;
    }

    void AddEdge(int a, int b) {
        adj[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        if (adj[a].find(b) != adj[a].end()) adj[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        return adj[a].find(b) != adj[a].end();
    }

    SparseGraph Transpose() const {
        SparseGraph res(n);

        for (int i=0; i<n; i++) {
            for (int x: adj[i]) {
                res.AddEdge(x, i);
            }
        }

        return res;
    }

protected:
    int n;
    vector<set<int> > adj;
};
#endif // __SPARSE_GRAPH_H__
