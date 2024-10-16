//
// Created by willy on 27/09/2024.
//

#ifndef QUEUE_H
#define QUEUE_H



class Queue {
private:
    int front;
    int rear; // tail queue
    int size;
    int *queue;
public:
  Queue(int capacity);
  bool isFull();
  bool isEmpty();
  void enqueue(int value);
  void dequeue();
  ~Queue();
};



#endif //QUEUE_H
