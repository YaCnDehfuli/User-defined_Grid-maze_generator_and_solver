#include "mid-project.h"
#include <iomanip>
Maze::Maze(size_t r,size_t c)
{
    rows=r;
    columns=c;
    m = maze(rows,std::vector<int>(columns,1));
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
