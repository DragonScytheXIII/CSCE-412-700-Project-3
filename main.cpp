// main.cpp
// Created by DragonScytheXIII on 6/14/2024.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>

#include "LoadBalancer.h"
#include "Server.h"

using namespace std;

/**
 * Generates a random IP4 Address
 * @return string, random IP4 Address
 */
string generateIP() 
{
    int ip1 = rand() % 256; 
    int ip2 = rand() % 256;
    int ip3 = rand() % 256;
    int ip4 = rand() % 256;

    stringstream ss;
    ss << ip1 << "." << ip2 << "." << ip3 << "." << ip4;
    return ss.str();
}

/**
 * Generates a random time between (0, 999)
 * @return int, random time
 */
int generateTime() 
{
    return rand() % 497 + 3; 
}
int main(int argc, char** argv) 
{

    int num_servers;
    int time;


    cout << "Welcome to Load Balancer!" << endl;
    cout << "Enter the number of servers: " << endl;
    cin >> num_servers;
    cout << "Enter length of time to run the load balancer:  " << endl;
    cin >> time;
    int lb_size = num_servers * 2;
    LoadBalancer lb = LoadBalancer();

    double min_task_time = numeric_limits<double>::infinity();;
    double max_task_time = 0.0;

    for (int i = 0; i < lb_size; i++) 
    {
        int random_time = generateTime();
        Request req = {generateIP(), generateIP(), random_time};
        lb.addRequestToQueue(req);
        if (random_time > max_task_time) 
        {
            max_task_time = random_time;
        }
        if (random_time < min_task_time) 
        {
            min_task_time = random_time;
        }
    }

    cout << "Starting size of queue: " <<  lb.getQueueSize() << endl;

    cout << "Creating " << num_servers << " servers" << endl;
    Server server_arr[num_servers];

    for (int i = 0; i < num_servers; i++) 
    {
        server_arr[i] = Server((char)(i + 65));
        server_arr[i].addRequest(lb.getRequest(), lb.getTime());
    }

    while (lb.getTime() < time) 
    {

        if (lb.requestQueueEmpty()) 
        {
            cout << "Request Queue is empty. Exiting..." << endl;
            break;
        }

        int current_time = lb.getTime();
        if (server_arr[current_time % num_servers].isRequestDone(current_time)) 
        {
            Request req = server_arr[current_time % num_servers].getRequest();
            cout << "At time value = " << current_time << " Server " << server_arr[current_time % num_servers].getName() <<
            " has processed a request from " << req.ip_in << " to " << req.ip_out << endl;

            // Give Server new request
            server_arr[current_time % num_servers].addRequest(lb.getRequest(), current_time);
        }

        // (5%) randomy add request to queue
        if (rand() % 20 == 0) 
        {
            int random_time = generateTime();
            Request to_add = {generateIP(), generateIP(), random_time};
            lb.addRequestToQueue(to_add);
            //cout << "Adding new random request" << endl;

            if (random_time > max_task_time) 
            {
                max_task_time = random_time;
            }
            if (random_time < min_task_time) 
            {
                min_task_time = random_time;
            }
        }
        lb.incrementTime();
    }
    cout << "Ending size of queue:" <<  lb.getQueueSize() << endl;
    cout << "Task time range " << min_task_time << "-" << max_task_time << " seconds" << endl;

    return 0;
}