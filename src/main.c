#include <fftw3.h>
#include <stdio.h>

double A[300] = {3.66775397, 49.76066181, 12.11324707, 38.55538817, 37.20272571,
       19.27399743, 84.76525518,  6.22844954,  3.97580094, 69.36624791,
       72.69548773, 28.97589604, 11.11783842, 86.16045675, 33.40425448,
       71.13852435, 81.7051293 , 16.44891949,  1.62139638, 77.81548794,
        1.88688827, 41.33034975, 37.05346794, 83.76936405, 72.56652786,
       59.62152924, 83.43610612, 62.79398843, 27.19358458, 78.05287088,
       50.13687791, 47.04833163, 20.32709061, 60.12414957, 66.97933522,
       61.21698601, 57.08982523, 18.31012605, 24.48165612, 30.58912371,
       11.94561357,  0.62143129, 33.73985659, 75.46525903, 10.22525476,
       17.2007137 , 34.13381485, 96.24247739, 20.33422931, 98.42327916,
       57.42423907, 85.97012555, 70.8794409 , 41.48997906, 30.99973464,
       60.87559652, 22.87894719, 64.33675631, 57.40641532, 74.40201613,
       32.85729463, 64.63042122, 79.08448857, 37.58349325, 25.05868359,
       92.55980252, 51.23463586, 43.16881069, 37.51848998, 77.33473965,
       71.54364447,  1.67666816, 25.0943933 , 15.47901179, 46.47163491,
       77.24988452, 12.67618142, 99.86476386, 52.18077727, 77.85027668,
       44.1416089 , 31.19794088, 37.73676699, 17.79540937, 52.01578196,
       48.09428521, 20.21392461, 13.86133092, 23.62556915, 80.67774497,
       10.31402659, 83.75317439, 99.45921092, 18.95777392, 61.31991918,
       93.74208722, 24.76008705,  4.29049303, 48.79275993, 73.10985514,
        2.2357382 , 29.29367574, 62.11753249, 79.68577992, 87.91628212,
       66.85729056, 75.38762298, 93.16689164, 28.65104822, 73.67763737,
       88.12892165, 15.91258775, 81.30236529, 50.56505565,  8.86726931,
       71.53585482, 32.05019566, 18.02987819, 45.76775337, 18.65811835,
       79.45959467, 36.42602927, 72.39028639, 90.95046944, 97.57320212,
       51.14616834, 52.79717602, 58.226696  , 67.11430717, 14.4492806 ,
       58.46264261, 13.86174488, 57.14162337, 26.13643238, 34.89362396,
       84.75117282, 91.6061694 , 66.25208893, 55.33825768,  1.66435526,
       54.83421986, 78.19515347, 51.03713187,  6.84084889, 36.97208262,
        6.36666097, 59.00245369, 22.5933831 ,  8.06750381,  3.94328548,
       61.17212367, 14.87858662, 86.11177766, 78.90047195, 56.10995052,
       47.94019602, 96.51210518, 70.68514744, 92.75679662, 80.07348794,
       75.28597269, 39.13083328, 45.96364324, 67.62908007,  9.27863353,
       48.95380139, 36.12566219,  6.4645348 ,  3.44033205, 53.33812525,
       35.16984242, 81.27926317, 36.71123292,  4.64133328, 95.61018838,
       53.72159692,  5.74070995, 37.35464778,  5.16167921, 98.22787671,
       94.73084168, 22.56841661, 57.29400645, 78.54081262,  7.83391226,
       22.63535223, 29.60172368, 27.4950273 , 99.24264389, 46.21646042,
       64.00085735, 15.17929817, 62.07808712,  2.89924615, 17.45755964,
       29.38881429, 50.16510809, 53.02817434, 62.05308728, 98.13102668,
       69.89475089, 55.46266298, 32.24256228, 91.02744862, 22.40209362,
       35.90225731, 86.62797777, 23.73155794, 51.39188264, 63.47035068,
       19.87800742, 73.5083502 , 35.23672045, 86.97328786, 21.31654518,
        6.48736557, 73.83047876, 75.02199088,  4.78428117, 14.92000804,
       24.02855124, 45.03550152, 17.15552864, 32.81500976, 50.64019238,
       13.51721661, 40.52524601, 46.97708562, 52.51261951, 83.73328834,
       32.08523805, 48.47143785, 99.65753065, 23.81118374, 97.72577344,
       96.65287923, 43.19310825, 84.02072178,  3.75626978, 75.62222252,
       17.80254288, 61.89395145, 75.45828396, 90.01148977, 78.37200564,
       28.30437753, 56.02243516, 50.43874947, 97.84891986, 58.09986253,
       78.74081034, 10.96392476, 38.66845258, 51.07707352, 11.90923984,
       73.99402725, 90.81662783, 72.99023318, 15.00615176, 96.9503621 ,
       67.67536014, 13.22683647, 43.74644774, 83.64154276, 22.50591646,
       60.91328104, 83.65256591, 51.43679409, 51.42160986, 16.1067906 ,
       15.04530456, 28.81726812, 91.7158468 , 90.86457714, 78.33267684,
       42.28781273, 41.61665067, 74.87932171, 81.21012609, 79.92585765,
       67.99278778, 41.69538372, 77.64761025, 95.12627267, 46.47831771,
       77.4074928 ,  0.3907024 ,  8.05832759, 76.93499271,  2.74602284,
       22.05776366, 17.14588286, 67.80110724, 33.91067233, 94.31585594,
       35.88206739, 76.34300449, 43.11052047, 68.18144769, 49.72594384};

void foo() {
  int N = 300;
  double* in = (double*) fftw_malloc(sizeof(double) * N);
  fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  fftw_plan plan;

  plan = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

  for (int Index = 0; Index < N; Index++)
  {
    in[Index] = A[Index];
  }

  if(plan == NULL)
  {
    printf("Plan is NULL");
  }

  fftw_print_plan(plan);
  fftw_execute(plan);
 
  printf("\n");
  for(int Index = 0; Index < N; Index++)
  {
    printf("%.40f, %.40f\n", out[Index][0], out[Index][1]);
  }

  fftw_destroy_plan(plan);
  fftw_free(in);
  fftw_free(out);
 

}

int main(int argc, char *argv[])
{
  foo();
}
