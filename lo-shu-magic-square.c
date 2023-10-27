#include <stdio.h>
#include <time.h>

void randomize(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    //I have no idea why this was so difficult to generate unqiue numbers mostly because I cant just do rand.range(len(array))
    //where array.pop(range)
    int loop = 0;
    int counter = 0;
    while (loop == 0)
    {
        int array[3][3];
        int numbers[9];

        srand(time(NULL));

        for (int i = 0; i < 9; i++)
        {
            numbers[i] = i + 1;
        }

        randomize(numbers, 9);

        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                array[i][j] = numbers[index];
                index++;
            }
        }
            
        loop = inp(array);
        counter++;
    }
    printf("Number of tries: %d\n", counter);
    return 0;
}

int inp(int arr[3][3])
{

    // Why I like python -> [:]
    int sum = arr[0][0] + arr[0][1] + arr[0][2];
    int sum2 = arr[1][0] + arr[1][1] + arr[1][2];
    int sum3 = arr[2][0] + arr[2][1] + arr[2][2];
    int sum4 = arr[0][0] + arr[1][0] + arr[2][0];
    int sum5 = arr[0][1] + arr[1][1] + arr[2][1];
    int sum6 = arr[0][2] + arr[1][2] + arr[2][2];
    int sum7 = arr[0][0] + arr[1][1] + arr[2][2];
    int sum8 = arr[0][2] + arr[1][1] + arr[2][0];

    if (sum, sum2, sum3, sum4, sum5, sum6, sum7, sum8 == 15)
    {
        printf("[%d %d %d]\n", arr[0][0], arr[0][1], arr[0][2]);
        printf("[%d %d %d]\n", arr[1][0], arr[1][1], arr[1][2]);
        printf("[%d %d %d]\n", arr[2][0], arr[2][1], arr[2][2]);

        return 1;
    }
    else
    {
        return 0;
    }
}
