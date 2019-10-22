typedef int* ListT;
typedef int** NodeT;
typedef int position;

typedef struct 
{
    ListT header[maxNodes];
    labeltype labels[maxNodes];
    NodeT root;

} TreeT;

