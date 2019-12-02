#include "ros/ros.h" 
#include <iostream> 
#include "std_msgs/Int32.h" 

using namespace std; 

void receive(const std_msgs::Int32& msg) {
	cout << ros::this_node::getName() << ": data: " << msg.data << endl;
	return;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "subscriber");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/topic", 1000, receive);
	ros::spin();
	return 0;
}