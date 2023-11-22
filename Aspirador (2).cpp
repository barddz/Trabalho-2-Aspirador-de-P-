// Pedro Barddal da Silva - RA: 21007988

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int num_salas, num_sujeiras;
    char modo;

    cout << "Digite o numero de salas (1-10): ";
    cin >> num_salas;

    cout << "Digite o numero de sujeiras: ";
    cin >> num_sujeiras;

    cout << "Digite 'o' para ambiente observavel ou outro caractere para parcialmente observavel: ";
    cin >> modo;

    vector<char> salas(num_salas, '?');
    vector<bool> visitadas(num_salas, false);
    for (int i = 0; i < num_sujeiras; ++i)
    {
        salas[rand() % num_salas] = 'x';
    }

    int pos_aspirador = rand() % num_salas;
    char comando;

    if (modo == 'o')
    {
        for (int i = 0; num_salas > i; i++)
            visitadas[i] = true;
    }
    do
    {
        cout << '\n';
        cout << "SALA      | ";

        for (int i = 0; i < num_salas; ++i)
        {
            char c = 65 + i;
            cout << c << ' ';
        }

        cout << '\n';
        cout << "Aspirador | ";

        for (int i = 0; i < num_salas; ++i)
        {
            cout << (i == pos_aspirador ? 'x' : ' ') << ' ';
        }

        cout << '\n';
        cout << "Sujeira   | ";

        for (int i = 0; i < num_salas; ++i)
        {
            if (i == pos_aspirador || visitadas[i])
            {
                cout << (salas[i] == 'x' ? 'x' : ' ') << ' ';
            }
            else
            {
                cout << '?' << ' ';
            }
        }
        cout << '\n';
        cout << '\n';

        if (salas[pos_aspirador] == 'x')
        {
            cout << "Aspirador limpou a sala " << pos_aspirador + 1 << '\n'
                 << '\n';
        }
        salas[pos_aspirador] = ' ';
        visitadas[pos_aspirador] = true;

        cout << "Digite '1' para mover para a esquerda, '2' para mover para a direita: ";
        cin >> comando;
        if (comando == '1' && pos_aspirador > 0)
        {
            --pos_aspirador;
        }
        else if (comando == '2' && pos_aspirador < num_salas - 1)
        {
            ++pos_aspirador;
        }

    } while (comando == '1' || comando == '2');
    return 0;
}