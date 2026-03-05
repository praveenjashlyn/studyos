#include <stdio.h>

int main(){
    int bt[20],wt[20],tt[20],p[20];
    int i,j,n,temp;

    printf("Enter number of processes : ");
    scanf("%d",&n);
    printf("Enter burst time : ");
    for(i=0;i<n;i++)
    {    scanf("%d",&bt[i]);
         p[i]=i;
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)  
            if(bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
    wt[0]=0;
    tt[0]=wt[0]+ bt[0];
    for(i=1;i<n;i++){
        
        wt[i]=wt[i-1]+bt[i-1];
        tt[i]=wt[i]+bt[i];
      
    }
    printf("P | wt | tt \n");
    for(i=0;i<n;i++){
        printf("%d  %d  %d \n",p[i],wt[i],tt[i]);
    }
}
