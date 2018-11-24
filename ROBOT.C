#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
void tablero (void);
void materiales (void);
void ver_materiales(void);
void realizar_movimiento(void);
void instrucciones(void);
void estado (void);
void guardar_pasos(void);
void retroceder_pasos(void);
int fila_ini=19, columna_ini=9, inicio=0, vida=5, objeto=0, obj1=0, obj2=0, nro_pasos=0;
char entrada[1],salir[1];
int pasos_f[100], pasos_c[100];
char lab [20][20] =
       {'Ú', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', '¿',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', 'Ú', 'Ä', 'Ä', 'Ä', 'Ä', '¿', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³.', '.', '.', '.', '.','³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', 'À', 'Ä', 'Ä', 'Ä', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '.', 'Ú', 'Ä', 'Ä', 'Ä', 'Ä', '.', '.', '³',
	'³', '.', '.', '.', '³', '.', '.', '.', '.', 'Ä', 'Ä', 'Ä', 'Ù', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'À', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ù', 'ê', 'À', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ù'};

char mat [20][20] =
       {'Ú', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', '¿',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', 'Ú', 'Ä', 'Ä', 'Ä', 'Ä', '¿', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³.', '.', '.','.', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', 'À', 'Ä', 'Ä', 'Ä', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '³', '.', '.', '.', '.', '.', '.', '.', 'Ú', 'Ä', 'Ä', 'Ä', 'Ä', '.', '.', '³',
	'³', '.', '.', '.', '³', '.', '.', '.', '.', 'Ä', 'Ä', 'Ä', 'Ù', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'³', '.', '³', '.', '.', '.', '.', '.', '³', '.', '³', '.', '.', '.', '.', '.', '.', '.', '.', '³',
	'À', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ù', 'ê', 'À', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ä', 'Ù'};


void main(){
	clrscr();
	materiales();
	tablero();
	textcolor(YELLOW);
	instrucciones();
	estado();
	do{
	   textcolor(BLUE);
	   gotoxy (1,22);cprintf("Indique el camino a seguir:                              ");
	   gotoxy (29,22);cscanf("%c",&entrada[0]);
	   realizar_movimiento();
	}while(entrada[0]!='0');
	clrscr();
}

void instrucciones (){
   gotoxy (40,3);cprintf("R O B O T    E S P I A");
   gotoxy (40,4);cprintf("______________________");
   textcolor(GREEN);
   gotoxy (40,5);cprintf("    INSTRUCCIONES:");
   textcolor(WHITE);
   gotoxy (25,6);cprintf("Busca los objetos movientote sin chocar con las paredes:");
   gotoxy (25,8);cprintf("W ¢ w --> Arriba");
   gotoxy (25,9);cprintf("Z ¢ z --> Abajo");
   gotoxy (25,10);cprintf("D ¢ d --> Derecha");
   gotoxy (25,11);cprintf("A ¢ a --> Izquierda");
   gotoxy (25,12);cprintf("0 --> Salir");
}

void estado (){
   if(vida==0){
      textcolor(RED+BLINK);
      gotoxy (32,14);cprintf("­HAS FALLADO!");
      entrada[0]='0';
      gotoxy(25,16);
      gotoxy(80,25);scanf("%c",&salir);
   }
   if(nro_pasos==99){
      textcolor(RED+BLINK);
      gotoxy (48,16);cprintf("­HAS FALLADO!");
      gotoxy (48,17);cprintf("SE AGOTARON TUS PASOS");
      entrada[0]='0';
      gotoxy(25,16);
      gotoxy(80,25);scanf("%c",&salir);
   }
   if(objeto>=2){
      textcolor(GREEN+BLINK);
      gotoxy (32,14);cprintf("­HAS GANADO EL JUEGO!");
      entrada[0]='0';
      gotoxy(25,16);
      retroceder_pasos();
      gotoxy(1,21);system("pause");
   }
   textcolor(YELLOW);
   gotoxy (25,14);cprintf("VIDAS: ");
   gotoxy (25,15);cprintf("OBJETOS ENCONTRADOS: ");
   gotoxy (25,16);cprintf("NRO PASOS DISPONIBLES: ");
   textcolor(BLUE);
   if(vida<=2){
      textcolor(RED+BLINK);
   }
   gotoxy (32,14);cprintf("%d",vida);
   textcolor(BLUE);
   gotoxy (46,15);cprintf("%d", objeto);
   gotoxy (48,16);cprintf("%d    ", 100-nro_pasos);
   textcolor(WHITE);
}

void tablero (){
	int i, j;
	for(i=0;i<20;i++){
	   for(j=0;j<20;j++){
	      if(i==0 || i==19 || j==0 || j== 19){
		textcolor(BLUE);
	      }else{
		textcolor(WHITE);
	      }
	      if (lab[i][j]=='@' || lab[i][j]=='*'){
		textcolor(GREEN+BLINK);
	      }else{
		textcolor(WHITE);
	      }
	      gotoxy (j+1,i+1);cprintf("%c",lab[i][j]);
	   }
	}
}

void ver_materiales (){
	int i, j;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		  if(i==0 || i==19 || j==0 || j== 19){
		    textcolor(BLUE);
		  }else{
		    textcolor(WHITE);
		    if(mat[i][j]=='@' || mat[i][j]=='*'){
		       textcolor(RED+BLINK);
		    }else{
		       textcolor(WHITE);
		    }
		  }
		  cprintf("%c",mat[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

void materiales (){
	int f, c, k;
	k=0;
	do{
	  srand(time(NULL));
	  f =rand()%20;
	  c=rand()%20;
	  if(mat[f][c]!='Ä' && mat[f][c]!='³' && mat[f][c]!='À' && mat[f][c]!='Ù' && mat[f][c]!='¿' && mat[f][c]!='Ú' && mat[f][c]!='ê' && mat[f][c]!='@'){ // 234 robot
	      if(k==0){
		 mat[f][c]='@';
	      }
	      if(k==1){
		 mat[f][c]='*';
	      }
	      k++;
	  }
	}while(k < 2);
	ver_materiales();
}


void realizar_movimiento (){
   int longitud=1, i=0, f=0, c=0;
   for (i=0; i<=longitud-1; i++){
      f=fila_ini;
      c=columna_ini;
      //Movimiento hacia arriba
      if(entrada[i]=='W' || entrada[i]=='w'){
	 if(lab[f-1][c]!='Ä' && lab[f-1][c]!='³' && lab[f-1][c]!='À' && lab[f-1][c]!='Ù' && lab[f-1][c]!='¿' && lab[f-1][c]!='Ú') {
	   if(mat[f-1][c]=='@' && obj1==0){
	      objeto++;
	      lab[f-1][c]='@';
	      obj1++;
	      estado();
	   }else if(mat[f-1][c]=='*' && obj2==0){
	      objeto++;
	      lab[f-1][c]='*';
	      obj2++;
	      estado();
	   }else {
	      lab[f][c]='ð';  // 240
	      f--;
	      lab[f][c]= 'ê';
	   }
	   inicio=1;
	   tablero();
       //	   system("pause");
	 }else {
	    textcolor(RED+BLINK);
	    gotoxy(c+1,f);cprintf("%c",lab[f-1][c]);
	    textcolor(WHITE);
	    vida--;
	    i=longitud-1;
	    estado();
	 }
      }

      //Movimiento hacia abajo
      if(entrada[i]=='Z' || entrada[i]=='z'){
	 if(lab[f+1][c]!='Ä' && lab[f+1][c]!='³' && lab[f+1][c]!='À' && lab[f+1][c]!='Ù' && lab[f+1][c]!='¿' && lab[f+1][c]!='Ú') {
	   if(mat[f+1][c]=='@' && obj1==0){
	      objeto++;
	      lab[f+1][c]='@';
	      obj1++;
	      estado();
	   }else if(mat[f+1][c]=='*' && obj2==0){
	      objeto++;
	      lab[f+1][c]='*';
	      obj2++;
	      estado();
	   }else{
	      lab[f][c]='ð';  // 240
	      f++;
	      lab[f][c]= 'ê';
	   }
	      inicio=1;
	      tablero();
      //	   system("pause");
	 }else {
	 textcolor(RED+BLINK);
	 gotoxy(c+1,f+2);cprintf("%c",lab[f+1][c]);
	 textcolor(WHITE);
	  vida--;
	  i=longitud-1;
	  estado();
	 }
      }

      //Movimiento hacia la derecha
      if(entrada[i]=='D' || entrada[i]=='d'){
	 if(lab[f][c+1]!='Ä' && lab[f][c+1]!='³' && lab[f][c+1]!='À' && lab[f][c+1]!='Ù' && lab[f][c+1]!='¿' && lab[f][c+1]!='Ú') {
	   if(mat[f][c+1]=='@'&& obj1==0){
	      objeto++;
	      lab[f][c+1]='@';
	      obj1++;
	      estado();
	   }else if(mat[f][c+1]=='*'&& obj2==0){
	      objeto++;
	      lab[f][c+1]='*';
	      obj2++;
	      estado();
	   }else{
	      lab[f][c]='ð';  // 240
	      c++;
	      lab[f][c]= 'ê';
	   }
	   inicio=1;
	   tablero();
      //	   system("pause");
	 }else {
	  textcolor(RED+BLINK);
	  gotoxy(c+2,f+1);cprintf("%c",lab[f][c+1]);
	  textcolor(WHITE);
	  vida--;
	  i=longitud-1;
	  estado();
	 }
      }

      //Movimiento hacia la izquierda
      if(entrada[i]=='A' || entrada[i]=='a'){
	 if(lab[f][c-1]!='Ä' && lab[f][c-1]!='³' && lab[f][c-1]!='À' && lab[f][c-1]!='Ù' && lab[f][c-1]!='¿' && lab[f][c-1]!='Ú') {
	   if(mat[f][c-1]=='@' && obj1==0){
	      objeto++;
	      lab[f][c-1]='*';
	      obj1++;
	      estado();
	   }else if(mat[f][c-1]=='*'){
	      objeto++;
	      lab[f][c-1]='*';
	      obj2++;
	      estado();
	   }else{
	      lab[f][c]='ð';  // 240
	      c--;
	      lab[f][c]= 'ê';
	   }
	   inicio=1;
	   tablero();
     //	   system("pause");
	 }else {
	  textcolor(RED+BLINK);
	  gotoxy(c,f+1);cprintf("%c",lab[f][c-1]);
	  textcolor(WHITE);
	  vida--;
	  i=longitud-1;
	  estado();
	 }
      }
      fila_ini=f;
      columna_ini=c;
      guardar_pasos();
      estado();
   }
}


void guardar_pasos (){
   if(inicio==0){
     // Inicializar matriz de pasos
     int i=0;
     for(i=0; i<=199; i++) {
	pasos_f[i]=0;
	pasos_c[i]=0;
     }
   }
   pasos_f[nro_pasos]=fila_ini;
   pasos_c[nro_pasos]=columna_ini;
   nro_pasos++;
}

void retroceder_pasos(){
   int i,j;
   for(i=nro_pasos-1; i>=0; i--){
      if(pasos_f[i]!=0){
	 textcolor(MAGENTA+BLINK);
	 gotoxy(pasos_c[i]+1,pasos_f[i]+1); cprintf("ê");
	 gotoxy(1,21);system("pause");
	 textcolor(WHITE);
	 gotoxy(pasos_c[i]+1,pasos_f[i]+1);cprintf(".");
      }
   }
}





