class Solution {
public:
    Solution(double radius, double x_center, double y_center): distribution(0, 1), R(radius), X(x_center), Y(y_center) {}
    
    vector<double> randPoint() {
        double theta = distribution(generator) * 2 * PI;
        double r = sqrt(distribution(generator)) * R;
        return {X + r * cos(theta), Y + r * sin(theta)};
    }
private:
    const double PI = 3.1415926535897932384626;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
    const double R;
    const double X;
    const double Y;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */