#include  <stdio.h>
int cont=0;
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
	printf("as alteracoes foram: %d ", cont);
}

int main(void){
	int x[10], i, j, eleito, menor, pos;
	
	
	int tam = sizeof(x)/sizeof(int);
	entrada(x, tam);
	imprimir(x,tam);
	// neste ponto está ocorrendo  selection sort
	// abre o for
	for(i=0; i<9; i++){
		//variável eleito recebe a posicao do for
		eleito = x[i];
		// variável menor recebe proxima posicao do for
		menor = x[i+1];
		// variavel guarda qual a posicao do for
		// por exemplo no for ele está primeira iteracao do for ou na segunda?
		// esta váriavel é responsável por armazenar a posição do laco
		pos = i+1;
		
		// abre o segundo for
		for( j=i+2; j< 10; j++){
			// se posicao do segundo for, for menor que váriavel menor do laco acima
			// ele subustituirá a váriavel menor com posição do segundo for
			if (x[j] < menor){
				// variavel menor então recebe a posição do segundo for
				menor = x[j];
				// esta váriavel é responsável por armazenar a posição do laco
				pos = j;
			}
			cont++;
			
		}
		if (menor < eleito){
			x[i] = x[pos];
			x[pos]= eleito;
			
		}
		
    } 	
	imprimir(x,tam);
}