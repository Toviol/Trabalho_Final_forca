#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("\t\t\t\t\t\t======================\n");
    printf("\t\t\t\t\t\t|    JOGO DA FORCA   | \n");
    printf("\t\t\t\t\t\t======================\n");
    char palavra[25];
    char letra;
    char erros[20];
    char tracos[50];
    int i, j, k, l, m = 0;
    int cont = 0, vidas = 6, tam=0;
    int contador = 0;
    // Reseta as variaveis do tipo "char". By GOOGLE.
    memset(&tracos, 0, sizeof(tracos));
    memset(&erros, 0, sizeof(erros));
    memset(&palavra, 0, sizeof(palavra));

    // Recebe a palavra.
    printf("\n\nEscolha a Palavra da Forca: ");
    gets(palavra);

    // Recebe a quantidade de caracteres da palavra inserida e substitue por _.
    for (i = 0; palavra[i] != '\0'; i++)
    {
        tracos[i] = '-';
    }
    tam=i;
    i = 0;
    // START THE GAME.
    while (vidas > 0)
    {
        // Limpa a Tela
        system("cls");

        // Layout
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t|    JOGO DA FORCA   | \n");
        printf("\t\t\t\t\t\t======================\n");

        // OS BONECÃO
        if (vidas == 6)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        if (vidas == 5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|               O\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        if (vidas == 4)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|               O\n");
            printf("\t|.|               |\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        if (vidas == 3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|               O\n");
            printf("\t|.|              /| \n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        if (vidas == 2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|               O\n");
            printf("\t|.|              /|\\ \n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        if (vidas == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\t___________________\n");
            printf("\t|__________________|\n");
            printf("\t|.|               |\n");
            printf("\t|.|               |\n");
            printf("\t|.|               O\n");
            printf("\t|.|              /|\\ \n");
            printf("\t|.|              / \n");
            printf("\t|.|\n");
            printf("\t|.|\n");
            printf("\t-----\n");
        }

        // Imprime a vida restante do player.
        printf("Vidas restantes: %d/6", vidas);

        int tamanho = strlen(erros);

        // Exibe os caracteres que a palavra não contém.
        printf("              Não contém: ");
        for (l = 0; l < tamanho; l++)
        {
            printf("%c, ", erros[l]);
        }
        printf("\n");
        // Imprime os _______...
        printf("                        %s", tracos);
        printf("\nTamanho:%d letra(s).\n\n", tam);
        printf("Insira uma letra %c: ", 1);
        scanf("%c", &letra);
        // Substitui os traços pela letra digitada
        for (j = 0; palavra[j] != '\0'; j++)
        {
            if (letra == palavra[j] || letra == '\n')
            {
                if (letra != '\n')
                {
                    tracos[j] = letra;
                }

                cont++;
            }
        }
        // Desconta uma vida
        if (cont == 0)
        {
            erros[i] = letra;
            vidas--;
            i++;
        }
        cont = 0;
        // Verifica se o vagabundo acertou ou não a palavra
        for (k = 0; k < strlen(palavra); k++)
        {

            if (palavra[k] == tracos[k])
            {
                contador++;
            }
            else
            {
                contador = 0;
                break;
            }
            system("cls");
            if (contador == strlen(palavra) + 1)
            {
                // BONECÃO GANHADOR
                if (vidas == 6)
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t      VOCÊ VENCEU!    \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }
                else if (vidas == 5)
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t      VOCÊ VeNCEU!    \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               O\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }
                else if (vidas == 4)
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t      VOCÊ vEnC3U!    \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               O\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }
                else if (vidas == 3)
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t      VOCÊ v3nC3U!    \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               O\n");
                        printf("\t\t\t\t\t\t|.|              /|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }
                else if (vidas == 2)
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t      V0cè v3nC3u     \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               O\n");
                        printf("\t\t\t\t\t\t|.|              /|\\ \n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }
                else
                {
                    while (m < 90)
                    {
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t  V0cè mor... v3nC3u  \n");
                        printf("\t\t\t\t\t\t======================\n");
                        printf("\t\t\t\t\t\t___________________\n");
                        printf("\t\t\t\t\t\t|__________________|\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               |\n");
                        printf("\t\t\t\t\t\t|.|               O\n");
                        printf("\t\t\t\t\t\t|.|              /|\\ \n");
                        printf("\t\t\t\t\t\t|.|              /\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t|.|\n");
                        printf("\t\t\t\t\t\t-----\n");
                        printf("\t\t\t\t\t\tVidas Restantes: %d/6", vidas);
                        printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
                        printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
                        Sleep(3000);
                        system("cls");
                        Sleep(750);

                        m++;
                    }
                }

                return 0;
            }
        }
    }
    system("cls");
    // BONECÃO PERDEDOR
    if (vidas == 0)
    {
        while (m < 90)
        {
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t======================\n");
            printf("\t\t\t\t\t\t      VOCÊ MORREU!    \n");
            printf("\t\t\t\t\t\t======================\n");
            printf("\t\t\t\t\t\t___________________\n");
            printf("\t\t\t\t\t\t|__________________|\n");
            printf("\t\t\t\t\t\t|.|               |\n");
            printf("\t\t\t\t\t\t|.|               |\n");
            printf("\t\t\t\t\t\t|.|               0\n");
            printf("\t\t\t\t\t\t|.|              /|\\ \n");
            printf("\t\t\t\t\t\t|.|              / \\ \n");
            printf("\t\t\t\t\t\t|.|\n");
            printf("\t\t\t\t\t\t|.|\n");
            printf("\t\t\t\t\t\t-----\n");
            printf("\t\t\t\t\t\tVidas Restantes: %c/6", 2);
            printf("\n\t\t\t\t\t\tA palavra era: %s", palavra);
            printf("\n\n\n\n\n\n\n\nDeveloped by: Tobias & Emanuel");
            Sleep(3000);
            system("cls");
            Sleep(750);

            m++;
        }
    }

    return 0;
}
