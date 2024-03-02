#include "../parser.h"

namespace tsil::parser {
    std::any TsilASTVisitor::visitArgs(TsilParser::ArgsContext *context) {
        std::vector<ast::ASTValue *> args;
        for (int i = 0; i < context->expr().size(); ++i) {
            args.push_back(AAV(visitContext(context->expr()[i])));
        }
        return args;
    }
} // namespace tsil::parser