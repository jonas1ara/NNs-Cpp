#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utilidades/img.h"
#include "neurona/activations.h"
#include "neurona/nn.h"
#include "matriz/matrix.h"
#include "matriz/ops.h"

int main() {
	srand(time(NULL));

	// ENTRENAMIENTO
	int number_imgs = 10000;
	Img** imgs = csv_to_imgs("datos/mnist_train.csv", number_imgs);
	NeuralNetwork* net = network_create(784, 300, 10, 0.1);
	network_train_batch_imgs(net, imgs, number_imgs);
	network_save(net, "testeo_neuronal");

	// // PREDICCIÓN
	// int number_imgs = 3000;
	// Img** imgs = csv_to_imgs("datos/mnist_train.csv", number_imgs);
	// NeuralNetwork* net = network_load("testeo_neuronal");
	// double score = network_predict_imgs(net, imgs, 1000);
	// printf("Score: %1.5f \n", score);

	imgs_free(imgs, number_imgs);
	network_free(net);
	return 0;
}