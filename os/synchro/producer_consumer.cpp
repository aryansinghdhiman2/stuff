#include <iostream>
#include <thread>
#include <memory>
using namespace std;

struct semaphore{
    int s;
    public:
    semaphore(int a):s(a){}
    void signal(){
        s++;
    }
    void wait(int waitTime){
        while(s<=0){
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
        s--;
    }
    void wait(int waitTime,string waiter){
        string line = waiter+" is waiting\n";
        while(s<=0){
            cout<<line;
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
        s--;
    }
};

unique_ptr<semaphore> mutex;
unique_ptr<semaphore> emptyMutex;
unique_ptr<semaphore> fullMutex;
unique_ptr<int> numberOfItems;

void producer(int waitTime,int produceTime){
    int numberOfItemToProduce = *numberOfItems;
    while(numberOfItemToProduce>0){
        this_thread::sleep_for(chrono::milliseconds(produceTime));
        emptyMutex->wait(waitTime,"Producer");
        mutex->wait(waitTime);
        cout<<"Producer produced item"<<endl;
        numberOfItemToProduce--;
        mutex->signal();
        fullMutex->signal();
    }
}

void consumer(int waitTime,int consumeTime){
    int numberOfItemsToConsume = *numberOfItems;
    while(numberOfItemsToConsume>0){
        this_thread::sleep_for(chrono::milliseconds(consumeTime));
        fullMutex->wait(waitTime,"Consumer");
        mutex->wait(waitTime);
        cout<<"Consumer consumed item"<<endl;
        numberOfItemsToConsume--;
        mutex->signal();
        emptyMutex->signal();
    }
}

int main(){
    cout<<"Enter Size of Buffer: ";
    int bufferSize;
    cin>>bufferSize;

    cout<<"Enter Number of Items: ";
    int n;
    cin>>n;

    cout<<"Enter Time Taken by producer to produce in millisecond: ";
    int proTime;
    cin>>proTime;

    cout<<"Enter Time Taken by consumer to consume in millisecond: ";
    int conTime;
    cin>>conTime;

    int waitTime=100;

    numberOfItems=make_unique<int>(n);
    mutex=make_unique<semaphore>(1);
    emptyMutex=make_unique<semaphore>(bufferSize);
    fullMutex=make_unique<semaphore>(0);

    thread producerThread(producer,waitTime,proTime);
    thread consumerThread(consumer,waitTime,conTime);
    producerThread.join();
    consumerThread.join();
}