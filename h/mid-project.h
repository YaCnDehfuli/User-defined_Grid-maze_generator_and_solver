#ifndef MID_PROJECT_H
#define MID_PROJECT_H
#include <iostream>
#include <stdio.h>
#include<iomanip>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <list>
#include <queue>
// #include <windows.h>
// #include <bits/stdc++.h>

  

class Maze
{
    using maze = std::vector<std::vector<int>>;
  
    public:
        Maze(size_t,size_t,double);
        void maze_show();
        // //void maze_show_2();
        void path_show(maze);
        void path_show_2(maze);
        
        void dfs();
        void bfs();
        std::vector<std::vector<bool>> vis;
        bool is_valid(std::pair<size_t,size_t> p);
        bool is_valid_prime(std::pair<size_t,size_t> p);
        void randorm_choose();
        std::pair<size_t,size_t> point_to_cordinates(size_t );
        size_t cordinates_to_point(std::pair<size_t,size_t>);
        // showing_maze sm;
        maze m;
        maze mb;
        maze parent_maze;
        size_t dfs_cells_to_goal;
        size_t bfs_cells_to_goal;
    private:
        size_t rows;
        size_t columns;
        double percentage;
};

#endif