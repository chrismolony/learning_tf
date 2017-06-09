#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "my_tf_broadcaster");
	ros::NodeHandle node;

	tf::TransformBroadcaster br;
	tf::Transform transform;
  
	ros::Rate rate(10.0);
	while (node.ok()){
		//固定关系
//		transform.setOrigin( tf::Vector3(0.0, 2.0, 0.0) );
//		transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
		//关系是时间的三角函数，且符合 x2 +y2 = r2 将会做画圆运动
		transform.setOrigin( tf::Vector3(2.0*sin(ros::Time::now().toSec()),
					   	2.0*cos(ros::Time::now().toSec()), 0.0));
		transform.setRotation( tf::Quaternion(0, 0, 0, 1));
		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "turtle1", "carrot1"));
		rate.sleep();
     }
	return 0;
};
