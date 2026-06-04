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
int buscarIndice(int codigo);

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
	// Solicita un código y utiliza buscarIndice()
	// para localizar la canción en la lista
	int codigoBuscado;
	
	cout<<"\n======= BUSCAR CANCIÓN ======="<<endl;
	
	cout<<"Ingrese el código: ";
	cin>> codigoBuscado;
	
	int indice = buscarIndice(codigoBuscado);
	
	if(indice != -1)
	{
		cout<<"\n===== Canción encontrada ====="<<endl;
		
		cout<<"Código: "<<lista[indice].codigo<<endl;
		cout<<"Título: "<<lista[indice].titulo<<endl;
		cout<<"Artista: "<<lista[indice].artista<<endl;
		cout<<"Género: "<<lista[indice].genero<<endl;
		cout<<"Duración: "<<lista[indice].duracion<<" min"<<endl;
	}
	else
	{
		cout<<"Canción no encontrada."<<endl;
	}
}

void actualizar()
{
	int codigoBuscado;
	
	cout<<"\n===== ACTUALIZAR CANCIÓN ====="<<endl;
	
	cout<<"Ingrese el código de la canción: ";
	cin>>codigoBuscado;
	
	cin.ignore();
	
	int indice=buscarIndice(codigoBuscado);
	
	// Modifica los datos de la canción encontrada
	if(indice!=-1)
	{
		cout<<"\nIngrese los nuevos datos: "<<endl;
		
		cout<<"Nuevo título: ";
		getline(cin, lista[indice].titulo);
		
		cout<<"Nuevo artista: ";
		getline(cin, lista[indice].artista);
		
		cout<<"Nuevo género: ";
		getline(cin, lista[indice].genero);
		
		cout<<"Nueva duración: ";
		cin>>lista[indice].duracion;
		
		cout<<"\nCanción actualizada correctamente."<<endl;
	}
	else
	{
		cout<<"Canción no encontrada."<<endl;
	}
	
}

void eliminar()
{
	int codigoBuscado;
	
	
	cout<<"Ingrese el código de la canción: ";
	cin>>codigoBuscado;
	
	int indice=buscarIndice(codigoBuscado);
	
	// Buscar canción por código
	if(indice!=-1)
	{
		// Desplaza los elelmentos para llenar el espacio vacio
		for(int j=indice; j<totalCanciones-1; j++)
		{
			lista[j]=lista[j+1];
		}
		
		totalCanciones--;
		
		cout<<"\nCanción eliminada correctamente."<<endl;
	}
	else
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

// Devuelve la posición de la canción si existe.
// Si no la encuentra, devuelve -1.
int buscarIndice(int codigo)
{
	for(int i=0; i<totalCanciones; i++)
	{
		if(lista[i].codigo==codigo)
		{
			return i;
		}
	}
	return -1;
}
