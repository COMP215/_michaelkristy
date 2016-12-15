#include <iostream>
#include <vector>

using namespace std;
//finds highest deadline of all the jobs
int maxDeadline(vector<string> jobNamesVec, vector<int> jobDeadlineVec, vector<int> jobProfitVec);
//finds the highest profit with the lowest job number available that can be added to the queue
int findHighestProfit(vector<string> jobNamesVec, vector<int>jobDeadlineVec, vector<int> jobProfitVec, int queue, vector<string> ignoreList);
//prints all results
void printResults(vector<string> jobNamesVec, vector<int>jobDeadlineVec, vector<int> jobProfitVec, vector<int> masterJobList);

int main(){
  //used as temp variables for the while loop
  string tempJobTitle;
  int jobDeadline;
  int jobProfit;

  //posistion in queue
  int queue = 1;

  //when user enters 0 this will turn true
  bool stopAddingData = false;

  //vectors to hold all of the information
  vector<string> jobNamesVec;
  vector<int> jobDeadlineVec;
  vector<int> jobProfitVec;
  vector<string> ignoreList;
  vector<int> masterJobList;

  cout << "-----Welcome to Job Sort-----" << endl;
  cout << "ENTER '0' TO QUIT ADDING" << endl;

  //used to add data to the vectors
  while(stopAddingData != true){
    cout << "Enter job title: ";
    cin >> tempJobTitle;
    if(tempJobTitle == "0"){
      stopAddingData = true;
    }
    if(stopAddingData == false){
      cout << "Enter job deadline: ";
      cin >> jobDeadline;
      if(jobDeadline == 0){
        stopAddingData = true;
      }
    }
    if(stopAddingData == false){
      cout << "Enter job profit: ";
      cin >> jobProfit;
      if(jobProfit == 0){
        stopAddingData = true;
      }
    }
    //job successfully added
    if(stopAddingData == false){
      cout << "Job Successfully Added!" << endl;
      jobNamesVec.push_back(tempJobTitle );
      jobDeadlineVec.push_back(jobDeadline);
      jobProfitVec.push_back(jobProfit);
    }
    //job haulted before finished
    else{
      cout << "Incomplete job, nothing added or input terminated." << endl;
    }
    cout << "------------------------" << endl;
  }

  //calls max deadline to find highest deadline possible
  int maxDeadlineNum = maxDeadline(jobNamesVec, jobDeadlineVec, jobProfitVec);
  for(int i = 0; i < maxDeadlineNum; i++){
      //finds highest profit avail
      int highestProf = findHighestProfit(jobNamesVec,jobDeadlineVec,jobProfitVec, queue, ignoreList);
      if(highestProf != -1){
      //list of used jobs
      ignoreList.push_back(jobNamesVec[highestProf]);
      //list of jobs done
      masterJobList.push_back(highestProf);
      queue++;
      }
      else{
        queue++;
      }

  }

  // calls print results
  printResults(jobNamesVec, jobDeadlineVec, jobProfitVec, masterJobList);
  return 0;
  }

//finds the highest deadline in list
int maxDeadline(vector<string> jobNames, vector<int> jobDeadlines, vector<int> jobProfit){
  int vectorLength = jobNames.size();
  int vectorDeadline = 0;
  int maxDeadline = 0;
  for(int i = 0; i < vectorLength; i++){
    vectorDeadline = jobDeadlines[i];
    if(vectorDeadline > maxDeadline){
      maxDeadline = vectorDeadline;
    }
  }
  return maxDeadline;
}

//finds highest profit lowest deadline
int findHighestProfit(vector<string> jobNamesVec, vector<int>jobDeadlineVec, vector<int> jobProfitVec, int queue, vector<string> ignoreList){
  int vectorLength = jobNamesVec.size();
  int vecGrabber = 0;
  int smallestVec = jobDeadlineVec[0];
  int currProfit;
  int posistion;
  int used = 0;
  int activated = 0;

  //make sure job is already done
  for(int i = 0; i < vectorLength; i++){
    if(queue > 1){
      for(int j = 0; j < jobNamesVec.size(); j++){
        if(jobNamesVec[i] == ignoreList[j]){
          used = 1;
        }
      }
    }
    //if job is not done
    if(jobDeadlineVec[i] <= queue && used != 1){
      vecGrabber = jobDeadlineVec[i];
      posistion = i;
      activated++;
      //if job is smaller than current
      if(vecGrabber < smallestVec){
        smallestVec = vecGrabber;
        currProfit = jobProfitVec[i];
        posistion = i;
      }
      //if job is the same as current but has a higher profit
      else if(vecGrabber == smallestVec && jobProfitVec[i] > currProfit){
        smallestVec = vecGrabber;
        currProfit = jobProfitVec[i];
        posistion = i;
      }
    }
      used = 0;
  }
  //if nothing applies send posisiton -1 to stop looking
  if (activated == 0) {
    posistion = -1;
  }
  return posistion;
}

//print results
void printResults(vector<string> jobNamesVec, vector<int>jobDeadlineVec, vector<int> jobProfitVec, vector<int> masterJobList){
  int totalProf = 0;
  for(int i = 0; i < masterJobList.size(); i++){
    cout << jobNamesVec[masterJobList[i]] << " completed in the queue at posistion " << i + 1 << "." << endl;
    totalProf = totalProf + jobProfitVec[masterJobList[i]];
  }
  cout << "Total profit: " << totalProf << endl;
}
