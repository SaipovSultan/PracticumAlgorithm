#include "test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int buying_houses(vector<int> house_prices, int amount){
    sort(house_prices.begin(), house_prices.end());
    return distance(house_prices.cbegin(), find_if(house_prices.cbegin(), house_prices.cend(), [&amount](const auto price){
        if(amount < price){
            return true;
        }else{
            amount -= price;
            return false;
        }
    }));
}

void Test(){
    {
        const vector<int> house_prices = {999, 999, 999};
        const int amount = 300;
        const int expected = 0;
        AssertEqual(buying_houses(house_prices, amount), expected);
    }
    {
        const vector<int> house_prices = {350, 999, 200};
        const int amount = 1000;
        const int expected = 2;
        AssertEqual(buying_houses(house_prices, amount), expected);
    }
}

struct Coordinate{
    size_t x, y;
};

bool is_land(size_t x, size_t y, const vector<vector<char>>& grid){
    return grid[y][x] == '1';
}

void kill_island(size_t x, size_t y,vector<vector<char>>& grid){
    queue<Coordinate> que;
    que.push({x, y});
    while(!que.empty()){
        size_t size = que.size();
        for(size_t i = 0;i < size;++i){
            auto coordinate = que.front();
            if(is_land(coordinate.x, coordinate.y, grid)){
                grid[coordinate.y][coordinate.x] = '0';
                if(coordinate.x > 0 && is_land(coordinate.x - 1, coordinate.y, grid)){
                    que.push({coordinate.x - 1, coordinate.y});
                }
                if(coordinate.x + 1 < grid[y].size() && is_land(coordinate.x + 1, coordinate.y, grid)){
                    que.push({coordinate.x + 1, coordinate.y});
                }
                if(coordinate.y > 0 < grid.size() && is_land(coordinate.x, coordinate.y - 1, grid)){
                    que.push({coordinate.x, coordinate.y - 1});
                }
                if(coordinate.y + 1 < grid.size() && is_land(coordinate.x, coordinate.y + 1, grid)){
                    que.push({coordinate.x, coordinate.y + 1});
                }
            }
            que.pop();
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t cnt_island = 0;
        for(size_t y = 0;y < grid.size();++y){
            for(size_t x = 0;x < grid[y].size();++x){
                if(grid[y][x] == '1'){
                    kill_island(x, y, grid);
                    ++cnt_island;
                }
            }
        }
        return cnt_island;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> grid = {{'1','0','1','1','1'},
                                 {'1','0','1','0','1'},
                                 {'1','1','1','0','1'}};
    solution.numIslands(grid);
    return 0;
}