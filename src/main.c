#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define nao_primo 0
#define primo 1

int verifica_primo(int numero){

	int i = 3, flag = 1;

	if(numero == 1 || numero == 0){
		return nao_primo;
	}else if(numero%2 == 0 && numero != 2){
			return nao_primo;
		}else{
			for(i; ((i <= numero/2) && (flag != 0)); i += 2){
				flag = numero%i;
			}
			if(flag == 0){
				return nao_primo;
			}else{
				return primo;
			}
		}

}

int main() {

	int  auxiliar = 0, flag_fim = 0;

  	FILE *pipe;

  	if ((pipe = popen("sort -r -n", "w")) == NULL){
    	perror("popen");
    	exit(1);
    }

	scanf("%d", &auxiliar);

	while (auxiliar != -1){
		if(verifica_primo(auxiliar) == nao_primo){
			fprintf(pipe, "%d\n", auxiliar);
	  	}
		scanf("%d", &auxiliar);
	}

	pclose(pipe);
	
	return 0;
}