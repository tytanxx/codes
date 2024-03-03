/*Integrantes do grupo: Jefferson da Silva de Souza, João Augusto Carrascoza e Pedro França de Godoi
Este código tem como objetivo exemplificar um sistema de gestão de hotel
Data: 27/06/2022*/

#include <stdio.h>
#include <stdlib.h>

//Quantidade de andaresES do HOTEL
#define andares 21

//Quantidade de  APARTAMENTOS do HOTEL
#define ap 15

//struct criada para exemplificar informações dos hóspedes
struct informacoes{
    char status;
	char nome[40];
	char CPF[15];
	char celular[12];
	char endereco[100];
	char email[50];
};

void mapa(struct informacoes hotel[andares][ap]);
void reserva(struct informacoes hotel[andares][ap]);
void CancelarReserva(struct informacoes hotel[andares][ap]);
void CheckIn(struct informacoes hotel[andares][ap]);
void CheckOut(struct informacoes hotel[andares][ap]);
void TaxaDeNaoVacancia(struct informacoes hotel[andares][ap]);
void MostrarDados(struct informacoes hotel[andares][ap]);

int main(){

    //Matriz criada com a finalidade de ser o MENU do Hotel
    char MatrizMenu[8][45] = {{"(1) - Check-in de hospede"}, {"(2) - Check-out de hospede"}, {"(3) - Reservar apartamento"},
    {"(4) - Cancelar reserva"}, {"(5) - Mapa de ocupacao e reservas de hotel"},{"(6) - Informacoes do hospede"},
    {"(7) - Taxas de ocupacao e reservas do hotel"},{"(8) - Sair do programa"}};

    int opcao, voltar;

    //Matriz criada com a finalidade de criar a matriz de andareses e Apartamentos
    struct informacoes hotel[andares][ap];

    //Criação da matriz de andareses e Apartamentos
    for(int i=20; i>0; i--)
        for(int j=1; j<15;j++){
        hotel[i][j].status = '.';}

    while(opcao != 8){

        //Mostrar o MENU
        for(int j=0; j <= 7; j++){
            printf("\n%s", MatrizMenu[j]);}
            printf("\n");

            //Pergunta para o usuário escolher a opcao desejada
            printf("\nDigite uma opcao: ");
            scanf("%d", &opcao);

            //Assim que o usuário digita a opcao desejada, inicia os comandos do mesmo
            switch (opcao){

                //Check-in
                case 1:
                    mapa(hotel);
                    CheckIn(hotel);
                    break;

                //Check-out
                case 2:
                    mapa(hotel);
                    CheckOut(hotel);
                    break;

                //Reserva
                case 3:
                    reserva(hotel);
                    break;

                //Cancelar reserva
                case 4:
                    CancelarReserva(hotel);
                    break;

                //Mapa do hotel
                case 5:
                    mapa(hotel);
                    printf("\nDigite '-1' para retornar ao MENU: ");
                    scanf("%d", &voltar);
                    if(voltar == -1)
                    break;

                //Mostrar Dados
                case 6:
                    MostrarDados(hotel);
                    break;

                //Ocupação
                case 7:
                    TaxaDeNaoVacancia(hotel);
                    break;

                //Encerrar programa
                case 8:
                    break;}}
}

//Função que possibilita o usuário ver o MAPA de dormitórios do HOTEL
void mapa(struct informacoes hotel[andares][ap]){

        printf("\nApto ---> \t");

        //Criar a coluna de Apartamentos e seus respectivos números
        for(int j=1; j<15;j++)
        printf("%2d ", j);
        printf("\n\n");

        //Criar a coluna de andareses e seus respectivos números
        for(int i=20; i>0;i--){
        printf("andares %2d:\t", i);

        //Colocar cada '.' ponto debaixo do seu respectivo Apartamento
        for(int j=1; j<15; j++)
        printf(" %c ", hotel[i][j].status);
        printf("\n");}
}

//Função que possibilita fazer a RESERVA de um dormitório do HOTEL
void reserva(struct informacoes hotel[andares][ap]){

    int andar, apto;

    while(andar != -1 && apto!= -1){
        //Chamada de mapa() para auxiliar o usuário
        mapa(hotel);

        //Pergunta para o usuário responder com o andares e Apartamento desejado
        printf("\nPara retornar ao MENU digite '-1,-1': ");
        printf("\nDigite 'andares, apartamento': ");
        scanf("%d,%d", &andar, &apto);

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(apto<1 || apto>14 || andar<1 || andar>20){
                //Mensagem de aviso para o usuário
                printf("\n------------------------------");
                printf("\n|Digite uma coordenada valida|");
                printf("\n------------------------------");}

                else
                    //Verificar se a coordenada que o usuário digitou já esta reservado
                    if(hotel[andar][apto].status == 'R'){
                        //Mensagem de aviso para o usuário
                        printf("\n-----------------------------------");
                        printf("\n|Este dormitorio ja esta reservado|");
                        printf("\n-----------------------------------");}

                        else
                            //Verificar se a coordenada já está ocupada
                            if(hotel[andar][apto].status == 'O'){
                                //Mensagem de aviso para o usuário
                                printf("\n---------------------------------");
                                printf("\n|Este dormitorio ja esta ocupado|");
                                printf("\n---------------------------------");}
        else{

            //Matriz (andares e apartamento) marcada com RESERVADA
            hotel[andar][apto].status = 'R';

            //Mensagem de aviso para o usuário
            printf("\n--------------------------------------------------------");
            printf("\n|Para concluir a sua reserva, digite os seguintes dados|");
            printf("\n--------------------------------------------------------\n");

            printf("\nDigite o seu nome: ");
            fflush(stdin);
            scanf("%s",&hotel[andar][apto].nome);

            printf("\nDigite o seu CPF: ");
            fflush(stdin);
            scanf("%s",&hotel[andar][apto].CPF);

            printf("\nDigite o numero do seu celular: ");
            fflush(stdin);
            scanf("%s",&hotel[andar][apto].celular);

            printf("\nDigite o seu endereco: ");
            fflush(stdin);
            scanf("%s",&hotel[andar][apto].endereco);

            printf("\nDigite o seu email: ");
            fflush(stdin);
            scanf("%s",&hotel[andar][apto].email);

            //Mensagem de aviso para o usuário
            printf("\n---------------------------");
            printf("\n|Sua reserva foi concluida|");
            printf("\n---------------------------");

            break;}}
}

//Função que possibilita fazer o CANCELAMENTO de uma RESERVA
void CancelarReserva(struct informacoes hotel[andares][ap]){

    int andar, apto;

    while(andar != -1 && apto != -1){
        //Chamada de mapa() para auxiliar o usuário
        mapa(hotel);

        //Pergunta para o usuário responder com o andares e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andares, apartamento) para cancelar a reserva: ");
        scanf("%d,%d", &andar, &apto);

        //Logo após o usuário digitar é testado a validade das coordenadas
        if (apto<1 || apto>14 || andar<1 || andar>20){
            //Mensagem de aviso para o usuário
            printf("\n------------------------------");
            printf("\n|Digite uma coordenada valida|");
            printf("\n------------------------------");}

            else
                //Utilizei esse IF para ver se a coordenada que o usuário digitou já esta reservado
                if(hotel[andar][apto].status == 'O'){
                    //Mensagem de aviso para o usuário
                    printf("\n---------------------------------");
                    printf("\n|Este dormitorio ja esta ocupado|");
                    printf("\n---------------------------------");}

                    else
                        //Utilizei esse IF para ver se a coordenada já está ocupada
                        if(hotel[andar][apto].status == '.'){
                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------------");
                        printf("\n|Este dormitorio nao esta reservado|");
                        printf("\n------------------------------------");}
        else{
                //Se tudo estiver correto as coordenadas serão marcadas na Matriz
                hotel[andar][apto].status = '.';

                //Mensagem de aviso para o usuário
                printf("\n-----------------------------------------");
                printf("\n|O cancelamento da reserva foi concluido|");
                printf("\n-----------------------------------------");
                break;}}
}

//Função que possibilita fazer o Check-in
void CheckIn(struct informacoes hotel[andares][ap]){

    int andar, apto;

    while(andar != -1 && apto != -1){
        //Chamada de mapa() para auxiliar o usuário
        mapa(hotel);

        //Aqui é feita a pergunta para o usuário responder com o andares e Apartamento desejado
        printf("\nPara retornar ao MENU digite '-1,-1: ");
        printf("\nDigite 'andares, apartamento': ");
        scanf("%d,%d", &andar, &apto);

        if (andar<1 || andar>20 || apto<1 || apto>14){
            //Mensagem de aviso para o usuário
            printf("\n------------------------------");
            printf("\n|Digite uma coordenada valida|");
            printf("\n------------------------------");}

            //Coordenada já estava reservada
            else

                //Utilizei esse IF para ver se a coordenada já está reservada, caso esteja muda o status para Ocupado
                if (hotel[andar][apto].status == 'R'){
                    hotel[andar][apto].status = 'O';

                    //Mensagem de aviso para o usuário
                    printf("\n----------------------------------------");
                    printf("\n|Seu Check-in foi executado com sucesso|");
                    printf("\n----------------------------------------");
                    break;}

                    //Coordenada digitada pelo usuário já está ocupada
                    else
                        if(hotel[andar][apto].status == 'O'){

                            //Mensagem de aviso para o usuário
                            printf("\n----------------------------------------------------------");
                            printf("\n|Este dormitorio ja esta ocupado, digite outra coordenada|");
                            printf("\n----------------------------------------------------------");}

                            else

                                if(hotel[andar][apto].status == '.'){
                                    hotel[andar][apto].status = 'O';

                                    //Utilizei esse comando abaixo para pegar os dados do usuário
                                    printf("\n--------------------------------------------------------");
                                    printf("\n|Para concluir a sua reserva, digite os seguintes dados|");
                                    printf("\n--------------------------------------------------------\n");

                                    printf("\nDigite o seu nome: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[andar][apto].nome);

                                    printf("\nDigite o seu CPF: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[andar][apto].CPF);

                                    printf("\nDigite o numero do seu celular: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[andar][apto].celular);

                                    printf("\nDigite o seu endereco: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[andar][apto].endereco);

                                    printf("\nDigite o seu email: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[andar][apto].email);


                                    //Mensagem de aviso para o usuário
                                    printf("\n----------------------------------------");
                                    printf("\n|Seu Check-in foi executado com sucesso|");
                                    printf("\n----------------------------------------");

                                    break;}
}}

//Função que possibilita fazer o Check-out de um dormitório do HOTEL
void CheckOut(struct informacoes hotel[andares][ap]){

    int andar, apto;

    while(andar != -1 && apto != -1){
        //Chamada de mapa() para auxiliar o usuário
        mapa(hotel);

        //Pergunta para o usuário responder com o andares e Apartamento desejado
        printf("\nPara retornar ao MENU digite '-1,-1': ");
        printf("\nDigite 'andares, apartamento': ");
        scanf("%d,%d", &andar, &apto);

        //Logo após o usuário digitar é testado a validade das coordenadas
        if (andar<1 || andar>20 || apto<1 || apto>14){
            //Mensagem de aviso para o usuário
            printf("\n------------------------------");
            printf("\n|Digite uma coordenada valida|");
            printf("\n------------------------------");}

            //Coordenada já estava Ocupada
            else
                if (hotel[andar][apto].status == 'O'){
                    hotel[andar][apto].status = '.';

                    //Mensagem de aviso para o usuário
                    printf("\n-----------------------------------------");
                    printf("\n|Seu Check-out foi executado com sucesso|");
                    printf("\n-----------------------------------------");
                    break;}

                    //Coordenada esta reservada
                    else
                        if(hotel[andar][apto].status == 'R'){
                            //Mensagem de aviso para o usuário
                            printf("\n---------------------------------------------------------");
                            printf("\n|Este dormitorio esta reservado, digite outra coordenada|");
                            printf("\n---------------------------------------------------------");}
        else{
            //Mensagem de aviso para o usuário
            printf("\n-----------------------------------------------");
            printf("\n|Nao ha nenhuma reserva feita neste dormitorio|");
            printf("\n-----------------------------------------------");
            break;}}
}

//Função que mostra em PORCENTAGEM a TAXA de OCUPAÇÃO, RESERVA e dormitórios LIVRES do HOTEL
void TaxaDeNaoVacancia(struct informacoes hotel[andares][ap]){

    int ContadorOcupacao = 0;
    int ContadorReserva = 0;
    int ContadorLivre = 0;
    float TaxaOcupacao, TaxaReserva, TaxaLivre;

    //Utilizei esse FOR abaixo para contar a quantidade de dormitórios ocupados no Hotel
    for(int i=20; i>0; i--)
        for(int j=1; j<15;j++){
            if(hotel[i][j].status == 'O'){ ContadorOcupacao = ContadorOcupacao + 1;}
                else if(hotel[i][j].status == 'R'){ ContadorReserva = ContadorReserva + 1;}
                    else if(hotel[i][j].status == '.'){ ContadorLivre = ContadorLivre + 1;}}

    //Calcular a porcetagem de dormitórios Ocupados do Hotel
    TaxaOcupacao = ContadorOcupacao*100.0/280.0;

    //Calcular a porcetagem de dormitórios Reservados do Hotel
    TaxaReserva = ContadorReserva*100.0/280.0;

    //Calcular a porcetagem de dormitórios Livres do Hotel
    TaxaLivre = ContadorLivre*100.0/280.0;

    //Porcentagem de cada status do Hotel
    printf("\n- Taxa Ocupacao: %0.2f\n", TaxaOcupacao);
    printf("\n- Taxa Reserva: %0.2f\n", TaxaReserva);
    printf("\n- Taxa Livre: %0.2f\n", TaxaLivre);

}

//Função que possibilita mostrar os dados do usuário de acordo com a coordenada desejada
void MostrarDados(struct informacoes hotel[andares][ap]){

    int andar, apto;

    while(andar != -1 && apto != -1){

        //Pergunta para o usuário responder com o andares e Apartamento desejado
        printf("\nPara retornar ao MENU digite '-1,-1': ");
        printf("\nDigite 'andares, apartamento' para exibir os dados desse cliente: ");
        scanf("%d,%d", &andar,&apto);

        //Logo após o usuário digitar é testado a validade das coordenadas
        if (apto<1 || apto>14 || andar<1 || andar>20){
            //Mensagem de aviso para o usuário
            printf("\n------------------------------");
            printf("\n|Digite uma coordenada valida|");
            printf("\n------------------------------");}

            else
                if(hotel[andar][apto].status == '.'){

                printf("\n-----------------------------------------------");
                printf("\n|Essa coordenada nao possui cliente cadastrado|");
                printf("\n-----------------------------------------------");}

                else
                    //Verificar se a coordenada que o usuário digitou já esta reservada ou ocupada
                    if(hotel[andar][apto].status == 'R' || hotel[andar][apto].status == 'O'){
                        //Aqui será mostrado cada dado de acordo com as coordenadas digitadas
                        printf("\nNome: %s ",hotel[andar][apto].nome);
                        printf("\nCelular: %s ",hotel[andar][apto].celular);
                        printf("\nCPF: %s ",hotel[andar][apto].CPF);
                        printf("\nEndereco: %s ",hotel[andar][apto].endereco);
                        printf("\nEmail: %s ",hotel[andar][apto].email);}}
}
