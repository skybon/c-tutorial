#include <stdio.h>

void main(){
	int width;
	int height;
	printf("Введите ширину холста: ");
	scanf("%i", &width);
	printf("Введите высоту холста: ");
	scanf("%i", &height);

	int canvas[height][width];
	printf("Создан холст размером %i x %i \n", width, height);


	int cell_height;
	int cell_width;
	printf("Введите ширину ячеек: ");
	scanf("%i", &cell_width);
	printf("Введите высоту ячеек: ");
	scanf("%i", &cell_height);

	int i;
	int j;

	printf("\n\n# Создано следующее PBM-изображение:\n\n\nP1\n%i %i\n", width, height);
	for (i=0;i<height;i++){
		if (i % (cell_height+1) == 0){						//каждая строка у которой остаток 0 заполняется единицей (ГОРИЗ. ГРАНИЦА)
			for (j=0;j<width;j++){
				canvas[i][j]=1;
				printf("%d", canvas[i][j]);
			}
		}
		else {
			for (j=0;j<width;j++){
				if (j % (cell_width+1) == 0){				//вставляем 1 если остаток столбец/ширина = 0 (ВЕРТ. ГРАНИЦА)
					canvas[i][j]=1;
				}
			printf("%d", canvas[i][j]);
			}
		}
		printf("\n");								//рисуем след строку
	}
	printf("\n");
}
