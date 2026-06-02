#include "auth.h"
#include "../db.h"

void Auth::registerUser(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto json = req->getJsonObject();

    std::string username = (*json)["username"].asString();
    std::string password = (*json)["password"].asString();

    db->execSqlAsync(
        "INSERT INTO users(username,password_hash) VALUES($1,$2)",
        [callback](const drogon::orm::Result&) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("registered");
            callback(resp);
        },
        [](const std::exception& e) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("error");
        },
        username, password
    );
}

void Auth::login(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("login stub (not secure yet)");
    callback(resp);
}