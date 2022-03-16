#include <bits/stdc++.h>

using namespace std;


int n;
double a[1000005];

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




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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
        quicksort(1,n);
        auto t2 = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << "Test " << i <<": ";
        cout << fixed << setprecision(6) << time.count() << '\n';
    }
    return 0;
}
