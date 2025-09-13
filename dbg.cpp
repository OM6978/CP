#include <iostream>
#include <cpr/cpr.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    // 1. Create a JSON object to send as the request body
    json payload = {
        {"title", "My Awesome Post"},
        {"body", "This is the content of my new post from C++."},
        {"userId", 11}
    };

    // 2. Make the POST request with the JSON payload
    cpr::Response r = cpr::Post(
        cpr::Url{"https://jsonplaceholder.typicode.com/posts"},
        cpr::Body{payload.dump()}, // Convert JSON object to a string for the body
        cpr::Header{{"Content-Type", "application/json"}} // Set the correct header
    );

    std::cout << "Request sent. Server responded with status code: " << r.status_code << std::endl;

    // 3. Check the response from the server
    // A successful POST request that creates a resource usually returns status 201
    if (r.status_code == 201) {
        // 4. Parse the JSON response from the server
        json response_json = json::parse(r.text);
        
        std::cout << "Successfully created a new post!" << std::endl;
        std::cout << "--- Server Response ---" << std::endl;
        // The .dump(2) function pretty-prints the JSON with an indent of 2 spaces
        std::cout << response_json.dump(2) << std::endl;

        // You can now access specific fields from the response
        int new_post_id = response_json["id"];
        std::cout << "\nThe new post was assigned ID: " << new_post_id << std::endl;

    } else {
        std::cerr << "Error: Could not create the post." << std::endl;
        std::cerr << "Error details: " << r.error.message << std::endl;
    }

    return 0;
}