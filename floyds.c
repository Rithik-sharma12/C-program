#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int cost[10][10], a[10][10];
void all_paths(int cost[10][10], int a[10][10], int n);
int min1(int a, int b);
void main() {
 int i, j, n;
 clrscr();
 printf("\nEnter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the adjacency matrix:\n");
 for (i = 1; i <= n; i++) {
 for (j = 1; j <= n; j++) {
 scanf("%d", &cost[i][j]);
 }
 }
 all_paths(cost, a, n);
 printf("\nShortest path obtained is:\n");
 for (i = 1; i <= n; i++) {
 for (j = 1; j <= n; j++) {
 printf("\t%d", a[i][j]);
 }
 printf("\n");
 }
 getch();
}
void all_paths(int cost[10][10], int a[10][10], int n) {
 int i, j, k;

 for (i = 1; i <= n; i++) {
 for (j = 1; j <= n; j++) {
 a[i][j] = cost[i][j];
 }
 }
 for (k = 1; k <= n; k++) {
 for (i = 1; i <= n; i++) {
 for (j = 1; j <= n; j++) {
 a[i][j] = min1(a[i][j], a[i][k] + a[k][j]);
 }
 }
 }
}
int min1(int a, int b) {
 return (a < b) ? a : b;
}
