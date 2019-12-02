#include "ros/ros.h" 
#include <iostream> 
#include "std_msgs/Int32.h" 

using namespace std; 

int main(int argc, char **argv) 
{ 
ros::init(argc, argv, "node"); 

ros::NodeHandle n; 
ros::Publisher pub = n.advertise<std_msgs::Int32>("/topic", 1000); 
ros::Rate loop_rate(1); 

std_msgs::Int32 msg;
int a; 
while (cin » a) {
loop_rate.sleep(); 
msg.data = a; 
pub.publish(msg); 
loop_rate.sleep(); 
} 
ros::spinOnce(); 
return 0; 
} 