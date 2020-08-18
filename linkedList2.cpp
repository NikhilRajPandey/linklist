#include <iostream>

class Node
{
    public:
        int data;
        Node *nextElement = NULL;
};
class LinkList
{
    private:
        int used_size = 0;
        Node *FirstElement = new Node;
        Node *LastElement = FirstElement;
        // By Default i am keeping this but when new element will come i will update this value
    public:
        void push_back(int data);
        void push_front(int data);
        void insert_(int index,int data);
        void insert_after_node(Node *param_node);
        void pop_back();
        void pop_front();
        void pop();
        void search(int index);
        void empty_it(); // Delete Function
        Node* get(int index);
        int size_();
};

Node* LinkList::get(int index){ // It will give you the pointer of that index
    if(index >= this->used_size){
        std::cout<<"Error: index is greater than size"<<std::endl;
        return 0;
    }
    if(index == this->used_size-1){ // If Requested index is last element
        return this->LastElement;
    }

    Node *ptr_of_node = this->FirstElement;
    while (index != 0){ // Iterating through each pointers
        ptr_of_node = ptr_of_node->nextElement;
        index--;
    };
    return ptr_of_node;
}
void LinkList::push_back(int data){
    if(this->used_size == 0){ // Means This is the first data in this LinkList
        this->FirstElement->data = data;
        this->used_size++;
        return;
    }
    this->LastElement->nextElement = new Node;
    this->LastElement->nextElement->data = data;
    this->LastElement = this->LastElement->nextElement;
    this->used_size++;
}
void LinkList::push_front(int data){
    if(this->used_size == 0){ // Means This is the first data in this LinkList
        this->FirstElement->data = data;
        this->used_size++;
        return;
    }
    Node *newNode = new Node; // First Creating a node then pointing it to head
    newNode->data = data;
    newNode->nextElement = this->FirstElement;
    this->FirstElement = newNode;
    this->used_size++;
}
void LinkList::insert_(int index,int data){
    if(index > this->used_size){
        std::cout<<"Error: index is greater than size"<<std::endl;
        return;
    }
    if(index == 0){
        this->push_front(data);
    }
    else if(index == this->used_size){
        this->push_back(data);
    }
    else{
        Node *ptr_of_node = this->FirstElement;
        Node *newNode = new Node;
        index--;
        /* I am starting the index from 1 because if index will be 0 then first `if` will handle it */
        while (index != 0){
            ptr_of_node = ptr_of_node->nextElement;
            index--;
        }
        newNode->data = data;
        newNode->nextElement = ptr_of_node->nextElement;
        ptr_of_node->nextElement = newNode;
        this->used_size++; 
    }
}
int LinkList::size_(){
    return this->used_size;
}

int main(){
    LinkList testing_;
    testing_.push_front(23);
    testing_.push_back(456);
    testing_.push_back(78);
    testing_.push_back(12);
    testing_.push_back(16);

    std::cout<<"Size is "<<testing_.size_()<<std::endl;
    testing_.insert_(3,9);
    for(int i=0;i<testing_.size_();i++){
    std::cout<<testing_.get(i)->data<<std::endl;
    }

    return 0;
}