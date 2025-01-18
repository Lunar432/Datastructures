#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

struct node *createNewNode(int value)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    tempNode->data = value;
    tempNode->leftChild = tempNode->rightChild = NULL;
    return tempNode;
}
struct node *addToTree(int data)
{
    struct node *newNode;
    newNode = createNewNode(data);
    struct node *current, *parent;
    if (root == NULL) // empty tree
    {
        root = newNode;
        return root;
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current; // sets parent to updated current pointer
            if (parent->data > data)
            {
                current = current->leftChild; // updates current pointer to leftChild
                if (current == NULL)
                {
                    parent->leftChild = newNode;
                    return root;
                }
            }
            else if (parent->data < data)
            {
                current = current->rightChild;
                if (current == NULL)
                {
                    parent->rightChild = newNode;
                    return root;
                }
            }
        }
    }
}

struct node* findMin(struct node* root) {
    while (root->leftChild != NULL)
        root = root->leftChild;
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root; // Tree is empty
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->leftChild = deleteNode(root->leftChild, key);
    } else if (key > root->data) {
        root->rightChild = deleteNode(root->rightChild, key);
    } else {
        // Node to delete found
        // Case 1: Node has no children (leaf node)
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child
        else if (root->leftChild == NULL) {
            struct node* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            struct node* temp = root->leftChild;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else {
            struct node* temp = findMin(root->rightChild); // Find in-order successor
            root->data = temp->data; // Replace data with successor
            root->rightChild = deleteNode(root->rightChild, temp->data); // Delete successor
        }
    }
    return root;
}

struct node *search(int key)
{
    struct node *current;
    current = root;
    while (current != NULL && current->data != key)
    {
        if (current->data > key)
        {
            current = current->leftChild;
        }
        else if (current->data < key)
        {
            current = current->rightChild;
        }
    }
    return current;
}

void preorder(struct node *root)
{
    // root -> left -> right
    if (root != NULL)
    {
        printf("%d -> ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}
void inorder(struct node *root)
{
    // left -> root -> right
    if (root != NULL)
    {
        inorder(root->leftChild);
        printf("%d -> ", root->data);
        inorder(root->rightChild);
    }
}
void postorder(struct node *root)
{
    // left -> right -> root
    if (root != NULL)
    {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d -> ", root->data);
    }
}

int main()
{
    int n;
    // creating the tree
    printf("\nNumber of elements in the tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = rand() % 100;
        addToTree(temp);
    }
    // all traversals
    printf("\nTraversing the tree:\n\n");
    printf("Preorder traversing:\n");
    preorder(root);
    printf("\nInorder traversing:\n");
    inorder(root);
    printf("\nPostorder traversing:\n");
    postorder(root);

    // search the key
    int key;
    struct node *element;
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    element = search(key);
    if (element == NULL)
        printf("Element not found!");
    else
    {
        printf("Element is found.");
    }

    // Deleting
    int delItem;
    printf("\nEnter item to delete: ");
    scanf("%d", &delItem);
    root = deleteNode(root, delItem);
    printf("\nAfter deletion, In-Order Traversing: \n");
    inorder(root);
    return 0;
}