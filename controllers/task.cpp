#include "task.h"
#include "../db.h"

void Task::createAssignment(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto json = req->getJsonObject();

    std::string title = (*json)["title"].asString();

    db->execSqlAsync(
        "INSERT INTO assignments(title) VALUES($1)",
        [callback](const drogon::orm::Result&) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("assignment created");
            callback(resp);
        },
        [](const std::exception& e) {},
        title
    );
}

void Task::listAssignments(const HttpRequestPtr&,
    std::function<void(const HttpResponsePtr&)>&& callback)
{
    db->execSqlAsync(
        "SELECT id,title FROM assignments",
        [callback](const drogon::orm::Result& r) {

            Json::Value arr(Json::arrayValue);

            for (auto row : r) {
                Json::Value obj;
                obj["id"] = row["id"].as<int>();
                obj["title"] = row["title"].as<std::string>();
                arr.append(obj);
            }

            auto resp = HttpResponse::newHttpJsonResponse(arr);
            callback(resp);
        },
        [](const std::exception& e) {}
    );
}}