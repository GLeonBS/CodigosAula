#include  <stdio.h>

void entrada (int *vet,int n){
	for(int i =0; i<n; i++){
		 printf("digite o %d numero: \n ", i+1);
		 scanf("%d",&(*(vet+i)));
	}
}

void imprimir (int *vet, int n ){
	printf("[ "); 
	for(int i =0; i < n; i++){
		printf("%d ",*(vet+i));		
	}
	printf("]\n");
}

int particao(int *vetor, int inicio, int fim){
	int pivo, indiceIni, indiceFim;
	pivo = vetor[(inicio+fim)/2];
	indiceIni=inicio-1;
	indiceFim=fim +1;
	int aux;	
	while(indiceIni<indiceFim){
		do {
			indiceFim--;
		}while(vetor[indiceFim] > pivo);
		
		do{
			indiceIni++;
		}while(vetor[indiceIni] < pivo);
				
		if(indiceIni < indiceFim){		
				
			aux = vetor[indiceIni];
			vetor[indiceIni]= vetor[indiceFim];
			vetor[indiceFim]= aux;			
		}
		return indiceFim;
	}	
}

void quicksort(int vetor[], int inicio, int fim){
	int q;
	if(inicio < fim ){
		q = particao(vetor, inicio, fim);
		quicksort(vetor,inicio,q);
		quicksort(vetor, q+1, fim);
	}
}

int main(void){
	int x[5];
	int tam = sizeof(x)/sizeof(int);
	
	entrada(x, tam);
	imprimir(x,tam);
	quicksort(x,0, tam-1);
	imprimir(x,tam);
}
