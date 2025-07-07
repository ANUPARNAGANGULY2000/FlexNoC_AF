// top level
#include <iostream>
#include <dot_compiler.h>
#include<defines.h>
#include <Injector.h>
#include <Queue.h>
#include <Primitive.h>
#include <node_factory.h>
#include <network.h>
#include <Mapping.h>
#include "Node.h"
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <fstream>
#include <sstream>
#include <DOTLexer.h>
#include <DOTParser.h>
#include <TypeCheckVisitor.h>
#include <NodeVisitor.h>
#include <DOTBaseVisitor.h>
#include <antlr4-runtime.h>
#include <memory>


using namespace dot_lang;
using namespace boost;

/* predefine some boost-specifics for examples */
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, std::shared_ptr<Node>> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

static Graph example_use_BGL();
static void writeGraph(Graph testG);
DOT::DOT(std::string pathToDOTFile) {
    // initialize the network object
    network = new Network();
    dot_lang::Mapping mapping;
    // use antlr4 to compile
    _compile(pathToDOTFile);
}

/*
 * Lexes, parses, and builds the symbol table for the DOT file.
 *   Result of this process is a network object that contains the nodes and edges
 *   that are defined in the DOT file, and an assurance that the topology is valid.
 */
void DOT::_translate(std::string pathToDOTFile) {
    // open the DOT file using pathToDOTFile
    std::ifstream file(pathToDOTFile);
    if(!file.is_open()){
    	std::cerr<<"Failed to open DOT file: "<<pathToDOTFile<<std::endl;
	return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    //file.close();

    antlr4::ANTLRInputStream inputStream(buffer.str());
    DOTLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    DOTParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.graph();
    if (parser.getNumberOfSyntaxErrors() > 0 ) {
        std::cerr << "Syntax errors found during parsing." << std::endl;
        return;
    }
   
    //print parse tree
   /* std::cout<<tree->toStringTree(&parser)<<std::endl;
    //token generation
    tokens.fill();
    for(auto token : tokens.getTokens()){
    	std::cout<<token->toString()<<std::endl;
    }*/
	
    // visit the parse tree, building symbol table, type checking, etc, generating objects for nodes and edges
    // visit nodes, then edges, then type check
   
    NodeVisitor nv(network, mapping);
    //nv.visit(tree); // builds all nodes

    try {
    		nv.visit(tree); // builds all nodes
	} catch (const std::exception& ex) {
    		std::cerr << "Exception: " << ex.what() << std::endl;
	} catch (...) {
    		std::cerr << "Unknown exception occurred." << std::endl;
	}

   EdgeVisitor ev(network, mapping);
   ev.visit(tree); // builds all edges

}

void DOT::_optimize() {}

void DOT::_codegen() {
    // example generating a graph using boost BGL
    Graph example_boost_graph = example_use_BGL();

    // write the graph to a .dot file
    writeGraph(example_boost_graph);
}

void DOT::_compile(std::string pathToDOTFile) {
    
    // phase1: translation (i.e., lexing, parsing, symbol table generation, and type checking)
    _translate(pathToDOTFile);

    // phase2: optimization (i.e., AST optimization, IR generation if applicable)
    _optimize();

    // phase3: code generation (i.e., generating the final output code or collateral files)
    // e.g., could use the DOT::network object to generate a BGL graph, and that could be provided to a consumer
    _codegen();
}

/* boost-specific example code */

static Graph example_use_BGL() {
    // example code using boost BGL library:
    //  generating graph with polymorphic Node objects
    Graph testG;
    
    /*std::vector<Vertex> nodes;

    NodeFactory factory;
    for (auto i = 0; i < 10; ++i) {
        std::shared_ptr<dot_lang::Node> node = factory.getNodeFromType(node_types(i%5));

        std::cout << "made Node: " << node->getID() << " with type: " << node->getType();
        if (node->getType() == SOURCE)
            std::cout << " injector type has rate: " << dynamic_cast<dot_lang::Injector*>(node.get())->getInjectionRate();
        else if (node->getType() == QUEUE)
            std::cout << " queue depth: " << dynamic_cast<dot_lang::Queue*>(node.get())->getBufferSize();
        std::cout << std::endl;
        auto v = add_vertex(node, testG);
        nodes.push_back(v);
    }

    for (auto i = 0; i < nodes.size()-1; i++)
        add_edge(nodes[i], nodes[i+1], testG);*/

    return testG;
}

static void writeGraph(Graph testG) {
    // custom writer for .dot output (for visualization purposes)
    auto vertex_writer = [&](std::ostream& out, const Vertex& v) {
        out << "[" << testG[v]->getGraphVizProperties() << "]";
    };

    auto edge_writer = [](std::ostream& out, const Edge& ) {};

    auto graph_writer = [&](std::ostream& out) {
        out << "rankdir=\"LR\"\n";
    };

    std::ofstream out_file("graph_out.dot");
/*    boost::write_graphviz(out_file, testG, vertex_writer, edge_writer, boost::make_graph_attributes_writer(boost::dummy_property_map(),
        boost::dummy_property_map(),
        boost::dummy_property_map()));
    system("dot -Tpng graph_out.dot -o graph_out.png");*/

    std::map<std::string, std::string> graph_attrs;
std::map<std::string, std::string> vertex_attrs;
std::map<std::string, std::string> edge_attrs;

boost::write_graphviz(
    out_file,
    testG,
    vertex_writer,
    edge_writer,
    boost::make_graph_attributes_writer(graph_attrs, vertex_attrs, edge_attrs)
);

}
