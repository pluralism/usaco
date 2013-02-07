#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#define MAX 10000


int main(int argc, char *argv[])
{
    int V, N, current;
    int numberways[MAX];

    cin >> V >> N;

    numberways[0] = 1;
    for(int i = 0; i < V; i++)
    {
        cin >> current;

        for(int j = current; j <= N; j++)
        {
            numberways[j] += numberways[j - current];
        }
    }

    cout << numberways[N];

    return 0;
}
