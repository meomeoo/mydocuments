#include <stdio.h>
#include <conio.h>

typedef struct
{
    int a, b;
} binh;

int kiemtra(binh *Q, int L, binh v);
int inkq(int *pi, binh *Q, int L);

void dongnuoc(int n, int m, int k)
{
    binh *Q = new binh[(m + 1) * (n + 1) + 1];
    int *pi = new int[(m + 1) * (n + 1) + 1];
    int F = 0, L = 0;
    Q[0].a = 0;
    Q[0].b = 0;
    while (F <= L)
    {
        binh v, u = Q[F];
        v.a = 0;
        v.b = u.b; //1
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        v.a = u.a;
        v.b = 0; //2
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        v.a = n;
        v.b = u.b; //3
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        v.a = u.a;
        v.b = m; //4
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        if (u.a + u.b > m)
        {
            v.a = u.a + u.b - m;
            v.b = m;
        }
        else
        {
            v.a = 0;
            v.b = u.a + u.b;
        } //5
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        if (u.a + u.b > n)
        {
            v.a = n;
            v.b = u.a + u.b - n;
        }
        else
        {
            v.a = u.a + u.b;
            v.b = 0;
        } //6
        if (kiemtra(Q, L, v))
        {
            L++;
            Q[L] = v;
            pi[L] = F;
            if (v.a == k || v.b == k)
                break;
        }
        F++;
    }
    if (F <= L)
        inkq(pi, Q, L);
    else
        printf("\nKhong dong duoc nuoc");
}

int kiemtra(binh *Q, int L, binh v)
{
    for (int i = 0; i <= L; i++)
        if (Q[i].a == v.a && Q[i].b == v.b)
            return 0;
    return 1;
}

int inkq(int *pi, binh *Q, int L)
{
    if (L == 0)
        printf("(%d,%d)", 0, 0);
    else
    {
        inkq(pi, Q, pi[L]);
        printf("->(%d,%d)", Q[L].a, Q[L].b);
    }
}

int main()
{
    int m, n, k;
    printf("Nhap dung tich can 1 : ");
    scanf("%d", &m);
    printf("Nhap dung tich can 2 : ");
    scanf("%d", &n);
    printf("Nhap dung tich can dong : ");
    scanf("%d", &k);
    if (k > m && k > n)
        printf("\nKhong dong duoc");
    else
        dongnuoc(m, n, k);
    getch();
}