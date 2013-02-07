#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::ifstream;
using std::ofstream;


#define NUM 10

char grid[NUM + 10][NUM + 10];
int dirs[4][2] = {
                {-1, 0},
                {0, 1},
                {1, 0},
                {0, -1}};

struct Position
{
    //The x and y positions
    int x, y;

    //Initialize a new Position
    Position(int xx = 0, int yy = 0)
        :x(xx), y(yy)
    {

    }

    friend bool operator == (const Position first, const Position second)
    {
        return first.x == second.x && first.y == second.y;
    }

    bool empty()
    {
        return grid[x][y] == '.';
    }
};


int main(int argc, char *argv[])
{
        ifstream fin("ttwo.in");
        ofstream fout("ttwo.out");
        Position cow, farmer;
        int moves = 0, current_cow_dir = 0, current_farmer_dir = 0, i = 0;


        for(int i = 0; i < NUM; i++)
        {
            fin.getline(grid[i], 11);
            for(int j = 0; j < NUM; j++)
            {
                if(grid[i][j] == 'C' || grid[i][j] == 'F')
                {
                    if(grid[i][j] == 'C')
                    {
                        cout << "found C";
                        cow = Position(i,j);
                    }
                    else
                    {
                        cout << "found F";
                        farmer = Position(i,j);
                    }
                    grid[i][j] = '.';
                    break;
                }
            }
        }


        while(++i)
        {
            if(cow == farmer)
                break;

            //Create a new_cow position for the cow(we now that the first move is always to north(0)
            Position new_cow = Position(cow.x + dirs[current_cow_dir][0],
                                     cow.y + dirs[current_cow_dir][1]);
            //Update the position of the cow
            if(!new_cow.empty())
            {
                current_cow_dir = (current_cow_dir + 1) % 4;
            }else
                cow = new_cow;

            //Create a new_farmer position for the farmer(it also starts at north(0))
            Position new_farmer = Position(farmer.x + dirs[current_farmer_dir][0],
                                        farmer.y + dirs[current_farmer_dir][1]);

            //Update the position of the farmer
            if(!new_farmer.empty())
            {
                current_farmer_dir = (current_farmer_dir + 1) % 4;
            }else
                farmer = new_farmer;
        }

        fout << i - 1;

        return 0;
}
