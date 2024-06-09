#include <stdio.h>

struct estrutura{
    char jogo[50];
    char produtora[50];
    int quantidade;
    float preco;
};


int f1(FILE *p, struct estrutura cadastro); //protótipos
int f2(FILE *p, struct estrutura cadastro);
int f3(FILE *p, struct estrutura cadastro);
int f4(FILE *p, struct estrutura cadastro);
int f5(FILE *p, struct estrutura cadastro);
int f6(FILE *p, struct estrutura cadastro);
int f7(FILE *p, struct estrutura cadastro);
int f8(FILE *p, struct estrutura cadastro);
int f9(FILE *p, struct estrutura cadastro);
int f10(FILE *p, struct estrutura cadastro);

int main(){
struct estrutura cadastro;
FILE *p;
if((p = fopen("desafio2doAndre.txt","ab"))==NULL)//só pra garantir que vai criar um txt logo no início, caso ainda não exista.
    {
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
fclose(p);

int option = 0;

do{
printf("\n\nEscolha a opcao desejada\n -   -   -   -   -   -   -   -   -  -   -   -   -   -   -   -   -   -  -\n\n");
printf("\n - - - - - - M E N U - - - - - -");
printf("\n   1 - Entrada de dados.");
printf("\n   2 - Lista todos os dados na tela.");
printf("\n   3 - Pesquisar um jogo pelo nome completo e mostra na tela.");
printf("\n   4 - Pesquisar produtora pelo nome completo");
printf("\n   5 - Pesquisa jogo por faixa de preco.");
printf("\n   6 - Altera quantidade (entrada e saida) pesquisado pelo nome completo.");
printf("\n   7 - Altera preco de um jogo pesquisado pelo nome completo");
printf("\n   8 - Altera dados. Pesquisa pelo nome completo.");
printf("\n   9 - Exclui dados. Pesquisa pelo nome completo.");
printf("\n  10 - Saida pelo usuario");

printf("\n\n Sua opcao = ");
scanf("%d",&option);

switch(option){

case 1://   1 – Entrada de dados.
    f1(p, cadastro);
    break;

case 2://   2 – Lista todos os dados na tela.
    f2(p, cadastro);
    break;

case 3://   3 – Pesquisar um jogo pelo nome completo e mostra na tela.
    f3(p, cadastro);
    break;

case 4://   4 – Pesquisar produtora pelo nome completo
    f4(p, cadastro);
    break;

case 5://   5 – Pesquisa jogo por faixa de preço.
    f5(p, cadastro);
    break;

case 6://   6 – Altera quantidade (entrada e saída) pesquisado pelo nome completo.
    f6(p, cadastro);
    break;

case 7://   7 – Altera preço de um jogo pesquisado pelo nome completo
    f7(p, cadastro);
    break;

case 8://   8 – Altera dados. Pesquisa pelo nome completo.
    f8(p, cadastro);
    break;

case 9://   9 – Exclui dados. Pesquisa pelo nome completo.
    f9(p, cadastro);
    break;

case 10://   10 – Saída pelo usuário
    f10(p, cadastro);
    break;

}

}while(option!=10);
}


int f1(FILE *p, struct estrutura cadastro){
    printf("\n INCLUIR JOGOS\n\n");
    char pergunta;
    int contagem = 0;
    if((p = fopen("desafio2doAndre.txt","ab+"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    getchar();
    do{
        fseek(p, 0, SEEK_END);//só pra garantir que o ponteiro estará lá. Teoricamente nao precisa pois append poe ponteiro no fim
        contagem = (ftell(p) / sizeof(cadastro));
        printf("\nAtualmente a lista de jogos contem %d jogos. \n",contagem);

        printf("\nVERIFICACAO Este eh o jogo numero %d da lista. ",contagem+1);
        /*  char jogo[50];
            char produtora[50];
            int quantidade;
            float preco;    */
        printf("\nDigite o nome do jogo = ");
        scanf("%49[^\n]", cadastro.jogo); getchar();
        printf("\nVERIFICACAO Voce digitou produto.nome = %s",cadastro.jogo);
        printf("\nInsira o nome da produtora = ");
        scanf("%49[^\n]", cadastro.produtora); getchar;
        printf("\nVERIFICACAO Voce digitou cadastro.produtora = %s",cadastro.produtora);
        printf("\nInsira a quantidade deste jogo = ");
        scanf("%d", &cadastro.quantidade);
        printf("\nInsira o preco unitario deste jogo = ");
        scanf("%f", &cadastro.preco);

        printf("\nVoce digitou: JOGO = %s PRODUTORA = %s QUANTIDADE = %d PRECO = %.2f",cadastro.jogo, cadastro.produtora, cadastro.quantidade, cadastro.preco);

        printf("\n\n - - - - - - - - - \n\n");
        getchar();
        fwrite(&cadastro, sizeof(cadastro), 1, p);//sempre será no fim pois o arquivo foi aberto em append


        printf("\n\nDeseja cadastrar mais produtos? S/N = ");
        //pergunta = getchar();
        scanf(" %c",&pergunta);
        getchar();
        printf("\n--==-- voce respondeu PERGUNTA = %c\n",pergunta);
        if(pergunta == 'n' || pergunta == 'N'){

            break;
        }
    }while(1);
    fclose(p);//fecha o arquivo se não quiser mais cadastrar produtos.
    contagem = 0;
return(0);
}

int f2(FILE *p, struct estrutura cadastro){
    //system("cls");
    if((p = fopen("desafio2doAndre.txt","r"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET);
    printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco");
    int contagem = (ftell(p) / sizeof(cadastro));

    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1){
        if(cadastro.jogo[0] != '\0'){
            printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);
        }
    }
fclose(p);
printf("\n\n = = = = = = = = = = = = = = = = = = = =\n\n");
return(0);
}

int f3(FILE *p, struct estrutura cadastro){ // 3 - Pesquisar um jogo pelo nome completo e mostra na tela.
    //system("cls");
    //getchar();
    long int otamanho;
    otamanho = sizeof(cadastro);//ftell(p)
    printf("\nO Tamanho eh de %ld bytes",otamanho);
    if((p = fopen("desafio2doAndre.txt","r"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    char busca[50];
    printf("\nDigite o nome completo do JOGO que deseja buscar = ");
    scanf("%[^\n]",&busca);
    getchar();
    int flag = 0;
    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {

        for(int i=0; i<50; i++){
            if(busca[i] != cadastro.jogo[i]){//é diferente, sái do loop for
                //flag = 0;
                break;
            }else if(busca[i] == cadastro.jogo[i] && busca[i] == '\0'){
                flag = 1;
                printf("\nJOGO ENCONTRADO!\n");
                printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);
                printf("\nPressione ENTER para continuar.\n");
                getchar();
                break;
            }

        }
        //fseek(p, sizeof(produto),SEEK_CUR);
    }
    if(flag == 0){
        printf("\n JOGO nao encontrado. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);
    return(0);
}

int f4(FILE *p, struct estrutura cadastro){//   4 – Pesquisar produtora pelo nome completo
    system("cls");
    getchar();
    if((p = fopen("desafio2doAndre.txt","r"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    char busca[50];
    printf("\nDigite o nome completo da PRODUTORA que deseja buscar = ");
    scanf("%[^\n]",&busca);
    getchar();
    int flag = 2;

    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {

        for(int i=0; i<50; i++){
            if(busca[i] != cadastro.produtora[i]){
                //flag = 0;
                //é diferente, sái do loop for
                break;
            }else if(busca[i] == cadastro.produtora[i] && busca[i] == '\0'){
                flag = 1;
                printf("\nPRODUTORA ENCONTRADA!\n");
                printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
                printf("%\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);
                printf("\nPressione ENTER para continuar.\n");
                getchar();
                break;
            }

        }
        //fseek(p, sizeof(produto),SEEK_CUR);
    }
    if(flag == 0){
        printf("\n PRODUTORA nao encontrada. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);
    return(0);
}

int f5(FILE *p, struct estrutura cadastro){ //   5 – Pesquisa jogo por faixa de preço.
    system("cls");
    getchar();
    if((p = fopen("desafio2doAndre.txt","r"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    float precoMIN, precoMAX;
    printf("\nDigite o preco MINIMO que deseja buscar = ");
    scanf("%f",&precoMIN);
    printf("\nDigite o preco MAXIMO que deseja buscar = ");
    scanf("%f",&precoMAX);

    int flag = 2;
    printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {

        if(cadastro.preco < precoMIN || cadastro.preco > precoMAX){
            //flag = 0;
        }else if(precoMIN <= cadastro.preco && cadastro.preco <= precoMAX){
            flag = 1;
            printf("%\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);
        }
    }

    if(flag == 0){
        printf("\n Nao foram encontrados jogos nessa faixa de preco. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);
    return(0);
}

int f6(FILE *p, struct estrutura cadastro){ //  6 - Altera quantidade (entrada e saida) pesquisado pelo nome completo.
    //system("cls");//eliminei esta linha por questões de portabilidade do código
    getchar();
    if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    char busca[50];
    printf("\nDigite o nome completo do JOGO que deseja buscar para alterar a quantidade do estoque = ");
    scanf("%[^\n]",&busca);
    getchar();
    int flag = 0;
    int contagem = 0;
    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {//cada iteração avança um bloco de estrutura no arquivo
    contagem = contagem + sizeof(cadastro);//garante saber a posição do ponteiro dentro do arquivo
    printf("\n-=-=-CONTAGEM = %d",contagem);
        for(int i=0; i<50; i++){
            if(busca[i] != cadastro.jogo[i]){//é diferente, sái do loop for
                //flag = 0;
                break;
            }else if(busca[i] == cadastro.jogo[i] && busca[i] == '\0'){//todos índices do array são iguais, inclusive o terminador \0
                flag = 1;//para indicar que já foi achado. A flag servirá para dar break onde necessário.
                printf("\nJOGO ENCONTRADO!\n");
                fclose(p);
                printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);

                printf("\n\n Deseja adicionar ou remover a quantidade? \nDigite 1 para adicionar e 2 para remover\n");
                int escolha, quantidade;

                do{
                    scanf("%d",&escolha);
                    if(escolha ==1){//AUMENTAR QUANTIDADE
                        do{
                            printf("\nQual a quantidade que voce deseja aumentar? = ");
                            scanf("%d",&quantidade);
                            if(quantidade < 0 ){
                                printf("\nQuantidade negativa! Digite um numero positivo");
                            }else{
                                cadastro.quantidade += quantidade;
                                if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
                                {
                                    printf("erro na abertura do arquivo \n");
                                    exit(0);
                                }
                                fseek(p, contagem - sizeof(cadastro),SEEK_CUR);
                                fwrite(&cadastro, sizeof(cadastro), 1, p);//sobrescreve o registro do jogo que teve quantidade modificada
                                fclose(p);
                                printf("\nQuantidade alterada.\n");
                                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);

                                flag = 1;
                                break;
                            }
                        }while(quantidade <0);


                    }else if(escolha ==2){//DIMINUIR QUANTIDADE
                        do{
                            printf("\nQual a quantidade que voce deseja diminuir? = ");
                            scanf("%d",&quantidade);
                            if(quantidade < 0 ){
                                printf("\nQuantidade negativa! Digite um numero positivo");
                            }else if(quantidade > cadastro.quantidade){
                                printf("\nEstoque insuficiente. A quantidade atual e de %d . Tente novamente.\n", cadastro.quantidade);
                            }else{
                                cadastro.quantidade = cadastro.quantidade - quantidade;
                                if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
                                {
                                    printf("erro na abertura do arquivo \n");
                                    exit(0);
                                }
                                fseek(p, contagem - sizeof(cadastro),SEEK_CUR);
                                fwrite(&cadastro, sizeof(cadastro), 1, p);//sobrescreve o registro do jogo que teve quantidade modificada
                                fclose(p);
                                printf("\nQuantidade alterada.\n");
                                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);
                                //printf("\nPrecione ENTER para continuar.\n");
                                //getchar();
                            }
                        }while(quantidade <0);
                    }else{
                        printf("\nOPCAO INVALIDA! Digite 1 pra aumentar ou 2 para diminuir a quantidade");
                    }
                    if(flag == 1){
                        break;
                    }
                }while(escolha != 1 && escolha != 2);

                printf("\nPressione ENTER para continuar.\n");
                getchar();
                if(flag == 1){
                        break;
                    }
                break;
            }//fim do if "JOGO ENCONTRADO" na parte de busca
            if(flag == 1){
                break;
            }
        }//fim do loop for que itera 50 vezes o array de caracteres
        if(flag == 1){
                break;
        }
    }
    if(flag == 0){
        printf("\n JOGO nao encontrado. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);
    return(0);
}

int f7(FILE *p, struct estrutura cadastro){//   7 - Altera preco de um jogo pesquisado pelo nome completo
    getchar();
    if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    char busca[50];
    printf("\nDigite o nome completo do JOGO que deseja buscar para alterar o preco = ");
    scanf("%[^\n]",&busca);
    getchar();
    int flag = 0;
    int contagem = 0;
    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {//cada iteração avança um bloco de estrutura no arquivo
    contagem = contagem + sizeof(cadastro);//garante saber a posição do ponteiro dentro do arquivo
    printf("\n-=-=-CONTAGEM = %d",contagem);
        for(int i=0; i<50; i++){
            if(busca[i] != cadastro.jogo[i]){//é diferente, sái do loop for
                //flag = 0;
                break;
            }else if(busca[i] == cadastro.jogo[i] && busca[i] == '\0'){//todos índices do array são iguais, inclusive o terminador \0
                flag = 1;//para indicar que já foi achado. A flag servirá para dar break onde necessário.
                printf("\nJOGO ENCONTRADO!\n");
                fclose(p);//operacao de leitura concluida. A próxima abertura será exclusiva para escrita no modo r+
                printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);

                int quantidade;
                do{
                    printf("\nQual e o novo preco deste jogo? = ");
                    scanf("%f",&cadastro.preco);
                    if(cadastro.preco < 0 ){
                        printf("\n Preco negativo! Digite um numero positivo");
                    }else{
                        flag = 1;
                        if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
                        {
                            printf("erro na abertura do arquivo \n");
                            exit(0);
                        }
                        fseek(p, contagem - sizeof(cadastro),SEEK_CUR);
                        fwrite(&cadastro, sizeof(cadastro), 1, p);//sobrescreve o registro do jogo que teve quantidade modificada
                        fclose(p);
                        printf("\n Preco alterado.\n");
                        printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);

                        flag = 1;
                        break;
                    }
                }while(cadastro.preco <0);

                if(flag == 1){
                    break;
                }
                printf("\nPressione ENTER para continuar.\n");
                getchar();
                if(flag == 1){
                    break;
                }
                break;
            }//fim do if "JOGO ENCONTRADO" na parte de busca
            if(flag == 1){
                break;
            }
        }//fim do loop for que itera 50 vezes o array de caracteres
        if(flag == 1){
                break;
        }
    }//fim do while que "puxa" bloco por bloco de estrutura lá do arquivo.
    if(flag == 0){
        printf("\n JOGO nao encontrado. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);

    return(0);
}

int f8(FILE *p, struct estrutura cadastro){
return(0);
}

int f9(FILE *p, struct estrutura cadastro){//9 - Exclui dados. Pesquisa pelo nome completo.
    system("cls");
    getchar();
    if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
    {
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    fseek(p, 0, SEEK_SET); //abriu o arquivo acima e aqui setou o ponteiro pro começo do arquivo, 0 ou SEEK_SET
    char busca[50];
    printf("\nDigite o nome completo do JOGO que deseja DELETAR = ");
    scanf("%[^\n]",&busca);
    getchar();
    int flag = 0;
    long int contagem = 0;
    while (fread(&cadastro, sizeof(cadastro), 1, p) == 1) {//lê o arquivo txt e joga na memória, usando a estrutura cadastro
    contagem = contagem + sizeof(cadastro);//garante saber a posição do ponteiro dentro do arquivo
    printf("\n-=-=-CONTAGEM = %ld",contagem);
        for(int i=0; i<50; i++){
            if(busca[i] != cadastro.jogo[i]){//é diferente, sái do loop for
                //flag = 0;
                break;
            }else if(busca[i] == cadastro.jogo[i] && busca[i] == '\0'){//todos índices do array são iguais, inclusive o terminador \0
                flag = 1;//para indicar que já foi achado. A flag servirá para dar break onde necessário.
                printf("\nJOGO ENCONTRADO!\n");
                fclose(p);
                printf("\nNOME --------------------------  Produtora --------------------- Quantidade --- Preco\n");
                printf("\n%-30s   %-30s  %-12d   %.2f",cadastro.jogo,cadastro.produtora,cadastro.quantidade,cadastro.preco);

                printf("\n\n Tem certeza que deseja deletar este jogo? \nDigite 1 para SIM e 2 para NAO\n");
                int escolha, quantidade;

                do{
                    scanf("%d",&escolha);
                    if(escolha ==1){//DELETAR
                        cadastro.jogo[0] = '\0';
                        cadastro.produtora[0] = '\0';
                        cadastro.quantidade = -1;
                        cadastro.preco = -1;
                        if((p = fopen("desafio2doAndre.txt","r+"))==NULL)
                        {
                            printf("erro na abertura do arquivo \n");
                            exit(0);
                        }
                        fseek(p, contagem - sizeof(cadastro),SEEK_SET);
                        fwrite(&cadastro, sizeof(cadastro), 1, p);
                        fclose(p);
                        printf("\nRegistro deletado! \n Precione ENTER para continuar.\n");
                        flag = 1;
                        break;


                    }else if(escolha ==2){//NAO DELETAR || MANTER
                        printf("\n Voce optou por nao deletar o registro do jogo");
                    }else{
                        printf("\nOPCAO INVALIDA! Digite 1 pra aumentar ou 2 para diminuir a quantidade");
                    }
                    if(flag == 1){
                        break;
                    }
                }while(escolha != 1 && escolha != 2);

                printf("\nPressione ENTER para continuar.\n");
                getchar();
                if(flag == 1){
                        break;
                }
                break;
            }//fim do if "JOGO ENCONTRADO" na parte de busca
            if(flag == 1){
                break;
            }
        }//fim do loop for que itera 50 vezes o array de caracteres
        if(flag == 1){
            break;
        }
        //fseek(p, sizeof(cadastro),SEEK_CUR);//deixei comentado pois foi um teste que acabou não precisando ser implementado
    }//fim do while que lê blocos de memória do arquivo
    if(flag == 0){
        printf("\n JOGO nao encontrado. Pressione ENTER para continuar.\n");
        getchar();
    }
    fclose(p);
    return(0);
}

int f10(FILE *p, struct estrutura cadastro){
    printf("\n\n - - - FIM DO PROGRAMA - - - \n\n");
    exit(0);
    return(0);
}
