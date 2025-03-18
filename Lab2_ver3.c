#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct record {// this is the structure of the record database
    int part;
    char name[20];
    float size;
    char size_metric[20];
    float cost;
       
};

struct record *Pointer1; // main pointer for database
void menu();
void printAllRecords();
void addRecord(); 
void deleteRecord();
void printNumRecords();
void printDatabaseSize();
void printNumChanges(bool print);
char databaseName[50]; // you need this to store the name for the database
int numRecs; // number of records in the database


void dummyRecords() { // manually added the database records, got rid of the array that was here
    struct record dummy1 = {394892948, "Poly pipe", 23.75, "mm", 8.83};
    struct record dummy2 = {123456789, "Aluminum tube", 45.0, "mm", 15.20};
    struct record dummy3 = {987654321, "Steel rod", 12.5, "cm", 10.50};
    struct record dummy4 = {112233445, "Copper wire", 5.25, "mm", 2.75};
    struct record dummy5 = {556677889, "PVC pipe", 30.0, "mm", 9.99};

    Pointer1 = malloc(sizeof(struct record) * 5);
    Pointer1[0] = dummy1;
    Pointer1[1] = dummy2;
    Pointer1[2] = dummy3;
    Pointer1[3] = dummy4;
    Pointer1[4] = dummy5;

    numRecs = 5;
};






void menu(){
    while(1){ 
        printf("\nMenu for your Database\n");
        printf("1. Print all records\n");
        printf("2. Add record\n");
        printf("3. Delete the record\n");
        printf("4. Print number of records\n");
        printf("5. Print database size\n");
        printf("6. Print number of changes\n");
        printf("7. Exit\n");
        printf("Please enter your selection >\n ");


        int selection;
        scanf("%d", &selection);
        getchar();
        printf("\n"); //create space before every output

        switch (selection){
            case 1:
                printAllRecords();
                break;
            case 2:
                printf("\nInsert the data for each element of for the part:\n");
                addRecord();
                printNumChanges(false);
                break;
            case 3:
                deleteRecord();
                printNumChanges(false);
                break;
            case 4:
                printNumRecords();
                break;
            case 5:
                printDatabaseSize();
                break;
                case 6:
            printf("Here are the number of changes that occured\n");
                printNumChanges(1);
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid selection. Please choose a number between 1 and 7.\n");
                break;
 

        }
            



    }

    
    

}
void printAllRecords(){
    printf("Printing all records\n");
    for(int i = 0; i < numRecs; i++){
        printf("Record %d\n", i + 1);
        printf("Part number: %d\n", Pointer1[i].part);
        printf("Part name: %s\n", Pointer1[i].name);
        printf("Part size: %.2f\n", Pointer1[i].size);
        printf("Part size metric: %s\n", Pointer1[i].size_metric);
        printf("Part cost: %.2f\n", Pointer1[i].cost); 
        printf("\n");
    }

}

void addRecord(){  //https://stackoverflow.com/questions/64533626/using-fgets-right-after-getchar
        struct record newRecord;


        printf("Enter the part number: ");
        if (scanf("%d", &newRecord.part)==1){
            getchar();
         }else{
            printf("Invalid input for part number.\n");// this is to check if the input is valid if not it will print out the error message
            getchar();
         }
          
        printf("Enter the part name: ");
         fgets(newRecord.name, sizeof(newRecord.name), stdin);// this help to get rid of the the error i was having which was when i run the code it would skip over the code or merge the  together question.
                                          // but with fgets it was able to allevate the error and allow you to read the entire line, including spaces, until it hit \n. This got rid of my error.
         newRecord.name[strcspn(newRecord.name, "\n")] = 0;
         

        printf("Enter the part size: ");
         if(scanf("%f", &newRecord.size)==1){
            getchar();
        }else{
            printf("Invalid input for part size.\n");
            getchar();
         }
         
        
        printf("Enter the part size metric(e.g. lbs ): ");
         fgets(newRecord.size_metric, sizeof(newRecord.size_metric), stdin);
         newRecord.size_metric[strcspn(newRecord.size_metric, "\n")] = 0;
         

        printf("Enter the part cost: ");
         if(scanf("%f", &newRecord.cost) ==1){
            getchar();
         } else{
            printf("Invalid input for part cost.\n");
            getchar();
         }

        printf("\nYou are viewing the New Record:\n");
        printf("Part number= %d\n", newRecord.part);
        printf("Part name= %s\n", newRecord.name);
        printf("Part size= %.2f\n", newRecord.size);
        printf("Part size metric= %s\n", newRecord.size_metric);
        printf("Part cost= %.2f\n", newRecord.cost);

      // if the database is empty  the it will create space for just 1 new record
    if(numRecs == 0){
        numRecs = 1;
        Pointer1= malloc(sizeof(struct record));
        Pointer1[0] = newRecord;
    }else{
      
       // if the database is not empty then it will create space for the new record and copy the old records into the new space
        numRecs++;
        Pointer1 = malloc(numRecs * sizeof(struct record));
        
        for(int i = 0; i < (numRecs-1); i++){ // copy the old records into the new space
            Pointer1[i] = Pointer1[i];
            
        }
        Pointer1[numRecs - 1] = newRecord; 
        free(Pointer1);
       
        
    }

       
}
// only delete the last record in the database
void deleteRecord(){
    if(numRecs > 0){
        if(numRecs == 1){// if there is only one recors this will free the pointer and set it 0
            free(Pointer1);
            Pointer1 = NULL;
            numRecs = 0;
       
        }else{   // makes space for one less record and copy the old records into the new space
            // Pointer1 = malloc((numRecs - 1) * sizeof(struct record));
             for(int i = 0; i < numRecs - 1; i++){
                 Pointer1[i] = Pointer1[i +1];
             }
            
             numRecs--;
        }
       
        
    }
    printf("Last record deleted successfully!\n");
   
    


}
    



void printNumRecords(){
    printf("here is the number of records in this database: %d\n", numRecs);
}



void printNumChanges(bool print){
   static int count =0;
   if(print == 1){
        printf("You have modified the database %d times\n", count);
    }else{
        count ++;
        printf("%d modification have been made so far\n", count);
   }


}// calculte the size of the database
void printDatabaseSize(){
    int size_database= numRecs * sizeof(struct record);
    printf("The size of the database is: %d bytes\n", size_database);

}
// this hold the number of dummy records at the start of the program before the program starts
int initialCount = 5; 

int main(int argc, char *argv[]){   //https://stackoverflow.com/questions/16027785/whats-wrong-with-my-code-what-is-argv1
    if(argc != 2){
        printf("Error: Please provide the database name\n");
        return 1;
    }
    strncpy(databaseName, argv[1], sizeof(databaseName) - 1);  //https:www.geeksforgeeks.org/strncpy-function-in-c/
    databaseName[sizeof(databaseName)- 1] = '\0'; 

    numRecs = initialCount; // initializes the number of records in the dummy database
    dummyRecords();

    menu();
    return 0;
}


       