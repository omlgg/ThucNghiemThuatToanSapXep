#include <bits/stdc++.h>

using namespace std;


double a[1000005],inp[1000005],tmp[1000005];
int n;

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


void mergesort(int l,int r)
{
    if (l == r) return;
    int mid = (l+r) >> 1;
    mergesort(l,mid);
    mergesort(mid+1,r);

    int cur = 0;
    int i = l, j = mid+1;
    while (i <= mid || j <= r)
    {
        if (i > mid)
            tmp[cur++] = a[j++];
        else if (j > r)
            tmp[cur++] = a[i++];
        else if (a[i] < a[j])
            tmp[cur++] = a[i++];
        else
            tmp[cur++] = a[j++];
    }
    for (int i = 0; i < cur; i++)
        a[l+i] = tmp[i];
}

void quicksort(int l,int r)
{
    double x;
    int i,j;
    i = l;
    j = r;
    x = a[(l+r)/2];
    while (i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quicksort(l,j);
    if (i < r) quicksort(i,r);
}


void heapsort()
{
    h.init();
    for (int i = 1; i <= n; i++)
        h.ins(a[i]);
    for (int i = 1; i <= n; i++)
        a[i] = h.top(),h.pop();
}




void copyinp()
{
    for (int i = 1; i <= n; i++)
        a[i] = inp[i];
}


int main()
{
    chrono::time_point<chrono::system_clock> t1,t2;
    chrono::duration<double> time;
    ifstream fi;
    cout << left << setw(10) << "Test";
    cout << left << setw(20) << "csort" << left << setw(20) << "quicksort" << left << setw(20) << "mergesort" << "heapsort\n";
    for (int i = 0; i <= 9; i++)
    {
        cout << left << setw(10) << i;
        string s = "test" + to_string(i) + ".txt";
        fi.open(s);
        fi >> n;
        for (int i = 1; i <= n; i++)
            fi >> inp[i];
        fi.close();

        copyinp();
        t1 = chrono::high_resolution_clock::now();
        sort(a+1,a+n+1);
        t2 = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << left << setw(20) << fixed << setprecision(6) << time.count();


        copyinp();
        t1 = chrono::high_resolution_clock::now();
        quicksort(1,n);
        t2 = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << left << setw(20) << fixed << setprecision(6) << time.count();


        copyinp();
        t1 = chrono::high_resolution_clock::now();
        mergesort(1,n);
        t2 = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << left << setw(20) << fixed << setprecision(6) << time.count();


        copyinp();
        t1 = chrono::high_resolution_clock::now();
        heapsort();
        t2 = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << fixed << setprecision(6) << time.count();

        cout << '\n';
    }
    return 0;
}
