#include <stdio.h>
#include <stdlib.h>


struct bst
{
    int value;
    struct bst *left;
    struct bst *right;

} bst;

struct bst* create_tree ( int value) {
    // kök oluşturma
    struct bst *root  = (struct bst*) malloc (sizeof(struct bst));

    // değer girme
    root-> value = value;
    
    // sağ sol kök NULL başlatma
    root->left = NULL;
    root->right = NULL;

    return root;
}

void insert (struct bst *root, int value){
    // kök boş mu bak
    if (root == NULL){
        printf("kok bos! \n");
        return;
    }
    // eklenecek değer kökten küçükse
    if (root->value > value) {
        if( root->left == NULL){
            root->left = create_tree(value);
        }
        else {
            insert (root->left, value);
        }
    }
    else{
        if (root->right == NULL) {
            root->right = create_tree(value);
        }
        else {
            insert (root -> right, value);
        }
    }
}

void inorder (struct bst *root){
    // inorder : sol-kök-sağ
    if (root == NULL)
        return;

    
    inorder (root->left);
    printf ("%d ",root->value);
    inorder (root->right);


}

void search (struct bst *root, int value ){
    // kök boş mu bak
    if (root == NULL){
        printf("deger bulunamadi \n");
        return;
    }
    if ( root ->value == value){
        printf ("deger bulundu =%d \n",value);
        return;
    }
    struct bst* tmp = root;
    if (root ->value > value){
        search (root->left, value);
    }
    if (root -> value < value){
        search (root ->right,value);
    }

}

int _max (int val1, int val2){
    return (val1>val2) ?val1: val2;
}

int depth ( struct bst * root){
    if (root == NULL)
        return 0;
    return 1 + _max (depth(root->left),depth(root->right));
}


int main(){

    int input_array[] = {1,2,3,4,5,6,7,8,10,11,9};
    int N = sizeof (input_array) / sizeof (input_array[0]);

    struct bst *TREE = create_tree(input_array[0]);
    for ( int i = 1; i < N; ++i)
    {
        insert (TREE,input_array[i]);
    }
    
    inorder (TREE);
    printf( "\n");

    search (TREE,5);  

    int depth_val = depth(TREE);
    printf ("derinlik = %d\n",depth_val);

    free (TREE);
    return 0;
}