// Server.cpp
// Created by DragonScytheXIII on 6/14/2022.
//
#include "Server.h"
/**
 * Default constructor, initialized name to empty char
 */
Server::Server() 
{
    requestStartTime = 0;
    serverName = ' ';
};
/**
 * Overloaded constructor, initialized name to input char
 */
Server::Server(char c) 
{
    requestStartTime = 0;
    serverName = c;
};
/**
 * Adds a request for the server to process
 * @param req, Request type to be added
 * @param currTime, Current time which request was added
 */
void Server::addRequest(Request req, int currTime) 
{
    r = req;
    requestStartTime = currTime;
};
/**
 * Gets the Name of the server
 * @return char, name of server
 */
char Server::getName() 
{
    return serverName;
}
/**
 * Returns whether a request has finished
 * @param current_time, Current time
 * @return bool, true if request finished
 */
bool Server::isRequestDone(int current_time) 
{
    return (requestStartTime + r.time <= current_time);
};
/**
 * Gets the request from the server
 * @return Request, current request being processed by server
 */
Request Server::getRequest() 
{
    return r;
}
