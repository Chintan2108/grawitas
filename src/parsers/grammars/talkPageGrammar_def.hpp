#pragma once

#define BOOST_SPIRIT_DEBUG

#include "talkPageGrammar.hpp"

namespace WikiTalkNet {

	template<typename Iterator, typename Skipper>
		TalkPageGrammar<Iterator, Skipper>::TalkPageGrammar() : TalkPageGrammar::base_type(comments, "TalkPageGrammar") {
			using namespace boost::spirit::qi;
			using boost::phoenix::push_back;

			// comment_ending = *char_(".;") [_val += 1, _pass = _val < 5] >> (eol | eoi);
			comments = (comment_grammar [push_back(_val, boost::spirit::_1)] ) % comment_ending;

			// BOOST_SPIRIT_DEBUG_NODE(comments);
			on_error<accept>(comments, std::cout << boost::phoenix::val("Error! Expecting ") << boost::spirit::_4 << boost::phoenix::val(" here: \"") << boost::phoenix::construct<std::string>(boost::spirit::_3, boost::spirit::_2) << boost::phoenix::val("\"") << std::endl);
		}
}
