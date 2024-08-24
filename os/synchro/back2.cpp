#include <iostream>
#include <thread>
#include <memory>
using namespace std;

class semaphore{
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
        while(s<=0){
            cout<<waiter<<" is waiting"<<endl;
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
        s--;
    }
};


unique_ptr<semaphore> mutex;
unique_ptr<semaphore> rw_mutex;
unique_ptr<int> read_count;
unique_ptr<int> numberOfItems;

void reader(int waitTime,int readTime,int i){
    int numberOfItemsToRead = *numberOfItems;
    while(numberOfItemsToRead>0){
        this_thread::sleep_for(chrono::milliseconds(readTime));
        mutex->wait(waitTime);
        (*read_count)++;
        if((*read_count)==1){
            rw_mutex->wait(waitTime);
        }
        mutex->signal();
        cout<<"Reader "<<i<<" is reading"<<endl;
        numberOfItemsToRead--;
        mutex->wait(waitTime);
        (*read_count)--;
        if(*(read_count)==0){
            rw_mutex->signal();
        }
        mutex->signal();
    }
}

void writer(int waitTime,int writeTime){
    int numberOfItemsToWrite = *numberOfItems;
    while(numberOfItemsToWrite>0){
        this_thread::sleep_for(chrono::milliseconds(writeTime));
        rw_mutex->wait(waitTime);
        cout<<"Writer is writing"<<endl;
        numberOfItemsToWrite--;
        rw_mutex->signal();
    }
}

int main(){
    mutex = make_unique<semaphore>(1);
    rw_mutex = make_unique<semaphore>(1);
    read_count = make_unique<int>(0);

    cout<<"Enter Number of Items: ";
    int n;
    cin>>n;
    numberOfItems = make_unique<int>(n);

    cout<<"Enter Time Taken by a writer to write in milliseconds: ";
    int wTime;
    cin>>wTime;

    cout<<"Enter Time Taken by a reader to read in milliseconds: ";
    int rTime;
    cin>>rTime;

    cout<<"Enter Time to be spent waiting in millisecond: ";
    int waitTime;
    cin>>waitTime;

    cout<<"Enter Number of Readers: ";
    int numOfRead;
    cin>>numOfRead;
    thread writerThread(writer,waitTime,wTime);
    for(int i=0;i<numOfRead;i++){
        thread readerThread(reader,waitTime,rTime,i);
        readerThread.join();
    }
    writerThread.join();
    

}