/**
 * @file LoadBalancer.h
 * @brief Header file for the LoadBalancer class.
 */

#ifndef REQUEST_CPP
#define REQUEST_CPP

#include "request.cpp"
#include <queue>

/**
 * @class LoadBalancer
 * @brief Manages a queue of requests and distributes them to servers.
 */
class LoadBalancer 
{
public:
    /**
     * @brief Constructor for LoadBalancer class.
     * Initializes the time to zero.
     */
    LoadBalancer();

    /**
     * @brief Checks if the request queue is empty.
     * @return True if the request queue is empty, false otherwise.
     */
    bool requestQueueEmpty();

    /**
     * @brief Gets the current time of the load balancer.
     * @return Current time as an integer.
     */
    int getTime();

    /**
     * @brief Increments the clock cycle of the load balancer.
     */
    void incrementTime();

    /**
     * @brief Adds a request to the queue.
     * @param req The Request object to be added to the queue.
     */
    void addRequestToQueue(Request req);

    /**
     * @brief Fetches and removes a request from the queue.
     * @return The Request object that was removed from the queue.
     * @throws std::logic_error if the queue is empty.
     */
    Request getRequest();

    /**
     * @brief Returns the size of the request queue.
     * @return The size of the request queue as an integer.
     */
    int getQueueSize();

private:
    int time; ///< Current time of the load balancer.
    std::queue<Request> requestQueue; ///< Queue of requests.
};

#endif // REQUEST_CPP
