#' Plot Beta Confidence Intervals
#'
#' @author Ivan Jacob Agaloos Pesigan
#'
#' @param object R object.
#'   Output of any of the following functions:
#'   [DeltaBeta()],
#'   [MCBeta()], and
#'   [PosteriorBeta()].
#' @param alpha Numeric.
#'   Significance level.
#' @param col Character vector.
#'   Optional argument.
#'   Character vector of colors.
#' @param type Charater string.
#'   Confidence interval type, that is,
#'   `type = "pc"` for percentile;
#'   `type = "bc"` for bias corrected.
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
#' vcov_phi_vec <- matrix(
#'   data = c(
#'     0.002704274, -0.001475275, 0.000949122,
#'     -0.001619422, 0.000885122, -0.000569404,
#'     0.00085493, -0.000465824, 0.000297815,
#'     -0.001475275, 0.004428442, -0.002642303,
#'     0.000980573, -0.00271817, 0.001618805,
#'     -0.000586921, 0.001478421, -0.000871547,
#'     0.000949122, -0.002642303, 0.006402668,
#'     -0.000697798, 0.001813471, -0.004043138,
#'     0.000463086, -0.001120949, 0.002271711,
#'     -0.001619422, 0.000980573, -0.000697798,
#'     0.002079286, -0.001152501, 0.000753,
#'     -0.001528701, 0.000820587, -0.000517524,
#'     0.000885122, -0.00271817, 0.001813471,
#'     -0.001152501, 0.00342605, -0.002075005,
#'     0.000899165, -0.002532849, 0.001475579,
#'     -0.000569404, 0.001618805, -0.004043138,
#'     0.000753, -0.002075005, 0.004984032,
#'     -0.000622255, 0.001634917, -0.003705661,
#'     0.00085493, -0.000586921, 0.000463086,
#'     -0.001528701, 0.000899165, -0.000622255,
#'     0.002060076, -0.001096684, 0.000686386,
#'     -0.000465824, 0.001478421, -0.001120949,
#'     0.000820587, -0.002532849, 0.001634917,
#'     -0.001096684, 0.003328692, -0.001926088,
#'     0.000297815, -0.000871547, 0.002271711,
#'     -0.000517524, 0.001475579, -0.003705661,
#'     0.000686386, -0.001926088, 0.004726235
#'   ),
#'   nrow = 9
#' )
#'
#' # Range of time intervals ---------------------------------------------------
#' beta <- DeltaBeta(
#'   phi = phi,
#'   vcov_phi_vec = vcov_phi_vec,
#'   delta_t = 1:5
#' )
#' plot(beta)
#'
#' @family Continuous Time Mediation Functions
#' @keywords cTMed plot
#' @noRd
# nolint start: cyclocomp_linter
.PlotBetaCI <- function(object,
                        alpha = 0.05,
                        col = NULL,
                        type = "pc") {
  stopifnot(
    type %in% c("pc", "bc")
  )
  if (length(object$output) == 1) {
    stop(
      paste0(
        "The input argument \'object\' only has a single `delta_t` value.",
        "\n",
        "Not suitable for plotting.",
        "\n"
      )
    )
  }
  stopifnot(length(alpha) == 1)
  stopifnot(
    alpha > 0 && alpha < 1
  )
  if (object$args$method == "mc") {
    ylab <- "Estimate"
    method <- "Monte Carlo Method"
  }
  if (object$args$method == "posterior") {
    ylab <- "Posterior"
    method <- "Posterior"
  }
  if (object$args$method == "delta") {
    ylab <- "Estimate"
    method <- "Delta Method"
  }
  if (object$args$method == "boot") {
    ylab <- "Estimate"
    if (type == "pc") {
      method <- "PC Bootstrap Method"
    }
    if (type == "bc") {
      method <- "BC Bootstrap Method"
    }
  }
  if (object$args$method %in% c("mc", "posterior")) {
    ci <- .MCCI(
      object = object,
      alpha = alpha
    )
    ci <- do.call(
      what = "rbind",
      args = ci
    )
    colnames(ci) <- c(
      "interval",
      "est",
      "se",
      "R",
      "ll",
      "ul"
    )
  }
  if (object$args$method == "boot") {
    ci <- .BootCI(
      object = object,
      alpha = alpha,
      type = type
    )
    ci <- do.call(
      what = "rbind",
      args = ci
    )
    colnames(ci) <- c(
      "interval",
      "est",
      "se",
      "R",
      "ll",
      "ul"
    )
  }
  if (object$args$method == "delta") {
    ci <- .DeltaCI(
      object = object,
      alpha = alpha
    )
    ci <- do.call(
      what = "rbind",
      args = ci
    )
    colnames(ci) <- c(
      "interval",
      "est",
      "se",
      "z",
      "p",
      "ll",
      "ul"
    )
  }
  effect <- rownames(ci)
  ci <- as.data.frame(
    ci
  )
  ci$effect <- effect
  rownames(ci) <- NULL
  effect <- unique(
    ci$effect
  )
  if (is.null(col)) {
    col <- grDevices::rainbow(length(effect))
  }
  foo <- function(effect,
                  col,
                  ci) {
    ci <- ci[which(ci$effect == effect), ]
    graphics::plot.default(
      x = 0,
      y = 0,
      xlim = range(ci$interval),
      ylim = range(c(ci$est, ci$ll, ci$ul)),
      type = "n",
      xlab = "Time Interval",
      ylab = ylab,
      main = paste0(
        (1 - alpha) * 100,
        "% CI for the Total Effect ",
        effect,
        " (",
        method,
        ")"
      )
    )
    for (i in seq_along(ci$interval)) {
      if (!(ci$ll[i] <= 0 && 0 <= ci$ul[i])) {
        graphics::segments(
          x0 = ci$interval[i],
          y0 = ci$ll[i],
          x1 = ci$interval[i],
          y1 = ci$ul[i],
          col = col,
          lty = 3,
          lwd = 1
        )
      }
    }
    graphics::abline(
      h = 0
    )
    graphics::lines(
      x = ci$interval,
      y = ci$est,
      type = "l",
      col = col,
      lty = 1,
      lwd = 2
    )
    graphics::lines(
      x = ci$interval,
      y = ci$ll,
      type = "l",
      col = col,
      lty = 3,
      lwd = 2
    )
    graphics::lines(
      x = ci$interval,
      y = ci$ul,
      type = "l",
      col = col,
      lty = 3,
      lwd = 2
    )
  }
  for (i in seq_along(effect)) {
    foo(
      effect = effect[i],
      col = col[i],
      ci = ci
    )
  }
}
# nolint end
