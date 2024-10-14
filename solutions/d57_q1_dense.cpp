#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        n = 3;
        adj = vector<vector<bool> >(n, vector<bool>(n, false));
    }

    DenseGraph(int n_in) {
        n = n_in;
        adj = vector<vector<bool> >(n, vector<bool>(n, false));
    }

    DenseGraph(const DenseGraph& G) {
        n = G.n;
        adj = G.adj;
    }

    void AddEdge(int a, int b) {
        adj[a][b] = true;
    }

    void RemoveEdge(int a, int b) {
        adj[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        return adj[a][b];
    }

    DenseGraph Transpose() const {
        DenseGraph res(adj.size());

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                res.adj[i][j] = adj[j][i];
            }
        }

        return res;
    }

protected:
    int n;
    vector<vector<bool> > adj;
};
#endif // __DENSE_GRAPH_H__
