#include <iostream>
#include "ContentManager.h"
#include "recommendation_system.hpp"

using namespace std;

void CrearAmisatad1(UserManager& users) {
    cout << "Agregar amigos mutuos!\nAmigo 1: ";
    std::string input;
    cin >> input;

    cout << "Amigo 2: ";
    std::string input2;
    cin >> input2;

    std::cout << "\n";
    
    users.addFriend(input, input2);
}

void Agregarinteres3(UserManager& users) {
    cout << "Usuario: ";
    std::string input;
    std::cin >> input;

    cout << "Categoría: ";
    std::string input2;
    std::cin >> input2;

    cout << "Interés: ";
    std::string input3;
    std::cin >> input3;

    users.addInterest(input, input2, input3);
}

void VerRecomendaciones4(RecommendationSystem& recommendations) {
    std::cout << "Recomendaciones de usuario: ";
    std::string input;
    std::cin >> input;
    std::cout << "\nRecomendaciones: \n";

    recommendations.get_users_from_manager();
    for(auto i: recommendations.recommendContent(input)){
        std::cout << i << "\n";
    }

    std::cout << "\n";
}

void AgregarUsuario5(UserManager& users) {
    cout << "Escriba el nombre del usuario al que quiera añadir: \n";

    std::string input;
    cin >> input;
    
    users.addUser(input);
}

int main() {
    int opcion;
    CategoryManager manager;
    UserManager users;
    RecommendationSystem recommendations(&users);
    string categoria, objeto;

    do {
        // Mostrar menú
        cout << "===== MENÚ =====\n";
        cout << "1. Crear amistad\n";
        cout << "2. Agregar contenido\n";
        cout << "3. Agregar interés a un usuario\n";
        cout << "4. Ver recomendaciones\n";
        cout << "5. Agregar usuario\n";
        cout << "6. Lista de usuarios\n";
        cout << "7. Salir \nInput: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                CrearAmisatad1(users);
                break;
            case 2:
                cout << "Ingrese una categoría: ";
                getline(cin, categoria); // Leer la categoría
                manager.addCategory(categoria);
                cout << "Ingrese un objeto para agregar a la categoría '" << categoria << "': ";
                getline(cin, objeto); // Leer el objeto
                // Agregar el objeto a la categoría
                manager.addObjectToCategory(categoria, objeto);
                break;
            case 3:
                Agregarinteres3(users);
                break;
            case 4:
                VerRecomendaciones4(recommendations);
                break;
            case 5:
                AgregarUsuario5(users);
                break;
            case 6:
                std::cout << "\nUSUARIOS---------\n";
                for(auto i: users.get_users_vector()){
                    std::cout << i.name << "\n";
                }
                std::cout << "\n";
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no valida. Por favor, intenta de nuevo.\n";
                break;
        }

        cout << endl; // Separador para mejor visualización
    } while (opcion != 7);

    return 0;
}
