//Aquí tienes un ejemplo de un programa en C++ que cumple con los requisitos que mencionaste. 
//Este programa utiliza vectores para almacenar la información de álbumes, artistas y canciones, 
//y utiliza un menú con las opciones que mencionaste:

#include <iostream>
#include <vector>
using namespace std;

// Estructura para representar una canción
struct Cancion {
    string nombre;
    int duracion;
};

// Estructura para representar un artista
struct Artista {
    string nombre;
    vector<Cancion> canciones;
};

// Estructura para representar un álbum
struct Album {
    string nombre;
    vector<Artista> artistas;
};

int main() {
    vector<Album> albums;
    
    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Ingresar álbum" << endl;
        cout << "2. Ingresar artista" << endl;
        cout << "3. Ingresar canciones" << endl;
        cout << "4. Visualizar álbumes, artistas y canciones" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";
        
        int opcion;
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                Album nuevoAlbum;
                cout << "Ingrese el nombre del álbum: ";
                cin >> nuevoAlbum.nombre;
                albums.push_back(nuevoAlbum);
                break;
            }
            case 2: {
                if (albums.empty()) {
                    cout << "Primero ingrese un álbum." << endl;
                } else {
                    int albumIndex;
                    cout << "Elija un álbum (1-" << albums.size() << "): ";
                    cin >> albumIndex;
                    albumIndex--;

                    Artista nuevoArtista;
                    cout << "Ingrese el nombre del artista: ";
                    cin >> nuevoArtista.nombre;
                    albums[albumIndex].artistas.push_back(nuevoArtista);
                }
                break;
            }
            case 3: {
                if (albums.empty()) {
                    cout << "Primero ingrese un álbum." << endl;
                } else {
                    int albumIndex;
                    cout << "Elija un álbum (1-" << albums.size() << "): ";
                    cin >> albumIndex;
                    albumIndex--;

                    int artistaIndex;
                    cout << "Elija un artista (1-" << albums[albumIndex].artistas.size() << "): ";
                    cin >> artistaIndex;
                    artistaIndex--;

                    Cancion nuevaCancion;
                    cout << "Ingrese el nombre de la canción: ";
                    cin >> nuevaCancion.nombre;
                    cout << "Ingrese la duración de la canción (en segundos): ";
                    cin >> nuevaCancion.duracion;

                    albums[albumIndex].artistas[artistaIndex].canciones.push_back(nuevaCancion);
                }
                break;
            }
            case 4: {
                cout << "Álbumes, artistas y canciones:" << endl;
                for (int i = 0; i < albums.size(); i++) {
                    cout << "Álbum " << i + 1 << ": " << albums[i].nombre << endl;
                    for (int j = 0; j < albums[i].artistas.size(); j++) {
                        cout << "  Artista: " << albums[i].artistas[j].nombre << endl;
                        cout << "  Canciones:" << endl;
                        for (int k = 0; k < albums[i].artistas[j].canciones.size(); k++) {
                            cout << "    " << albums[i].artistas[j].canciones[k].nombre << " (Duración: " << albums[i].artistas[j].canciones[k].duracion << " segundos)" << endl;
                        }
                    }
                }
                break;
            }
            case 5: {
                cout << "Saliendo del programa." << endl;
                return 0;
            }
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
                break;
        }
    }
    
    return 0;
}


//Este programa utiliza estructuras para representar álbumes, artistas y canciones, 
//y un vector para almacenar la información. El menú permite al usuario realizar varias acciones, como ingresar álbumes, 
//artistas y canciones, y ver la información almacenada.