// #include "../settings/style.h"
// #include <iostream>
// #include <string>


// ADD NODE ------------------------------------------------
template <typename T>
void addNode(T *&list, T *node, bool isFile, void (*fileUploadFunc)(T *&)){

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
        cout << BLACK GREENB "\tAgregado con exito" NC << endl << endl;
    }

    fileUploadFunc(list);
    
}