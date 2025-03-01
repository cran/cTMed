## ---- test-cTMed-direct-std
lapply(
  X = 1,
  FUN = function(i,
                 text,
                 tol) {
    message(text)
    testthat::test_that(
      paste(text, "DirectStd"),
      {
        testthat::skip_on_cran()
        answer <- -0.3429
        phi <- matrix(
          data = c(
            -0.357, 0.771, -0.450,
            0.0, -0.511, 0.729,
            0, 0, -0.693
          ),
          nrow = 3
        )
        colnames(phi) <- rownames(phi) <- c("x", "m", "y")
        sigma <- matrix(
          data = c(
            0.24455556, 0.02201587, -0.05004762,
            0.02201587, 0.07067800, 0.01539456,
            -0.05004762, 0.01539456, 0.07553061
          ),
          nrow = 3
        )
        delta_t <- 2
        testthat::expect_true(
          (
            answer - DirectStd(
              phi = phi,
              sigma = sigma,
              delta_t = delta_t,
              from = "x",
              to = "y",
              med = "m"
            )$output
          ) <= tol
        )
      }
    )
    testthat::test_that(
      paste(text, "MedStd"),
      {
        testthat::skip_on_cran()
        answer <- -0.3429
        phi <- matrix(
          data = c(
            -0.357, 0.771, -0.450,
            0.0, -0.511, 0.729,
            0, 0, -0.693
          ),
          nrow = 3
        )
        colnames(phi) <- rownames(phi) <- c("x", "m", "y")
        sigma <- matrix(
          data = c(
            0.24455556, 0.02201587, -0.05004762,
            0.02201587, 0.07067800, 0.01539456,
            -0.05004762, 0.01539456, 0.07553061
          ),
          nrow = 3
        )
        delta_t <- 2
        testthat::expect_true(
          (
            answer - MedStd(
              phi = phi,
              sigma = sigma,
              delta_t = delta_t,
              from = "x",
              to = "y",
              med = "m"
            )$output[, "direct"]
          ) <= tol
        )
      }
    )
    testthat::test_that(
      paste(text, "plot error"),
      {
        testthat::skip_on_cran()
        answer <- -0.3429
        phi <- matrix(
          data = c(
            -0.357, 0.771, -0.450,
            0.0, -0.511, 0.729,
            0, 0, -0.693
          ),
          nrow = 3
        )
        colnames(phi) <- rownames(phi) <- c("x", "m", "y")
        sigma <- matrix(
          data = c(
            0.24455556, 0.02201587, -0.05004762,
            0.02201587, 0.07067800, 0.01539456,
            -0.05004762, 0.01539456, 0.07553061
          ),
          nrow = 3
        )
        delta_t <- 2
        med <- MedStd(
          phi = phi,
          sigma = sigma,
          delta_t = 1:5,
          from = "x",
          to = "y",
          med = "m"
        )
        print(med)
        summary(med)
        plot(med)
        plot(med, col = 1:3)
        med <- MedStd(
          phi = phi,
          sigma = sigma,
          delta_t = 1,
          from = "x",
          to = "y",
          med = "m"
        )
        print(med)
        summary(med)
        testthat::expect_error(
          plot(med)
        )
        direct <- DirectStd(
          phi = phi,
          sigma = sigma,
          delta_t = delta_t,
          from = "x",
          to = "y",
          med = "m"
        )
        print(direct)
      }
    )
  },
  text = "test-cTMed-direct-std",
  tol = 0.01
)
