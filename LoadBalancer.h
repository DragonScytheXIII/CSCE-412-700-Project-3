// LoadBalancer.h
// Created by leero on 9/29/2022.
//

#ifndef CS412_LOADBALANCER_LOADBALANCER_H
#define CS412_LOADBALANCER_LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class LoadBalancer {
public:
    LoadBalancer();
    int getTime();
    void incrementTime();
    void addRequestToQueue(Request req);
    Request getRequest();
    bool isRequestQueueEmpty();
    int getQueueSize();
private:
    int systemTime;
    std::queue<Request> requestQueue;
};



#endif //CS412_LOADBALANCER_LOADBALANCER_H