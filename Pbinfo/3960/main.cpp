#include <fstream>
using namespace std;

ifstream cin("intersectie.in");
ofstream cout("intersectie.out");

void citire(int &n, int a[])
{
    n = 0;
    do{
        cin >> a[++n];
    }while(a[n] !=0 );
    n--;
}

void interclasare1(int n, int a[], int &k, int b[])
{
    int x, i;
    i = 1;
    k = 0;
    do{
        cin >> x;
        if(x)
        {
            while(a[i] < x && i <= n)
            i++;
        if(i <= n && a[i] == x)
            if(k == 0 || k >= 1 && b[k] != x)
                b[++k] = x;
        }
    }while(x);
}

void interclasare2(int k, int b[], int &n, int a[])
{
    int x, i;
    i = 1;
    n = 0;
    do{
        cin >> x;
        while(i <= k && b[i] < x)
            i++;
        if(i <= k && b[i] == x)
            if(n == 0 || n >= 1 && a[n] != x)
                a[++n] = x;
    }while(x);
}

int main()
{
    int n, a[100001], b[100001], k, nr = 0;
    citire(n, a);
    do{
        nr++;
        if(nr % 2 == 1)
            interclasare1(n, a, k, b);
        else
            interclasare2(k, b, n, a);

    }while(!cin.eof());
    if(nr % 2 == 1)
        if(k)
            for(int i = 1; i <= k; i++)
                cout << b[i] << " ";
        else
            cout << "nu exista";
    else
        if(n)
            for(int i = 1; i <= n; i++)
                cout << a[i] << " ";
        else
            cout << "nu exista";
    return 0;
}
