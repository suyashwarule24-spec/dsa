// Extracted from dsa 2.pdf
#include <stdio.h>



void selectionSort(float arr[], int n)

{
    int i, j, min;

    float temp;

    for(i = 0; i < n - 1; i++){

        min = i;
        for(j = i + 1; j < n; j++){

            if(arr[j] < arr[min])

                min = j;}

        temp = arr[i];
        arr[i] = arr[min];

        arr[min] = temp;

    }

}


void bubbleSort(float arr[], int n)

{

    int i, j;
    float temp;



    for(i = 0; i < n - 1; i++){

        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1])

         {

                temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }

        }

    }

}


void display(float arr[], int n)

{

    int i;


    printf("\nSorted Percentages:\n");

    for(i = 0; i < n; i++){

        printf("%.2f ", arr[i]);
    }

    printf("\n");

}


void topFive(float arr[], int n)

{

    int i, count;


    printf("\nTop Five Scores:\n");



    count = (n < 5) ? n : 5;


    for(i = n - 1; i >= n - count; i--)

    {

        printf("%.2f\n", arr[i]);

    }
}





int main()
{

    float per[100];

    int n, i, choice;


    printf("Enter number of students: ");

    scanf("%d", &n);



    printf("Enter first year percentages:\n");
    for(i = 0; i < n; i++){

        scanf("%f", &per[i]);

    }


    do{

        printf("\n===== MENU =====\n");

        printf("1. Selection Sort\n");

        printf("2. Bubble Sort\n");
        printf("3. Display Top Five Scores\n");

        printf("4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch(choice){

            case 1:
                selectionSort(per, n);

                printf("\nArray Sorted Using Selection Sort.\n");

                display(per, n);

                break;


            case 2:

                bubbleSort(per, n);

                printf("\nArray Sorted Using Bubble Sort.\n");

                display(per, n);
                break;



            case 3:

                topFive(per, n);
                break;



            case 4:

                printf("Exiting Program...\n");
                break;



            default:

                printf("Invalid Choice!\n");
        }



    } while(choice != 4);


    return 0;

}
