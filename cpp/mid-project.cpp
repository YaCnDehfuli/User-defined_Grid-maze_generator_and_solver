#include "mid-project.h"
#include <iomanip>
Maze::Maze(size_t r,size_t c)
{
    rows=r;
    columns=c;
    m = maze(rows,std::vector<int>(columns,1));
    vis=std::vector<std::vector<bool>>(rows,std::vector<bool>(columns,false));
}

void Maze::show()
{
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            std::cout<<std::setw(2)<<std::left <<"|"<<std::setw(2)<<std::fixed<<m[i][j];
        }
        std::cout << "|";
        std::cout<<std::endl;
        std::cout << std::endl;
    }
}   

void Maze::dfs()
{
    
}

bool Maze::is_valid(std::pair<size_t,size_t> p)
{
    if(p.first>=rows || p.second>=columns)
        return false;
    if(vis[p.first][p.second])
        return false;
    else
        return true;
}
