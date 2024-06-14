#ifndef REQUEST_CPP
#include "request.cpp"
#include <queue>
class LoadBalancer 
{
public:
    bool requestQueueEmpty();
    LoadBalancer();
    int getTime();
    void incrementTime();
    void addRequestToQueue(Request req);
    Request getRequest();
    int getQueueSize();
private:
    int time;
    std::queue<Request> requestQueue;
};
#endif 