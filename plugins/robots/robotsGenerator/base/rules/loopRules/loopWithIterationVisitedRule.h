#pragma once

#include "loopBlockRuleBase.h"

namespace qReal {
namespace robots {
namespace generators {
namespace semantics {

class LoopWithIterationVisitedRule : public LoopBlockRuleBase
{
public:
	LoopWithIterationVisitedRule(SemanticTree *tree, Id const &id
			, LinkInfo const &iterationLink, LinkInfo const &nextLink);

	virtual bool apply();
};

}
}
}
}
