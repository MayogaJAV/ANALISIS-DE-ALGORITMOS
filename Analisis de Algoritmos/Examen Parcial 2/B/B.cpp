#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>
#include <algorithm>
struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

void swap(Point& a, Point& b) {
    Point t = a;
    a = b;
    b = t;
}

int partitionX(std::vector<Point>& points, int low, int high) {
    double pivot = points[high].x;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (points[j].x <= pivot) {
            i++;
            swap(points[i], points[j]);
        }
    }
    swap(points[i + 1], points[high]);
    return (i + 1);
}

void quicksortX(std::vector<Point>& points, int low, int high) {
    if (low < high) {
        int pi = partitionX(points, low, high);
        quicksortX(points, low, pi - 1);
        quicksortX(points, pi + 1, high);
    }
}

bool compareX(Point p1, Point p2) {
    return p1.x < p2.x;
}

bool compareY(Point p1, Point p2) {
    return p1.y < p2.y;
}

double closestPair(std::vector<Point>& points, int left, int right) {
    if (left >= right) {
        return std::numeric_limits<double>::infinity();
    }

    int mid = (left + right) / 2;
    double delta = std::min(closestPair(points, left, mid), closestPair(points, mid + 1, right));

    std::vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (std::abs(points[i].x - points[mid].x) < delta) {
            strip.push_back(points[i]);
        }
    }

    std::sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < delta; j++) {
            delta = std::min(delta, dist(strip[i], strip[j]));
        }
    }

    return delta;
}

int main() {
    int n;

    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);

        for (int i = 0; i < n; i++) {
            std::cin >> points[i].x >> points[i].y;
        }

        quicksortX(points, 0, n - 1);

        double dist = closestPair(points, 0, n - 1);

        if (dist < 10000) {
            std::cout << std::fixed << std::setprecision(4) << dist << std::endl;
        } else {
            std::cout << "INFINITY" << std::endl;
        }
    }

    return 0;
}