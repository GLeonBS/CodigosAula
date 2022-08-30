#include  <stdio.h>
int cont =0;
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
	printf("alteracoes foram: %d ",cont);
}

void intercala(int x[], int inicio, int fim, int meio){
	int poslivre, inicio_vetor1, inicio_vetor2, indice;
	int aux[6];
	inicio_vetor1= inicio;
	inicio_vetor2=meio+1;
	poslivre=inicio;
	
	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim){
		if (x[inicio_vetor1] <= x[inicio_vetor2]){
			aux[poslivre] = x[inicio_vetor1];
			inicio_vetor1 = inicio_vetor1 + 1;
		
		} else{
			aux[poslivre]= x[inicio_vetor2];
			inicio_vetor2 = inicio_vetor2 + 1;
		}
		poslivre++;				
	}
	for (indice = inicio_vetor1; indice<= meio ; indice++){
		aux[poslivre]= x[indice];
		poslivre++;
	}
	
	for (indice=inicio_vetor2; indice<=fim; indice++){
		aux[poslivre] = x[indice];
		poslivre++;
	}
	
	for (indice=inicio; indice<=fim ; indice++){
		x[indice]= aux[indice];
		cont++;	
	}	
}


void merge(int x[], int inicio, int fim ){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		merge(x, inicio, meio);
		merge(x, meio+1, fim);
		intercala(x, inicio, fim, meio);
	}
	
}
int main(void){
	int x[6];
	int tam = sizeof(x)/sizeof(int);
	
	entrada(x, tam);
	imprimir(x,tam);
	merge(x,0, 5);
	imprimir(x,tam);
}