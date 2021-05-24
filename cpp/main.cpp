#include <iostream>
#include "mid-project.h"
int main()
{
    size_t r{};
    size_t c{};
    size_t p{};
    size_t choice{};

    std::cout << "\n\n\n\n";
    printf("%68s", " ");

    printf("\033[%dm**** \U0001F600 Hey there \U0001F600 ! **** \033[m\n\n", 96);
    printf("%47s", " ");
    printf("\033[%dm This is a simple \"Grid maze\" solver using\033[m", 95);
    printf("\033[%dm DFS\033[m", 92);
    printf("\033[%dm and \033[m", 95);
    printf("\033[%dmBFS \033[m", 92);
    printf("\033[%dmalgorithms ⛳ \033[m\n\n", 95);
    printf("%41s", " ");
    printf("\033[%dm The maze gonna be compeletly created by you, so fill the blanks with a number ✍ \033[m\n\n", 34);

p:
    std::cout << "\n";
    printf("\033[%dmHow many rows do you want it to have\?: \033[m", 33);
    while (1)
    {
        if (std::cin >> r)
        {
            if (r == 0 || r == 1)
            {
                printf("\033[%dm\n You can't have a maze with that row size ⛔ !!.Try again: \033[m", 91);
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            else if(r>35)
            {
                printf("\033[%dm\n SORRY 😓 !! this row size is going to create a maze which is bigger   \033[m\n", 91);
                printf("\033[%dm than VScode console size ⛔! Try lower dimentions (Maximum:35) : \033[m", 91);
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            else    
                break;
        }

        else
        {
            printf("\033[%dm\n You are NOT entering a number ⛔ !!.Try again: \033[m", 91);
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    }

    printf("\033[%dm\nHow many columns do you want it to have\?: \033[m", 33);
    while (1)
    {
        if (std::cin >> c)
        {
            if (c == 0 || c == 1)
            {
                printf("\033[%dm\n You can't have a maze with that column size ⛔ !!.Try again: \033[m", 91);
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            else
                break;
        }
        else
        {
            printf("\033[%dm\n You are NOT entering a number ⛔ !!.Try again: \033[m", 91);
            std::cin.clear();
            while (std::cin.get() != '\n'); 
        }
    }
    std::cout << "\n\n\n";
    printf("%25s", " ");
    printf("\033[38;5;%dm In order to give you the maximum customization of maze, you can determine how full you would like your maze to be\033[m\n", 66);
    printf("%25s", " ");
    printf("\033[38;5;%dm you can do that by assigning a double number that represents the\033[m", 66);
    printf("\033[38;5;%dm percentage of obstacles\033[m", 1);
    printf("\033[38;5;%dm in your whole maze cells\033[m\n\n", 66);

    printf("\033[%dm\n How much obstacle percentage do you want\?: \033[m", 33);
    while (1)
    {
        if (std::cin >> p)
        {
            if (p > 100)
            {
                printf("\033[%dm\n No number above 100 is allowed ⛔ !!.Try again: \033[m", 91);
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            else
                break;
        }
        else
        {
            printf("\033[%dm\n You are NOT entering a number ⛔ !!.Try again: \033[m", 91);
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    }

    printf("\033[38;5;%dm\n ⬇⬇⬇⬇⬇⬇ YOUR MAZE IS READY ⬇⬇⬇⬇⬇⬇ \033[m\n", 121);
    Maze n(r, c, p);

    printf("\033[38;5;%dm\n1.This is what I wanted 😍 \033[m\n", 10);
    printf("\033[38;5;%dm2.I want to change the maze 😑 \033[m\n", 9);
    printf("\033[38;5;%dm\nChoose what it's gonna be : \033[m", 220);
    // std::cin>>choice;
    while (1)
    {
        if (std::cin >> choice)
        {
            if (choice > 2)
            {
                printf("\033[%dm\n You are NOT choosing ⛔ !!.Try again: \033[m", 91);
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            else
                break;
        }
        else
        {
            printf("\033[%dm\n You are NOT choosing ⛔ !!.Try again: \033[m", 91);
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    }

    if (choice == 2)
        goto p;

    std::cout << "\n\n";
    printf("%65s", " ");
    printf("\033[38;5;%dm ****Ok🏁.Now it's time to solve your maze😎 ****\033[m\n\n", 87);
    printf("%48s", " ");
    printf("\033[38;5;%dm The path is shown by blue cells from starting cell ( 0 , 0 ) to Goal cell (\033[m", 87);
    printf("\033[%dm%3ld\033[m",96,r-1);
    printf("\033[38;5;%dm ,\033[m", 87);
    printf("\033[%dm%3ld\033[m",96,c-1);
    printf("\033[38;5;%dm )\033[m\n\n", 87);
    printf("%41s", " ");
    printf("\033[38;5;%dm There is numbers in blue cells which shows you the exact steps that program is taking to get there \033[m\n\n", 87);
    
    
    printf("\033[38;5;%dm ⬇⬇⬇⬇⬇⬇ THIS IS DFS ALGORITHM ⬇⬇⬇⬇⬇⬇ \033[m\n", 121);
    n.path_show(n.DFS_maze);
    std::cout<<"\n";
    printf("\033[38;5;%dmThis path used\033[m", 93);
    printf("\033[%dm%3ld\033[m",91,n.dfs_cells_to_goal-1);
    printf("\033[38;5;%dm cells to reach the goal cell\033[m\n", 93);
    
    
    std::cout<<"\n";
    printf("\033[38;5;%dm\n ⬇⬇⬇⬇⬇⬇ THIS IS BFS ALGORITHM ⬇⬇⬇⬇⬇⬇ \033[m", 121);
    n.bfs();
    n.path_show(n.BFS_maze);
    std::cout<<"\n";
    printf("\033[38;5;%dmThis path used\033[m", 93);
    printf("\033[%dm%3ld\033[m",91,n.bfs_cells_to_goal+1);
    printf("\033[38;5;%dm cells to reach the goal cell which is the shortest path possible!\033[m\n\n", 93);
    
}
