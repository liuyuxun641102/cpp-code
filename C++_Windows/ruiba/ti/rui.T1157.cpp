#include <bits/stdc++.h>
using namespace std;

vector<bool> f(int n)
{
    vector<bool> isprime(n + 1, 0);
    vector<int> primes;
    isprime[0] = isprime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
            primes.push_back(i);
        for (int p : primes)
        {
            if (p * i > n)
                break;
            isprime[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
    return isprime;
}
int main()
{
    vector<bool> isprime = f(100);
    for (int i = 6; i <= 100; i += 2)
    {
        for (int j = 3; j <= i; j++)
        {
            if (!isprime[j] && !isprime[i - j])
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}