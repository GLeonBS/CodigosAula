#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int cont =0;

void entrada(int *vet, int tam){
	for(int i = 0; i < tam; i++){
		printf("Digite o numero %d: \n ",i+1);
		scanf("%d",&(*(vet+i)));
	}	
}

void imprimir(int  *vet,int tam){

    printf("[ "); 
	for(int i =0; i < tam; i++){
		printf("%d ",*(vet+i));		
	}
	printf("]\n");
	printf("\n as alteracoes foram: %d \n",cont);
	
}

void ordenacao(int *x, int tam){

	int aux;
	for(int n=1; n<=tam; n++){
	
		for(int i=0; i<=8; i++){
			if(x[i]>x[i+1]){
				aux= x[i];
				x[i] = x[i+1];
				x[i+1]= aux;
		
		}
		cont++;	
	}	
}
}

void decrescente(int *x,int tam){
	int aux;
	for(int i= tam; i>0; i--){
		for(int d=9; d>0; d--){
			if(x[d]>x[d-1]){
				aux= x[d];
				x[d]= x[d-1];
				x[d-1]= aux;
			}
		cont++;
		}
	}
}


int main(void){
	
	int vet[10];
	int tam = sizeof (vet)/ sizeof(int);
	
	entrada(vet,tam);
	imprimir(vet,tam);
	ordenacao(vet,tam);
	imprimir(vet,tam);
}
