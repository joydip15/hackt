/**
	\file "sim/chpsim/InstancePools.cc"
	$Id: InstancePools.cc,v 1.1.2.2 2006/12/19 23:44:12 fang Exp $
 */

// replaced by "Object/nonmeta_state.cc"
#include "sim/chpsim/InstancePools.h"

#if 0
#include <iostream>
#include "sim/chpsim/InstancePools.h"
#include "Object/state_manager.h"
#include "Object/global_entry.h"
#include "Object/traits/int_traits.h"
#include "Object/traits/bool_traits.h"
#include "Object/traits/chan_traits.h"

namespace HAC {
namespace SIM {
namespace CHPSIM {
#include "util/using_ostream.h"
using entity::global_entry_pool;
using entity::bool_tag;
using entity::int_tag;
using entity::channel_tag;
using entity::footprint;

//=============================================================================
// class instance_pool_base method definitions

template <class Tag>
instance_pool_base<Tag>::instance_pool_base(const state_manager& sm) :
		pool() {
	const global_entry_pool<Tag>& p(sm.get_pool<Tag>());
	const size_t s = p.size();
	this->pool.resize(s);
}

template <class Tag>
instance_pool_base<Tag>::~instance_pool_base() { }

//=============================================================================
// class InstancePools method definitions

InstancePools::InstancePools(const state_manager& sm) :
		bool_base_type(sm), 
		int_base_type(sm), 
		channel_base_type(sm) {
#if 0
	const global_entry_pool<bool_tag>& bp(sm.get_pool<bool_tag>());
	const global_entry_pool<int_tag>& ip(sm.get_pool<int_tag>());
	const global_entry_pool<channel_tag>& cp(sm.get_pool<channel_tag>());
	const size_t bs = bp.size();
	const size_t is = ip.size();
	const size_t cs = cp.size();
	bool_pool.resize(bs);
	int_pool.resize(is);
	channel_pool.resize(cs);
#endif
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
InstancePools::~InstancePools() { }

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ostream&
InstancePools::dump_struct(ostream& o, const state_manager& sm, 
		const footprint& topfp) const {
	{
		const global_entry_pool<bool_tag>& bp(sm.get_pool<bool_tag>());
		const node_index_type bools = bool_base_type::pool.size();
		node_index_type i = FIRST_VALID_NODE;
		for ( ; i<bools; ++i) {
			o << "bool[" << i << "]: \"";
			bp[i].dump_canonical_name(o, topfp, sm);
			o << "\" ";
			// no static structural information
			// bool_pool[i].dump_struct(o);
			o << endl;
		}
	}{
		const global_entry_pool<int_tag>& ip(sm.get_pool<int_tag>());
		const node_index_type ints = int_base_type::pool.size();
		node_index_type i = FIRST_VALID_NODE;
		for ( ; i<ints; ++i) {
			o << "int[" << i << "]: \"";
			ip[i].dump_canonical_name(o, topfp, sm);
			o << "\" ";
			// no static structural information
			// int_pool[i].dump_struct(o);
			o << endl;
		}
	}{
		const global_entry_pool<channel_tag>&
			cp(sm.get_pool<channel_tag>());
		const node_index_type chans = channel_base_type::pool.size();
		node_index_type i = FIRST_VALID_NODE;
		for ( ; i<chans; ++i) {
			o << "chan[" << i << "]: \"";
			cp[i].dump_canonical_name(o, topfp, sm);
			o << "\" ";
			// no static structural information
			// channel_pool[i].dump_struct(o);
			o << endl;
		}
	}
	return o;
}

//=============================================================================
}	// end namespace CHPSIM
}	// end namespace SIM
}	// end namespace HAC
#endif
