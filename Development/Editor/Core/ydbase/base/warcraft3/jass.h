#pragma once

#include <base/config.h>
#include <cstdint>
#include <vector>

namespace base { namespace warcraft3 { namespace jass {

	typedef void     jnothing_t;
	typedef uint32_t jboolean_t;
	typedef uint32_t jcode_t;
	typedef uint32_t jhandle_t;
	typedef uint32_t jinteger_t;
	typedef uint32_t jreal_t;
	typedef uint32_t jstring_t;

	class _BASE_API string_fake
	{
	public:
		string_fake();
		string_fake(const char* str);
		string_fake(const string_fake& that);
		string_fake(string_fake&& that);
		~string_fake();
		operator jstring_t () const;
		string_fake& operator =(const char* str);
		string_fake& operator =(const string_fake& that);
		string_fake& operator =(string_fake&& that);

	private:
		uint32_t memory_[8];
	};

	class _BASE_API call_param
	{
	public:
		call_param(size_t n);
		template <class T> void push(size_t i, T value);
		void push_real(size_t i, jreal_t value);
		const uintptr_t* data() const;

	private:
#pragma warning(push)
#pragma warning(disable: 4251)
		std::vector<uintptr_t>   param_buffer_;
		std::vector<jreal_t>     real_buffer_;
		std::vector<string_fake> string_buffer_;
#pragma warning(pop)
	};

	_BASE_API float       from_real      (jreal_t val);
	_BASE_API jreal_t     to_real        (float val);
	_BASE_API const char* from_string    (jstring_t val);
	_BASE_API string_fake to_string      (const char* val);

	_BASE_API uintptr_t   create_string  (const char* val);
	_BASE_API const char* from_trigstring(const char* val);
	_BASE_API const char* from_stringid  (uint32_t strid);

	_BASE_API void        handle_add_ref (jhandle_t h);
	_BASE_API void        handle_release (jhandle_t h);

	_BASE_API uintptr_t   call           (const char* name, ...);
	_BASE_API uintptr_t   call           (uintptr_t func_address, const uintptr_t* param_list, size_t param_list_size);
}}}
