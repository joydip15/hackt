/**
	\file "Object/global_entry_context.tcc"
	$Id: global_entry_context.tcc,v 1.1.2.2 2007/01/14 05:38:44 fang Exp $
 */

#ifndef	__HAC_OBJECT_GLOBAL_ENTRY_CONTEXT_TCC__
#define	__HAC_OBJECT_GLOBAL_ENTRY_CONTEXT_TCC__

#include "Object/global_entry_context.h"
#include "Object/global_entry.h"
#include "Object/ref/meta_instance_reference_subtypes.h"
#include "Object/ref/simple_meta_instance_reference.h"
#include "Object/unroll/unroll_context.h"

namespace HAC {
namespace entity {
//=============================================================================
// class global_entry_context method definitions

/**
	Looks up globally allocated index using footprint frame
	if this is a local index, else returns the same id as a global id. 
	\param lni the index of the instance local to the footprint (type).
 */
template <class Tag>
size_t
global_entry_context::lookup_global_id(const size_t lni) const {
	INVARIANT(lni);
	if (fpf) {
		// see also footprint_frame_transformer in global_entry.h
#if 1
		// equivalent
		return footprint_frame_transformer(*fpf, Tag())(lni);
#else
		return fpf->template get_frame_map<Tag>()[lni-1];
#endif
	} else {
		// is top-level footprint
		return lni;
	}
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/**
	Translates a meta-instance-reference to globally allocated index.
	This already folds the operation of member-function lookup_global_id.
	\param r the meta-instance-reference to lookup.  
	\return globally allocated index, or 0 if lookup failed.  
 */
template <class Tag>
size_t
global_entry_context::lookup_meta_reference_global_index(
		const simple_meta_instance_reference<Tag>& r) const {
	NEVER_NULL(sm);
	NEVER_NULL(topfp);
	if (fpf) {
		const unroll_context c(fpf->_footprint, topfp);
		const size_t local_index =
			r.lookup_locally_allocated_index(*sm, c);
		if (!local_index)
			return 0;
		return footprint_frame_transformer(*fpf, Tag())(local_index);
	} else {
		return r.lookup_globally_allocated_index(*sm, *topfp);
	}
}

//=============================================================================
}	// end namespace entity
}	// end namespace HAC

#endif	// __HAC_OBJECT_GLOBAL_ENTRY_CONTEXT_TCC__

