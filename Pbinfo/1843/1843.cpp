void P(int x[], int n, int& s)
{
    if (n == 0)
        s = 0;
    else
    {
        P(x, n - 1, s);

        if (x[n - 1] < 2 || (x[n - 1] != 2 && x[n - 1] % 2 == 0))
        return;
    
        for (int d = 3; d * d <= x[n - 1]; d += 2)
            if (x[n - 1] % d == 0)
                return;

        s += x[n - 1];  
    }  
}
