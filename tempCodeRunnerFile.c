#include<stdio.h>

void AssTim(int n,int e1,int e2,int s[2][n],int t[2][n-1],int x1,int x2)
{
    int f0[n],f1[n];
    f0[0]=e1+s[0][0];
    f1[0]=e2+s[1][0];

    for(int j=1;j<n;j++){

        if(f0[j-1] + s[0][j] <= f1[j-1] + t[1][j-1] + s[0][j])
            f0[j] = f0[j-1] + s[0][j];
        else 
            f0[j] = f1[j-1] + t[1][j-1] + s[0][j];

        if(f1[j-1] + s[1][j] <= f0[j-1] + t[0][j-1] + s[1][j])
            f1[j] = f1[j-1] + s[1][j];
        else   
            f1[j] = f0[j-1] + t[0][j-1] + s[1][j];

        
    }
    printf("%d\n",f0[n-1]);
    printf("%d\n",f1[n-1]);
}

int main(){
    int s[2][5]={{7,9,3,4,8},{8,5,6,4,5}};
    int t[2][4]={{2,3,1,3},{2,1,2,2}};

    AssTim(5,2,4,s,t,3,6);

    return 0;
}