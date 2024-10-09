    #include <iostream>
    #include <cstring>
    using namespace std;

    int main()
    {
        char s[260], cuv[260][260], *p;
        int sum[100] = {}, k = 0;

        cin.get(s, 260);
        for (p = strtok(s, " "); p; p = strtok(NULL, " "))
        {
            int ok = 0;
            for (int i = 0; i < strlen(p) && !ok; ++i)
                if (isalpha(p[i]))
                    ok = 1;
            if (ok)
            {
                strcpy(cuv[++k], p);
                for (int i = 0; i < strlen(p); ++i)
                    sum[k] += p[i];
            }
        }

        if(!k)
            cout << "NU EXISTA";
        else
        {
            for (int i = 1; i < k; ++i)
                for (int j = i + 1; j <= k; ++j)
                    if (sum[i] > sum[j])
                    {
                        swap(sum[i], sum[j]);
                        swap(cuv[i], cuv[j]);
                    }

            for (int i = 1; i <= k; ++i)
                if (sum[i])
                {

                    cout << sum[i] << ' ' << cuv[i] << ' ';
                    for (int j = 1; j <= k; ++j)
                        if (sum[i] == sum[j] && i != j)
                        {
                            cout << cuv[j] << ' ';
                            sum[j] = 0;
                        }
                    cout << '\n';
                }
        }

        return 0;
    }
