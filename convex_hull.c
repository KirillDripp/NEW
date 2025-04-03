#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "convex_hull.h"

// Функція для визначення орієнтації трьох точок (лівий, чи правий поворот)
int ccw(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val > 0) ? 1 : (val < 0) ? -1 : 0;  // 1 - за годинниковою стрілкою, -1 - проти, 0 - колінеарні
}

// Функція для обчислення кута між точками
double getAngle(Point p, Point q) {
    return atan2(q.y - p.y, q.x - p.x);  // Повертаємо кут у радіанах
}

// Функція порівняння точок за координатами (для сортування та знаходження найлівої)
int compare_points(const void *a, const void *b) {
    const Point *p1 = (const Point *)a;
    const Point *p2 = (const Point *)b;
    if (p1->x == p2->x) {
        return p1->y - p2->y;
    }
    return p1->x - p2->x;
}

// Функція для порівняння точок за полярним кутом
int compare_by_polar_angle(const void *a, const void *b) {
    const Point *p1 = (const Point *)a;
    const Point *p2 = (const Point *)b;
    double angle1 = getAngle({0, 0}, *p1);
    double angle2 = getAngle({0, 0}, *p2);
    if (angle1 == angle2) {
        return compare_points(a, b);
    }
    return (angle1 < angle2) ? -1 : 1;
}

void convexHull(Point points[], int n, Point result[], int *result_size) {
    if (n < 3) {
        *result_size = 0;
        return;
    }

    qsort(points, n, sizeof(Point), compare_points);  // Сортуємо точки за координатами

    Point hull[n];
    int hull_size = 0;

    // Додаємо першу точку на оболонку
    hull[hull_size++] = points[0];

    // Виповнюємо оболонку з точок
    for (int i = 1; i < n; i++) {
        while (hull_size > 1 && ccw(hull[hull_size - 2], hull[hull_size - 1], points[i]) != 1) {
            hull_size--;
        }
        hull[hull_size++] = points[i];
    }

    *result_size = hull_size;
    for (int i = 0; i < hull_size; i++) {
        result[i] = hull[i];
    }

    // Логування результату
    printf("Convex Hull result:\n");
    for (int i = 0; i < *result_size; i++) {
        printf("(%d, %d)\n", result[i].x, result[i].y);
    }
}
