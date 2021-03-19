
#include <iostream>
using namespace std;

#define N 3

int main ( )
{
    int A [N][N]= {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int B [N][N]= {6, 1, 8, 7, 2, 5, 9, 3, 4};
    int CARP [N][N], Toplam;

    cout<<"A Matrisi: "<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<" "<<A [i][j];
        cout<<"\n";
    }

    cout<<"B Matrisi: "<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<" "<<B [i][j];
        cout<<"\n";
    }

    cout<<"CARP Matrisi: "<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            Toplam=0;
            for(int k=0; k<N; k++)
            {
                Toplam+= A [i][k]*B [k][j];
            }

            CARP[i][j]= Toplam;
            cout<<" "<<CARP [i][j];
        }
        cout<<"\n";
    }

    return 0;
}

