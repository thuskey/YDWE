#pragma once

#include <base/util/buffer.h>
#include <slk/table/MetaTable.hpp>

namespace slk
{
	struct MetaReader
	{
		static void Read(base::util::buffer_reader& reader, MetaTable& table);
	};
}