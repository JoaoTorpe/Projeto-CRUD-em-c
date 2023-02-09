#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define max_registros  100

int tela ()
{
    int opicao;
    printf ("--- Menu de Opcoes ---");
    printf ("\n1 - Criar: ");
    printf ("\n2 - Mostrar: ");
    printf ("\n3 - Atualizar: ");    
    printf ("\n5 - Sair: ------>>>> : ");
    scanf ("%d", &opicao);
    return opicao;
}
void sair ()
{
    printf ("Programa encerrado com sucesso."); 
}

typedef struct  {
    char nome[10];
    double salario;
    int idade;
}funcionario;

int criar(int);
int mostrar(int);

int atualizar(int);

int main()
{    
    int id = -1;

    setlocale(LC_ALL,"potuguese");
    int op;
    op = tela();
    
    if(op == 5){
        sair();
    }
    else{
   do {
    switch (op)
    {
        case 1:{
			
        system("cls");
        id++;
        int i = id;
        op = criar(id);
          break;
          	}
        case 2:{
			
	
        system("cls");
         op = mostrar(id);
          break;
          	}
        case 3:{
		
         op = atualizar(id);
          break;
      }
        
        default:
        system("cls");
         printf ("opcao invalida\n");
        op = tela();
        break;
         }}while(op !=5);
         system("cls");
    sair();
    }
    
    return 0;
}

int criar(int id){
    funcionario func[max_registros];
   
   FILE *arquivo;
   arquivo = fopen("lista.txt","a");
   if(arquivo == NULL){
       printf("problemas para abrir o arquivo ?(`?')?  \n");
       
   }

   
 
     printf(" ID: %d\n",id);
    printf("\nRegistro do funcionario:\n");
    printf("Nome:\n");
    scanf("%9s",func[id].nome);
    
    
    printf("salario: \n");
    scanf("%lf",&func[id].salario);
    
  
    printf("idade: \n");
    scanf("%d",&func[id].idade);
     printf("\n");
 
    
    fwrite(&func,sizeof( funcionario),1,arquivo);
   
   fclose(arquivo);
   system("cls");
return tela();
  
   
}
   
  int mostrar(int id){
        funcionario func[max_registros];
       FILE *arquivo;
   arquivo = fopen("lista.txt","r");
   
   if(arquivo == NULL){
       printf("Arquivo removido. \n");
       
   }
   else{
       

    int i;
   if(fread(func, sizeof(funcionario),1,arquivo)== 1){

   for(i=0;i<=id;i++){
       printf("Id: Nº %d",i);
   printf("\nNome:%s\n",func[i].nome);
   printf("Salario:R$%.2lf\n",func[i].salario);
   printf("Idade:%d Anos\n",func[i].idade);
   printf("------------------------------\n");
   	}
}
   
   fclose(arquivo);
       
}
    return tela();  
   } 
   
   
   int atualizar(int id){
       
       funcionario func[max_registros];
        printf("\n Atualizar registro do funcionario:\n");
    
     //Escolha
    int option;
    printf("Selecione um ID pra alterar:\n");
    scanf("%d",&option);
       
       FILE *arquivo;
   arquivo = fopen("lista.txt","w");
   if(arquivo == NULL){
       printf("problemas para abrir o arquivo   :(\n");
       }
    else{
	
  printf("Nome:\n");
    scanf("%9s",func[option].nome);
    
    
    printf("salario: \n");
    scanf("%lf",&func[option].salario);
    
  
    printf("idade: \n");
    scanf("%d",&func[option].idade);
     printf("\n");
     
  fwrite(&func,sizeof( funcionario),1,arquivo);
  
   fclose(arquivo);
   return tela();
}
   }
   






