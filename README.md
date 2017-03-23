
<!-- README.md is generated from README.Rmd. Please edit that file -->
Description of the package
==========================

This program is used for imputing missing covariates by the 'sequential BART' approach. Sequential BART is a flexible Bayesian nonparametric approach to impute the missing covariates which involves factoring the joint distribution of the covariates with missingness into a set of sequential conditionals and applying Bayesian additive regression trees (BART) to model each of these univariate conditionals. Package provides a function, serBARTfunc(), which computes and returns the imputed values.

Installation
============

devtools::install\_github("mjdaniels/SequentialBART")

Main components of the package
==============================

The pacakge provides a function, seqBART(), to run the sequential BART model to find the missing covariates. The function takes as arguments 1. X, Covariates having the missing values.

1.  Y, Response Variable.

2.  Datatype, representing the type of covariate, continuous or binary,

3.  Type, representing the type of missingness of the covaraites. It can take 3 values: type=0 represents no response. If the response is continuous, use type=1 ( linear regression used for inference regression model), else if it is binary, use type=2 (logistic regression used for inference regression model).

Rest of the arguments are standard arguments for BART. Defaults are provided.

Example
=======

sbart::seqBART(xx=Xcovariates, yy=Response, datatype=datatypeValues, type=1)
