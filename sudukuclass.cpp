#include "sudukuclass.h"

sudu::sudu()
{
	sum = 91;
	step = 0;
	small = 9;
	smallx = smally = 0;
	whole = 0;
}

int sudu::find_grid(int x,int y)   //  read in the location and return the grid number
{
    int gx = (x-1)/3 + 1;
    int gy = (y-1)/3 + 1;
    return (gx-1)*3+gy;
}


void sudu::debug_print()//    print the whole pic to debug
{
    for(int i=1;i<=9;++i)
    {
        for(int j = 1;j<=9;++j)
        {
            if(!g[i][j].num)
                cout<<"* ";
            else cout<<g[i][j].num<<' ';
        }
        cout<<endl;
    }
    return;
}

void sudu::debug_print_seq()//    print the whole pic to debug
{
    for(int i=1;i<=9;++i)
    {
        for(int j = 1;j<=9;++j)
        {
            if(!g[i][j].num)
                cout<<"* ";
            else cout<<g[i][j].sequence<<' ';
        }
        cout<<endl;
    }
    return;
}


void sudu::form()
{
    int all = 20;
    while(all)
    {
        int tempx = rand()%9 + 1;
        int tempy = rand()%9 + 1;
        int tempnum = rand()%9 + 1;
        //cout<<"form:"<<tempx<<' '<<tempy<<' '<<tempnum<<endl;
        int ans = deny(tempx, tempy, tempnum, 1);
        if(ans > 0)
            --all;
    }
}



void sudu::readin()
{
    // set the graph
    
    
    
    
    
    
    //debug_print();
    int x = 1,y = 1,TempNum = 1;
    while(cin>>x>>y>>TempNum)
    {
        if(x*y*TempNum==0)
            break;
        
        
       // cout<<x<<y<<TempNum<<endl;
        if(TempNum!=0)
            deny(x,y,TempNum,true);
        
    }
    //debug_print();
    // here we have done all the readin and cut the branched
    //so we can go on the conculation
    // like the searching9
    // the least one have 2/3 so we can search through that
}

int sudu::test(int x,int y)
{
    if(whole == 333)
        return 333;
    for (int i=1;i<=9;++i)
    {
        for(int j = 1;j<=9;++j)
            g[i][j].changed = false;
    }
    if(x*y==0)
    {
        cout<<"going out of the graph"<<endl;
        return -1;
    }
    for(int i=1;i<=9;++i)
    {
        if(g[x][y].ok[i])
           whole = deny(x,y,i,0);
        if(whole == 333)
            return 333;
    }
    return 0;
    /*
     
     let all row column and grid elements delete the Num
     and then
     1. chhoose the least one to be the new one
     solve the new one
     2. find that somebody is 0 so we have to go back*/
    return 0;
}





int sudu::deny(const int x,const int y,const int Num,bool input)
{
    
    if(g[x][y].ok[Num]==false||g[x][y].num)
        return -369;//               when forming the graph ,if it is occupied, return 369 to change another one
    
    
    
    bool changed[10][10];
    for(int i=1;i<=9;++i)
        for(int j =1;j<=9;++j)
            changed[i][j] = 0;
    
    int success = 1;
    if(!input)
    {
        small = 9;
        smallx = 0;
        smally = 0;
    }
    
    g[x][y].num = Num;
    ++step;
    g[x][y].sequence = step;
    --sum;
    
    if(!sum)
    {
        cout<<"the final answer"<<endl;
        debug_print();
        whole = 333;
        //while(true)
          //  cout<<endl;
        return 333;
    }
    
    
    for(int i = 1;i<=9;++i)
    {
        // ??????????????????????????????????????????????????// ??????????????????????????????????????????????????// ??????????????????????????????????????????????????
        if(!g[x][i].num)
        {
            if(g[x][i].ok[Num])
            {
                g[x][i].ok[Num] = false;
                changed[x][i] = true;
                --g[x][i].posibles;
                
                
                if(g[x][i].posibles>=1)
                {
                    if(g[x][i].posibles<small)
                    {
                        small = g[x][i].posibles;
                        g[x][i].least = true;
                        g[smallx][smally].least = false;
                        smallx = x;
                        smally = i;
                        
                    }
                }
                else
                {
                    cout<<"have no answer row"<<x<<' '<<i<<endl;
                    success = false;
                }
            }
            else
            {
                if(g[x][i].posibles>=1)
                {
                    if(g[x][i].posibles<small)
                    {
                        small = g[x][i].posibles;
                        g[x][i].least = true;
                        g[smallx][smally].least = false;
                        smallx = x;
                        smally = i;
                        
                    }
                }
                else
                {
                    cout<<"have no answer row"<<x<<' '<<i<<endl;
                    success = false;
                }
            }
            /*
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
             }*/
            
        }
        if(!g[i][y].num)
        {
            if(g[i][y].ok[Num])
            {
                g[i][y].ok[Num] = false;
               changed[i][y] = true;
                --g[i][y].posibles;
                /*
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
                 }*/
                if(g[i][y].posibles>=1)
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
                    success = false;
                }
            }
            else
            {
                if(g[i][y].posibles>=1)
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
                    success = false;
                }
                
            }

        }
            }
    const int gridpos = find_grid(x,y);
    for(int i = ((gridpos-1)/3+1)*3-2;i<=((gridpos-1)/3+1)*3;++i)
        for(int j = ((gridpos-1)%3+1)*3-2;j<=((gridpos-1)%3+1)*3;++j)
        {
            if(!g[i][j].num)
            {
                if(g[i][j].ok[Num])
                {
                    g[i][j].ok[Num] = false;
                    changed[i][j] = true;
                    --g[i][j].posibles;
                    /*if(g[i][j].posibles==1)
                     {
                     for(int p = 1;p<=9;++p)
                     {
                     if(g[i][j].ok[p])
                     {
                     deny(i,j,p);
                     break;
                     }
                     }
                     }*/
                    if(g[i][j].posibles>=1)
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
                        success = false;
                    }
                }
                else
                {
                    if(g[i][j].posibles>=1)
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
                        success = false;
                    }
                }
            }
        }
    if(input&&success)
        return 666;
    if(input&&!success)
        
    {
        --step;
        g[x][y].sequence = -1;
        ++sum;
        g[x][y].num = 0;
        
        for(int i = 1;i<=9;++i)
        {
            if(changed[x][i])
            {
                changed[x][i] = false;
                g[x][i].posibles += 1;
                g[x][i].ok[Num] = true;
            }
            if(changed[i][y])
            {
                changed[i][y] = false;
                g[i][y].posibles +=1;
                g[i][y].ok[Num] = true;
            }
        }
        const int gridpos = find_grid(x,y);
        for(int i = ((gridpos-1)/3+1)*3-2;i<=((gridpos-1)/3+1)*3;++i)
            for(int j = ((gridpos-1)%3+1)*3-2;j<=((gridpos-1)%3+1)*3;++j)
            {
                if(changed[i][j])
                {
                    changed[i][j] = false;
                    g[i][j].posibles += 1;
                    g[i][j].ok[Num] = true;
                }
            }
        cout<<"input has problem"<<endl;
        return -369;
    }
   // debug_print();
    //cout<<x<<"******** regular"<<y<<endl;
    
    
    if(success)
        success = test(smallx,smally);
    if(success==333)
        return 333;
    
    if(!success)
    {
      //  cout<<"worong!!!!!"<<endl;
       // cout<<x<<"   cuo     "<<y<<endl;

        
        --step;
        g[x][y].sequence = -1;
        ++sum;
        g[x][y].num = 0;
        
        for(int i = 1;i<=9;++i)
        {
            if(changed[x][i])
            {
                changed[x][i] = false;
                g[x][i].posibles += 1;
                g[x][i].ok[Num] = true;
            }
            if(changed[i][y])
            {
                changed[i][y] = false;
                g[i][y].posibles +=1;
                g[i][y].ok[Num] = true;
            }
        }
        const int gridpos = find_grid(x,y);
        for(int i = ((gridpos-1)/3+1)*3-2;i<=((gridpos-1)/3+1)*3;++i)
            for(int j = ((gridpos-1)%3+1)*3-2;j<=((gridpos-1)%3+1)*3;++j)
            {
                if(changed[i][j])
                {
                    changed[i][j] = false;
                    g[i][j].posibles += 1;
                    g[i][j].ok[Num] = true;
                }
            }
    }
    
    return 0;
}

