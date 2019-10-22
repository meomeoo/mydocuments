#include<stdio.h>


int delete_node( LIST *linp,int k)
{
    Node* node_delete=NULL, cur, pre_node;
    cur = linp;
    if( cur-> key ==k)
        printf("Khong co nut nhu yeu cau can xao!");
    else if (cur->next->key==k){
        node_delete = cur;
        free(cur);
        return node_delete->key;
    }
    else{
        while(cur!=NULL){
            pre_node=cur;
            cur=cur->next;
            if(cur->next!=NULL){
                printf("Khong co nut nhu yeu cau can xao!");
                break;
            } 
            if(cur->next->key==k ){
                node_delete=cur;
                pre_delete->next=node_delete->next;
                free(cur);
                return node_delete->key;
                break;
            }

                


            
        }
        
    }
    
    
    
    


}