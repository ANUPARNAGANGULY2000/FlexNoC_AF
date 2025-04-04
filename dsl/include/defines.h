#pragma once
#include <string>
#include <memory>

namespace dot_lang {
enum node_types {SOURCE=0, SINK, QUEUE, SERVER, ARBITER};
}

const std::string _nodeTypeToString[] = {
    "Source",
    "Sink",
    "Queue",
    "Server",
    "Arbiter"
};