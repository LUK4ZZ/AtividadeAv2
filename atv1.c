#include <stdio.h>

// Sub-algoritmo para validar a quantidade de peças fabricadas
int validaQuantidade(int quantidade) {
    return quantidade >= 0;
}

// Sub-algoritmo para calcular o salário total com base na quantidade de peças
float calculaSalario(int quantidade) {
    float adicional_produtividade = 0;

    if (quantidade > 50) {
        if (quantidade <= 80) {
            adicional_produtividade = (quantidade - 50) * 0.5;
        } else {
            adicional_produtividade = 30 * 0.5 + (quantidade - 80) * 0.75;
        }
    }

    float salario_total = 600 + adicional_produtividade;

    return salario_total;
}

// Sub-algoritmo para mostrar o resultado final
void mostraFinal() {
    int quantidade_funcionarios = 0;

    while (1) {
        int quantidade;

        printf("Quantas peças foram fabricadas? (digite -1 para sair): ");
        scanf("%d", &quantidade);

        if (quantidade == -1) {
            break;
        }

        if (validaQuantidade(quantidade)) {
            float salario = calculaSalario(quantidade);
            printf("O salário é: R$ %.2f\n", salario);
            quantidade_funcionarios++;
        } else {
            printf("Quantidade inválida!\n");
        }
    }

    printf("Total de funcionários processados: %d\n", quantidade_funcionarios);
}

int main() {
    mostraFinal();
    return 0;
}
