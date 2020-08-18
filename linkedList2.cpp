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
        void insert_after_node(Node *param_node,int data);
        void pop_back();
        void pop_front();
        void pop();
        void search(int index);
        void empty_it(); // Delete Function
        void print_elems(int end); // ^^ It will print 0-end elements
        void print_all();
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
int LinkList::size_(){
    return this->used_size;
}
void LinkList::print_elems(int end){
    if(end >= this->used_size){
        std::cout<<"Error: index is greater than size"<<std::endl;
        return;
    }
    
    end--;
    Node *ptr_of_node = this->FirstElement;

    std::cout<<"{ ";
    while (end > 0){
        std::cout<<ptr_of_node->data<<",";
        ptr_of_node = ptr_of_node->nextElement;
        end--;
    }
    std::cout<<ptr_of_node->data<<" }"<<std::endl;
}
void LinkList::print_all(){
    Node *ptr_of_node = this->FirstElement;
    
    std::cout<<"{ ";
    while (ptr_of_node->nextElement != NULL){
        std::cout<<ptr_of_node->data<<",";
        ptr_of_node = ptr_of_node->nextElement;
    }
    std::cout<<ptr_of_node->data<<" }"<<std::endl;
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
void LinkList::insert_after_node(Node *param_node,int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->nextElement = param_node->nextElement;
    param_node->nextElement = new_node;
    this->used_size++;
}

int main(){
    LinkList testing_;
    testing_.push_front(23);
    testing_.push_back(456);
    testing_.push_back(78);
    testing_.push_back(12);
    testing_.push_back(16);

    testing_.insert_(3,9);
    std::cout<<"Debug: "<<testing_.get(3)->data<<std::endl;
    testing_.insert_after_node(testing_.get(0),92);

    testing_.print_all();
    testing_.print_elems(2);

    return 0;
}