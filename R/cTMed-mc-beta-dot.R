.MCBeta <- function(phi,
                    vcov_phi_vec,
                    delta_t,
                    R,
                    test_phi = TRUE,
                    ncores = NULL,
                    seed = NULL) {
  varnames <- colnames(phi)
  x <- expand.grid(
    to = varnames,
    from = varnames
  )
  varnames <- c(
    sapply(
      X = seq_len(dim(x)[1]),
      FUN = function(i) {
        paste0("from ", x[i, 2], " to ", x[i, 1])
      }
    ),
    "interval"
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
      # generate phi
      if (!is.null(seed)) {
        set.seed(seed)
      }
      phis <- parallel::mclapply(
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
      output <- lapply(
        X = delta_t,
        FUN = function(i) {
          thetahatstar <- parallel::mclapply(
            X = phis,
            FUN = .TotalDeltaT,
            delta_t = i,
            mc.cores = ncores
          )
          thetahatstar <- do.call(
            what = "rbind",
            args = thetahatstar
          )
          colnames(thetahatstar) <- varnames
          est <- .TotalDeltaT(
            phi = phi,
            delta_t = i
          )
          names(est) <- varnames
          out <- list(
            delta_t = i,
            est = est,
            thetahatstar = thetahatstar
          )
          return(out)
        }
      )
    } else {
      # generate phi
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
      phis <- parallel::parLapply(
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
      output <- lapply(
        X = delta_t,
        FUN = function(i) {
          thetahatstar <- parallel::parLapply(
            cl = cl,
            X = phis,
            fun = .TotalDeltaT,
            delta_t = i
          )
          thetahatstar <- do.call(
            what = "rbind",
            args = thetahatstar
          )
          colnames(thetahatstar) <- varnames
          est <- .TotalDeltaT(
            phi = phi,
            delta_t = i
          )
          names(est) <- varnames
          out <- list(
            delta_t = i,
            est = est,
            thetahatstar = thetahatstar
          )
          return(out)
        }
      )
    }
    # nocov end
  } else {
    # generate phi
    if (!is.null(seed)) {
      set.seed(seed)
    }
    phis <- lapply(
      X = seq_len(R),
      FUN = function(i) {
        return(
          .MCPhiI(
            phi = phi,
            vcov_phi_vec_l = t(chol(vcov_phi_vec)),
            test_phi = test_phi
          )
        )
      }
    )
    output <- lapply(
      X = delta_t,
      FUN = function(i) {
        thetahatstar <- lapply(
          X = phis,
          FUN = .TotalDeltaT,
          delta_t = i
        )
        thetahatstar <- do.call(
          what = "rbind",
          args = thetahatstar
        )
        colnames(thetahatstar) <- varnames
        est <- .TotalDeltaT(
          phi = phi,
          delta_t = i
        )
        names(est) <- varnames
        out <- list(
          delta_t = i,
          est = est,
          thetahatstar = thetahatstar
        )
        return(out)
      }
    )
  }
  return(output)
}
