// Extracted from DOC-20261008-WA0008.pdf
#include <stdio.h>

  #define MAX 5

  int queue[MAX];
  int front = -1;
  int rear = -1;

  void addJob()
  {
      int job;

      if ((rear + 1) % MAX == front)
      {
          printf("Queue is Full! Cannot accept more jobs.\n");
          return;
      }

      printf("Enter Job Number: ");
      scanf("%d", &job);

      if (front == -1)
      {
          front = 0;
          rear = 0;
      }
      else
      {
          rear = (rear + 1) % MAX;
      }

      queue[rear] = job;

      printf("Job %d added successfully.\n", job);
  }

  void deleteJob()
  {
      if (front == -1)
      {
          printf("Queue is Empty! No job to process.\n");
          return;
      }

      printf("Job %d is processed.\n", queue[front]);

      if (front == rear)
      {
          front = -1;
          rear = -1;
      }
      else
      {
          front = (front + 1) % MAX;
      }
  }

  void display()
  {
      int i;

      if (front == -1)
      {
          printf("Queue is Empty.\n");
          return;
      }

      printf("Jobs in Queue: ");
      i = front;

      while (1)
      {
          printf("%d ", queue[i]);

          if (i == rear)
              break;

          i = (i + 1) % MAX;
      }

      printf("\n");
  }

  int main()
  {
      int choice;

      do
      {
          printf("\n----- CIRCULAR JOB QUEUE -----\n");
          printf("1. Add Job\n");
          printf("2. Delete Job\n");
          printf("3. Display Queue\n");
          printf("4. Exit\n");

          printf("Enter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
              case 1:
                  addJob();
                  break;

              case 2:
                  deleteJob();
                  break;

              case 3:
                  display();
                  break;

              case 4:
                  printf("Program terminated.\n");
                  break;

              default:
                  printf("Invalid choice!\n");
          }

      } while (choice != 4);

      return 0;
  }
