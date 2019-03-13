#include <levmar.h>
#include <Rcpp.h>

void fun(double *p, double *x, int m, int n, void *data_){
  double a = p[0];
  double b = p[1];

  double *data = (double *) data_;

  for(int i = 0; i < n; i++){
      x[i] = log(a*data[i]+b);
  }
}

void jacFun(double *p, double *jac, int m, int n, void *data_){
  double a = p[0]; 
  double b = p[1];

  double *data = (double *) data_;

  int k, l;
  for(l=k=0; l < n; l++){
    jac[k++] = data[l]/(a*data[l]+b);
    jac[k++] = 1/(a*data[l]+b);
  }

}

// [[Rcpp::export]]
void test_levmar(){
  int m = 2; // # of parameters
  int n = 40; // # of observations

  double a = 1.0;
  double b = 2.0;

  double data[] = {0.119047619047619, 0.238095238095238,    0.357142857142857, 0.476190476190476,   0.595238095238095, 0.714285714285714, 1.07142857142857, 1.42857142857143,
    0.119047619047619   ,0.238095238095238, 0.357142857142857, 0.476190476190476, 0.595238095238095, 0.714285714285714  ,1.07142857142857, 1.42857142857143 ,
    0.119047619047619,  0.238095238095238,  0.357142857142857,  0.476190476190476,  0.595238095238095,  0.714285714285714,  1.07142857142857,   1.42857142857143,
    0.119047619047619,  0.238095238095238,  0.357142857142857,  0.476190476190476   ,0.595238095238095, 0.714285714285714,  1.07142857142857,   1.42857142857143,
    0.119047619047619,  0.238095238095238   ,0.357142857142857, 0.476190476190476,  0.595238095238095,  0.714285714285714,  1.07142857142857,   1.42857142857143};

  double popti[2];
  popti[0] = a; popti[1] = b;

  double x[40];
  fun(popti, x, m, n, (void *) data);

  // algorithm parameters
  double opts[LM_OPTS_SZ], info[LM_INFO_SZ];
  opts[0]=LM_INIT_MU;
  // stopping thresholds for
  opts[1]=1E-10;       // ||J^T e||_inf
  opts[2]=1E-10;       // ||Dp||_2
  opts[3]=1E-10;       // ||e||_2
  opts[4]= LM_DIFF_DELTA; // finite difference if used

  double p[2];
  p[0] = 3.0; p[1] = 1.0;

  dlevmar_der(fun,jacFun,p,x,m,n,100,opts,info,NULL,NULL,(void *) data);

  Rcpp::Rcout << "Optimum found:" << std::scientific << std::setprecision(8)<< "\t"<< p[0]<< "\t" << p[1]<< std::endl;
 }
