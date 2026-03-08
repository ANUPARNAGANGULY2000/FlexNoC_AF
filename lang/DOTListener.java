// Generated from DOT.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DOTParser}.
 */
public interface DOTListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DOTParser#graph}.
	 * @param ctx the parse tree
	 */
	void enterGraph(DOTParser.GraphContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#graph}.
	 * @param ctx the parse tree
	 */
	void exitGraph(DOTParser.GraphContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#stmt_list}.
	 * @param ctx the parse tree
	 */
	void enterStmt_list(DOTParser.Stmt_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#stmt_list}.
	 * @param ctx the parse tree
	 */
	void exitStmt_list(DOTParser.Stmt_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(DOTParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(DOTParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#attr_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAttr_stmt(DOTParser.Attr_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#attr_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAttr_stmt(DOTParser.Attr_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#attr_list}.
	 * @param ctx the parse tree
	 */
	void enterAttr_list(DOTParser.Attr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#attr_list}.
	 * @param ctx the parse tree
	 */
	void exitAttr_list(DOTParser.Attr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#node_attr_list}.
	 * @param ctx the parse tree
	 */
	void enterNode_attr_list(DOTParser.Node_attr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#node_attr_list}.
	 * @param ctx the parse tree
	 */
	void exitNode_attr_list(DOTParser.Node_attr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edge_attr_list}.
	 * @param ctx the parse tree
	 */
	void enterEdge_attr_list(DOTParser.Edge_attr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edge_attr_list}.
	 * @param ctx the parse tree
	 */
	void exitEdge_attr_list(DOTParser.Edge_attr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#generic_attr}.
	 * @param ctx the parse tree
	 */
	void enterGeneric_attr(DOTParser.Generic_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#generic_attr}.
	 * @param ctx the parse tree
	 */
	void exitGeneric_attr(DOTParser.Generic_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#cv_attr}.
	 * @param ctx the parse tree
	 */
	void enterCv_attr(DOTParser.Cv_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#cv_attr}.
	 * @param ctx the parse tree
	 */
	void exitCv_attr(DOTParser.Cv_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#service_time_attr}.
	 * @param ctx the parse tree
	 */
	void enterService_time_attr(DOTParser.Service_time_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#service_time_attr}.
	 * @param ctx the parse tree
	 */
	void exitService_time_attr(DOTParser.Service_time_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#coeff_service_time_attr}.
	 * @param ctx the parse tree
	 */
	void enterCoeff_service_time_attr(DOTParser.Coeff_service_time_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#coeff_service_time_attr}.
	 * @param ctx the parse tree
	 */
	void exitCoeff_service_time_attr(DOTParser.Coeff_service_time_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#zero_load_latency_attr}.
	 * @param ctx the parse tree
	 */
	void enterZero_load_latency_attr(DOTParser.Zero_load_latency_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#zero_load_latency_attr}.
	 * @param ctx the parse tree
	 */
	void exitZero_load_latency_attr(DOTParser.Zero_load_latency_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#depth_attr}.
	 * @param ctx the parse tree
	 */
	void enterDepth_attr(DOTParser.Depth_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#depth_attr}.
	 * @param ctx the parse tree
	 */
	void exitDepth_attr(DOTParser.Depth_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#priority_attr}.
	 * @param ctx the parse tree
	 */
	void enterPriority_attr(DOTParser.Priority_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#priority_attr}.
	 * @param ctx the parse tree
	 */
	void exitPriority_attr(DOTParser.Priority_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#rate_attr}.
	 * @param ctx the parse tree
	 */
	void enterRate_attr(DOTParser.Rate_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#rate_attr}.
	 * @param ctx the parse tree
	 */
	void exitRate_attr(DOTParser.Rate_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#type_attr}.
	 * @param ctx the parse tree
	 */
	void enterType_attr(DOTParser.Type_attrContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#type_attr}.
	 * @param ctx the parse tree
	 */
	void exitType_attr(DOTParser.Type_attrContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#type_}.
	 * @param ctx the parse tree
	 */
	void enterType_(DOTParser.Type_Context ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#type_}.
	 * @param ctx the parse tree
	 */
	void exitType_(DOTParser.Type_Context ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#a_list}.
	 * @param ctx the parse tree
	 */
	void enterA_list(DOTParser.A_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#a_list}.
	 * @param ctx the parse tree
	 */
	void exitA_list(DOTParser.A_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#attr_}.
	 * @param ctx the parse tree
	 */
	void enterAttr_(DOTParser.Attr_Context ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#attr_}.
	 * @param ctx the parse tree
	 */
	void exitAttr_(DOTParser.Attr_Context ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edge_stmt}.
	 * @param ctx the parse tree
	 */
	void enterEdge_stmt(DOTParser.Edge_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edge_stmt}.
	 * @param ctx the parse tree
	 */
	void exitEdge_stmt(DOTParser.Edge_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edgeRHS}.
	 * @param ctx the parse tree
	 */
	void enterEdgeRHS(DOTParser.EdgeRHSContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edgeRHS}.
	 * @param ctx the parse tree
	 */
	void exitEdgeRHS(DOTParser.EdgeRHSContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edgeop}.
	 * @param ctx the parse tree
	 */
	void enterEdgeop(DOTParser.EdgeopContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edgeop}.
	 * @param ctx the parse tree
	 */
	void exitEdgeop(DOTParser.EdgeopContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#node_stmt}.
	 * @param ctx the parse tree
	 */
	void enterNode_stmt(DOTParser.Node_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#node_stmt}.
	 * @param ctx the parse tree
	 */
	void exitNode_stmt(DOTParser.Node_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#node_id}.
	 * @param ctx the parse tree
	 */
	void enterNode_id(DOTParser.Node_idContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#node_id}.
	 * @param ctx the parse tree
	 */
	void exitNode_id(DOTParser.Node_idContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#port}.
	 * @param ctx the parse tree
	 */
	void enterPort(DOTParser.PortContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#port}.
	 * @param ctx the parse tree
	 */
	void exitPort(DOTParser.PortContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#subgraph}.
	 * @param ctx the parse tree
	 */
	void enterSubgraph(DOTParser.SubgraphContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#subgraph}.
	 * @param ctx the parse tree
	 */
	void exitSubgraph(DOTParser.SubgraphContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#id_}.
	 * @param ctx the parse tree
	 */
	void enterId_(DOTParser.Id_Context ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#id_}.
	 * @param ctx the parse tree
	 */
	void exitId_(DOTParser.Id_Context ctx);
}