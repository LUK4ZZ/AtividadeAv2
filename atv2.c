#include <stdio.h>

typedef struct {
    char sexo;
    float salario;
    char* classificacao;
} Assalariado;

char validaSexo() {
    char sexo;
    do {
        printf("Diga o sexo (M ou F): ");
        scanf(" %c", &sexo);
        sexo = (sexo == 'm' || sexo == 'M') ? 'M' : ((sexo == 'f' || sexo == 'F') ? 'F' : '\0');
    } while (sexo != 'M' && sexo != 'F');
    return sexo;
}

float validaSalario() {
    float salario;
    do {
        printf("Digite o salário: R$ ");
        scanf("%f", &salario);
        if (salario <= 1) {
            printf("Salário inválido! O salário deve ser pelo menos maior que R$ 1,00.\n");
        }
    } while (salario <= 1);
    return salario;
}

char* classificaSalario(float salario) {
    if (salario > 1400) {
        return "Acima";
    } else if (salario < 1400) {
        return "Abaixo";
    } else {
        return "Igual";
    }
}

void mostraClassificacao(Assalariado assalariado) {
    printf("\nSexo: %s\n", assalariado.sexo == 'M' ? "Masculino" : "Feminino");
    printf("Salário: R$ %.2f\n", assalariado.salario);
    printf("Classificação: %s do salário mínimo\n", assalariado.classificacao);
}

int main() {
    int numAssalariados;
    int abaixoSalarioMinimo = 0;
    int acimaSalarioMinimo = 0;

    printf("Informe o número dos assalariados que vão ser cadastrados:\n");
    scanf("%d", &numAssalariados);

    Assalariado assalariados[numAssalariados];

    for (int i = 0; i < numAssalariados; i++) {
        printf("\nAssalariado %d:\n", i + 1);

        assalariados[i].sexo = validaSexo();
        assalariados[i].salario = validaSalario();
        assalariados[i].classificacao = classificaSalario(assalariados[i].salario);

        mostraClassificacao(assalariados[i]);

        if (assalariados[i].salario > 1400) {
            acimaSalarioMinimo++;
        } else if (assalariados[i].salario < 1400) {
            abaixoSalarioMinimo++;
        }
    }

    printf("\nResumo:\n");
    printf("Assalariados abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Assalariados acima do salário mínimo: %d\n", acimaSalarioMinimo);

    return 0;
}
