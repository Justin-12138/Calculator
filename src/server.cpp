#include <iostream>
#include <string>
#include <httplib.h>
#include "../include/Calculator.h"

using namespace httplib;

int main() {
    Server svr;
    Calculator calc;

    svr.Post("/calculate", [&](const Request& req, Response& res) {
        auto json = nlohmann::json::parse(req.body);
        std::string expression = json["expression"];
        
        try {
            double result = calc.calculate(expression);
            res.set_content(nlohmann::json{{"result", result}}.dump(), "application/json");
        } catch (const std::exception& e) {
            res.set_content(nlohmann::json{{"error", e.what()}}.dump(), "application/json");
        }
    });

    svr.set_mount_point("/", "./web");
    std::cout << "Server started at http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);

    return 0;
}
