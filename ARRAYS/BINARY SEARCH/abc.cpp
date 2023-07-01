#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

class doubly_linked_list{
public:
    struct node*head;
    struct node*tail;
    bool before=true;
    struct node*circle;
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
        circle = NULL;
    }
    void insert_val(int n)
    {
        if(before==true)
            insert_begin(n);
        else
            append(n);
        before = !before;

    }
    void insert_begin(int n)
    {
        struct node*temp = new node;
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void append(int n)
    {
        struct node*temp = new node;
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void print()
    {
        struct node*temp;
        temp = head;
        while(temp!=circle)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        if(circle != NULL)
        {
            cout<<circle->data<<" ";
            temp = tail;
            while(temp != circle)
            {
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<circle->data<<" ";
        }
        cout<<endl;
    }
    void shuffle(int i1, int i2)
    {
        struct node* pos1,* pos2;
        //get nodes
        int i=1;
        struct node* temp = head;
        bool is_circle = false;
        while(temp != NULL)
        {
            if(i == i1)
                pos1 = temp;
            else if(i == i2)
                pos2 = temp;
            else if(temp == circle)
                is_circle = true;
            if(temp == tail)
                break;
            temp = temp->next;
            i++;
        }
        if(pos1 == head and pos2 == tail)
        {
            tail->next = head;
        }
        if(pos1 == head)
        {
            head = pos2->next;
            head->prev = NULL;
            tail->next = pos1;
            pos1->prev = tail;
            pos2->next = pos1;
            tail = pos2;
        }
        else if(pos2 == tail)
        {
            tail->next = pos1;
        }
        else
        {
            (pos1->prev)->next = pos2->next;
            (pos2->next)->prev = pos1->prev;
            tail->next = pos1;
            pos1->prev = tail;
            pos2->next = pos1;
            tail = pos2;
        }
        circle = pos1;
    }
};
int main()
{
    char op;
    int temp1, temp2;
    int n;
    cin>>n;
    doubly_linked_list* lst = new doubly_linked_list();
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op == 'I')
        {
            cin>>temp1;
            lst->insert_val(temp1);
        }
        else if(op == 'D')
        {
            lst->print();
        }
        else if(op == 'S')
        {
            cin>>temp1>>temp2;
            lst->shuffle(temp1, temp2);
        }
        else if(op == 'F')
        {
            cout<<lst->head->data<<endl;
        }
    }
}