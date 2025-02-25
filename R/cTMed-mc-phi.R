#' Generate Random Drift Matrices
#' Using the Monte Carlo Method
#'
#' This function generates random
#' drift matrices \eqn{\boldsymbol{\Phi}}
#' using the Monte Carlo method.
#'
#' @details
#' ## Monte Carlo Method
#'   Let \eqn{\boldsymbol{\theta}} be
#'   \eqn{\mathrm{vec} \left( \boldsymbol{\Phi} \right)},
#'   that is,
#'   the elements of the \eqn{\boldsymbol{\Phi}} matrix
#'   in vector form sorted column-wise.
#'   Let \eqn{\hat{\boldsymbol{\theta}}} be
#'   \eqn{\mathrm{vec} \left( \hat{\boldsymbol{\Phi}} \right)}.
#'   Based on the asymptotic properties of maximum likelihood estimators,
#'   we can assume that estimators are normally distributed
#'   around the population parameters.
#'   \deqn{
#'   	\hat{\boldsymbol{\theta}}
#'   	\sim
#'   	\mathcal{N}
#'   	\left(
#'   	\boldsymbol{\theta},
#'   	\mathbb{V} \left( \hat{\boldsymbol{\theta}} \right)
#'   	\right)
#'   }
#'   Using this distributional assumption,
#'   a sampling distribution of \eqn{\hat{\boldsymbol{\theta}}}
#'   which we refer to as \eqn{\hat{\boldsymbol{\theta}}^{\ast}}
#'   can be generated by replacing the population parameters
#'   with sample estimates,
#'   that is,
#'   \deqn{
#'   	\hat{\boldsymbol{\theta}}^{\ast}
#'   	\sim
#'   	\mathcal{N}
#'   	\left(
#'   	\hat{\boldsymbol{\theta}},
#'   	\hat{\mathbb{V}} \left( \hat{\boldsymbol{\theta}} \right)
#'   	\right) .
#'   }
#'
#' @author Ivan Jacob Agaloos Pesigan
#'
#' @inheritParams Indirect
#' @param vcov_phi_vec Numeric matrix.
#'   The sampling variance-covariance matrix of
#'   \eqn{\mathrm{vec} \left( \boldsymbol{\Phi} \right)}.
#' @param R Positive integer.
#'   Number of replications.
#' @param test_phi Logical.
#'   If `test_phi = TRUE`,
#'   the function tests the stability
#'   of the generated drift matrix \eqn{\boldsymbol{\Phi}}.
#'   If the test returns `FALSE`,
#'   the function generates a new drift matrix \eqn{\boldsymbol{\Phi}}
#'   and runs the test recursively
#'   until the test returns `TRUE`.
#' @param ncores Positive integer.
#'   Number of cores to use.
#'   If `ncores = NULL`,
#'   use a single core.
#'   Consider using multiple cores
#'   when number of replications `R`
#'   is a large value.
#' @param seed Random seed.
#'
#' @return Returns an object
#'   of class `ctmedmc` which is a list with the following elements:
#'   \describe{
#'     \item{call}{Function call.}
#'     \item{args}{Function arguments.}
#'     \item{fun}{Function used ("MCPhi").}
#'     \item{output}{A list simulated drift matrices.}
#'   }
#'
#' @examples
#' set.seed(42)
#' phi <- matrix(
#'   data = c(
#'     -0.357, 0.771, -0.450,
#'     0.0, -0.511, 0.729,
#'     0, 0, -0.693
#'   ),
#'   nrow = 3
#' )
#' colnames(phi) <- rownames(phi) <- c("x", "m", "y")
#' MCPhi(
#'   phi = phi,
#'   vcov_phi_vec = 0.1 * diag(9),
#'   R = 100L # use a large value for R in actual research
#' )
#' phi <- matrix(
#'   data = c(
#'     -6, 5.5, 0, 0,
#'     1.25, -2.5, 5.9, -7.3,
#'     0, 0, -6, 2.5,
#'     5, 0, 0, -6
#'   ),
#'   nrow = 4
#' )
#' colnames(phi) <- rownames(phi) <- paste0("y", 1:4)
#' MCPhi(
#'   phi = phi,
#'   vcov_phi_vec = 0.1 * diag(16),
#'   R = 100L, # use a large value for R in actual research
#'   test_phi = FALSE
#' )
#'
#' @family Continuous Time Mediation Functions
#' @keywords cTMed mc
#' @export
MCPhi <- function(phi,
                  vcov_phi_vec,
                  R,
                  test_phi = TRUE,
                  ncores = NULL,
                  seed = NULL) {
  idx <- rownames(phi)
  stopifnot(
    idx == colnames(phi)
  )
  args <- list(
    phi = phi,
    vcov_phi_vec = vcov_phi_vec,
    R = R,
    test_phi = test_phi,
    ncores = ncores,
    seed = seed,
    method = "mc"
  )
  # nocov start
  par <- FALSE
  if (!is.null(ncores)) {
    ncores <- as.integer(ncores)
    if (ncores > R) {
      ncores <- R
    }
    if (ncores > 1) {
      par <- TRUE
    }
  }
  if (par) {
    os_type <- Sys.info()["sysname"]
    if (os_type == "Darwin") {
      fork <- TRUE
    } else if (os_type == "Linux") {
      fork <- TRUE
    } else {
      fork <- FALSE
    }
    if (fork) {
      if (!is.null(seed)) {
        set.seed(seed)
      }
      output <- parallel::mclapply(
        X = seq_len(R),
        FUN = function(i) {
          return(
            .MCPhiI(
              phi = phi,
              vcov_phi_vec_l = t(chol(vcov_phi_vec)),
              test_phi = test_phi
            )
          )
        },
        mc.cores = ncores
      )
    } else {
      cl <- parallel::makeCluster(ncores)
      on.exit(
        parallel::stopCluster(cl = cl)
      )
      if (!is.null(seed)) {
        parallel::clusterSetRNGStream(
          cl = cl,
          iseed = seed
        )
      }
      output <- parallel::parLapply(
        cl = cl,
        X = seq_len(R),
        fun = function(i) {
          return(
            .MCPhiI(
              phi = phi,
              vcov_phi_vec_l = t(chol(vcov_phi_vec)),
              test_phi = test_phi
            )
          )
        }
      )
    }
    # nocov end
  } else {
    if (!is.null(seed)) {
      set.seed(seed)
    }
    output <- .MCPhi(
      phi = phi,
      vcov_phi_vec_l = t(chol(vcov_phi_vec)),
      R = R,
      test_phi = test_phi
    )
  }
  output <- lapply(
    X = output,
    FUN = function(x) {
      colnames(x) <- rownames(x) <- idx
      return(x)
    }
  )
  out <- list(
    call = match.call(),
    args = args,
    fun = "MCPhi",
    output = output
  )
  class(out) <- c(
    "ctmedmcphi",
    class(out)
  )
  return(out)
}
