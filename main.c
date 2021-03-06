#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
int InitializeArraySize();
void FillArrayWithRand(int* array, int size);
int GetRandomNumber(int min_number, int max_number);
void PrintArray(int array[], int size);
int GetMinIndex(int array[], int size);
void CopyArrays(int* array1, int* array2, int sizeOfSmallerArray);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *one, int* two);
int GetRepNumsCount(int arr[], int size);
void PrintAllRepNums(int array[], int size);
void ArrayWorkWithRandomNumbers();
void ArrayWorkWithManualNumbers();
void SaveArray(int array[], int size);
void EditArray(int* array, int size);

int main()
{
    srand(time(0));
    int choice = 0;
    main_menu:
    printf("\nWhat would you want to do?\n1-Array work\n2-Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        {
            secondmenu:;
            int secondChoice = 0;
            printf("\nWhat would you want to do?\n1-Create an array \n2-Open an array\n3-Back\n");
            scanf("%d", &secondChoice);
            switch (secondChoice)
            {
            case 1:
            //Create an aray:
                randomOrManualChoice:;
                int randomOrManual = 0;
                printf("\nChoose:\n1-Random Numbers\n2-Manual mode\n3-Back\n");
                scanf("%d", &randomOrManual);
                switch (randomOrManual)
                {
                case 1:
                //random numbers array
                    ArrayWorkWithRandomNumbers();
                    goto main_menu;
                    break;
                case 2:
                    ArrayWorkWithManualNumbers();
                    break;
                case 3:
                //go to back(to second menu)
                    goto secondmenu;
                    break;
                default:
                    printf("Invalid choice!\n\n");
                    goto randomOrManualChoice;
                    break;
                }
                break;
            case 2:
                //TODO Opening an array from file
                break;
            case 3:
            //Back (main menu)
                goto main_menu;
                break;
            default:
            printf("Invalid choice!\n\n");
                goto secondmenu;
                break;
            }
            break;
        }
        case 2:
            break;
        default:
        {
            printf("Invalid choice!\n\n");
            goto main_menu;
            break;
        }
    }
    return 0;
}

int InitializeArraySize()
{
    //User enters size for an array
    unsigned int size = 0;
    printf("How big should the InitialArray be? (≤100)\n");
    here:
    scanf("%d, size", &size);
    if(size < 1 || size > 100)
    {
        printf("Invalid size! Choose a number between 1 and 100\n");
        goto here;
    }
    return size;
}

void FillArrayWithRand(int* array, int size)
{
    //Fills array with random numbers
    for (int i = 0; i < size; i++)
    {
        array[i] = GetRandomNumber(0, 100);
    }
}

int GetRandomNumber(int min_number, int max_number)
{
    //Generates a random number
    int number = (rand() % (max_number + 1 - min_number )) + min_number;
    return number;
}

void PrintArray(int array[], int size)
{
    //Prints array
	for (int i = 0; i < size; i++)
	{
		printf("[%d] = %d\n", i, array[i]);
	}
}

int GetMinIndex(int array[], int size)
{
    //Returns the index of the min number in array
    int minnum = array[0];
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < minnum)
        {
            minnum = array[i];
            index = i;
        }
    }
    return index;
}

void CopyArrays(int* array1, int* array2, int sizeOfSmallerArray)
{
    //Copies the elements from array1 to array2 (array2 MUST BE THE SAME SIZE OF SMALLER THAN array1)
    for (int i = 0; i < sizeOfSmallerArray; i++)
    {
        array2[i] = array1[i];
    }
}

void quickSort(int array[], int low, int high)
{
    //Self-explanatory
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi-1);
        quickSort(array, pi+1, high);
    }
}

int partition(int array[], int low, int high)
{
    //Teruns the pivot for quickSort
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }   
    }
    swap(&array[i+1], &array[high]);
    return (i+1);
}

void swap(int *one, int* two)
{
    //swaps the values of 'one' and 'two'
    int temp = *one;
    *one = *two;
    *two = temp;
}

int GetRepNumsCount(int arr[], int size)
{
    //Returns the Count of the numbers that are repeated in array
    //NOTE: the function doesn't return how many times the number has been returned
    int count = 0, j;
    for (int i = 0; i < size - 1; i++)
    {
        j = 1;
        while(arr[i] == arr[i+1])
        {
            i++;
            j++;
        }
        if (j != 1)
        {
            count++;
        }
    }
    return count;
}

void PrintAllRepNums(int array[], int size)
{
    //Prints every number that is repeated in array AND how many times it has been repeated
    int RepNumsCount = GetRepNumsCount(array,size);
    printf("Repeated Numbers: %d\n", RepNumsCount);
    if (RepNumsCount != 0)
    {
        int** RepesatingNumbers = (int**)malloc(RepNumsCount * sizeof(int));
        for (int i = 0; i < RepNumsCount; i++){RepesatingNumbers[i] = (int*)malloc(2*sizeof(int));}
        
        int j = 0;
        for (int i = 0; i < RepNumsCount; i++)
        {
            int count = 1;
            while (array[j] != array[j+1])
            {
                j++;
            }
            while (array[j] == array[j+1])
            {
                j++;
                count++;
            }
            RepesatingNumbers[i][0] = array[j];
            RepesatingNumbers[i][1] = count;      
            printf("%d is repeated %d times\n",RepesatingNumbers[i][0], RepesatingNumbers[i][1]);
        }
    }
}

void ArrayWorkWithRandomNumbers()
{
        int InitialArraySize, SecondArraySize, EditChoice;
        InitialArraySize = InitializeArraySize();
        int* InitialArray = (int*) malloc(InitialArraySize * sizeof(int));
        FillArrayWithRand(InitialArray, InitialArraySize);
        PrintArray(InitialArray, InitialArraySize);
        printf("Before continuing, would you want to edit the array?\n1-Yes\n2-No\n");
        editchoice_manual:
        scanf("%d", & EditChoice);
        if (EditChoice == 1)
        {
            EditArray(InitialArray, InitialArraySize);
        }
        else if (EditChoice == 2)
        {
        }
        else
        {
            printf("Invalid choice!\nEnter 1 or 2\n");
            goto editchoice_manual;
        }
        PrintArray(InitialArray, InitialArraySize);    
        SecondArraySize = GetMinIndex(InitialArray, InitialArraySize);
        printf("Min index is %d and InitialArray[%d] = %d\n", SecondArraySize, SecondArraySize, InitialArray[SecondArraySize]);
        int* SecondArray = (int*) malloc(SecondArraySize * sizeof(int));
        CopyArrays(InitialArray, SecondArray, SecondArraySize);
        printf("---------\nNew Array:\n");
        PrintArray(SecondArray, SecondArraySize);
        printf("---------\nSorted New Array:\n");
        quickSort(SecondArray, 0, SecondArraySize - 1);
        PrintArray(SecondArray,SecondArraySize);
        printf("----------\n");
        PrintAllRepNums(SecondArray,SecondArraySize);
        int save = 0;
        save_option_auto:
        printf("\nWould you like to Save the array?\n1-Yes\n2-No(Exit to Main Menu)\n");
        scanf("%d", &save);
        if (save == 1)
        {
            SaveArray(SecondArray,SecondArraySize);
        }
        else if (save == 2)
        {
            exit;
        }
        else
        {
            printf("Invalid choice!\n");
            goto save_option_auto;
        }
}

void ArrayWorkWithManualNumbers()
{
    int InitialArraySize, SecondArraySize, EditChoice;
    InitialArraySize = InitializeArraySize();
    int* InitialArray = (int*) malloc(InitialArraySize * sizeof(int));
    for (int i = 0; i < InitialArraySize; i++)
    {
        printf("Enter number[%d] :", i);
        scanf("%d", &InitialArray[i]);
    }
    PrintArray(InitialArray, InitialArraySize);
    printf("Before continuing, would you want to edit the array?\n1-Yes\n2-No\n");
    editchoice_manual:
    scanf("%d", & EditChoice);
    if (EditChoice == 1)
    {
        EditArray(InitialArray, InitialArraySize);
    }
    else if (EditChoice == 2)
    {
    }
    else
    {
        printf("Invalid choice!\nEnter 1 or 2\n");
        goto editchoice_manual;
    }
    PrintArray(InitialArray, InitialArraySize);
    SecondArraySize = GetMinIndex(InitialArray, InitialArraySize);
    printf("Min index is %d and InitialArray[%d] = %d\n", SecondArraySize, SecondArraySize, InitialArray[SecondArraySize]);
    int* SecondArray = (int*) malloc(SecondArraySize * sizeof(int));
    CopyArrays(InitialArray, SecondArray, SecondArraySize);
    printf("---------\nNew Array:\n");
    PrintArray(SecondArray, SecondArraySize);
    printf("---------\nSorted New Array:\n");
    quickSort(SecondArray, 0, SecondArraySize - 1);
    PrintArray(SecondArray,SecondArraySize);
    printf("----------\n");
    PrintAllRepNums(SecondArray,SecondArraySize);
    int save = 0;
    save_option:
    printf("\nWould you like to Save the array?\n1-Yes\n2-No(Exit to Main Menu)\n");
    scanf("%d", &save);
    if (save == 1)
    {
        SaveArray(SecondArray,SecondArraySize);
    }
    else if (save == 2)
    {
        exit;
    }
    else
    {
        printf("Invalid choice!\n");
        goto save_option;
    }
}

void SaveArray(int array[], int size)
{
    //saves array to an file
    char name[64]; 
	printf("Enter the name of the file to be created: "); 
	scanf("%s", &name);
    FILE* fptr;
    fptr = fopen(name, "w"); 
    for (int i = 0; i <= size/4; i++)
    {
        for (int j = i*4; j < i*4 + 4; j++)
        {
            fprintf(fptr,"%d",array[j]);
            if(j<i*4 + 3) { fprintf(fptr, " ");}
        }
        fprintf(fptr, "\n");
    }  
}

void EditArray(int* array, int size)
{
    int ChangeChoiceInFunc = 1;
    int IndexToEditinFunc = 0;
    do
    {
        EnteringIndexForEditing:
        printf("What index whould you like to Edit? ");
        scanf("%d", &IndexToEditinFunc);
        if (IndexToEditinFunc >=0 && IndexToEditinFunc < size)
        {
            printf("InitialArray[%d] = ", IndexToEditinFunc);
            scanf("%d", &array[IndexToEditinFunc]);
            editchoice:
            printf("Change another number?(1/0)\n1-Yes\n0-No\n");
            scanf("%d", &ChangeChoiceInFunc);
            if ( !(ChangeChoiceInFunc == 1 || ChangeChoiceInFunc == 0) )
            {
                printf("Invalid choice!\n");
                goto editchoice;
            }
        }
        else
        {
            printf("Invalid index!\n");
            goto EnteringIndexForEditing;
        }
    }while(ChangeChoiceInFunc == 1);
}