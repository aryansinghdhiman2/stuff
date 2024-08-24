#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    const int size = 1000;
    const double range_multiplier = 30.0;
    vector<double> A(size);
    vector<double> median_array, avg_array, weighted_avg_array;
    vector<double> moving_array_avg, moving_array_weighted_avg, moving_array_median;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < size; ++i)
    {
        A[i] = dis(gen) * range_multiplier;
    }

    for (int i = 0; i < size; i += 4)
    {

        for (int j = i; j < min(size, i + 9); ++j)
        {

            vector<double> window(A.begin() + i, A.begin() + min(size, i + 9));
            sort(window.begin(), window.end());

            double median = window.size() % 2 == 0 ? (window[window.size() / 2 - 1] + window[window.size() / 2]) / 2.0 : window[window.size() / 2];

            double sum = 0.0;
            for (double value : window)
            {
                sum += value;
            }
            double avg = sum / window.size();

            double weighted_sum = 0.0;
            for (int k = 0; k < int(window.size()); ++k)
            {
                weighted_sum += (k + 1) * window[k];
            }
            double weighted_avg = weighted_sum / (window.size() * (window.size() + 1) / 2.0);

            
            median_array.push_back(median);
            avg_array.push_back(avg);
            weighted_avg_array.push_back(weighted_avg);
        }
    }

    double B;
    
    cout << "Enter a value for B (between 0.2 and 0.9): ";
    cin >> B;

    for (int i = 2; i < size; ++i)
    {
        moving_array_avg.push_back(B * avg_array[i - 1] + A[i] * (1 - B));
        moving_array_weighted_avg.push_back(B * weighted_avg_array[i - 1] + A[i] * (1 - B));
        moving_array_median.push_back(B * median_array[i - 1] + A[i] * (1 - B));
    }

    
    cout << "\nMoving Average of Average Array:"<<endl<<"[ ";
    for (double value : moving_array_avg)
    {
        cout << value << " , ";
    }

    cout << " ]";
    cout << "\n\n";

    cout << "Moving Average Weighted Average array: "<<endl<<"[ ";
    for (double value : moving_array_weighted_avg)
    {
        cout << value << " , ";
    }
    cout << " ]";
    cout << "\n\n";

    cout << "Moving Average Median Array:"<<endl<<"[ ";
    for (double value : moving_array_median)
    {
        cout << value << " , ";
    }
    cout << " ]";
    cout << "\n\n";

    return 0;
}
