//#include <iostream>
#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "tf2_msgs/TFMessage.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Vector3.h"
/////////////////////
#include "tf/transform_datatypes.h"
#include "sys/types.h"// 
#include "sys/socket.h"//
#include "netinet/in.h"//
#include "stdio.h"// 
#include "string.h"// 
#include "thread"//
#include <termios.h>
#include "math.h"
using namespace std;
using std::thread;
void TcpThread1();
double roll0, pitch0, yaw0, roll1, pitch1, yaw1, roll2, pitch2, yaw2, roll3, pitch3, yaw3, roll4, pitch4, yaw4, roll5, pitch5, yaw5;
bool exiT = true;
bool moveD = true;
double e = 1.0e-4;
////////////////////

    void tfCallback(const tf2_msgs::TFMessage::ConstPtr& msg)
    {
	int len;
	int sock;
	int i;
	int z;
	    
	string jj1;
	string jj2;
	string jj3;
	string jj4;
	string jj5;
	string jj6;
	string Jinfo;
	    
    struct sockaddr_in addr;
	struct sockaddr_in client;
	    
if(exiT==true){
	/* ソケットの作成 */
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	/* ソケットの設定 */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(sock, (struct sockaddr*) & addr, sizeof(addr));

	/* TCPクライアントからの接続要求を待てる状態にする */
	listen(sock, 1);
	
	/* TCPクライアントからの接続要求を受け付ける */
	len = sizeof(client);
	sock = accept(sock, (struct sockaddr*) & client, (socklen_t*)& len);
}

   exiT = false;
   z = 1;
	ROS_INFO("J1: [%lf, %lf, %lf, %lf]", msg->transforms[0].transform.rotation.x, msg->transforms[0].transform.rotation.y , msg->transforms[0].transform.rotation.z, msg->transforms[0].transform.rotation.w);
	ROS_INFO("J2: [%lf, %lf, %lf, %lf]", msg->transforms[1].transform.rotation.x, msg->transforms[1].transform.rotation.y , msg->transforms[1].transform.rotation.z, msg->transforms[1].transform.rotation.w);
	ROS_INFO("J3: [%lf, %lf, %lf, %lf]", msg->transforms[2].transform.rotation.x, msg->transforms[2].transform.rotation.y , msg->transforms[2].transform.rotation.z, msg->transforms[2].transform.rotation.w);
    ROS_INFO("J4: [%lf, %lf, %lf, %lf]", msg->transforms[3].transform.rotation.x, msg->transforms[3].transform.rotation.y , msg->transforms[3].transform.rotation.z, msg->transforms[3].transform.rotation.w);
	ROS_INFO("J5: [%lf, %lf, %lf, %lf]", msg->transforms[4].transform.rotation.x, msg->transforms[4].transform.rotation.y , msg->transforms[4].transform.rotation.z, msg->transforms[4].transform.rotation.w);
	ROS_INFO("J6: [%lf, %lf, %lf, %lf]", msg->transforms[5].transform.rotation.x, msg->transforms[5].transform.rotation.y , msg->transforms[5].transform.rotation.z, msg->transforms[5].transform.rotation.w);

//////////////////////////////////////
tf::Quaternion q0(
        msg->transforms[0].transform.rotation.x,
        msg->transforms[0].transform.rotation.y, 
        msg->transforms[0].transform.rotation.z,
        msg->transforms[0].transform.rotation.w);
tf::Quaternion q1(
        msg->transforms[1].transform.rotation.x,
        msg->transforms[1].transform.rotation.y, 
        msg->transforms[1].transform.rotation.z,
        msg->transforms[1].transform.rotation.w);
tf::Quaternion q2(
        msg->transforms[2].transform.rotation.x,
        msg->transforms[2].transform.rotation.y, 
        msg->transforms[2].transform.rotation.z,
        msg->transforms[2].transform.rotation.w);
tf::Quaternion q3(
        msg->transforms[3].transform.rotation.x,
        msg->transforms[3].transform.rotation.y, 
        msg->transforms[3].transform.rotation.z,
        msg->transforms[3].transform.rotation.w);
tf::Quaternion q4(
        msg->transforms[4].transform.rotation.x,
        msg->transforms[4].transform.rotation.y, 
        msg->transforms[4].transform.rotation.z,
        msg->transforms[4].transform.rotation.w);
tf::Quaternion q5(
        msg->transforms[5].transform.rotation.x,
        msg->transforms[5].transform.rotation.y, 
        msg->transforms[5].transform.rotation.z,
        msg->transforms[5].transform.rotation.w);
	    
tf::Matrix3x3 m0(q0);
tf::Matrix3x3 m1(q1);
tf::Matrix3x3 m2(q2);
tf::Matrix3x3 m3(q3);
tf::Matrix3x3 m4(q4);
tf::Matrix3x3 m5(q5);

m0.getRPY(roll0, pitch0, yaw0);
m1.getRPY(roll1, pitch1, yaw1);
m2.getRPY(roll2, pitch2, yaw2);
m3.getRPY(roll3, pitch3, yaw3);
m4.getRPY(roll4, pitch4, yaw4);
m5.getRPY(roll5, pitch5, yaw5);

if (isinf(yaw0) || isnan(yaw0) || isinf(pitch1) || isnan(pitch1) || isinf(pitch2) || isnan(pitch2) || isinf(yaw3) || isnan(yaw3) || isinf(pitch4) || isnan(pitch4) || isinf(yaw5) || isnan(yaw5)) {
	z = 0;
}
if (fabs(yaw0) <= e || fabs(pitch1) <= e || fabs(pitch2) <= e || fabs(yaw3) <= e || fabs(pitch4) <= e || fabs(yaw5) <= e) {
	z = 0;
}

std::cout << "Roll: " << roll0 << ", Pitch: " << pitch0 << ", Yaw: " << yaw0 << std::endl;
std::cout << "Roll: " << roll1 << ", Pitch: " << pitch1 << ", Yaw: " << yaw1 << std::endl;
std::cout << "Roll: " << roll2 << ", Pitch: " << pitch2 << ", Yaw: " << yaw2 << std::endl;
std::cout << "Roll: " << roll3 << ", Pitch: " << pitch3 << ", Yaw: " << yaw3 << std::endl;
std::cout << "Roll: " << roll4 << ", Pitch: " << pitch4 << ", Yaw: " << yaw4 << std::endl;
std::cout << "Roll: " << roll5 << ", Pitch: " << pitch5 << ", Yaw: " << yaw5 << std::endl;

if (z == 1) {

if (fabsf(roll2) > 3.0f) {
	pitch2 = 1.5708f + 1.5708f - pitch2;
}


if (fabsf(roll4) > 3.0f) {
	pitch2 = 1.5708f + 1.5708f - pitch4;
}

			if (yaw0 < 0.0) {
				jj1 =  to_string(yaw0);
			}
			else {
				jj1 = "+" + to_string(yaw0);
			}

			if (pitch1 < 0.0) {
				jj2 = to_string(pitch1);
			}
			else {
				jj2 = "+" + to_string(pitch1);
			}

			if (pitch2 < 0.0) {
				jj3 = to_string(pitch2);
			}
			else {
				jj3 = "+" + to_string(pitch2);
			}
	    
			if (yaw3 < 0.0) {
				jj4 = to_string(yaw3);
			}
			else {
				jj4 = "+" + to_string(yaw3);
			}

			if (pitch4 < 0.0) {
				jj5 = to_string(pitch4);
			}
			else {
				jj5 = "+" + to_string(pitch4);
			}

			if (yaw5 < 0.0) {
				jj6 = to_string(yaw5);
			}
			else {
				jj6 = "+" + to_string(yaw5);
			}
		
	Jinfo = jj1 + "J" + jj2 + "J" + jj3 + "J" + jj4 + "J" + jj5 + "J" + jj6;
	char JJ[Jinfo.length()];
	for (i = 0; i < 59; i++) {
				JJ[i] = Jinfo[i];
			}
			write(sock, JJ, strlen(JJ));
}
}

/////////////////////////////////////////////

int main(int argc, char **argv)

{
    ros::init(argc, argv, "tf_subscriber_node");

    ros::NodeHandle ntf;

    ros::Subscriber sub = ntf.subscribe("/tf",10, tfCallback);

    ros::spin ();

    ros::waitForShutdown();

    return 0;

}
