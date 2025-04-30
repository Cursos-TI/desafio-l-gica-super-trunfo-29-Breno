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

    // Menu interativo para dois atributos
    int escolha1, escolha2;

    printf("\nEscolha o PRIMEIRO atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (Menor vence!)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);

    // Valida a primeira escolha
    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opcao invalida!\n");
        return 0;
    }

    // Menu dinâmico para segunda escolha
    printf("\nEscolha o SEGUNDO atributo para comparacao (diferente do primeiro):\n");

    if (escolha1 != 1) printf("1 - Populacao\n");
    if (escolha1 != 2) printf("2 - Area\n");
    if (escolha1 != 3) printf("3 - PIB\n");
    if (escolha1 != 4) printf("4 - Pontos Turisticos\n");
    if (escolha1 != 5) printf("5 - Densidade Demografica (Menor vence!)\n");

    printf("Escolha: ");
    scanf("%d", &escolha2);

    // Validação permanece igual
    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Opcao invalida ou repetida!\n");
        return 0;
    }

    // Função auxiliar para obter valor de atributo
    float obterValor(struct Pais p, int atributo, float densidade, float pibPerCapita) {
        switch (atributo) {
            case 1: return p.populacao;
            case 2: return p.area;
            case 3: return p.pib;
            case 4: return p.pontosTuristicos;
            case 5: return densidade; // Menor vence, A densidade não está no struct Pais, então ela precisa ser passada separadamente. Por isso, no case 5, retorna densidade
            default: return 0;
        }
    }

    // Obtem os valores para ambos atributos e países
    float Pais1Escolha1 = obterValor(pais1, escolha1, densidadePopulacional1, pibPerCapita1);
    float Pais2Escolha1 = obterValor(pais2, escolha1, densidadePopulacional2, pibPerCapita2);
    float Pais1Escolha2 = obterValor(pais1, escolha2, densidadePopulacional1, pibPerCapita1);
    float Pais2Escolha2 = obterValor(pais2, escolha2, densidadePopulacional2, pibPerCapita2);

    // Mostrar os valores
    printf("\n--- Comparando ---\n");
    printf("Pais 1: %s", pais1.estado);
    printf("Pais 2: %s", pais2.estado);

    // Função para imprimir nome do atributo
    char* nomeAtributo(int id) {
        switch(id) {
            case 1: return "Populacao";
            case 2: return "Area";
            case 3: return "PIB";
            case 4: return "Pontos Turisticos";
            case 5: return "Densidade Demografica";
            default: return "Desconhecido";
        }
    }

    printf("\nAtributo 1 - %s: %.2f (Pais 1) vs %.2f (Pais 2)\n", nomeAtributo(escolha1), Pais1Escolha1, Pais2Escolha1);
    printf("Atributo 2 - %s: %.2f (Pais 1) vs %.2f (Pais 2)\n", nomeAtributo(escolha2), Pais1Escolha2, Pais2Escolha2);

    // Comparação individual (informativa)
    int pontos1 = 0, pontos2 = 0;
    if (escolha1 == 5) {
        if (Pais1Escolha1 < Pais2Escolha1) pontos1++;
        else if (Pais1Escolha1 > Pais2Escolha1) pontos2++;
    } else {
        if (Pais1Escolha1 > Pais2Escolha1) pontos1++;
        else if (Pais1Escolha1 < Pais2Escolha1) pontos2++;
    }

    if (escolha2 == 5) {
        if (Pais1Escolha2 < Pais2Escolha2) pontos1++;
        else if (Pais1Escolha2 > Pais2Escolha2) pontos2++;
    } else {
        if (Pais1Escolha2 > Pais2Escolha2) pontos1++;
        else if (Pais1Escolha2 < Pais2Escolha2) pontos2++;
    }

    // Soma dos valores para decisão final
    float soma1 = Pais1Escolha1 + Pais1Escolha2;
    float soma2 = Pais2Escolha1 + Pais2Escolha2;

    printf("\n--- Resultado Final ---\n");
    printf("Soma dos Atributos - Pais 1: %.2f\n", soma1);
    printf("Soma dos Atributos - Pais 2: %.2f\n", soma2);

    if (soma1 > soma2)
        printf("Vencedor: Pais 1 (%s)\n", pais1.estado);
    else if (soma1 < soma2)
        printf("Vencedor: Pais 2 (%s)\n", pais2.estado);
    else
        printf("Empate!\n");

    return 0;
}
