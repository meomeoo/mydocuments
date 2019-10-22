#include<stdio.h>
# define maxlength 1000

typedef int elementtype; /* elements are integers */

typedef struct list_tag 
{
    elementtype elements [maxlength];
    int last;
} list_type;

int end (list_type *lp)
{
    return (lp->last +1);
}

void insert (elementtype x , int p , list_type * lp)
{
    int v; // running position
    if (lp -> last >= maxlength - 1)
    {
        printf("\n%s ","list is full");
        return;
    }
    if ((p < 0) || (p > lp -> last + 1))
    {
        printf("\n%s ","position does not exist");
        return;
    }
    else{
        for (int q = lp -> last; q >= p; q--)
        lp -> elements [q+1] = lp -> elements [q];
        lp -> last = lp -> last +1 ;
        lp -> elements[p] = x;
        }
}

void deleteL(int p , list_type * lp)
{
    int q; /* running position */
    if ((p > lp-> last) || (p < 0))
    {
        printf("\n%s ","position does not exist");
        return;
    }
    else /* shift elements */ {
    lp -> last --;
    for (int q = p; q <= lp ->last; q++)
    lp -> elements [q] = lp -> elements [q+1];
    }
}

int main()
{
    list_type *lp, L;
    lp = &L;
    lp -> last =2;
    lp -> elements[0]=1;
    lp -> elements[1]=2;
    lp -> elements[2]=3;
    
    printf("%d\n",lp->elements[i]);

    



    

}

