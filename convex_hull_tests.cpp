#include <gtest/gtest.h>
#include "convex_hull.h"
#include <set>

bool point_equal(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

bool point_in_set(const std::set<Point> &points_set, const Point &p) {
    return points_set.find(p) != points_set.end();
}

TEST(ConvexHullTest, TestConvexHullWithMultiplePoints) {
    Point points[] = {{0, 0}, {2, 0}, {2, 2}, {1, 3}, {0, 2}};
    int n = 5;
    Point result[5];
    int result_size = 0;

    convexHull(points, n, result, &result_size);

    std::set<Point> expected_points = {{0, 0}, {2, 0}, {1, 3}, {0, 2}, {2, 2}};
    for (int i = 0; i < result_size; i++) {
        EXPECT_TRUE(point_in_set(expected_points, result[i]));
    }
}

TEST(ConvexHullTest, TestConvexHullWithCollinearPoints) {
    Point points[] = {{0, 0}, {1, 1}, {2, 2}};
    int n = 3;
    Point result[3];
    int result_size = 0;

    convexHull(points, n, result, &result_size);

    std::set<Point> expected_points = {{0, 0}, {2, 2}};
    for (int i = 0; i < result_size; i++) {
        EXPECT_TRUE(point_in_set(expected_points, result[i]));
    }
}

TEST(ConvexHullTest, TestConvexHullWithSinglePoint) {
    Point points[] = {{0, 0}};
    int n = 1;
    Point result[1];
    int result_size = 0;

    convexHull(points, n, result, &result_size);

    ASSERT_EQ(result_size, 0);
}

TEST(ConvexHullTest, TestConvexHullWithNoPoints) {
    Point points[] = {};
    int n = 0;
    Point result[0];
    int result_size = 0;

    convexHull(points, n, result, &result_size);

    ASSERT_EQ(result_size, 0);
}
