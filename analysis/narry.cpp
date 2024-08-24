#include <bits/stdc++.h> 
#include <chrono> 
using namespace std;
 using namespace std::chrono; 
 pair <int,int> 
 linear_search(int arr[], int low, int high,int key,int ans)
 {     
    pair <int,int> p;      
    auto start = steady_clock::now();     
    for(int i=low;i<high;i++){         
        if(key==arr[i]){          
               ans=1;
}
}
ans = 0;
auto stop = steady_clock::now();
auto duration = (duration_cast<microseconds>(stop - start).count());
p.first = ans;
p.second = duration;
return p;
}
int nary_search(int arr[], int low, int high, int n, int key)
{
    vector<int> cut;
    int ncuts = n - 1;
    int m = 1;
    int ans = 0;
    pair<int, int> a;
    if (high - low - 1 < n)
    {
        a = linear_search(arr, low, high, key, ans);
        ans = a.first;
        return a.second;
    }
    if (ans != 1)
    {
        cut.push_back(low);
        while (m != n)
        {
            int t = ((m * (high-low)) / n) + low;
            cut.push_back(t);
            m++;
        }
        cut.push_back(high - 1);
    }
    auto start = steady_clock::now();
    for (int i = 0; i < ncuts + 1; i++)
    {
        if (key == arr[cut[i]])
        {
            ans = 1;
        }
    }
    if (ans != 1)
    {
        for (int i = 1; i <= ncuts + 1; i++)
        {
            if (key < arr[cut[i]])
            {
                ans = nary_search(arr, cut[i - 1], cut[i], n, key);
            }
            if (ans == 1)
            {
                break;
            }
        }
    }
    auto stop = steady_clock::now();
    auto duration = (duration_cast<microseconds>(stop - start).count());
    return duration;
}
int main()
{
    int N = 10000;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10000;
    }
    sort(arr, arr + N);
    int key = rand() % 10000;
    int searches;
    cin >> searches;
    vector<int> v;
    for (int i = 0; i < searches; i++)
    {
        int n;
        cin >> n;
        int dur = nary_search(arr, 0, N, n, key);
        v.push_back(dur);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}