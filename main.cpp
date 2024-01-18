#include <iostream>

#include "ShoppingList.h"
#include "User.h"

/*
(12) Classi che rappresentano una lista della spesa (es. Listonic):
Un utente può avere diverse liste della spesa dove segnare oggetti da acquistare
che appartengono a diverse categorie ed eventualmente con quantità da acquistare.
Si usa Observer per aggiornare il numero di oggetti da acquistare in una lista e
quali questi siano. Si possono avere più utenti che condividono la stessa lista.
*/

int main() {

    ShoppingList listaSpesa1("listaSpesa1");
    listaSpesa1.addItem("frutta", "mela", 5);
    listaSpesa1.addItem("verdura", "carota");
    ShoppingList listaSpesa2("listaSpesa2");
    listaSpesa2.addItem("frutta", "mela", 3);
    listaSpesa2.addItem("frutta", "pera");
    listaSpesa2.addItem("pesce", "merluzzo", 0);
    User ale = User("alessia");
    User gid = User("giada");
    ale.addList(&listaSpesa1);
    ale.addList(&listaSpesa2);
    gid.addList(&listaSpesa2);
    ale.displayAll();
    gid.displayAll();

    std::cout << std::endl;
    std::cout << std::endl;

    ale.removeList(&listaSpesa2);
    ale.displayAll();

    return 0;
}