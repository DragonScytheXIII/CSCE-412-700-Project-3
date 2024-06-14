// Server.h
// Created by leero on 9/28/2022.
//

#ifndef CS412_LOADBALANCER_SERVER_H
#define CS412_LOADBALANCER_SERVER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class Server {
private:
    Request r;
    int requestStartTime;
    char serverName;
public:
    Server();
    Server(char c);
    void addRequest(Request req, int current_time);
    bool isRequestDone(int current_time);
    Request getRequest();
    char getName();
};


#endif //CS412_LOADBALANCER_SERVER_H