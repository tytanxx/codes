//Integrantes do Grupo: Jefferson da Silva de Souza, Jo�o Augusto Carrascoza e Pedro Fran�a de Godoi
//Esse c�digo � referente a entrega da primeira semana: REQ1, REQ2, REQ3
//Segue abaixo o c�digo dos requisitos acima
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

    //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
    int mapa(char matriz[andar][ap]);

    //Chamei a Fun��o  CheckIn para auxiliar o usu�rio na tomada de decis�o
    int CheckIn(char matriz[andar][ap]);

    //Chamei a Fun��o Reserva para auxiliar o usu�rio na tomada de decis�o
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

            //Em seguida � apresentado uma pergunta para o usu�rio escolher a opcao desejada
            printf("\nDigite uma opcao: ");
            scanf("%d", &k);

            //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
            system("cls");

            //Assim que o usu�rio digita a opcao desejada, inicia os comandos abaixo em rela��o a opcao digitada
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
    //A fun��o principal do WHILE � executar a opcao desejada e logo depois quando a opcao termina de executar o usu�rio
    //volta a tela inicial do MENU
}

int mapa(char matriz[andar][ap]){

        //Esta fun��o foi criada para receber a matriz de Andares e Apartamentos criada acima e completar
        //com os Andares e Apartamentos

        int i, j, t;

        printf("\nApto ---> \t");

        //Utilizei o FOR abaixo para colocar o n�meros dos Apartamentos no lugar exato de cada '.' ponto correspondente
        for(j=1; j<15;j++)
        printf("%2d ", j);
        printf("\n");

        //Utilizei esse FOR para criar a coluna de Andares e seus respectivos n�meros
        for(int i=20; i>0;i--){
        printf("Andar %2d:\t", i);

        //Utilizei esse FOR para deixar cada '.' ponto de baixo do seu respectivo Apartamento
        for(int j=1; j<15; j++)
        printf(" %c ", matriz[i][j]);
        printf("\n");}

        //Logo ap�s isso a fun��o termina
}

int reserva(char matriz[andar][ap]){

    //Criamos esta funcao para fazer a Reserva do Andar e Apartamento
    int i, j;

    //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
    int mapa(char matriz[andar][ap]);
    mapa(matriz);

    //Criei esse WHILE para iterar ate que o usu�rio digite uma coordenada valida
    while(i != -1){

        //Aqui � feita a pergunta para o usu�rio responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
        system("cls");

        //Logo ap�s o usu�rio digitar � testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else
                    if (j<1 || j>15 || i<1 || i>21){

                        //Mensagem de aviso para o usu�rio
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                        system("cls");

                        //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
                        mapa(matriz);}
                        else
                            //Utilizei esse IF para ver se a coordenada que o usu�rio digitou j� esta reservado
                            if(matriz[i][j] == 'R'){
                                //Mensagem de aviso para o usu�rio
                                printf("\n-----------------------------------");
                                printf("\n|Este dormitorio ja esta reservado|");
                                printf("\n-----------------------------------");

                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                Sleep(5000);

                                //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                system("cls");

                                //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
                                mapa(matriz);}
                                else

                                    //Utilizei esse IF para ver se a coordenada j� est� ocupada
                                    if(matriz[i][j] == 'O'){
                                        //Mensagem de aviso para o usu�rio
                                        printf("\n---------------------------------");
                                        printf("\n|Este dormitorio ja esta ocupado|");
                                        printf("\n---------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                        system("cls");

                                        //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
                                        mapa(matriz);}
                            else{
                                    //Se tudo estiver correto as coordenadas ser�o marcadas na Matriz
                                    matriz[i][j] = 'R';

                                    //Mensagem de aviso para o usu�rio
                                    printf("\n---------------------------");
                                    printf("\n|Sua reserva foi concluida|");
                                    printf("\n---------------------------");

                                    //Utilizei o comando abaixo para finalizar a sess�o e retornar ao MENU
                                    i = -1;

                                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar, logo ap�s isso �
                                    //redirecionado para o MENU
                                    Sleep(5000);

                                    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                    system("cls");}}

}

int CheckIn(char matriz[andar][ap]){

    //Criamos essa funcao para fazer o Check-in dos dormit�rios

    int i, j;

    //Utilizei esse DO-WHILE para fa�a um loop ate que o usu�rio digite uma coordenada v�lida
    do{
        //Aqui � feita a pergunta para o usu�rio responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
        system("cls");

        //Logo ap�s o usu�rio digitar � testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else

                    //Utilizei esse IF para ver se a coordenada digitada est� dentro da matriz
                    if (i<1 || i>20 || j<1 || j>15){
                        //Mensagem de aviso para o usu�rio
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                        system("cls");

                        //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
                        mapa(matriz);}

            //Utilei esse ELSE caso o usu�rio digite um valor valido e que essa coordenada j� esteva reservada
            else

                //Utilizei esse IF para ver se a coordenada j� est� reservada, caso esteja muda o status para Ocupado
                if (matriz[i][j] == 'R'){

                    matriz[i][j] = 'O';

                    //Mensagem de aviso para o usu�rio
                    printf("\n----------------------------------------");
                    printf("\n|Seu Check-in foi executado com sucesso|");
                    printf("\n----------------------------------------");

                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                    system("cls");

                    //Utilizei o comando abaixo para finalizar a sess�o e retornar ao MENU
                    i = -1;}

                    //Utilizei o ELSE abaico para caso a coordenada digitada pelo usu�rio j� esteja ocupada
                    else

                        //Utilizei esse IF para conferir se a coordenada digitada j� est� Ocupada
                        if(matriz[i][j] == 'O'){

                            //Mensagem de aviso para o usu�rio
                            printf("\n----------------------------------------------------------");
                            printf("\n|Este dormitorio ja esta ocupado, digite outra coordenada|");
                            printf("\n----------------------------------------------------------");

                            //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                            Sleep(5000);

                            //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                            system("cls");

                            //Chamei a Fun��o MAPA para auxiliar o usu�rio na tomada de decis�o
                            mapa(matriz);}

                            //Utilizei o ELSE abixo para caso a coordenada digitada pelo usu�rio ainda n�o esteja
                            //reservada
                            else{

                                        //Mensagem de aviso para o usu�rio
                                        printf("\n----------------------------------------------");
                                        printf("\n|Nao ha nenhuma reserva feita neste dormitorio|");
                                        printf("\n----------------------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
                                        system("cls");

                                        //Utilizei o comando abaixo para finalizar a sess�o e retornar ao MENU
                                        i = -1;}


    }while(i != -1);

    //Utilizei esse comando abaixo para 'limpar' o que esta acima dele na tela do terminal
    system("cls");

}

