#include "ros/ros.h"
#include "my_service/Determinant.h"

bool determ(my_service::Determinant::Request &req,
    my_service::Determinant::Response &res)
{
	res.det = req.first*req.fifth*req.ninth+req.seventh*req.second*req.sixth+req.fourth*req.eighth*req.third-req.seventh*req.fifth*req.third-req.first*req.eighth*req.sixth-req.fourth*req.second*req.ninth;
	ROS_INFO("request:a11=%d;a12=%d;a13=%d;a21=%d;a22=%d;a23=%d;a31=%d;a32=%d;a33=%d;",req.first,req.second,req.fourth,req.fifth,req.sixth,req.seventh,req.eighth,req.ninth);
	ROS_INFO("sending back response:[%f]",res.det);
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"determinant_of_matrix_server");
	ros::NodeHandle n;
	ros::ServiceServer service=n.advertiseService("determinant_of_matrix",determ);
	ROS_INFO("READY TO FIND DETERMINANT");
	ros::spin();
	return 0;
}
