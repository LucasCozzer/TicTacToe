#include <stdio.h>
#include <stdlib.h>

#define TAM 3 // definindo tamanho do tabuleiro
#define PLAYERX 'X' // definindo player X
#define PLAYERO 'O' // defininfo player O


//função stetica
int introgame();
// procedimentos
void inic_tab(char tabuleiro[][TAM]); // inicializando tabuleiro (matriz)
void most_tab(char tabuleiro[][TAM]); // mostrando o tabuleiro (Matriz)
int jogada(int jy, int jx, int player, char tabuleiro[TAM][TAM]); // registrando a jogada no tabuleiro
// funções
int vitoria(char tabuleiro[TAM][TAM]); // verificando se a vitoria
// main

int main (void) {

	char tabuleiro[TAM][TAM]; // tabuleiro do jogo
	int fimJogo = 0; // define se o jogo terminou se for diferente de 0
	int entrada_x, entrada_y; // declarando as variaveis de entrada do tabuleiro
	int playerJogada = 1; // declarando a variavel de player, caso for impar = player 1, caso for par = player 2
	inic_tab(tabuleiro); // inicializando o tabuleiro com o caractere '<ESPAÇO>'


	// game
	if (introgame() != 1) {
		fimJogo = 9;
		return 0;
	}

	do {
		system("clear");

		most_tab(tabuleiro);
		putchar('\n');
		printf("Digite o indice da jogada [y],[x]: ");
		scanf("%d %d", &entrada_y, &entrada_x);

		if(jogada(entrada_y, entrada_x, playerJogada, tabuleiro) == 1) {
			printf("\nDigite uma jogada válida!!\n");
			continue;
		}

		if (fimJogo >= 3) {
			if (vitoria(tabuleiro)) {

				system("clear");

				most_tab(tabuleiro);

				printf("\n(%c) GANHOU O JOGO\n", vitoria(tabuleiro) == 1 ? PLAYERX : PLAYERO);
				fimJogo = 9;
				return 0;
			}
		}

		fimJogo++;
		playerJogada++;

	} while (fimJogo < 9);

	printf("\nJOGO TERMINADO, NENHUM VENCEDOR\n");

	return 0;
}

int introgame() {

	int returngame;

	printf("____o__ __o____    o                    o                                  o                               \n");
	printf("/   \\   /   \\    _<|>_                 <|>                                <|>                              \n");
	printf("     \\o/                               < >                                < >                              \n");
	printf("      |            o        __o__       |         o__ __o/      __o__      |        o__ __o      o__  __o  \n");
	printf("     < >          <|>      />  \\        o__/_    /v     |      />  \\       o__/_   /v     v\\    /v      |> \n");
	printf("      |           / \\    o/             |       />     / \\   o/            |      />       <\\  />      //\n");
	printf("      o           \\o/    <|             |       \\      \\o/   <|            |      \\         /  \\o    o/    \n");
	printf("     <|            |      \\\\            o        o      |     \\\\           o       o       o    v\\\\  /v __o \n");
	printf("     / \\          / \\     _\\o__</      <\\__      <\\__  / \\    _\\o__</     <\\__     <\\__ __/>      <\\/> __/>\n\n");

	printf("\t\tBem vindo ao jogo da velha!\n\n");
	printf("\t\tTic Tac Toe é um jogo de tabuleiro simples para dois jogadores, onde um marca 'X' e o outro 'O' em uma grade 3x3. \n\t\tO objetivo é ser o primeiro a alinhar três de suas marcas, seja na horizontal, vertical ou diagonal. \n\t\tO jogo termina em vitória ou empate se todas as casas forem preenchidas sem vencedor.\n");

	printf("\nPor favor, digite 1 para iniciar ou 0 para encerrar: ");
	scanf("%d", &returngame);

	return returngame;

}

void inic_tab(char tabuleiro[][TAM]) {

	// percorrer matriz inicializando elementos
	for (int il = 0; il < TAM; il++) { // percorrendo a linha do tabuleiro (matriz)
		for (int ic = 0; ic < TAM; ic++){ // percorrendo as casas do tabuleiro (matriz)
			tabuleiro[il][ic] = ' '; // adicionando o caractere a cada casa do tabuleiro (matriz)
		}
	}
	return ; // retornando nada, pois é um void (nada)
}

void most_tab(char tabuleiro[][TAM]) {
	// percorrer matriz mostrando conteudo de cada linha
	for (int il = 0; il < TAM; il++) { // percorrendo a linha do tabuleiro (matriz)
		for (int ic = 0; ic < TAM; ic++) { // percorrendo a casa do tabuleiro (matriz)
			(ic != 1) ? printf(" %c ", tabuleiro[il][ic]) : printf("| %c |", tabuleiro[il][ic]); // mostrando cada elemento de cada casa
		}
		putchar('\n'); // escrevendo carater especial '\n' para pular de linha
		puts("-----------");
	}

	return ; // retornando nada, pois é um void (nada)
}

int jogada(int jy, int jx, int player, char tabuleiro[TAM][TAM]) {

	if (jy > 3 || jx > 3) return 1; // retorna nada, pois é um void (nada) finaliza a execução da função

	if (tabuleiro[jy - 1][jx - 1] != ' ') return 1; // retorna nada, pois é um void (nada) finaliza execução da função

	tabuleiro[jy - 1][jx - 1] = (player % 2 == 0) ? PLAYERO : PLAYERX; // verifica se é a vez do player conforme o número da variavel player
	/*
		se player for impar = 'X'
		se player for par = 'O'
	*/

	return 0; // retorna nada, pois é um void (nada)
}


int vitoria(char tabuleiro[TAM][TAM]) {

	// percorrendo o tabuleiro (matriz)
	for (int il = 0; il < TAM; il++) { // percorrendo as linhas do tabuleiro (matriz)

		if ((tabuleiro[il][0] == tabuleiro[il][1] && tabuleiro[il][0] == tabuleiro[il][2] && tabuleiro[il][0] != ' ') || (tabuleiro[0][il] == tabuleiro[1][il] && tabuleiro[0][il] == tabuleiro[2][il] && tabuleiro[0][il] != ' ')) {
			return (tabuleiro[il][0] == 'X' || tabuleiro[0][il] == 'X') ? 1 : 2;
		}

		if ((tabuleiro[il][0] == tabuleiro[1][1] && tabuleiro[il][0] == tabuleiro[2][2] && tabuleiro[il][0] != ' ') || (tabuleiro[il][2] == tabuleiro[1][1] && tabuleiro[il][2] == tabuleiro[2][0] && tabuleiro[il][2] != ' ')){
			return (tabuleiro[il][0] == 'X' || tabuleiro[il][2] == 'X') ? 1 : 2;
		}
	}

	return 0;
}