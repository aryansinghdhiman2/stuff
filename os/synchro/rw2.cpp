#include <iostream>
#include <vector>

std::vector<int> sharedData;   // Shared resource
int mutex = 1;                 // Binary semaphore for mutual exclusion
int rwMutex = 1;               // Binary semaphore for readers-writers exclusion

void wait(int& semaphore)
{
    while (semaphore <= 0) {
        // Busy wait until the semaphore is available
    }
    --semaphore;
}

void signal(int& semaphore)
{
    ++semaphore;
}

void reader(int readersCount)
{
    wait(mutex);
    ++readersCount;

    if (readersCount == 1) {
        wait(rwMutex);
    }

    signal(mutex);

    // Read the shared data
    std::cout << "Reader " << readersCount << " is reading." << std::endl;

    wait(mutex);
    --readersCount;

    if (readersCount == 0) {
        signal(rwMutex);
    }

    signal(mutex);
}

void writer(int writersCount)
{
    wait(rwMutex);
    ++writersCount;

    // Write to the shared data
    std::cout << "Writer " << writersCount << " is writing." << std::endl;

    --writersCount;
    signal(rwMutex);
}

int main()
{
    std::cout << "Enter the number of readers: ";
    int numReaders;
    std::cin >> numReaders;
    std::cout << "Enter the number of writers: ";
    int numWriters;
    std::cin >> numWriters;
    for (int i = 0; i < numReaders; ++i) {
        reader(i);
    }
    for (int i = 0; i < numWriters; ++i) {
        writer(i);
    }

    return 0;
}