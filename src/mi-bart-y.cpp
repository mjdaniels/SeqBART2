#include <Rcpp.h>
using namespace Rcpp;

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>

#include "Eigen/Dense"
#include "Eigen/Cholesky"

#include "rng.h"
#include "info.h"


//#include "tree.h" // for initinput
#include "funs.h" // for mcmc + initinput AND for the fit in the main function
//#include "bd.h" // for mcmc



//#include "clasinit.h" // how is init in this func undrestanding what init is when I have commented classinit.h
//#include "clasinit.h"  // giving it  now, cause the  clasinit is ifndef now.. lets see...
#include "func_mcmc.h"



#include "func_initialInput.h"

using std::cout;
using std::endl;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Map;
using namespace Eigen;



//-----------------------------------------
// function to get initial data
//-----------------------------------------

//static void  init_input(size_t index, init& ip_initial, int* vartype)
//   {
//     std::vector<tree> t(m);
//     ip_initial.t=t;
//     ip_initial.di.x = new double [n*(p-index)];
//     ip_initial.allfit = new double [n];
//    //read in data
//    //read y NOTE: we assume y is already centered at 0.
//    double miny = INFINITY; //use range of y to calibrate prior for bottom node mu's
//    double maxy = -INFINITY;
//    sinfo allys;       //sufficient stats for all of y, use to initialize the bart trees.
//    double ytemp;
//
//    if(index==0)
//      {
//        if(vartype[p-index]==0)
// 	 {
// 	   cout<<"continuous"<<endl;
// 	   for(size_t i=0;i<n;i++)
// 	     {
// 	       ip_initial.y.push_back(y[i]);
// 	     }
// 	 }
//        else
// 	 {
// 	   cout<<"binary"<<endl;
// 	   for(size_t i=0;i<n;i++)
// 	     {
// 	       ip_initial.y.push_back(z[i*binum+p-bistart]);
// 	       ip_initial.z.push_back(int(y[i]));
// 	     }
//          }
//        cout<<ip_initial.y[0]<<endl;
// 	   ip_initial.di.x=&x[0];
// cout<<ip_initial.di.x[0]<<endl;
//      }
//
//    else
//      {
//        if(vartype[p-index]==0)
// 	 {
// 	   cout<<"continuous"<<endl;
// 	   for(size_t i=0;i<n;i++)
// 	     {
// 	       ip_initial.y.push_back(x[(i+1)*p-index]);
// 	       for(size_t j=0;j<p-index;j++)
// 		 {
// 		   ip_initial.di.x[i*(p-index)+j]=x[i*p+j];
// 		 }
//
// 	     }
// 	 }
//        else
// 	 {
// 	   cout<<"binary"<<endl;
// 	   for(size_t i=0;i<n;i++)
// 	     {
// 	       ip_initial.z.push_back(int(x[(i+1)*p-index]));
// 	       ip_initial.y.push_back(z[i*binum+p-index-bistart]);
// 	       for(size_t j=0;j<p-index;j++)
// 		 {
// 		   ip_initial.di.x[i*(p-index)+j]=x[i*p+j];
// 		 }
// 	     }
// 	 }
//      }
//     cout<<"\ndata import ok"<<endl;
//    for(size_t i=0;i<n;i++) {
//      ytemp=ip_initial.y[i];
//       if(ytemp<miny) miny=ytemp;
//       if(ytemp>maxy) maxy=ytemp;
//       allys.sy += ytemp; // sum of y
//       allys.sy2 += ytemp*ytemp; // sum of y^2
//    }
//    allys.n = n;
//     cout << "\ny read in:\n";
//     cout << "n: " << n << endl;
//    cout << "y first and last:\n";
//    cout << ip_initial.y[0] << ", " << ip_initial.y[n-1] << endl;
//    double ybar = allys.sy/n; //sample mean
//    double shat = sqrt((allys.sy2-n*ybar*ybar)/(n-1)); //sample standard deviation
//    cout << "ybar,shat: " << ybar << ", " << shat <<  endl;
//
//    //read x
//    //the n*p numbers for x are stored as the p for first obs, then p for second, and so on.
//    cout << "\nx read in:\n";
//    cout << "p: " << p << endl;
//    cout << "first row: " <<  ip_initial.di.x[0] << " ...  " << ip_initial.di.x[p-1-index] << endl;
//    cout << "last row: " << ip_initial.di.x[(n-1)*(p-index)] << " ...  " << ip_initial.di.x[n*(p-index)-1] << endl;
//
//    //x cutpoints
//    size_t nc=100; //100 equally spaced cutpoints from min to max.
//    makexinfo(p-index,n,&(ip_initial.di.x[0]),ip_initial.xi,nc,vartype);
//    cout<<ip_initial.di.x[0]<<endl;
//    //dinfo
//    for(size_t i=0;i<n;i++)
//      {
//        ip_initial.allfit[i]=ybar;
//      }
//
//    for(unsigned int i=0;i<m;i++)
//      {
//        ip_initial.t[i].setm(ybar/m); //if you sum the fit over the trees you get the fit.
//      }
//
//
//   //prior and mcmc
//    ip_initial.pi.pbd=1.0; //prob of birth/death move
//    ip_initial.pi.pb=.5; //prob of birth given  birth/death
//
//    ip_initial.pi.alpha=.95; //prior prob a bot node splits is alpha/(1+d)^beta, d is depth of node
//    ip_initial.pi.beta=2.0; //2 for bart means it is harder to build big trees.
//
//    if(vartype[p-index]==0)
//      {
//        ip_initial.pi.tau=(maxy-miny)/(2*kfac*sqrt((double)m));
//        ip_initial.pi.sigma=shat;
//
//        cout << "\nalpha, beta: " << ip_initial.pi.alpha << ", " << ip_initial.pi.beta << endl;
//        cout << "sigma, tau: " << ip_initial.pi.sigma << ", " << ip_initial.pi.tau << endl;
//
//      }
//    else
//      {
//        ip_initial.pi.tau=3.0/(kfac*sqrt((double)m));
//        ip_initial.pi.sigma=1.0;
//      }
//
//     cout<<ip_initial.allfit[n-1]<<endl;
//    ip_initial.di.n=n;
//     cout<<ip_initial.di.n<<endl;
//    ip_initial.di.p=p-index;
//    cout<<ip_initial.di.p<<endl;
//    ip_initial.di.y=ip_initial.r; //the y for each draw will be the residual
//    cout<<ip_initial.r<<endl;
//    ip_initial.di.vartype=vartype;
//
//
//      return;
//    }


// mcmc

//--------------------------------
// main program
//--------------------------------
// Multiply a number by one
// @param x one single integer.
// @export
// this export is for namespaces


// this export is needed to make it availale to R and its is done by Rcpp thats why "Rcpp::export"
// [[Rcpp::export]]
NumericVector cpp_bart_y (NumericVector new_xroot, NumericVector new_yroot, int new_nd, int new_burn,
                int new_m, int new_nu, int new_kfac, int  new_nmissing,
                IntegerVector new_xmissroot, int new_bistart, NumericVector new_vartyperoot,
                NumericVector new_zroot, NumericVector new_lambda, int new_type)
{

  size_t m;
  double kfac;
  std::vector<double> x,y;
  std::vector<double> z;
  size_t n,p;
  double nu;
  double lambda;
  int bistart;
  int binum;
//
//   cout<< "2017 build"<<endl;
//   cout<<"why two diffrent exports"<<endl;
//


  NumericVector mymif2;
  //random number generation
  uint seed=99;
  RNG gen(seed); //this one random number generator is used in all draws

  //read in data
  y = Rcpp::as< std::vector<double> >(new_yroot);

  n = y.size();
  //n = 0;
  if(n<1)
    {
      //cout << "error n<1\n";
     // raise an exception!!! Not exit nor return! catch is optional
      return mymif2;
    }
  // cout<< "Y included. Linear regression. Diffuse prior."<<endl;
  // cout << "\ny read in:\n";
  // cout << "n: " << n << endl;
  // cout << "y first and last:\n";
  // cout << y[0] << ", " << y[n-1] << endl;

  //read x
    x = Rcpp::as< std::vector<double> >(new_xroot); // ***aparently x is not a 2d vector.

  p = x.size()/n;
  if(x.size() != n*p)
    {
    //cout << "error: input x file has wrong number of values\n";
    // raise an exception!!!!  Not exit nor return! catch is optional
    return mymif2;
    }
  // cout << "\nx read in:\n";
  // cout << "p: " << p << endl;
  // cout << "first row: " <<  x[0] << " ...  " << x[p-1] << endl;
  // cout << "last row: " << x[(n-1)*p] << " ...  " << x[n*p-1] << endl;
  //

   //optionally read in additional arguments
//  size_t burn = 100; //number of mcmc iterations called burn-in
//  size_t nd = 1000; //number of mcmc iterations
//  m=200; //number of trees in BART sum
//   lambda = 1.0; //this one really needs to be set
//  nu = 3.0;
//  size_t nvar=0; // # of covariates with missing values


    m = 200;
    nu = 3.0;
    kfac = 2.0;

    m = new_m;
    nu = new_nu;
    kfac = new_kfac;

    size_t burn = 100;
    size_t nd = 1000;
    size_t nvar=0;

    burn  = new_burn;
    nd = new_nd;
    nvar = new_nmissing;

    bistart=0;
    binum=0;


//  if(argc>4) nd = atoi(argv[4]);
//  if(argc>5) lambda = atof(argv[5]);
//  if(argc>6) burn = atoi(argv[6]);
//  if(argc>7) m = atoi(argv[7]);
//  if(argc>8) nu = atof(argv[8]);
//  if(argc>9) kfac = atof(argv[9]);
//  if(argc>10) nvar=atoi(argv[10]);



    std::vector<int> ind_missing = Rcpp::as< std::vector<int> >(new_xmissroot);

//      std::ifstream mindf(argv[11]);  //file to read missing indicator from
//      std::vector<int> ind_missing;
//      int mtemp;
//      while(mindf>> mtemp)  ind_missing.push_back(mtemp);

//  cout <<"\nburn,nd,number of trees: " << burn << ", " << nd << ", " << m << endl;
//  cout <<"\nlambda,nu,kfac: " << lambda << ", " << nu << ", " << kfac << endl;
//  cout <<"\nnvar:" << nvar<<endl;

//   bistart = atoi(argv[12]);
    //new_bistart
    bistart = new_bistart;



    int* vartype=new int[p+1];

    //std::ifstream vart(argv[13]);  //file to read variable type from
   std::vector<int> vart2 = Rcpp::as< std::vector<int> >(new_vartyperoot);



    //int vartemp;
   int jj=0;
//   while(vart >> vartemp)  {
//     vartype[jj]=vartemp;
//     if(jj>=bistart){
//       if(vartemp==1){binum++;}
//     }
//     jj++;
//   }
//   //  jj=0;
//   //  while(vartype[jj]==0) {bistart++;jj++;}
    for (std::vector<int>::const_iterator i = vart2.begin(); i != vart2.end(); ++i)
    {
        // cout << "jj is here" << jj <<endl;
        vartype[jj]=*i;
        if(jj>=bistart)
        {
            if(*i==1)
            {
                binum++;
            }
        }
        jj++;
    }

//   std::ifstream bi(argv[14]);
// double bitemp;
// jj=0;
// while(bi>>bitemp)
//   {z.push_back(bitemp);
//     //   cout<<"z["<<jj<<"]"<<bitemp<<endl;
//     jj++;
//   }
    z = Rcpp::as< std::vector<double> >(new_zroot);


// std::string name1(argv[15]);
// //cout<<name1;
//  std::string filename="";
//  filename.append(name1);
//    std::string new_ffname_conv = Rcpp::as<std::string>(new_ffname);
//    std::string filename="";
//    filename.append(new_ffname_conv);

    // Pointer Creation!!
    init *all_initial = new init[nvar+1]; //right
    //init all_initial[nvar+1]; //wrong

   for(size_t i=0;i<nvar+1;i++)
    {
      all_initial[i].ftemp=new double [n];
      all_initial[i].r=new double [n];
      //cout<<all_initial[i].r<<endl;
    }

  for(size_t i=0;i<nvar+1;i++)
    {
      //cout<<"\n function"<<i+1<<endl;
      //init_input(i,all_initial[i],vartype);
      init_input(i, all_initial[i], vartype,  m, kfac, bistart, binum, n, p, z, y, x);


      // cout<<all_initial[i].r<<endl;
      // cout<<"first and last ys:\n"<<endl;
      // cout <<all_initial[i].y[0]<<"..."<<all_initial[i].y[n-1]<<endl;
      // cout << "\nfirst and last row of x"<<endl;
      // cout << "first row: " <<  all_initial[i].di.x[0] << " ...  " << all_initial[i].di.x[p-1-i] << endl;
      //  cout << "last row: " << all_initial[i].di.x[(n-1)*(p-i)] << " ...  " << all_initial[i].di.x[n*(p-i)-1] << endl;
    }


   //storage for ouput
   //missing value
 // std::ofstream mif("mif.txt");
  //std::ofstream mif(filename.c_str());//file to save imputed missing value

//  NumericVector mymif2;

  //std::vector<double> cppmymif2 = Rcpp::as< std::vector<double> >(mymif2);
  //std::vector<double> mymif;

  //std::ofstream accpt("/home/dandan/Downloads/test/accpt.txt");//file to save imputed missing value
  //std::ofstream bsdf("/home/dandan/Downloads/test/bart-sd.txt"); //note that we write all burn+nd draws to this file.

   // //mcmc
  double pro_prop=0.0; //proposal probability of MH min(1,alpha)
  double pro_propnum=1.0;//numerator of proposal prob
  double pro_propdenom=1.0;//denominator of proposal prob
  double prop=0.0;// proposal for mh
  dinfo di_temp; //x used to get fitted value
  double* ppredmean=new double[p];
  double* fpredtemp=new double[1];

  // new change1  4/21/2015
  MatrixXd xx(n,p+1);
  VectorXd x1=VectorXd::Constant(n,1);
  VectorXd beta(p+1);
  //VectorXd yy(y.data());
  Map<Eigen::Matrix<double,Dynamic,Dynamic,RowMajor> > yy(y.data(),n,1);
  VectorXd ee(n);
  double* sigsq=new double[1];
  Map<Eigen::Matrix<double,1,1> > sigsq1(sigsq);
  MatrixXd cho(p+1,p+1);
  MatrixXd xxinv(n,n);
  //VectorXd rbeta(p+1);
  std::vector<double> rnor;
  for(size_t i=0;i<=p;i++) rnor.push_back(0.0);
  Map<Eigen::Matrix<double,Dynamic,Dynamic,RowMajor> > rbeta(rnor.data(),p+1,1);
  double* meantemp1=new double[1];
  double* meantemp2=new double[1];
  Map<Eigen::Matrix<double,1,1> > meantemp11(meantemp1);
  Map<Eigen::Matrix<double,1,1> > meantemp21(meantemp2);
  VectorXd xxtemp(p+1);

  Map<Eigen::Matrix<double,Dynamic,Dynamic,RowMajor> > xx1(all_initial[0].di.x,n,p);
    xx<<x1,xx1;
    //  cout<<"xx="<<xx<<endl;
    beta=(xx.transpose()*xx).inverse()*xx.transpose()*yy;
    // cout<<"beta"<<beta<<endl;
    //end change 1


  //  double temp_a;
  di_temp.n=1;di_temp.y=0;
  std::vector<double> tempx;
  for(size_t i=0;i<=p;i++) tempx.push_back(0.0);
  Map<Eigen::Matrix<double,Dynamic,Dynamic,RowMajor> > xxtemp1(tempx.data(),p,1);
  xxtemp<<1,xxtemp1;
  //cout << "\nMCMC:\n"<<endl;
  //cout << "xxtemp1="<<xxtemp1<<endl;
  // cout <<"xxtemp="<<xxtemp<<endl;
  // clock_t tp;
  // tp = clock();
  size_t l=0;
  for(size_t i=0;i<(nd+burn);i++)
    {
      //if(i%100==0) cout << "i: " << i << endl;

      // mcmc used to get updated parameters
      for(size_t j=1;j<nvar+1;j++)
      	{ lambda= (new_lambda[j]);

      	  mcmc(all_initial[j], gen,vartype,  m,  n,  lambda, nu);

      	}

      //new change2 -- posterior of beta and sigma
        xx<<x1,xx1;
        ee=yy-xx*beta;
	//	cout<<"ee="<<ee<<endl;
	sigsq1=(ee.transpose()*ee);
	sigsq[0]=sigsq[0]/gen.chi_square(double(n-p-1));
	// cout<<"sig="<<sigsq[0]<<endl;
        xxinv=(xx.transpose()*xx).inverse()*sigsq[0];
	cho=(xxinv.llt().matrixL());
	// cout<<"cho="<<cho<<endl;
        gen.normal(rnor,0,1);
        //VectorXd rbeta(rnor.data());
        beta=xxinv/sigsq[0]*xx.transpose()*yy+cho*rbeta;
	//end change2

      // all_initial[0].t[0].pr();
      //  prxi(all_initial[0].xi);

      jj=0;
      //-------------------------------
      // impute missing values
      for(size_t j=0;j<n;j++)
  	{
  	  //the row of x used to get prediction

  	  for(size_t k=1;k<=nvar;k++) //change3
  	    {
  	      if(ind_missing[j*(nvar+1)+k]==1)
  		{

  	  for(size_t j1=0;j1<p;j1++)
  	    {
  	      tempx[j1]=all_initial[0].di.x[j*p+j1];
  	    }

		  //cout<<"missing"<<j<<"and"<<k<<endl;
  		  //proposal
                  if(vartype[p-k]==0)
		    {
  		  prop=gen.normal(all_initial[k].allfit[j],all_initial[k].pi.sigma);
		  // cout<<"proposal"<<prop<<endl;
		  //cout<<"mean"<<all_initial[k].allfit[j]<<endl;
		  // cout<<"sig"<<all_initial[k].pi.sigma<<endl;
  		  // calcualte proposal prob
		  // pro_propdenom=pn(all_initial[k].y[j],all_initial[k].allfit[j],pow(all_initial[k].pi.sigma,2));
		  pro_propdenom=1.0;
  		  //pro_propnum=pn(prop,all_initial[k].allfit[j],pow(all_initial[k].pi.sigma,2));
		  pro_propnum=1.0;
		    } else
		    {prop=double(abs(all_initial[k].z[j]-1));
                      pro_propnum=fabs(prop-phi(-all_initial[k].allfit[j]));
                      pro_propdenom=fabs(double(all_initial[k].z[j])-phi(-all_initial[k].allfit[j]));
		      //  temp_a=phi(-all_initial[k].allfit[j]);
		       // cout<<"phi"<<temp_a;
		       //cout<<"zzzzzzzz"<<all_initial[k].z[j]<<"prop"<<prop<<endl;
		       //cout<<"ppppppp"<<pro_propnum<<"ppppppp"<<pro_propdenom<<endl;

		    }
		  // change 4

		  // cout << "xxtemp1="<<xxtemp1<<endl;
 xxtemp<<1,xxtemp1;
 // cout <<"xxtemp="<<xxtemp<<endl;
		    meantemp11=(xxtemp.transpose()*beta);
		    //  cout<<"meantemp11="<<meantemp11<<endl;
		    // cout<<"beta="<<beta<<endl;
		    // cout<<"meantemp1="<<meantemp1[0]<<endl;
		  pro_propdenom=pro_propdenom*pn(all_initial[0].y[j],meantemp1[0],sigsq[0]);
	  tempx[p-k]=prop;//change the element to proposal
           xxtemp<<1,xxtemp1;
          meantemp21=(xxtemp.transpose()*beta);
	  // cout << "xxtemp1="<<xxtemp1<<endl;
 // cout <<"xxtemp="<<xxtemp<<endl;
 // cout<<"meantemp2="<<meantemp2[0]<<endl;
 pro_propnum=pro_propnum*pn(all_initial[0].y[j],meantemp2[0],sigsq[0]);

		  l=1; //change 5
  		  while(l<k)
  		    { if(vartype[p-l]==0){
  		      pro_propdenom=pro_propdenom*pn(all_initial[l].y[j],all_initial[l].allfit[j],pow(all_initial[l].pi.sigma,2));
                      }else{
			pro_propdenom=pro_propdenom*fabs(double(all_initial[l].z[j])-phi(-all_initial[l].allfit[j]));
			// temp_a=phi(-all_initial[l].allfit[j]);
			//   cout<<"phi"<<temp_a;
                        }


		      // cout<<"a"<<all_initial[l].y[j]<<"b"<<all_initial[l].allfit[j]<<"C"<<all_initial[l].pi.sigma<<endl;

  		      di_temp.p=p-l; di_temp.x=&tempx[0];
                      di_temp.vartype=vartype;
  		      ppredmean[l]=0.0;
  		      for(size_t q=0;q<m;q++)
  			{
  			  fit(all_initial[l].t[q],all_initial[l].xi,di_temp,fpredtemp);
  			  ppredmean[l] += fpredtemp[0];
  			}
                     if(vartype[p-l]==0){
  		      pro_propnum=pro_propnum*pn(all_initial[l].y[j],ppredmean[l],pow(all_initial[l].pi.sigma,2));
                      }else{
		       pro_propnum=pro_propnum*fabs(double(all_initial[l].z[j])-phi(-ppredmean[l]));}
		     // cout<<"d"<<ppredmean[l]<<endl;
		      l++;
		      // cout<<"denom"<<pro_propdenom<<"num"<<pro_propnum;
		    }


                  if(vartype[p-k]==0){
  		  pro_prop=std::min(1.0,pro_propnum/pro_propdenom);
		  }else{pro_prop=pro_propnum/(pro_propnum+pro_propdenom);
		    // if(j==6&&k==19){
		    // cout<<"proposal_prob"<<pro_prop<<"prop"<<prop<<endl;}
		  }
		  // cout<<"proposal_prob"<<pro_prop<<endl;
  		  //if proposal accepted, update variables
  		  if(gen.uniform()<pro_prop)
  		    { if(vartype[p-k]==0) { all_initial[k].y[j]=prop;
		      }else {all_initial[k].z[j]=int(prop);
			if(all_initial[k].z[j]==0)
			  {
			    all_initial[k].y[j]=0.0;
			    while(all_initial[k].y[j]>=0.0)
			      {
				all_initial[k].y[j]=gen.normal(all_initial[k].allfit[j],1);
			      }
			  } else
			  {
			    all_initial[k].y[j]=0.0;
			    while(all_initial[k].y[j]<=0.0)
			      {
				all_initial[k].y[j]=gen.normal(all_initial[k].allfit[j],1);
			      }
			  }

		      }

                      l=0;
		      while(l<k)
  			{
      all_initial[l].di.x[j*(p-l)-k+p]=prop;
      all_initial[l].allfit[j]=ppredmean[l];
      l++;
  			}
		      // mif<<prop<<endl;
          mymif2.push_back(prop);
		       // cout<<"mif="<<prop<<endl;
		       //   accpt<<1<<endl;

  		    }
  		  else
  		    {
  		    if(vartype[p-k]==0)
  		      {
			      //  mif<<all_initial[k].y[j] <<endl;
  		      mymif2.push_back(all_initial[k].y[j]);
			      }
  		    else
  		      {
  		     // mif<<all_initial[k].z[j] <<endl;
  		      mymif2.push_back(all_initial[k].z[j]);
		        }


  		    }
  		}

  	    }
  	}

    }
  // tp=clock()-tp;
  // double thetime = (double)(tp)/(double)(CLOCKS_PER_SEC);
  // cout << "time for loop: " << thetime << endl;
  // cout << "you had type =" << new_type<< endl;
  // cout << "22feb2";
  return mymif2;
   //return 0;
}
