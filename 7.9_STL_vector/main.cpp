#include <iostream>
#include <vector> // 包含向量容器头文件

using namespace std;

int main()
{
    int i;
    vector<int> nums; // 整形向量，长度为0
    nums.insert(nums.begin(), -99); // 在向量第1个位置插入-99
    nums.insert(nums.begin(), 4); // 在向量第1个位置插入4
    nums.insert(nums.end(), 50); // 在向量末尾插入50

    for(i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";  // 依次输出向量中所有元素：4 -99 50
    cout << endl;

    nums.erase(nums.begin()); // 删除向量中第1个元素4
    nums.erase(nums.begin()); // 删除向量中第1个元素-99

    for(i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";  // 依次输出向量中所有元素：50
    cout << endl;

    return 0;
}
/********* 运行结果：**********/
/********* 4 -99 50 **********/
/********* 50       **********/