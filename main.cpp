#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    char palavra[30], letra[1], secreta[30];
    int tam, i, chances, acertos;
    bool acerto; // verifica se a letra digitada é certa ou não

    chances = 6;
    tam = 0;
    i = 0;
    acerto = false;
    acertos = 0;

    cout << "Fale para o seu amigo tampar os olhos e digite a palavra secreta: " << endl;
    cin >> palavra;
    system("cls");

    // Encontrando o tamanho da palavra
    while(palavra[i] != '\0'){ // '\0' é o flag de terminação da string
        i++;
        tam++;
    }

    for(i=0; i < tam; i++){
        secreta[i]='-';
    }

    // loop principal do jogo
    while((chances > 0) && (acertos < tam)){
        cout << "Chances restantes: " << chances << endl;
        cout << "Palavra secreta: ";
        for(i=0; i<tam; i++){
            cout << secreta[i];
        }
        cout << "\n\nDigite uma letra: ";
        cin >> letra[0];
        for(i=0; i<tam; i++){
            if(palavra[i] == letra[0]){
                acerto = true;
                secreta[i]=palavra[i];
                acertos++;
            }
        }
        // caso o jogador não acerte a letra é decrementado o numero de chances
        if(!acerto){
            cout << "A letra nao faz parte da palavra: " << letra[0] << endl;
            chances--;
        }
        acerto = false;
        system("cls");
    }

    if(acertos == tam){ // Jogador ganhou
        cout << "Voce venceu!!" << endl;
        cout <<"A palavra eh: " << palavra << endl;
    } else{
        cout << "Voce perdeu!!" << endl;
        cout << "A palavra secreta era: " << palavra << endl;
    }

    system("pause");
    return 0;
}
