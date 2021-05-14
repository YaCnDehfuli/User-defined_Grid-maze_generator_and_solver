#ifndef MID_PROJECT_H
#define MID_PROJECT_H
#include <iostream>
#include <vector>
#include <stack>
class Maze
{
    using maze = std::vector<std::vector<int>>;

    public:
        Maze(size_t,size_t);
        void show();
        void dfs();
        std::vector<std::vector<bool>> vis;

        bool is_valid(std::pair<size_t,size_t> p);
        // void randorm_choose();
        maze m;
    private:
        size_t rows;
        size_t columns;
};

#endif