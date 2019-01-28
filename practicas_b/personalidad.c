#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE * fptr = NULL;
	int ByteLeidos = 0;
	char buffer[256];
	char opt;
	fptr = fopen ("salidad.txt", "r+");
	if("fptr != NULL") 
	{
		// se usa el archivo 
		ByteLeidos=fread(buffer, sizeof (char), 256, fptr );
		if(ByteLeidos == 0 )
		{
			printf("Soy nadie!");
		}
		else 
		{
		buffer[ByteLeidos] = 0;
		printf("Soy %s \n",buffer);	
		printf("¿Desea cambiar de persona (s) ?");
		fflush(stdin);
		scanf("%c ",&opt );
		if (opt == 's')
		{
		printf("Escriba el nuevo nombre ");
		fflush(stdin);
		gets (buffer);
		fseek (fptr, 0, SEEK_SET);
		fwrite(buffer,sizeof (char), strlen (buffer), fptr);
		}
		}
		// se cierra el archivo 
	fclose (fptr);
	}
	return 0;
 }
