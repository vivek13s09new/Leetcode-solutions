class node{
public:
    int data;
    node *next;
};

class MinStack {
    int minValue;
    node *head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        node *temp;
        temp = new node();
        temp->data = val;
        if(head == nullptr){
            temp->next = nullptr;
            minValue = val;
        }else{
            temp->next = head;
            if(val < minValue){
                minValue = val;
            }
        }
        head = temp;
    }
    
    void pop() {
        if(head == nullptr){
            return;
        }
        int currValue = head->data;
        if(currValue == minValue){
            node *curr = head->next;
            int min = INT_MAX;
            while (curr != nullptr){
                if(curr->data < min){
                    min = curr->data;
                }
                curr = curr->next;
            }
            minValue = min;
        }
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    
    int top() {
        if(head){
            return head->data;
        }
        return -1;
    }
    
    int getMin() {
        if(head){
            return minValue;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
