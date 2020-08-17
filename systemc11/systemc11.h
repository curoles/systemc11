/**@file
 * @brief     SystemC11 definitions and aliases.
 * @authors   Igor Lesik 2020
 * @copyright Igor Lesik  2020
 *
 *
 */
#pragma once

#include "systemc.h"

namespace sc {

using Module = sc_module;

template <class T> using In = sc_core::sc_in<T>;
template <class T> using Out = sc_core::sc_out<T>;

using In1 = In<bool>;
using Out1 = Out<bool>;


} // namespace sc
