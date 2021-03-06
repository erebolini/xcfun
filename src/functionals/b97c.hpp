#ifndef B97C_H
#define B97C_H

#include "b97xc.hpp"
#include "pw92eps.hpp"
#include "functional.hpp"


namespace b97c
{
    
    // parameters for enhancement factor
    // c_ab0, c_ab1, c_ab2, c_ss0, c_ss1, c_ss2
    const parameter c_b97[2][3] =
    {  { 0.9454, 0.7471, -4.5961},{ 0.1737, 2.3487, -2.4868}};

    const parameter c_b97_1[2][3] =
    {  { 0.955689, 0.788552, -5.47869}, {0.0820011, 2.71681, -2.87103}};

    const parameter c_b97_2[2][3] =
    {  { 0.999849, 1.40626, -7.44060}, {0.585808, -0.691682, 0.394796}};
    
    const parameter Gamma_par = 0.2;
    const parameter Gamma_antipar = 0.006;
    
    
    template<class num>
    static num energy_b97c_par(const parameter &Gamma,
                               const parameter c_params[],const num &a,
                               const num &a_43, const num &gaa, num &e_LSDA)
    {
        e_LSDA = pw92eps::pw92eps_polarized(a)*a;
        num s2_ab2 = b97xc::spin_dens_gradient_ab2(gaa, a_43);
        return e_LSDA *b97xc::enhancement(Gamma, c_params, s2_ab2);
    }

    
    template<class num>
    static num energy_b97c_antipar(const parameter &Gamma,
                                   const parameter c_params[], const densvars<num> &d, const num &e_LSDA_a, const num &e_LSDA_b)
    {
         num e_LSDA = pw92eps::pw92eps(d)*d.n - e_LSDA_a - e_LSDA_b;
         num s2_ab = 0.5*(b97xc::spin_dens_gradient_ab2(d.gaa, d.a_43)+b97xc::spin_dens_gradient_ab2(d.gbb, d.b_43));
        
        return e_LSDA *b97xc::enhancement(Gamma, c_params, s2_ab);
    }
    
  }

#endif

