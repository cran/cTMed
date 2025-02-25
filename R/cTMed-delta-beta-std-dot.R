.DeltaBetaStd <- function(delta_t,
                          phi,
                          sigma,
                          vcov_theta) {
  constructor <- function(delta_t) {
    return(
      function(x) {
        return(
          .TotalStdVec(
            v = x,
            delta_t = delta_t
          )
        )
      }
    )
  }
  func <- constructor(
    delta_t = delta_t
  )
  v <- c(
    .Vec(phi),
    .Vech(sigma)
  )
  jacobian <- numDeriv::jacobian(
    func = func,
    x = v
  )
  return(
    list(
      delta_t = delta_t,
      jacobian = jacobian,
      est = func(x = v),
      vcov = jacobian %*% vcov_theta %*% t(jacobian)
    )
  )
}
