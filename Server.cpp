/**
 * @file Server.cpp
 * @brief Implementation file for the Server class.
 * @author DragonScytheXIII
 * @date 6/14/2024
 */

#include "Server.h"

/**
 * @brief Default constructor for the Server class.
 * Initializes the server name to an empty character.
 */
Server::Server() 
{
    requestStartTime = 0;
    serverName = ' ';
}

/**
 * @brief Overloaded constructor for the Server class.
 * Initializes the server name to the input character.
 * @param c Character to set as the server name.
 */
Server::Server(char c) 
{
    requestStartTime = 0;
    serverName = c;
}

/**
 * @brief Adds a request for the server to process.
 * @param req The Request object to be processed.
 * @param currTime The current time when the request was added.
 */
void Server::addRequest(Request req, int currTime) 
{
    r = req;
    requestStartTime = currTime;
}

/**
 * @brief Gets the name of the server.
 * @return The name of the server as a character.
 */
char Server::getName() 
{
    return serverName;
}

/**
 * @brief Checks if the current request has finished processing.
 * @param current_time The current time.
 * @return True if the request has finished, false otherwise.
 */
bool Server::isRequestDone(int current_time) 
{
    return (requestStartTime + r.time <= current_time);
}

/**
 * @brief Gets the current request being processed by the server.
 * @return The current Request object.
 */
Request Server::getRequest() 
{
    return r;
}
