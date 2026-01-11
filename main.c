#include<stdio.h>
#include<stdlib.h>
#include<string.h>  //For strlen()
#include<ctype.h>   //For isdigit()
#include<unistd.h>  //For usleep()
#define MAX_LETTER 200
// Define ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
struct book{
     struct book* left; 
     int id; 
     char* title; 
     char* author; 
     int copies;
     struct book* right;
};
struct borrower{
    struct borrower* left; 
      int id;
      char* name;
      struct borrower* right;
};
//------queue-------------------------------------------
// borrower a book
//type of queue elements
typedef struct node_borrow_book{
       int id_book;
       int id_borrower;
       char* date;
       struct node_borrow_book*next;
}node_borrow;
typedef struct queue_borrow_book{
    node_borrow*head;
    node_borrow*tail;
}queue_borrow;
///// returning book
//type of queue elements
typedef struct node_return_book{
       int id_book;
       int id_borrower;
       char* date;
       struct node_return_book*next;
}node_return;
typedef struct queue_return_book{
    node_return*head;
    node_return*tail;
}queue_return;
//*************************************menu****************************************
//books
void book(){
printf("                              .--.           .---.        .-.     \n");
usleep(200000);
printf("                          .---|--|   .-.     | A |  .---. |~|    .--.\n");
usleep(200000);
printf("                       .--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
usleep(200000);
printf("                       |  |NT2|oc|===| |~~|  | C |--|   |_|~|CATS|  |___|-.\n");
usleep(200000);
printf("                       |  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
usleep(200000);
printf("                       |  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
usleep(200000);
printf("                       |~~|===|--|===|~|~~|  |~~~|--|:::|=|~|----|==|---|=|\n");
usleep(200000);
printf("                       ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
usleep(1000000);
system("cls");
}
// the main menu
void  menu1(){
puts(MAGENTA"================*menu*================"RESET);
puts("|  choose an operation               |");
usleep(200000);
puts("|              1->borrower a book    |");
usleep(200000);
puts("|              2->return a book      |");
usleep(200000);
puts("|              3->display books      |");
usleep(200000);
puts("|              4->display borrowers  |");
usleep(200000);
puts("|              5->add book           |");
usleep(200000);
puts("|              6->add borrower       |");
usleep(200000);
puts("|              7->remove book        |");
usleep(200000);
puts("|              8->remove borrower    |");
usleep(200000);
puts("|              9->display loans      |");
usleep(200000);
puts("|              10->exit              |");
usleep(200000);
puts(MAGENTA"======================================"RESET);
usleep(200000);
}
//book borrowing options
void menu_borrower_a_book(){
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
usleep(200000);
puts("  choose an operation ");
usleep(200000);
puts("              1->display books");
usleep(200000);
puts("              2->entering information");
usleep(200000);
puts("              3->exit");
usleep(200000);
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
usleep(200000);
}
//book return options
void menu_choosing_book(){
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
usleep(200000);
puts("choose by :");
usleep(200000);
puts("     1->id");
usleep(200000);
puts("     2->title of book");
usleep(200000);
puts("     3->author of book");
usleep(200000);
puts("     4->exit");
usleep(200000);
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
}
//menu of book selection options
void menu_choosing_borrower(){
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
usleep(200000);
puts("choose by :");
usleep(200000);
puts("     1->id");
usleep(200000);
puts("     2->name of author");
usleep(200000);
puts("     3->exit");
usleep(200000);
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
}
//menu of book return options
void menu_return_a_book(){
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
puts("              1->entering information");
puts("              2->exit");
usleep(200000);
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
}
// menu of loan options
void menu_display_loans(){
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
puts("  display : ");
usleep(200000);
puts("         1->Transactions: Borrowing Books");
usleep(200000);
puts("         2->Transactions: Returning Books");
usleep(200000);
puts("         3->exit");
usleep(200000);
puts(GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET);
}
/*<><><><><><><><><><><><><><>this below functions are about the file<><><><><><><><><><><><><><>*/
// function for reading a line from a file
void read_file(FILE* F,char* line){
   fgets(line,MAX_LETTER,F); //line output
return;
}
// function for calculating the number of file lines
int number_line_file(FILE* p_file){
    int count=0;// Initialize line counter
    char line[MAX_LETTER];
    while(fgets(line,MAX_LETTER,p_file)){// Read the file line by line until the end
      count++;// Increment the counter for each line
    }
    return count;
}
// function for determining the command of the line
void command_line(char* line,char* command){
  int count=0;
  while(line[count]!=' '){
    command[count]=line[count];
    count++;
  }
  command[count]='\0';// Add null terminator to make it a valid string
}
// function to determining the number of command in a file
int number_command_file(char* command,FILE* p_file){
char com[MAX_LETTER],line[MAX_LETTER];
int j,len=strlen(command),count=0,lenth=number_line_file(p_file);
   fseek(p_file, 0, SEEK_SET);// Reset file pointer to the beginning of the file
   while(j<lenth){
        j++;
        read_file(p_file,line);
        for(int i=0;i<len;i++){
        com[i]=line[i];
        }
        com[len]='\0';
       if(strcmp(command,com)==0){// Compare extracted command with the given command
       count++;
       }
    }
    return count;
}
// function to display the data of a file
int display_file(char* file_name){
  FILE* F=fopen(file_name,"r"); // Open the file in read mode
  if(F==NULL){ // Check if file opening was successful
     printf("Failed to open the file %s",file_name);
     return 1;
  }
   int length=number_line_file(F);// Get the number of lines in the file
    fseek(F, 0, SEEK_SET);// Reset file pointer to the beginning of the file
    char line[MAX_LETTER];
    char com[MAX_LETTER];
    for(int i=0;i<length;i++){
    read_file(F,line);// Read a line from the file
    command_line(line,com);// Extract the command from the line
    printf("the command : %s\n",com);
    usleep(20000);
    printf("%s\n",line);
    usleep(20000);
    }
  fclose(F);// Close the file after reading
  return 0;
}
// function to delete a command of a line
void delete_command(char* line,char* command,char* new_line){
 int ind1=strlen(line),ind2=strlen(command);
 for(int i=0;i<(ind1-ind2);i++){
    new_line[i]=line[i+ind2];
 }
 new_line[ind1-ind2]='\0';
}
/*<><><><><><><><><><><><><><>this below functions are about the books<><><><><><><><><><><><><><>*/
//allocate a new cell and return its address in pointer head
void Allocate_book(struct book**head){
   *head=malloc(sizeof(struct book));
}
//assign the values to the cell pointed to by p
void Ass_val_book(struct book*p,int id_book, char*title_book,char*author_book,int copies_book){
   p->id=id_book;// Assign book id
   // Allocate memory for the title
   p->title=malloc(strlen(title_book)+1);
   if(p->title!=NULL){
     strcpy(p->title,title_book);// Assign book title
            }
    // Allocate memory for the author
   p->author=malloc(strlen(author_book)+1);
   if(p->author!=NULL){
    strcpy(p->author,author_book);// Assign book author
   }
   p->copies=copies_book; // Assign book copies
}
//link the cell p to the cell q
void Ass_L_adr_book(struct book* p,struct book* q){
   p->left=q;
}
//link the cell p to the cell q
void Ass_R_adr_book(struct book* p,struct book* q){
   p->right=q;
}
// Function to display the list of books
void display_list_book(struct book* head){
  struct book* ptr=head;
  int count=1;
  while(ptr!=NULL){
    printf(CYAN"--------------------------------------\n"RESET);
    usleep(10000);
    printf(BLUE"the data of the book %d are :\n"RESET,count);
    usleep(10000);
    printf(BLUE"    the id ==> %d \n"RESET,ptr->id);
    usleep(10000);
    printf(BLUE"    the title ==> %s \n"RESET,ptr->title);
    usleep(10000);
    printf(BLUE"    the author ==> %s \n"RESET,ptr->author);
    usleep(10000);
    printf(BLUE"    the number of copies ==> %d \n"RESET,ptr->copies);
    usleep(10000);
    printf(CYAN"--------------------------------------\n"RESET);
    usleep(10000);
    count++;
    ptr=ptr->right;
  }
}
//deallocate and destroy the cell pointed to by p
void Free_node_book(struct book* p){
free(p);
}
// Function to free (deallocate) all nodes in the book list
void free_list_book(struct book** head){
   struct book*temp;
   while(*head !=NULL){
    temp=*head;
    free(temp->title);// Free the allocated memory for the book title
    free(temp->author);// Free the allocated memory for the book author
    *head=(*head)->right;
    Free_node_book(temp);// Free the current node
   }
}
//function for extracting book data from a line in the file
void data_book(char* line,int* id_number,char*name_of_book,char*name_of_author,int* number_cobies){
        char new_line[MAX_LETTER];
        *id_number=0;
        *number_cobies=0;
        delete_command(line,"ADD_BOOK",new_line);// Remove the "ADD_BOOK" command from the input line
        int ind1=0,ind2=0,ind3=0,len=strlen(new_line);
   while(ind1<len){
        // Extract book id
         if(isdigit(new_line[ind1])){
            // Convert characters to integer
            char c=new_line[ind1];
            int n=c-'0';
           *id_number=(*id_number)*10+n;
         }
        // Extract book title and author name
          if(new_line[ind1]=='"'){
              ind1++;
              while(new_line[ind1]!='"'){
                 name_of_book[ind2]=new_line[ind1];
                 ind2++;
                 ind1++;
              }
              name_of_book[ind2]='\0';
              ind1+=3;
              while(new_line[ind1]!='"'){
                  name_of_author[ind3]=new_line[ind1];
                  ind3++;
                  ind1++;
              }
              while(ind1<len){
                if(isdigit(new_line[ind1])){
                  // Convert characters to integer
                  char ca=new_line[ind1];
                  int nu=ca-'0';
                  *number_cobies=(*number_cobies)*10+nu;
                }
                ind1++;
              }
              name_of_author[ind3]='\0';
          }
          if(ind1<len){
          ind1++;}
    }
}
// this function create a doubly linked list and initial it from the file
int create_doubly_linked_list_book(struct book** head,char* file_name){
      struct book*p,*q;
      FILE* F=fopen(file_name,"r");// Open the file in read mode
    if(F==NULL){
       printf("Failed to open the file %s",file_name);
       return 1;
    }
    char command[MAX_LETTER]="ADD_BOOK",line[MAX_LETTER],com[MAX_LETTER],name_of_book[MAX_LETTER],name_of_author[MAX_LETTER];
    int number_command=number_command_file(command,F),count=0,len,id_number,number_cobies;
    fseek(F, 0, SEEK_SET);
    len=number_line_file(F);
    fseek(F, 0, SEEK_SET);
    while(count<len){
       read_file(F,line);
       command_line(line,com);
       if(strcmp(com,"ADD_BOOK")==0){
        goto skip;
       }
       count++;
    }
    skip:
    fseek(F, 0, SEEK_SET);
    for(int i=0;i<count;i++){
        read_file(F,line);
    }
    for(int size=1;size<=number_command;size++){
     Allocate_book(&p);
     if(p==NULL){
        printf("Failed memory allocation\n");
        return 1;
     }
      read_file(F,line);
      data_book(line,&id_number,name_of_book,name_of_author,&number_cobies);
      Ass_val_book(p,id_number,name_of_book,name_of_author,number_cobies);
      if(size==1){
        *head=p;
      }else{
       Ass_L_adr_book(p,q);
       Ass_R_adr_book(q,p);
      }
      q=p;
    }
     fclose(F);
     return 0;
}
//this function create a new node
int new_node_book(struct book** p){
   Allocate_book(p);
   if((*p)==NULL){
     printf("Failed memory allocation\n");
     return 1;
    }
      char name_book[MAX_LETTER],name_author[MAX_LETTER];
      int id,copies;
      printf("enter the title of the book :\t");
      scanf("%s",name_book);
      printf("enter the author of the book :\t");
      scanf("%s",name_author);
      printf("enter the id of the book :\t");
      scanf("%d",&id);
      printf("enter the number of the copies of the book :\t");
      scanf("%d",&copies);
      Ass_val_book(*p,id,name_book,name_author,copies);
      (*p)->left=NULL;
      (*p)->right=NULL;
      return 0;
}
//this function insert the new node in the last of the doubly linked list
void insert_at_last_book(struct book**head){
 struct book* p=NULL,*q=*head;
 new_node_book(&p);
 if((*head)==NULL){
    *head=p;
    return;
 }
 while(q->right!=NULL){
    q=q->right;
 }
Ass_L_adr_book(p,q);
Ass_R_adr_book(q,p);
}
//this function create a new node
int new_node_book2(struct book** p,int id,char*name_book,char*name_author,int copies){
   Allocate_book(p);
   if((*p)==NULL){
     printf("Failed memory allocation\n");
     return 1;
    }
      Ass_val_book(*p,id,name_book,name_author,copies);
      (*p)->left=NULL;
      (*p)->right=NULL;
      return 0;
}
//this function insert the new node in the last of the doubly linked list
void insert_at_last_book2(struct book**head,int id,char*name_book,char*name_author,int copies){  ////////////////////
 struct book* p=NULL,*q=*head;
 new_node_book2(&p,id,name_book,name_author,copies);
 if((*head)==NULL){
    *head=p;
    return;
 }
 while(q->right!=NULL){
    q=q->right;
 }
Ass_L_adr_book(p,q);
Ass_R_adr_book(q,p);
}
//this function search for the node that has the id of book that we chose it and return it
struct book* serch_by_id_book(struct book* head,int id_book){
    struct book* current=head;
    while(current!=NULL){
        if(current->id==id_book){
            return current;
        }
        current=current->right;
    }
    return NULL;//return NULL if does not any node has this id
}
//this function search for the node that has the title of book that we chose it and return it
struct book* serch_by_title_book(struct book* head,char* title_book){
    struct book* current=head;
    while(current!=NULL){
       if(strcmp(current->title,title_book)==0){
        return current;
       }
       current=current->right;
    }
    return NULL;//return NULL if does not any node has this title
}
//this function search for the node that has the author of book that we chose it and return it
struct book* serch_by_author_book(struct book* head,char* author_book){
    struct book* current=head;
    while(current!=NULL){
       if(strcmp(current->author,author_book)==0){
        return current;
       }
        current=current->right;
    }
    return NULL;//return NULL if does not any node has this author
}
//this function decrease the number of the copies of the book that we chose its id
void decrease_number_copeies_book_by_id(struct book* head,int id_book){
    struct book* current=head;
    while(current!=NULL){
        if(current->id==id_book){
            current->copies--;
            break;
        }
        current=current->right;
    }
}
//this function decrease the number of the copies of the book that we chose its title
void decrease_number_copeies_book_by_title(struct book* head,char* title_book){
    struct book* current=head;
    while(current!=NULL){
        if(strcmp(title_book,current->title)==0){
            current->copies--;
            break;
        }
        current=current->right;
    }
}
//this function decrease the number of the copies of the book that we chose its author
void decrease_number_copeies_book_by_author(struct book* head,char* author_book){
    struct book* current=head;
    while(current!=NULL){
        if(strcmp(author_book,current->author)==0){
            current->copies--;
            break;
        }
        current=current->right;
    }
}
//this function increase the number of the copies of the book that we chose its id
void increase_number_copeies_book_by_id(struct book* head,int id_book){
    struct book* current=head;
    while(current!=NULL){
        if(current->id==id_book){
            current->copies++;
            break;
        }
        current=current->right;
    }
}
//delete a node from a doubly linked list
void delete_node_book(struct book** head,struct book* book){
    struct book* p=NULL,*q=NULL;
      if(*head==NULL){
        printf("the list is empty\n");
        return;
      }
      if(book==NULL){
        printf("this node does not exist\n");
        return;
      }
      if(*head==book){
         *head=book->right;
         if(*head!=NULL){
            (*head)->left=NULL;
         }
         free(book->title);
         free(book->author);
         free(book);
         return;
      }
      if(book->right==NULL){
        p=book->left;
        p->right=NULL;
       free(book->title);
       free(book->author);
        free(book);
        return;
      }
    p=book->left;
    q=book->right;
    p->right=q;
    q->left=p;
    free(book->title);
    free(book->author);
    free(book);
}
/*<><><><><><><><><><><><><><>this below functions are about the borrower<><><><><><><><><><><><><><>*/
//allocate a new cell and return its address in pointer head
void Allocate_borrower(struct borrower**head){
   *head=malloc(sizeof(struct borrower));
}
//assign the values to the cell pointed to by p
void Ass_val_borrower(struct borrower*p,int id_borrower, char*name_borrower){
   p->id=id_borrower;// Assign borrower id
   // Allocate memory for the name
   p->name=malloc(strlen(name_borrower)+1);
   if(p->name!=NULL){
    strcpy(p->name,name_borrower);// Assign borrower name
   }
}
//link the cell p to the cell q
void Ass_L_adr_borrower(struct borrower*p,struct borrower*q){
    p->left=q;
}
//link the cell p to the cell q
void Ass_R_adr_borrower(struct borrower*p,struct borrower*q){
    p->right=q;
}
// Function to display the list of books
void display_list_borrower(struct borrower* head){
  struct borrower* ptr=head;
  int count=1;
  while(ptr!=NULL){
    printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
    printf("the data of the borrower %d are : \n",count);
    printf("    the id of the borrower ==> %d \n",ptr->id);
    printf("    the name of the borrower ==> %s \n",ptr->name);
    count++;
    ptr=ptr->right;
  }
    printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
}
//deallocate and destroy the cell pointed to by p
void Free_node_borrower(struct borrower* p){
free(p);
}
// Function to free (deallocate) all nodes in the book list
void free_list_borrower(struct borrower**head){
   struct borrower*temp;
   while(*head !=NULL){
    temp=*head;
    free(temp->name);// Free the allocated memory for the borrower name
    *head=(*head)->right;
    Free_node_borrower(temp);// Free the current node
   }
}
//function for extracting borrower data from a line in the file
void data_borrower(char* line,int*id,char* name){
    char new_line[MAX_LETTER],command[MAX_LETTER]="ADD_BORROWER";
    *id=0;
    delete_command(line,command,new_line);
    int length=strlen(new_line),count=1,ind=0;

        for(int i=0;i<3;i++){
            char c=new_line[count];
            int n=c-'0';
            *id=(*id)*10+n;
            count++;
        }
        while(count<length){
        if(new_line[count]!=' '){
            name[ind]=new_line[count];
            ind++;
        }
        count++;
        }
        name[ind]='\0';
}
// this function create a doubly linked list and initial it from the file
int create_doubly_linked_list_borrower(struct borrower**head,char* file_name){
   struct borrower*p,*q;
   FILE* F=fopen(file_name,"r");
    if(F==NULL){
       printf("Failed to open the file %s",file_name);
       return 1;
    }
   char command[MAX_LETTER]="ADD_BORROWER",line[MAX_LETTER],com[MAX_LETTER],name_borrower[MAX_LETTER];
   int  length=number_command_file(command,F),count=0,len,id_borrower;
   fseek(F, 0, SEEK_SET);
   len=number_line_file(F);
   fseek(F, 0, SEEK_SET);
   while(count<len){
       read_file(F,line);
       command_line(line,com);
       if(strcmp(com,"ADD_BORROWER")==0){
        break;
       }
       count++;
   }
    fseek(F, 0, SEEK_SET);
    for(int i=0;i<count;i++){
        read_file(F,line);
    }
    for(int size=1;size<=length;size++){
      Allocate_borrower(&p);
      if(p==NULL){
        printf("Failed memory allocation\n");
        return 1;
      }
      read_file(F,line);
      data_borrower(line,&id_borrower,name_borrower);
      Ass_val_borrower(p,id_borrower,name_borrower);
      if(size==1){
        *head=p;
      }else{
        Ass_L_adr_borrower(p,q);
        Ass_R_adr_borrower(q,p);
      }
      q=p;
   }
   fclose(F);
   return 0;
}
//this function create a new node
void new_node_borrower(struct borrower**p){
   Allocate_borrower(p);
   if((*p)==NULL){
        printf("Failed memory allocation\n");
    return;
   }
   char name[MAX_LETTER];
   int id;
   printf("enter the name of the borrower :\t");
   scanf("%s",name);
   printf("enter the id of the borrower :\t");
   scanf("%d",&id);
   Ass_val_borrower(*p,id,name);
   (*p)->left=NULL;
   (*p)->right=NULL;
}
//this function insert the new node in the last of the doubly linked list
void insert_at_last_borrower(struct borrower**head){
    struct borrower* p,*q=*head;
    new_node_borrower(&p);
    if((*head)==NULL){
        *head=p;
        return;
    }
    while(q->right!=NULL){
        q=q->right;
    }
    Ass_L_adr_borrower(p,q);
    Ass_R_adr_borrower(q,p);
}
//this function create a new node
void newNodeBorrower2(struct borrower**p,char*name,int id){
   Allocate_borrower(p);
   if((*p)==NULL){
        printf("Failed memory allocation\n");
    return;
   }
   Ass_val_borrower(*p,id,name);
   (*p)->left=NULL;
   (*p)->right=NULL;
}
//this function insert the new node in the last of the doubly linked list
void insertAtLastBorrower2(struct borrower**head,char*name,int id){
    struct borrower* p,*q=*head;
    newNodeBorrower2(&p,name,id);
    if((*head)==NULL){
        *head=p;
        return;
    }
    while(q->right!=NULL){
        q=q->right;
    }
    Ass_L_adr_borrower(p,q);
    Ass_R_adr_borrower(q,p);
}
//this function search for the node that has the id of borrower that we chose it and return it
struct borrower* serch_by_id_borrower(struct borrower* head,int id_borrower){
   struct borrower*current=head;
   while(current!=NULL){
      if(current->id==id_borrower){
        return current;
      }
      current=current->right;
   }
   return NULL;
}
//this function search for the node that has the name of borrower that we chose it and return it
struct borrower* search_by_name_borrower(struct borrower* head,char* name_borrower){
      struct borrower*current=head;
      while(current!=NULL){
        if(strcmp(current->name,name_borrower)==0){
            return current;
        }
        current=current->right;
      }
      return NULL;
}
//delete a node from a doubly linked list
void delete_node_borrower(struct borrower** head,struct borrower* borrower){
    struct borrower* p=NULL,*q=NULL;
      if(*head==NULL){
        printf("the list is empty\n");
        return;
      }
      if(borrower==NULL){
        printf("this node does not exist\n");
        return;
      }
      if(*head==borrower){
         *head=borrower->right;
         if(*head!=NULL){
            (*head)->left=NULL;
         }
         free(borrower->name);
         free(borrower);
         return;
      }
      if(borrower->right==NULL){
        p=borrower->left;
        p->right=NULL;
        free(borrower->name);
        free(borrower);
        return;
      }
    p=borrower->left;
    q=borrower->right;
    p->right=q;
    q->left=p;
    free(borrower->name);
    free(borrower);
}
//*****************************************************************************
//function to comparison of two dates writing on the figure yyyy-mm-dd
int compare_two_dates(char*date1,char*date2){
    int year1=0,year2=0,month1=0,month2=0,day1=0,day2=0;
 for(int i=0;i<4;i++){
    char c1=date1[i],c2=date2[i];
    int n1=c1-'0',n2=c2-'0';
    year1=year1*10+n1;
    year2=year2*10+n2;
 }
 if(year1<year2){
    return -1;
 }
 if(year1>year2){
    return 1;
 }
 if(year1==year2){
    for(int i=5;i<7;i++){
    char c1=date1[i],c2=date2[i];
    int n1=c1-'0',n2=c2-'0';
    month1=month1*10+n1;
    month2=month2*10+n2;
 }
 if(month1<month2){
    return -1;//return -1 if date1 before date2
 }
 if(month1>month2){
    return 1;//return 1 if date1 after date2
 }
 if(month1==month2){
    for(int i=8;i<10;i++){
    char c1=date1[i],c2=date2[i];
    int n1=c1-'0',n2=c2-'0';
    day1=day1*10+n1;
    day2=day2*10+n2;
    }
    if(day1<day2){
    return -1;//return -1 if date1 before date2
    }
    if(day1>day2){
    return 1;//return 1 if date1 after date2
    }
 }
 }
 return 0; //return 0 if date1=date2
}
//this function read the date and write it in the form yyyy-mm-dd
void convert_date_string(char* date){
 int count=0;
 char year[MAX_LETTER],month[MAX_LETTER],day[MAX_LETTER];
 printf("enter the return date of book\n");
 printf("    enter the year\n");
 scanf("%s",year);
 printf("    enter the month\n");
 scanf("%s",month);
 printf("    enter the day\n");
  scanf("%s",day);
 for(int i=0;i<strlen(year);i++){
    date[count]=year[i];
    count++;
 }
 date[count]='-';
 for(int i=0;i<strlen(month);i++){
    count++;
    date[count]=month[i];
 }
  count++;
  date[count]='-';
   for(int i=0;i<strlen(day);i++){
    count++;
    date[count]=day[i];
 }
 date[count+1]='\0';
}
//this function check if the queue is empty or not
int EmptyQueueBorrowing(queue_borrow*q){
return q->head==NULL;//return 1 if the queue is empty and 0 if the queue is not empty
}
//this function check if the queue is full or not
int FullQueueBorrowing(queue_borrow*q){
return 0;
}
//this function create a queue
void create_queue_borrowing_book(queue_borrow**q){
    *q=malloc(sizeof(queue_borrow));
    if(*q==NULL){
        printf("Failed memory allocation\n");
        return;
    }
    (*q)->head=NULL;
    (*q)->tail=NULL;
}
//this function create a node
void create_node_borrowing_book(node_borrow**p,int idBook,int idBorrower,char* Date){
      *p=malloc(sizeof(node_borrow));
           if(*p==NULL){
        printf("Failed memory allocation\n");
        return;
    }
   (*p)->id_book=idBook;
   (*p)->id_borrower=idBorrower;
   (*p)->date=malloc(strlen(Date)+1);
   strcpy((*p)->date,Date);
   (*p)->next=NULL;
}
//this function add a loan (borrowing book) in the last of the queue
int EnqueueBorrowingBook(queue_borrow*q,int idBook,int idBorrower,char* Date){
    node_borrow*p=NULL;
    if ( FullQueueBorrowing(q) ) return 0;
    create_node_borrowing_book(&p,idBook,idBorrower,Date);
    if(q->tail==NULL){
        q->head=p;
        q->tail=p;
        return 0;
    }
    q->tail->next=p;
    q->tail=p;
    return 0;
}
//this function remove a loan (borrowing book) in the begin of the queue and return its values
void DequeueBorrowingBook(queue_borrow*q,int*idBook,int*idBorrower){
   if(EmptyQueueBorrowing(q)){
        printf("this function is empty");
        return ;
   }
   node_borrow*temp=q->head;
   q->head=q->head->next;
   *idBook=temp->id_book;
   *idBorrower=temp->id_borrower;
   free(temp);
   if(q->head==NULL){
     q->tail=NULL;
   }
}
//function for extracting book borrowing data from from a line in the file
void data_borrow_book(char*line,int*id_book,int*id_borrower,char*date){
    char new_line[MAX_LETTER],command[MAX_LETTER]="BORROW_BOOK";
    int count=1,len=0,ind=0;
    delete_command(line,command,new_line);
    len=strlen(new_line);
    *id_book=0;
    *id_borrower=0;
    while(new_line[count]!=' '){
            char c=new_line[count];
            int n=c-'0';
           (*id_book)=(*id_book)*10+n;
           count++;
    }
    count++;
    while(new_line[count]!=' '){
            int n=new_line[count]-'0';
           (*id_borrower)=(*id_borrower)*10+n;
           count++;
    }
    count++;
    for(int i=count;i<=len;i++){
      date[ind]=new_line[i];
      ind++;
    }
}
//this function filling a queue from a file
int filling_queue_borrowring_by_data_file(queue_borrow*q,char*file_name){
       FILE* F=fopen(file_name,"r");
       if(F==NULL){
       printf("Failed to open the file %s",file_name);
       return 1;
       }
       int count=0,length=number_command_file("BORROW_BOOK",F),IdBook,IdBorrower,len=0;
       char line[MAX_LETTER],com[MAX_LETTER],Date[MAX_LETTER];
       fseek(F,0,SEEK_SET);
       len=number_line_file(F);
       fseek(F, 0, SEEK_SET);
       while(count<len){
          read_file(F,line);
          command_line(line,com);
          if(strcmp(com,"BORROW_BOOK")==0){
            break;
          }
           count++;
       }
       fseek(F, 0, SEEK_SET);
       for(int i=0;i<count;i++){
        read_file(F,line);
       }
       for(int i=0;i<length;i++){
        read_file(F,line);
        data_borrow_book(line,&IdBook,&IdBorrower,Date);
        EnqueueBorrowingBook(q,IdBook,IdBorrower,Date);
       }
       fclose(F);
       return 0;
}
//this function display the loan (borrowing books)
void display_queue_borrow_book(queue_borrow*q){
   node_borrow*temp=q->head;
   int count=1;
   while(temp!=NULL){
    printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
    printf("the data of the lean %d are :\n",count);
    printf("            the id of the book is : %d\n",temp->id_book);
    printf("            the id of the borrower is : %d\n",temp->id_borrower);
    printf("            the date of the return is : %s\n",temp->date);
    count++;
    temp=temp->next;
   }
   printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
}
// Function to free (deallocate) all nodes of the list of the queue
void freelist_queue_borrow(queue_borrow**q){
  node_borrow*ptr1=(*q)->head,*ptr2;
  while(ptr1!=NULL){
    ptr2=ptr1;
    ptr1=ptr1->next;
    free(ptr2->date);
    free(ptr2);
  }
  free(*q);
}
//----------------------------------------------------------------------------------
//function for extracting book returning data from from a line in the file
void data_returning_book(char*line,int*id_book,int*id_borrower,char*date){
    char new_line[MAX_LETTER],command[MAX_LETTER]="RETURN_BOOK";
    int count=1,len=0,ind=0;
    delete_command(line,command,new_line);
    len=strlen(new_line);
    *id_book=0;
    *id_borrower=0;
    while(new_line[count]!=' '){
            int n=new_line[count]-'0';
           (*id_book)=(*id_book)*10+n;
           count++;
    }
    count++;
    while(new_line[count]!=' '){
            int n=new_line[count]-'0';
           (*id_borrower)=(*id_borrower)*10+n;
           count++;
    }
    count++;
    for(int i=count;i<len;i++){
      date[ind]=new_line[i];
      ind++;
    }
}
//this function check if the queue is empty or not
int EmptyQueueReturning(queue_return*q){
return q->head==NULL;//return 1 if the queue is empty and 0 if the queue is not empty
}
//this function check if the queue is full or not
int FullQueueReturning(queue_return*q){
return 0;
}
//this function create a queue
void create_queue_returning_book(queue_return**q){
    *q=malloc(sizeof(queue_return));
    if(*q==NULL){
        printf("Failed memory allocation\n");
        return;
    }
    (*q)->head=NULL;
    (*q)->tail=NULL;
}
//this function create a node
void create_node_returning_book(node_return**p,int idBook,int idBorrower,char* Date){
      *p=malloc(sizeof(node_return));
           if(*p==NULL){
        printf("Failed memory allocation\n");
        return;
    }
   (*p)->id_book=idBook;
   (*p)->id_borrower=idBorrower;
   (*p)->date=malloc(strlen(Date)+1);
   strcpy((*p)->date,Date);
   (*p)->next=NULL;
}
//this function add a loan (returning book) in the last of the queue
int EnqueueReturningBook(queue_return*q,int idBook,int idBorrower,char* Date){
    node_return*p=NULL;
    if ( FullQueueReturning(q) ) return 0;
    create_node_returning_book(&p,idBook,idBorrower,Date);
    if(q->tail==NULL){
        q->head=p;
        q->tail=p;
        return 0;
    }
    q->tail->next=p;
    q->tail=p;
    return 0;
}
//this function display the loan (borrowing books)
void display_return_borrow_book(queue_return*q){
   node_return*temp=q->head;
   int count=1;
   while(temp!=NULL){
    printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
    printf("the data of the lean %d are :\n",count);
    printf("                the id of the book is : %d\n",temp->id_book);
    printf("                the id of the borrower is : %d\n",temp->id_borrower);
    printf("                the date of the return is : %s\n",temp->date);
    count++;
    temp=temp->next;
   }
   printf(CYAN"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"RESET);
}
//this function filling a queue from a file
int filling_queue_returning_by_data_file(queue_return*q,char*file_name){
       FILE* F=fopen(file_name,"r");
       if(F==NULL){
       printf("Failed to open the file %s",file_name);
       return 1;
       }
       int count=0,length=number_command_file("RETURN_BOOK",F),IdBook,IdBorrower,len=0;
       char line[MAX_LETTER],com[MAX_LETTER],Date[MAX_LETTER];
       fseek(F,0,SEEK_SET);
       len=number_line_file(F);
       fseek(F, 0, SEEK_SET);
       while(count<len){
          read_file(F,line);
          command_line(line,com);
          if(strcmp(com,"RETURN_BOOK")==0){
            break;
          }
           count++;
       }
       fseek(F, 0, SEEK_SET);
       for(int i=0;i<count;i++){
        read_file(F,line);
       }
       for(int i=0;i<length;i++){
        read_file(F,line);
        data_returning_book(line,&IdBook,&IdBorrower,Date);
        EnqueueReturningBook(q,IdBook,IdBorrower,Date);
       }
       fclose(F);
       return 0;
}
// Function to free (deallocate) all nodes of the list of the queue
void freelist_queue_return(queue_return**q){
  node_return*ptr1=(*q)->head,*ptr2;
  while(ptr1!=NULL){
    ptr2=ptr1;
    ptr1=ptr1->next;
    free(ptr2->date);
    free(ptr2);
  }
  free(*q);
}
//this function add a loan(returning book) to the queue using the priority of the date of return the book
void add_elament_to_queue_using_priority_date(queue_return*q,int idBook,int idBorrower,char*Date){
    node_return*node=NULL,*current,*temp;
    create_node_returning_book(&node,idBook,idBorrower,Date);
    temp=q->head;
    if(node==NULL){
        printf("Failed memory allocation\n");
        return;
    }
    if(q->head==NULL){
        q->head=node;
        return;
    }
    if(compare_two_dates(Date,q->head->date)==-1){
      current=q->head;
      q->head=node;
      node->next=current;
      return;
    }
    while(temp->next!=NULL && compare_two_dates(Date,temp->next->date)!=-1 ){
      temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
}
//this function remove a loan (returning book) in the begin of the queue and return its values
void DequeueReturningBook(queue_return*q,int*idBook,int*idBorrower){
   if(EmptyQueueReturning(q)){
        printf("this function is empty");
        return ;
   }
   node_return*temp=q->head;
   q->head=q->head->next;
   *idBook=temp->id_book;
   *idBorrower=temp->id_borrower;
   free(temp);
   if(q->head==NULL){
     q->tail=NULL;
   }
}
// principle program
int main(){
    //definition of variables
    struct book* head1=NULL,*ptr1,*p1;
    struct borrower* head2=NULL,*ptr2,*p2;
    queue_borrow*q_borrow=NULL;
    queue_return*q_return=NULL;
    int choice1=0,choice2=0,choice3=0,choice4=0,choice5=0,choice6=0,choice7=0,id_book,id_borrower,IdBorrower,IdBook;
    char name_author[MAX_LETTER],AuthorName[MAX_LETTER],title_book[MAX_LETTER],TitleBook[MAX_LETTER],name_borrower[MAX_LETTER],NameBorrower[MAX_LETTER],date_borrow[MAX_LETTER],nameborrower[MAX_LETTER],title[MAX_LETTER],author[MAX_LETTER],date_return[MAX_LETTER];
    //////
    book();
    //////
    create_doubly_linked_list_book(&head1,"library_data.txt");
    create_doubly_linked_list_borrower(&head2,"library_data.txt");
    create_queue_borrowing_book(&q_borrow);
    filling_queue_borrowring_by_data_file(q_borrow,"library_data.txt");
    create_queue_returning_book(&q_return);
    filling_queue_returning_by_data_file(q_return,"library_data.txt");
    /////
    first:
    menu1();
    printf("Please enter your choice\n");
    scanf("%d",&choice1);
    switch(choice1){
      case 1:
          second:
          menu_borrower_a_book();
          printf("Please enter your choice\n");
          scanf("%d",&choice2);
          switch(choice2){
              case 1:
                  display_list_book(head1);
                  goto second;
              case 2:
                  printf("enter the data of the borrower\n");
                  printf("      enter the name of the borrower : ");
                  scanf("%s",NameBorrower);
                  printf("      enter the id of the borrower : ");
                  scanf("%d",&IdBorrower);
                  p2=serch_by_id_borrower(head2,IdBorrower);
                  third:
                  printf("select a book\n");
                  menu_choosing_book();
                  scanf("%d",&choice4);
                  switch(choice4){
                   case 1:
                       printf("enter the id of the book that you need to select it \n");
                       scanf("%d",&IdBook);
                       p1=serch_by_id_book(head1,IdBook);
                       if(p1==NULL){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       if(p1->copies==0){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       decrease_number_copeies_book_by_id(head1,IdBook);
                       convert_date_string(date_borrow);
                       EnqueueBorrowingBook(q_borrow,IdBook,IdBorrower,date_borrow);
                       if(p2==NULL){
                          insertAtLastBorrower2(&head2,NameBorrower,IdBorrower);
                       }
                       goto second;
                   case 2:
                       printf("enter the title of the book that you need to select it \n");
                       scanf("%s",TitleBook);
                       p1=serch_by_title_book(head1,TitleBook);
                       if(p1==NULL){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       if(p1->copies==0){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       decrease_number_copeies_book_by_title(head1,TitleBook);
                       convert_date_string(date_borrow);
                       EnqueueBorrowingBook(q_borrow,p1->id,IdBorrower,date_borrow);
                       if(p2==NULL){
                           insertAtLastBorrower2(&head2,NameBorrower,IdBorrower);
                       }
                       goto second;
                   case 3:
                       printf("enter the name of author of the book that you need to select it \n");
                       scanf("%s",AuthorName);
                       p1=serch_by_author_book(head1,AuthorName);
                       if(p1==NULL){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       if(p1->copies==0){
                        printf(RED"this book does not exist\n"RESET);
                        goto second;
                       }
                       decrease_number_copeies_book_by_author(head1,AuthorName);
                       convert_date_string(date_borrow);
                       EnqueueBorrowingBook(q_borrow,p1->id,IdBorrower,date_borrow);
                       if(p2==NULL){
                           insertAtLastBorrower2(&head2,NameBorrower,IdBorrower);
                        }
                       goto second;
                   case 4:
                       printf(YELLOW"exit\n"RESET);
                       goto second;
                   default:
                       goto third;
                  }
                  goto second;
              case 3:
                  printf(YELLOW"Exit\n"RESET);
                  goto first;
              default:
                  printf(RED"this option does not exist\n"RESET);
                  goto second;
          }
          goto first;
      case 2:
          seventh:
          menu_return_a_book();
          printf("Please enter your choice\n");
          scanf("%d",&choice3);
          switch(choice3){
             case 1:
                 printf("enter the id of the borrower\n");
                 scanf("%d",&id_borrower);
                 p2=serch_by_id_borrower(head2,id_borrower);
                 if(p2==NULL){
                    printf("this borrower does not exist in the list please enter his name : ");
                    scanf("%s",nameborrower);
                    insertAtLastBorrower2(&head2,nameborrower,id_borrower);
                 }
                 printf("enter the id of the book\n");
                 scanf("%d",&id_book);
                 p1=serch_by_id_book(head1,id_book);
                 if(p1==NULL){
                     printf(RED"this borrower does not exist in the list \n"RESET);
                     printf("     please enter its title : ");
                     scanf("%s",title);
                     printf("     please enter its author : ");
                     scanf("%s",author);
                     insert_at_last_book2(&head1,id_book,title,author,1);
                 }else{
                    increase_number_copeies_book_by_id(head1,id_book);
                 }
                 convert_date_string(date_return);
                 add_elament_to_queue_using_priority_date(q_return,id_book,id_borrower,date_return);
                 goto seventh;
             case 2:
                 printf(YELLOW"Exit\n"RESET);
                 goto first;
             default:
                 printf(RED"this option does not exist\n"RESET);
                 goto seventh;
          }
          goto first;
      case 3:
          if(head1==NULL){
              printf(RED"does not exist books\n"RESET);
          }else{
          display_list_book(head1);
               }
          goto first;
      case 4:
          if(head2==NULL){
              printf(RED"does not exist borrowers\n"RESET);
           }else{
               display_list_borrower(head2);
               }
           goto first;
      case 5:
           insert_at_last_book(&head1);
           goto first;
      case 6:
           insert_at_last_borrower(&head2);
           goto first;
      case 7:
           fourth:
           printf("select the book that you need to delete it\n");
           menu_choosing_book();
           scanf("%d",&choice5);
           switch(choice5){
              case 1:
                  printf("enter the id of the book that you need to delete it :  ");
                  scanf("%d",&id_book);
                  ptr1=serch_by_id_book(head1,id_book);
                  if(ptr1==NULL){
                    printf(RED"this book does not exist"RESET);
                    goto fourth;
                  }
                  delete_node_book(&head1,ptr1);
                  goto fourth;
              case 2:
                  printf("enter the title of the book that you need to delete it :  ");
                  scanf("%s",title_book);
                  ptr1=serch_by_title_book(head1,title_book);
                  if(ptr1==NULL){
                    printf(RED"this book does not exist\n"RESET);
                    goto fourth;
                  }
                  delete_node_book(&head1,ptr1);
                  goto fourth;
              case 3:
                  printf("enter the author of the book that you need to delete it :  ");
                  scanf("%s",name_author);
                  ptr1=serch_by_author_book(head1,name_author);
                  if(ptr1==NULL){
                    printf(RED"this book does not exist\n"RESET);
                    goto fourth;
                  }
                  delete_node_book(&head1,ptr1);
                  goto fourth;
              case 4:
                  printf(YELLOW"exit\n"RESET);
                  goto first;
              default:
                  printf(RED"this option does not exist\n"RESET);
                  goto fourth;
           }
           goto first;
      case 8:
           fifth:
           printf("select the borrower that you need to delete it\n");
           menu_choosing_borrower();
           scanf("%d",&choice6);
           switch(choice6){
              case 1:
                  printf("enter the id of borrower that you need to delete it :  ");
                  scanf("%d",&id_borrower);
                  ptr2=serch_by_id_borrower(head2,id_borrower);
                  if(ptr2==NULL){
                    printf(RED"this borrower does not exist\n"RESET);
                    goto fifth;
                  }
                  delete_node_borrower(&head2,ptr2);
                  goto fifth;
              case 2:
                  printf("enter the name of the borrower that you need to delete it :  ");
                  scanf("%s",name_borrower);
                  ptr2=search_by_name_borrower(head2,name_borrower);
                  if(ptr2==NULL){
                    printf(RED"this borrower does not exist\n"RESET);
                    usleep(200000);
                    goto fifth;
                  }
                  delete_node_borrower(&head2,ptr2);
                  goto fifth;
              case 3:
                  printf(YELLOW"exit\n"RESET);
                  goto first;
              default:
                  printf(RED"this option does not exist\n"RESET);
                  usleep(200000);
                  goto fifth;
           }
           goto first;
      case 9:
           sixth:
           menu_display_loans();
           printf("Please enter your choice\n");
           scanf("%d",&choice7);
           switch(choice7){
               case 1:
                   display_queue_borrow_book(q_borrow);
                   goto sixth;
               case 2:
                   display_return_borrow_book(q_return);
                   goto sixth;
               case 3:
                   printf(YELLOW"exit\n"RESET);
                   goto first;
               default:
                   printf(RED"this option does not exist\n"RESET);
                   usleep(200000);
                   goto sixth;
            }
      case 10:
           printf(YELLOW"exit\n"RESET);
           break;
      default:
           printf(RED"this option does not exist\n"RESET);
           usleep(200000);
           goto first;
    }
     //freeing memory
     free_list_borrower(&head2);
     free_list_book(&head1);
     freelist_queue_borrow(&q_borrow);
     freelist_queue_return(&q_return);
return 0;
}


