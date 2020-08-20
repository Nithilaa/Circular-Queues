#include<iostream>
using namespace std;

class Queue {
    public:
        int rear, head;
        int queue_size;
        int *circular_queue;

        Queue(int size_1) {
            head = rear = -1;
            queue_size = size_1;
            circular_queue = new int[size_1];
        }
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value)
{
    if ((head == 0 && rear == queue_size-1) || (rear == (head-1)%(queue_size-1)))  {
        cout<<"\nQueue is FULL";
        return;
    }
    else if (head == -1) {
         head = rear = 0;
        circular_queue[rear] = value;
    }
   else if (rear == queue_size-1 && head != 0) {
        rear = 0;
        circular_queue[rear] = value;
    }
    else {
        rear++;
        circular_queue[rear] = value;
    }
}

int Queue::deQueue()
{
    if (head == -1)  {
        cout<<"\nQueue is EMPTY";
        return -1;
    }

    int data = circular_queue[head];
    circular_queue[head] = -1;
    if (head == rear)  {
        head = -1;
        rear = -1;
    }
    else if (head == queue_size-1)
        head = 0;
    else
        head++;

    return data;
}

void Queue::displayQueue()
{
    if (head == -1) {
        cout<<"\nQueue is EMPTY"<<endl;
        return;
    }
    cout<<"\nCircular Queue elements are : ";
    if (rear >= head) {
        for (int i = head; i <= rear; i++)
            cout<<circular_queue[i]<<" ";
    }
    else  {
        for (int i = head; i < queue_size; i++)
            cout<<circular_queue[i]<<" ";

        for (int i = 0; i <= rear; i++)
            cout<<circular_queue[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    Queue q(5);

    int choice = 1;
    int option, val;
    while(choice==1)
    {
        cout<<"Enter your choice : \n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n\nYour choice : ";
        cin>>option;

        switch(option) {
         case 1:
            cout<<"Enter value for inserting in circular queue : "<<endl;
            cin>>val;
            q.enQueue(val);
            break;

         case 2:
            q.deQueue();
            break;

         case 3:
            cout<<"The circular queue is : ";
            q.displayQueue();
            break;

         case 4:
            cout<<"Exit\n";
            choice = 0;
            break;

         default: cout<<"Error!\n";
      }

    }

    return 0;
}
