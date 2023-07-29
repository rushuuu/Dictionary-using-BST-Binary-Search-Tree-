#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Dictionary
{
   char word[128], meaning[256];
   struct Dictionary *left, *right;
};

struct Dictionary *root = NULL;

FILE *fp1;

void insert(char *word, char *meaning);
void deleteNode(char *str);
void findElement(char *str);
void inorderTraversal(struct Dictionary *myNode);
void SearchSimilarWord(struct Dictionary* myNode,char *word);
void writeInFile(char word[128],char meaning[256]);
void openDictionary();

int main(void)
{
   int ch;
   char word[128], meaning[256];
   openDictionary();
   printf("\n ------------DICTIONARY------------ ");
   while (1)
   {
      printf("\n1. Insertion\n2. Deletion\n");
      printf("3. Searching\n4. Traversal\n");
      printf("5. Search Similar Word\n6. Exit\nEnter ur choice:");
      scanf("%d", &ch);
      getchar();
      switch (ch)
      {
      case 1:
         printf("Word to insert:");
         fgets(word, 100, stdin);
         printf("Meaning:");
         fgets(meaning, 256, stdin);
         insert(word, meaning);
         break;
      case 2:
         printf("Enter the word to delete:");
         fgets(word, 100, stdin);
         deleteNode(word);
         break;
      case 3:
         printf("Enter the search word:");
         fgets(word, 100, stdin);
         findElement(word);
         break;
      case 4:
         inorderTraversal(root);
         break;
      case 5:
         printf("Enter the word to search:");
         fgets(word, 100, stdin);
         printf("\nSimilar Words are : \n");
         SearchSimilarWord(root,word);
         break;
      case 6:
         exit(0);
      default:
         printf("You have entered wrong option\n");
         break;
      }
   }
   return 0;
}
struct Dictionary *createNode(char *word, char *meaning)
{
   struct Dictionary *newnode;
   newnode = (struct Dictionary *)malloc(sizeof(struct Dictionary));
   strcpy(newnode->word, word);
   strcpy(newnode->meaning, meaning);
   newnode->left = newnode->right = NULL;
   return newnode;
}

void writeInFile(char word[128],char meaning[256])
{
   
   fp1 = fopen("F:\\DSA Innovative\\first.txt","a");
   fprintf(fp1,"\n");
   fprintf(fp1,"`%s",word);
   fprintf(fp1,"%s",meaning);
   fclose(fp1);
}

int x=0;
void openDictionary(){
   fp1=fopen("F:\\DSA Innovative\\first.txt","r");
   char word[128];
   char meaning[256];
   char ch;
   while((ch = fgetc(fp1)) != EOF ){
      if((ch== '`')){
         fscanf(fp1,"%s",word);
         fscanf(fp1,"%s",meaning);
         insert(word,meaning);
      }
   }
   x=1;
}



void insert(char *word, char *meaning)
{
   struct Dictionary *parent = NULL, *current = NULL, *newnode = NULL;
   int res = 0;
   if (!root)
   {
      root = createNode(word, meaning);
      if(x)
      writeInFile(word,meaning);
      return;
   }
   for (current = root; current != NULL;
        current = (res > 0) ? current->right : current->left)
   {
      res = strcasecmp(word, current->word);
      if (res == 0)
      {
         printf("Duplicate entry!!\n");
         return;
      }
      parent = current;
   }
   newnode = createNode(word, meaning);
   if(x)
   writeInFile(word,meaning);
   
   res > 0 ? (parent->right = newnode) : (parent->left = newnode);
   return;
}



void deleteNode(char *str)
{
   struct Dictionary *parent = NULL, *current = NULL, *temp = NULL;
   int flag = 0, res = 0;
   if (!root)
   {
      printf("No Words present in the Dictionary!!\n");
      return;
   }
   current = root;
   while (1)
   {
      res = strcasecmp(current->word, str);
      if (res == 0)
         break;
      flag = res;
      parent = current;
      current = (res > 0) ? current->left : current->right;
      if (current == NULL)
         return;
   }
   /* deleting leaf node */
   if (current->right == NULL)
   {
      if (current == root && current->left == NULL)
      {
         free(current);
         root = NULL;
         return;
      }
      else if (current == root)
      {
         root = current->left;
         free(current);
         return;
      }

      flag > 0 ? (parent->left = current->left) : (parent->right = current->left);
   }
   else
   {
      /* delete node with single child */
      temp = current->right;
      if (!temp->left)
      {
         temp->left = current->left;
         if (current == root)
         {
            root = temp;
            free(current);
            return;
         }
         flag > 0 ? (parent->left = temp) : (parent->right = temp);
      }
      else
      {
         /* delete node with two children */
         struct Dictionary *successor = NULL;
         while (1)
         {
            successor = temp->left;
            if (!successor->left)
               break;
            temp = successor;
         }
         temp->left = successor->right;
         successor->left = current->left;
         successor->right = current->right;
         if (current == root)
         {
            root = successor;
            free(current);
            return;
         }
         (flag > 0) ? (parent->left = successor) : (parent->right = successor);
      }
   }
   free(current);
   return;
}

void findElement(char *str)
{
   struct Dictionary *temp = NULL;
   int flag = 0, res = 0;
   if (root == NULL)
   {
      printf("No words are there in Dictionary\n");
      return;
   }
   temp = root;
   while (temp)
   {
      if ((res = strcasecmp(temp->word, str)) == 0)
      {
         printf("Word   : %s", str);
         printf("Meaning: %s", temp->meaning);
         flag = 1;
         break;
      }
      temp = (res > 0) ? temp->left : temp->right;
   }
   if (!flag)
      printf("Word doesnot exist in Dictionary\n");
   return;
}

void inorderTraversal(struct Dictionary *myNode)
{
   if (myNode)
   {
      inorderTraversal(myNode->left);
      printf("Word    : %s", myNode->word);
      printf("\n");
      printf("Meaning : %s", myNode->meaning);
      printf("\n");
      inorderTraversal(myNode->right);
   }
   return;
}


void SearchSimilarWord(struct Dictionary* myNode,char word[100]){
   if(myNode)
   {  
      SearchSimilarWord(myNode->left,word);
      char s1[128];
      char s2[128];
      strcpy(s1,myNode->word);
      strcpy(s2,word);
      int j=0,x=0;
      for(int i=0;i<strlen(s1);i++){
         if(s2[j]!='\0' && s1[i]==s2[j]){
            j++;
            if(j==strlen(s2)-1){
                x=1; break;
            }
         }
         else if(j!=0){
            j=0;
         }
      }
      if(x) printf(" %s",myNode->word);
      x=0;
      SearchSimilarWord(myNode->right,word);
   }
}


