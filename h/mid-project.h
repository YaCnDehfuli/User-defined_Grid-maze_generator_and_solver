#ifndef MID_PROJECT_H
#define MID_PROJECT_H
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

class Maze
{
    using maze = std::vector<std::vector<int>>;
    using showing_maze = std::vector<std::vector<std::string>>;
    
    public:
        Maze(size_t,size_t,double);
        
        void maze_show();
        void path_show();
        void dfs();
        std::vector<std::vector<bool>> vis;
        bool is_valid(std::pair<size_t,size_t> p);
        void randorm_choose();
        showing_maze sm;
        maze m;
        size_t cells_to_goal;
    private:
        size_t rows;
        size_t columns;
        double percentage;
};

#endif