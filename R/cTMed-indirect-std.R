#' Standardized Indirect Effect of X on Y Through M
#' Over a Specific Time Interval
#'
#' This function computes the standardized indirect effect
#' of the independent variable \eqn{X}
#' on the dependent variable \eqn{Y}
#' through mediator variables \eqn{\mathbf{m}}
#' over a specific time interval \eqn{\Delta t}
#' using the first-order stochastic differential equation model's
#' drift matrix \eqn{\boldsymbol{\Phi}}
#' and process noise covariance matrix \eqn{\boldsymbol{\Sigma}}.
#'
#' @details The standardized indirect effect
#'   of the independent variable \eqn{X}
#'   on the dependent variable \eqn{Y}
#'   relative to some mediator variables \eqn{\mathbf{m}}
#'   over a specific time interval \eqn{\Delta t}
#'   is given by
#'   \deqn{
#'     \mathrm{Indirect}^{\ast}_{{\Delta t}_{i, j}}
#'     =
#'     \mathrm{Total}^{\ast}_{{\Delta t}_{i, j}} -
#'     \mathrm{Direct}^{\ast}_{{\Delta t}_{i, j}}
#'   }
#'   where
#'   \eqn{\mathrm{Total}^{\ast}_{\Delta t}} and
#'   \eqn{\mathrm{Direct}^{\ast}_{\Delta t}}
#'   are standardized total and direct effects
#'   for time interval \eqn{\Delta t}.
#'
#' @author Ivan Jacob Agaloos Pesigan
#'
#' @param sigma Numeric matrix.
#'   The process noise covariance matrix (\eqn{\boldsymbol{\Sigma}}).
#' @inheritParams Indirect
#' @inherit Indirect references
#'
#' @return Returns an object
#'   of class `ctmedeffect` which is a list with the following elements:
#'   \describe{
#'     \item{call}{Function call.}
#'     \item{args}{Function arguments.}
#'     \item{fun}{Function used ("IndirectStd").}
#'     \item{output}{The standardized indirect effect.}
#'   }
#'
#' @examples
#' phi <- matrix(
#'   data = c(
#'     -0.357, 0.771, -0.450,
#'     0.0, -0.511, 0.729,
#'     0, 0, -0.693
#'   ),
#'   nrow = 3
#' )
#' colnames(phi) <- rownames(phi) <- c("x", "m", "y")
#' sigma <- matrix(
#'   data = c(
#'     0.24455556, 0.02201587, -0.05004762,
#'     0.02201587, 0.07067800, 0.01539456,
#'     -0.05004762, 0.01539456, 0.07553061
#'   ),
#'   nrow = 3
#' )
#' delta_t <- 1
#' IndirectStd(
#'   phi = phi,
#'   sigma = sigma,
#'   delta_t = delta_t,
#'   from = "x",
#'   to = "y",
#'   med = "m"
#' )
#'
#' @family Continuous Time Mediation Functions
#' @keywords cTMed effects
#' @export
IndirectStd <- function(phi,
                        sigma,
                        delta_t,
                        from,
                        to,
                        med) {
  idx <- rownames(phi)
  stopifnot(
    idx == colnames(phi),
    length(from) == 1,
    length(to) == 1,
    from %in% idx,
    to %in% idx
  )
  for (i in seq_len(length(med))) {
    stopifnot(
      med[i] %in% idx
    )
  }
  args <- list(
    phi = phi,
    sigma = sigma,
    delta_t = delta_t,
    from = from,
    to = to,
    med = med
  )
  output <- .IndirectStd(
    phi = phi,
    sigma = sigma,
    delta_t = delta_t,
    from = which(idx == from),
    to = which(idx == to),
    med = sapply(
      X = med,
      FUN = function(x,
                     idx) {
        return(
          which(idx == x)
        )
      },
      idx = idx
    )
  )
  out <- list(
    call = match.call(),
    args = args,
    fun = "IndirectStd",
    output = output
  )
  class(out) <- c(
    "ctmedeffect",
    class(out)
  )
  return(out)
}
