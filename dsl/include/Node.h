#pragma once
#include "defines.h"

namespace dot_lang {
    class Node {
    public: 
        Node();
        Node(node_types);
        Node(node_types, std::string);
        virtual ~Node() = default;
        unsigned int getID() const {return _id;}
        node_types getType() const {return _type;}
        void setName(std::string name) {_name = name;}
        std::string getName() const {return _name;}

        virtual std::string getGraphVizProperties() = 0;
    
    protected:
        virtual std::string _getIDLabel() {
            return "label=\"" + std::to_string(_id) + "\"";
        }
        virtual std::string _shape() = 0;

    private:
        unsigned int _id;
        node_types _type;
        static unsigned int _id_counter;
        std::string _name;
    };
}
