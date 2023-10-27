#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void remplirTableauAvecEntiersAleatoires(int tab[], int taille, int valeurMax);
void selectionSort (int tab[], int numberOfElements);
void insertionSort(int tab[], int numberOfElements);
int main(){
    int tab[1000];
    int taille,option;
    do {
      printf("\n\nEntrer la taille du Tableau >>: ");
      scanf("%d",&taille);
    }while(taille < 0 || taille > 1000);

    remplirTableauAvecEntiersAleatoires(tab,taille,1000000); // Function Call

    // afficher le tableau remlir par les valeurs aleatoires
    printf("\n\nThis Table is fulled with Random values and it is not sorted:\n ");
    printf("\n\n\t{ ");
    for(int i = 0 ; i < taille; i++){
        printf(" %d , ",tab[i]);
    }
    printf(" }\t\n\n");
    printf("\nChoose An Algorithme to Sort The Random Table Above\n");
    printf("\n0.Tri Par Selection (Sort By Selection)\n");
    printf("\n1.Tri Par insertion (Sort By Insertion)\n");
    printf("\nEnter Your Option: ");
    scanf("%d",&option);
    switch(option){
        case 0: 
            selectionSort(tab,taille); // Calling The Sort by Selection function to sort the table
            printf("\n\nThe Table Sorted Using Selection Sort Algorithme:\n");
            printf("\n\n\t{ ");
            clock_t startTime = clock(); // start Timer
            for(int i = 0 ; i < taille; i++){
                printf(" %d , ",tab[i]);
            }
            clock_t endTime = clock(); // stop Timer
            printf(" }\t\n\n");
            printf("This Algorithme took %d seconds to execute\n\n",(endTime - startTime));
            break;
        case 1:
            insertionSort(tab,taille); // Calling The Sort By Insertion Function to Sort the Table
            printf("\n\nThe Table Sorted Using Insertion Sort Algorithme:\n");
            printf("\n\n\t{ ");
            clock_t start = clock();//Start The Timer
            for(int i = 0 ; i < taille; i++){
                printf(" %d , ",tab[i]);
            }
            clock_t end = clock();//Stop The Timer
            printf(" }\t\n\n");
            printf("This Algorithme took %d seconds to execute\n\n",(end - start));
            break;
        default:
            printf("\nPlease entre one of the option above 0 or 1\n\n");
    }
            
    return 0;
}

// Funciton part
void remplirTableauAvecEntiersAleatoires(int tab[], int taille, int valeurMax){
    for(int i = 0 ; i < taille; i++){
        tab[i] = rand() % valeurMax;
    }
}
// Le procedure de tri par selection du minumum
void selectionSort (int tab[], int numberOfElements)
{
  int i = 0 ; int  j , minIndex,temp;
  while(i < numberOfElements)
  {
    minIndex = i;
    for(j = i+1 ; j < numberOfElements ; j++){
        if(tab[j] < tab[minIndex])
        {
            minIndex = j;
        }
    }
    temp = tab[minIndex];
    tab[minIndex] = tab[i];
    tab[i] = temp;
    i++;
  }
}
// Le procedure de tri par insertion
void insertionSort(int tab[], int numberOfElements)
{
    int i , pos, temp;
    for(i = 0 ; i < numberOfElements; i++)
    {
        temp = tab[i];
        pos = i;
        while((pos > 0)  && (tab[pos-1] > temp))
        {
            tab[pos] = tab[pos-1];
            pos = pos - 1;
        }
        tab[pos] = temp;
    }
}