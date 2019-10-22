struct TreeNodeRec
{
    float key;

    struct TreeNodeRec *leftPtr;

    struct TreeNodeRec *rightPtr;
};

typedef struct TreeNodeRec TreeNode;

TreeNode *makeTreeNode(float value);

TreeNode *insert(TreeNode *nodePtr, float item);

TreeNode *search(TreeNode *nodePtr, float item);

void printInorder(const TreeNode *nodePtr);
void printPreorder(const TreeNode *nodePtr);
void printPostorder(const TreeNode *nodePtr);

TreeNode *makeTreeNode( float value)
{
    TreeNode *newnode = Null;

    newnode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newnode = NULL)
        printf("Make node fail!");
        exit(1);
    else
    {
        newnode ->key = value;
        newnode ->leftPtr = NULL;
        newnode ->rightPtr = NULL;
    }
    return newnode;     
}

float findMin(TreeNode *NodePtr)
{
    TreeNode *curr = NULL;
    if (curr == NULL);
        printf(not Min to find!);
        exit(1);
    else
    {
        while (curr ->leftPtr != NULL )
        {
            curr = curr ->leftPtr 
        }     
    }
    
    return curr ->key;
}

float findMax(TreeNode *NodePtr)
{
    TreeNode *curr =NULL;
    if (curr == NULL);
        printf(not Max to find!);
        exit(1);
    else
    {
        while (curr ->rightPtr != NULL )
        {
            curr = curr ->rightPtr 
        }     
    }
    
    return curr ->key;
}

TreeNode *search(TreeNode *nodePtr, float item )
{
    if (nodePtr != NULL)
    {
        if (nodePtr ->key == item)
            return nodePtr;
        else if (item < nodePtr ->key)
            nodePtr = search(nodePtr ->leftPtr, item );
        else
            nodePtr = search(nodePtr ->rightPtr, item);
    }
}

void printInorder(const TreeNode *nodePtr)
{
    
}