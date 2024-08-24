#include <iostream>
#include <thread>
#include <memory>
using namespace std;

struct semaphore{
    int count;
    int sizeOfBuffer;
    int numberOfItemsToProduce;
    int numberOfItemsToConsume;
    int waitingTime;
    semaphore(int s,int np,int wt):sizeOfBuffer(s),numberOfItemsToProduce(np),waitingTime(wt){
        this->count=0;
        this->numberOfItemsToConsume=numberOfItemsToProduce;
    }
    void consumerWait(){
        if(this->numberOfItemsToConsume>0){
            while(this->count<=0){
                cout<<"Consumer Waiting"<<endl;
                this_thread::sleep_for(chrono::milliseconds(100));
            }
            this->count--;
            this->numberOfItemsToConsume--;
        }
    }
    void producerSignal(){
        if(numberOfItemsToProduce>0){
            while(this->count>this->sizeOfBuffer){
                cout<<"Producer Waiting"<<endl;
                this_thread::sleep_for(chrono::milliseconds(100));
            }
            this->count++;
            this->numberOfItemsToProduce--;
        }
    }
    bool allItemsProduced(){
        return this->numberOfItemsToProduce <= 0;
    }
    bool allItemsConsumed(){
        return this->numberOfItemsToConsume <= 0;
    }
    // void output(){
    //     cout<<"sizeOfBuffer is: "<<sizeOfBuffer<<"\nCount is: "<<count<<"\nProduce is: "<<numberOfItemsToProduce<<"\nConsumer is: "<<numberOfItemsToConsume<<endl;
    // }
};


unique_ptr<semaphore> bufferSemaphore;

void producer(int produceTime){
    while(not bufferSemaphore->allItemsProduced()){
        this_thread::sleep_for(chrono::milliseconds(produceTime));
        bufferSemaphore->producerSignal();
        cout<<"Producer produced item"<<endl;
        // bufferSemaphore.output();
    }
}

void consumer(int consumeTime){
    while(not bufferSemaphore->allItemsConsumed()){
        this_thread::sleep_for(chrono::milliseconds(consumeTime));
        bufferSemaphore->consumerWait();
        cout<<"Consumer consumed item"<<endl;
        // bufferSemaphore.output();
    }
}
int main(){
    // bufferSemaphore.output();
    // semaphore bufferSemaphore(5,25);
    cout<<"Enter size of Buffer: ";
    int sizeOfBuffer;
    cin>>sizeOfBuffer;

    cout<<"Enter Number of Items: ";
    int numberOfItems;
    cin>>numberOfItems;

    cout<<"Enter Time Taken by Producer to produce item in milliseconds: ";
    int produceTime;
    cin>>produceTime;

    cout<<"Enter Time Taken by Consumer to produce item in milliseconds: ";
    int consumeTime;
    cin>>consumeTime;

    cout<<"Enter Time to be spent waiting in milliseconds: ";
    int waitTime;
    cin>>waitTime;
    bufferSemaphore = make_unique<semaphore>(sizeOfBuffer,numberOfItems,waitTime);

    thread producerThread(producer,produceTime);
    thread consumerThread(consumer,consumeTime);
    producerThread.join();
    consumerThread.join();
}