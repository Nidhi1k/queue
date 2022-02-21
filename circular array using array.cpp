//implement a circular queue using array 
#include <iostream>
#include<queue>
using namespace std;
class Queue{
    //basic variables and data we need
    int * arr;
    int qfront;
    int rear;
    int size;
    int popped_element;
    public:
    //constuctor
    Queue(){
        size=5;
        //dynamic memory allocation
        arr=new int[size];//datatype variable = new datatype [size];
        //initialising 
        qfront = -1;
        rear=-1;
        //initially lets assume both front and rear pointers are at the same position
        //qfront=rear=-1 
    }
    /**********************************************************************************/
    //functions
    //function to check our queue(we are implementing queue using an array) is empty or not
    bool isEmpty(){
        
        if(qfront==-1)
        {   cout<<"circular queue is empty"<<endl;
            return true;
        }
        else
        {
            cout<<"circular queue is not empty"<<endl;
            return false;
        }
        // if(qfront==rear)//both points to same allocation
        // {
        //     //queue is empty
        //     cout<<"queue is empty"<<endl;
        //     return true;
        // }
        // else
        // {
        //     cout<<"queue is not empty"<<endl;
        //     return false;
        // }
    }
    //function to enqueue /push element in our queue 
    
    bool enqueue(int value)
    {   if((qfront==0 && rear ==size-1)||(rear==(qfront-1)%(size-1)))
        {
           cout<<"queue is full"<<endl;
           return false;
        }
        else if (qfront==-1)
        {
            qfront=rear=0;
            arr[rear]=value;
        }
        else if(rear==size-1 && qfront!=0)
        {
             rear=0;
             arr[rear]=value;
            
        }
        else{
            rear++;
            arr[rear]=value;
        }
        return true;
        // //check if there is any space in queue or not that is queue is full or not
        // if(rear==size-1)
        // {
        //     //queue is full
        //     cout<<"queue is full "<<endl;
        // }
        // else
        // {
        //     //if queue is having space left for entering more data
        //     arr[rear]=data;
        //     rear++;
        // }
        
    }
    
    //function to dequeue / pop
    
    int dequeue()
    {   
            if(qfront==-1)
            {
                cout<<"no element can be popped array empty"<<endl;
                return -1;
            }
            popped_element=arr[qfront];
            arr[qfront]=-1;
            //how 
            if(qfront==rear)
            {
                qfront=rear=-1;
            }
            //pop 
            //case 1: to maintain cyclic nature
            else if(qfront==size-1)
            {
                qfront=0;
            }
            else
            {
                qfront++;
            }
            return popped_element;
        
        // //check is there element/s in queue to pop
        // if(qfront==rear)
        // {
        //     //no element in our queue
        //     cout<<"no element in our queue to pop "<<endl;
        //     return -1;
        // }
        // else
        // {    popped_element = arr[qfront];
        //     arr[qfront]=-1;
        //     qfront ++; 
        //     // if our queue has became empty ,it means we have all elements present in the queue 
        //     if(qfront==rear)
        //     {
        //         qfront = rear =0 ;
        //     }
            
        // }
        // cout<<"the popped element is"<<endl ;
        // return popped_element;
    }
    // return front of the queue
    // int front(){
    //     //check array is empty or not 
    //     if(qfront==rear)
    //     {
    //         //queue empty
    //         cout<<"queue empty"<<endl;
    //         return -1;
    //     }
    //     else
    //     {
    //         return arr[qfront];
    //     }
    // }
    

};
    
  
int main() {
    
    //declaring object
    Queue q;
    q.isEmpty();
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(9);
    //1 3 6 9
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
   //6 9
   //cout<<"element at the front is"<<endl;
   //cout<<q.front();
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(3);
    
    for(int i=1;i<=5;i++){
    cout<<q.dequeue()<<" ";
    }
    
	// your code goes here
	return 0;
}
