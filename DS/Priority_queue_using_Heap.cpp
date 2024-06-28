#include <bits/stdc++.h>
using namespace std;
class Max_Heap
{
public:
    vector<int> nodes;
    // O(logn)
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    // O(logn)
    void down_heapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
            {
                largest = l;
            }
            if (r < nodes.size() && nodes[largest] < nodes[r])
            {
                largest = r;
            }
            if (largest == idx)
                break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }
    // O(logn)
    void Insert(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }
    // O(logn)
    void Delete(int idx)
    {
        if (idx >= nodes.size())
        {
            return;
        }
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    // O(1)
    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty." << "\n";
            return -1;
        }
        return nodes[0];
    }
    // O(logn)
    int Extract_Max()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty." << "\n";
            return -1;
        }
        int ret = nodes[0];
        Delete(0);
        return ret;
    }
    // O(n)
    void build_From_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n / 2 - 1;
        for (int i = last_non_leaf; i >= 0; i--)
        {
            down_heapify(i);
        }
    }
    // O(1)
    void Print_Heap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }
    int size()
    {
        return nodes.size();
    }
};
class Priotity_Queue
{
public:
    Max_Heap h;
    Priotity_Queue()
    {
    }
    void push(int x)
    {
        h.Insert(x);
    }
    void pop()
    {
        h.Delete(0);
    }
    int top()
    {
        return h.getMax();
    }
    int Size()
    {
        return h.size();
    }
};
int main()
{
    Priotity_Queue pq;
    pq.push(5);
    pq.push(7);
    pq.push(10);
    pq.push(1);
    pq.push(2);
    while (pq.Size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}