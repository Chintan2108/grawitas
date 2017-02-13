#pragma once

#include <iostream>

#include "../models/graph.h"

namespace WikiTalkNet {

	void graphToGraphviz(std::ostream& ostr, const UserGraph& g);
	void graphToGraphviz(std::ostream& ostr, const CommentGraph& g);
	void graphToGraphviz(std::ostream& ostr, const TwoModeGraph& g);

}
