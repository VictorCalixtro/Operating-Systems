#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void showFrameFunc(int a[], int size)
{
    int i = 0;
    for (; i < size; i++)

        printf("%d ", a[i]);

    printf("\n");
}

void Optimal_Algorithm_func(int a[], int size, int frame_number)
{

    int frame[frame_number], i, index = 0, count, j, k, farthest;

    int page_fault = 0;

    bool page[6];

    for (i = 0; i < 6; i++)
        page[i] = false;

    for (i = 0; i < size; i++)
    {

        if (index < frame_number && !page[a[i]])
        {

            page_fault++;

            frame[index++] = a[i];

            page[a[i]] = true;
        }

        else if (index >= frame_number && !page[a[i]])
        {

            page_fault++;

            count = 0;

            bool visited[6];

            for (j = 0; j < 6; j++)
                visited[j] = false;

            for (j = i + 1;; j++)
            {

                if (count == frame_number || j == size)
                    break;

                if (page[a[j]] && !visited[a[j]])
                {
                    farthest = a[j];
                    visited[a[j]] = true;

                    count++;
                }
            }

            printf("%d will be replaced\n", farthest);

            page[farthest] = false;

            for (k = 0; k < frame_number; k++)
            {

                if (frame[k] == farthest)
                    break;
            }

            frame[k] = a[i];

            page[a[i]] = true;
        }

        showFrameFunc(frame, index);
    }

    int page_hit = 20 - page_fault;

    printf("\nPage fault= %d\nPage hit = %d\n\n", page_fault, page_hit);
}



void LRU_Algorithm_Func(int a[], int size, int frame_number)
{

    int frame[frame_number], i, index = 0, count, j, k, LRU_Algorithm_Func;

    int page_fault = 0;

    bool page[6];

    for (i = 0; i < 6; i++)
        page[i] = false;

    for (i = 0; i < size; i++)
    {

        if (index < frame_number && !page[a[i]])
        {

            page_fault++;

            frame[index++] = a[i];

            page[a[i]] = true;
        }

        else if (index >= frame_number && !page[a[i]])
        {

            page_fault++;

            count = 0;

            bool visited[6];

            for (j = 0; j < 6; j++)
                visited[j] = false;

            for (j = i - 1;; j--)
            {

                if (count == frame_number || j < 0)
                    break;

                if (page[a[j]] && !visited[a[j]])
                {
                    LRU_Algorithm_Func = a[j];
                    visited[a[j]] = true;

                    count++;
                }
            }

            printf("%d will be replaced\n", LRU_Algorithm_Func);

            page[LRU_Algorithm_Func] = false;

            for (k = 0; k < frame_number; k++)
            {

                if (frame[k] == LRU_Algorithm_Func)
                    break;
            }

            frame[k] = a[i];

            page[a[i]] = true;
        }

        showFrameFunc(frame, index);
    }

    int page_hit = 20 - page_fault;

    printf("\nPage fault= %d\nPage hit = %d\n\n", page_fault, page_hit);
}



int main()
{

    int frame_number, i;

    printf("Enter the frame number : ");

    scanf("%d", &frame_number);

    int arr[frame_number];

    bool page[6];

    for (i = 0; i < 6; i++)
        page[i] = false;

    int a[20];

    for (i = 0; i < 20; i++)
    {

        a[i] = rand() % 5 + 1;
    }
    
    showFrameFunc(a, 20);

    printf("***************LRU_Algorithm_Func_****************\n");

    LRU_Algorithm_Func(a, 20, frame_number);
    

    printf("***************Optimal_Algorithm_func**************\n");

    Optimal_Algorithm_func(a, 20, frame_number);

    



    return 0;
}
