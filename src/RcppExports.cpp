// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// DirectStd
double DirectStd(const arma::mat& phi, const arma::mat& sigma, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_DirectStd(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(DirectStd(phi, sigma, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// Direct
double Direct(const arma::mat& phi, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_Direct(SEXP phiSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(Direct(phi, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// IndirectCentrals
arma::mat IndirectCentrals(const arma::mat& phi, const arma::vec& delta_t);
RcppExport SEXP _cTMed_IndirectCentrals(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(IndirectCentrals(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// IndirectCentralVec
Rcpp::NumericVector IndirectCentralVec(const arma::vec& phi_vec, const double& delta_t);
RcppExport SEXP _cTMed_IndirectCentralVec(SEXP phi_vecSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type phi_vec(phi_vecSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(IndirectCentralVec(phi_vec, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// IndirectCentral
Rcpp::NumericVector IndirectCentral(const arma::mat& phi, const double& delta_t);
RcppExport SEXP _cTMed_IndirectCentral(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(IndirectCentral(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// IndirectStd
double IndirectStd(const arma::mat& phi, const arma::mat& sigma, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_IndirectStd(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(IndirectStd(phi, sigma, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// Indirect
double Indirect(const arma::mat& phi, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_Indirect(SEXP phiSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(Indirect(phi, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// MCPhiI
arma::mat MCPhiI(const arma::mat& phi, const arma::mat& vcov_phi_vec_l, bool test_phi);
RcppExport SEXP _cTMed_MCPhiI(SEXP phiSEXP, SEXP vcov_phi_vec_lSEXP, SEXP test_phiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type vcov_phi_vec_l(vcov_phi_vec_lSEXP);
    Rcpp::traits::input_parameter< bool >::type test_phi(test_phiSEXP);
    rcpp_result_gen = Rcpp::wrap(MCPhiI(phi, vcov_phi_vec_l, test_phi));
    return rcpp_result_gen;
END_RCPP
}
// MCPhiSigmaI
Rcpp::List MCPhiSigmaI(const arma::vec& theta, const arma::mat& vcov_theta, bool test_phi);
RcppExport SEXP _cTMed_MCPhiSigmaI(SEXP thetaSEXP, SEXP vcov_thetaSEXP, SEXP test_phiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type vcov_theta(vcov_thetaSEXP);
    Rcpp::traits::input_parameter< bool >::type test_phi(test_phiSEXP);
    rcpp_result_gen = Rcpp::wrap(MCPhiSigmaI(theta, vcov_theta, test_phi));
    return rcpp_result_gen;
END_RCPP
}
// MCPhiSigma
Rcpp::List MCPhiSigma(const arma::vec& theta, const arma::mat& vcov_theta, const arma::uword& R, bool test_phi);
RcppExport SEXP _cTMed_MCPhiSigma(SEXP thetaSEXP, SEXP vcov_thetaSEXP, SEXP RSEXP, SEXP test_phiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type vcov_theta(vcov_thetaSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type R(RSEXP);
    Rcpp::traits::input_parameter< bool >::type test_phi(test_phiSEXP);
    rcpp_result_gen = Rcpp::wrap(MCPhiSigma(theta, vcov_theta, R, test_phi));
    return rcpp_result_gen;
END_RCPP
}
// MCPhi
Rcpp::List MCPhi(const arma::mat& phi, const arma::mat& vcov_phi_vec_l, const arma::uword& R, bool test_phi);
RcppExport SEXP _cTMed_MCPhi(SEXP phiSEXP, SEXP vcov_phi_vec_lSEXP, SEXP RSEXP, SEXP test_phiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type vcov_phi_vec_l(vcov_phi_vec_lSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type R(RSEXP);
    Rcpp::traits::input_parameter< bool >::type test_phi(test_phiSEXP);
    rcpp_result_gen = Rcpp::wrap(MCPhi(phi, vcov_phi_vec_l, R, test_phi));
    return rcpp_result_gen;
END_RCPP
}
// Meds
arma::mat Meds(const arma::mat& phi, const arma::vec& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_Meds(SEXP phiSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(Meds(phi, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// MedStds
arma::mat MedStds(const arma::mat& phi, const arma::mat& sigma, const arma::vec& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_MedStds(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(MedStds(phi, sigma, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// MedStdVec
Rcpp::NumericVector MedStdVec(const arma::vec& v, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_MedStdVec(SEXP vSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type v(vSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(MedStdVec(v, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// MedStd
Rcpp::NumericVector MedStd(const arma::mat& phi, const arma::mat& sigma, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_MedStd(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(MedStd(phi, sigma, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// MedVec
Rcpp::NumericVector MedVec(const arma::vec& phi_vec, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_MedVec(SEXP phi_vecSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type phi_vec(phi_vecSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(MedVec(phi_vec, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// Med
Rcpp::NumericVector Med(const arma::mat& phi, const double& delta_t, const arma::uword& from, const arma::uword& to, const arma::vec& med);
RcppExport SEXP _cTMed_Med(SEXP phiSEXP, SEXP delta_tSEXP, SEXP fromSEXP, SEXP toSEXP, SEXP medSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type from(fromSEXP);
    Rcpp::traits::input_parameter< const arma::uword& >::type to(toSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type med(medSEXP);
    rcpp_result_gen = Rcpp::wrap(Med(phi, delta_t, from, to, med));
    return rcpp_result_gen;
END_RCPP
}
// TestPhi
bool TestPhi(const arma::mat& phi);
RcppExport SEXP _cTMed_TestPhi(SEXP phiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    rcpp_result_gen = Rcpp::wrap(TestPhi(phi));
    return rcpp_result_gen;
END_RCPP
}
// TestStable
bool TestStable(const arma::mat& x);
RcppExport SEXP _cTMed_TestStable(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(TestStable(x));
    return rcpp_result_gen;
END_RCPP
}
// TotalCentrals
arma::mat TotalCentrals(const arma::mat& phi, const arma::vec& delta_t);
RcppExport SEXP _cTMed_TotalCentrals(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalCentrals(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalCentralVec
Rcpp::NumericVector TotalCentralVec(const arma::vec& phi_vec, const double& delta_t);
RcppExport SEXP _cTMed_TotalCentralVec(SEXP phi_vecSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type phi_vec(phi_vecSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalCentralVec(phi_vec, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalCentral
Rcpp::NumericVector TotalCentral(const arma::mat& phi, const double& delta_t);
RcppExport SEXP _cTMed_TotalCentral(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalCentral(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalDeltaT
Rcpp::NumericVector TotalDeltaT(const arma::mat& phi, const double& delta_t);
RcppExport SEXP _cTMed_TotalDeltaT(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalDeltaT(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalStdDeltaT
Rcpp::NumericVector TotalStdDeltaT(const arma::mat& phi, const arma::mat& sigma, const double& delta_t);
RcppExport SEXP _cTMed_TotalStdDeltaT(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalStdDeltaT(phi, sigma, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalStdVec
arma::vec TotalStdVec(const arma::vec& v, const double& delta_t);
RcppExport SEXP _cTMed_TotalStdVec(SEXP vSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type v(vSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalStdVec(v, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalStd
arma::mat TotalStd(const arma::mat& phi, const arma::mat& sigma, const double& delta_t);
RcppExport SEXP _cTMed_TotalStd(SEXP phiSEXP, SEXP sigmaSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalStd(phi, sigma, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// TotalVec
arma::vec TotalVec(const arma::vec& phi_vec, const double& delta_t);
RcppExport SEXP _cTMed_TotalVec(SEXP phi_vecSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type phi_vec(phi_vecSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(TotalVec(phi_vec, delta_t));
    return rcpp_result_gen;
END_RCPP
}
// Total
arma::mat Total(const arma::mat& phi, const double& delta_t);
RcppExport SEXP _cTMed_Total(SEXP phiSEXP, SEXP delta_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type phi(phiSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta_t(delta_tSEXP);
    rcpp_result_gen = Rcpp::wrap(Total(phi, delta_t));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cTMed_DirectStd", (DL_FUNC) &_cTMed_DirectStd, 6},
    {"_cTMed_Direct", (DL_FUNC) &_cTMed_Direct, 5},
    {"_cTMed_IndirectCentrals", (DL_FUNC) &_cTMed_IndirectCentrals, 2},
    {"_cTMed_IndirectCentralVec", (DL_FUNC) &_cTMed_IndirectCentralVec, 2},
    {"_cTMed_IndirectCentral", (DL_FUNC) &_cTMed_IndirectCentral, 2},
    {"_cTMed_IndirectStd", (DL_FUNC) &_cTMed_IndirectStd, 6},
    {"_cTMed_Indirect", (DL_FUNC) &_cTMed_Indirect, 5},
    {"_cTMed_MCPhiI", (DL_FUNC) &_cTMed_MCPhiI, 3},
    {"_cTMed_MCPhiSigmaI", (DL_FUNC) &_cTMed_MCPhiSigmaI, 3},
    {"_cTMed_MCPhiSigma", (DL_FUNC) &_cTMed_MCPhiSigma, 4},
    {"_cTMed_MCPhi", (DL_FUNC) &_cTMed_MCPhi, 4},
    {"_cTMed_Meds", (DL_FUNC) &_cTMed_Meds, 5},
    {"_cTMed_MedStds", (DL_FUNC) &_cTMed_MedStds, 6},
    {"_cTMed_MedStdVec", (DL_FUNC) &_cTMed_MedStdVec, 5},
    {"_cTMed_MedStd", (DL_FUNC) &_cTMed_MedStd, 6},
    {"_cTMed_MedVec", (DL_FUNC) &_cTMed_MedVec, 5},
    {"_cTMed_Med", (DL_FUNC) &_cTMed_Med, 5},
    {"_cTMed_TestPhi", (DL_FUNC) &_cTMed_TestPhi, 1},
    {"_cTMed_TestStable", (DL_FUNC) &_cTMed_TestStable, 1},
    {"_cTMed_TotalCentrals", (DL_FUNC) &_cTMed_TotalCentrals, 2},
    {"_cTMed_TotalCentralVec", (DL_FUNC) &_cTMed_TotalCentralVec, 2},
    {"_cTMed_TotalCentral", (DL_FUNC) &_cTMed_TotalCentral, 2},
    {"_cTMed_TotalDeltaT", (DL_FUNC) &_cTMed_TotalDeltaT, 2},
    {"_cTMed_TotalStdDeltaT", (DL_FUNC) &_cTMed_TotalStdDeltaT, 3},
    {"_cTMed_TotalStdVec", (DL_FUNC) &_cTMed_TotalStdVec, 2},
    {"_cTMed_TotalStd", (DL_FUNC) &_cTMed_TotalStd, 3},
    {"_cTMed_TotalVec", (DL_FUNC) &_cTMed_TotalVec, 2},
    {"_cTMed_Total", (DL_FUNC) &_cTMed_Total, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_cTMed(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
