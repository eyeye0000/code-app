#include "db.h"

drogon::orm::DbClientPtr db =
drogon::orm::DbClient::newPgClient(
    "host=localhost port=5432 dbname=peerdb user=postgres password=1234",
    1
);