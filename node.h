typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node* make_node(char data, Node* next);
