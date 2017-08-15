#include<stdio.h>
int main(int argc,char*argv[]){
    int num,N4=0,N=0,flag=1;
    int A[5] = {0,0,0,0,0};
    bool bit[5]={false,false,false,false,false};
    scanf("%d",&N);
    while(N--){
        scanf("%d",&num);
        switch(num%5){
            case 0:{
                if(num%2==0)
                {
                    bit[0] = true;
                    A[0]+=num;
                }
               
                break;
            };
            case 1:{
                bit[1] = true;
                A[1]+=flag*num;
                flag = -flag;
                break;
            };
            case 2:{
                bit[2] = true;
                A[2]++;
                break;
            };
            case 3:{
                bit[3] = true;
                A[3]+=num;
                N4++;
                break;
            };
            case 4:{
                bit[4] = true;
                if(num>A[4])A[4]=num;
                break;
            };
            default:break;
        }
    }
    if(bit[0])printf("%d ",A[0]);
    else printf("N ");
    if(bit[1])printf("%d ",A[1]);
    else printf("N ");
    if(bit[2])printf("%d ",A[2]);
    else printf("N ");
    if(bit[3])printf("%.1f ",(float)A[3]/N4);
    else printf("N ");
    if(bit[4])printf("%d",A[4]);
    else printf("N");
}