//
//  main.cpp
//  Proj2_3530
//
//  Created by Zain Lateef on 12/1/16.
//  Copyright © 2016 Zain Lateef. All rights reserved.
//
#include<iostream>
#include<string>
int kmp(std::string target,std::string source)
{
    int targ_len=target.length();
    int orange=0,i=1,j=0,cnt=0;
    int holder[targ_len];
    holder[0]=0;
    while(i<targ_len)
    {
        if(target[i]==target[cnt])
        {
            cnt++;
            holder[i]=cnt;
            
            i++;
        }
        else
        {
            if(cnt!=0)
            {
                cnt=holder[cnt-1];
            }
            else
            {
                holder[i]=0;
                i++;
            }
        }
    }
    int text_len=source.length();
    i=0;
    while(i<text_len)
    {
        if(target[j]==source[i])
        {
            i++;
            j++;
        }
        
        if(j==targ_len)
        {
            orange++;
            j=holder[j-1];
        }
        else if(target[j]!=source[i]&&i<text_len)
        {
            if(j!=0)
                j=holder[j-1];
            else
                i=i+1;
        }
    }
    
    return orange;
}

void longest(int *rows,int *cols,int en)
{
    int uno_mas=en+1,i,j;
    int holder[uno_mas][uno_mas];
    for(i=0;i<uno_mas;i++)
{
    for(j=0;j<uno_mas;j++)
    {
        if(i==0||j==0)
            holder[i][j]=0;
        else if(rows[i-1]==cols[j-1])
            holder[i][j]=holder[i-1][j-1]+1;
        else
        {
            if(holder[i-1][j]>holder[i][j-1])
                holder[i][j]=holder[i-1][j];
            else
                holder[i][j]=holder[i][j-1];
        }
    }
}
    /*Print
     for(i=0;i<en;i++)
     std::cout<<holder[i];
     std::cout<<std::endl;
     *///
    int k=holder[en][en];
    int size=k+1;
    int tantra[size];
    i=en,j=en;
    while(i>0&&j>0)
{
    if(rows[i-1]==cols[j-1])
    {
        tantra[k-1]=rows[i-1];
        i--;
        j--;
        k--;
    }
        else if (holder[i-1][j]>holder[i][j-1])
        i--;
    else
        j--;
    }
for(i=0;i<size-1;i++)
    std::cout<<tantra[i]<<" ";
}




int main()
{
    std::string hint, input;
    int en,i,j,k,l;
    std::cin>>hint;
    std::cin>>en;
    int rows[en],cols[en];
    char colera[en*en];
    
    for(i=0;i<en;i++)
    {
        std::cin>>input;
        rows[i]=kmp(hint,input);
        
        k=i;
        for(j=0;j<en;j++)
        {
            colera[k]=input[j];
            k=k+en;
        }
     
    }//2n^2
    
    std::string strung(colera);
    l=0;
    
    for(i=0;i<en;i++)
    {
        cols[i]=kmp(hint,strung.substr(l,en));
        l=l+en;
    }//2n^2+n^2=3n^2

    /*Print
     for(i=0;i<en;i++)
     std::cout<<rows[i];
     std::cout<<std::endl;
     for(i=0;i<en;i++)
     std::cout<<cols[i];
     std::cout<<std::endl;
     
     *///Combination found
    longest(rows,cols,en);
    
    

  
    
        return 0;
    
}
