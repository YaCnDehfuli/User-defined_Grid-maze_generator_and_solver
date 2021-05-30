#ifndef MID_PROJECT_H
#define MID_PROJECT_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <queue>

class Maze
{
    using maze = std::vector<std::vector<int>>;
  
    public:
        Maze(size_t,size_t,double);
        void maze_show();
        void path_show(maze);
        
        void dfs(double);
        void randorm_choose();
        void bfs();
        void bidirectional();
        void Backward_bfs();
        
        std::vector<std::vector<bool>> vis;
        bool is_valid(std::pair<size_t,size_t> p);
        
        std::pair<size_t,size_t> point_to_cordinates(size_t );
        size_t cordinates_to_point(std::pair<size_t,size_t>);

        maze DFS_maze;
        maze BFS_maze;
        maze Backward_BFS_maze;
        maze parent_maze;
        maze Bidirectional_maze;

       
        std::vector<size_t> BFS_route;
        std::vector<size_t> Backward_BFS_route;

        size_t dfs_cells_to_goal;
        size_t bfs_cells_to_goal;
        size_t bidirectional_cells_to_goal;

    
    private:
        
        size_t rows;
        size_t columns;
        double percentage;
};

#endif