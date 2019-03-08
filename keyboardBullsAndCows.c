/*
	Bulls and Cows game...
	
	Bulls and Cows (also known as Cows and Bulls or Pigs and Bulls or Bulls and Cleots) is an old code-breaking mind or paper and pencil game for two or more players, 
	predating the commercially marketed board game Mastermind.
	
	It is a game that may date back a century or more which uses numbers or words. It is played by two opponents.
	
	create by Leonardo Lopez Madrigal 
	github: @leoCloser 
	twitter: @leocloser

*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

char * keyboard(char *string, int secret);
int _strlen(char *string); 
int flagKeyExist(char *string, char tecla, int cant);
void printString(char *string);
void bullsAndCows(char *secreto, char *string); 

static unsigned int flag=0;
static unsigned int intentos=0;	

int main(void){
	char *string;
	char *secreto; 
	
	printf("BULLS and COWS GAME\n");
	printf("Written in C languaje \n");
	
	while(1){
		
		if( flag == 0){
			printf("JUEGO NUEVO\n\n");
			printf("Ingrese numero secreto: ");
			secreto = keyboard(secreto, 1);
			printf("\n");	
		}
	 
		//hacer esto en un ciclo de 8..... 
		if(intentos <= 8){
			flag=1;
			printf("Haga un intento: ");
			string = keyboard(string, 0);
			bullsAndCows(secreto, string);
			printf("Intentos= %d\n", intentos + 1);
			intentos++;
		} else {
			printf("---- Perdiste :( ----");
			intentos=0;
			flag=0;
			system("pause");
			system("cls");
		}
	}
	
	return 0;
}

void bullsAndCows(char secreto[4], char string[4])
{
	int bulls=0; 
	int cows=0; 
	int i=0, j=0;
	
	for(i=0; i<4; i++)
	{	
		for(j=0; j<4; j++)
		{	
			if( secreto[i] == string[j] )
			{
				if(i == j)
				{
					bulls++;
				} else {
					cows++;	
				}
			}
		}
	}
	
	printf("\nBulls= %d Cows= %d\n", bulls, cows);
	if( bulls == 4){
		printf("Ganaste ¡¡¡¡¡ Hurra !!!!!\n\n");
		intentos=0;
		flag=0;
		system("pause");
	}
	printf("\n");
}

char * keyboard(char *string, int secret)
{
	int i=0;
	char tecla;
	int flag=0; 
	
	string = (char *)malloc(sizeof( char ));
	
	do{
		tecla = getch();
		if( tecla >= '0' && tecla <= '9' )
		{
			if( flagKeyExist(string, tecla, i) )
			{	
				if( secret ){
					putchar('*');
					string[i++] = tecla;	
				} else {
					putchar(tecla);
					string[i++] = tecla;	
				}
			}
		}	
	}while(i < 4);
	string[i] = '\x0';
	return string;
}

int _strlen(char *string){
	int i=0;
	while( *string++ )
		i++;
	return i;
}

int flagKeyExist(char *string, char tecla, int cant)
{
	int i=0;
	int flag=0; 
	
	for(i=0; i< cant; i++)
	{
		if( string[i] == tecla)
		{
			return 0; //If exist return 0...
		}
	}
	return 1; //If not exist return 1...
}

void printString(char *string)
{
	int i=0;
	for(i=0; i<_strlen(string); i++)
	{
		printf("%c", string[i]);
	}
	printf("\n");
}
