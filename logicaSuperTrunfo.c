#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

/*
 23/07/2025  - (Célio) foi realizada as alterações e complementos referente ao modulo AVENTUREIRO.
             - ajustadas as saidas de tela para melhor entendimento dos dados mostrados
             - inseridas variaveis para densidade e renda per capta em cada carta
             - inseridas as linhas da calculo para as novas variaveis (vide observações nas referidas linhas)
*/


/*
  24/07/2025 - (Célio) - foram realizadas as alterações e complementos referente ao modulo MESTRE
             - criada a variavel SUPERPODER baseado na soma de todas os valores numericos menos a Densidade demografica 
             - apliquei a ideia de abater o valor da densidade na seguinte metodologia:
               SUPERPODER = soma de tudo * (1 / densidade * 100) de forma a gerar um numero onde a densidade quanto mais alta for
               mais alto será o desconto no superpoder da cidade.
*/

/*
  26/07/2025 - (Célio) - foram acrescidas linhas de codigo ao projeto anterior do desafio de cartas de supertrunfo conforme orientação.
             - o jogo agora compara todos os atributos, um a um, usando estrutura de decisão IF ELSE 
             - para diferenciar as duas fases do desenvolvimento os codigo desse novo desafio com as linhas totalmente em maiusculas
             - comentarios em versalete ou minusculas referem-se a fases do desafio anterior
             - devido ao novo conjunto de comparações o bloco de comparação anterior foi deletado do código
*/

/*
  28/07/2025 - (Célio) - foI foi alterada a forma de fazer as comparações de cartas, sendo inserido um menu interativo
             - que permite ao usuário escolher qual a caracteristicva a ser comparada
             - para diferenciar as duas fases do desenvolvimento os codigo desse novo desafio com as linhas totalmente em maiusculas
             - comentarios em versalete ou minusculas referem-se a fases do desafio anterior
             - foi mantido o código de nivel anterior (novato) do mesmo desafio devido não ter havido até agora a interação da tutoria
*/




int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // * Optei por usar uma referência para o PIB que é Milhões de Reais, para eviar a digitação de numero muito grande
    //   sendo assim PIB inferiores a um Milhão deverá ser informado como 0.xx (zero milhões e x mil reais)  


    // declaração de variavel para receber a opção do usuario na escolha do item a comparar
    int opcao;

    // Declaração das variaveis para o cadastro da primeira carta
    char estado1;               // 01 caracter para armazenar o Estado
    char codigo1[4];            // 04 caracteres para armazenar o código da carta 
    char nomecidade1[50];       // 50 caracteres para armazenar o nome da cidade
    unsigned long int populacao1;             // numero inteiro para armazenar o numero de habitantes
    float area1;                // um numero float (ponto flutuante) para armazenar a área em km2
    float pib1;                 // um numero float (ponto flutuante) para armazenar o PIB 
    int pontosturisticos1;      // um numero inteiro para armazenar a quantidade de pontos turisticos da cidade

    // inserido no nivel AVENTUREIRO
    float densidadedemografica1; // um numero float (ponto flutuante) para armazenar a qtd de habitantes por KM2
    float rendapercapta1;         // um numero float (ponto flutuante) pára armazenar o valor per capta 
    
    // inserido no nivel MESTRE
    float superpoder1;         // um float (ponto flutuante) para armazenar a soma (super poder) dos atributos numericos da cidade

    // Declaração das variaveis para o cadastro da segunda carta
    char estado2;                // 01 caracter para armazenar o Estado
    char codigo2[4];             // 04 caracteres para armazenar o código da carta 
    char nomecidade2[50];        // 50 caracteres para armazenar o nome da cidade
    unsigned long int populacao2;              // numero inteiro para armazenar o numero de habitantes
    float area2;                 // um numero float (ponto flutuante) para armazenar a área em km2
    float pib2;                  // um numero float (ponto flutuante) para armazenar o PIB 
    int pontosturisticos2;       // um numero inteiro para armazenar a quantidade de pontos turisticos da cidade

    // inserido no nivel AVENTUREIRO
    float densidadedemografica2;  // um numero float (ponto flutuante) para armazenar a qtd de habitantes por KM2
    float rendapercapta2;         // um numero float (ponto flutuante) pára armazenar o valor per capta 
    
    // inserido no nivel MESTRE
    float superpoder2;          // um numero float (ponto flutuante) para armazenar a soma (super poder) dos atributos numericos da cidade
    
    // inserido no nivel MESTRE
    int resultadopopulacao;              // numero inteiro para armazenar o resultado da comparação de população
    int resultadoarea;                   // numero inteiro para armazenar o resultado da comparação de area em km
    int resultadopib;                    // numero inteiro para armazenar o resultado da comparação de pib
    int resultadopontosturisticos;       // numero inteiro para armazenar o resultado da comparação de pontos turisticos
    int resultadodensidade;              // numero inteiro para armazenar o resultado da comparação de densidade demografica
    int resultadopercapta;               // numero inteiro para armazenar o resultado da comparação de renda per capta
    int resultadosuperpoder;             // numero inteiro para armazenar o resultado da comparação de super poder



    // Mensagem inicial para o usuário para explicar as regras de inserção de dados no que tange ao código da carta
    printf("Cadastre as duas cartas, inserindo os dados e pressionando ENTER\n");
    printf("Note que no código da carta a letra deverá ser a mesma informada para o campo Estado\n");
    printf("*(Usar ponto no lugar de vírgula na separação decimal)\n\n");

    // Entrada de dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf(" %s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomecidade1); 

    printf("Digite a População (nº de hab): ");
    scanf("%lu", &populacao1);

    printf("Digite a Área (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em milhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosturisticos1);

    // inserido no nivel AVENTUREIRO
    
    // o código a seguir foi inserido por orientação da tutoria visa evitar erro de divisão por zero  
    if (area1 != 0) {
        densidadedemografica1 = (float)populacao1 / area1;} 
    else            {    
        densidadedemografica1 = 1.0f; // Ou trate o erro de outra forma
        printf("Atenção: Área da Carta 1 é zero! Densidade foi atribuida por padrao como 1\n");
    } 

    // linha original densidadedemografica1 = (float) populacao1 / area1; // a densidade é a divisao da população pela area
    // a renda é a divisao do pib pela populacação. Multipliquei por 1 milhão por ser o indice usado na entrada dos dados (milhoes de Reais).
    // assim o valor apresentado no per capta corresponderá a Reais
    rendapercapta1 = (float) ((pib1 / populacao1) * 1000000);  
  
    // inserido no nivel MESTRE
    superpoder1 = (float)populacao1 + area1 + (pib1 * 1000000.0f) + pontosturisticos1 + rendapercapta1 + (1.0f / densidadedemografica1);

     // Exibição dos dados da Carta 1
    printf("\n\n Dados Informados\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomecidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.1f milhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosturisticos1);
    
    // inserido no nivel AVENTUREIRO
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadedemografica1);   
    printf("Renda Per Capta: %.2f Reais\n", rendapercapta1);   

    // inserido no nivel MESTRE
    printf("Super Poder: %.2f pontos\n\n", superpoder1);   

    // Entrada de dados da Carta 2
    printf("\n\n=== Cadastro da Carta 2 ===\n");           // Inicio com dois \n para separar os print de tela e evitar que muito "embolado"
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf(" %s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomecidade2); 

    printf("Digite a População (nº de hab): ");
    scanf("%lu", &populacao2);

    printf("Digite a Área (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em milhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosturisticos2);

    // inserido no nivel AVENTUREIRO
    
    // o código a seguir foi inserido por orientação da tutoria visa evitar erro de divisão por zero  
    if (area2 != 0) {
        densidadedemografica2 = (float)populacao2 / area2;} 
    else            {    
        densidadedemografica2 = 1.0f; // Ou trate o erro de outra forma
        printf("Atenção: Área da Carta 2 é zero! Densidade foi atribuida por padrao como 1\n");
    } 

    // linha original  - densidadedemografica2 = (float) populacao2 / area2; // a densidade é a divisao da população pela area
    
    // a renda é a divisao do pib pela populacação. Multipliquei por 1 milhão por ser o indice usado na entrada dos dados (milhoes de Reais).
    // assim o valor apresentado no per capta corresponderá a Reais
    rendapercapta2 = (float) ((pib2 / populacao2) * 1000000);  
  
    // inserido no nivel MESTRE
    superpoder2 = (float)populacao2 + area2 + (pib2 * 1000000.0f) + pontosturisticos2 + rendapercapta2 + (1.0f / densidadedemografica2);

    // Exibição dos dados da Carta 2
    printf("\n\n Dados Informados\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomecidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.1f milhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosturisticos2);   

    // inserido no nivel AVENTUREIRO
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadedemografica2);   
    printf("Renda Per Capta: %.2f Reais\n", rendapercapta2);   

    // inserido no nivel MESTRE
    printf("Super Poder: %.2f pontos\n", superpoder2);   
   


    /* ==========================================================
         COMPARAÇÃO INDIVIDUAL DE TODOS OS ATRIBUTOS NUMÉRICOS
       UTILIZANDO IF E ELSE SIMPLES. DESAFIO LOGICA SUPER TRUNFO
                       NÍVEL NOVATO  
       ==========================================================
      **** foi mantida aqui por até agora não haver sido enviada manifestação de correção de trabalho
    

    printf("\n\n=== COMPARAÇÃO INDIVIDUAL DOS ATRIBUTOS ===\n");

    // COMPARAÇÃO DE POPULAÇÃO
    printf("\n\nComparação de População:\n");
    printf("Carta 1 - %s: %lu habitantes\n", nomecidade1, populacao1);
    printf("Carta 2 - %s: %lu habitantes\n", nomecidade2, populacao2);
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else
        if (populacao2 > populacao1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE ÁREA
    printf("\n\nComparação de Área:\n");
    printf("Carta 1 - %s: %.2f km²\n", nomecidade1, area1);
    printf("Carta 2 - %s: %.2f km²\n", nomecidade2, area2);
    if (area1 > area2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else 
        if (area2 > area1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE PIB
    printf("\n\nComparação de PIB:\n");
    printf("Carta 1 - %s: %.2f milhões de reais\n", nomecidade1, pib1);
    printf("Carta 2 - %s: %.2f milhões de reais\n", nomecidade2, pib2);
    if (pib1 > pib2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else 
        if (pib2 > pib1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE PONTOS TURÍSTICOS
    printf("\n\nComparação de Pontos Turísticos:\n");
    printf("Carta 1 - %s: %d pontos\n", nomecidade1, pontosturisticos1);
    printf("Carta 2 - %s: %d pontos\n", nomecidade2, pontosturisticos2);
    if (pontosturisticos1 > pontosturisticos2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else 
        if (pontosturisticos2 > pontosturisticos1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE DENSIDADE DEMOGRÁFICA (MENOR VENCE)
    printf("\n\nComparação de Densidade Demográfica:\n");
    printf("Carta 1 - %s: %.2f hab/km²\n", nomecidade1, densidadedemografica1);
    printf("Carta 2 - %s: %.2f hab/km²\n", nomecidade2, densidadedemografica2);
    if (densidadedemografica1 < densidadedemografica2) {
        printf("Resultado: Carta 1 (%s) venceu! (MENOR densidade vence)\n", nomecidade1);
        } 
    else 
        if (densidadedemografica2 < densidadedemografica1) {
           printf("Resultado: Carta 2 (%s) venceu! (MENOR densidade vence)\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE RENDA PER CAPTA
    printf("\n\nComparação de Renda Per Capta:\n");
    printf("Carta 1 - %s: R$ %.2f\n", nomecidade1, rendapercapta1);
    printf("Carta 2 - %s: R$ %.2f\n", nomecidade2, rendapercapta2);
    if (rendapercapta1 > rendapercapta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else 
        if (rendapercapta2 > rendapercapta1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

    // COMPARAÇÃO DE SUPER PODER
    printf("\n\nComparação de Super Poder:\n");
    printf("Carta 1 - %s: %.2f pontos\n", nomecidade1, superpoder1);
    printf("Carta 2 - %s: %.2f pontos\n", nomecidade2, superpoder2);
    if (superpoder1 > superpoder2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
        } 
    else 
        if (superpoder2 > superpoder1) {
           printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
           } 
        else {
           printf("Resultado: Empate!\n");
        }

     printf("\n\n==== fim da execução ====\n");

   */
    

    /*
    ==========================================================
        NOVO BLOCO: INTERATIVIDADE COM MENU E SWITCH CASE
        DESAFIO SUPER TRUNFO - NÍVEL AVENTUREIRO
    ==========================================================
    */

    

    printf("\n\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha um atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (MENOR VENCE)\n");
    printf("6 - Renda Per Capta\n");
    printf("7 - Super Poder\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu habitantes\n", nomecidade1, populacao1);
            printf("%s: %lu habitantes\n", nomecidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km²\n", nomecidade1, area1);
            printf("%s: %.2f km²\n", nomecidade2, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2f milhões de reais\n", nomecidade1, pib1);
            printf("%s: %.2f milhões de reais\n", nomecidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Número de Pontos Turísticos:\n");
            printf("%s: %d pontos\n", nomecidade1, pontosturisticos1);
            printf("%s: %d pontos\n", nomecidade2, pontosturisticos2);
            if (pontosturisticos1 > pontosturisticos2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (pontosturisticos2 > pontosturisticos1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Densidade Demográfica (MENOR VENCE):\n");
            printf("%s: %.2f hab/km²\n", nomecidade1, densidadedemografica1);
            printf("%s: %.2f hab/km²\n", nomecidade2, densidadedemografica2);
            if (densidadedemografica1 < densidadedemografica2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (densidadedemografica2 < densidadedemografica1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6:
            printf("Renda Per Capta:\n");
            printf("%s: R$ %.2f\n", nomecidade1, rendapercapta1);
            printf("%s: R$ %.2f\n", nomecidade2, rendapercapta2);
            if (rendapercapta1 > rendapercapta2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (rendapercapta2 > rendapercapta1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 7:
            printf("Super Poder:\n");
            printf("%s: %.2f pontos\n", nomecidade1, superpoder1);
            printf("%s: %.2f pontos\n", nomecidade2, superpoder2);
            if (superpoder1 > superpoder2) {
                printf("Resultado: %s venceu!\n", nomecidade1);
            } else if (superpoder2 > superpoder1) {
                printf("Resultado: %s venceu!\n", nomecidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, selecione uma opção entre 1 e 7.\n");
            break;
    }

    printf("\n==== FIM DA COMPARAÇÃO INTERATIVA ====\n");
   
    return 0;
    
}
