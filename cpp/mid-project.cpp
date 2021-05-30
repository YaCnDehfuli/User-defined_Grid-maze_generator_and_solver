#include "mid-project.h"


Maze::Maze(size_t r, size_t c, double _percentage)
{
    rows = r;
    columns = c;
    percentage = _percentage;
    DFS_maze = maze(rows, std::vector<int>(columns, 0));
    BFS_maze = maze(rows, std::vector<int>(columns, 0));
    Backward_BFS_maze = maze(rows, std::vector<int>(columns, 0));
    Bidirectional_maze = maze(rows, std::vector<int>(columns, 0));
    parent_maze = maze(rows, std::vector<int>(columns, 0));
    std::vector<size_t> BFS_route;
    std::vector<size_t> Backward_BFS_route;
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            parent_maze[i][j]= (i*(columns))+j;
        }
    }
    vis = std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, false));
    dfs(1.3);
    randorm_choose();
    maze_show();
}

void Maze::path_show(maze _m)
{
    std::cout << "\n";
    for (size_t i{}; i < columns; i++)
        std::cout << "-----";
    std::cout << std::endl;
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            if(_m[i][j]==-100)
            {
                std::cout<<"|";
                printf("\033[%dm    \033[m",47);
            }
            else if(_m[i][j] > 0)
            {
                std::cout<<"|";
                printf("\033[%dm %3d\033[m", 44 ,_m[i][j]);

            }
            else if(_m[i][j]<0 && _m[i][j]>-100)
            {
                std::cout<<"|";
                printf("\033[%dm %3d\033[m", 45 ,-1*_m[i][j]);
            }
            else
            {
                std::cout<<std::setw(13);
                std::cout << std::setw(2) << std::left << "|" << std::setw(3) << " "; 
            }
        }
        std::cout << "|";
        std::cout << std::endl;
        for (size_t i{}; i < columns; i++)
            std::cout << "-----";
        std::cout << std::endl;
    }
}


void Maze::maze_show()
{
    std::cout << "\n";
    for (size_t i{}; i < columns; i++)
        std::cout << "-----";
    std::cout << std::endl;
    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            if(DFS_maze[i][j]==-100)
            {
                std::cout<<"|";
                printf("\033[%dm    \033[m",47);
            }
            else
            {
                std::cout<<std::setw(13);
                std::cout << std::setw(2) << std::left << "|" << std::setw(3) << " ";  //sm[i][j];
            }
        }
        std::cout << "|";
        std::cout << std::endl;
        for (size_t i{}; i < columns; i++)
            std::cout << "-----";
        std::cout << std::endl;
    }
}

bool Maze::is_valid(std::pair<size_t, size_t> p)
{
    if(p.first <0 || p.second<0)
        return false;
    else if (p.first >= rows || p.second >= columns)
        return false;
    else if (vis[p.first][p.second])
        return false;
    else if (DFS_maze[p.first][p.second] == -100)
        return false;
    else
        return true;
}

void Maze::dfs(double coef)
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
            DFS_maze[current_cell.first][current_cell.second] = counter;
            counter++;
            dfs_cells_to_goal = counter;
            if (current_cell == Goal_cell)
            {
                if (counter < (size_t(rows + columns) * coef))
                {
                    break;
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
    if (DFS_maze[Goal_cell.first][Goal_cell.second] > int((rows + columns) * coef))
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
        current_cell = starting_cell;
        counter = 1;
        for (size_t i{}; i < rows; i++)
        {
            for (size_t j{}; j < columns; j++)
            {
                DFS_maze[i][j] = 0;
            }
        }
        goto q;
    }
}

void Maze::randorm_choose()
{
    size_t counter{1};
    while (counter <= size_t((rows * columns - dfs_cells_to_goal) * percentage / 100) + 1)
    {
        size_t random_row = rand() % (rows);
        size_t random_column = rand() % (columns);
        if (DFS_maze[random_row][random_column] == 0)
        {
            DFS_maze[random_row][random_column] = -100;
            BFS_maze[random_row][random_column] = -100;
            Backward_BFS_maze[random_row][random_column]=-100;
            Bidirectional_maze[random_row][random_column]=-100;
            counter++;
        }
    }
}

std::pair<size_t,size_t> Maze::point_to_cordinates(size_t point)
{
    size_t r = size_t(point/columns);
    size_t c = point-(r*columns);
    std::pair<size_t,size_t> cor{r,c};
    return cor;
}

size_t Maze::cordinates_to_point(std::pair<size_t,size_t> cori)
{
    return parent_maze[cori.first][cori.second];
}

void Maze::bfs()
{
    std::pair<size_t, size_t> starting_cell = {0, 0};
    std::pair<size_t, size_t> Goal_cell = {rows - 1, columns - 1};

    std::queue<std::pair<size_t, size_t>> q;
    std::pair<size_t, size_t> current_cell = starting_cell;
    for (size_t i{}; i < vis.size(); i++)
    {
        for (size_t j{}; j < vis[0].size(); j++)
        {
            vis[i][j] = false;
        }
    }

    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            if (BFS_maze[i][j] != -100)
            {
                BFS_maze[i][j] = 0;
            }
        }
    }
    std::vector<size_t> parent_vector (rows*columns);
    q.push(current_cell);
    vis[current_cell.first][current_cell.second] = true;
    BFS_maze[current_cell.first][current_cell.second] = 1;

    parent_vector[0]=-1;
    bfs_cells_to_goal=1;
    while (!q.empty())
    {
        bfs_cells_to_goal = bfs_cells_to_goal + 1;
        current_cell = q.front();
        q.pop();

        std::pair<size_t, size_t> up{current_cell.first, current_cell.second - 1};
        std::pair<size_t, size_t> down{current_cell.first, current_cell.second + 1};
        std::pair<size_t, size_t> left{current_cell.first - 1, current_cell.second};
        std::pair<size_t, size_t> right{current_cell.first + 1, current_cell.second};
        std::vector<std::pair<size_t, size_t>> directions{up, down, left, right};
        
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(directions.begin(), directions.end(), std::default_random_engine(seed));
                
        for (auto &i : directions)
        {
            if (is_valid(i))
            {
                q.push(i);
                vis[i.first][i.second] = true;
                parent_vector[(parent_maze[i.first][i.second])]=parent_maze[current_cell.first][current_cell.second];
                if (i == Goal_cell)
                {
                    std::pair <size_t,size_t> corr =i;
                    size_t pw{1};
                    while(pw!=0)
                    {
                        pw = parent_vector[cordinates_to_point(corr)];
                        BFS_route.push_back(pw);
                        corr=point_to_cordinates(pw);
                    }
                    break;
                }
            }

            else
                continue;
        }
    }
    bfs_cells_to_goal=BFS_route.size();
    BFS_maze[Goal_cell.first][Goal_cell.second]=bfs_cells_to_goal+1;
    for(auto i:BFS_route)
    {
        BFS_maze[point_to_cordinates(i).first][point_to_cordinates(i).second]=bfs_cells_to_goal;
        bfs_cells_to_goal--;
    }
    bfs_cells_to_goal=BFS_route.size();
}

void Maze::Backward_bfs()
{
    std::pair<size_t, size_t> starting_cell = {rows - 1, columns - 1};
    std::pair<size_t, size_t> Goal_cell = {0, 0};

    std::queue<std::pair<size_t, size_t>> q;
    std::pair<size_t, size_t> current_cell = starting_cell;
    
    for (size_t i{}; i < vis.size(); i++)
    {
        for (size_t j{}; j < vis[0].size(); j++)
        {
            vis[i][j] = false;
        }
    }

    for (size_t i{}; i < rows; i++)
    {
        for (size_t j{}; j < columns; j++)
        {
            if (Backward_BFS_maze[i][j] != -100)
            {
                Backward_BFS_maze[i][j] = 0;
            }
        }
    }
    std::vector<size_t> Backward_parent_vector (rows*columns);

    q.push(current_cell);
    
    vis[current_cell.first][current_cell.second] = true;
    Backward_BFS_maze[current_cell.first][current_cell.second] = 1;

    Backward_parent_vector[0]=-1;
    
    while (!q.empty())
    {
        current_cell = q.front();
        q.pop();

        std::pair<size_t, size_t> up{current_cell.first, current_cell.second - 1};
        std::pair<size_t, size_t> down{current_cell.first, current_cell.second + 1};
        std::pair<size_t, size_t> left{current_cell.first - 1, current_cell.second};
        std::pair<size_t, size_t> right{current_cell.first + 1, current_cell.second};
        std::vector<std::pair<size_t, size_t>> directions{up, down, left, right};
        
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(directions.begin(), directions.end(), std::default_random_engine(seed));
                
        for (auto &i : directions)
        {
            if (is_valid(i))
            {
                q.push(i);
                vis[i.first][i.second] = true;
                Backward_parent_vector[(parent_maze[i.first][i.second])]=parent_maze[current_cell.first][current_cell.second];
                if (i == Goal_cell)
                {
                    std::pair <size_t,size_t> corr =i;
                    size_t pw{1};
                    while(pw!=0)
                    {
                        pw = Backward_parent_vector[cordinates_to_point(corr)];
                        Backward_BFS_route.push_back(pw);
                        corr=point_to_cordinates(pw);
                    }
                    break;
                }
            }

            else
                continue;
        }
    }
    size_t Backward_bfs_cells_to_goal {Backward_BFS_route.size()};
    for(auto i:Backward_BFS_route)
    {
        Backward_BFS_maze[point_to_cordinates(i).first][point_to_cordinates(i).second]=Backward_bfs_cells_to_goal-1;
        Backward_bfs_cells_to_goal--;
    }
    Backward_bfs_cells_to_goal=Backward_BFS_route.size();
    Backward_BFS_maze[Goal_cell.first][Goal_cell.second] = Backward_bfs_cells_to_goal;
}

void Maze::bidirectional()
{
    size_t joint_point;
    size_t c{1};
    bool intersection {false};
    std::reverse(Backward_BFS_route.begin(),Backward_BFS_route.end());
    std::reverse(BFS_route.begin(),BFS_route.end());

    std::vector<size_t> bfway;
    std::vector<size_t> bcway;
    m:
    bfway.push_back(BFS_route[c]);
    bcway.push_back(Backward_BFS_route[c]);
    for(auto i:bfway)
    {
        for(auto j:bcway)
        {
            if(j==i)
            {
                joint_point=i;
                intersection = true;
                goto n;
            }
        }
    }
    if(!intersection)
    {
        c++;
        goto m;
    }
    n:
    size_t cc{0};
    for(auto i:Backward_BFS_route)
    {
        Bidirectional_maze[point_to_cordinates(i).first][point_to_cordinates(i).second]= -1*cc;
        cc++;
        if(i==joint_point)
        {
            break;
        }

    }
    Bidirectional_maze[0][0]=1;
    size_t ccc{1};
    for(auto i:BFS_route)
    {
        Bidirectional_maze[point_to_cordinates(i).first][point_to_cordinates(i).second]= ccc;
        ccc++;
        if(i == joint_point)
        {
            break;
        }
    }
    bidirectional_cells_to_goal = cc+ccc-4;
}