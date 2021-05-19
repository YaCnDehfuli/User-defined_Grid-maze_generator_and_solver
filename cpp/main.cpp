#include <iostream>
#include "mid-project.h"
int main()
{
    Maze n(14, 14, 50);
    // n.maze_show();
    n.dfs();
    n.bfs();
    n.path_show(n.mb);
    n.path_show(n.m);
}