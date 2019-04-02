#include<iostream>
#include<iomanip>
using namespace std;



void add(int *A,int *B,int *C,int size){
  for(int i=0;i<size;i++){
    *(C+i)= *(A+i)+ *(B+i);
  }
}
void sub(int *A,int *B,int *C,int size){
  for(int i=0;i<size;i++){
    *(C+i)= *(A+i)- *(B+i);
  }
}


//
// void multiply(int *A,int *B,int *C,int n){
//
//   if(n<=1){
//     *C = (*A)*(*B);
//     return;
//   }else if(n>1){
//     int M1[n*n/4];
//     int M2[n*n/4];
//     int M3[n*n/4];
//     int M4[n*n/4];
//     int M5[n*n/4];
//     int M6[n*n/4];
//     int M7[n*n/4];
//     int C11[n*n/4];
//     int C12[n*n/4];
//     int C21[n*n/4];
//     int C22[n*n/4];
//     int A11[n*n/4];
//     int A12[n*n/4];
//     int A21[n*n/4];
//     int A22[n*n/4];
//     int B11[n*n/4];
//     int B12[n*n/4];
//     int B21[n*n/4];
//     int B22[n*n/4];
//     int tmp1[n*n/4];
//     int tmp2[n*n/4];
//
//
//     //divide A to A11 A12 A21 A22 & divide B to B11 B12 B21 B22 & init tmp1,tmp2
//     for(int i=0;i<n/2;i++){
//       int* temp_address_A11=A+(0*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_A12=A+(0*(n*n/2)+1*(n/2))+i*n;
//       int* temp_address_A21=A+(1*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_A22=A+(1*(n*n/2)+1*(n/2))+i*n;
//       int* temp_address_B11=B+(0*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_B12=B+(0*(n*n/2)+1*(n/2))+i*n;
//       int* temp_address_B21=B+(1*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_B22=B+(1*(n*n/2)+1*(n/2))+i*n;
//       for(int j=0;j<n/2;j++){
//         A11[i*(n/2)+j]= *(temp_address_A11+j);
//         A12[i*(n/2)+j]= *(temp_address_A12+j);
//         A21[i*(n/2)+j]= *(temp_address_A21+j);
//         A22[i*(n/2)+j]= *(temp_address_A22+j);
//         B11[i*(n/2)+j]= *(temp_address_B11+j);
//         B12[i*(n/2)+j]= *(temp_address_B12+j);
//         B21[i*(n/2)+j]= *(temp_address_B21+j);
//         B22[i*(n/2)+j]= *(temp_address_B22+j);
//
//       }
//     }
//
//
//
//     //make M1~M7
//     // cout<<"  M1=(A11+A22)(B11+B22)"<<endl;
//     add(A11,A22,tmp1,n*n/4);
//     add(B11,B22,tmp2,n*n/4);
//     multiply(tmp1,tmp2,M1,n/2);
//     // cout<<"  M2=(A21+A22)B11"<<endl;
//     add(A21,A22,tmp1,n*n/4);
//     multiply(tmp1,B11,M2,n/2);
//     // cout<<"  M3=A11(B12-B22)"<<endl;
//     sub(B12,B22,tmp1,n*n/4);
//     multiply(A11,tmp1,M3,n/2);
//     // cout<<"  M4=A22(B21-B11)"<<endl;
//     sub(B21,B11,tmp1,n*n/4);
//     multiply(A22,tmp1,M4,n/2);
//     // cout<<"  M5=(A11+A12)B22"<<endl;
//     add(A11,A12,tmp1,n*n/4);
//     multiply(tmp1,B22,M5,n/2);
//     // cout<<"  M6=(A21-A11)(B11+B12)"<<endl;
//     sub(A21,A11,tmp1,n*n/4);
//     add(B11,B12,tmp2,n*n/4);
//     multiply(tmp1,tmp2,M6,n/2);
//     // cout<<"  M7=(A12-A22)(B21+B22)"<<endl;
//     sub(A12,A22,tmp1,n*n/4);
//     add(B21,B22,tmp2,n*n/4);
//     multiply(tmp1,tmp2,M7,n/2);
//
//     //make C11 C12 C21 C22
//     // cout<<"   C11=M1+M4-M5+M7"<<endl;
//     add(M1,M4,tmp1,n*n/4);
//     sub(tmp1,M5,tmp2,n*n/4);
//     add(tmp2,M7,C11,n*n/4);
//     // cout<<"   C12=M3+M5"<<endl;
//     add(M3,M5,C12,n*n/4);
//     // cout<<"   C21=M2+M4"<<endl;
//     add(M2,M4,C21,n*n/4);
//     // cout<<"   C22=M1-M2+M3+M6"<<endl;
//     sub(M1,M2,tmp1,n*n/4);
//     add(tmp1,M3,tmp2,n*n/4);
//     add(tmp2,M6,C22,n*n/4);
//
//
//     //put C11~C22 into C
//     for(int i=0;i<n/2;i++){
//       int* temp_address_C11=C+(0*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_C12=C+(0*(n*n/2)+1*(n/2))+i*n;
//       int* temp_address_C21=C+(1*(n*n/2)+0*(n/2))+i*n;
//       int* temp_address_C22=C+(1*(n*n/2)+1*(n/2))+i*n;
//       for(int j=0;j<n/2;j++){
//         *(temp_address_C11+j)=C11[i*(n/2)+j];
//         *(temp_address_C12+j)=C12[i*(n/2)+j];
//         *(temp_address_C21+j)=C21[i*(n/2)+j];
//         *(temp_address_C22+j)=C22[i*(n/2)+j];
//       }
//     }
//
//   }
//
// }


void multiply(int *A,int *B,int *C,int n){
  if(n<=1){
    *C = (*A) * (*B);
    return;
  }else if(n>1){
    int *ptr_M1=new int[n*n/4];
    int *ptr_M2=new int[n*n/4];
    int *ptr_M3=new int[n*n/4];
    int *ptr_M4=new int[n*n/4];
    int *ptr_M5=new int[n*n/4];
    int *ptr_M6=new int[n*n/4];
    int *ptr_M7=new int[n*n/4];
    int *ptr_A11=new int[n*n/4];
    int *ptr_A12=new int[n*n/4];
    int *ptr_A21=new int[n*n/4];
    int *ptr_A22=new int[n*n/4];
    int *ptr_B11=new int[n*n/4];
    int *ptr_B12=new int[n*n/4];
    int *ptr_B21=new int[n*n/4];
    int *ptr_B22=new int[n*n/4];
    int *ptr_tmp1=new int[n*n/4];
    int *ptr_tmp2=new int[n*n/4];


    //divide A to A11 A12 A21 A22 & divide B to B11 B12 B21 B22
    for(int i=0;i<n/2;i++){
      int* temp_address_A11=A+(0*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_A12=A+(0*(n*n/2)+1*(n/2))+i*n;
      int* temp_address_A21=A+(1*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_A22=A+(1*(n*n/2)+1*(n/2))+i*n;
      int* temp_address_B11=B+(0*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_B12=B+(0*(n*n/2)+1*(n/2))+i*n;
      int* temp_address_B21=B+(1*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_B22=B+(1*(n*n/2)+1*(n/2))+i*n;
      for(int j=0;j<n/2;j++){
        *(ptr_A11+i*(n/2)+j)= *(temp_address_A11+j);
        *(ptr_A12+i*(n/2)+j)= *(temp_address_A12+j);
        *(ptr_A21+i*(n/2)+j)= *(temp_address_A21+j);
        *(ptr_A22+i*(n/2)+j)= *(temp_address_A22+j);
        *(ptr_B11+i*(n/2)+j)= *(temp_address_B11+j);
        *(ptr_B12+i*(n/2)+j)= *(temp_address_B12+j);
        *(ptr_B21+i*(n/2)+j)= *(temp_address_B21+j);
        *(ptr_B22+i*(n/2)+j)= *(temp_address_B22+j);
      }
    }



    //make M1~M7
    // cout<<"  M1=(A11+A22)(B11+B22)"<<endl;
    add(ptr_A11,ptr_A22,ptr_tmp1,n*n/4);
    add(ptr_B11,ptr_B22,ptr_tmp2,n*n/4);
    multiply(ptr_tmp1,ptr_tmp2,ptr_M1,n/2);
    // cout<<"  M2=(A21+A22)B11"<<endl;
    add(ptr_A21,ptr_A22,ptr_tmp1,n*n/4);
    multiply(ptr_tmp1,ptr_B11,ptr_M2,n/2);
    // cout<<"  M3=A11(B12-B22)"<<endl;
    sub(ptr_B12,ptr_B22,ptr_tmp1,n*n/4);
    multiply(ptr_A11,ptr_tmp1,ptr_M3,n/2);
    // cout<<"  M4=A22(B21-B11)"<<endl;
    sub(ptr_B21,ptr_B11,ptr_tmp1,n*n/4);
    multiply(ptr_A22,ptr_tmp1,ptr_M4,n/2);
    // cout<<"  M5=(A11+A12)B22"<<endl;
    add(ptr_A11,ptr_A12,ptr_tmp1,n*n/4);
    multiply(ptr_tmp1,ptr_B22,ptr_M5,n/2);
    // cout<<"  M6=(A21-A11)(B11+B12)"<<endl;
    sub(ptr_A21,ptr_A11,ptr_tmp1,n*n/4);
    add(ptr_B11,ptr_B12,ptr_tmp2,n*n/4);
    multiply(ptr_tmp1,ptr_tmp2,ptr_M6,n/2);
    // cout<<"  M7=(A12-A22)(B21+B22)"<<endl;
    sub(ptr_A12,ptr_A22,ptr_tmp1,n*n/4);
    add(ptr_B21,ptr_B22,ptr_tmp2,n*n/4);
    multiply(ptr_tmp1,ptr_tmp2,ptr_M7,n/2);

    delete [] ptr_A11;
    delete [] ptr_A12;
    delete [] ptr_A21;
    delete [] ptr_A22;
    delete [] ptr_B11;
    delete [] ptr_B12;
    delete [] ptr_B21;
    delete [] ptr_B22;

    int *ptr_C11=new int[n*n/4];
    int *ptr_C12=new int[n*n/4];
    int *ptr_C21=new int[n*n/4];
    int *ptr_C22=new int[n*n/4];

    //make C11 C12 C21 C22
    // cout<<"   C11=M1+M4-M5+M7"<<endl;
    add(ptr_M1,ptr_M4,ptr_tmp1,n*n/4);
    sub(ptr_tmp1,ptr_M5,ptr_tmp2,n*n/4);
    add(ptr_tmp2,ptr_M7,ptr_C11,n*n/4);
    // cout<<"   C12=M3+M5"<<endl;
    add(ptr_M3,ptr_M5,ptr_C12,n*n/4);
    // cout<<"   C21=M2+M4"<<endl;
    add(ptr_M2,ptr_M4,ptr_C21,n*n/4);
    // cout<<"   C22=M1-M2+M3+M6"<<endl;
    sub(ptr_M1,ptr_M2,ptr_tmp1,n*n/4);
    add(ptr_tmp1,ptr_M3,ptr_tmp2,n*n/4);
    add(ptr_tmp2,ptr_M6,ptr_C22,n*n/4);

    delete [] ptr_M1;
    delete [] ptr_M2;
    delete [] ptr_M3;
    delete [] ptr_M4;
    delete [] ptr_M5;
    delete [] ptr_M6;
    delete [] ptr_M7;
    delete [] ptr_tmp1;
    delete [] ptr_tmp2;

    //put C11~C22 into C
    for(int i=0;i<n/2;i++){
      int* temp_address_C11=C+(0*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_C12=C+(0*(n*n/2)+1*(n/2))+i*n;
      int* temp_address_C21=C+(1*(n*n/2)+0*(n/2))+i*n;
      int* temp_address_C22=C+(1*(n*n/2)+1*(n/2))+i*n;
      for(int j=0;j<n/2;j++){
        *(temp_address_C11+j)=  *(ptr_C11+i*(n/2)+j);
        *(temp_address_C12+j)=  *(ptr_C12+i*(n/2)+j);
        *(temp_address_C21+j)=  *(ptr_C21+i*(n/2)+j);
        *(temp_address_C22+j)=  *(ptr_C22+i*(n/2)+j);
      }
    }


    delete [] ptr_C11;
    delete [] ptr_C12;
    delete [] ptr_C21;
    delete [] ptr_C22;

  }
}




void Strassen(int *A,int *B,int *C,int M,int N,int K){
  int Z=1;//2^0
  while (Z<max(max(M,N),K)) {
    Z*=2;
  }

  int AA[Z][Z],BB[Z][Z],CC[Z][Z];
  //fill A & B with 0
  cout<<"A with 0="<<endl;
  for(int i=0;i<Z;i++){
    for(int j=0;j<Z;j++){
      if(i<N && j<M){
        AA[i][j]=*(A+M*i+j);
      }else{
        AA[i][j]=0;
      }
      cout<<setw(4)<<AA[i][j];
    }
    cout<<endl;
  }
  cout<<"B with 0="<<endl;
  for(int i=0;i<Z;i++){
    for(int j=0;j<Z;j++){
      if(i<M && j<K){
        BB[i][j]=*(B+K*i+j);
      }else{
        BB[i][j]=0;
      }
      cout<<setw(4)<<BB[i][j];
    }
    cout<<endl;
  }

  multiply(&AA[0][0],&BB[0][0],&CC[0][0],Z);
  cout<<"(A with 0)*(B with 0)="<<endl;
  for(int i=0;i<Z;i++){
    for(int j=0;j<Z;j++){
      cout<<setw(4)<<CC[i][j];
    }
    cout<<endl;
  }


  //put ans into C
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      *(C+i*K+j)=CC[i][j];
    }
  }


}


int main(){
  int M,N,K;
  cout<<"A(M rows N columns) * B(K rows M columns) = C(K rows N columns)"<<endl;
  cout<<"input M=?"<<endl;
  cin>>M;
  cout<<"input N=?"<<endl;
  cin>>N;
  cout<<"input K=?"<<endl;
  cin>>K;

  int A[N][M];
  int B[M][K];
  int C[N][K];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<"A["<<i<<"]["<<j<<"]=?"<<endl;
      cin>>A[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<K;j++){
      cout<<"B["<<i<<"]["<<j<<"]=?"<<endl;
      cin>>B[i][j];
    }
  }






  Strassen(&A[0][0],&B[0][0],&C[0][0], M, N, K);

  cout<<"Ans: C=A*B="<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      cout<<setw(4)<<C[i][j];
    }
    cout<<endl;
  }

  return 0;
}
