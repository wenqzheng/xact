#include "xact/generalized_cas_1/Operation.h"
#include "xact/generalized_cas_1/Precondition.h"
#include "xact/generalized_cas_1/GeneralizedCAS.h"
#include "xact_asm/core.h"

namespace xact { namespace generalized_cas_1 {

GeneralizedCASOpCore& GeneralizedCASOp::core() {
  return core_;
}

const GeneralizedCASOpCore& GeneralizedCASOp::core() const {
  return core_;
}

bool GeneralizedCASOp::execute() {
  return xact_generalized_cas_op(
    core_.preconditions, core_.nPreconditions,
    core_.operations, core_.nOperations
  ) == 0;
}

}} // xact::generalized_cas_1

