#include "functional.hpp"
#include "pw9xx.hpp"

template<class num>
static num pbesol_enhancement(const num &na, const num &gaa)
{
  using pw91_like_x_internal::S2;
  const parameter muge = 0.123456790123;
  const parameter kappa = 0.804;
  num st2 = S2(na,gaa);
  num mu = muge;
  num t1 = 1 + mu*st2/kappa;
  return 1 + kappa - kappa/t1;
}


template<class num>
static num energy_pbesolx(const num &na, const num &gaa)
{
  const parameter c = pow(81/(4*M_PI),1.0/3.0)/2;
  num na43 = pow(na,4.0/3.0);
  num lda = -c*na43;
  num pbesolx = lda * pbesol_enhancement(na,gaa);
  return pbesolx;
}


template<class num>
static num energy(const densvars<num> &d)
{
  return energy_pbesolx(d.a,d.gaa) + energy_pbesolx(d.b,d.gbb);
}


FUNCTIONAL(XC_PBESOLX) = {
  "PBEsol Exchange Functional",
  "PBEsol Exchange Functional\n"
  "J.P. Perdew et al., Phys. Rev. Lett. 100, 136406 (2008)\n"
  "Implemented by Eduardo Fabiano\n",
  XC_DENSITY | XC_GRADIENT,
  ENERGY_FUNCTION(energy)
};

