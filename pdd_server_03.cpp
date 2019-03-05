#include<iostream>
using namespace std;

#include<stack>

/*
my first idea is BFS, on this occasion, search the neighbour is easy,
but mark the visited are difficult.
SO for the time consideration, I choose an most easy way to realize:
just search line by line , after one line finished , turn to the next line's leftmost position

sorry, I ignore the irregular are four directions.. it is too troublesome.
Turn to BFS again.
*/
struct Node{
	int x, y;
	int status;//0 undiscovered, 1, visited
	Node(int x, int y) :x(x), y(y), status(0){}
};

class Solution {
public:
	int getArea() {
		int area = 0;
		stack<Node> stack;
		stack.push(Node(0, 0));
		while (!stack.empty()) {
			Node n = stack.top();
			
			//!!! each node will be into the stack ,so the area is the node Num
			stack.pop();
			area++;
			for (int i = 0; i < 4; i++) {
				//BFS each node will get into the stack
				if (move(i)&&moveN(i).status==0) {
					stack.push(moveN(i));
				}
			}
		}
		return area;
	}
private:
	//direction 0,1,2,3 : forward, backward, left right
	bool move(int direction) {

	}
	//for convenience ,I add this function,
	//get the node after direction
	Node moveN(int direction) {
		/*
		this is easy to implement, just according different directions , get the different node(x,y)
		*/
	}
	/*
	int BFS() {

	}
	*/
};