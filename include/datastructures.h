#pragma once
#include <bits/stdc++.h>

using namespace std;

struct Segment_Tree {
    struct node {
        int ans = 0, lazy = 0, l, r;
 
        void leaf(int val) {
            ans = val;
        }
        void pull(const node &a, const node &b) {
            ans = a.ans+b.ans;
        }
        void push(int val) {
            lazy += val;
        }
    };
 
    int n;
    vector<int> a;
    vector<node> st;
 
    Segment_Tree(int _n) : n(_n), a(n, 0), st(4 * n) {
        build(1, 0, n-1);
    }
 
    Segment_Tree(const vector<int> &_a) : n((int)_a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }
 
    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }
 
    void push(int p) {
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].ans += (st[p].r-st[p].l+1) * st[p].lazy;
            st[p].lazy = 0;
        }
    }
 
    node query(int p, int i, int j) {
        push(p);
        if (i > st[p].r || j < st[p].l) return node();
        if (i <= st[p].l && st[p].r <= j) return st[p];
        node ret, ls = query(2*p, i, j), rs = query(2*p+1, i, j);
        ret.pull(ls, rs);
        return ret;
    }
 
    int query(int i, int j) {
        return query(1, i, j).ans;
    }
 
    void update(int p, int i, int j, int val) {
        push(p);
        if (i > st[p].r || j < st[p].l) return;
        if (i <= st[p].l && st[p].r <= j) {
            st[p].push(val);
            push(p);
            return;
        }
        update(2*p, i, j, val);
        update(2*p+1, i, j, val);
        st[p].pull(st[2*p], st[2*p+1]);
    }
 
    void update(int i, int j, int val) {
        update(1, i, j, val);
    }
 
    void set(int p, int i, int x) {
        if (st[p].l == st[p].r) {
            st[p].leaf(x);
            return;
        }
        int m = (st[p].l+st[p].r)/2;
        if (i <= m) set(2*p, i, x);
        else set(2*p+1, i, x);
        st[p].pull(st[2*p], st[2*p+1]);
    }
 
    void set(int i, int x) {
        set(1, i, x);
    }
};
    
struct DSU {
    int n;
    vi parent, gsize;
    
    void init(int n) {
        this->n = n;
        parent = vi(n+1);
        gsize = vi(n+1, 1);
        repe(i, 0, n) parent[i] = i;
    }
    
    int find(int u) {
        if(u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    int unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(gsize[u] < gsize[v]) swap(u, v);
            parent[v] = u;
            gsize[u] += gsize[v];
            return u;
        }
        return -1;
    }
};
 
