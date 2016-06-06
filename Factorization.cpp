// Factorization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

vector<int> allFactors(int A) 
{
    // track head and tail factors
    // head items are treated as a stack
    // tail items are treated as a queue
    vector<int> factorsA;
    vector<int> factorsB;
    int N = sqrt(A);

    for (int i = 1; i <= N; i++)
    {
        if (A % i == 0)
        {
            factorsA.push_back(i);
            // condition that prevents from adding the same number twice
            if (i != (A / i))
            {
                factorsB.insert(factorsB.begin(), A / i);
            }
        }
    }

    // join head and tail and return the sorted list of factors
    vector<int> factors(factorsA);
    factors.insert(factors.end(), factorsB.begin(), factorsB.end());
    return factors;
}

int main()
{
    for (auto e : allFactors(36))
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

