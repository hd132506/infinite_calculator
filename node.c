#include <stdlib.h>
#include "node.h"

Node* make_node(char data, Node* next) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = next;
    return n;
}
