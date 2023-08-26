#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main () {
    
}

int findSecondMinimumValueStep( struct TreeNode* root, int rootValue );

/*
====================
findSecondMinimumValue
    Função responsável por chamar a função principal, passando como
    parâmetro certos dados da raiz, os quais serão utilizados para
    encontrar o 2° menor valor da árvore
====================
*/

int findSecondMinimumValue( struct TreeNode* root ) {
    if ( root == NULL ) {
        return -1;
    }

    return findSecondMinimumValueStep( root, root->val );
}

/*
====================
findSecondMinimumValueStep
    Função recursiva que itera sobre os nodos da árvore até
    encontrar o primeiro que tenha valor diferente ao da raiz
====================
*/

int findSecondMinimumValueStep( struct TreeNode* root, int rootValue ) {
    if ( root == NULL ) {
        return -1;
    }

    if ( root->val != rootValue ) {
        return root->val;
    }
    
    int x, y;

    x = findSecondMinimumValueStep( root->left, rootValue );
    y = findSecondMinimumValueStep( root->right, rootValue );
        
    if ( x == -1 ) return y;
    if ( y == -1 ) return x;
    if ( x < y ) {
        return x; 
    } else {
        return y;
    }
}