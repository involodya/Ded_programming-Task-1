#include <stdio.h>
#include <stdlib.h>
#include <assert.h>      // ��� assert
#include <math.h>       // ��� isfinite

/* The squire equations solver function

   @version Vers 1.0
   @date 09. 09. 2021

   @brief Solving task #1 for the course "Professional Programming"

   @param [in] a  a-coefficient
   @param [in] b  b-coefficient
   @param [in] c  c-coefficient
   @param [out] x1 x1-coefficient
   @param [out] x2 x2-coefficient

   @return Number of roots

*/


#include "defines.h"
#include "unittest.h"

int SolvingEquation(double a, double b, double c, double* x1,double* x2){

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    if (a==0 || (a<0.00001 && a>(-0.00001) ))
    {
        if (b==0)
          {

          if (c==0)
            {
            return INFINITE_NROOTS;
            }
          else
            {
            return 0;
            }

          }

        else
          {
          *x1=-c/b;
          return 1;
          }

    }

    else
        {
        double discr= b*b-4*a*c;


        if (discr<0)            // NEGATIVE DISCRIMINANT
            {
            return 0;
            }

        if (discr==0)           // ZERO DISCRIMINANT
            {
            *x1=(-b)/(2*a);
            return 1;
            }

        if (discr>0)            // POSITIVE DISCRIMINANT
            {
            double dsqrt = sqrt(discr);

            *x1 = (-b-dsqrt) / (2*a);
            *x2 = (-b+dsqrt) / (2*a);

            return 2;
            }
        }

}


int main()
{
    UnitTest();
    printf("\tKozhanov Gleb, B05-120\n");
    printf("\tThe square equation solver\n\n");
    printf("PLease, enter a,b,c:");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    scanf("%lg %lg %lg", &a, &b, &c);
    int Nroot = SolvingEquation(a,b,c,&x1,&x2);

    switch (Nroot)
    {
        case 0: printf("No roots\n");
                break;

        case 1: printf("x1=%lg\n",x1);
                break;

        case 2: printf("x1=%lg, x2=%lg\n", x1, x2);
                break;

        case INFINITE_NROOTS: printf("Any number");
                break;

        default: printf("main(): ERROR: nRoots = %d/n", Nroot);
                return 1;

    }


    return 0;
}
