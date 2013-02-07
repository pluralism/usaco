/*
ID: andrepd1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::sort;


struct Time
{
    int begin;
    int end;
};

bool compareTimes(const Time &a, const Time &b)
{
    if(a.begin == b.begin)
        return a.end > b.end;

    return a.begin < b.begin;
}

int main(int argc, char *argv[])
{
    int N, l_interval = 0, min_interval = 0;
    vector<int> sortTimes;
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    //The number of cows to milk
    fin >> N;

    //Create a struct with N elements
    Time *times = new Time[N];

    //Enter the begin/end time for each cow
    for(int i = 0; i < N; i++)
    {
        fin >> times[i].begin >> times[i].end;
    }

    //Sort the times by the start time
    sort(times, times + N, compareTimes);

    l_interval = times[0].end - times[0].begin;

    for(int i = 1; i < N; i++)
    {
        //If the time can be placed between the previous then we must analize it
        if(times[i].begin < times[i - 1].end && times[i].begin > times[i - 1].begin)
        {
            for(int j = i - 1; j <= i; j++)
            {
                sortTimes.push_back(times[j].begin);
                sortTimes.push_back(times[j].end);
            }
            //And sort them
            sort(sortTimes.begin(), sortTimes.begin() + sortTimes.size());

            if(l_interval < sortTimes.back() - sortTimes.front())
                l_interval = sortTimes.back() - sortTimes.front();
        }

        if(times[i].begin > times[i - 1].end)
        {
            if(min_interval < times[i].begin - times[i - 1].end)
                min_interval = times[i].begin - times[i - 1].end;

            times[i - 1] = times[i];
        }else if(times[i - 1].end < times[i].end)
            times[i - 1].end = times[i].end;

        if(sortTimes.size() > 0)
            sortTimes.clear();
    }

    delete[] times;

    fout << l_interval << " " << min_interval << endl;

    return 0;
}
