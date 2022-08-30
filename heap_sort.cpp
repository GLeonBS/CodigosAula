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

void troca(int *vetor, int inicio, int fim){
	int aux;
	aux = vetor[inicio];
	vetor[inicio]= vetor[fim];
	vetor[fim]= aux;
}

void fila_prioridade (int *x,int i, int qtde){
	int fila_esquerda, fila_direita, maior, aux;
	maior = i;
	
	if(2*i+1 <= qtde){
		fila_esquerda=2*i+1;
		fila_direita = 2*i;
		
		if(x[fila_esquerda] >= x[fila_direita] && x[fila_esquerda] > x[i]){
			maior = 2*i+1;
			
	    }else if (x[fila_direita] > x[fila_esquerda] && x[fila_direita] > x[i]){
	    	maior = 2*i;
			
		}else if(2*i <= qtde){
			fila_direita=2*i;
			
			if(x[fila_direita] > x[i]){
				maior=2*1;
			}
		}
		if (maior != i){
			troca(x,i,maior);
			fila_prioridade(x,maior,qtde);
		}
	}
}

void transforma_heap(int *x, int qtde){
	int i;
	for (i=qtde/2; i>=1;i--){
		fila_prioridade(x+i,i, qtde);
	}
}

void heapsort(int *x,int qtde){
	int i, ultima_pos, aux;
	for(i=qtde; i>=2; i--){
		troca(x,1,i);
		fila_prioridade(x+i,1, ultima_pos);
	}
}



int particao(int *vetor, int inicio, int fim){
	int pivo, indiceIni, indiceFim;
	pivo = vetor[(inicio+fim)/2];
	indiceIni=inicio-1;
	indiceFim=fim +1;
	
	while(indiceIni<indiceFim){
		do {
			indiceFim--;
		}while(vetor[indiceFim] > pivo);
		
		do{
			indiceIni++;
		}while(vetor[indiceIni] < pivo);
				
		if(indiceIni < indiceFim){
			troca(vetor,indiceIni,indiceFim);
		}
		return indiceFim;
	}	
}



int main(void){
	int x[5];
	int tam = sizeof(x)/sizeof(int);
	
	entrada(x, tam);
	imprimir(x,tam);
	transforma_heap(x,tam);
	heapsort(x,tam);
	imprimir(x,tam);
}