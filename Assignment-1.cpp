 #include <iostream>
 #include<iomanip>
 #include<cstdlib>
 #include<ctime>
 #include <fstream>
 using namespace std;
 void sortEfficient(int[], int );
 void sortInefficient(int [], int );
 
 int main() {
 	int SIZE=100000;
	clock_t   start, end;  // available when ctime is included 
	double    duration;
	int dataBest[SIZE], dataAvg[SIZE], dataWorst[SIZE];	
  
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
  
  start = clock() ; //Start timing
  sortInefficient(dataBest, SIZE);// Call sortInefficient function 
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nInefficient best case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  //Reset dataBest array
  myfile.open("bestCase.txt"); //Open files 
  
  if (myfile.is_open())  {        
    
	for(int i=1; i<=SIZE; i++){ 
		myfile>> dataBest[i] ; 	
	}
    myfile.close();
  }
  else cout << "Unable to open file"; 
  
    start = clock() ; //Start timing
  sortInefficient(dataAvg, SIZE);// Call sortInefficient function 
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nInefficient average case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  //Reset dataAvg array
  myfile.open("averageCase.txt");  
  if(myfile.is_open()) {
  	
  	for(int i=1; i<=SIZE; i++){
  		myfile>> dataAvg[i];
  		
	  }
	  myfile.close();
  }
  else cout <<"Unable to open file";
  
      start = clock() ; 
  sortInefficient(dataWorst, SIZE);
  end = clock() ; 
  duration=((double)(end - start))/CLOCKS_PER_SEC; 
  cout<<"\n\nInefficient worst case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  //Reset dataWorst array
      myfile.open("worstCase.txt");  
  if(myfile.is_open()) {
  	
  	for(int i=1; i<=SIZE; i++){
  		myfile>> dataWorst[i];

	  }
	  myfile.close();
  }
  else cout <<"Unable to open file";
  
  start = clock() ; //Start timing
  sortEfficient(dataBest, SIZE);// Call sortEfficient function 
  end = clock() ; //End timing
  duration=((double)(end - start))/CLOCKS_PER_SEC; //Compute seconds
  cout<<"\n\nEfficient best case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  start = clock() ;
  sortEfficient(dataAvg, SIZE); 
  end = clock() ; 
  duration=((double)(end - start))/CLOCKS_PER_SEC; 
  cout<<"\n\nEfficient average case took "<<setprecision(3)<<fixed<<duration<<" seconds!\n";
  
  start = clock() ; 
  sortEfficient(dataWorst, SIZE);
  end = clock() ; 
  duration=((double)(end - start))/CLOCKS_PER_SEC; 
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
 
 
