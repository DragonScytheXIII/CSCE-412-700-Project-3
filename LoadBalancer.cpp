// LoadBalancer.cpp
// Created by leero on 9/29/2022.
//

#include <stdexcept>

#include "LoadBalancer.h"

/**
 * Default constructor, initialized name to blank
 */
LoadBalancer::LoadBalancer() {
    systemTime = 0;
}

/**
 * Gets the current time of the load balancer
 *
 * @return int, time
 */
int LoadBalancer::getTime() {
    return systemTime;
}

/**
 * Increments the time (clock cycle) of the load balancer
 */
void LoadBalancer::incrementTime() {
    systemTime += 1;
}

/**
 * Adds a request to the queue
 *
 * @param Request type to be added to queue
 */
void LoadBalancer::addRequestToQueue(Request req) {
    requestQueue.push(req);
    incrementTime();
}

/**
 * Fetches the request from the queue, removes request
 *
 * @return Request that was removed from queue.
 */
Request LoadBalancer::getRequest() {
    incrementTime();
    if (!requestQueue.empty()) {
        Request removed = requestQueue.front();
        requestQueue.pop();
        return removed;
    }
    else {
        throw std::logic_error("Trying to remove from empty queue");
    }
}

/**
 * Returns whether requestQueue is empty
 *
 * @return bool, true if empty
 */
bool LoadBalancer::isRequestQueueEmpty() {
    return requestQueue.empty();
}

/**
 * Returns the size of the queue
 *
 * @return int, requestQueue size
 */
int LoadBalancer::getQueueSize() {
    return requestQueue.size();
}