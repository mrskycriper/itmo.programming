#pragma once


template <typename Type>
class Greater
{
public:
	bool operator () (const Type& First, const Type& Second) const
	{
		return First >= Second;
	}
};

namespace Algorithms
{

	template <typename iterType, typename Func>
	bool all_of (iterType start, iterType end, Func function)
	{
		for (; start != end; ++start)
		{
			if (!function (*start))
			{
				return false;
			}
		}
		return true;
	}

	template <typename iterType, typename Func>
	bool is_sorted (iterType start, iterType end, Func function)
	{
		iterType prev;
		while (start != end)
		{
			prev = start;
			++start;
			if (start == end)
			{
				break;
			}
			if (!function (*prev, *start))
			{
				return false;
			}
		}
		return true;
	}


	template <typename iterType, typename Type>
	iterType find_backwards (iterType start, iterType end, const Type& item)
	{
		for (; end != start; --end)
		{
			if (*end == item)
			{
				return end;
			}
		}
		return end;
	}

}


