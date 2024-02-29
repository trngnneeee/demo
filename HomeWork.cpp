#include <iostream>
#include <math.h>

bool isSqrNum(int x)
{
    int tmp = sqrt(x);
    return tmp * tmp == x;
}

double percentageOfFindingLuggage(int exp1){
    // 4.2.1
    int s = round(sqrt(exp1)) * round(sqrt(exp1));
    double p1;
    if (exp1 >= s) p1 = 1;
    else p1 = ((double)exp1 / s + 80) / 123;
    return p1;
}

double traceLuggage(int hp1, int exp1, double m1, int e2)
{
    // 4.2.2
    double p2;
    if (e2 % 2 != 0)
    {
        double usedMoney = 0;
        while (usedMoney > 0.5 * m1)
        {
            if (hp1 < 200)
            {
                hp1 *= 1.3;
                m1 -= 150;
                usedMoney += 150;
            }
            else
            {
                hp1 *= 1.1;
                m1 -= 70;
                usedMoney += 70;
            }
            if (exp1 < 400) 
            {
                m1 -= 200;
                usedMoney += 200;
            }
            else
            {
                m1 -= 120;
                usedMoney += 120;
            }
            exp1 *= 1.13;
            if (exp1 < 300)
            {
                m1 -= 100;
                usedMoney += 100;
            }
            else
            {
                m1 -= 120;
                usedMoney += 120;
            }
            exp1 *= 0.9;
        }
        hp1 *= 0.83;
        exp1 *= 1.17;
        p2 = percentageOfFindingLuggage(exp1);
        return p2;
    }
    else
    {
        if (hp1 < 200)
            {
                hp1 *= 1.3;
                m1 -= 150;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            else
            {
                hp1 *= 1.1;
                m1 -= 70;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            if (exp1 < 400) 
            {
                m1 -= 200;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            else
            {
                m1 -= 120;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            exp1 *= 1.13;
            if (exp1 < 300)
            {
                m1 -= 100;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            else
            {
                m1 -= 120;
                if (m1 == 0)
                {
                    hp1 *= 0.83;
                    exp1 *= 1.17;
                    p2 = percentageOfFindingLuggage(exp1);
                    return p2;
                }   
            }
            exp1 *= 0.9;
    }
    p2 = percentageOfFindingLuggage(exp1);
    return p2;
    
}

int findI(int e2){
    if (e2 < 10) return e2;
    else if (e2 >= 10 && e2 <= 99)
    {
        int sum = 0;
        sum += e2 % 10;
        e2 /= 10;
        sum += e2;
        return sum % 10;
    }
}

int main()
{
    
    return 0;
}