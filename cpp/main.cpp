#include <iostream>
#include "mid-project.h"
int main()
{
Maze n (11,11);
n.show();
n.dfs();
n.show();
n.randorm_choose(60);
n.smshow();
// n.sm[2][3]="*";
// n.smshow();
}