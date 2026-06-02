// Sistema de gestión de canciones

#include <iostream>
#include <string>
using namespace std;

// Estructura 
struct Cancion 
{
	int codigo;
	string titulo;
	string artista;
	string genero;
	float duracion;
};

// Arreglo
Cancion lista[100];

// Variable de canciones existentes
int totalCanciones = 0;

// Declaramos funciones
void registrar();
void mostrar();
void buscar();
void actualizar();
void eliminar();
void ordenar();
bool codigoExiste(int codigo);

int main()
{
	//MENU
	int opcion;
	do
	{
		cout<<"\n============ MENU ============"<< endl;
		cout<<"1. Registrar canciones" << endl;
		cout<<"2. Mostrar canciones" << endl;
		cout<<"3. Buscar canciones" << endl;
		cout<<"4. Actualizar canciones" << endl;
		cout<<"5. Eliminar canciones" << endl;
		cout<<"6. Ordenar canciones" << endl;
		cout<<"7. Salir" << endl;
		
		cout<<"Selecione una opción: ";
		cin >> opcion;
		
		switch(opcion) 
		{
			case 1:
            	registrar();
            	break;
            
        	case 2:
            	mostrar();
            	break;
            
            case 3:
            	buscar();
            	break;
            	
            case 4:
            	actualizar();
            	break;
            
            case 5:
            	eliminar();
            	break;
            	
            case 6:
            	ordenar();
            	break;
				
			case 7:
            	cout <<"Saliendo..." << endl;
            	break;		

            default:
				cout<<"Opción inválida"<<endl;	
		}
	} while(opcion !=7);
		
	return 0;
}

// Definimos funciones
void registrar()
{
	// Verifica que aún exista espacio en el arreglo
	if(totalCanciones>=100)
	{
		cout<<"No hay espacio para más canciones."<<endl;
		return;
	}
	
	cout <<"\n==== REGISTRO DE CANCIONES ===="<< endl;
	
	int codigoNuevo;
	
	cout<<"Código: ";
	cin>>codigoNuevo;
	
	// Verifica que el código no se repita
	if(codigoExiste(codigoNuevo))
	{
		cout<<"ERROR: el código ya existe."<<endl;
		return;
	}
	lista[totalCanciones].codigo=codigoNuevo;
	
	cin.ignore(); // Limpia el buffer para permitir getline()
	
	cout<<"Título: ";
	getline(cin, lista[totalCanciones].titulo);
	
	cout<<"Artista: ";
	getline(cin, lista[totalCanciones].artista);
	
	cout<<"Género: ";
	getline(cin, lista[totalCanciones].genero);
	
	cout<<"Duracion (minutos): ";
	cin>> lista[totalCanciones].duracion;
	
	totalCanciones++; // Aumenta el total de canciones
	cout<<"\nCancion registrada correctamente."<< endl;
}

void mostrar()
{
	cout<<"\n===== LISTA DE CANCIONES ====="<< endl;
	
	// Verifica si existen canciones registradas
	if(totalCanciones == 0)
	{
		cout<<"No hay canciones registradas."<<endl;
		return;
	}
	
	// Recorre la lista para mostrar canciones
	for(int i=0; i<totalCanciones; i++) 
	{
		cout<<"\n------------------------------"<<endl;
		cout<<"\nCanción #"<<i+1<<endl;
		
		cout<<"Código: "<<lista[i].codigo<<endl;
		cout<<"Título: "<<lista[i].titulo<<endl;
		cout<<"Artista: "<<lista[i].artista<<endl;
		cout<<"Género: "<<lista[i].genero<<endl;
		cout<<"Duración: "<<lista[i].duracion<<"min"<<endl;
	}
}

void buscar()
{
	// Búsqueda secuencial
	// Recorre la lista buscando coincidencias de código
	int codigoBuscado;
	bool encontrado = false;
	
	cout<<"\n======= BUSCAR CANCIÓN ======="<<endl;
	
	cout<<"Ingrese el código: ";
	cin>> codigoBuscado;
	
	for(int i=0; i<totalCanciones; i++)
	{
		if(lista[i].codigo == codigoBuscado)
		{
			cout<<"\n======== Canción encontrada: "<<endl;
			
			cout<<"Código: "<<lista[i].codigo<<endl;
			cout<<"Título: "<<lista[i].titulo<<endl;
			cout<<"Artista: "<<lista[i].artista<<endl;
			cout<<"Género: "<<lista[i].genero<<endl;
			cout<<"Duración: "<<lista[i].duracion<<"min"<<endl;
			
			encontrado = true;
			break; 
		}
	}
	
	if(!encontrado)
	{
		cout<<"Canción no encontrada."<<endl;
	}
	
}

void actualizar()
{
	int codigoBuscado;
	bool encontrado = false;
	
	cout<<"\n===== ACTUALIZAR CANCIÓN ====="<<endl;
	
	cout<<"Ingrese el código de la canción: ";
	cin>>codigoBuscado;
	
	cin.ignore();
	
	// Modifica los datos de la canción encontrada
	for(int i=0; i<totalCanciones; i++)
	{
		if(lista[i].codigo==codigoBuscado)
		{
			cout<<"\nIngrese los nuevos datos: "<<endl;
			
			cout<<"Nuevo título: ";
			getline(cin, lista[i].titulo);
			
			cout<<"Nuevo artista: ";
			getline(cin, lista[i].artista);
			
			cout<<"Nuevo género: ";
			getline(cin, lista[i].genero);
			
			cout<<"Nueva duración: ";
			cin>>lista[i].duracion;
			
			encontrado=true;
			
			cout<<"\nCanción actualizada correctamente."<<endl;
			
			break;
		}
	}
	if(!encontrado)
	{
		cout<<"Canción no encontrada."<<endl;
	}
}

void eliminar()
{
	int codigoBuscado;
	bool encontrado=false;
	
	cout<<"\n====== ELIMINAR CANCIÓN ======"<<endl;
	
	cout<<"Ingrese el código de la canción: ";
	cin>>codigoBuscado;
	
	// Buscar canción por código
	for(int i=0; i<totalCanciones; i++)
	{
		if(lista[i].codigo==codigoBuscado)
		{
			// Desplaza los elementos hacia la izquierda
			for(int j=i; j<totalCanciones-1; j++)
			{
				lista[j]=lista[j+1];
			}
			
			// Reduce la cantidad de canciones 
			totalCanciones--;
			encontrado=true;
			
			cout<<"\nCanción eliminada correctamente."<<endl;
			
			break;
		}
	}
	if(!encontrado)
	{
		cout<<"Canción no encontrada."<<endl;
	}
}

void ordenar()
{
	// Uso de Bubble Sort
	// Ordenamiento alfabético
	Cancion auxiliar;
	
	for(int i=0; i<totalCanciones-1; i++)
	{
		for(int j=0; j<totalCanciones-i-1; j++)
		{
			// Compara títulos consecutivos
			if(lista[j].titulo>lista[j+1].titulo)
			{
				// Intercambia posiciones de las canciones
				auxiliar=lista[j];
				lista[j]=lista[j+1];
				lista[j+1]=auxiliar;
			}
		}
	}
	
	cout<<"\nCanciones ordenadas correctamente."<<endl;
}

bool codigoExiste(int codigo)
{
	for(int i=0; i<totalCanciones; i++)
	{
		if(lista[i].codigo==codigo)
		{
			return true;
		}
	}
	
	return false;
}




















