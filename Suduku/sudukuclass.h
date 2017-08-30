#ifndef SUDU
#define SUDU
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

class sudu
{
private:
    int small;
    int whole;

public:

    int sum;
    int step;
    int smallx,smally;
	struct point
	{
    	int num;
    	bool ok[10];
    	bool settled;
    	int posibles;
    	int sequence;
    	bool least;
    	bool changed;
    	point()
    	{
        	sequence = -1;
        	num = 0;
        	for(int i=0;i<=9;++i)
            ok[i] = true;
        	posibles =9;
        	least = false;
        	changed = false;
    	}
	}g[10][10];
    int right[10][10];
    sudu()
    {
        sum = 81;
        step = 0;
        small = 9;
        smallx = smally = 0;
        whole = 0;
    }
    void clear();
    int find_grid(int,int);
	int deny(const int,const int,const int,bool);
	int test(int,int);
    void debug_print();
	void debug_print_seq();
    void form(int i  = 1);
	void readin();
    struct tree
    {
        int depth;
        int px,py,pnum;
        int who;
        int down;
        tree* next[10];
        tree* former;
        tree()
        {
            down = 0;
            depth = 0;
            px = py = pnum = 0;
            who = 0;
            for(int i=0;i<=9;++i)
                next[i] = NULL;
            former = NULL;
        }
        tree(int x,int y,int num,int d)
        {
            down = 0;
            depth = d;
            px = x;
            py = y;
            pnum = num;
            who = 0;
            for(int i=0;i<=9;++i)
                next[i] = NULL;
            former = NULL;
        }
    }*node,*finalone;

};
#endif
