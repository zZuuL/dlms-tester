#include "HdlcConnectionPool.h"


//---------------------------------------------------------------------------//


static int connection_id = 1;


//---------------------------------------------------------------------------//


HdlcConnectionPool::HdlcConnectionPool()
{}


//---------------------------------------------------------------------------//


bool HdlcConnectionPool::connect(int id)
{
    auto connection = connections.value(id, nullptr);
    if (connection != nullptr)
        return connection->connect();
    return false;
}


//---------------------------------------------------------------------------//


bool HdlcConnectionPool::disconnect(int id)
{
    auto connection = connections.value(id, nullptr);
    if (connection != nullptr)
        return connection->disconnect();
    return false;
}


//---------------------------------------------------------------------------//


int HdlcConnectionPool::addConnection(const DeviceSetting& setting)
{
    int result = connection_id++;

    auto* connection = new HdlcConnection(result, this);
    connection->setSettings(setting);
    connections.insert(result, connection);
    return result;
}


//---------------------------------------------------------------------------//


void HdlcConnectionPool::modifyConnection(int id, const DeviceSetting& setting)
{
    auto connection = connections.value(id, nullptr);
    if (connection != nullptr)
    {
        connection->disconnect();
        connection->setSettings(setting);
        connection->connect();
    }
}


//---------------------------------------------------------------------------//


bool HdlcConnectionPool::removeConnection(int id)
{
    auto connection = connections.value(id, nullptr);
    if (connection != nullptr)
    {
        connection->disconnect();
        connections.remove(id);
        delete connection;
    }

    return false;
}


//---------------------------------------------------------------------------//
