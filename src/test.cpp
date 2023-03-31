//
// Tutorial Author: shapelim@kaist.ac.kr (임형태)

#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>

using namespace std;

template<class T>
void print_pc(pcl::PointCloud<T> &cloud) {
    int count = 0;
    for (const auto &pt: cloud.points) {
        cout << count++ << ": ";
        cout << pt.x << ", " << pt.y << ", " << pt.z << endl;
    }
}
template<class T2>
void print_pc2(pcl::PointCloud<T2> &cloud) {
    int count = 0;
    for (const auto &pt: cloud.points) {
        cout << count++ << ": ";
        cout << pt.x << ", " << pt.y << endl;
    }
}
int main(int argc, char**argv) {
    
    pcl::PointCloud<pcl::PointXYZ> cloud_init0;
    
    cloud_init0.resize(3); //cloud의 size를 3으로 설정

    cloud_init0.points[0].x = 1;cloud_init0.points[0].y = 2;cloud_init0.points[0].z = 3;
    cloud_init0.points[1].x = 4;cloud_init0.points[1].y = 5;cloud_init0.points[1].z = 6;
    cloud_init0.points[2].x = 7;cloud_init0.points[2].y = 8;cloud_init0.points[2].z = 9;

    cout << "cloud_init0:  " << endl;
    print_pc(cloud_init0);
    cout << "==============" << endl;

    pcl::PointCloud<pcl::PointXYZ> cloud_init1;
    pcl::PointXYZ                  point_xyz; // pcl::PointXYZ이라는 type에 data를 담는다.

    point_xyz.x = 1;
    point_xyz.y = 2;
    point_xyz.z = 3;
    cloud_init1.push_back(point_xyz);
    point_xyz.x = 4;
    point_xyz.y = 5;
    point_xyz.z = 6;
    cloud_init1.push_back(point_xyz);
    point_xyz.x = 7;
    point_xyz.y = 8;
    point_xyz.z = 9;
    cloud_init1.push_back(point_xyz);
    cout << "cloud_init1:  " << endl;
    print_pc(cloud_init1);
    cout << "==============" << endl;

    pcl::PointCloud<pcl::PointXYZ> cloud_init2;
    cloud_init2.push_back(pcl::PointXYZ(1, 2, 3));
    cloud_init2.push_back(pcl::PointXYZ(4, 5, 6));
    cloud_init2.push_back(pcl::PointXYZ(7, 8, 9));
    cout << "cloud_init2:  " << endl;
    print_pc(cloud_init2);
    cout << "==============" << endl;


    //연습
    pcl::PointCloud<pcl::PointXY> cloud_init_test;
    pcl::PointXY point_xy;
    point_xy.x = 1; point_xy.y=0; point_xy.x = 2;
    cloud_init_test.push_back(point_xy);
    cout <<"cloud_init_test:" <<endl;
    print_pc2(cloud_init_test);
    cout << "==============" << endl;

    pcl::PointCloud<pcl::PointXY> cloud_init_test2;
    point_xy.x = 2; point_xy.y=0;
    cloud_init_test2.push_back(point_xy);
    cout <<"cloud_init_test2:" <<endl;
    print_pc2(cloud_init_test2);
    cout << "==============" << endl;

    cloud_init_test += cloud_init_test2;
    cout <<"cloud_init_test_after:" <<endl;
    print_pc2(cloud_init_test);
    cout << "==============" << endl;   

    // 여기까지


    pcl::PointCloud<pcl::PointXYZ> cloud2;
    cloud2.push_back(pcl::PointXYZ(1, 2, 3));
    cloud2.push_back(pcl::PointXYZ(4, 5, 6));


    pcl::PointCloud<pcl::PointXYZ> cloud3;
    cloud3.push_back(pcl::PointXYZ(7, 8, 9));
    cloud3.push_back(pcl::PointXYZ(10, 11, 12));

    cloud2 += cloud3;

    cout << "size: " << cloud2.size() << endl;
    print_pc(cloud2);

    cloud3.push_back(pcl::PointXYZ(12, 13, 14));
    cout << "After: " << endl;
    print_pc(cloud3);

}
