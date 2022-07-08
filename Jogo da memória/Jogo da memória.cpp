#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int m1[4][4] = { 1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8 }, m2[4][4], rnd, m3[4][4] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, l1, l2, c1, c2, contV = 0, tV;
    srand(time(NULL));
    rnd = rand() % 3;

    int OpMenu;

    do //Menu do jogo, para apresentar os créditos e para dar início ou fim ao código.
    {
        cout << "Bem vindo ao jogo da memoria! Escolha uma das alternativas abaixo abaixo: \n1: Jogar \n2: Creditos \n3: Sair \n\nEscolha:  ";
        cin >> OpMenu;

        switch (OpMenu)
        {
        case 2:
        {
            cout << "\n\nCódigo feito por: \n-Gabriel Bosio\n-Eduardo Souza Cruz Accacio\n-Natan Porto Machado Da Silva\n-Leticia Paschk Alves\n\n";
            system("pause");
        }
        break;

        case 3:
        {
            cout << "\n\nJogo encerrado, feche a janela.";
            return 0;
        }
        break;
        default: OpMenu = 1; //Como padrão, caso o jogador digite outro numero fora do pedido, será tratado como 1.
        }
        system("cls");
    } while (OpMenu != 1);

    cout << "       C1 C2 C3 C4" << endl << endl //Apresentação da primeria matriz.
        << "L1     " << m1[0][0] << "  " << m1[0][1] << "  " << m1[0][2] << "  " << m1[0][3] << endl << endl
        << "L2     " << m1[1][0] << "  " << m1[1][1] << "  " << m1[1][2] << "  " << m1[1][3] << endl << endl
        << "L3     " << m1[2][0] << "  " << m1[2][1] << "  " << m1[2][2] << "  " << m1[2][3] << endl << endl
        << "L4     " << m1[3][0] << "  " << m1[3][1] << "  " << m1[3][2] << "  " << m1[3][3] << endl << endl;

    Sleep(3000);

    switch (rnd) //Definição aleatória de qual matriz será usada para o jogo.
    {
    case 0: //transposta
    {
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                m2[x][y] = m1[y][x];
            }
        }
    }
    break;

    case 1: //invertida por linha
    {
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                m2[x][y] = m1[3 - x][y];
            }
        }
    }
    break;

    case 2: //invertida pora coluna
    {
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                m2[x][y] = m1[x][3 - y];
            }
        }
    }
    break;
    }

    for (int n = 0; n < 24; n++) //Ínicio do looping de tentativas.
    {
        system("cls");

        cout << "       C1 C2 C3 C4" << endl << endl
            << "L1     " << m3[0][0] << "  " << m3[0][1] << "  " << m3[0][2] << "  " << m3[0][3] << endl << endl
            << "L2     " << m3[1][0] << "  " << m3[1][1] << "  " << m3[1][2] << "  " << m3[1][3] << endl << endl
            << "L3     " << m3[2][0] << "  " << m3[2][1] << "  " << m3[2][2] << "  " << m3[2][3] << endl << endl
            << "L4     " << m3[3][0] << "  " << m3[3][1] << "  " << m3[3][2] << "  " << m3[3][3] << endl << endl
            << "     \nJogadas feitas: " << n << endl
            << "     \nTentativas restantes: " << 24 - n << endl;


        cout << "\nLinha do numero 1: ";
        cin >> l1;
        cout << "\nColuna do numero 1: ";
        cin >> c1;
        cout << "\nLinha do numero 2: ";
        cin >> l2;
        cout << "\nColuna do numero 2: ";
        cin >> c2;

        if (c1 == c2 and l1 == l2) //Checagem caso a mesma cordenada seja digitada duas vezes.
        {
            cout << "\nMesma cordenada digitada, perda de tentativa.";
        }
        else if (m3[l1 - 1][c1 - 1] != 0 or m3[l2 - 1][c2 - 1] != 0) //Checagem caso a cordenada já tenha sido revelada e acertada anteriormente.
        {
            cout << "\nCordenada inutilizável escolhida, perda de tentativa.";
        }
        else //Para escolha válida.
        {
            m3[l1 - 1][c1 - 1] = m2[l1 - 1][c1 - 1];
            m3[l2 - 1][c2 - 1] = m2[l2 - 1][c2 - 1];

            system("cls");

            cout << "       C1 C2 C3 C4" << endl << endl
                << "L1     " << m3[0][0] << "  " << m3[0][1] << "  " << m3[0][2] << "  " << m3[0][3] << endl << endl
                << "L2     " << m3[1][0] << "  " << m3[1][1] << "  " << m3[1][2] << "  " << m3[1][3] << endl << endl
                << "L3     " << m3[2][0] << "  " << m3[2][1] << "  " << m3[2][2] << "  " << m3[2][3] << endl << endl
                << "L4     " << m3[3][0] << "  " << m3[3][1] << "  " << m3[3][2] << "  " << m3[3][3] << endl << endl
                << "     \nJogadas feitas: " << n << endl
                << "     \nTentativas restantes: " << 24 - n << endl;


            if (m3[l1 - 1][c1 - 1] != m3[l2 - 1][c2 - 1]) // Em caso de erro.
            {
                m3[l1 - 1][c1 - 1] = 0;
                m3[l2 - 1][c2 - 1] = 0;
                cout << "\nVoce errou";
            }

            else
            {
                cout << "\nVoce acertou!"; //Em caso de acerto, os numeros acertados serão somados.
                contV = contV + m3[l1 - 1][c1 - 1] + m3[l2 - 1][c2 - 1];
            }

            if (contV >= 72) //O jogo acabará quando a soma dos numeros acertados se igualar a soma total da matriz.
            {
                cout << "\n\nVocê ganhou!" << endl << endl << "Numero de tentativas: " << n << endl;
                return 0;
            }
        }

        Sleep(3000);



    }

    cout << "Game Over!" << endl << "Numero de tentativas expirou"; //O jogo acabará quando não ouver mais tentativas.

    return 0;
}
