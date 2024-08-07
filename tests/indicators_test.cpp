/**
 * @file indicators_test.cpp
 * @author Nanubala Gnana Sai
 *
 * Test file for all the indicators: Epsilon, IGD+, IGD.
 *
 * ensmallen is free software; you may redistribute it and/or modify it under
 * the terms of the 3-clause BSD license.  You should have received a copy of
 * the 3-clause BSD license along with ensmallen.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */

#include <ensmallen.hpp>
#include "catch.hpp"

using namespace ens;
using namespace ens::test;

/**
 * Calculates the Epsilon performance indicator for the pair of fronts.
 * Tests for data of type double.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/285
 * for more.
 */
TEST_CASE("EpsilonDoubleTest", "[IndicatorsTest]")
{
  arma::cube referenceFront(2, 1, 3);
  double tol = 1e-10;
  referenceFront.slice(0) = arma::vec{0.01010101, 0.89949622};
  referenceFront.slice(1) = arma::vec{0.02020202, 0.85786619};
  referenceFront.slice(2) = arma::vec{0.03030303, 0.82592234};
  arma::cube front = referenceFront * 1.1;
  double eps =  Epsilon::Evaluate(front, referenceFront);

  REQUIRE(eps == Approx(1.1).margin(tol));
}

/**
 * Calculates the Epsilon performance indicator for the pair of fronts.
 * Tests for data of type float.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/285
 * for more.
 */
TEST_CASE("EpsilonFloatTest", "[IndicatorsTest]")
{
  arma::fcube referenceFront(2, 1, 3);
  float tol = 1e-10;
  referenceFront.slice(0) = arma::fvec{0.01010101f, 0.89949622f};
  referenceFront.slice(1) = arma::fvec{0.02020202f, 0.85786619f};
  referenceFront.slice(2) = arma::fvec{0.03030303f, 0.82592234f};
  arma::fcube front = referenceFront * 1.1;
  double eps =  Epsilon::Evaluate(front, referenceFront);

  REQUIRE(eps == Approx(1.1).margin(tol));
}

/**
 * Calculates the IGD performance indicator for the pair of fronts.
 * Tests for data of type double.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/
 * for more.
 */
TEST_CASE("IGDDoubleTest", "[IndicatorsTest]")
{
  arma::cube referenceFront(2, 1, 3);
  double tol = 1e-10;
  referenceFront.slice(0) = arma::vec{0.11111111, 0.75039705};
  referenceFront.slice(1) = arma::vec{0.22222222, 0.60558677};
  referenceFront.slice(2) = arma::vec{0.33333333, 0.49446993};
  arma::cube front = referenceFront * 1.1;
  double igd = IGD::Evaluate(front, referenceFront, 1);
  REQUIRE(igd == Approx(0.06666608265617857).margin(tol));
}

/**
 * Calculates the IGD performance indicator for the pair of fronts.
 * Tests for data of type float.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/399
 * for more.
 */
TEST_CASE("IGDFloatTest", "[IndicatorsTest]")
{
  arma::fcube referenceFront(2, 1, 3);
  float tol = 1e-10;
  referenceFront.slice(0) = arma::fvec{0.11111111f, 0.75039705f};
  referenceFront.slice(1) = arma::fvec{0.22222222f, 0.60558677f};
  referenceFront.slice(2) = arma::fvec{0.33333333f, 0.49446993f};
  arma::fcube front = referenceFront * 1.1;
  float igd = IGD::Evaluate(front, referenceFront, 1);

  REQUIRE(igd == Approx(0.06666608265617857).margin(tol));
}

/**
 * Calculates the IGD+ performance indicator for the pair of fronts.
 * Tests for data of type double.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/399
 * for more.
 */
TEST_CASE("IGDPlusDoubleTest", "[IndicatorsTest]")
{
  arma::cube referenceFront(2, 1, 3);
  double tol = 1e-10;
  referenceFront.slice(0) = arma::vec{0.01010101, 0.89949622};
  referenceFront.slice(1) = arma::vec{0.02020202, 0.85786619};
  referenceFront.slice(2) = arma::vec{0.03030303, 0.82592234};
  arma::cube front = referenceFront * 1.1;
  double igdPlus = IGDPlus::Evaluate(front, referenceFront);

  REQUIRE(igdPlus == Approx(0.05329735411078149).margin(tol));
}

/**
 * Calculates the IGD+ performance indicator for the pair of fronts.
 * Tests for data of type float.
 * The reference numerical results have been taken from hand calculated values.
 * Refer the IPynb notebook in https://github.com/mlpack/ensmallen/pull/285
 * for more.
 */
TEST_CASE("IGDPlusFloatTest", "[IndicatorsTest]")
{
  arma::fcube referenceFront(2, 1, 3);
  float tol = 1e-10;
  referenceFront.slice(0) = arma::fvec{0.01010101f, 0.89949622f};
  referenceFront.slice(1) = arma::fvec{0.02020202f, 0.85786619f};
  referenceFront.slice(2) = arma::fvec{0.03030303f, 0.82592234f};
  arma::fcube front = referenceFront * 1.1;
  float igdPlus = IGDPlus::Evaluate(front, referenceFront);

  REQUIRE(igdPlus == Approx(0.05329735411078149).margin(tol));
}
