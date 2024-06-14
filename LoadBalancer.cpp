// LoadBalancer.cpp
// Created by DragonScytheXIII on 6/14/2022.
//
#include <stdexcept>
#include "LoadBalancer.h"
/**
 * Default constructor, initialized name to blank
 */
LoadBalancer::LoadBalancer() 
{
    time = 0;
}
/**
 * Gets the current time of the load balancer
 *
 * @return int, time
 */
int LoadBalancer::getTime() 
{
    return time;
}
/**
 * Increments the clock cycle of the load balancer
 */
void LoadBalancer::incrementTime() 
{
    time += 1;
}
/**
 * Adds a request to the queue
 *
 * @param Request type to be added to queue
 */
void LoadBalancer::addRequestToQueue(Request request) 
{
    requestQueue.push(request);
    incrementTime();
}
/**
 * Fetches the request from the queue, removes request
 *
 * @return Request that was removed from queue.
 */
Request LoadBalancer::getRequest() 
{
    incrementTime();
    if (!requestQueue.empty()) {
        Request removed = requestQueue.front();
        requestQueue.pop();
        return removed;
    }
    else {
        throw std::logic_error("Queue Empty, cannot remove");
    }
}
/**
 * Returns the size of the queue
 *
 * @return int, requestQueue size
 */
int LoadBalancer::getQueueSize() 
{
    return requestQueue.size();
}
/**
 * Returns whether requestQueue is empty
 *
 * @return bool, true if empty
 */
bool LoadBalancer::requestQueueEmpty() 
{
    return requestQueue.empty();
}