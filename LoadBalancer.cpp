/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 * @author DragonScytheXIII
 * @date 6/14/2024
 */

#include <stdexcept>
#include "LoadBalancer.h"

/**
 * @brief Default constructor for LoadBalancer class.
 * Initializes the time to zero.
 */
LoadBalancer::LoadBalancer() 
{
    time = 0;
}

/**
 * @brief Gets the current time of the load balancer.
 * @return Current time as an integer.
 */
int LoadBalancer::getTime() 
{
    return time;
}

/**
 * @brief Increments the clock cycle of the load balancer.
 */
void LoadBalancer::incrementTime() 
{
    time += 1;
}

/**
 * @brief Adds a request to the queue.
 * @param request The Request object to be added to the queue.
 */
void LoadBalancer::addRequestToQueue(Request request) 
{
    requestQueue.push(request);
    incrementTime();
}

/**
 * @brief Fetches and removes a request from the queue.
 * @return The Request object that was removed from the queue.
 * @throws std::logic_error if the queue is empty.
 */
Request LoadBalancer::getRequest() 
{
    incrementTime();
    if (!requestQueue.empty()) {
        Request removed = requestQueue.front();
        requestQueue.pop();
        return removed;
    } else {
        throw std::logic_error("Queue Empty, cannot remove");
    }
}

/**
 * @brief Returns the size of the request queue.
 * @return The size of the request queue as an integer.
 */
int LoadBalancer::getQueueSize() 
{
    return requestQueue.size();
}

/**
 * @brief Checks if the request queue is empty.
 * @return True if the request queue is empty, false otherwise.
 */
bool LoadBalancer::requestQueueEmpty() 
{
    return requestQueue.empty();
}
