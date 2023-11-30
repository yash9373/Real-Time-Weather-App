#include<stdio.h>
int N,ack,flag=0;

void reTransmit(int x[],int cnt){
	int xcnt =0,x_x[cnt];
	for(int i=0;i<cnt;i++){
		printf("\nretransmitting frame %d...",x[i]);
		printf("\n Send Ack (1/-1) : ");
		scanf("%d",&ack);
		if(ack<0){
			x_x[xcnt] = x[i];
			xcnt++;
		}
	}
	if(xcnt!=0){
		printf("\n--------------");
		reTransmit(x_x,xcnt);
	}else{
		printf("\nTransmission Successful");
	}
}

int main(){
	printf("\nEnter Number Of Frames: ");
	scanf("%d",&N);
	int x[N],cnt=0;
	for(int i=0;i<N;i++){
		printf("\nSending Frame %d... ",i);
		printf("\n Send Ack (1/-1) : ");
		scanf("%d",&ack);
		if(ack<0){
			x[cnt]= i;
			cnt++;
		} 
	}
	if(cnt !=0){
		reTransmit(x,cnt);
	}else{
	printf("\nTransmission Successful");
	}
	return 0;
}   