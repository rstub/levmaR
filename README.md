
<!-- README.md is generated from README.Rmd. Please edit that file -->

[![Travis build
status](https://travis-ci.org/rstub/levmaR.svg?branch=master)](https://travis-ci.org/rstub/levmaR)
[![AppVeyor build
status](https://ci.appveyor.com/api/projects/status/github/rstub/levmaR?branch=master&svg=true)](https://ci.appveyor.com/project/rstub/levmaR)

# levmaR

The goal of levmaR is to provide an interface for the
Levenberg-Marquardt optimization algorithm provided by the [levmar
library](http://users.ics.forth.gr/~lourakis/levmar/).

## Installation

You can install the released version of levmaR from GitHub with:

``` r
remotes::install_github("rstub/levmaR")
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(levmaR)
test_levmar()
#> Optimum found:   1.00000289e+00  1.99999760e+00
```
