#include "mid-project.h"
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono> 

Maze::Maze(size_t r, size_t c)
{
    rows = r;
    columns = c;
    m = maze(rows, std::vector<int>(columns,0));
    size_t counter{};
    vis = std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, false));
}

void Maze::show()
{
    std::cout << "\n";
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            std::cout << std::setw(4) << std::left << "|" << std::setw(4) << std::fixed << m[i][j];
        }
        std::cout << "|";
        std::cout << std::endl;
        for (size_t i{}; i < columns; i++)
            std::cout << "--------";
        std::cout << std::endl;
    }
}

void Maze::dfs()
{
    int counter{1};
    
    std::pair<size_t, size_t> starting_cell = {0, 0};
    std::pair<size_t, size_t> Goal_cell = {rows - 1, columns - 1};

    std::stack<std::pair<size_t, size_t>> st;
    std::pair<size_t, size_t> current_cell = starting_cell;

    st.push(current_cell);
    
    while (!st.empty())
    {
        current_cell = st.top();
        st.pop();
        
        if (is_valid(current_cell))
        {
            vis[current_cell.first][current_cell.second] = true;
            m[current_cell.first][current_cell.second]=counter;
            counter++;
            if (current_cell == Goal_cell)
            {
                std::cout<<std::endl<<"I found a path !!!"<<std::endl;
                break;
            }
        }
        else
            continue;

        std::pair<size_t, size_t> up{current_cell.first, current_cell.second - 1};
        std::pair<size_t, size_t> down{current_cell.first, current_cell.second + 1};
        std::pair<size_t, size_t> left{current_cell.first - 1, current_cell.second};
        std::pair<size_t, size_t> right{current_cell.first + 1, current_cell.second};

        std::vector<std::pair<size_t,size_t>> directions {up,down,left,right};

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (directions.begin(), directions.end(), std::default_random_engine(seed));
        
        for(auto &i:directions)
            st.push(i);
    }
}

bool Maze::is_valid(std::pair<size_t, size_t> p)
{
    if (p.first >= rows || p.second >= columns)
        return false;
    if (vis[p.first][p.second])
        return false;
    else
        return true;
}
