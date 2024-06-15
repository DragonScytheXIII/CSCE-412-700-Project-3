/**
 * @file Server.h
 * @brief Header file for the Server class.
 * @date 6/14/2024
 */

#ifndef CS412_LOADBALANCER_SERVER_H
#define CS412_LOADBALANCER_SERVER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

/**
 * @class Server
 * @brief Represents a server that processes requests.
 */
class Server {
private:
    Request r;            /**< Current request being processed */
    int requestStartTime; /**< Time at which the current request started processing */
    char serverName;      /**< Name of the server */

public:
    /**
     * @brief Default constructor for the Server class.
     * Initializes the server name to an empty character.
     */
    Server();

    /**
     * @brief Overloaded constructor for the Server class.
     * Initializes the server name to the input character.
     * @param c Character to set as the server name.
     */
    Server(char c);

    /**
     * @brief Adds a request for the server to process.
     * @param req The Request object to be processed.
     * @param current_time The current time when the request was added.
     */
    void addRequest(Request req, int current_time);

    /**
     * @brief Checks if the current request has finished processing.
     * @param current_time The current time.
     * @return True if the request has finished, false otherwise.
     */
    bool isRequestDone(int current_time);

    /**
     * @brief Gets the current request being processed by the server.
     * @return The current Request object.
     */
    Request getRequest();

    /**
     * @brief Gets the name of the server.
     * @return The name of the server as a character.
     */
    char getName();
};

#endif // CS412_LOADBALANCER_SERVER_H
