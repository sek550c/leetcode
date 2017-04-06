#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
class LinkList {
private:
    Node* head;
public:
    LinkList() {
        head = NULL;
    }
    void insert(Node *node, int index) {
        if (head == NULL) {
            head = node;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    void delete_node(int index){
        if (head == NULL){
            return;
        }
        Node *current_node = head;
        int count = 0;
        if (index == 0){
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index - 1){
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1 && current_node->next != NULL){
            Node *delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
        }
    }
    void show(int index){
        if (head == NULL){
            return;
        }
        Node *current_node = head;
        int count = 0;
        while (count != index){
            current_node = current_node->next;
            count++;
        }
        cout<<current_node->data<<endl;
    }
    int length(){
        if (head == NULL){
            return 0;
        }
        Node *current_node = head; 
        int count = 1; // initialize to 1 because 1 node exist already
        while (current_node->next != NULL){
            current_node = current_node->next;
            count++;
        }
        return count;
    }

};
int main() {
    LinkList linklist;
    int N,M,num,original_length = 0,current_length = 0;
    cin>>N>>M;
    if (N <= M || ((N - M)+1)%2 != 0){
        cout<<"not valide number entered"<<endl;
        return 0;
    }
    // create
    for (int i = 1; i <= N; i++) {
        Node *node = new Node(i);
        linklist.insert(node, i - 1);
    }
    original_length = linklist.length();
    current_length = linklist.length();
    //linklist.output();
    // remove
    for (int i = 0; i < M; i++){
        cin>>num;
        if (num > current_length){
            cout<<"the num entered is out of range"<<endl;
            return 0;
        }
        linklist.delete_node(num - 1);
        current_length = linklist.length();
    }
    //linklist.output();
    current_length = linklist.length();
    //cout<<"length: "<<max<<endl;
    linklist.show((current_length-1)/2);
    
    return 0;
}
