#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int sum = 81;
int step = 0;
int grid[10];    // at begin 
bool gridnum[10][10];

int find_grid(int x,int y)   //  read in the location and return the grid number
{
	int gx = (x-1)%3 + 1;
	int gy = (y-1)%3 + 1;
	return (gx-1)*3+gy;
}

/*
grid
1 2 3
4 5 6
7 8 9

*/



struct point    
{
	int num;
	bool ok[10];
	bool settled;
	int posibles;
	int sequence;
	point()
	{
		sequence = -1;
		num = 0;
		for(int i=0;i<=9;++i)
			ok = true;
		posibles =9;
	}
}g[10][10];

void debug_print()//    print the whole pic to debug
{
	for(int i=1;i<=9;++i)
	{
		for(int j = 1;j<=9;++j)
		{
			if(!g[i][j].num)
				cout<<"* ";
			else cout<<g[i][j].num;
		}
		cout<<endl;
	}
	return;
}

/*
void solverow()
{
	int occupiedrow[10];
	int occupiedcol[10];
	for(int i=1;i<=9;++i)
	{
		memset(occupiedcol,0,sizeof(occupiedcol));
		memset(occupiedrow,0,sizeof(occupiedrow));
		for(int j = 1;j<=9;++j)
		{
			if(g[i][j].num)
				occupiedrow[g[i][j].num] = 1;
			if(g[j][i].num)
				occupiedcol[g[j][i].num] = 1;
		}
		for(int j = 1;j<=9;++j)
		{
			if(!g[i][j].num)
				for(int k = 1;k<=9;++k)
					if(occupiedrow[k])
					{
						g[i][j].ok[k] = false;
						--g[i][j].posibles;
					}	
			if(!g[j][i].num)
				for(int k = 1;k<=9;++k)
					if(occupiedcol[k])
					{
						g[j][i].ok[k] = false;
						
						//	x stands for the row num and y for the cols so if i want to a[x][y]
						
						--g[j][i].posibles;
					}

		}
	}
}
*/
void deny(const int &x,const int &y,const int &Num)
{
	--sum;
	g[x][y].num = Num;
	for(int i = 1;i<=9;++i)
	{
		if(!g[i][x].num)
		{
			g[x][i].ok[Num] = false;
			--g[x][i].posibles;
			if(g[x][i].posibles==1)
				{
					for(int p = 1;p<=9;++p)
					{
						if(g[x][i].ok[p])
						{	
							deny(x,i,p);
							break;
						}
					}
				}
		}
		if(!g[i][y].num)
		{
			g[i][y].ok[Num] = false;
			--g[i][y].posibles;
			if(g[i][y].posibles==1)
				{
					for(int p = 1;p<=9;++p)
					{
						if(g[i][y].ok[p])
						{	
							deny(i,y,p);
							break;
						}
					}
				}
		}
	}
	const int gridpos = find_grid(x,y);
	--grid[gridpos];
	gridnum[gridpos][Num] = 0;
	if(grid[gridpos] == 1)
	{
		for(int i = )
	}
	
}

int basicsolve()
{
	for(int i=1;i<=9;++i)
		for(int j =1;j<=9;++j)
		{
			if(!g[i][j].num&&g[i][j].posibles==1)
			{
				int k;
				for(k = 1;k<=9;++k)
				{
					if(g[i][j].ok[k])
						break;
				}
				deny(i,j,k);
			}
		}
}
void readin()
{
	// set the graph
	for(int i=1;i<=9;++i)
	{
		grid[i] = 9;
		for(int j = 1;j<=9;++j)
		{
			gridnum[i][j] = 1;
		}
	}



	fstream fin;
	fin.open("test.txt");
	while(!fin.eof())
	{
		int x,y,TempNum;
		fin>>x>>y>>TempNum;
		deny(x,y,TempNum);
	}
}
int main()
{


}