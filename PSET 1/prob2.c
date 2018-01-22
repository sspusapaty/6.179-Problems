#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_node {
    struct huffman_node *left;
    struct huffman_node *right;
    char letter;
} Node;

Node* newNode(char letter)
{
    // Allocate memory for new node
    Node* node = (Node*)malloc(sizeof(Node));
    
    // Assign data to this node
    node->letter = letter;
    
    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void addToBST(Node* root, char letter,char* code){
    int len = strlen(code);
    Node* charNode = newNode(letter);
    Node* parentNode = root;
    //printf("key1:%c\n", root->letter);
    int index = 0;
    while(1){
        //printf("key2:%c\n", parentNode->letter);
        if (index != len-1)
        {
            if (code[index] == '0')
            {
                if (parentNode->left == NULL){
                    Node* currNode = newNode('\0');
                    parentNode->left = currNode;
                }
                parentNode = parentNode->left;
            }
            else if (code[index] == '1')
            {
                if(parentNode->right == NULL){
                    Node* currNode = newNode('\0');
                    parentNode->right = currNode;
                }
                parentNode = parentNode->right;
            }
        }
        else{
            if (code[index] == '0'){
                parentNode->left = charNode;
                //printf("key3:%c\n", parentNode->left->letter);
            }
            else if (code[index] == '1'){
                parentNode->right = charNode;
                //printf("key4:%c\n", parentNode->right->letter);
            }
            break;
        }
        index++;
    }
}

Node* buildBST(int N){
    Node* root = newNode('\0');
    for(int i = 0;i<N;i++)
    {
        char letter = 'B';
        char* code = "0100";
        addToBST(root,letter,code);
        
        letter = 'C';
        code = "0110";
        addToBST(root,letter,code);
        
        letter = 'D';
        code = "11";
        addToBST(root,letter,code);
    }
    //printf("key5:%c\n",root->left->right->right->left->letter);
    return root;
}

void decodeHuff(Node* root, char *string, int N){
    int len = strlen(string);
    Node* start = root;
    //printf("key6:%c\n",start->left->right->right->left->letter);
    for(int i = 0;i<len;i++){
        //printf("%c\n",start->letter);
        if (string[i] == '0'){
            if (start->left != NULL){
                //printf("A:%i\n",i);
                start = start->left;
                //printf("key9:%c\n",start->right->right->left->letter);
            }
            else if (start->left == NULL && start->right == NULL){
                //printf("B:%i\n",i);
                //printf("%c",start->letter);
                start = root;
                //printf("key7:%c\n",start->left->right->right->left->letter);
            }
        }
        else if (string[i] == '1'){
            if (start->right != NULL){
                //printf("C:%i\n",i);
                start = start->right;
            }
            else if (start->left == NULL && start->right == NULL){
                //printf("D:%i\n",i);
                //printf("%c",start->letter);
                start = root;
                //printf("key8:%c\n",start->left->right->right->left->letter);
            }
        }
        if (start->left == NULL && start->right == NULL){
            printf("%c",start->letter);
            start = root;
        }
    }
}

int main()
{
    int N;
    scanf("%d\n", &N);
    Node* root = newNode('\0');
    char letter;
    char* nums;
    char code[N];
    for(int i = 0; i<N;i++){
        scanf("%s", code);
        letter = code[0];
        nums = &code[1];
        if(letter=='0' || letter=='1'){
            letter = ' ';
            nums = &code[0];
        }
        addToBST(root,letter,nums);
    }
    char string[100];
    scanf("%s",string);
    decodeHuff(root, string, N);
    return 0;
}
