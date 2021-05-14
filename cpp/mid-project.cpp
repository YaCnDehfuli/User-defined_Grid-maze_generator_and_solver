#include "mid-project.h"
#include <iomanip>
// #include <stack>
#include <algorithm>
#include <random>
#include <chrono> 

Maze::Maze(size_t r, size_t c)
{
    rows = r;
    columns = c;
    m = maze(rows, std::vector<int>(columns));
    size_t counter{};
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            counter++;
            m[i][j] = counter;
        }
    }
    vis = std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, false));
}

void Maze::show()
{
    std::cout << "\n";
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            std::cout << std::setw(2) << std::left << "|" << std::setw(2) << std::fixed << m[i][j];
        }
        std::cout << "|";
        std::cout << std::endl;
        for (size_t i{}; i < columns; i++)
            std::cout << "----";
        std::cout << std::endl;
    }
}

// void next(std::pair<size_t,size_t> current_cell)
// {
//     Maze::st.push({current_cell.first-1,current_cell.second});
//     Maze::st.push({current_cell.first+1,current_cell.second});
//     Maze::st.push({current_cell.first,current_cell.second-1});
//     Maze::st.push({current_cell.first,current_cell.second+1});
// }


void Maze::dfs()
{
    std::pair<size_t, size_t> starting_cell = {0, 0};
    std::pair<size_t, size_t> Goal_cell = {rows - 1, columns - 1};
    std::cout << Goal_cell.first << "  " << Goal_cell.second << std::endl;
    std::stack<std::pair<size_t, size_t>> st;
    std::vector<size_t> route;
    std::pair<size_t, size_t> current_cell = starting_cell;
    st.push(current_cell);
    while (!st.empty())
    {
        current_cell = st.top();
        st.pop();
        if (is_valid(current_cell))
        {
            vis[current_cell.first][current_cell.second] = true;
            route.push_back(m[current_cell.first][current_cell.second]);
            std::cout << current_cell.first << "  " << current_cell.second << std::endl;
            if (current_cell == Goal_cell)
            {
                goto q;
                std::cout << "this is goal" << std::endl;
            }
        }
        else
            continue;

        std::pair<size_t, size_t> up{current_cell.first, current_cell.second - 1};
        std::pair<size_t, size_t> down{current_cell.first, current_cell.second + 1};
        std::pair<size_t, size_t> left{current_cell.first - 1, current_cell.second};
        std::pair<size_t, size_t> right{current_cell.first + 1, current_cell.second};

        std::vector<std::pair<size_t,size_t>> directions {up,down,left,right};
        std::cout << std::endl;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (directions.begin(), directions.end(), std::default_random_engine(seed));
        for(auto &i:directions)
            st.push(i);

    }
q:
    for (auto &i : route)
        std::cout << i << " ";
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
