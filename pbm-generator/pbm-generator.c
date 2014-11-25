#include <stdio.h>
int width=100;								//ширина холста
int height=100;								//высота холста

int canvas[100][100];							//сам холст

void draw_horizontal_line(int hline_y,int hline_length) {		//горизонтальная линия длиной в холст
	int x;								//счётчик

	for (x=0;x<hline_length;x++) {
		canvas[x][hline_y]=1;
	}
}

void draw_vertical_line(int vline_x,int vline_length) {			//вертикальная линия длиной в холст
	int y;								//счётчик

	for (y=0;y<vline_length;y++){
		canvas[vline_x][y]=1;
	}
}

void draw_grid(){
	int hpos;							//счётчик
	int ypos;							//счётчик

	int grid_height;
	int grid_width;

	int cell_height;
	int cell_width;


	printf("# Введите ширину сетки: ");
	scanf("%i", &grid_width);
	printf("# Введите высоту сетки: ");
	scanf("%i", &grid_height);
	printf("# Введите ширину ячеек: ");
	scanf("%i", &cell_width);
	printf("# Введите высоту ячеек: ");
	scanf("%i", &cell_height);

	for (ypos=0;ypos<grid_width;ypos++){
		if (ypos % (cell_width+1) == 0){
			draw_vertical_line(ypos, grid_height);
		}
	}

	for (hpos=0;hpos<grid_height;hpos++){
		if (hpos % (cell_height+1) == 0){			//+1 т.к. 1 пиксель между ячейками (граница)
			draw_horizontal_line(hpos, grid_width);
		}
	}
}

void show() {
	printf("##################################\n\n# Создано следующее PBM-изображение:\n\n##################################\n\n# CREATED BY PBM GENERATOR 0.1 #\n# (c) Artem Vorotnikov <artem@vorotnikov.me>, 2014\n\n##################################\n\nP1\n%i %i\n", width, height);
	int x;
	int y;

	for (y=0;y<height;y++){
		for(x=0;x<width;x++){
			printf("%d ",canvas[x][y]);
		}
		printf("\n");
	}
}

void init() {

	//printf("Введите ширину холста: ");
	//scanf("%i", &width);
	//printf("Введите высоту холста: ");
	//scanf("%i", &height);

	//int canvas[width][height];


	printf("Создан холст размером %i x %i \n", width, height);
}

void main(){
	int action_choice;						//выбор действия
	init();
	printf("# Выберите действие (0 для помощи): ");
	scanf("%i", &action_choice);
	if (action_choice==0) {
		printf("# Доступны следующие действия:\n    1 - вывести изображение на экран и выйти.\n    2 - нарисовать сетку.\n");
	}
	else if (action_choice==1) {
		show();
	}
	else if (action_choice==2) {
		draw_grid();
		show();
	}
}