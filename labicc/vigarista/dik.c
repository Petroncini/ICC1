#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int format;
  char comment[100];
  int xDim;
  int yDim;
  int maxVal;
  int minVal;
  int **pixels;
} image;

int **mallocMatrix(int x, int y);
void loadImage(image *img);
image processImage(image img);
void saveImage(image img);
void freeMatrix(int **matrix);

int main(void) {
  image img;
  loadImage(&img);

  image processed = processImage(img);
  saveImage(processed);

  freeMatrix(processed.pixels);
  freeMatrix(img.pixels);

  return 0;
}

int **mallocMatrix(int x, int y) { // aloca memória para os pixels da imagem
  int *matrix;
  if ((matrix = malloc(sizeof(int) * x * y)) == NULL) {
    printf("Failed to allocate memory for matrix\n");
    exit(1);
  }
  int **pointers;
  if ((pointers = malloc(sizeof(int *) * x)) == NULL) {
    printf("Failed to allocate memory for pointers\n");
    free(matrix);
    exit(1);
  }

  for (int i = 0; i < x; i++) {
    pointers[i] = matrix + i * y;
  }

  return pointers;
}

void loadImage(
    image *img) { // recebe o nome do arquivo do usuario e carrega a imagem
  char filename[50];

  fgets(filename, 50, stdin);
  filename[strlen(filename) - 1] = '\0';

  FILE *img_source;

  if ((img_source = fopen(filename, "r")) == NULL) {
    printf("Failed to load file\n");
    exit(1);
  }

  fscanf(img_source, "P%i\n", &img->format);

  fgets(img->comment, 100, img_source);

  fscanf(img_source, "%i %i\n", &img->xDim, &img->yDim);

  img->pixels = mallocMatrix(img->xDim, img->yDim);

  fscanf(img_source, "%i\n", &img->maxVal);
  img->maxVal = -1;

  img->minVal = 256;

  for (int i = 0; i < img->xDim; i++) {
    for (int j = 0; j < img->yDim; j++) {
      if (img->format == 2) {
        fscanf(img_source, "%i", &img->pixels[i][j]);
      } else {
        fread(&img->pixels[i][j], 1, 1, img_source);
      }

      if (img->pixels[i][j] < img->minVal) {
        img->minVal = img->pixels[i][j];
      }

      if (img->pixels[i][j] > img->maxVal) {
        img->maxVal = img->pixels[i][j];
      }
    }
  }
  fclose(img_source);
}

image processImage(
    image img) { // processa a imagem usando o operador logaritmico
  image out;
  out.format = 2;
  out.xDim = img.xDim;
  out.yDim = img.yDim;
  out.maxVal = -1;
  out.minVal = 256;
  out.pixels = mallocMatrix(out.xDim, out.yDim);
  strcpy(out.comment, "# CREATOR: Image Generator SCC-222 – Lab ICC I\n");

  float c = 255.0 / (log(1.0 + img.maxVal));

  for (int i = 0; i < img.xDim; i++) {
    for (int j = 0; j < img.yDim; j++) {
      out.pixels[i][j] = c * (log(1.0 + img.pixels[i][j]));

      if (out.pixels[i][j] < out.minVal) {
        out.minVal = out.pixels[i][j];
      }

      if (out.pixels[i][j] > out.maxVal) {
        out.maxVal = out.pixels[i][j];
      }
    }
  }

  return out;
}

void saveImage(
    const image img) { // salva a imagem e printa o que é salvo no terminal
  FILE *img_destination;
  if ((img_destination = fopen("out.pgm", "w")) == NULL) {
    printf("Failed to open output file\n");
    exit(1);
  }

  fprintf(img_destination, "P%i\n", img.format);
  printf("P%i\n", img.format);

  fputs(img.comment, img_destination);
  printf("%s", img.comment);

  fprintf(img_destination, "%i %i\n", img.xDim, img.yDim);
  printf("%i %i\n", img.xDim, img.yDim);

  fprintf(img_destination, "%i\n", img.maxVal);
  printf("%i\n", img.maxVal);

  for (int i = 0; i < img.xDim; i++) {
    for (int j = 0; j < img.yDim; j++) {
      fprintf(img_destination, "%i\n", img.pixels[i][j]);
      printf("%i\n", img.pixels[i][j]);
    }
  }
  fclose(img_destination);
}

void freeMatrix(
    int **matrix) { // desaloca a memoria usada para guardar os pixels
  free(matrix[0]);
  free(matrix);
}
