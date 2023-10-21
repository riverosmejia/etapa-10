#include <iostream>

using namespace std;

#include <limits> // Necesario para std::numeric_limits
#include <climits> // Necesario para std::streamsize

//eleccion de que librería usar dependiendo del entorno del sistema:

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#include <cstdlib>
#endif

//fin de la elección.

//funcion para limpiar pantalla:
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif
}

void pauseProgram() {
    std::cout << "Presiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// definición de la estructura del nodo del árbol:

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Función para insertar un número en el árbol
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        root = new TreeNode;
        root->data = value;
        root->left = root->right = nullptr;
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Función para buscar un número en el árbol
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

int safeInput() {
    int number;
    while (!(std::cin >> number)) {
        std::cin.clear(); // Restablecer el estado del flujo de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada incorrecta
        std::cout << "Entrada invalida. Ingrese un numero: ";
    }
    return number;
}

// Función para dibujar el árbol en orden
void display(TreeNode* root) {
    if (root != nullptr) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    int choice;
    int number;

    do {
        cout << "Menu:\n";
        cout << "1. Ingresar un numero\n";
        cout << "2. Buscar un numero\n";
        cout << "3. Observar el arbol\n";
        cout << "4. Salir\n";
        cout << "Elija una opcion: ";
        cin >> choice;



        switch (choice) {
            case 1:
            
                clearScreen();

                cout << "Ingrese un numero: ";
                number = safeInput();
 
                root = insert(root, number);
                
                cout<<"\n\n";
                pauseProgram();
                clearScreen();

                break;
 
            case 2:
 
                clearScreen();

                cout << "Ingrese el numero a buscar: ";
                cin >> number;
                
                if (search(root, number)) {
                    cout << "El numero existe en la estructura.\n";
                }
                else {
                    cout << "El numero no existe en la estructura.\n";
                }
                
                cout<<"\n\n";
                pauseProgram();
                clearScreen();

                break;
            case 3:
                clearScreen();

                cout << "Arbol ordenado: ";
                display(root);
                cout << "\n";

                cout<<"\n\n";
                pauseProgram();
                clearScreen();

                break;
            case 4:
                clearScreen();

                cout << "Saliendo del programa.\n";
                break;

            default:
                
                clearScreen();

                cout << "Opcion invalida. Intente de nuevo.\n";
                
                cout<<"\n\n";
                pauseProgram();
                clearScreen();                

                break;
        }
    } while (choice != 4);

    // Liberar la memoria del árbol
    // (No se muestra en este ejemplo, pero es importante hacerlo)

    return 0;
}
