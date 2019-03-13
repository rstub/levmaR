context("test-default")

test_that("test works", {
  expect_output(test_levmar(), "Optimum found.*00000289e.*99999760e")
})
