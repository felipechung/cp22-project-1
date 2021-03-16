 #include <iostream>
 #include<iomanip>
 #include<cstdlib>
 #include<ctime>
 #include <fstream>
 using namespace std;
 void sortEfficient(int[], int );
 void sortInefficient(int [], int );
 
 int main() {
 	int SIZE=10000;
	clock_t   start, end;  // available when ctime is included 
	double    duration;
	int dataBest[SIZE], dataAvg[SIZE], dataWorst[SIZE], dataBestIn[SIZE], dataAvgIn[SIZE], dataWorstIn[SIZE];
	
  
  ifstream myfile;
  
  myfile.open("bestCase.txt"); //Open files 
  
  if (myfile.is_open())  {        
    
	for(int i=1; i<=SIZE; i++){ //Enter file numbers into arrays
		myfile>> dataBest[i] ; 	
	}
    myfile.close();
  }
  else cout << "Unable to open file"; 
    
  myfile.open("averageCase.txt");
  
  if(myfile.is_open()) {
  	
  	for(int i=1; i<=SIZE; i++){
  		myfile>> dataAvg[i];
  		
	  }
	  myfile.close();
  }
  else cout <<"Unable to open file";
  
    myfile.open("worstCase.txt");
  
  if(myfile.is_open()) {
  	
  	for(int i=1; i<=SIZE; i++){
  		myfile>> dataWorst[i];

	  }
	  myfile.close();
  }
  else cout <<"Unable to open file";
  
//  start = clock() ; //Start timing
//  sortInefficient(dataBestIn, SIZE);// Call sortefficientfunction 
//  end = clock() ; //End timing
//  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
//  cout<<"\n\nInefficient best case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
//  
//    start = clock() ; //Start timing
//  sortInefficient(dataAvgIn, SIZE);// Call sortefficientfunction 
//  end = clock() ; //End timing
//  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
//  cout<<"\n\nInefficient average case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
//  
//      start = clock() ; //Start timing
//  sortInefficient(dataWorstIn, SIZE);// Call sortefficientfunction 
//  end = clock() ; //End timing
//  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
//  cout<<"\n\nInefficient worst case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  start = clock() ; //Start timing
  sortEfficient(dataBest, SIZE);// Call sortefficientfunction 
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nEfficient best case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  start = clock() ; //Start timing
  sortEfficient(dataAvg, SIZE);
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nEfficient average case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  start = clock() ; //Start timing
  sortEfficient(dataWorst, SIZE);
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nEfficient worst case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
	
	
	
	return 0;
 }
 
 
 void sortEfficient(int d[], int SIZE) {
 	int t, swap;
 	
	
	for( int pass=1; pass<=SIZE; pass++ ){
		swap = 0;
		for(int i=1; i<= (SIZE-pass); i++){
			if(d[i] > d[i+1]){
				t = d[i];
				d[i] = d[i+1];
				d[i+1] = t;
				swap = 1;				
			}			
		}
		if (swap == 0){
			break;
		}
	}
//	cout << "Sorted numbers: ";
//	for(int i=1; i<=SIZE; i++){
//	 cout << d[i] << " ";
//	}	
 }
 void sortInefficient(int d[], int SIZE){
 	int t;
 	for( int pass=1; pass<=SIZE; pass++){
 		for(int i=1; i<=(SIZE-pass); i++){
 			if(d[i] > d[i+1]){
 				t = d[i];
 				d[i] = d[i+1];
				d[i+1] = t;
			 }
		 }
	 }
 }
 
 
