#include "xcint.hpp"

static struct alias_data aliases_array[XC_MAX_ALIASES] =
{
  {"null","No functional",{{"slaterx",0.0}} },
  {"lda","Slater exchange and VWN5 correlation",{{"slaterx",1.0},{"vwn5c",1.0}} },
  {"blyp","Becke exchange and LYP correlation",{{"beckex",1.0},{"lypc",1.0}} },
  {"pbe","PBE exchange and correlation",{{"pbex",1.0},{"pbec",1.0}} },
  {"bp86","Becke-Perdew 1986",{{"beckex",1.0},{"p86c",1.0}} },
  {"kt2","Keal-Tozer 2",{{"slaterx",1.07173},{"ktx",-0.006},{"vwn5c",0.576727}} },
  {"kt3","Keal-Tozer 3",{{"slaterx",1.092},{"ktx",-0.004},{"optxcorr",-0.925452},{"lypc",0.864409}} },
  // Hybrid Functionals
  {"pbe0","Perdew-Burke-Ernzerhof",{{"pbex",0.75},{"pbec",1.0},{"exx",0.25}} }, 
  {"b3lyp","Becke-3-paramater-LYP (VWN5 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"lypc",0.81},{"vwn5c",0.19},{"exx",0.20}} }, 
  {"m06","M06", {{"m06c",1.0},{"m06x",1.0}} }, 
  {"m06-2x","M06 2X", {{"m06x2c",1.0},{"m06x2x",1.0}} }, 
  {"m06L","M06 L", {{"m06lc",1.0},{"m06lx",1.0}} }, 
  {"b3lyp-g","Becke-3-paramater-LYP (VWN3 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"lypc",0.81},{"vwn3c",0.19},{"exx",0.20}} }, 
  {"b3p86","Becke-3-paramater-LYP (VWN5 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"p86c",0.81},{"vwn5c",1.0},{"exx",0.20}} }, 
  {"b3p86-g","Becke-3-paramater-LYP (VWN3 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"p86c",0.81},{"vwn3c",1.0},{"exx",0.20}} }, 
  {"bpw91","Becke 88 exchange+PW91",{{"beckex",1.0},{"pw91c",1.0}} },
};

// TODO: OLYP


struct alias_data *xcint_aliases = aliases_array;
