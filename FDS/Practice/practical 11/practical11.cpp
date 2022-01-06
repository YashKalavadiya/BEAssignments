#include "iostream"

using namespace std;


class Queue {
	int front = 0, rear = 0;
	int jobs[10];

public:

	void addJob(int job) {
		if(rear < 10) {
			jobs[rear] = job;
			rear += 1;
		}
		else{
			cout<<"\nQueue is FULL!!!!!!";
		}
	}

	void removeJob() {
		if(front < rear) {
			cout<<"\nJob: "<<jobs[front]<<" removed";
			front += 1;
		}
		else{
			cout<<"\nQueue is alredy EMPTY!!!!";
		}
	}

	void printJobQueue() {
		if(front < rear) {
			for(int i = front; i < rear; i++) {
				cout<<"\n"<<i<<" : "<<jobs[i];
			}
		}
		else{
			cout<<"\nQueue is EMPTY!!!!";
		}
	}

	void resetQueue() {
		front = 0;
		rear = 0;
	}

	void printMenu() {
		cout<<"\nMENU";
		cout<<"\n1. Add JOB";
		cout<<"\n2. Remove JOB";
		cout<<"\n3. Display Job Queue";
		cout<<"\n4. Reset Queue";
		cout<<"\n5. EXIT";
	}

	void execute() {
		bool isExit = false;
		while(!isExit) {
			printMenu();
			cout<<"\nEnter your choice: ";
			int ch;
			int job;
			cin>>ch;
			switch(ch) {
			case 1:
				cout<<"\nEnter JOB: ";
				cin>>job;
				addJob(job);
				break;
			case 2:
				removeJob();
				break;
			case 3:
				printJobQueue();
				break;
			case 4:
				resetQueue();
				break;
			case 5:
				isExit = true;
				break;
			}
		}
	}
};

int main() {

	Queue q;
	q.execute();
	return 0;
}
