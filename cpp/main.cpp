#include <iostream>
#include "mid-project.h"
int main()
{
Maze n (14,14,50);
n.path_show();
n.maze_show();
n.bfs();
n.path_show();
}