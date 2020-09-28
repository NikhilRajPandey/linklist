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

        // These Function are for throwing errors
        bool isEmpty(){
            if(this->used_size == 0){
                std::cout<<"Size is 0"<<std::endl;
                return true;
            }
            return false;
        }
        bool isElemPresent(int &index){
            if(index >= this->used_size){
                std::cout<<"Error: index is greater than size"<<std::endl;
                return false;
            }
            return true;
        }
    public:
        Node *FirstElement = new Node;
        Node *LastElement = FirstElement;
        /* By Default i am keeping this but when new element will come i will update this value
        I am Keeping LastElement For reduce time complexity for push_back() */

        void push_back(int data);
        void push_front(int data);
        void insert_(int index,int data);
        void insert_after_node(Node *param_node,int data);
        void pop_back();
        void pop_front();
        void pop(int index);
        int search(int element,bool fromEnd=false); // Give You the index of founded elem
        void delete_them(int start,int end); // <= Here End will be not deleted
        void clear(); // <= This will delete all elements it
        void print_elems(int end); // ^^ It will print 0-end elements
        void print_all();
        void reverse();
        Node* get(int index);
        int size_();
};

// All Gets Functions
Node* LinkList::get(int index){ // It will give you the pointer of that index
    if(!this->isElemPresent(index)){
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

int LinkList::search(int element,bool fromEnd){
    if(this->isEmpty()){return -1;}

    int index = 0;
    Node *ptr_of_node = this->FirstElement;

    if(!fromEnd){ // If I have to give First index
        while (ptr_of_node != NULL){
            if(ptr_of_node->data == element){return index;}
            ptr_of_node = ptr_of_node->nextElement;

            index++;
        }
        return -1; // Means Not Found
    }
    else{ // If I have to give last index
        int founded_index = -1;
        while (ptr_of_node != NULL){
            if(ptr_of_node->data == element){founded_index = index;}
            ptr_of_node = ptr_of_node->nextElement;
            
            index++;
        }
        return founded_index;
    }
}
// Printing Functions
void LinkList::print_elems(int end){
    if(!this->isElemPresent(end)){return;}
    
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
    if(this->used_size != 0){
        while (ptr_of_node->nextElement != NULL){
            std::cout<<ptr_of_node->data<<",";
            ptr_of_node = ptr_of_node->nextElement;
        }
        std::cout<<ptr_of_node->data;
    }
    std::cout<<" }"<<std::endl;
}

// All Insertion Function
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
    else if(index == this->used_size){ // Means Appending
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
// AAll Deletion Function
void LinkList::pop_back(){
    if(this->isEmpty()){
        return;
    }
    else if(this->used_size == 1){ // If Size is only 1
        this->pop_front();
    }
    else{
        this->pop(this->used_size-1);
    }
}
void LinkList::pop_front(){
    if(this->isEmpty()){
        return;
    }
    else{
        if(this->used_size == 1){
            this->FirstElement->data = 0;
            // I have just reset the data because this Class Need One Node Active
            this->used_size--;
            return;
        }
        Node *second_node = this->FirstElement->nextElement;
        delete this->FirstElement;
        this->FirstElement = second_node;
        this->used_size--;
    }
}
void LinkList::pop(int index){
    // These are warning Error They will come when size is 0 or index >= size
    if(this->isEmpty()){return;}
    if(!this->isElemPresent(index)){return;}

    if(index == 0){this->pop_front();return;}

    //  Checking Is last index Because i have to another process to delete last element
    bool isLast = (index == this->used_size-1);

    // Acessing To the Previous element of the element which i have to delete
    Node * ptr_of_node = this->FirstElement;
    while (index-1 > 0){
        ptr_of_node = ptr_of_node->nextElement;
        index--;
    }
    if(isLast){
        delete ptr_of_node->nextElement;
        ptr_of_node->nextElement = NULL;
    }
    else{
        Node *cache = ptr_of_node->nextElement->nextElement;
        delete ptr_of_node->nextElement;
        ptr_of_node->nextElement = cache;
    }
    this->used_size--;
}

void LinkList::delete_them(int start,int end){
    if(this->isEmpty()){return;}

    Node *ptr_of_node = this->FirstElement;
    Node *cache;
    Node *start_node;
    int index = 0;
    /* Sorry For My Bad English */
    bool start_deleting = false; // This will be activate when start will come in loop

    while (index < end){
        start_deleting = (index >= start);
        cache = ptr_of_node;
        ptr_of_node = ptr_of_node->nextElement;

        if(start_deleting){
            delete cache;
            this->used_size--;
        }
        else{
            start_node = cache;
        }
        index++;
    }
    // If `Start` is 0 then i will select start as list[end-1:]
    if(start == 0){this->FirstElement = ptr_of_node;return;}

    // other wise This will contain new this->FirstElement (list[{end-start}:])
    start_node->nextElement = ptr_of_node;
}

void LinkList::clear(){
    this->delete_them(0,this->used_size);
}

void LinkList::reverse(){
    Node *prev_node = NULL;
    Node *curr_node = this->FirstElement;
    Node *next_node;

    while (true){
        next_node = curr_node->nextElement;
        if(next_node == NULL){break;}
        curr_node->nextElement = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    curr_node->nextElement = prev_node;
    this->FirstElement = curr_node;
}

int main(){
    LinkList testing_;
    testing_.push_front(23);
    // testing_.print_all();
    // testing_.pop_front();
    testing_.push_back(456);
    testing_.push_back(78);
    testing_.push_back(12);
    testing_.push_back(16);

    testing_.insert_(3,9);
    // std::cout<<"Debug: "<<testing_.get(3)->data<<std::endl;
    testing_.insert_after_node(testing_.get(0),92);

    testing_.print_all();
    // testing_.pop(testing_.size_()-2);
    // testing_.delete_them(0,3);
    testing_.delete_them(1,3);
    // testing_.clear();
    // testing_.push_back(16);
    testing_.print_all();
    // testing_.print_elems(2);
    // std::cout<<testing_.search(23)<<std::endl;
    // std::cout<<testing_.search(78)<<std::endl;
    // std::cout<<testing_.search(16,true)<<std::endl;

    return 0;
}
