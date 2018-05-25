#include<iostream>
#include<string>
#include<math.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//metodos o funciones
char** crear_tablero();
void liberar_m(char** matriz,int size);
char** llenar_tablero(char** matriz,int size);
void imprimir(char**matriz,int size);
char** validar_movimiento(char** matriz,int x, int y,int x1,int y1);
char** reconocer_coronel(char** matriz,int size);
char** validar_movimientos_coronel(char** matriz,int x,int y,int x1,int x2);
char** comer_pieza(char** matriz,int x, int y, int x1, int x2);
bool ver_ganador(char** matriz, int size,string ganador);


int main(){

	bool centinela = true;
	int x  = 0;
	int y  = 0;
	int x1 = 0; 
	int y1 = 0;
	////
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;
	string jugador1 =  " ";
	string jugador2  = " ";

	cout<<"Bienvenido a CraftSTar"<<endl;
        cout<<"--------------------------"<<endl;
	cout<<"¡INSTRUCCIONES!"<<endl;
	cout<<"1. Las coordenadas se manejan con Enteros, Ejemplo: Coordenada en X = 0, Coordenada en Y = 		0"<<endl;
	cout<<"2.FIN DE LAS INSTRUCCIONES"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<" "<<endl;
	cout<<"Jugador 1, Ingrese su nombre: "<<endl;
	cin>>jugador1;
	cout<<"Jugador 2, Ingrese su nombre: "<<endl;
	cin>>jugador2;
        cout<<"  "<<endl;
	
	char** matriz = crear_tablero();
	matriz = llenar_tablero(matriz,8);
	
	imprimir(matriz,8);

	while(centinela==true){
	      cout<<"JUGADOR 1: "<<jugador1<<endl;
	      cout<<"Ingrese coordenada en X de la pieza: "<<endl;
	      cin>>x;
	      while(x>7){
		cout<<"ERROR FUERA DE RANGO, Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x;
	      }
 	      cout<<"Ingrese coordenada en y de la pieza: "<<endl;
	      cin>>y;
	      while(y>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en y de la pieza: "<<endl;
	        cin>>y;
	      }

	      cout<<"--------------------------------------"<<endl;
	      cout<<"Ingrese coordenada en X de la pieza a mover "<<endl;
	      cin>>x1;
	      while(x1>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x1;
	      }
 	      cout<<"Ingrese coordenada en y de la pieza a mover "<<endl;
	      cin>>y1;
	      while(y1>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>y1;
	      }


 		while(matriz[x][y] != 'O'){
			cout<<" "<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<" ERROR VAN LAS PIEZAS 'O' SELECCIONE PORFA"<<endl;
			cout<<"------------------------------------------- "<<endl;
			cout<<" "<<endl;
			cout<<"Ingrese coordenada en X de la pieza: "<<endl;
		          cin>>x;
		      while(x>7){
			cout<<"ERROR FUERA DE RANGO, Ingrese coordenada en X de la pieza: "<<endl;
			cin>>x;
		       }
	 	       cout<<"Ingrese coordenada en y de la pieza: "<<endl;
		       cin>>y;
		      while(y>7){
			cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en y de la pieza: "<<endl;
			cin>>y;
		      }
			cout<<"--------------------------------------"<<endl;
	      cout<<"Ingrese coordenada en X de la pieza a mover "<<endl;
	      cin>>x1;
	      while(x1>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x1;
	      }
 	      cout<<"Ingrese coordenada en y de la pieza a mover "<<endl;
	      cin>>y1;
	      while(y1>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>y1;
	          }
		 }
              
	      	      
	      
	      matriz = validar_movimiento(matriz,x,y,x1,y1);
	      matriz = reconocer_coronel(matriz,8);
	      matriz = validar_movimientos_coronel(matriz,x,y,x1,y1);
	      matriz = comer_pieza(matriz,x,y,x1,y1);

	/*	for(int i = 0;i<8;i++){
			for(int j = 0;j<8;j++){
			matriz[i][j] = ' ';

			}
		}*/
	       imprimir(matriz,8);
	      centinela = ver_ganador(matriz,8,jugador1);
		if(centinela == false){
			break;
		}		
	      //imprimir(matriz,8);



	      cout<<"JUGADOR 2: "<<jugador2<<endl;
	      cout<<"Ingrese coordenada en X de la pieza: "<<endl;
	      cin>>x2;
	      while(x2>7){
		cout<<"ERROR FUERA DE RANGO, Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x2;
	      }
 	      cout<<"Ingrese coordenada en y de la pieza: "<<endl;
	      cin>>y2;
	      while(y2>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en y de la pieza: "<<endl;
	        cin>>y2;
	      }
	      cout<<"--------------------------------------"<<endl;
	      cout<<"Ingrese coordenada en X de la pieza a mover "<<endl;
	      cin>>x3;
	      while(x3>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x3;
	      }
 	      cout<<"Ingrese coordenada en y de la pieza a mover "<<endl;
	      cin>>y3;
	      while(y3>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>y3;
	      }


		while(matriz[x2][y2] != 'X'){
			cout<<" "<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<" ERROR VAN LAS PIEZAS 'X' SELECCIONE PORFA"<<endl;
			cout<<"------------------------------------------- "<<endl;
			cout<<" "<<endl;
			cout<<"Ingrese coordenada en X de la pieza: "<<endl;
		          cin>>x2;
		      while(x2>7){
			cout<<"ERROR FUERA DE RANGO, Ingrese coordenada en X de la pieza: "<<endl;
			cin>>x2;
		       }
	 	       cout<<"Ingrese coordenada en y de la pieza: "<<endl;
		       cin>>y2;
		      while(y2>7){
			cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en y de la pieza: "<<endl;
			cin>>y2;
		      }
			cout<<"--------------------------------------"<<endl;
	      cout<<"Ingrese coordenada en X de la pieza a mover "<<endl;
	      cin>>x3;

	      while(x3>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en X de la pieza: "<<endl;
	        cin>>x3;
	      }

 	      cout<<"Ingrese coordenada en y de la pieza a mover "<<endl;
	      cin>>y3;

	      while(y3>7){
		cout<<"ERROR FUERA DE RANGO , Ingrese coordenada en y de la pieza: "<<endl;
	        cin>>y3;
	          }

		 }

		

	      matriz = validar_movimiento(matriz,x2,y2,x3,y3);
	      matriz = reconocer_coronel(matriz,8);
	      matriz = validar_movimientos_coronel(matriz,x2,y2,x3,y3);
	      matriz = comer_pieza(matriz,x2,y2,x3,y3);
	      imprimir(matriz,8);
	      centinela = ver_ganador(matriz,8,jugador2);
	      if(centinela == false){
			break;
		}

	     // imprimir(matriz,8);
	      
	      

        }
	cout<<"  "<<endl;
	cout<<"  "<<endl;
	cout<<" ASI QUEDO EL TABLERO "<<endl;
	cout<<" "<<endl;
	imprimir(matriz,8);
	liberar_m(matriz,8);





return 0;
}


char** crear_tablero(){
	char**tempo = new char*[8];
	for(int i = 0;i<8;i++){
		tempo[i] = new char[8];

	}

	for(int i = 0; i<8;i++)
		for(int j = 0; j<8;j++)
		    tempo[i][j] = 0;


	return tempo;

}//fin del metodo crear tablero


void liberar_m(char** matriz, int size){
	for(int i = 0;i<size;i++){
		delete[] matriz[i];
		matriz[i] = NULL;

	}

	delete[]matriz;
	matriz=NULL;
}

char** llenar_tablero(char** matriz, int size){
	   //asignacion de piezas de equipo x
	   matriz[0][1] = 'X';  matriz[0][3] = 'X'; matriz[0][5] = 'X';  matriz[0][7] = 'X'; 
           matriz[1][0] = 'X';  matriz[1][2] = 'X'; matriz[1][4] = 'X';  matriz[1][6] = 'X';
	   matriz[2][1] = 'X';  matriz[2][3] = 'X'; matriz[2][5] = 'X';  matriz[2][7] = 'X';

	   //asignacion de piezas equipo y
	   matriz[5][0] = 'O';  matriz[5][2] = 'O'; matriz[5][4] = 'O';  matriz[5][6] = 'O'; 
           matriz[6][1] = 'O';  matriz[6][3] = 'O'; matriz[6][5] = 'O';  matriz[6][7] = 'O';
	   matriz[7][0] = 'O';  matriz[7][2] = 'O'; matriz[7][4] = 'O';  matriz[7][6] = 'O';

return matriz;
}


void imprimir(char**matriz,int size){
	
	for(int i = 0;i<size;i++){

		for(int j = 0; j<size;j++){
		    


		      cout<<"| "<<matriz[i][j]<<" |";
		      
			
		}
		cout<<endl;

		
	}


}//fin del metodo de imprimir


char** validar_movimiento(char** matriz,int x, int y, int x1, int y1){

 int formula = sqrt( ((x1 - x) * (x1 - x))  + ((y1 - y) * (y1 - y)) ) ;  	
 

    if(formula == 1){
	if(matriz[x][y] == 'X'){
		if(y1==y || x1<=x ){
		   cout<<"MOVIMIENTO NO VALIDO"<<endl;
		   cout<<" "<<endl;
		}else{
		    matriz[x][y] = ' ';
	            matriz[x1][y1] = 'X';

		}	
		
	  // imprimir(matriz,8);

          }else	if(matriz[x][y] == 'O'){

		if(y1==y || x1>=x ){
		   cout<<"MOVIMIENTO NO VALIDO"<<endl;
		   cout<<" "<<endl;
		}else{
		    matriz[x][y] = ' ';
	            matriz[x1][y1] = 'O';

		}
	   }
	//imprimir(matriz,8);
         } else{
	    cout<<"MOVIMIENTO NO VALIDO"<<endl;
	    cout<<" "<<endl;
    }
    
  

return matriz;
}



char** reconocer_coronel(char** matriz,int size){
	for(int i = 0;i<size;i++){
		if(matriz[0][i] == 'O'){
			matriz[0][i] = 'V';
		}	
        }

	for(int i = 0;i<size;i++){
		if(matriz[7][i] == 'X'){
			matriz[0][i] = 'A';
		}	
        }

return matriz;

}//reconocer_coronel 




char** validar_movimientos_coronel(char** matriz,int x, int y, int x1, int y1){
if(matriz[x][y] == 'A'){
	matriz[x][y] = ' ';
	matriz[x1][y1] = 'A';
	      
        	


}else if(matriz[x][y] == 'V'){
	matriz[x][y] = ' ';
	matriz[x1][y1] = 'V';

}


return matriz;
}//fin del metodo reconocer coronel

char** comer_pieza(char** matriz,int x, int y, int x1, int y1){

int formula = sqrt( ((x1 - x) * (x1 - x))  + ((y1 - y) * (y1 - y)) ) ;  	
 
   if(formula == 1){
    	if(matriz[x][y] == 'X' || matriz[x][y] == 'A'){
		if(matriz[x1][y1] == 'O' || matriz[x1][y1] == 'V'){
		    matriz[x][y] = ' ';
	            matriz[x1][y1] = 'X';

		}
    }else if (matriz[x][y] == 'O' || matriz[x][y] == 'V'){
		if(matriz[x1][y1] == 'X' || matriz[x1][y1] == 'A'){
		    matriz[x][y] = ' ';
	            matriz[x1][y1] = 'O';

		}
    }
   }

 return matriz;
}//fin del metodo comer piezas

bool ver_ganador(char** matriz,int size,string ganador){
bool c;    
	for(int i = 0;i<size;i++){
		for(int j = 0; j<size;j++){
		    if(matriz[i][j] != ' '){
		        
			c = true;
                      }else{
			c = false;
			
		      }	
		
		}
	
	}
	if(c == true){
        cout<<" "<<endl;
	cout<<"Aun no termina la partida"<<endl;
	cout<<" "<<endl;
	}else if(c==false){
		cout<<"--------------------------"<<endl;
			cout<<"El Ganador es :  "<<ganador<<"   Felicidades!"<<endl;
	}

return c;
}
