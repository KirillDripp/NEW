#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

typedef struct {
    int x;
    int y;
} Point;

// Додаємо оператор порівняння для точок
inline bool operator<(const Point& p1, const Point& p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;  // Якщо x координати однакові, порівнюємо за y
    }
    return p1.x < p2.x;  // Інакше порівнюємо за x
}

// Функція для визначення орієнтації трьох точок
int ccw(Point p, Point q, Point r);

// Функція для обчислення кута між точками
double getAngle(Point p, Point q);

// Функція для порівняння точок за координатами
int compare_points(const void *a, const void *b);

// Функція для порівняння точок за полярним кутом
int compare_by_polar_angle(const void *a, const void *b);

// Основна функція для побудови опуклої оболонки
void convexHull(Point *points, int n, Point *result, int *result_size);

#endif // CONVEX_HULL_H
