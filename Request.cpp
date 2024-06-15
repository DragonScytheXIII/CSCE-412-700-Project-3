/**
 * @file Request.cpp
 * @brief Implementation file for the Request structure.
 * @author DragonScytheXIII
 * @date 6/14/2024
 */

#define REQUEST_CPP

#include <string>

/**
 * @struct Request
 * @brief Represents a request object containing source and destination IP addresses and the expected time to complete the request.
 */
struct Request
{
    std::string ip_in;  /**< Source IP Address */
    std::string ip_out; /**< Destination IP Address */
    int time;           /**< Time to process request */
};
