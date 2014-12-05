#include <stdio.h>

//typedef struct Timage Timage;

struct Timage {
int width;								//ширина холста
int height;								//высота холста
int canvas[100][100];							//сам холст
};
//ФЛАГИ
int flag_interactive=0;
int flag_interactive_canvas=0;

struct Timage a;

void draw_horizontal_line(int hline_y,int hline_length) {		//горизонтальная линия длиной в холст
	int x;								//счётчик

	for (x=0;x<hline_length;x++) {
		a.canvas[x][hline_y]=1;
	}
}

void draw_vertical_line(int vline_x,int vline_length) {			//вертикальная линия длиной в холст
	int y;								//счётчик

	for (y=0;y<vline_length;y++){
		a.canvas[vline_x][y]=1;
	}
}

void draw_grid(){
	int hpos;							//счётчик
	int ypos;							//счётчик

	int grid_height;
	int grid_width;

	int cell_height;
	int cell_width;

	if (flag_interactive==1) {
		printf("# Введите ширину сетки: ");
		scanf("%i", &grid_width);
		printf("# Введите высоту сетки: ");
		scanf("%i", &grid_height);
		printf("# Введите ширину ячеек: ");
		scanf("%i", &cell_width);
		printf("# Введите высоту ячеек: ");
		scanf("%i", &cell_height);
	}
	else {
		grid_width=50;
		grid_height=50;
		cell_width=5;
		cell_height=5;
	}

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
	printf("P1\n##################################\n#\n# Создано следующее PBM-изображение:\n#\n##################################\n#\n# CREATED BY PBM GENERATOR 0.1\n# (c) Artem Vorotnikov <artem@vorotnikov.me>, 2014\n#\n##################################\n#\n%i %i\n", a.width, a.height);
	int x;
	int y;

	for (y=0;y<a.height;y++){
		for(x=0;x<a.width;x++){
			printf("%d ",a.canvas[x][y]);
		}
		printf("\n");
	}
}

void init(int w, int h) {
	if (flag_interactive_canvas==1) {
	printf("Введите ширину холста: ");
	scanf("%i", w);
	printf("Введите высоту холста: ");
	scanf("%i", h);
	}
    //else {
        //w=100;
        //h=100;
    //}
    a.width=w;
    a.height=h;
	if (flag_interactive==1){
		printf("# Создан холст размером %i x %i \n", w, h);
	}
}

int main(){
	init(10,10);
	if (flag_interactive==1) {
		int action_choice;						//выбор действия
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
	else {
		draw_grid();
		show();
	}

	return 0;
}
