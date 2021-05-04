#ifndef MID_PROJECT_H
#define MID_PROJECT_H
#include <iostream>
#include <vector>

class Maze
{
    using maze = std::vector<std::vector<int>>;
    public:
        Maze(size_t,size_t);
        void show();
        void dfs();
        void randorm_choose();
        // ~Maze();
    private:
        size_t rows;
        size_t columns;
        maze m;
};

#endif