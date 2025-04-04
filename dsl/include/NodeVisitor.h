#pragma once

#include "DOTBaseVisitor.h"
#include "Node.h"
#include "network.h"
#include "node_factory.h"

namespace dot_lang {
    class NodeVisitor : public DOTBaseVisitor {
    private:
        Network* network;
        NodeFactory nodeFactory;

    public:
        NodeVisitor(Network* net) : network(net) {}

        std::any visitNode_stmt(DOTParser::Node_stmtContext *ctx) override {
            // node_id node_attr_list
            // get id
            auto nodeName = visitNode_id(ctx->node_id());

            // find type attribute in node_attr_list to create node:
            auto nodeType = std::any_cast<node_types>(visitType_(ctx->node_attr_list()->type_attr(0)->type_()));

            // create node
            std::shared_ptr<Node> node = nodeFactory.getNodeFromType(nodeType, std::any_cast<std::string>(nodeName));

            // set node properties from node_attr_list
            visitNode_attr_list(ctx->node_attr_list(), node);

            // add node to network
            network->addNode(node);

            return nullptr;
        }

        std::any visitNode_id(DOTParser::Node_idContext *ctx) override {
            // id port
            // get id
            auto id = ctx->id_()->ID();
            return id->getText();
        }

        std::any visitType_(DOTParser::Type_Context *ctx) override {
            // type
            // type is a token from the grammar (SOURCE, QUEUE, ARBITER, SERVER, SINK)
            //   use token to determine node type
            if (ctx->SOURCE()) {
                return std::any(SOURCE);
            } else if (ctx->QUEUE()) {
                return std::any(QUEUE);
            } else if (ctx->ARBITER()) {
                return std::any(ARBITER);
            } else if (ctx->SERVER()) {
                return std::any(SERVER);
            } else if (ctx->SINK()) {
                return std::any(SINK);
            }
            return nullptr;
        }

        void visitNode_attr_list(DOTParser::Node_attr_listContext *ctx, std::shared_ptr<Node> node) {
            // node_attr_list
            // generic_attr* type_attr generic_attr*
            // get type_attr from ctx

            // any generic_attr before or after type_attr, visit each:
            for (auto genericAttr : ctx->generic_attr()) {
                visitGeneric_attr(genericAttr, node);
            }
        }

        void visitGeneric_attr(DOTParser::Generic_attrContext *ctx, std::shared_ptr<Node> node) {
            // generic_attr
            // attr_ cv_attr depth_attr priority_attr rate_attr
            // get attr from ctx

            // any of the possible attribute may or may not exist
            auto attr = ctx->attr_() ? visitAttr_(ctx->attr_()) : std::any();
            auto cvAttr = ctx->cv_attr() ? visitCv_attr(ctx->cv_attr()) : std::any();
            auto depthAttr = ctx->depth_attr() ? visitDepth_attr(ctx->depth_attr()) : std::any();
            auto priorityAttr = ctx->priority_attr() ? visitPriority_attr(ctx->priority_attr()) : std::any();
            auto rateAttr = ctx->rate_attr() ? visitRate_attr(ctx->rate_attr()) : std::any();

            if (attr.has_value()) {
                std::cout << "attr: " << std::any_cast<std::string>(attr) << std::endl;
                // node->setAttribute(std::any_cast<std::string>(attr));
            }
            if (cvAttr.has_value()) {
                std::cout << "cvAttr: " << std::any_cast<double>(cvAttr) << std::endl;
                // node->setCV(std::any_cast<int>(cvAttr));
            }
            if (depthAttr.has_value()) {
                std::cout << "depthAttr: " << std::any_cast<int>(depthAttr) << std::endl;
                // node->setDepth(std::any_cast<int>(depthAttr));
            }
            if (priorityAttr.has_value()) {
                std::cout << "priorityAttr: " << std::any_cast<double>(priorityAttr) << std::endl;
                // node->setPriority(std::any_cast<int>(priorityAttr));
            }
            if (rateAttr.has_value()) {
                std::cout << "rateAttr: " << std::any_cast<double>(rateAttr) << std::endl;
                // node->setRate(std::any_cast<double>(rateAttr));
            }
        }

        std::any visitCv_attr(DOTParser::Cv_attrContext *ctx) override {
            // CV '=' NUMBER (';' | ',')?
            // get cv from ctx
            auto cv = ctx->NUMBER();
            return std::any(std::stod(cv->getText()));
        }

        std::any visitDepth_attr(DOTParser::Depth_attrContext *ctx) override {
            // DEPTH '=' NUMBER (';' | ',')?
            // get depth from ctx
            auto depth = ctx->NUMBER();
            return std::any(std::stoi(depth->getText()));
        }

        std::any visitPriority_attr(DOTParser::Priority_attrContext *ctx) override {
            // PRIORITY '=' NUMBER (';' | ',')?
            // get priority from ctx
            auto priority = ctx->NUMBER();
            return std::any(std::stod(priority->getText()));
        }

        std::any visitRate_attr(DOTParser::Rate_attrContext *ctx) override {
            // RATE '=' NUMBER (';' | ',')?
            // get rate from ctx
            auto rate = ctx->NUMBER();
            return std::any(std::stod(rate->getText()));
        }
    };
}