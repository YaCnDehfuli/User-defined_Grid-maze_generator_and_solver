#include "mid-project.h"

Maze::Maze(size_t r, size_t c)
{
    rows = r;
    columns = c;
    m = maze(rows, std::vector<int>(columns, 0));
    sm = showing_maze(rows, std::vector<std::string>(columns, " "));
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
void Maze::smshow()
{
    std::cout << "\n";
    for (size_t i{}; i < columns; i++)
        std::cout << "------";
    std::cout<<std::endl;
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            std::cout << std::setw(2) << std::left << "|" << std::setw(4) << std::fixed << sm[i][j];
        }
        std::cout << "|";
        std::cout << std::endl;
        for (size_t i{}; i < columns; i++)
            std::cout << "------";
        std::cout << std::endl;
    }
}

void Maze::dfs()
{

    std::pair<size_t, size_t> starting_cell = {0, 0};
    std::pair<size_t, size_t> Goal_cell = {rows - 1, columns - 1};

    std::stack<std::pair<size_t, size_t>> st;
    std::pair<size_t, size_t> current_cell = starting_cell;
q:
    st.push(current_cell);
    size_t counter{1};

    while (!st.empty())
    {
        current_cell = st.top();
        st.pop();

        if (is_valid(current_cell))
        {
            vis[current_cell.first][current_cell.second] = true;
            m[current_cell.first][current_cell.second] = counter;
            counter++;
            cells_to_goal = counter;
            if (current_cell == Goal_cell)
            {
                if (counter < (size_t(rows + columns) * 1.2))
                {
                    std::cout << "\n"
                              << "I found a path !!!" << std::endl;
                    goto p;
                }
                else
                {
                    goto n;
                }
            }
        }
        else
            continue;

        std::pair<size_t, size_t> up{current_cell.first, current_cell.second - 1};
        std::pair<size_t, size_t> down{current_cell.first, current_cell.second + 1};
        std::pair<size_t, size_t> left{current_cell.first - 1, current_cell.second};
        std::pair<size_t, size_t> right{current_cell.first + 1, current_cell.second};

        std::vector<std::pair<size_t, size_t>> directions{up, down, left, right};

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(directions.begin(), directions.end(), std::default_random_engine(seed));

        for (auto &i : directions)
            st.push(i);
    }
n:
    std::cout << m[Goal_cell.first][Goal_cell.second] << std::endl;
    if (m[Goal_cell.first][Goal_cell.second] > int((rows + columns) * 1.2))
    {
        while (!st.empty())
        {
            st.pop();
        }
        for (size_t i{}; i < vis.size(); i++)
        {
            for (size_t j{}; j < vis[0].size(); j++)
            {
                vis[i][j] = false;
            }
        }
        std::pair<size_t, size_t> starting_cell = {0, 0};
        // std::pair<size_t, size_t> Goal_cell = {rows - 1, columns - 1};
        current_cell = starting_cell;
        counter = 1;
        for (size_t i{}; i < rows; i++)
        {
            for (size_t j{}; j < columns; j++)
            {
                m[i][j] = 0;
            }
        }
        goto q;
    }
p:
    std::cout << " DFS Done" << std::endl;
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

void Maze::randorm_choose(double percentage)
{
    size_t counter{};
    // std::cout<<size_t((rows * columns - cells_to_goal) * percentage / 100)<<std::endl;
    while (counter <= size_t((rows * columns - cells_to_goal) * percentage / 100))
    {
        size_t random_row = rand() % (rows);
        size_t random_column = rand() % (columns);
        std::cout << "random row is : " << random_row << std::endl;
        std::cout << "random coulumd is : " << random_column << std::endl;
        if (m[random_row][random_column] == 0)
        {
            sm[random_row][random_column] = "***";
            counter++;
        }
    }
}
