#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class Auth : public HttpController<Auth> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(Auth::login, "/login", Post);
    ADD_METHOD_TO(Auth::registerUser, "/register", Post);
    METHOD_LIST_END

        void login(const HttpRequestPtr& req,
            std::function<void(const HttpResponsePtr&)>&& callback);

    void registerUser(const HttpRequestPtr& req,
        std::function<void(const HttpResponsePtr&)>&& callback);
};
