#include<iostream>
#include<stdio.h>
#include<map>
#include<stdlib.h>
using namespace std;

main()
{
    int n,q;
    int st,pr,am;
    int addr;
    map <int,int> price; 
    map <int,int> amt;
    scanf("%d",&n);
    scanf("%d", &q);
    for(int i=0;i<n;i++){
        scanf("%d", &st);
        scanf("%d", &pr);
        scanf("%d", &am);
        price.insert(pair <int,int>(st,pr));
        amt.insert(pair <int,int>(st,am));
    }
    int min = 99999999;
    int pos = -7;
    for(int i=0;i<q;i++){
        scanf("%d",&addr);
        for(int i=-5; i<=5; i++){
            if(price.find(addr+i)->second < min && amt.find(addr+i)->second != 0 && price.count(addr+i)){
                min = price.find(addr+i)->second;
                pos = i;
            }
        }
        if(pos!=-7){
            (amt.find(addr+pos)->second)--;
        }
        if (min == 99999999){
            min = 0;
        }
        //printf("---ANS---> ");
        printf("%d\n",min);
        min = 99999999;
        pos = -1;
    }
}
