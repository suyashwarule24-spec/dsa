// Extracted from dsa assignmnet 1.pdf
// Code section 1
#include <stdio.h>

int linearSearch(int arr[], int n, int key){

    int i;

    for(i = 0; i < n; i++){
        if(arr[i] == key {

            return i; // Roll number found

        }

    }
    return -1;// Roll number not found

}



int main(){
    int roll[100];

    int n, i, choice, key, result;

    printf("Enter the number of students attended training: ");

    scanf("%d", &n);
    printf("Enter roll numbers:\n");

    for(i = 0; i < n; i++){

        scanf("%d", &roll[i]);

    }
    do{

        printf("\n===== MENU =====\n");

        printf("1. Display Roll Numbers\n");

        printf("2. Search Roll Number\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);



        switch(choice){
            case 1:

                printf("\nStudents Attended Training:\n");

                for(i = 0; i < n; i++){

                    printf("%d ", roll[i]);
                }

                printf("\n");

                break;


            case 2:

                printf("Enter roll number to search: ");

                scanf("%d", &key);

                result = linearSearch(roll, n, key);
                if(result != -1){

                  printf("Student with Roll Number %d attended the
training program.\n", key);
                }

                else{

                   printf("Student with Roll Number %d did NOT attend
the training program.\n", key);
                }

                break;

            case 3:

                printf("Exiting program...\n");

                break;
            default:

                printf("Invalid choice! Please try again.\n");

        }


    } while(choice != 3);



    return 0;

}

// Code section 2
#include <stdio.h>

int binarySearch(int arr[], int n, int key){

    int low = 0, high = n - 1, mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(arr[mid] == key){

            return mid;   // Roll number found

        }
        else if(arr[mid] < key){

            low = mid + 1;

        }

        else{
            high = mid - 1;

        }

    }

    return -1;   // Roll number not found
}

int main(){

    int roll[100];

    int n, i, choice, key, result;
    printf("Enter the number of students attended training: ");

    scanf("%d", &n);

    printf("Enter roll numbers:\n");

    for(i = 0; i < n; i++){
        scanf("%d", &roll[i]);

    }

    do{

        printf("\n===== MENU =====\n");

        printf("1. Display Roll Numbers\n");
        printf("2. Search Roll Number\n");

        printf("3. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch(choice){

            case 1:

                printf("\nStudents Attended Training:\n");
                for(i = 0; i < n; i++){

                    printf("%d ", roll[i]);}

                printf("\n");

                break;
            case 2:

                printf("Enter roll number to search: ");

                scanf("%d", &key);

                result = binarySearch(roll, n, key);
                if(result != -1){

                  printf("Student with Roll Number %d attended the
training program.\n", key);

                }
                else{

                   printf("Student with Roll Number %d did NOT attend
the training program.\n", key);}

                break;
            case 3:

                printf("Exiting program...\n");

                break;
            default:

                printf("Invalid choice! Please try again.\n");}

    } while(choice != 3);

 return 0;

    }
