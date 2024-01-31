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

    std::shared_ptr<ShoppingList> listaSpesa1 = std::make_shared<ShoppingList>("listaSpesa1");
    listaSpesa1->addItem("frutta", "mela", 5, true);
    listaSpesa1->addItem("verdura", "carota");
    std::shared_ptr<ShoppingList> listaSpesa2 = std::make_shared<ShoppingList>("listaSpesa2");
    listaSpesa2->addItem("frutta", "mela", 3);
    listaSpesa2->addItem("frutta", "pera");
    listaSpesa2->addItem("pesce", "merluzzo", 0, true);
    User ale = User("alessia");
    User gid = User("giada");
    ale.addList(listaSpesa1);
    ale.addList(listaSpesa2);
    gid.addList(listaSpesa2);
    ale.displayAll();
    gid.displayAll();

    std::cout << std::endl;
    std::cout << std::endl;

    ale.removeList(listaSpesa1);
    listaSpesa2->removeItem("frutta", "mela");
    listaSpesa2->setItemBought("frutta", "pera");
    listaSpesa2->setItemToBuy("pesce", "merluzzo");
    listaSpesa2->setItemBought("frutta", "arancia");
    ale.displayAll();

    return 0;
}