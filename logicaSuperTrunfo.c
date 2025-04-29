#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    // Criando as duas cartas (estruturas) para armazenar as informações dos países
    struct Pais {
        char estado[100]; // Aloca um espaço para a string
        char codigo[6]; // Aloca um espaço para a string
        char cidade[100]; // Aloca um espaço para a string
        int populacao;
        float area;
        float pib;
        int pontosTuristicos;
    };

    struct Pais pais1, pais2;

    // Coletando informações sobre o primeiro pais
    printf("Digite as informacoes para o primeiro Pais: \n");

    printf("digite o nome do estado: \n");
    fgets(pais1.estado, sizeof(pais1.estado), stdin);
    /* Lê uma linha de texto do usuário e armazena no campo 'estado' da estrutura 'pais1',
    Sizeof garante que o número de caracteres não ultrapasse o tamanho do array 'estado'*/

    printf("Digite a primeira letra do estado seguida de um numero de 01 a 04: \n");
    fgets(pais1.codigo, sizeof(pais1.codigo), stdin);

    printf("Digite o nome da cidade: \n");
    fgets(pais1.cidade, sizeof(pais1.cidade), stdin);

    printf("digite o numero de habitantes da cidade '.'Nao usar para separar centenas: \n");
    scanf("%d", &pais1.populacao);//Alterado para %lu devido ao tipo da variavel unsigned long int

    printf("Digite a area da cidade em KM quadrados '.'Nao usar para separar centenas:: \n");
    scanf("%f", &pais1.area);

    printf("digite o pib da cidade '.'Nao usar para separar centenas: \n");
    scanf("%f", &pais1.pib);

    printf("digite o numero de pontos Turisticos na cidade: \n");
    scanf("%d", &pais1.pontosTuristicos);

    printf("\n");

    getchar();  // Limpar o buffer de entrada após o scanf

    // Coletando informações sobre o segundo pais
    printf("Digite as informacoes para o Segundo Pais: \n");

    printf("digite o nome do estado: \n");
    fgets(pais2.estado, sizeof(pais2.estado), stdin);

    printf("Digite a primeira letra do estado seguida de um numero de 01 a 04: \n");
    fgets(pais2.codigo, sizeof(pais2.codigo), stdin);

    printf("Digite o nome da cidade: \n");
    fgets(pais2.cidade, sizeof(pais2.cidade), stdin);

    printf("digite o numero de habitantes da cidade '.'Nao usar para separar centenas: \n");
    scanf("%d", &pais2.populacao);//Alterado para %lu devido ao tipo da variavel unsigned long int

    printf("Digite a area da cidade em KM quadrados '.'Nao usar para separar centenas: \n");
    scanf("%f", &pais2.area);

    printf("digite o pib da cidade '.'Nao usar para separar centenas: \n");
    scanf("%f", &pais2.pib);

    printf("digite o numero de pontos Turisticos na cidade: \n");
    scanf("%d", &pais2.pontosTuristicos);

    // Variáveis para calcular a Densidade Populacional e PIB per Capita
    float densidadePopulacional1 = pais1.populacao / pais1.area;
    float pibPerCapita1 = pais1.pib / pais1.populacao;

    float densidadePopulacional2 = pais2.populacao / pais2.area;
    float pibPerCapita2 = pais2.pib / pais2.populacao;

    //Calcular "Super Poder" somando todos os atributos numéricos,incluindo inverso da densidade
    float superpoder1 = pais1.populacao + pais1.area + pais1.pib + pais1.pontosTuristicos
    + pibPerCapita1 + (1 / densidadePopulacional1);/* (1 / densidadePopulacional1) adiciona o
    inverso da densidade populacional ao Super Poder. Quanto quanto menor a densidade populacional,
    maior será o "Super Poder" do país.*/

    float superpoder2 = pais2.populacao + pais2.area + pais2.pib + pais2.pontosTuristicos
    + pibPerCapita1 + (1 / densidadePopulacional2);

    // Escolher um atributo para comparação
    int comparacao = 1;// 1 = População


    printf("\n"); // Linha em branco para separar as informações

    // Imprimindo informações sobre o primeiro pais
    printf("Informacoes do Primeiro Pais: \n\n");
    printf("Nome do Estado: %s", pais1.estado);
    printf("Codigo do Estado: %s", pais1.codigo);
    printf("Nome da Cidade: %s", pais1.cidade);
    printf("Numero de Habitantes da Cidade: %d \n", pais1.populacao);//Alterado para %lu
    printf("Tamanho da Area: %.2f \n", pais1.area);
    printf("Pib da Cidade: %.2f \n", pais1.pib);
    printf("Numero de Pontos Turisticos: %d \n", pais1.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes por km2 \n", densidadePopulacional1);
    printf("PIB per Capita: %.2f \n", pibPerCapita1);
    printf("Super Poder 1: %.2f \n\n",superpoder1);

    // Imprimindo informações sobre o segundo pais
    printf("Informacoes do Segundo Pais: \n\n");
    printf("Nome do Estado: %s", pais2.estado);
    printf("Codigo do Estado: %s", pais2.codigo);
    printf("Nome da Cidade: %s", pais2.cidade);
    printf("Numero de Habitantes da Cidade: %d \n", pais2.populacao);//Alterado para %lu
    printf("Tamanho da Area: %.2f \n", pais2.area);
    printf("Pib da Cidade: %2.f \n", pais2.pib);
    printf("Numero de Pontos Turisticos: %d \n", pais2.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes por km2 \n", densidadePopulacional2);
    printf("PIB per Capita: %.2f \n", pibPerCapita2);
    printf("Super Poder 2: %.2f \n",superpoder2);

    // Menu Interativo
    int escolha;
    printf("\nEscolha o atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (Menor vence!)\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    printf("\n--- Comparando ---\n");
    printf("Pais 1: %s", pais1.estado);
    printf("Pais 2: %s ", pais2.estado);

    switch (escolha) {
        case 1:
            printf("Populacao - Pais 1: %d, Pais 2: %d\n", pais1.populacao, pais2.populacao);
            if (pais1.populacao > pais2.populacao)
                printf("Resultado: Pais 1 venceu!\n");
            else if (pais1.populacao < pais2.populacao)
                printf("Resultado: Pais 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Area - Pais 1: %.2f, Pais 2: %.2f\n", pais1.area, pais2.area);
            if (pais1.area > pais2.area)
                printf("Resultado: Pais 1 venceu!\n");
            else if (pais1.area < pais2.area)
                printf("Resultado: Pais 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("PIB - Pais 1: %.2f, Pais 2: %.2f\n", pais1.pib, pais2.pib);
            if (pais1.pib > pais2.pib)
                printf("Resultado: Pais 1 venceu!\n");
            else if (pais1.pib < pais2.pib)
                printf("Resultado: Pais 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Pontos Turisticos - Pais 1: %d, Pais 2: %d\n", pais1.pontosTuristicos, pais2.pontosTuristicos);
            if (pais1.pontosTuristicos > pais2.pontosTuristicos)
                printf("Resultado: Pais 1 venceu!\n");
            else if (pais1.pontosTuristicos < pais2.pontosTuristicos)
                printf("Resultado: Pais 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Densidade Demografica - Pais 1: %.2f, Pais 2: %.2f\n", densidadePopulacional1, densidadePopulacional2);
            if (densidadePopulacional1 < densidadePopulacional2)
                printf("Resultado: Pais 1 venceu! (Menor densidade)\n");
            else if (densidadePopulacional1 > densidadePopulacional2)
                printf("Resultado: Pais 2 venceu! (Menor densidade)\n");
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
