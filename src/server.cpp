#include <iostream>
#include <string>
#include <httplib.h>
#include "../include/Calculator.h"
#include <nlohmann/json.hpp>

using namespace httplib;
using json = nlohmann::json;

int main() {
    Server svr;
    Calculator calc;

    // RESTful API endpoints
    svr.Post("/api/calculate", [&](const Request& req, Response& res) {
        try {
            auto json_data = json::parse(req.body);
            std::string expression = json_data["expression"];
            double result = calc.calculate(expression);
            res.set_content(json{{"result", result}}.dump(), "application/json");
        } catch (const std::exception& e) {
            res.set_content(json{{"error", e.what()}}.dump(), "application/json");
            res.status = 400;
        }
    });

    svr.set_mount_point("/", "./web");
    std::cout << "RESTful Calculator API running at http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);

    return 0;
}
