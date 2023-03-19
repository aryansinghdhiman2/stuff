#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<double> fractionalKnapsack(int size, vector<int> &profits, vector<int> &weights, int capacity)
{
    vector<double> fractionVec(size);

    vector<pair<double, int> > ratio(size);
    for (int i = 0; i < size; i++)
    {
        ratio[i].first = (double)profits[i] / weights[i];
        ratio[i].second = i;
    }

    sort(ratio.rbegin(), ratio.rend());

    int currentCapacity = capacity;
    for (int i = 0; i < size; i++)
    {
        int weight = weights[ratio[i].second];
        if (weight <= currentCapacity)
        {
            fractionVec[ratio[i].second] = 1.0;
            currentCapacity -= weight;
        }
        else
        {
            fractionVec[ratio[i].second] = (double)currentCapacity / weight;
            currentCapacity = 0;
        }

        if (currentCapacity == 0)
            break;
    }

    return fractionVec;
}

int main()
{
    int size, capacity;
    cout << "Enter size : ";
    cin >> size;

    vector<int> profits(size);
    vector<int> weights(size);

    cout << "Enter " << size << " elements in the profits array : ";
    for (int i = 0; i < size; i++)
        cin >> profits[i];
    cout << "Enter " << size << " elements in the weights array : ";
    for (int i = 0; i < size; i++)
        cin >> weights[i];

    cout << "Enter capacity : ";
    cin >> capacity;

    vector<double> fractionVec = fractionalKnapsack(size, profits, weights, capacity);

    double maxProfit = 0;
    for (int i = 0; i < size; i++)
        maxProfit += fractionVec[i] * profits[i];

    cout << "Fractional Vector : ";
    for (int i = 0; i < size; i++)
        cout << fractionVec[i] << " ";
    cout << endl;
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}