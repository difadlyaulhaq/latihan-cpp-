#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    cout << node->data;
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data;
    printInorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data;
}

int main()
{
    cout<<"Nama : Difa dlyaul Haq"<<endl;
    cout<<"NIM: 22.61.0234"<<endl;
    cout << "===================" << endl;
    struct node* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');
    root->left->right->left = newNode('G');
    root->right->left->right = newNode('H');

    cout << "== TRAVERSAL PADA BINARY TREE ==" << endl << endl;
    
    cout << "Kunjungan Preorder" << endl;
    cout << "===================" << endl;
    printPreorder(root);
    
    cout << endl << endl;
    
    cout << "Kunjungan Inorder" << endl;
    cout << "==================" << endl;
    printInorder(root);

    cout << endl << endl;

    cout << "Kunjungan Postorder" << endl;
    cout << "====================" << endl;
    printPostorder(root);

    return 0;
}
