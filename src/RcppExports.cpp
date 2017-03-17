// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// cpp_bart_y
NumericVector cpp_bart_y(NumericVector new_xroot, NumericVector new_yroot, int new_nd, int new_burn, int new_m, int new_nu, int new_kfac, int new_nmissing, IntegerVector new_xmissroot, int new_bistart, NumericVector new_vartyperoot, NumericVector new_zroot, NumericVector new_lambda, int new_type);
RcppExport SEXP bartpkg1_cpp_bart_y(SEXP new_xrootSEXP, SEXP new_yrootSEXP, SEXP new_ndSEXP, SEXP new_burnSEXP, SEXP new_mSEXP, SEXP new_nuSEXP, SEXP new_kfacSEXP, SEXP new_nmissingSEXP, SEXP new_xmissrootSEXP, SEXP new_bistartSEXP, SEXP new_vartyperootSEXP, SEXP new_zrootSEXP, SEXP new_lambdaSEXP, SEXP new_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type new_xroot(new_xrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_yroot(new_yrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_nd(new_ndSEXP);
    Rcpp::traits::input_parameter< int >::type new_burn(new_burnSEXP);
    Rcpp::traits::input_parameter< int >::type new_m(new_mSEXP);
    Rcpp::traits::input_parameter< int >::type new_nu(new_nuSEXP);
    Rcpp::traits::input_parameter< int >::type new_kfac(new_kfacSEXP);
    Rcpp::traits::input_parameter< int >::type new_nmissing(new_nmissingSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type new_xmissroot(new_xmissrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_bistart(new_bistartSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_vartyperoot(new_vartyperootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_zroot(new_zrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_lambda(new_lambdaSEXP);
    Rcpp::traits::input_parameter< int >::type new_type(new_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_bart_y(new_xroot, new_yroot, new_nd, new_burn, new_m, new_nu, new_kfac, new_nmissing, new_xmissroot, new_bistart, new_vartyperoot, new_zroot, new_lambda, new_type));
    return rcpp_result_gen;
END_RCPP
}
// cpp_bart_y1
NumericVector cpp_bart_y1(NumericVector new_xroot, NumericVector new_yroot, int new_nd, int new_burn, int new_m, int new_nu, int new_kfac, int new_nmissing, IntegerVector new_xmissroot, int new_bistart, NumericVector new_vartyperoot, NumericVector new_zroot, NumericVector new_beta, NumericVector new_vroot, NumericVector new_lambda, int new_type);
RcppExport SEXP bartpkg1_cpp_bart_y1(SEXP new_xrootSEXP, SEXP new_yrootSEXP, SEXP new_ndSEXP, SEXP new_burnSEXP, SEXP new_mSEXP, SEXP new_nuSEXP, SEXP new_kfacSEXP, SEXP new_nmissingSEXP, SEXP new_xmissrootSEXP, SEXP new_bistartSEXP, SEXP new_vartyperootSEXP, SEXP new_zrootSEXP, SEXP new_betaSEXP, SEXP new_vrootSEXP, SEXP new_lambdaSEXP, SEXP new_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type new_xroot(new_xrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_yroot(new_yrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_nd(new_ndSEXP);
    Rcpp::traits::input_parameter< int >::type new_burn(new_burnSEXP);
    Rcpp::traits::input_parameter< int >::type new_m(new_mSEXP);
    Rcpp::traits::input_parameter< int >::type new_nu(new_nuSEXP);
    Rcpp::traits::input_parameter< int >::type new_kfac(new_kfacSEXP);
    Rcpp::traits::input_parameter< int >::type new_nmissing(new_nmissingSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type new_xmissroot(new_xmissrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_bistart(new_bistartSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_vartyperoot(new_vartyperootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_zroot(new_zrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_beta(new_betaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_vroot(new_vrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_lambda(new_lambdaSEXP);
    Rcpp::traits::input_parameter< int >::type new_type(new_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_bart_y1(new_xroot, new_yroot, new_nd, new_burn, new_m, new_nu, new_kfac, new_nmissing, new_xmissroot, new_bistart, new_vartyperoot, new_zroot, new_beta, new_vroot, new_lambda, new_type));
    return rcpp_result_gen;
END_RCPP
}
// cpp_bart
NumericVector cpp_bart(NumericVector new_xroot, NumericVector new_yroot, int new_nd, int new_burn, int new_m, int new_nu, int new_kfac, int new_nmissing, IntegerVector new_xmissroot, int new_bistart, NumericVector new_vartyperoot, NumericVector new_zroot, NumericVector new_lambda, int new_type);
RcppExport SEXP bartpkg1_cpp_bart(SEXP new_xrootSEXP, SEXP new_yrootSEXP, SEXP new_ndSEXP, SEXP new_burnSEXP, SEXP new_mSEXP, SEXP new_nuSEXP, SEXP new_kfacSEXP, SEXP new_nmissingSEXP, SEXP new_xmissrootSEXP, SEXP new_bistartSEXP, SEXP new_vartyperootSEXP, SEXP new_zrootSEXP, SEXP new_lambdaSEXP, SEXP new_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type new_xroot(new_xrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_yroot(new_yrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_nd(new_ndSEXP);
    Rcpp::traits::input_parameter< int >::type new_burn(new_burnSEXP);
    Rcpp::traits::input_parameter< int >::type new_m(new_mSEXP);
    Rcpp::traits::input_parameter< int >::type new_nu(new_nuSEXP);
    Rcpp::traits::input_parameter< int >::type new_kfac(new_kfacSEXP);
    Rcpp::traits::input_parameter< int >::type new_nmissing(new_nmissingSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type new_xmissroot(new_xmissrootSEXP);
    Rcpp::traits::input_parameter< int >::type new_bistart(new_bistartSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_vartyperoot(new_vartyperootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_zroot(new_zrootSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type new_lambda(new_lambdaSEXP);
    Rcpp::traits::input_parameter< int >::type new_type(new_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_bart(new_xroot, new_yroot, new_nd, new_burn, new_m, new_nu, new_kfac, new_nmissing, new_xmissroot, new_bistart, new_vartyperoot, new_zroot, new_lambda, new_type));
    return rcpp_result_gen;
END_RCPP
}
