#include<stdio.h>
#include<stdlib.h>
int n;
int book[100];
struct node
{
    int data;
    struct node* lchild, * rchild;
};
void SearchBST(struct node* root,int c)
{
    while (root)
    {
        if (root->data == c)
        {
            printf("找到了\n");
            return;
        }
        else if (c < root->data)
        {
            root = root->lchild;
        }
        else if (c > root->data)
        {
            root = root->rchild;
        }
        
    }
    printf("没找到\n");
}
void InsertBST(struct node* root, int c)
{
    if (root->data==NULL)
    {
        root->data = c;
        printf("%d", root->data);
        printf("插入成功\n");
        return;
    }
    while (1)
    {
        if (root->data == c)
        {
            printf("已有相同元素，插入失败\n");
            return;
        }
        else if (c < root->data && root->lchild != NULL)
        {
            root = root->lchild;
        }
        else if (c > root->data && root->rchild != NULL)
        {
            root = root->rchild;
        }
        else if (c < root->data && root->lchild == NULL)
        {
            struct node* p = (struct node*)malloc(sizeof(struct node));
            p->lchild = NULL;
            p->rchild = NULL;
            root->lchild = p;
            p->data = c;
            printf("%d", p->data);
            printf("插入成功\n");
            return;
        }
        else if (c > root->data && root->rchild == NULL)
        {
            struct node* p = (struct node*)malloc(sizeof(struct node));
            p->lchild = NULL;
            p->rchild = NULL;
            root->rchild = p;
            p->data = c;
            printf("%d", p->data);
            printf("插入成功\n");
            return;
        }
    }
}

void Delete(struct node* q)
{
    struct node* root = q;

    q = root->rchild;
    while (1)
    {
        if (q->lchild == NULL)
        {
            root->data = q->data;
            q = NULL;
            return;
        }
        q = q->lchild;
    }
}

void DeleteBST(struct node* root, int c)
{
    while (root)
    {
        if (root->lchild->data == c)
        {
            if (root->lchild->lchild == NULL && root->lchild->rchild == NULL)
            {
                root->lchild = NULL;
                return;
            }
            if (root->lchild->lchild != NULL&&root->rchild==NULL)
            {
                root->lchild = root->lchild->lchild;
                root->lchild = NULL;
                return;
            }
            Delete(root->lchild);
            printf("删除成功\n");
            return;
        }
        else if (root->rchild->data == c)
        {
            if (root->rchild->lchild == NULL && root->rchild->rchild == NULL)
            {
                root->rchild = NULL;
                return;
            }
            if (root->lchild->lchild != NULL && root->rchild == NULL)
            {
                root->lchild = root->lchild->lchild;
                root->lchild = NULL;
                return;
            }
            Delete(root->rchild);
            printf("删除成功\n");
            return;
        }
        else if (c < root->data&&( root->lchild->data != c|| root->rchild->data != c))
        {
            root = root->lchild;
        }
        else if (c > root->data && (root->lchild->data != c || root->rchild->data != c))
        {
            root = root->rchild;
        }
   
    }
    printf("元素不存在,删除失败\n");
    return;
}



void PreOrder(struct node* root) {
    if (root) {
        printf("%d  ", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
void InOrder(struct node* root) {
    if (root) {
        InOrder(root->lchild);
       if(root)
        printf("%d  ", root->data);
        InOrder(root->rchild);
    }
}
void PostOrder(struct node* root) {
    if (root) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d  ", root->data);
    }
}

int main()
{
    int arr[] = { 30,27,32,25,33,35,40,45 };
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = NULL;
    root->lchild = NULL;
    root->rchild = NULL;
    

    for (int i = 0; i < 8; i++)
    {
        InsertBST(root, arr[i]);
    }
    printf("前序排序  ");
    PreOrder( root);
    printf("\n");
    printf("中序排序  ");
    InOrder( root);
    printf("\n");
    printf("后序排序  ");
    PostOrder( root);
    printf("\n");
}



