#include <stdio.h>
int main(void){
int cont=0;
int x[5],n,i,aux;
for(i=0; i<=9; i++){
	printf("digite o %d numero: ",i+1);
	scanf("%d",&x[i]);
}
for(n=1; n<=9; n++){
	
	for(i=0; i<=3; i++){
		if(x[i]>x[i+1]){
			aux= x[i];
			x[i] = x[i+1];
			x[i+1]= aux;
		
		}
		cont++;	
	}
	
}
for(i=0; i <=9; i++){
	printf( " [ " );
	for(i=0; i<10; i++){
		printf("%d",x[i]);
		printf(" ] " );
	
	}
		printf("\n as alteracoes foram: %d \n",cont);
}
}
