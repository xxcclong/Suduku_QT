#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int sum = 81;
int step = 0;
int grid[10];    // at begin
bool gridnum[10][10];
int small = 9;
int smallx = 0,smally = 0;
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
	bool least;
	point()
	{
		sequence = -1;
		num = 0;
		for(int i=0;i<=9;++i)
			ok = true;
		posibles =9;
		least = false;
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

int deny(const int &x,const int &y,const int &Num)
{
	++step;
	g[x][y].sequence.num = step;
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
						if(p == 9)
						{
							cout<<"have no answer row"<<x<<' '<<y<<endl;
						}
					}
				}
			else if(g[x][i].posibles>1)
			{
				if(g[x][i].posibles<small)
				{
					small = g[x][i].posibles;
					g[x][i].least = true;
					g[smallx][smally].least = false;
					smallx = x;
					smally = y;

				}
			}
			else
			{
				cout<<"have no answer row"<<x<<' '<<y<<endl;
				return -1;
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
						if(p==9)
						{
							cout<<"no answer  column"<<i<<' '<<y<<endl;
							return -1;
						}
					}
				}
				else if(g[i][y].posibles>1)
				{
					if(g[i][y].posibles<small)
					{
						small = g[i][y].posibles;
						g[i][y].least = true;
						g[smallx][smally].least = false;
						smallx = i;
						smally = y;
					}
				}
				else
				{
					cout<<"no answer column"<<i<<' '<<y<<endl;
					return -1;
				}
		}
	}
	const int gridpos = find_grid(x,y);
			for(int i = (gridpos-1)/3+1;i<=(gridpos-1)%3+3;++i)
					for(int j = (gridpos-1)%3+1;j<=(gridpos-1)%3+3;++j)
					{
						if(!g[i][j].num)
						{
							g[i][j].ok[Num] = false;
							--g[i][j].posibles;
							if(g[i][j].posibles==1)
							{
								for(int p = 1;p<=9;++p)
								{
									if(g[i][j].ok[p])
									{
										deny(i,j,p);
										break;
									}
								}
							}
							else if(g[i][j].posibles>1)
							{
								if(g[i][j].posibles<small)
								{
									small = g[i][j].posibles;
									g[i][j].least = true;
									g[smallx][smally].least = false;
									smallx = i;
									smally = j;
								}
							}
							else
							{
									cout<<"no answer(grid)"<<i<<' '<<j<<endl;
							}
						}
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




	fstream fin;
	fin.open("test.txt");
	while(!fin.eof())
	{
		int x,y,TempNum;
		fin>>x>>y>>TempNum;
		if(tempNum!=0)
			deny(x,y,TempNum);

	}
	// here we have done all the readin and cut the branched
	//so we can go on the conculation
	// like the searching9
	// the least one have 2/3 so we can search through that
}
int main()
{


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