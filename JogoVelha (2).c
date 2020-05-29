#include <stdio.h>
// Cria as variaveis dos jogadores e a variavel que armazena os X`s e O`s do jogo.
char j1[20],j2[20],game[3][3];
// Contador de jogadas.
int cont;
main() {
	// Reinicia o jogo ou Inicia.
	restartGame();

}
// Reiniciador ou iniciador de jogos.
restartGame() {
	// Limpa a tela.
	system("cls");
	// Variavel de contador para 0.
	cont=0;
	// Reseta o tabuleiro
	configGame();
	// Informacao dos jogadores 1 e 2
	printf("\n       Bem vindo ao jogo da velha");
	printf("\n       Vamos precisar dos nomes dos jogadores desta partida!");
	printf("\n       Jogador 1 (X): ");
	fflush(stdin);
	gets(j1);
	printf("       Jogador 2 (O): ");
	fflush(stdin);
	gets(j2);
	// Limpa a tela.
	system("cls");
	printf("\n       Nomes configurados!");
	printf("\n       Pressione qualquer tecla para iniciar a partida.");
	printf("\n\n       Boa sorte.\n\n\n\n\n");
	// Pausa o sistema.
	system("pause");
	// Imprime o tabuleiro
	printGame();
}
// Configura todas os caracteres do game[3][3] para vazio.
configGame() {
	int i,j;
	for(i=0;i!=3;i++){
		for(j=0;j!=3;j++) {
			game[i][j] = ' ';
		}
	}
}

// Imprime o tabuleiro
printGame() {
	// Cria a variavel que armazena a coluna e linha desejada.
	int col,lin;
	// Limpa a tela.
	system("cls");
	// cria uma variavel i para rodar no for.
	int i;
	// imprime o tabuleiro.
	for(i=0;i!=3;i++) {
		printf("\n      %c | %c | %c ",game[i][0],game[i][1],game[i][2]);
	}
	// Se o contador for numero par
	if(cont%2) {
		// Vez do jogador 2.
		printf("\n\n   Vez de %s",j2);
		printf("\n     Digite a coluna desejada: ");
		// Recebe a coluna desejada
		scanf("%d",&col);
		printf("\n     Digite a linha desejada: ");
		// Recebe a linha desejada.
		scanf("%d",&lin);
		// Checa se a linha e a coluna esta entre o intervalo de 1 - 3 e checa se o lugar escolhido esta vazio.
		if(col>0&&col<4&&lin>0&&lin<4&&game[lin-1][col-1]==' ') {
			// Seta a linha e coluna desejada para O.
			game[lin-1][col-1]='O';
			// Aumenta 1 no contador.
			cont++;
			// Checador de vitoria.
			checkWin();
			// Se a linha e a coluna nao esta entre 1 - 3 ou se o lugar estiver vazio.
		}else{
			
			printf("\n\n        Jogada invalida!\n\n");
			system("pause");
			printGame();
		}
		// Se o contador for numero par
	}else{
		// Vez do jogador 1.
		// Mesma coisa da explicacao acima tendo as mudancas so do X.
		printf("\n\n     Vez de %s",j1);
		printf("\n     Digite a coluna desejada: ");
		scanf("%d",&col);
		printf("\n     Digite a linha desejada: ");
		scanf("%d",&lin);
		if(col>0&&col<4&&lin>0&&lin<4&&game[lin-1][col-1]==' ') {
			game[lin-1][col-1]='X';
			cont++;
			checkWin();
		}else{
			printf("\n\n     Jogada invalida!\n\n");
			system("pause");
			printGame();
		}
	}

}
// Checador de win.
checkWin() {
	char l;
	// Condicoes de vitoria para o X.
	if((game[0][0]=='X' && game[0][1]=='X' && game[0][2] == 'X')
	|| (game[1][0]=='X' && game[1][1]=='X' && game[1][2] == 'X')
	|| (game[2][0]=='X' && game[2][1]=='X' && game[2][2]=='X')
	|| (game[0][0]=='X' && game[1][0]=='X' && game[2][0]=='X')
	|| (game[0][1]=='X' && game[1][1]=='X' && game[2][1]=='X')
	|| (game[0][2]=='X' && game[1][2]=='X' && game[2][2]=='X')
	|| (game[0][0]=='X' && game[1][1]=='X' && game[2][2]=='X')
	|| (game[0][2]=='X' && game[1][1]=='X' && game[2][0]=='X')) {
		// Se a condicao acima for verdadeira.
		// Limpar a tela.
			system("cls");
			// Jogador 1 ganhou.
			printf("\n     JOGADOR %s GANHOU!!!!!",j1);
			printf("\n        Jogar novamente? (s/n) ");
			// Reset.
			fflush(stdin);
			// Recebe o caracter de jogar novamente
			scanf("%c",&l);
			// Se o caracter for 's' reinicia o jogo.
			if(l=='s') {
			// Limpa a tela.
			system("cls");
			printf("\n\n        Reiniciando...");
			// Pausa o programa por 5 segundos.
			Sleep(5000);
			// Reinicia o jogo.
			restartGame();
		}else{
			// Caso o caracter nao for 's' encerrar o jogo.
			printf("\n        Ate logo!");
			// Encerrar programa.
			return 0;
		}
		// Mesma coisa da condicao de cima so que para o 'O'.
	} else 
	if((game[0][0]=='O' && game[0][1]=='O' && game[0][2] == 'O')
	|| (game[1][0]=='O' && game[1][1]=='O' && game[1][2] == 'O')
	|| (game[2][0]=='O' && game[2][1]=='O' && game[2][2]=='O')
	|| (game[0][0]=='O' && game[1][0]=='O' && game[2][0]=='O')
	|| (game[0][1]=='O' && game[1][1]=='O' && game[2][1]=='O')
	|| (game[0][2]=='O' && game[1][2]=='O' && game[2][2]=='O')
	|| (game[0][0]=='O' && game[1][1]=='O' && game[2][2]=='O')
	|| (game[0][2]=='O' && game[1][1]=='O' && game[2][0]=='O')) {
			system("cls");
			printf("\n     JOGADOR %s GANHOU!!!!!",j2);
			printf("\n        Jogar novamente? (s/n) ");
			fflush(stdin);
			scanf("%c",&l);
			if(l=='s') {
			system("cls");
			printf("\n\n        Reiniciando...");
			Sleep(5000);
			restartGame();
		}else{
			printf("\n        Ate logo!");
			return 0;
		}
	}
	
	// Caso o contador estiver em 9 (todas as jogadas possiveis foram gastas)
	
	if(cont==9) {
		// Avisar empate.
		// Limpa tela.
		system("cls");
		printf("\n\n        Jogo empatado!");
		printf("\n        Jogar novamente? (s/n) ");
		// Reset.
		fflush(stdin);
		scanf("%c",&l);
		// Se o caracter for 's' reinicia o jogo.
		if(l=='s') {
			system("cls");
			printf("\n\n        Reiniciando...");
			Sleep(5000);
			restartGame();
		}else{
			// Caso o caracter nao for 's' encerrar o jogo.
			printf("\n        Ate logo!");
		}
	}else{
		// Imprimir tabuleiro com o resultado novo.
		printGame();
	}
}
