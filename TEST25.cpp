// TEST25
#include <iostream>
using namespace std;
typedef char * U;
U P1[27], P2[9], P3[59];
int M, K, L;
int main()
{
    for (K=0; K<27; K=K+1)
    {
        P1[K] = new char;
        cin >> *P1[K];
    }

    for (K=0; K<9; K=K+1)
    {
        P2[K] = new char;
        cin >> *P2[K];
    }
    M=0;
    for (K=0; K<27; K=K+1)
    {
        if (*P1[K] != 'P')
        {
            P3[M]=P1[K];
            M=M+1;
        }
        else
        {
            for (L=0; L<9; L=L+1)
            {
                P3[M]=P2[L];
                M=M+1;
            }
        }
    }
    for (L=0; L<59; L=L+1)
    {
        cout << *P3[L];
    }
    cout << endl;

    for (K=0; K<27; K=K+1)
    {
        delete P1[K];
    }

    for (K=0; K<9; K=K+1)
    {
        delete P2[K];
    }

    return 0;
}
