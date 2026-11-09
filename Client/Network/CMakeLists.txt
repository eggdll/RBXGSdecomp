list(APPEND NETWORK_SOURCES "API.cpp")
list(APPEND NETWORK_SOURCES "Client.cpp")
list(APPEND NETWORK_SOURCES "ClientPhysics.cpp")
list(APPEND NETWORK_SOURCES "CrashReporter.cpp")
list(APPEND NETWORK_SOURCES "IdManager.cpp")
list(APPEND NETWORK_SOURCES "NetworkSettings.cpp")
list(APPEND NETWORK_SOURCES "Player.cpp")
list(APPEND NETWORK_SOURCES "Players.cpp")
list(APPEND NETWORK_SOURCES "Replicator.cpp")
list(APPEND NETWORK_SOURCES "Server.cpp")
list(APPEND NETWORK_SOURCES "Streaming.cpp")

add_library(Network ${NETWORK_SOURCES})

target_include_directories(Network
    PUBLIC
        "include"

    PRIVATE
        "include/Network"
        "raknet30/Source"
)

target_link_libraries(Network PRIVATE App Boost G3D)
