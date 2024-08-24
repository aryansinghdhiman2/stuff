#include <iostream>
#include <thread>

using namespace std;

struct semaphore{
    int count;
    int size;
    int numberOfItemsToProduce;
    int numberOfItemsToConsume;
    semaphore(int s,int np):size(s),numberOfItemsToProduce(np){
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
            while(this->count>this->size){
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
    void output(){
        cout<<"Size is: "<<size<<"\nCount is: "<<count<<"\nProduce is: "<<numberOfItemsToProduce<<"\nConsumer is: "<<numberOfItemsToConsume<<endl;
    }
};

semaphore bufferSemaphore(3,100);

void producer(){
    while(not bufferSemaphore.allItemsProduced()){
        bufferSemaphore.producerSignal();
        // bufferSemaphore.output();
        cout<<"Producer produced item"<<endl;
    }
}

void consumer(){
    while(not bufferSemaphore.allItemsConsumed()){
        bufferSemaphore.consumerWait();
        // bufferSemaphore.output();
        cout<<"Consumer consumed item"<<endl;
    }
}
int main(){
    thread producerThread(producer);
    thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();
}