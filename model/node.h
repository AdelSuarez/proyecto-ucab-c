
// ADD NODE ------------------------------------------------
template <typename T>
void addNode(T *&list, T *node, bool isFile){

    if (list == NULL){
        list = node;

    } else {
        T *current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = node;

    }
    if (!isFile){
        cout << BLACK GREENB "\tAgregado con exito" NC;
    }
    
}

template <typename N>
void removeNode(N *&list, N *current, N *previous) {

    if (current == NULL) {
        cout << BLACK REDB " Articulo no encontrado!" NC;
        _getch();
        return;
    }
    if (previous == NULL) { // El artículo a eliminar es el primer elemento
        list = current->next;
    } else { // El artículo a eliminar está en medio o al final de la lista
        previous->next = current->next;
    }
    delete current;
    cout << BLACK GREENB " Articulo borrado con exito!" NC;
    _getch();
}

template <typename N>
bool isDuplicate(N *&list, long long int dni) {
    N * current = list;
    while ( current != NULL) {
        if (current->person.dni == dni){
            return true;
        }
        current = current->next;
    }
    return false;
}


// SEARCH
template <typename N>
N* find(N *&list, long long int dni, N *&previous) {
    N *current = list;
    previous = NULL;

    while (current != NULL && current->person.dni != dni) {
        previous = current;
        current = current->next;
    }

    return current;
}


