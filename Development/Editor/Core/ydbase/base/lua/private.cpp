#include <base/lua/private.h>

extern "C" {
#include <lstate.h>
}

namespace base { namespace lua {
	bool allow_yield(state* ls)
	{
		return ls->self()->nny == 0;
	}
}}
