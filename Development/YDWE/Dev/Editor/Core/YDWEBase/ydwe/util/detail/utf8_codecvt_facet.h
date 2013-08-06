#pragma once

#include <ydwe/config.h>
#include <locale>

_BASE_BEGIN 
namespace util { namespace detail {

class utf8_codecvt_facet : public std::codecvt<wchar_t, char, std::mbstate_t>  
{
public:
	explicit utf8_codecvt_facet()
		: std::codecvt<wchar_t, char, std::mbstate_t>() 
	{ }

protected:
	virtual bool do_always_noconv() const throw() { return false; }
	virtual int do_encoding() const throw() { return 0; }
	virtual std::codecvt_base::result do_in(std::mbstate_t& state, const char * from, const char * from_end, const char * & from_next, wchar_t * to, wchar_t * to_end, wchar_t*& to_next) const;
	virtual std::codecvt_base::result do_out(std::mbstate_t & state, const wchar_t * from, const wchar_t * from_end, const wchar_t*  & from_next, char * to, char * to_end, char * & to_next) const;
	virtual std::codecvt_base::result do_unshift(std::mbstate_t&, char * from, char * /*to*/, char * & next) const;
	virtual int do_length(const std::mbstate_t &, const char * from, const char * from_end, std::size_t max_limit) const throw();
	virtual int do_max_length() const throw () { return 6; }
};

}}
_BASE_END
