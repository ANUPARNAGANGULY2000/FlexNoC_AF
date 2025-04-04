#include <gtest/gtest.h>
#include "DOTParser.h"
#include "DOTLexer.h"
#include <antlr4-runtime.h>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

class SyntaxErrorListener : public antlr4::BaseErrorListener {
public:
    bool hasError = false;

    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {
        std::cerr << "Syntax error at line " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        hasError = true;
    }
};

class DOTParserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Common setup code for all tests
    }

    void TearDown() override {
        // Common cleanup code for all tests
    }

    bool parseDotFile(const std::string& dotFilePath) {
        try {
            std::string input = readFile(dotFilePath);
            antlr4::ANTLRInputStream inputStream(input);
            DOTLexer lexer(&inputStream);
            antlr4::CommonTokenStream tokens(&lexer);
            DOTParser parser(&tokens);

            SyntaxErrorListener errorListener;
            parser.removeErrorListeners();
            parser.addErrorListener(&errorListener);

            antlr4::tree::ParseTree* tree = parser.graph();
           
            return tree != nullptr && !errorListener.hasError;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            return false;
        }
    }
};

TEST_F(DOTParserTest, ParseValidDotFile) {
    std::string dotFilePath = "../../test_graph.dot";
    bool success = parseDotFile(dotFilePath);
    ASSERT_TRUE(success);
}

TEST_F(DOTParserTest, ParseInvalidDotFileRaisesException) {
    std::string dotFilePath = "../invalid_graph.dot";
    bool success = parseDotFile(dotFilePath);
    ASSERT_FALSE(success);
}