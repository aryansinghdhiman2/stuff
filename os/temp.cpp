#include <iostream>
using namespace std;
#define MEMORY 5000
int BLOCK_S;
int mft(int ps[], int num_b, int n)
{
    int ifg = 0;
    for (int i = 0; i < n && num_b >= 0; i++)
    {
        if (ps[i] <= BLOCK_S)
        {
            cout << "process" << i << " of size " << ps[i] << " is allocated a block " << endl;
            ifg += BLOCK_S - ps[i];
            num_b--;
        }
    }
    return ifg;
}
int main()
{
    cout << "Enter the block size" << endl;
    cin >> BLOCK_S;
    int num_b = (MEMORY / BLOCK_S);
    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    int ps[n];
    cout << "Enter the sizes of processes" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
    }
    int r = mft(ps, num_b, n);
    cout << "Internal fragmentation = " << r << endl;
    cout << "External fragmentation " << MEMORY - (num_b * BLOCK_S) << endl;
    return 0;
}