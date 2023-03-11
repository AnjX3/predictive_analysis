// C program to demonstrate predictive analysis -binary Decision tree for Deck of cards
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dispcard[20];
int i;
struct node
{
    int key;
    struct node *left, *right;
};

// create a new node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//  inorder traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
/* insert a new node with given key in decision tree */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}
// search a given key
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
int  traverse(struct node* root)
{
    char myChoice;
    i++;
    // Base Cases: root is null or key is present at root
    if ((root->left == NULL)&&(root->right==NULL) )
       return root->key;
   printf("\n whether your card less than %d\n", root->key);
   myChoice=getche();

    if(myChoice=='y')
    {
            if(root->left==NULL)
            {
             return(root->key);
            }
            else
            {
              dispcard[i]=root->key;
              traverse(root->left);
            }
    }
    else
    {
        printf("\n whether your card greater than %d\n", root->key);
        myChoice=getche();
            if(myChoice=='y')
            {
                if(root->right==NULL)
                {
                    return(root->key);
                }
                else
                {
                    dispcard[i]=root->key;
                    traverse(root->right);
                }
            }
            else{
                return root->key;
            }

    }

}


int main()
{
char ans;
 int mycard,j,k;
    struct node *root = NULL;
    //tree for deck of card for either diamond or heart or club or spade
    root = insert(root, 7);
    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 11);
    insert(root, 9);
    insert(root, 8);
    insert(root, 10);
    insert(root, 13);
    insert(root, 12);
    printf("\n\n\n\n\n..........Choose a card in your mind from a deck of cards...........\n\n\n");
    printf("Deck of Cards::DIAMOND::HEART::CLUB::SPADE::\n");
    printf("                            7                 \n");
    printf("                      /         \\                \n");
    printf("                  4                 J           \n");
    printf("               /        \\       /      \\      \n");
    printf("            2             6     9           K     \n");
    printf("          /   \\         /     /  \\      /        \n");
    printf("         1     3       5     8     10    Q     \n");


    inorder(root);

    printf("\n Whether your card is Red?............. <y/n> \n");
    ans=getche();
    if(ans=='y')
    {
     dispcard[0]=18;
     printf("\n Whether your card Diamond?...............<y/n>\n");
     ans=getche();
        if(ans=='y')
        {
            dispcard[1]=4;
        }
        else
        {
            dispcard[1]=3;
        }
    }
    else
    {
        dispcard[0]=19;
        printf("\n Whether your card Club?...............<y/n>\n");
        ans=getche();
        if(ans=='y')
        {
            dispcard[1]=5;
        }
        else
        {
            dispcard[1]=6;
        }
    }
    i=1;
    mycard=traverse(root);
    dispcard[i]=mycard;

    for(j=0;j<i;j++)
    {
        if(dispcard[j]==18 && dispcard[j+1]==4)
            printf("\nDIAMOND%c%c(RED):: A,2,3,4,5,6,7,8,9,10,J,Q,K\n\n",4,4);
        else if(dispcard[j]==18 && dispcard[j+1]==3)
            printf("\nHEART%c%c(RED):: A,2,3,4,5,6,7,8,9,10,J,Q,K\n\n",3,3);
        else if(dispcard[j]==19 && dispcard[j+1]==5)
            printf("\nCLUB%c%c(BLACK):: A,2,3,4,5,6,7,8,9,10,J,Q,K\n",5,5);
        else if(dispcard[j]==19 && dispcard[j+1]==6)
            printf("\nSPADE%c%c(BLACK):: A,2,3,4,5,6,7,8,9,10,J,Q,K\n",6,6);
        else
          {printf("    %d\n",dispcard[j+1]);
            printf("    |\n");
        printf("    |\n");}

    }

     printf("\n\nYour choice card is................. ");
    if(mycard==1)
        printf("A%c",dispcard[1]);
    else if(mycard==11)
        printf("J%c",dispcard[1]);
    else if(mycard==12)
        printf("Q%c",dispcard[1]);
    else if(mycard==13)
        printf("K%c",dispcard[1]);
    else
    printf("%d%c\n",mycard,dispcard[1]);
    getche();
    return 0;
}
