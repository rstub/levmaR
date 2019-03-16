inlineCxxPlugin <- function(...) {
    libs_dir <- system.file("lib", package="levmaR", mustWork=TRUE)
    plugin <-
        Rcpp::Rcpp.plugin.maker(
                  include.before = "#include <levmar.h>",
                  libs           = paste("-L", libs_dir, "-llevmar $(LAPACK_LIBS) $(BLAS_LIBS) $(FLIBS)"),
                  package        = "levmaR"
              )
    settings <- plugin()
    settings$env$PKG_CPPFLAGS <- "-I../inst/include"
    settings
}
