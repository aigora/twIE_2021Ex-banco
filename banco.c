#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//PROTOTIPO DE LAS FUNCIONES
void menu();
void cambio(char a[]);
void altaCliente();
void altaCuenta();
void consultaCliente();
void consultaC();
void ingreso();
void retiro();
void pago();
void transferencia();
void transferenciaDestino(char idDestino[10], float nSaldo);
void intereses();
void reporte();
void movimientof(char idCuenta[10], char idCliente[10],char tipo[1], float cargo);
char fecha();

//ESTRUCTURA CLIENTE Y SUS RESPECTIVAS VARIABLES
typedef struct
{
	char idCliente[10];
	char Nombre[50];
	char Ciudad[25];
	char Direccion[25];
	char Edad[15];
	char Telefono[20];
}cliente;


//ESTRUCTURA CUENTA Y SUS RESPECTIVAS VARIABLES
typedef struct
{
	char IdCuenta[10];
	char IdCliente[10];
	int nif;
	int nTipoCuenta;
	float nSaldo;
	float nLimiteCredito;
}cuenta;


//ESTRUCTURA MOVIMIENTO Y SUS RESPECTIVAS VARIABLES
typedef struct
{
	char IdCuenta[10];
	char IdCliente[10];
	char idTipoMov[1];
	char Descripcion[25];
	float cargo;
	char dFecha[100];
}movimiento;


//FUNCION PRINCIPAL MAIN: EN ESTA FUNCION PRINCIPAL SE LLAMAN A LAS DEMAS FUNCIONES
int main(){

	menu();
	return 0;
}


//FUNCION MENU: IMPRIME LAS OPCIONES DEL MENU PRINCIPAL POR PANTALLA, Y PERMITE QUE EL USUARIO ELIJA UNA OPCIÓN
void menu(){
	system("cls");
	char op,op2;
	do{
		system("cls");
		printf("\n                               SISTEMA BANCARIO\n\n");
		printf(" MENU PRINCIPAL\n\n");
		printf(" 1. Clientes\n");
		printf(" 2. Cuentas\n");
		printf(" 3. Ingresos/Retiros\n");
		printf(" 4. Pagos\n");
		printf(" 5. Transferencia\n");
		printf(" 6. Inversion\n");
		printf(" 7. Estado de Cuenta\n");
		printf(" 8. Salir\n\n");
		printf(" Ingrese opcion: ");
		scanf("%s",&op);
		
		if(op!='1' && op!='2' && op!='3' && op!='4' && op!='5' && op!='6' && op!='7' && op!='8'){
			printf(" Error al ingresar valores. Presione una tecla para volver a ingresar..");
			getch();
		}
			
	}while(op!='1' && op!='2' && op!='3' && op!='4' && op!='5' && op!='6' && op!='7' && op!='8'); 
	
	
	if (op=='1'){
			do{
				system("cls");
				printf("\n                               SISTEMA BANCARIO\n\n");
				printf(" CLIENTES\n\n");
				printf(" 1. Registro\n");
				printf(" 2. Consulta\n");
				printf(" 3. Regresar al menu principal\n\n");
				printf(" Ingrese opcion: ");
				scanf("%s",&op2);
				
				if(op2!='1' && op2!='2' && op2!='3' && op2!='4'){
					printf("");
					printf(" Error al ingresar valores. Presione una tecla para volver a ingresar..");
					getch();
				}
			
			}while(op2!='1' && op2!='2' && op2!='3' && op2!='4');
		
		if (op2=='1') altaCliente();   //AQUÍ SE LLAMA A LA FUNCION ALTA CLIENTES
		if (op2=='2') consultaCliente();     //AQUÍ SE LLAMA A LA FUNCION CONSULTA CLIENTES
		if (op2=='3'){
			system("cls");
			menu();
		}
		
	}	
	
	
	if (op=='2'){
			do{
				system("cls");
				printf("\n                               SISTEMA BANCARIO\n\n");
				printf(" CUENTAS\n\n");
				printf(" 1. Registro\n");
				printf(" 2. Consulta\n");
				printf(" 3. Regresar al menu principal\n\n");
				printf(" Ingrese opcion: ");
				scanf("%s",&op2);
				
				if(op2!='1' && op2!='2' && op2!='3' && op2!='4'){
					printf("");
					printf(" Error al ingresar valores. Presione una tecla para volver a ingresar..");
					getch();
				}
			
			}while(op2!='1' && op2!='2' && op2!='3' && op2!='4');
		
		if (op2=='1') altaCuenta();   //AQUÍ SE LLAMA A LA FUNCOON ALTA CUENTA
		if (op2=='2') consultaC();    
		if (op2=='3'){
			system("cls");
			menu();
		}

	}
	
	if (op=='3'){
			system("cls");
			do{
				printf("\n                               SISTEMA BANCARIO\n\n");
				printf(" INGRESO / RETIRO\n\n");
				printf(" 1. Ingreso\n");
				printf(" 2. Retiro\n");
				printf(" 3. Regresar al menu principal\n\n");
				printf(" Ingrese opcion: ");
				scanf("%s",&op2);
				
				if(op2!='1' && op2!='2' && op2!='3'){
					printf("");
					printf(" Error al ingresar valores. Presione una tecla para volver a ingresar..");
					getch();
					system("cls");
				}
			
			}while(op2!='1' && op2!='2' && op2!='3');
		
		if (op2=='1') ingreso();   //AQUÍ SE LLAMA A LA FUNCION INGRESO
		if (op2=='2') retiro();   //AQUÍ SE LLAMA A LA FUNCION RETIRO
		if (op2=='3'){
			system("cls");
			menu();
		}

	}
	
	if (op=='4') pago();
	if (op=='5') transferencia();
	if (op=='6') intereses();
	if (op=='7') reporte();
	if (op=='8')
		exit(0);
	
}

//FUNCION ALTA CLIENTE, ESTA FUNCION PERIMTE REGISTRAR LOS DATOS DE LOS CLIENTES
void altaCliente(){
	FILE *pa, *pa2;                                              //AQUI SE CREAN 2 VARIABLEs DE TIPO PUNTERO CON EL NOMBRE PA Y PA2. ES DECIR, UNA VARIABLE PARA CADA FICHERO..
	char r;                                                      //..LAS CUALES VAN A CONTENER LA DIRECCION FISICA DE LOS FICHEROS UTILIZADOS
	cliente nuevo, lista[50];                                      //AQUÍ SE CREAN DOS VARIABLES DE TIPO CLIENTE, UNO ES NUEVO Y EL OTRO ES UN VECTOR LLAMADO LISTA..
	system("cls");                                                   //..LA VARIABLE NUEVO NOS PERMITIRÁ ALMACENAR LOS DATOS EN LAS VARIABLES DE LA ESTRUCTURA, PARA LUEGO GUARDARLOS EN EL FICHERO, MÁS ABAJO SE INDICE LA LINEA DONDE SE GUARDAN.
	if (((pa = fopen("Archivo Binario","a+b"))==NULL) || ((pa2 = fopen("Clientes","a+b"))==NULL))         //FUNCION FOPEN: PERMITE CREAR Y/O ABRIR UN FICHERO, SE CREAN 2 FICHEROS, UNO BINARIO  USADO PARA LAS BUSQUEDAS Y EL OTRO DE TEXTO , QUE PERMITE LEER LOS CARACTERES DEL TECLADO NORMAL
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                             //CON ESTE WHILE, SE VA A RECORRER TODO EL FICHERO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL RETORNA UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR A LLEGADO AL FINAL DEL FICHERO
	{ if(fread(&nuevo, sizeof(cliente), 1, pa)){                   //LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS EN EL FICHERO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL VECTOR CUANTOS ELEMENTOS TENDRÁ
		lista[i]=nuevo;                                          //TODA LA INFORMACION ALMACENADA EN NUEVO SE GUARDARA EN EL VECTOR LISTA..
		i++;}                                                    //.. ESTO SE HACE PARA LUEGO COMPARAR
	}

	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" REGISTRO DE CLIENTE\n\n");
	printf(" Id Cliente:    ");
		res=i;
		do{
			gets(nuevo.idCliente);
			
			
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].idCliente,nuevo.idCliente)==0) encontro=0;              //COMPARA EL ID CLIENTE INGRESADO POR TECLADO , CON LOS ID CLIENTES QUE ESTAN EN EL VECTOR LISTA
				else i++;
			}
			
			//SI SE ENCUENTRA EL ID, SE MUESTRA MENSAJE DE QUE YA EXISTE Y SE DEBE INGRESAR OTRO
			if (i<=ultimo){
				printf("\n ID Cliente ya registrado!\n Presione una tecla para ingresar otro ID..");
				getch();
				system("cls");
				printf("\n                               SISTEMA BANCARIO\n\n");
				printf(" REGISTRO DE CLIENTE\n\n");
				printf(" Id Cliente:    ");
			}
		}
		while(i<=ultimo);

	//IMPRIME EN PANTALLA Y SE INGRESAN LOS DATOS
	
	printf(" Nombre:        "); gets(nuevo.Nombre);
	printf(" Ciudad:        "); gets(nuevo.Ciudad);
	printf(" Direccion:     "); gets(nuevo.Direccion);
	printf(" Edad:          "); gets(nuevo.Edad);
	printf(" Telefono:      "); gets(nuevo.Telefono);

	
	// CON ESTE DO WHILE SE CONFIRMA EL REGISTRO DEL CLIENTE, SE DEBE PRESIONAR S PARA CONFIRMAR , N PARA CANCELAR
	do{
		printf("\n");
		printf(" Confirmar Registro de Cliente: Si[s] / No [n]: "); 
		r=getch();
	}while(r!='S' && r!='s' && r!='N' && r!='n');
	
	
	if (r=='s' || r=='S') {
		fwrite(&nuevo, sizeof(cliente),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FIHCERO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
		fprintf(pa2, "%s %s %s %s %s %s\n", nuevo.idCliente, nuevo.Nombre, nuevo.Ciudad, nuevo.Direccion, nuevo.Edad, nuevo.Telefono);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO CLIENTES, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
		printf("\n");
		printf("\n Cliente Registrado Correctamente\n"); 
		printf(" Presione una tecla para volver al menu principal..");
	}
	
	else {
		printf("\n\n Cliente NO Registrado\n"); 
		printf(" Presione una tecla para volver al menu principal..");
	}
	
	fclose(pa);
	fclose(pa2);
	getch();
	system("cls");
	menu();
}


//FUNCION CONSULTAR CLIENTE, PERMITE REALIZAR LA CONSULTA DE LOS DATOS DEL CLIENTE, PARA LO CUAL SE DEBE INGRESAR EL NOMBRE DEL CLIENTE
void consultaCliente(){
	system("cls");
	cliente nuevo, lista[50];
	char nombre[50];
	int encontro=1,linea,i,ultimo;
	FILE *pa;
	if ((pa = fopen("Archivo Binario", "a+b"))== NULL){ 
		printf("No se puede abrir el archivo.\n");
		return;
	}
	rewind(pa); i=0;
	while(!feof(pa))
	{ 
		if(fread(&nuevo, sizeof(cliente), 1, pa)){
			lista[i]=nuevo;
		 	i++;
		}
	}
	
	fclose(pa);
 
  	fflush(stdin);
  	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" CONSULTA DE CLIENTES\n\n");
  	printf(" Ingrese Nombre del Cliente: ");gets(nombre);
  	ultimo=i-1;
  	i=0;
  	
  	//PROCESO DE BUSQUEDA DEL NOMBRE DEL CLIENTE
  	while (i<=ultimo && encontro)
  	{ 
	  	if (strcmp(lista[i].Nombre,nombre)==0) encontro=0; //COMPARA SI EL NOMBRE INGRESADO POR TECLADO, ES IGUAL AL NOMBRE QUE ESTA EN EL VECTOR LISTA
    	else 
			i++;
  	}
  	
  	//IMPRIME LOS DATOS DEL CLIENTE
  	if (i<=ultimo)
 	{
 		system("cls");
	    printf("\n                               SISTEMA BANCARIO\n\n");
		printf(" CONSULTA DE CLIENTES\n\n");
	    printf(" Id Cliente:   %s\n",lista[i].idCliente);
	    printf(" Nombres:      %s\n",lista[i].Nombre);
	    printf(" Ciudad:       %s\n",lista[i].Ciudad);
	    printf(" Direccion:    %s\n",lista[i].Direccion);
	    printf(" Edad:         %s\n",lista[i].Edad);
	    printf(" Telefono:     %s\n",lista[i].Telefono);

	    printf("\n Presione una tecla para volver al menu principal...");
		getch();
		system("cls");
		menu();
  	}
  	
  	else
  	{ 
		printf(" Cliente NO registrado. Presione una tecla para volver... ");
		getch();
		system("cls");
		menu();
  	}
}


//FUNCION ALTA CUENTA, PERMITE DAR DE ALTA A UNA CUENTA, PARA CREAR UNA CUENTA SE DEBE INGRESAR ID DE UN CLIENTE REGISTRADO ANTERIORMENTE 
void altaCuenta(){
	FILE *pa, *pa2;                                                                                      //AQUI SE CREAN 2 VARIABLES DE TIPO PUNTERO CON EL NOMBRE PA Y PA2. ES DECIR, UNA VARIABLE PARA CADA FICHERO..
	char r;  
	float valor;                                                                                         //..LA CUEAL VA A CONTENER LA DIRECCION FISICA DE LOS FICHEROS UTILIZADOS
	cuenta nuevo, lista[50];                                                                             //AQUÍ SE CREAN DOS VARIABLES DE TIPPO ESTRUCTURA CUENTA, UNO ES NUEVO Y EL OTRO ES UN VECTOR LLAMADO LISTA..
	system("cls");                                                                                       //..LA VARIABLE NUEVO NOS PERMITERÁ ALMACENAR LOS DATOS EN LAS VARIABLES, PARA LUEGO GUARDARLOS EN EL FICHERO, MÁS ABAJO SE INDICA LA LINEA DONDE SE GUARDAN.
	if (((pa = fopen("Archivo Binario 2","a+b"))==NULL) || ((pa2 = fopen("Cuentas","a+b"))==NULL))       //FUNCION FOPEN: PERMITE CREAR Y/O ABRIR UN FICHERO, SE CREAN 2 FICHEROS, UNO BINARIO Y EL OTRO DE TEXTO , EL DE TEXTO PERMITE LEER LOS CARACTERES DEL TECLADO NORMAL
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                             //CON ESTE WHILE, SE VA A RECORRER TODO EL FICHERO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL RETORNA UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR A LLEGADO AL FINAL DEL FICHERO
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                  //LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS EN EL FICHERO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL VECTOR CUANTAS POSICIONES TENDRÁ
		lista[i]=nuevo;                                          //TODA LA INFORMACION ALMACENADA EN NUEVO SE GUARDARA EN EL VECTOR..
		i++;}                                                    //.. ESTO SE HACE PARA LUEGO COMPARAR
	}

	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" ALTA DE CUENTA\n\n");
	printf(" Id Cuenta:                 ");
		res=i;
		do{
			gets(nuevo.IdCuenta);
			
			//PROCESO DE BUSQUEDA DEL ID DEL CLIENTE
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,nuevo.IdCuenta)==0) encontro=0;              //COMPARA EL ID CLIENTE INGRESADO POR TECLADO , CON LOS ID QUE ESTAN EN LOS FICHEROS
				else i++;
			}
			if (i<=ultimo){
				printf("\n ID Cuenta ya registrado!\n Presione una tecla para ingresar otro ID..");
				getch();
				system("cls");
				printf("\n                               SISTEMA BANCARIO\n\n");
				printf(" ALTA DE CUENTA\n\n");
				printf(" Id Cuenta:                 ");
			}
		}while(i<=ultimo);
	
	
	char IDCliente[10];
	printf(" Id Cliente:                "); 
	gets(IDCliente);
	
	//SE CREAN DOS PUNTEROS, PARA PODER ABRIR EL FICHERO CLIENTES, CON ESTE FICHERO VAMOS A COMPROBAR QUE EL CLIENTE ESTA REGISTRADO.
	FILE *pa3, *pa4;
  	cliente nuevoc, listac[50];
  	if (((pa3 = fopen("Archivo Binario", "a+b"))== NULL) || ((pa4 = fopen("Clientes", "a+b"))== NULL))
  	{ printf("No se puede abrir el archivo.\n");
  		return ;
  	}
  	
	rewind(pa3); i=0;
  	while(!feof(pa3))
  	{ if(fread(&nuevoc, sizeof(cliente), 1, pa3)){
		listac[i]=nuevoc;
		i++;
	 	}
  	}
  	
  	encontro=1;
  	ultimo=i-1;
  	i=0;
  
  	while (i<=ultimo && encontro){ 
		if (strcmp(listac[i].idCliente,IDCliente)==0)               //SE COMPARA QUE ID DEL CLIENTE INGRESADO POR TECLADO SEA IGUAL A UNOS DE LOS ID QUE ESTAN EL EL FICHERO
	  		encontro=0;
    	else 
			i++;
  	}
  	
  	// SI EXISTEN ID IGUALES , SE PROCEDE A A SEGUIR LLENANDO CAMPOS
  	if (i<=ultimo){
  		strcpy(nuevo.IdCliente,IDCliente);
  		printf(" NIF(solo numeros, sin letra/s):                       "); scanf("%i",&nuevo.nif);
		do{
			printf(" N Tipo de Cuenta (1.- Credito\t2.- Debito):          "); scanf("%i",&nuevo.nTipoCuenta);
		}while(nuevo.nTipoCuenta<1 || nuevo.nTipoCuenta>2);
		
		if(nuevo.nTipoCuenta==1){
			nuevo.nLimiteCredito = 30000.00;
		}
		
		printf(" Saldo:                     $"); scanf("%f",&nuevo.nSaldo);
		valor = nuevo.nSaldo;
		fflush(stdin);
		do{
			printf("\n");
			printf(" Confirmar Registro de Cuentas: Si[s] / No [n]: "); 
			r=getch();
		}while(r!='S' && r!='s' && r!='N' && r!='n');
		
		
		if (r=='s' || r=='S') {
			if(nuevo.nTipoCuenta==1){
				fwrite(&nuevo, sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2, LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
				fprintf(pa2, "%s %s %i %i %6.2f %6.2f\n", nuevo.IdCuenta, IDCliente, nuevo.nif, nuevo.nTipoCuenta, nuevo.nSaldo, nuevo.nLimiteCredito);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO CUENTA, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				fclose(pa3);
				fclose(pa4);
				printf("\n");
				printf("\n Cuenta Registrada Correctamente\n"); 
				printf(" Presione una tecla para volver al menu principal..");
			}
			
			else{
				fwrite(&nuevo, sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2, LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
				fprintf(pa2, "%s %s %i %i %6.2f\n", nuevo.IdCuenta, IDCliente, nuevo.nif, nuevo.nTipoCuenta, nuevo.nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO CUENTA, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				fclose(pa3);
				fclose(pa4);
				printf("\n");
				printf("\n Cuenta Registrada Correctamente\n"); 
				printf(" Presione una tecla para volver al menu principal..");
			}
			
		}
		
		else {
			printf("\n\n Cuenta NO Registrada\n"); 
			printf(" Presione una tecla para volver al menu principal..");
		}
	}
	
	else{
		printf("Id Cliente NO Encontrado.\n");
		
	}
	
	fclose(pa);
	fclose(pa2);
	movimientof(nuevo.IdCuenta, nuevo.IdCliente,"S", nuevo.nSaldo);
	getch();
	system("cls");
	menu();
}


//FUNCION CONSULTA C, PERMITE CONSULTAR LOS DATOS DE UNA CUENTA, PARA LO CUAL SE DEBE INGRESAR ID DE LA CUENTA
void consultaC(){
	system("cls");
	cuenta nuevo, lista[50];
	char nombre[50];
	int encontro=1,linea,i,ultimo;
	FILE *pa;
	if ((pa = fopen("Archivo Binario 2", "a+b"))== NULL){ 
		printf("No se puede abrir el archivo.\n");
		return;
	}
	rewind(pa); i=0;
	while(!feof(pa))
	{ 
		if(fread(&nuevo, sizeof(cuenta), 1, pa)){
			lista[i]=nuevo;
		 	i++;
		}
	}
	fclose(pa);
 
  	
  	fflush(stdin);
  	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" CONSULTA DE CUENTA\n\n");
  	printf(" Ingrese ID de la Cuenta: ");gets(nombre);
  	ultimo=i-1;
  	i=0;
  	while (i<=ultimo && encontro)
  	{ 
	  	if (strcmp(lista[i].IdCuenta,nombre)==0) encontro=0;
    	else i++;
  	}
  	
  	if (i<=ultimo)
 	{
 		if(lista[i].nTipoCuenta==1){
 			system("cls");
		    printf("\n                               SISTEMA BANCARIO\n\n");
			printf(" CONSULTA DE CUENTAS\n\n");
		    printf(" Id Cuenta:         %s\n",lista[i].IdCuenta);
		    printf(" Id Cliente:        %s\n",lista[i].IdCliente);
		    printf(" NIF:               %i\n",lista[i].nif);
			printf(" Tipo Cuenta:       CREDITO\n");
		    printf(" Saldo:             $%6.2f\n",lista[i].nSaldo);
		    printf(" Limite Credito:    $%6.2f\n",lista[i].nLimiteCredito);
	
		    printf("\n Presione una tecla para volver al menu principal...");
			getch();
			system("cls");
			menu();
		}
		
		else{
			system("cls");
		    printf("\n                               SISTEMA BANCARIO\n\n");
			printf(" CONSULTA DE CUENTAS\n\n");
		    printf(" Id Cuenta:         %s\n",lista[i].IdCuenta);
		    printf(" Id Cliente:        %s\n",lista[i].IdCliente);
		    printf(" NIF:               %i\n",lista[i].nif);
			printf(" Tipo Cuenta:       DEBITO\n");
		    printf(" Saldo:             $%6.2f\n",lista[i].nSaldo);
	
		    printf("\n Presione una tecla para volver al menu principal...");
			getch();
			system("cls");
			menu();
		}
 		
  	}
  	
  	else
  	{ 
		printf(" Cliente NO registrado. Presione una tecla para volver... ");
		getch();
		system("cls");
		menu();
  	}
}


//FUNCION INGRESO, PERMITE REALIZAR UN INGRESO EN CUALQUIER CUENTA, PARA LO CUAL SE DEBE INGRESAR EL NUMERO DE CUENTA
void ingreso(){
	FILE *pa, *pa2;                                              
	char r;    
	char IdCuenta[10];
	char IdCliente[10]; 
	float cargo;                                                 
	cuenta nuevo, lista[50];                                    
	system("cls");                                               
	if ((pa = fopen("Archivo Binario 2","a+b"))==NULL)         
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}
	
	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                              
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                  
		lista[i]=nuevo;                                           
		i++;}                                                     
	}
	fclose(pa);
	
	
	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" INGRESO\n\n");
	printf(" Ingrese ID de Cuenta:          ");
		res=i;
		do{
			gets(nuevo.IdCuenta);
			
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,nuevo.IdCuenta)==0) encontro=0;              //COMPARA EL NUMERO DE CUENTA INGRESADO POR TECLADO , CON LOS NUMEROS DE CUENTA QUE ESTAN EL VECTOR LISTA
				else i++;
			}
			
			if(encontro==1){
				printf("\n ID Cuenta no existe.\n");
			}
			
			if (i<=ultimo){
				strcpy(IdCuenta, nuevo.IdCuenta);
				strcpy(IdCliente, lista[i].IdCliente);
				
				printf(" Ingrese cantidad a depositar:  $");
				scanf("%f",&nuevo.nSaldo);
				
				cargo = nuevo.nSaldo;
				lista[i].nSaldo += nuevo.nSaldo; 
				
				if(lista[i].nTipoCuenta == 1 && lista[i].nSaldo > 30000){
					printf("\n Error! Se Supera el valor limite.");
	    			printf("\n Presione una tecla para volver al menu principal..");
					getch();
				    system("cls");
					menu();	
				}
				
	    		do{
					printf("\n");
					printf(" Confirmar Transaccion: Si[s] / No [n]: "); 
					r=getch();
				}while(r!='S' && r!='s' && r!='N' && r!='n');
				
				
				if (r=='s' || r=='S') {
					// Abrir el archivo para Sobrescribir
				    if (((pa = fopen("Archivo Binario 2", "wb"))== NULL) || ((pa2 = fopen("Cuentas", "wb"))== NULL)){ 
						printf("No se puede abrir el archivo.\n");
						return;
				    }
				    i=0;
					
					while(i<=ultimo){
						if(lista[i].nTipoCuenta==1) {
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2, LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo, lista[i].nLimiteCredito);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO CUENTAS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
							i++;	
						}
						else{
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2 , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO CUENTAS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
							i++;
						}
						
						
			    	}
			    	
			    	fclose(pa);
					fclose(pa2);
			    	movimientof(IdCuenta, IdCliente,"D", cargo);
					printf("\n\n Transaccion Realizada con Exito.\n");	
				}
	    		
	    		if (r=='N' || r=='n'){
	    			printf("\n\n Transaccion Cancelada.");
	    			printf("\n Presione una tecla para volver al menu principal..");
					getch();
				    system("cls");
					menu();	
				}
	    		
			    
			    		
			}
			
		}while(i<=ultimo);
		
		printf(" Presione una tecla para volver al menu principal..");
		getch();
	    system("cls");
		menu();	
	
	
}

//FUNCION RETIRO, PERMIET RETIRAR DINERO DE CUALQUIER CUENTA CREADA, SE DEBE INGRESAR NUMERO DE CUENTA Y NIF PARA PODER RETIRAR
void retiro(){
	FILE *pa, *pa2;                                              
	char r;    
	char IdCuenta[10];
	char IdCliente[10];  
	float cargo;                                                
	cuenta nuevo, lista[50];                                     
	system("cls");                                               
	if ((pa = fopen("Archivo Binario 2","a+b"))==NULL)          
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                            
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                   
		lista[i]=nuevo;                                          
		i++;}                                                   
	}
	fclose(pa);
	

	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" RETIRO\n\n");
				printf(" Ingrese ID Cuenta:           ");
		res=i;
		do{
			gets(nuevo.IdCuenta);
				printf(" Ingrese NIF:                 "); scanf("%i",&nuevo.nif);
			
			
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,nuevo.IdCuenta)==0 && lista[i].nif==nuevo.nif)  //COMPARA EL ID CUENTA INGRESADO POR TECLADO , CON LOS ID CUENTA DEL VECTOR LISTA
					encontro=0;              
				else i++;
			}
			
			if(encontro==1){
				printf("\n Error en ID Cuenta o NIF\n");
			}
			
			if (i<=ultimo){
				strcpy(IdCuenta, nuevo.IdCuenta);
				strcpy(IdCliente, lista[i].IdCliente);
				printf(" Ingrese cantidad a retirar:  $");
				scanf("%f",&nuevo.nSaldo);
				
				cargo = nuevo.nSaldo;
				lista[i].nSaldo -= nuevo.nSaldo; 
				
				if(lista[i].nSaldo<0){
					printf("\n No cuenta con fondos suficientes para realizar el retiro.\n");
					printf(" Presione una tecla para volver al menu principal..");
					getch();
					menu();
				}
				
	    
	    		do{
					printf("\n");
					printf(" Confirmar Transaccion: Si[s] / No [n]: "); 
					r=getch();
				}while(r!='S' && r!='s' && r!='N' && r!='n');
				
				
				if (r=='s' || r=='S') {
					// Abrir el archivo para Sobrescribir
				    if (((pa = fopen("Archivo Binario 2", "wb"))== NULL) || ((pa2 = fopen("Cuentas", "wb"))== NULL)){ 
						printf("No se puede abrir el archivo.\n");
						return;
				    }
				    i=0;
					
					while(i<=ultimo){
						if(lista[i].nTipoCuenta==1) {
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2, LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo, lista[i].nLimiteCredito);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO CUENTAS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				      		i++;	
						}
						else{
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO 2, LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO CUENTAS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				      		i++;
						}
					
			    	}
			    	
			    	fclose(pa);
					fclose(pa2);
			    	movimientof(IdCuenta, IdCliente,"R", cargo);
					printf("\n\n Transaccion Realizada con Exito.\n");	
				}
	    		
	    		if (r=='N' || r=='n'){
	    			printf("\n\n Transaccion Cancelada.\n");
	    			printf(" Presione una tecla para volver al menu principal..");
					getch();
				    system("cls");
					menu();	
				}
	    		
			    
			    		
			}
			
		}while(i<=ultimo);
		
		printf(" Presione una tecla para volver al menu principal..");
		getch();
	    system("cls");
		menu();	
	
	
}


//FUNCION PAGO, PERMITE REALIZAR PAGOS , SOLO SI ES CUENTA DE CREDITO
void pago(){
	FILE *pa, *pa2;                                             
	char r; 
	char IdCuenta[10];
	char IdCliente[10];
	float cargo;                                                     
	cuenta nuevo, lista[50];                                     
	system("cls");                                                
	if ((pa = fopen("Archivo Binario 2","a+b"))==NULL)          
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                           
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                  
		lista[i]=nuevo;                                          
		i++;}                                                   
	}
	fclose(pa);
	

	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" Pago\n\n");
				printf(" Ingrese ID Cuenta:         ");
		res=i;
		do{
			gets(nuevo.IdCuenta);
			//proceso de busqueda de la informaci¢n
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,nuevo.IdCuenta)==0 && lista[i].nTipoCuenta == 1) encontro=0;              //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL VECTOR LISTA
				else i++;
			}
			
			if(encontro==1){
				printf("\n ID Cuenta no existe o no es una Cuenta de Credito");
			}
			
			if (i<=ultimo){
				strcpy(IdCuenta, nuevo.IdCuenta);
				strcpy(IdCliente, lista[i].IdCliente);
				printf(" Ingrese cantidad a pagar:  $");
				scanf("%f",&nuevo.nSaldo);
				
				cargo = nuevo.nSaldo;
				lista[i].nSaldo -= nuevo.nSaldo; 
				
				if(lista[i].nSaldo<0){
					printf("\n No cuenta con fondos suficientes para realizar el pago.\n");
					printf(" Presione una tecla para volver al menu principal..");
					getch();
					menu();
				}
	    
	    		do{
					printf("\n");
					printf(" Confirmar Transaccion: Si[s] / No [n]: "); 
					r=getch();
				}while(r!='S' && r!='s' && r!='N' && r!='n');
				
				
				if (r=='s' || r=='S') {
					// Abrir el archivo para Sobrescribir
				    if (((pa = fopen("Archivo Binario 2", "wb"))== NULL) || ((pa2 = fopen("Cuentas", "wb"))== NULL)){ 
						printf("No se puede abrir el archivo.\n");
						return;
				    }
				    i=0;
					
					while(i<=ultimo){
						if(lista[i].nTipoCuenta==1) {
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo, lista[i].nLimiteCredito);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				      		i++;	
						}
						else{
							fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
							fprintf(pa2, "%s %s %i %i %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				      		i++;
						}
					
			    	}
			    	
			    	fclose(pa);
					fclose(pa2);
			    	movimientof(IdCuenta, IdCliente,"P", cargo);
					printf("\n\n Transaccion Realizada con Exito.");	
				}
	    		
	    		if (r=='N' || r=='n'){
	    			printf("\n\n Transaccion Cancelada.");
	    			printf("\n Presione una tecla para volver al menu principal..");
					getch();
				    system("cls");
					menu();	
				}
	    		
			    fclose(pa);
				fclose(pa2);
			    		
			}
			
		}while(i<=ultimo);
		
		printf("\n Presione una tecla para volver al menu principal..");
		getch();
	    system("cls");
		menu();		
}


//FUNCION TRANSFERENCIA, PERMITE REALIZAR UNA TRANSFERENCIA 
void transferencia(){
	FILE *pa, *pa2;                                            
	char r; 
	char IdCuenta[10];
	char IdCliente[10];
	float cargo;
	char idCuentaDestino[10];                                                     
	cuenta nuevo, lista[50];                                    
	system("cls");                                               
	if ((pa = fopen("Archivo Binario 2","a+b"))==NULL)          
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,encontro2=1,i,j,ultimo,res;

	rewind(pa); 
	i=0;
	j=0;
	while(!feof(pa))                                             
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                  
		lista[i]=nuevo;                                          
		i++;}                                                    
	}
	fclose(pa);
	

	fflush(stdin);
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" Transferencia\n\n");
	printf(" Ingrese ID Cuenta Origen:       ");
		res=i;
		do{
			gets(nuevo.IdCuenta);
			printf(" Ingrese ID Cuenta Destino:      ");
			gets(idCuentaDestino);
			
			ultimo=res-1;
			i=0;
			j=0;
			encontro=1;
			encontro2=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,nuevo.IdCuenta)==0 && lista[i].nTipoCuenta != 1) encontro=0;              //COMPARA EL ID CUENTA ORIGEN INGRESADO POR TECLADO , CON LOS ID CUENTA QUE ESTAN EN EL VECTOR LISTA
				else i++;
			}
			
			while (j<=ultimo && encontro2){
				if (strcmp(lista[j].IdCuenta,idCuentaDestino)==0 && lista[j].nTipoCuenta != 1) encontro2=0;              //COMPARA EL ID CUENTA DESTINO INGRESADO POR TECLADO , CON LOS ID QUE ESTAN EN EL VECTOR LISTA
				else j++;
			}
			
			
			if(encontro == 1 || encontro2 == 1 ){
				printf("\n ID Cuenta NO existe o NO es una Cuenta de Debito\n");
				printf(" Presione una tecla para volver al menu principal..");
				getch();
				menu();
			}
	
		
			if (i<=ultimo){
				strcpy(IdCuenta, nuevo.IdCuenta);
				strcpy(IdCliente, lista[i].IdCliente);
				printf(" Ingrese cantidad a transferir:  $");
				scanf("%f",&nuevo.nSaldo);
				cargo = nuevo.nSaldo;
				
				lista[i].nSaldo -= nuevo.nSaldo; 
				
				if(lista[i].nSaldo<0){
					printf("\n No cuenta con fondos suficientes para realizar la transferencia.\n");
					printf(" Presione una tecla para volver al menu principal..");
					getch();
					menu();
				}
	    
	    		do{
					printf("\n");
					printf(" Confirmar Transaccion: Si[s] / No [n]: "); 
					r=getch();
				}while(r!='S' && r!='s' && r!='N' && r!='n');
				
				
				if (r=='s' || r=='S') {
					// Abrir el archivo para Sobrescribir
				    if (((pa = fopen("Archivo Binario 2", "wb"))== NULL) || ((pa2 = fopen("Cuentas", "wb"))== NULL)){ 
						printf("No se puede abrir el archivo.\n");
						return;
				    }
				    i=0;
					
					while(i<=ultimo){
						fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FICHERO DESTINO
						fprintf(pa2, "%s %s %i %i %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
				      	i++;
			    	}
			    	
			    	fclose(pa);
					fclose(pa2);
					movimientof(IdCuenta, IdCliente,"T-", cargo);
			    	transferenciaDestino(idCuentaDestino,nuevo.nSaldo);	
			    	movimientof(idCuentaDestino, lista[j].IdCliente,"T+", cargo);
				}
	    		
	    		if (r=='N' || r=='n'){
	    			printf("\n\n Transaccion Cancelada.");
	    			printf("\n Presione una tecla para volver al menu principal..");
					getch();
				    system("cls");
					menu();	
				}
	    		
			    fclose(pa);
				fclose(pa2);
			    		
			}
			
		}while(i<=ultimo);

		printf("\n Presione una tecla para volver al menu principal..");
		getch();
	    system("cls");
		menu();		
}


//FUNCION TRANSFERENCIA DESTINO, PERMITE ACTUALIZAR EL SALDO DE LA CUENTA DESTINO CUANDO SE REALIZA UNA TRANSFERENCIA
void transferenciaDestino(char idDestino[10], float nSaldo){
	FILE *pa, *pa2;                                              
	char r;                                                     
	cuenta nuevo, lista[50];                                                                                
	if ((pa = fopen("Archivo Binario 2","a+b"))==NULL)           
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	while(!feof(pa))                                            
	{ if(fread(&nuevo, sizeof(cuenta), 1, pa)){                   
		lista[i]=nuevo;                                          
		i++;}                                                   
	}
	fclose(pa);
	
		res=i;
		do{
			//proceso de busqueda de la informaci¢n
			ultimo=res-1;
			i=0;
			encontro=1;
			while (i<=ultimo && encontro){
				if (strcmp(lista[i].IdCuenta,idDestino)==0) encontro=0;              //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL VECTOR LISTA
				else i++;
			}
			

			if (i<=ultimo){

				lista[i].nSaldo += nSaldo; 
				
				
				
				// Abrir el archivo para Sobrescribir
				if (((pa = fopen("Archivo Binario 2", "wb"))== NULL) || ((pa2 = fopen("Cuentas", "wb"))== NULL)){ 
					printf("No se puede abrir el archivo.\n");
					return;
			    }
			    i=0;
					
				while(i<=ultimo){
					fwrite(&lista[i], sizeof(cuenta),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL FICHERO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN FIICHERO DESTINO
					fprintf(pa2, "%s %s %i %i %6.2f\n", lista[i].IdCuenta, lista[i].IdCliente, lista[i].nif, lista[i].nTipoCuenta, lista[i].nSaldo);       //AQUI SE GUARDAN LOS DATOS EN EL FICHERO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
			      	i++;
		    	}
					    	
				printf("\n\n Transaccion Realizada con Exito.");	
			
			    fclose(pa);
				fclose(pa2);		
			}
			
		}while(i<=ultimo);	
}


//FUNCION INTERESES, PERMITE REALIZAR EL CALCULO DE INTERESES, INGRESANDO UN MONTO, TASA Y MESES
void intereses(){
	float capital, intereses, tasanominal,meses,tasa;
	system("cls");
	printf("\n                               SISTEMA BANCARIO\n\n");
	printf(" INVERSION\n\n");
	printf(" Ingrese capital a invertir:                  $"); scanf("%f",&capital);
	printf(" Ingrese los meses que colocara la inversion: "); scanf("%f",&meses); 
	printf(" Ingrese la tasa de interes:                  "); scanf("%f",&tasa);
	tasanominal = (tasa * meses)/100;
	intereses = (capital*tasanominal);
	printf(" Intereses ganados:                           $%6.2f",intereses);
	printf("\n\n Presione una tecla para volver al menu principal..");
	getch();
	system("cls");
	menu();	
}


//FUNCION MOVIMIENTOF, PERMITE INGRESAR DATOS EN EL FICHERO DE TEXTO MOVIMIENTOS 
void movimientof(char idCuenta[10], char idCliente[10],char tipoM[1], float cargo){
	FILE *pa, *pa2;                                             
	char r;                                                      
	movimiento nuevo, lista[50];                                             
	char tipores[1];
	
	if (((pa = fopen("Archivo Binario 3","a+b"))==NULL) || ((pa2 = fopen("Movimientos","a+b"))==NULL))         
	{ printf("No se puede abrir el archivo.\n");
		return ;
		}
	
	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                          
	{ if(fread(&nuevo, sizeof(cliente), 1, pa)){                   
		lista[i]=nuevo;                                          
		i++;}                                                   
	}
	strcpy(nuevo.IdCuenta,idCuenta);
	strcpy(nuevo.IdCliente,idCliente);
	nuevo.cargo = cargo;
	
	time_t t;
	struct tm *tm;
	char fecha[100];
	t=time(NULL);
	tm=localtime(&t);
	strftime(fecha, 100, "%d/%m/%Y", tm);
	
	strcpy(nuevo.dFecha, fecha);
	strcpy(nuevo.idTipoMov, tipoM);
	
	if(strcmp(tipoM,"D")==0)
		strcpy(nuevo.Descripcion,"Ingreso         ");
		
	else if(strcmp(tipoM,"R")==0)
		strcpy(nuevo.Descripcion,"Retiro           ");
		
	else if(strcmp(tipoM,"P")==0)
		strcpy(nuevo.Descripcion,"Pago             ");
		
	else if(strcmp(tipoM,"S")==0)
		strcpy(nuevo.Descripcion,"Saldo Inicial    ");
		
	else if(strcmp(tipoM,"T+")==0)
		strcpy(nuevo.Descripcion,"Transf. Realizada");
		
	else 
		strcpy(nuevo.Descripcion,"Transf. Recibida ");
	

	
	fwrite(&nuevo, sizeof(movimiento),1,pa);                                                          
	fprintf(pa2, "%s %s %s %s %6.2f %s \n", nuevo.IdCuenta, nuevo.IdCliente, tipoM, nuevo.Descripcion, nuevo.cargo, nuevo.dFecha);       
	
	fclose(pa);
	fclose(pa2);

}


//FUNCION REPORTE, SE IMPRIME REPORTE CON INFORMACION DE LOS MOVIMIENTOS DE LA CUENTA
void reporte(){
	FILE *pa, *pa2;                                             
	char r;    
	char IdCliente[10]; 
	char IdCuenta[10];  
	float cargo;                                               
	movimiento nuevo, lista[50];                                     
	system("cls");                                               
	if ((pa = fopen("Archivo Binario 3","a+b"))==NULL)         
	{ printf("No se puede abrir el archivo.\n");
		return ;
	}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	
	while(!feof(pa))                                             
	{ if(fread(&nuevo, sizeof(movimiento), 1, pa)){                   
		lista[i]=nuevo;                                          
		i++;}                                                    
	}
	fclose(pa);

	res=i;
	printf(" REPORTES\n\n");
	fflush(stdin);
	printf(" Ingrese ID Cliente: "); gets(IdCliente);
	printf(" Ingrese ID Cuenta:  "); gets(IdCuenta);
	
	
	//ABRIMOS EL FICHERP CLIENTE PARA EXTRAER INFORMACION
	FILE *pa3; 
	cliente nuevo2, lista2[50];
	char Nombre[50];
	char Ciudad[25];
	
	if ((pa3 = fopen("Archivo Binario","a+b"))==NULL)          //FUNCION FOPEN: PERMITE CREAR Y/O ABRIR UN FICHERO, SE CREAN 2 FICHERO, UNO BINARIO Y EL OTRO DE TEXTO , EL DE TEXTO PERMITE LEER LOS CARACTERES DEL TECLADO NORMAL
	{ printf("No se puede abrir el archivo.\n");
		return ;
	}

	int encontro2=1,j,ultimo2,res2;
	rewind(pa3); 
	j=0;
	
	while(!feof(pa3))                                             //CON ESTE WHILE, SE VA A RECORRER TODO EL FICHERO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL DEVUELVE UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR A LLEGADO AL FINAL DEL FCHERO
	{ if(fread(&nuevo2, sizeof(cliente), 1, pa3)){                   //LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS DEL FICHERO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL VECTOR CUANTAS POSICIONES TENDRÁ
		lista2[j]=nuevo2;                                          //TODA LA INFORMACION ALMACENADA EN NUEVO SE GUARDARA EN EL VECOTR LISTA..
		j++;}                                                    //.. ESTO SE LO HACE PARA LUEGO COMPARAR
	}
	fclose(pa3);
	
	res2=j;
	ultimo2= j-1;
	j = 0;
	while (j<=ultimo2 && encontro2){
		if (strcmp(lista2[j].idCliente,IdCliente)==0) encontro2=0;              //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL ARR LISTA
		else j++;
	}
	
	strcpy(Nombre,lista2[j].Nombre);
	strcpy(Ciudad,lista2[j].Ciudad);
	
    ////////////////////////////////////////////////////////////////////////////
	
	//ABRIMOS EL FICHERO CUENTA PARA EXTRAER INFORMACION
	FILE *pa4; 
	cuenta nuevo3, lista3[50];
	float SaldoActual;
	float Limite;
	char NumCuenta[10];
	
	if ((pa4 = fopen("Archivo Binario 2","a+b"))==NULL)          //FUNCION FOPEN: PERMITE CREAR Y/O ABRIR UN FICHERO, SE CREAN 2 FICHEROS, UNO BINARIO Y EL OTRO DE TEXTO , EL DE TEXTO PERMITE LEER LOS CARACTERES DEL TECLADO NORMAL
	{ printf("No se puede abrir el archivo.\n");
		return ;
	}

	int encontro3=1,k,ultimo3,res3;
	rewind(pa4); 
	k=0;
	
	while(!feof(pa4))                                             //CON ESTE WHILE, SE VA A RECORRER TODO EL FICHERO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL DEVUELVE UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR HA LLEGADO AL FINAL DEL FICHERO
	{ if(fread(&nuevo3, sizeof(cuenta), 1, pa4)){                   //LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS DEL FICHERO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL VECTOR CUANTAS POSICIONES TENDRÁ
		lista3[k]=nuevo3;                                          //TODA LA INFORMACION ALMACENADA EN NUEVO SE GUARDARA EN EL VECTOR LISTA..
		k++;}                                                    //.. ESTO SE  HACE PARA LUEGO COMPARAR
	}
	fclose(pa4);
	
	res3=k;
	ultimo3= k-1;
	k = 0;
	while (k<=ultimo3 && encontro3){
		if (strcmp(lista3[k].IdCuenta,IdCuenta)==0) encontro3=0;              //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL VECTOR LISTA
		else k++;
	}
	
	SaldoActual = lista3[k].nSaldo;
	Limite = lista3[k].nLimiteCredito;
	strcpy(NumCuenta,lista3[k].IdCuenta);
	
    ////////////////////////////////////////////////////////////////////////////
	

	ultimo= i-1;
	i = 0;
	while (i<=ultimo && encontro){
		if (strcmp(lista[i].IdCliente,IdCliente)==0 && strcmp(lista[i].IdCuenta, IdCuenta)==0) encontro=0;              //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL VECTOR LISTA
		else i++;
	}
					
	if(encontro == 1 ){
		printf("\n ID Cuenta / ID Cliente no existe!\n");
		printf(" Presione una tecla para volver al menu principal..");
		getch();
		menu();
	}
	
	
	i=0;
	system("cls");
	printf("                               ESTADO DE CUENTA\n");
	printf("\n ID CLIENTE:      %s", IdCliente);     
	printf("\n NOMBRE CLIENTE:  %s", Nombre); 
	printf("\n CIUDAD:          %s",Ciudad);      
	printf("\n ID CUENTA:       %s",NumCuenta);
	printf("\n LIMITE CREDITO:  $%6.2f",Limite);
	printf("\n SALDO ACTUAL:    $%6.2f",SaldoActual);
	
	printf("\n\n FECHA MOV                     TIPO MOVIMIENTO                 CARGO\n");
	while(i<=ultimo){
		
		if (strcmp(lista[i].IdCliente,IdCliente)==0 && strcmp(lista[i].IdCuenta, IdCuenta)==0){
			printf(" %s                    %s               $%6.2f\n",lista[i].dFecha,lista[i].Descripcion,lista[i].cargo);
		}
		i++;
	}

	printf("\n Presione una tecla para volver al menu principal..");
	getch();
	system("cls");
	menu();	
}

