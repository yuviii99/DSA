#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            next = NULL;
        }
};


void printLL(node *head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}


void insert_at_head(node * &head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node * n = new node(data);
    n->next = head;
    head = n;
}


void insert_at_middle(node *head, int data, int position){
    if(position==0){
        insert_at_head(head, data);
        return;
    }
    node * temp = head;
    for(int jump=1;jump<=position-1;jump++){
        temp = temp->next;
    }
    node * n = new node(data);
    n->next = temp->next;
    temp->next = n;
}


node *rec_reverse(node *head){
    // Base Case
    if(head==NULL or head->next==NULL){
        return head;
    }
    // Recursive Case
    node * small_head = rec_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return small_head;
}


void reverse(node *&head){
    node * prev = NULL;
    node * current = head;
    node * temp;
    while(current!=NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}


node * kReverse(node * head, int k){
    if(head == NULL){
        return NULL;
    }

    node * prev = NULL;
    node * current = head;
    node * temp;
    int count = 1;
    while(current!=NULL and count<=k){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }

    if(temp!=NULL){
        head->next = kReverse(temp, k);
    }
    return prev;
}


node *merge(node* a, node* b){
    //Base Case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //Recursive Case
    node *c = NULL;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}


node* getMid(node *head){
    //Complete this function to return data middle node
    node *runner1 = head;
    node *runner2 = head->next;
    while(runner2!=NULL and runner2->next != NULL){
        runner1 = runner1->next;
        runner2 = runner2->next->next;
    }
    return runner1;
}


node *mergeSort(node *head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    // Recursive Case

    node *mid = getMid(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}


int main(){
    node * head = NULL;
    insert_at_head(head, 71);
    insert_at_head(head, 52);
    insert_at_head(head, 44);
    insert_at_head(head, 93);
    insert_at_head(head, 111);
    // insert_at_middle(head, 6, 3);
    // reverse(head);
    printLL(head);
    // head = kReverse(head, 2);
    // printLL(head);
    node * head2 = NULL;
    insert_at_head(head2, 19);
    insert_at_head(head2, 13);
    insert_at_head(head2, 91);
    insert_at_head(head2, 62);
    insert_at_head(head2, 22);
    printLL(head2);
    node *head3 = merge(head, head2);
    printLL(head3);
    node *head4 = mergeSort(head3);
    printLL(head4);
    return 0;
}