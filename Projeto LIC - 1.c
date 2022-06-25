//Integrantes do Grupo: Jefferson da Silva de Souza, João Augusto Carrascoza e Pedro França de Godoi
//Esse código é referente a entrega da primeira semana: REQ1, REQ2, REQ3
//Segue abaixo o código dos requisitos acima
//Data: 13/06/2022

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define andar 21
#define ap 15

int main(){

    //Matriz criada com a finalidade de ser o MENU do Hotel
    char MatrizMenu[8][45] = {{"(1) - Check-in de hospede"}, {"(2) - Check-out de hospede"}, {"(3) - Reservar apartamento"},
    {"(4) - Cancelar reserva"}, {"(5) - Mapa de ocupacao e reservas de hotel"},{"(6) - Informacoes do hospede"},
    {"(7) - Taxas de ocupacao e reservas do hotel"},{"(8) - Sair do programa"}};

    int j, k, i, g;

    //Matriz criada com a finalidade de criar a matriz de Andares e Apartamentos
    char matriz[andar][ap];

    //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
    int mapa(char matriz[andar][ap]);

    //Chamei a Função  CheckIn para auxiliar o usuário na tomada de decisão
    int CheckIn(char matriz[andar][ap]);

    //Chamei a Função Reserva para auxiliar o usuário na tomada de decisão
    int reserva(char matriz[andar][ap]);

    //Utilizei esse FOR para criar a matriz de Andares e Apartamentos
    for(i=20; i>0; i--)
        for(j=1; j<15;j++){
        matriz[i][j] = '.';}

    //Utilizei esse WHILE para fazer o loop principal do programa
    while(k != 8){

        //Utilizei esse FOR para imprimir a matriz do MENU
        for(j=0; j <= 7; j++){
            printf("\n%s", MatrizMenu[j]);}
            printf("\n");

            //Em seguida é apresentado uma pergunta para o usuário escolher a opcao desejada
            printf("\nDigite uma opcao: ");
            scanf("%d", &k);

            //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
            system("cls");

            //Assim que o usuário digita a opcao desejada, inicia os comandos abaixo em relação a opcao digitada
            if(k == 1){
                mapa(matriz);
                CheckIn(matriz);}
                else{
                    if(k == 3){
                        reserva(matriz);}
                        else{
                            if(k == 5){
                                mapa(matriz);
                                printf("\nPara voltar ao MENU digite (-1): ");
                                scanf("%d", &g);
                                if (g == -1){
                                    system("cls");}}}}
}
    //A função principal do WHILE é executar a opcao desejada e logo depois quando a opcao termina de executar o usuário
    //volta a tela inicial do MENU
}

int mapa(char matriz[andar][ap]){

        //Esta função foi criada para receber a matriz de Andares e Apartamentos criada acima e completar
        //com os Andares e Apartamentos

        int i, j, t;

        printf("\nApto ---> \t");

        //Utilizei o FOR abaixo para colocar o números dos Apartamentos no lugar exato de cada '.' ponto correspondente
        for(j=1; j<15;j++)
        printf("%2d ", j);
        printf("\n");

        //Utilizei esse FOR para criar a coluna de Andares e seus respectivos números
        for(int i=20; i>0;i--){
        printf("Andar %2d:\t", i);

        //Utilizei esse FOR para deixar cada '.' ponto de baixo do seu respectivo Apartamento
        for(int j=1; j<15; j++)
        printf(" %c ", matriz[i][j]);
        printf("\n");}

        //Logo após isso a função termina
}

int reserva(char matriz[andar][ap]){

    //Criamos esta funcao para fazer a Reserva do Andar e Apartamento
    int i, j;

    //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
    int mapa(char matriz[andar][ap]);
    mapa(matriz);

    //Criei esse WHILE para iterar ate que o usuário digite uma coordenada valida
    while(i != -1){

        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else
                    if (j<1 || j>15 || i<1 || i>21){

                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(matriz);}
                        else
                            //Utilizei esse IF para ver se a coordenada que o usuário digitou já esta reservado
                            if(matriz[i][j] == 'R'){
                                //Mensagem de aviso para o usuário
                                printf("\n-----------------------------------");
                                printf("\n|Este dormitorio ja esta reservado|");
                                printf("\n-----------------------------------");

                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                Sleep(5000);

                                //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                system("cls");

                                //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                mapa(matriz);}
                                else

                                    //Utilizei esse IF para ver se a coordenada já está ocupada
                                    if(matriz[i][j] == 'O'){
                                        //Mensagem de aviso para o usuário
                                        printf("\n---------------------------------");
                                        printf("\n|Este dormitorio ja esta ocupado|");
                                        printf("\n---------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                        system("cls");

                                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                        mapa(matriz);}
                            else{
                                    //Se tudo estiver correto as coordenadas serão marcadas na Matriz
                                    matriz[i][j] = 'R';

                                    //Mensagem de aviso para o usuário
                                    printf("\n---------------------------");
                                    printf("\n|Sua reserva foi concluida|");
                                    printf("\n---------------------------");

                                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                    i = -1;

                                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar, logo após isso é
                                    //redirecionado para o MENU
                                    Sleep(5000);

                                    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                    system("cls");}}

}

int CheckIn(char matriz[andar][ap]){

    //Criamos essa funcao para fazer o Check-in dos dormitórios

    int i, j;

    //Utilizei esse DO-WHILE para faça um loop ate que o usuário digite uma coordenada válida
    do{
        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else

                    //Utilizei esse IF para ver se a coordenada digitada está dentro da matriz
                    if (i<1 || i>20 || j<1 || j>15){
                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(matriz);}

            //Utilei esse ELSE caso o usuário digite um valor valido e que essa coordenada já esteva reservada
            else

                //Utilizei esse IF para ver se a coordenada já está reservada, caso esteja muda o status para Ocupado
                if (matriz[i][j] == 'R'){

                    matriz[i][j] = 'O';

                    //Mensagem de aviso para o usuário
                    printf("\n----------------------------------------");
                    printf("\n|Seu Check-in foi executado com sucesso|");
                    printf("\n----------------------------------------");

                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                    system("cls");

                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                    i = -1;}

                    //Utilizei o ELSE abaico para caso a coordenada digitada pelo usuário já esteja ocupada
                    else

                        //Utilizei esse IF para conferir se a coordenada digitada já está Ocupada
                        if(matriz[i][j] == 'O'){

                            //Mensagem de aviso para o usuário
                            printf("\n----------------------------------------------------------");
                            printf("\n|Este dormitorio ja esta ocupado, digite outra coordenada|");
                            printf("\n----------------------------------------------------------");

                            //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                            Sleep(5000);

                            //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                            system("cls");

                            //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                            mapa(matriz);}

                            //Utilizei o ELSE abixo para caso a coordenada digitada pelo usuário ainda não esteja
                            //reservada
                            else{

                                        //Mensagem de aviso para o usuário
                                        printf("\n----------------------------------------------");
                                        printf("\n|Nao ha nenhuma reserva feita neste dormitorio|");
                                        printf("\n----------------------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                        system("cls");

                                        //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                        i = -1;}


    }while(i != -1);

    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
    system("cls");

}

