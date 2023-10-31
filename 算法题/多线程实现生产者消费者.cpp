#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int max_queue_size = 5;
std::queue<int> q1;
std::mutex tex;
std::condition_variable que_full, que_empty;

void producer()
{
    int i = 10;
    while (i--)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::unique_lock<std::mutex> lock(tex);
            if (q1.size() >= max_queue_size)
            {
                que_full.wait(lock);
            }
            q1.push(i);
        }
        que_empty.notify_one();
    }
}
void consumer()
{

}
#if 0
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
#endif


/*
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int maxBufferSize = 5;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable bufferNotEmpty, bufferNotFull;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // 模拟生产时间
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (buffer.size() >= maxBufferSize) {
                std::cout << "Buffer is full. Producer waiting." << std::endl;
                bufferNotFull.wait(lock);
            }
            buffer.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
        bufferNotEmpty.notify_one();
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));  // 模拟消费时间
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (buffer.empty()) {
                std::cout << "Buffer is empty. Consumer waiting." << std::endl;
                bufferNotEmpty.wait(lock);
            }
            int data = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << data << std::endl;
        }
        bufferNotFull.notify_one();
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
*/