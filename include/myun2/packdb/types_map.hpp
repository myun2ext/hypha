#ifndef __github_com_myun2__packdb__types_map_HPP__
#define __github_com_myun2__packdb__types_map_HPP__

namespace myun2
{
	namespace packdb
	{
		struct types_map
		{
			enum code {
				nil=0,
				integer=1,
				string=2,
				array=16,
				hash=17
			};
		};

		template <enum types_map::code code>
		struct code_to_class_type {};

		template <>
		struct code_to_class_type<types_map::integer> {
			typedef types::integer<int> type;
		};

		template <>
		struct code_to_class_type<types_map::string> {
			typedef types::string type;
		};

//		template <>
//		struct code_to_class_type<types_map::array> {
//			typedef types::array type;
//		};

//		template <>
//		struct code_to_class_type<types_map::hash> {
//			typedef types::hash type;
//		};
	}
}

#endif//__github_com_myun2__packdb__types_map_HPP__
