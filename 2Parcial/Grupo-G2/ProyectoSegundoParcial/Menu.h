#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Operacion.h"
#include "shunting_yard.hpp"
#include "Login.h"
#include "Marquesina.h"
#pragma warning(disable:4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;
void marquee_limit(std::string text, size_t limit);
void menu_principal();
void Color(int Background, int Text);
void gotoxy(USHORT x, USHORT y) {
    COORD cp = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void Color(int Background, int Text) { // Función para cambiar el color del fondo y/o pantalla
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
    // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
    // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
    int    New_Color = Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
int menu(const char titulo[], const char* opciones[], int n);
int menu2(const char titulo[], const char* opciones[], int n);
void menu_inicio();
void menu_inicio() {
    bool repite = true;
    int opcion2;
    int n = 3;
    std::string user_admin;// = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
    std::string password_admin;// = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
    std::string test = "GRUPO #2 UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
    std::thread t2(marquee_limit, test, test.size());

    const char* titulo = "\n\tMENU DE OPCIONES";
    const char* opciones[] = { "\tCREAR USUARIO", "\tINGRESAR","\tSALIR" };
    do {
        system("cls");
        fflush(stdin);
        opcion2 = menu(titulo, opciones, n);
        switch (opcion2) {
        case 1: {
            std::cout << "\n\n\tDesea Crear un nuevo administrador[s/n]: ";
            char option = 0;
            std::cin >> option;
            std::cin.ignore();
            if (option == 's' || option == 'S')
            {
                system("cls");
               std::cout << "\nIngrese los datos del administrador principal: " << std::endl;
                user_admin = Utils::Validation::read_string("Ingrese el usuario: ", Utils::InputType::USER);
                password_admin = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
                std::cout << std::endl;
                if (Utils::File::read_file(user_admin, password_admin)) {
                    std::cout<<"El usuario ya existe, intente nuevamente."<<std::endl;
                }
                else {
                    Utils::Generator::generate_admins(user_admin, password_admin);
                    std::cout << "\tUsuario creado con exito" << std::endl;
                }
                
            }
            system("pause");
            break;
        }
        case 2: {
            std::cout << "\n\n" << std::endl;
            
            std::string user= Utils::Validation::read_string("\n\tIngrese el usuario: ", Utils::InputType::USER);
            std::string pass= Utils::Validation::read_string("\n\tIngrese la contraseña: ", Utils::InputType::PASSWORD);
            std::cout << std::endl;
            if (user_admin._Equal(user) && password_admin._Equal(pass)) {
                menu_principal();
            }
            else{
                std::cout << "\nUSUARIO O CONTRASENIA INCORRECTO" << std::endl;
            }
            
            if (!Utils::File::exists_file("user.txt"))
            {
                std::cout << "NO EXISTE NINGUN ADMINISTRADOR PRINCIPAL" << std::endl;
                std::string user2 = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
                std::string password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
                Utils::Generator::generate_admins(user2, password);
                std::cout << "\nAdministrador principal creado" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                //main_menu();
                break;
            }
            system("pause");
            break;
        }

        case 3: {
            repite = false;
            exit(0);
            break; }



        } 

    } while (repite);
}
void menu_principal()
{
    std::string test = "GRUPO #2 UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
    std::thread t2(marquee_limit, test, test.size());
    cout << "\n";
    bool repite = true;
    int opcion;
    string exprecion;
    ShuntingYard::RPN rpn;
    ShuntingYard::Node* tree;
    // Titulo del menú y nombres de las opciones
    const char* titulo = "\n\tMENU DE OPCIONES";
    const char* opciones[] = { "\tNotacion infija", "\tNotacion prefija","\tNotacion postfija", "\tSalir" };
    Operacion op;
    float resultado;
    string infix = "";
    ShuntingYard::variables["x"] = 15;
    int n = 4;  // Numero de opciones
    Marquesina mark1("---BIENVENIDOS A NUESTRO PROGRAMA---");
   // mark1.transicion();
    cout << "\n";
    do {
        system("cls");
        mark1.transicion();
        opcion = menu(titulo, opciones, n);
        //mark1.transicion();
        switch (opcion) {
        case 1:
            system("cls");
            do {
                cout << "\n\nIngrese la expresion infija:";
                cin >> exprecion;

            } while (!op.is_infix(exprecion));
            rpn = ShuntingYard::reversePolishNotation(exprecion.c_str());
            tree = ShuntingYard::parse(rpn);
            std::cout << "El resultado de la operacion es: " << ShuntingYard::eval(tree) << std::endl;
            cout << "Notacion prefija:" << op.infix_a_prefix(exprecion) << endl;
            infix = op.infix_a_prefix(exprecion);
            cout << "Notacion postfija: " << op.prefix_a_postfix(infix) << endl;
            mark1.transicion();
            cout << "\n\n";
            system("pause");
            break;
        case 2:
            system("cls");
            do {
                cout << "\n\nIngrese la expresion prefija:";
                cin >> exprecion;
            } while (!op.is_prefix(exprecion));

            cout << "Notacion infija:" << op.prefix_a_infix(exprecion) << endl;
            cout << "Notacion postfija:" << op.prefix_a_postfix(exprecion) << endl;
            rpn = ShuntingYard::reversePolishNotation((op.prefix_a_infix(exprecion)).c_str());
            tree = ShuntingYard::parse(rpn);
            std::cout << "El resultado de la operacion es: " << ShuntingYard::eval(tree) << std::endl;
            
            mark1.transicion();
            cout << "\n\n";
            system("pause");
            break;
        case 3:
            system("cls");
            do {
                cout << "\n\nIngrese la expresion postfija:";
                cin >> exprecion;
            } while (!op.is_postfix(exprecion));
            cout << "Notacion prefija:" << op.postfix_a_prefix(exprecion) << endl;
            cout << "Notacion infija:" << op.postfix_a_infix(exprecion) << endl;
            rpn = ShuntingYard::reversePolishNotation((op.postfix_a_infix(exprecion)).c_str());
            tree = ShuntingYard::parse(rpn);
            std::cout << "El resultado de la operacion es: " << ShuntingYard::eval(tree) << std::endl;
            //cout << "Notacion funcional:" << op.postfix_a_funtional(exprecion) << endl;
            mark1.transicion();
            cout << "\n\n";
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\nGracias por utilizar nuestro programa" << endl;
            repite = false;
            system("pause>nul");
            exit(0);
            //t2.join();
            break;
        }

    } while (repite);
}
void marquee_limit(std::string text, size_t limit) {
    bool ciclo = true;
    while (ciclo)
    {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        SetConsoleTitleA(text.substr(0, limit).c_str());
        if (GetAsyncKeyState(VK_F2)) {//RETURN
            ciclo = false;
            break;
        }

    }
}

int menu(const char titulo[], const char* opciones[], int n)
{

    int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
    int tecla;
    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
    do {
        system("cls");
        //  system("color ");
        gotoxy(5, 3 + opcionSeleccionada);  Color(1, 2); cout << "==>" << endl;
        Color(0, 15);
        // Imprime el título del menú
        gotoxy(15, 2); cout << titulo;
        // Imprime las opciones del menú
        for (int i = 0; i < n; ++i) {
            gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
        }
        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
        do {
            tecla = getch();
            // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch (tecla) {
        case ARRIBA:   // En caso que se presione ARRIBA
            opcionSeleccionada--;
            if (opcionSeleccionada < 1) {
                opcionSeleccionada = n;
            }
            break;
        case ABAJO:
            opcionSeleccionada++;
            if (opcionSeleccionada > n) {
                opcionSeleccionada = 1;
            }
            break;
        case ENTER:
            repite = false;
            break;
        }
    } while (repite);
    return opcionSeleccionada;
}

//int menu2(const char titulo[], const char* opciones[], int n)
//{
//
//    int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
//    int tecla;
//    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
//    do {
//        system("cls");
//        //  system("color ");
//        gotoxy(5, 3 + opcionSeleccionada);  Color(2, 2); cout << "==>" << endl;
//        Color(0, 15);
//        // Imprime el título del menú
//        gotoxy(15, 2); cout << titulo;
//        // Imprime las opciones del menú
//        for (int i = 0; i < n; ++i) {
//            gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
//        }
//        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
//        do {
//            tecla = getch();
//            // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
//        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
//        switch (tecla) {
//        case ARRIBA:   // En caso que se presione ARRIBA
//            opcionSeleccionada--;
//            if (opcionSeleccionada < 1) {
//                opcionSeleccionada = n;
//            }
//            break;
//        case ABAJO:
//            opcionSeleccionada++;
//            if (opcionSeleccionada > n) {
//                opcionSeleccionada = 1;
//            }
//            break;
//        case ENTER:
//            repite = false;
//            break;
//        }
//    } while (repite);
//    return opcionSeleccionada;
//}