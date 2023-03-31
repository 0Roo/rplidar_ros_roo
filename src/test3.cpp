#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  // 레이저 스캔 데이터로부터 PointCloud를 생성
  // 여기에서는 각도와 거리를 기반으로 2D 좌표계에서 3D 좌표계로 변환합니다.
  // 레이저 스캔 데이터는 scan->ranges 배열에 저장되어 있습니다.
  for (unsigned int i = 0; i < scan->ranges.size(); i++)
  {
    float range = scan->ranges[i];
    float angle = scan->angle_min + i * scan->angle_increment;

    if (range < scan->range_min || range > scan->range_max)
      continue;

    pcl::PointXYZ point;
    point.x = range;
    point.y = 0;
    point.z = 0;

    cloud->points.push_back(point);
  }

  cloud->width = cloud->points.size();
  cloud->height = 1;
  cloud->is_dense = true;

  sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(*cloud, output);
  output.header.frame_id = scan->header.frame_id;

  // 변환된 PointCloud를 publish
  // ROS에서는 PointCloud2를 사용합니다.
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("output_topic", 1);
  pub.publish(output);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "laser_to_pointcloud");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe<sensor_msgs::LaserScan>("input_topic", 1, scanCallback);

  ros::spin();

  return 0;
}
