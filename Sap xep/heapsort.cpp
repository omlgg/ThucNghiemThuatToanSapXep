#include <bits/stdc++.h>

using namespace std;


struct heap
{
    int n=0;
    double h[1000005];

    void init()
    {
        n = 0;
    }

    double top()
    {
        return h[1];
    }

    void upheap(int x)
    {
        if (x == 1) return;
        int p = x/2;
        if (h[p] > h[x])
        {
            swap(h[p],h[x]);
            upheap(p);
        }
    }

    void downheap(int x)
    {
        int l,r;
        l = x*2;
        r = x*2+1;

        int tmp = x;
        if (l <= n && h[l] < h[tmp])
            tmp = l;
        if (r <= n && h[r] < h[tmp])
            tmp = r;
        if (tmp != x)
        {
            swap(h[x],h[tmp]);
            downheap(tmp);
        }
    }

    void pop()
    {
        swap(h[n],h[1]);
        n--;
        downheap(1);
    }

    void ins(double x)//insert x
    {
        h[++n] = x;
        upheap(n);
    }

}h;
int n;
double a[1000005];

void heapsort()
{
    h.init();
    for (int i = 1; i <= n; i++)
        h.ins(a[i]);
    for (int i = 1; i <= n; i++)
        a[i] = h.top(),h.pop();
}

int main()
{
    ifstream fi;
    for (int i = 0; i <= 9; i++)
    {
        fi >> n;
        string s = "test" + to_string(i) + ".txt";
        fi.open(s);
        fi >> n;
        for (int i = 1; i <= n; i++)
            fi >> a[i];
        fi.close();

        auto t1 = chrono::high_resolution_clock::now();
        heapsort();
        auto t2 = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << "Test " << i <<": ";
        cout << fixed << setprecision(6) << time.count() << '\n';
    }
    return 0;
}
