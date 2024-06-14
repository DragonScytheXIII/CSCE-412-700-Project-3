// Request.cpp
// Created by DragonScytheXIII on 6/14/2022.
//
#define REQUEST_CPP
#include <string>
/**
 * This structure represents a request object. It contains the Source and Destination
 * IP4 Address as well as the expected time to complete the request.
 */
struct Request
{
    std::string ip_in; /**< Source IP Address */
    std::string ip_out; /**< Destination IP Address */
    int time; /**< Time to process request */
};