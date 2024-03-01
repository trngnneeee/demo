#include <iostream>
#include <math.h>

int findMaxOfDiagonal(int a[][10], int indexRow, int indexColum){
    int max = 0;    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i + j == indexRow + indexColum || i - j == indexRow - indexColum)
            {
                if (a[i][j] > max) max = a[i][j];
            }
        }
    }   
    return max;
}

int chaseTaxi(int hp1, int hp2, int exp1, int exp2, int e3){
    int taxiMap[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiMap[i][j] = ((e3 * j) + (i * 2)) * (i - j);
        }
    }

    int sherlockMap[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sherlockMap[i][j] = findMaxOfDiagonal(taxiMap, i, j);
            if (sherlockMap[i][j] < 0) sherlockMap[i][j] = abs(sherlockMap[i][j]);
        }
    }

}

int main()
{
    
    return 0;
}