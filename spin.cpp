#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;
using std::ifstream;
using std::ofstream;


struct Wheel
{
    int speed;
    vector<pair<int, int> > wedges;
};


int main(int arg, char *argv[])
{
    vector<Wheel> wheels;
    int positions[360], i;
    bool done = false;
    ifstream fin("spin.in");
    ofstream fout("spin.out");

    for(int i = 0; i < 5; i++)
    {
        Wheel temp;
        int w;

        fin >> temp.speed;
        fin >> w;

        for(int i = 0; i < w; i++)
        {
            int start, extent;

            fin >> start >> extent;
            temp.wedges.push_back(make_pair(start, extent));
        }
        wheels.push_back(temp);
    }

    for(i = 0; i < 360; i++)
    {
        memset(positions, 0, sizeof(positions));

        for(int j = 0; j < 5; j++)
        {
            int pos = (wheels[j].speed * i) % 360;
            int w = wheels[j].wedges.size();

            for(int k = 0; k < w; k++)
            {
                for(int l = wheels[j].wedges[k].first; l <= wheels[j].wedges[k].first + wheels[j].wedges[k].second; l++)
                {
                    positions[(pos + l) % 360]++;
                }
            }
        }

        for(int b = 0; b < 360; b++)
        {
            if(positions[b] == 5)
                done = true;
        }

        if(done)
        {
            fout << i << endl;
            break;
        }
    }

    return 0;
}
