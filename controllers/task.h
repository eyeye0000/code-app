#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class Task : public HttpController<Task> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(Task::createAssignment, "/task/create", Post);
    ADD_METHOD_TO(Task::listAssignments, "/task/list", Get);
    METHOD_LIST_END

        void createAssignment(const HttpRequestPtr& req,
            std::function<void(const HttpResponsePtr&)>&& callback);

    void listAssignments(const HttpRequestPtr& req,
        std::function<void(const HttpResponsePtr&)>&& callback);
};