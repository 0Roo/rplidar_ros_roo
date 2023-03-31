// Tutorial Author: shapelim@kaist.ac.kr (임형태)

#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include "ros/ros.h"
#include <pcl_ros/point_cloud.h>
#include <boost/foreach.hpp>
#include "sensor_msgs/LaserScan.h" 
#include "sensor_msgs/PointCloud2.h"
#include "laser_geometry/laser_geometry.h"
using namespace std;


// template<class T>
// void print_pc(pcl::PointCloud<T> &cloud) {
//     int count = 0;
//     for (const auto &pt: cloud.points) {
//         cout << count++ << ": ";
//         cout << pt.x << ", " << pt.y << endl;
//     }
// }

// void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
// {
//     int count = scan->scan_time / scan->time_increment;
//     ROS_INFO("I heard a laser scan %s[%d]:", scan->header.frame_id.c_str(), count);
//     ROS_INFO("angle_range, %f, %f", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));
//     for(int i = 0; i < count; i++) {
//         float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
//         ROS_INFO(": [%f, %f]", degree, scan->ranges[i]);
//     }
// }

// void callback(const PointCloud::ConstPtr& msg)
// {
//   printf ("Cloud: width = %d, height = %d\n", msg->width, msg->height);
//   BOOST_FOREACH (const pcl::PointXYZ& pt, msg->points)
//     printf ("\t(%f, %f, %f)\n", pt.x, pt.y, pt.z);
// }

// pcl::PointCloud<pcl::PointXYZ> cloudmsg2cloud(sensor_msgs::PointCloud2 cloudmsg)
//   {
//     pcl::PointCloud<pcl::PointXYZ> cloud_dst;
//     pcl::fromROSMsg(cloudmsg, cloud_dst);
//     return cloud_dst;
//   }

// sensor_msgs::PointCloud2 laser2cloudmsg(sensor_msgs::LaserScan laser)
//     {
//       static laser_geometry::LaserProjection projector;
//       sensor_msgs::PointCloud2 pc2_dst;
//       projector.projectLaser(laser, pc2_dst,-1,laser_geometry::channel_option::Intensity | laser_geometry::channel_option::Distance);
//       pc2_dst.header.frame_id = "map";

//       return pc2_dst;
//     }


void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    int count = scan->scan_time / scan->time_increment;
    ROS_INFO("I heard a laser scan %s[%d]:", scan->header.frame_id.c_str(), count);
    ROS_INFO("angle_range, %f, %f", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));
  
    for(int i = 0; i < count; i++) {
        float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
        ROS_INFO(": [%f, %f]", degree, scan->ranges[i]);
    }
}
int main(int argc, char**argv) {

    ros::init(argc, argv, "rplidar_node_client");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);
    ros::spin();
    return 0;   
    // pcl::PointCloud<pcl::PointXYZ> cloud_init;
    // pcl::PointXYZ point_xyz;
    // point_xyz = cloudmsg2cloud(sub);
    // sensor_msgs::PointCloud2 pc = laser2cloudmsg(sub.ranges);
    // pcl::PointCloud<pcl::PointXYZ> cloudmsg2cloud(sensor_msgs::PointCloud2 cloudmsg)
}
