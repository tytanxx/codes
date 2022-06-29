/*Esse código é referente a um sistema de HOTEL
Basicamente o usuário poderá fazer RESERVA, CHECK-IN, CHECK-OUT e outras coisas...
Para entrar com as coordenadar digite: (andar, apartamento) exemplo: 1, 1
Me considero um iniciante em programação, então provavelmente poderá haver formas mais faceis de escrever esse código(mudando funções, lógica...)
Foi desenvolvido por João Augusto Carrascoza
Esse código só poderá ser utilizado em WINDOWS por causa do comando 'system("cls"); e o Sleep(5000);'
Caso queira executar esse programa em LINUX, troque por 'system("clear"); e sleep(5);' e deverá apagar a biblioteca '<Windows.h>
Data 26/06/2022*/

#include <stdio.h>
#include <stdlib.h>

//Biblioteca referente ao comando Sleep(5000);
#include <Windows.h>

//Esse 'define' serve para a quantidade de ANDARES do HOTEL,
//só irá alterar na MATRIZ (caso queira adicinoar, deverá mudar respectivamente os 'FOR' utilizados para criar a MATRIZ
#define andar 21

//Esse 'define' serve para a quantidade de  APARTAMENTOS do HOTEL,
//só irá alterar na MATRIZ (caso queira adicinoar, deverá mudar respectivamente os 'FOR' utilizados para criar a MATRIZ
#define ap 15

struct informacoes{

    char status;
	char nome[40];
	char CPF[15];
	char celular[12];
	char endereco[100];
	char email[50];
};

//Compilado das Funções
void mapa(struct informacoes hotel[andar][ap]);
void reserva(struct informacoes hotel[andar][ap]);
void CancelarReserva(struct informacoes hotel[andar][ap]);
void CheckIn(struct informacoes hotel[andar][ap]);
void CheckOut(struct informacoes hotel[andar][ap]);
void TaxaDeNaoVacancia(struct informacoes hotel[andar][ap]);
void MostrarDados(struct informacoes hotel[andar][ap]);

int main(){

    //Matriz criada com a finalidade de ser o MENU do Hotel
    char MatrizMenu[8][45] = {{"(1) - Check-in de hospede"}, {"(2) - Check-out de hospede"}, {"(3) - Reservar apartamento"},
    {"(4) - Cancelar reserva"}, {"(5) - Mapa de ocupacao e reservas de hotel"},{"(6) - Informacoes do hospede"},
    {"(7) - Taxas de ocupacao e reservas do hotel"},{"(8) - Sair do programa"}};

    int j, i, g, opcao, voltar;

    //Matriz criada com a finalidade de criar a matriz de Andares e Apartamentos
    struct informacoes hotel[andar][ap];

    //Utilizei esse FOR para criar a matriz de Andares e Apartamentos
    for(i=20; i>0; i--)
        for(j=1; j<15;j++){
        hotel[i][j].status = '.';}

    //Utilizei esse WHILE para fazer o loop principal do programa
    while(opcao != 8){

        //Utilizei esse FOR para imprimir a matriz do MENU
        for(j=0; j <= 7; j++){
            printf("\n%s", MatrizMenu[j]);}
            printf("\n");

            //Em seguida é apresentado uma pergunta para o usuário escolher a opcao desejada
            printf("\nDigite uma opcao: ");
            scanf("%d", &opcao);

            //Utilizei esse comando para limpar a tela do terminal
            system("cls");

            //Assim que o usuário digita a opcao desejada, inicia os comandos abaixo em relação a opcao digitada
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
                    printf("\nDigite (-1) para retornar ao MENU: ");
                    scanf("%d", &voltar);
                    if(voltar == -1) system("cls");
                    break;
                //Ocupação
                case 6:
                    MostrarDados(hotel);
                    break;
                case 7:
                    TaxaDeNaoVacancia(hotel);
                    break;
                case 8:
                    break;}}

    //A função principal do WHILE é executar a opcao desejada e logo depois quando a opcao termina de executar o usuário
    //volta a tela inicial do MENU
}

//Função que possibilita o usuário ver o MAPA de dormitórios do HOTEL
void mapa(struct informacoes hotel[andar][ap]){

        //Esta função foi criada para receber a matriz de Andares e Apartamentos criada acima e completar
        //com os Andares e Apartamentos

        int i, j;

        printf("\nApto ---> \t");

        //Utilizei o FOR abaixo para colocar o números dos Apartamentos no lugar exato de cada '.' ponto correspondente
        for(j=1; j<15;j++)
        printf("%2d ", j);
        printf("\n\n");

        //Utilizei esse FOR para criar a coluna de Andares e seus respectivos números
        for(int i=20; i>0;i--){
        printf("Andar %2d:\t", i);

        //Utilizei esse FOR para deixar cada '.' ponto de baixo do seu respectivo Apartamento
        for(int j=1; j<15; j++)
        printf(" %c ", hotel[i][j].status);
        printf("\n");}

        printf ("\n");

        //Logo após isso a função termina
}

//Função que possibilita fazer a RESERVA de um dormitório do HOTEL
void reserva(struct informacoes hotel[andar][ap]){

    //Criamos esta funcao para fazer a Reserva do Andar e Apartamento
    int i, j;

    //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
    void mapa(struct informacoes hotel[andar][ap]);
    mapa(hotel);

    //Criei esse WHILE para iterar ate que o usuário digite uma coordenada valida
    while(i != -1){

        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando para limpar a tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else
                    if (j<1 || j>14 || i<1 || i>20){

                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando para limpar a tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(hotel);}

                        else
                            //Utilizei esse IF para ver se a coordenada que o usuário digitou já esta reservado
                            if(hotel[i][j].status == 'R'){
                                //Mensagem de aviso para o usuário
                                printf("\n-----------------------------------");
                                printf("\n|Este dormitorio ja esta reservado|");
                                printf("\n-----------------------------------");

                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                Sleep(5000);

                                //Utilizei esse comando para limpar a tela do terminal
                                system("cls");

                                //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                mapa(hotel);}

                                else

                                    //Utilizei esse IF para ver se a coordenada já está ocupada
                                    if(hotel[i][j].status == 'O'){
                                        //Mensagem de aviso para o usuário
                                        printf("\n---------------------------------");
                                        printf("\n|Este dormitorio ja esta ocupado|");
                                        printf("\n---------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando para limpar a tela do terminal
                                        system("cls");

                                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                        mapa(hotel);}
                            else{

                                    //Se tudo estiver correto as coordenadas serão marcadas na Matriz
                                    hotel[i][j].status = 'R';

                                    //Utilizei esse comando abaixo para pegar os dados do usuário
                                    printf("\n--------------------------------------------------------");
                                    printf("\n|Para concluir a sua reserva, digite os seguintes dados|");
                                    printf("\n--------------------------------------------------------\n");

                                    printf("\nDigite o seu nome: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].nome);

                                    printf("\nDigite o seu CPF: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].CPF);

                                    printf("\nDigite o numero do seu celular: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].celular);

                                    printf("\nDigite o seu endereco: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].endereco);

                                    printf("\nDigite o seu email: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].email);

                                    //Utilizei esse comando para limpar a tela do terminal
                                    system("cls");

                                    //Mensagem de aviso para o usuário
                                    printf("\n---------------------------");
                                    printf("\n|Sua reserva foi concluida|");
                                    printf("\n---------------------------");

                                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                    Sleep(5000);

                                    //Utilizei esse comando para limpar a tela do terminal
                                    system("cls");

                                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                    i = -1;}}
}

//Função que possibilita fazer o CANCELAMENTO de uma RESERVA de um dormitório do HOTEL
void CancelarReserva(struct informacoes hotel[andar][ap]){

    //Criamos esta funcao para fazer a Reserva do Andar e Apartamento
    int i, j;

    //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
    void mapa(struct informacoes hotel[andar][ap]);
    mapa(hotel);

    //Criei esse WHILE para iterar ate que o usuário digite uma coordenada valida
    while(i != -1){

        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento) para cancelar a reserva: ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando para limpar a tela do terminal
        system("cls");


        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else
                    if (j<1 || j>14 || i<1 || i>20){

                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando para limpar a tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(hotel);}

                        else

                            //Utilizei esse IF para ver se a coordenada que o usuário digitou já esta reservado
                            if(hotel[i][j].status == 'O'){

                                //Mensagem de aviso para o usuário
                                printf("\n---------------------------------");
                                printf("\n|Este dormitorio ja esta ocupado|");
                                printf("\n---------------------------------");

                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                Sleep(5000);

                                //Utilizei esse comando para limpar a tela do terminal
                                system("cls");

                                //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                mapa(hotel);}

                                else

                                    //Utilizei esse IF para ver se a coordenada já está ocupada
                                    if(hotel[i][j].status == '.'){
                                        //Mensagem de aviso para o usuário
                                        printf("\n------------------------------------");
                                        printf("\n|Este dormitorio nao esta reservado|");
                                        printf("\n------------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando para limpar a tela do terminal
                                        system("cls");

                                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                                        mapa(hotel);}
                            else{

                                    //Se tudo estiver correto as coordenadas serão marcadas na Matriz
                                    hotel[i][j].status = '.';

                                    //Mensagem de aviso para o usuário
                                    printf("\n-----------------------------------------");
                                    printf("\n|O cancelamento da reserva foi concluido|");
                                    printf("\n-----------------------------------------");

                                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                    Sleep(5000);

                                    //Utilizei esse comando para limpar a tela do terminal
                                    system("cls");

                                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                    i = -1;}}
}

//Função que possibilita fazer o Check-in de um dormitório do HOTEL
void CheckIn(struct informacoes hotel[andar][ap]){

    //Criamos essa funcao para fazer o Check-in dos dormitórios

    int i, j;

    //Utilizei esse DO-WHILE para faça um loop ate que o usuário digite uma coordenada válida
    do{
        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando para limpar a tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else

                    //Utilizei esse IF para ver se a coordenada digitada está dentro da matriz
                    if (i<1 || i>20 || j<1 || j>14){
                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando para limpar a tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(hotel);}

            //Utilei esse ELSE caso o usuário digite um valor valido e que essa coordenada já esteva reservada
            else

                //Utilizei esse IF para ver se a coordenada já está reservada, caso esteja muda o status para Ocupado
                if (hotel[i][j].status == 'R'){

                    hotel[i][j].status = 'O';

                    //Mensagem de aviso para o usuário
                    printf("\n----------------------------------------");
                    printf("\n|Seu Check-in foi executado com sucesso|");
                    printf("\n----------------------------------------");

                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                    Sleep(5000);

                    //Utilizei esse comando para limpar a tela do terminal
                    system("cls");

                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                    i = -1;}

                    //Utilizei o ELSE abaico para caso a coordenada digitada pelo usuário já esteja ocupada
                    else

                        //Utilizei esse IF para conferir se a coordenada digitada já está Ocupada
                        if(hotel[i][j].status == 'O'){

                            //Mensagem de aviso para o usuário
                            printf("\n----------------------------------------------------------");
                            printf("\n|Este dormitorio ja esta ocupado, digite outra coordenada|");
                            printf("\n----------------------------------------------------------");

                            //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                            Sleep(5000);

                            //Utilizei esse comando para limpar a tela do terminal
                            system("cls");

                            //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                            mapa(hotel);}

                            //Utilizei o ELSE abixo para caso a coordenada digitada pelo usuário ainda não esteja
                            //reservada
                            else

                                if(hotel[i][j].status == '.'){

                                    hotel[i][j].status = 'O';

                                    //Utilizei esse comando abaixo para pegar os dados do usuário
                                    printf("\n--------------------------------------------------------");
                                    printf("\n|Para concluir a sua reserva, digite os seguintes dados|");
                                    printf("\n--------------------------------------------------------\n");

                                    printf("\nDigite o seu nome: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].nome);

                                    printf("\nDigite o seu CPF: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].CPF);

                                    printf("\nDigite o numero do seu celular: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].celular);

                                    printf("\nDigite o seu endereco: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].endereco);

                                    printf("\nDigite o seu email: ");
                                    fflush(stdin);
                                    scanf("%s",&hotel[i][j].email);

                                    //Utilizei esse comando para limpar a tela do terminal
                                    system("cls");

                                    //Mensagem de aviso para o usuário
                                    printf("\n----------------------------------------");
                                    printf("\n|Seu Check-in foi executado com sucesso|");
                                    printf("\n----------------------------------------");

                                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                    Sleep(5000);

                                    //Utilizei esse comando para limpar a tela do terminal
                                    system("cls");

                                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                    i = -1;}


    }while(i != -1);
}

//Função que possibilita fazer o Check-out de um dormitório do HOTEL
void CheckOut(struct informacoes hotel[andar][ap]){

    //Criamos essa funcao para fazer o Check-Out dos dormitórios

    int i, j;

    //Utilizei esse DO-WHILE para faça um loop ate que o usuário digite uma coordenada válida
    do{
        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento): ");
        scanf("%d,%d", &i, &j);

        //Utilizei esse comando para limpar a tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else

                    //Utilizei esse IF para ver se a coordenada digitada está dentro da matriz
                    if (i<1 || i>20 || j<1 || j>14){
                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando para limpar a tela do terminal
                        system("cls");

                        //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                        mapa(hotel);}

            //Utilei esse ELSE caso o usuário digite um valor valido e que essa coordenada já esteva Ocupada
            else

                //Utilizei esse IF para ver se a coordenada já estava ocupada, caso esteja muda o status para Disponivel
                if (hotel[i][j].status == 'O'){

                    hotel[i][j].status = '.';

                    //Mensagem de aviso para o usuário
                    printf("\n-----------------------------------------");
                    printf("\n|Seu Check-out foi executado com sucesso|");
                    printf("\n-----------------------------------------");

                    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                    Sleep(5000);

                    //Utilizei esse comando para limpar a tela do terminal
                    system("cls");

                    //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                    i = -1;}

                    //Utilizei o ELSE abaico para caso a coordenada digitada pelo usuário já esteja reservada
                    else

                        //Utilizei esse IF para conferir se a coordenada digitada já está Ocupada
                        if(hotel[i][j].status == 'R'){

                            //Mensagem de aviso para o usuário
                            printf("\n---------------------------------------------------------");
                            printf("\n|Este dormitorio esta reservado, digite outra coordenada|");
                            printf("\n---------------------------------------------------------");

                            //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                            Sleep(5000);

                            //Utilizei esse comando para limpar a tela do terminal
                            system("cls");

                            //Chamei a Função MAPA para auxiliar o usuário na tomada de decisão
                            mapa(hotel);}

                            //Utilizei o ELSE abixo para caso a coordenada digitada pelo usuário ainda não esteja
                            //reservada
                            else{

                                        //Mensagem de aviso para o usuário
                                        printf("\n-----------------------------------------------");
                                        printf("\n|Nao ha nenhuma reserva feita neste dormitorio|");
                                        printf("\n-----------------------------------------------");

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando para limpar a tela do terminal
                                        system("cls");

                                        //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                        i = -1;}


    }while(i != -1);
}

//Função que mostra em PORCENTAGEM a TAXA de OCUPAÇÃO, RESERVA e dormitórios LIVRES do HOTEL
void TaxaDeNaoVacancia(struct informacoes hotel[andar][ap]){

    int i, j;
    int ContadorOcupacao = 0;
    int ContadorReserva = 0;
    int ContadorLivre = 0;
    float TaxaOcupacao, TaxaReserva, TaxaLivre;

    //Utilizei esse FOR abaixo para contar a quantidade de dormitórios ocupados no Hotel
    for(i=20; i>0; i--)
        for(j=1; j<15;j++){
            if(hotel[i][j].status == 'O'){
                ContadorOcupacao = ContadorOcupacao + 1;}}

    //Utilizei esse FOR abaixo para contar a quantidade de dormitórios reservados no Hotel
    for(i=20; i>0; i--)
        for(j=1; j<15;j++){
            if(hotel[i][j].status == 'R'){
                ContadorReserva = ContadorReserva + 1;}}

    //Utilizei esse FOR abaixo para contar a quantidade  dormitórios livres no Hotel
    for(i=20; i>0; i--)
        for(j=1; j<15;j++){
            if(hotel[i][j].status == '.'){
                ContadorLivre = ContadorLivre + 1;}}

    //Usei essa TaxaOcupacao para calcular a porcetagem de dormitórios Ocupados do Hotel
    TaxaOcupacao = ContadorOcupacao * 100.0 / 280.0;

    //Usei essa TaxaReserva para calcular a porcetagem de dormitórios Reservados do Hotel
    TaxaReserva  = ContadorReserva  * 100.0 / 280.0;

    //Usei essa TaxaLivre para calcular a porcetagem de dormitórios Livres do Hotel
    TaxaLivre    = ContadorLivre    * 100.0 / 280.0;

    //Aqui vai ser impresso na tela a porcentagem de cada status do Hotel
    printf("\n- Taxa Ocupacao: %0.2f\n", TaxaOcupacao);
    printf("\n- Taxa Reserva: %0.2f\n", TaxaReserva);
    printf("\n- Taxa Livre: %0.2f\n", TaxaLivre);

    //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
    Sleep(5000);

    //Utilizei esse comando para limpar a tela do terminal
    system("cls");
}

//Função que possibilita imprimir os dados do usuário de acordo com a coordenada desejada
void MostrarDados(struct informacoes hotel[andar][ap]){

    // Neste caso o i e j serão as variaveis de andar e apartamento respectivamente
    int i, j;

    //Criei esse WHILE para iterar ate que o usuário digite uma coordenada valida
    while(i != -1){

        //Aqui é feita a pergunta para o usuário responder com o Andar e Apartamento desejado
        printf("\nPara retornar ao MENU digite (-1,-1): ");
        printf("\nDigite (andar, apartamento) para exibir os dados desse cliente: ");
        scanf("%d,%d", &i,&j);

        //Utilizei esse comando para limpar a tela do terminal
        system("cls");

        //Logo após o usuário digitar é testado a validade das coordenadas
        if(i == -1 && j == -1){
                i == -1;}
                else
                    if (j<1 || j>14 || i<1 || i>20){

                        //Mensagem de aviso para o usuário
                        printf("\n------------------------------");
                        printf("\n|Digite uma coordenada valida|");
                        printf("\n------------------------------");

                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                        Sleep(5000);

                        //Utilizei esse comando para limpar a tela do terminal
                        system("cls");}

                        else
                            if(hotel[i][j].status == '.'){

                                printf("\n-----------------------------------------------");
                                printf("\n|Essa coordenada nao possui cliente cadastrado|");
                                printf("\n-----------------------------------------------");

                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                Sleep(5000);

                                //Utilizei esse comando para limpar a tela do terminal
                                system("cls");

                                i = -1;}

                                else

                                    //Utilizei esse IF para ver se a coordenada que o usuário digitou já esta reservado
                                    if(hotel[i][j].status == 'R'){

                                        //Aqui será mostrado cada dado de acordo com as coordenadas digitadas
                                        printf("\nNome: %s ",hotel[i][j].nome);
                                        printf("\nCelular: %s ",hotel[i][j].celular);
                                        printf("\nCPF: %s ",hotel[i][j].CPF);
                                        printf("\nEndereco: %s ",hotel[i][j].endereco);
                                        printf("\nEmail: %s ",hotel[i][j].email);

                                        //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                        Sleep(5000);

                                        //Utilizei esse comando para limpar a tela do terminal
                                        system("cls");


                                        //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                        i = -1;}

                                        else
                                            if(hotel[i][j].status == 'O'){

                                                //Aqui será mostrado cada dado de acordo com as coordenadas digitadas
                                                printf("\nNome: %s ",hotel[i][j].nome);
                                                printf("\nCelular: %s ",hotel[i][j].celular);
                                                printf("\nCPF: %s ",hotel[i][j].CPF);
                                                printf("\nEndereco: %s ",hotel[i][j].endereco);
                                                printf("\nEmail: %s ",hotel[i][j].email);

                                                //Utilizei esse comando abaixo para mostrar na tela por 5 segundos e depois fechar
                                                Sleep(5000);

                                                //Utilizei esse comando para limpar a tela do terminal
                                                system("cls");

                                                //Utilizei o comando abaixo para finalizar a sessão e retornar ao MENU
                                                i = -1;}}
}
