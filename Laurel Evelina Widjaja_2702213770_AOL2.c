#include<stdio.h>
#include<string.h>

// struct untuk menampung beberapa variabel dengan tipe data yang beragam dari file
struct building{
	char location1[100];
	char location2[100];
	int price;
	int room;
	int bathroom;
	int carPark;
	char type[100];
	char furnish[100];
};

// untuk memanggil struct secara global
struct building data[10000];
struct building temp; //untuk kebutuhan sorting

// fungsi untuk menampilkan menu pilihan -> mengembalikan angka pilihan dari input user ke int main
int pilihan(){
	int choice;
	do{
		printf("What do you want to do?\n");
		printf("1. Display Data\n");
		printf("2. Search Data\n");
		printf("3. Sort Data\n");
		printf("4. Export Data\n");
		printf("5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &choice); getchar();
	} while(choice < 1 || choice > 5);
	
	return choice;
}

// menu 1 -> display data
void display_data(){
	int row = 0, i, n;
	
	// membaca file
	FILE *fin = fopen("file.csv", "r");
	fscanf(fin, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n"); // supaya baris 1 dari file (yang berisi judul) tidak ikut tersimpan di struct
	while (!feof(fin)) {
    	fscanf(fin, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", data[row].location1, data[row].location2, &data[row].price, &data[row].room, &data[row].bathroom, &data[row].carPark, data[row].type, data[row].furnish);
        row++;
    }
    
	// validasi jumlah baris yang ingin ditampilkan harus lebih dari atau sama dengan 1
	do{
		printf("Number of rows: ");
		scanf("%d", &n); getchar();
	} while(n < 1);
	printf("\n");
	
	// untuk memenuhi kondisi jika input user lebih dari jumlah baris dalam file, maka akan menampilkan semua data dalam file
	if(n > row){
		n = row-1;
	}
	
	// menampilkan data pada internal program 
	printf("%-15s \t %-12s \t %-6s \t %-3s \t %-3s \t %-3s \t %-8s \t %-8s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"); // untuk judul
	for(i=0; i<n; i++){
		printf("%-15s \t %-12s \t %-6d \t %-3d \t %-6d \t %-6d \t %-8s \t %-8s\n", data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathroom, data[i].carPark, data[i].type, data[i].furnish);
	}
	
	fclose(fin);
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

// menu 2 -> search data
void search_data(){
	int i, j, row = 0, flag = 0, target_int;
	int store[10000];
	char column_name[100], target_string[100];
	
	// membaca file
	FILE *fin = fopen("file.csv", "r");
	fscanf(fin, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n"); // supaya baris 1 dari file (yang berisi judul) tidak ikut tersimpan di struct
	while (!feof(fin)) {
    	fscanf(fin, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", data[row].location1, data[row].location2, &data[row].price, &data[row].room, &data[row].bathroom, &data[row].carPark, data[row].type, data[row].furnish);
        row++;
    }
    fclose(fin);
    
    // validasi input nama kolom
    do{
    	printf("Choose column: ");
    	scanf("%[^\n]", column_name); getchar();
	} while(strcmp(column_name, "Location") != 0 && strcmp(column_name, "City") != 0 && strcmp(column_name, "Price") != 0 && strcmp(column_name, "Rooms") != 0 && strcmp(column_name, "Bathroom") != 0 && strcmp(column_name, "Carpark") != 0 && strcmp(column_name, "Type") != 0 && strcmp(column_name, "Furnish") != 0);
    
    // menerima input sesuai dengan tipe data
    printf("What do you want to find? ");
    if(strcmp(column_name, "Location") == 0 || strcmp(column_name, "City") == 0 || strcmp(column_name, "Type") == 0 || strcmp(column_name, "Furnish") == 0){
    	scanf("%[^\n]", target_string); getchar();
	} else if(strcmp(column_name, "Price") == 0 || strcmp(column_name, "Rooms") == 0 || strcmp(column_name, "Bathroom") == 0 || strcmp(column_name, "Carpark") == 0){
		scanf("%d", &target_int); getchar();
	}
    
    // linear search untuk mencari target
	j = 0;
	if(strcmp(column_name, "Location") == 0){ 
		for(i=0; i<row; i++){
			if(strcmp(target_string, data[i].location1) == 0){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "City") == 0){
		for(i=0; i<row; i++){
			if(strcmp(target_string, data[i].location2) == 0){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Price") == 0){
		for(i=0; i<row; i++){
			if(target_int == data[i].price){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Rooms") == 0){
		for(i=0; i<row; i++){
			if(target_int == data[i].room){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Bathroom") == 0){
		for(i=0; i<row; i++){
			if(target_int == data[i].bathroom){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Carpark") == 0){
		for(i=0; i<row; i++){
			if(target_int == data[i].carPark){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Type") == 0){
		for(i=0; i<row; i++){
			if(strcmp(target_string, data[i].type) == 0){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else if(strcmp(column_name, "Furnish") == 0){
		for(i=0; i<row; i++){
			if(strcmp(target_string, data[i].furnish) == 0){
				store[j] = i;
				j++;
				flag = 1;
			}
		}
	} else{
		flag = 0;
	}
	
	// kondisi jika data tidak ditemukan
	if(flag == 0){
		printf("Data not found\n");
		return;
	}
	
	// kondisi jika data ditemukan, maka akan menampilkan semua data dengan nama target
	if(flag == 1){
		printf("Data found. Detail of data:\n");
		printf("%-15s \t %-12s \t %-6s \t %-3s \t %-3s \t %-3s \t %-8s \t %-8s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
	
		for(i=0; i<j; i++){
			printf("%-15s \t %-12s \t %-6d \t %-3d \t %-6d \t %-6d \t %-8s \t %-8s\n", data[store[i]].location1, data[store[i]].location2, data[store[i]].price, data[store[i]].room, data[store[i]].bathroom, data[store[i]].carPark, data[store[i]].type, data[store[i]].furnish);
		}
	}
}

// menu 3 -> sort data
void sort_data(){
	int i, j, row = 0;
	char column_name[100], sort_type[5];
	
	// membaca file
	FILE *fin = fopen("file.csv", "r");
	fscanf(fin, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n");
	while (!feof(fin)) {
    	fscanf(fin, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", data[row].location1, data[row].location2, &data[row].price, &data[row].room, &data[row].bathroom, &data[row].carPark, data[row].type, data[row].furnish);
        row++;
    }
    fclose(fin);
    
    // validasi input nama kolom
    do{
    	printf("Choose column: ");
    	scanf("%[^\n]", column_name); getchar();
	} while(strcmp(column_name, "Location") != 0 && strcmp(column_name, "City") != 0 && strcmp(column_name, "Price") != 0 && strcmp(column_name, "Rooms") != 0 && strcmp(column_name, "Bathroom") != 0 && strcmp(column_name, "Carpark") != 0 && strcmp(column_name, "Type") != 0 && strcmp(column_name, "Furnish") != 0);
    
    // validasi input apakah asc atau desc
    do{
		printf("Sort ascending or descending? ");
		scanf("%[^\n]", sort_type); getchar();
	} while(strcmp(sort_type, "asc") != 0 && strcmp(sort_type, "desc") != 0);
	
	// bubble sort untuk mengurutkan data sesuai dengan input user
	for(i=0; i<row; i++){
		for(j=0; j<row-1-i; j++){
			if(strcmp(column_name, "Location") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(strcmp(data[j].location1, data[j+1].location1) > 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(strcmp(data[j].location1, data[j+1].location1) < 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "City") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(strcmp(data[j].location2, data[j+1].location2) > 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(strcmp(data[j].location2, data[j+1].location2) < 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Type") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(strcmp(data[j].type, data[j+1].type) > 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(strcmp(data[j].type, data[j+1].type) < 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Furnish") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(strcmp(data[j].furnish, data[j+1].furnish) > 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(strcmp(data[j].furnish, data[j+1].furnish) < 0){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Price") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(data[j].price > data[j+1].price){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(data[j].price < data[j+1].price){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Rooms") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(data[j].room > data[j+1].room){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(data[j].room < data[j+1].room){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Bathroom") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(data[j].bathroom > data[j+1].bathroom){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(data[j].bathroom < data[j+1].bathroom){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			} else if(strcmp(column_name, "Carpark") == 0){
				if(strcmp(sort_type, "asc") == 0){
					if(data[j].carPark > data[j+1].carPark){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				} else if(strcmp(sort_type, "desc") == 0){
					if(data[j].carPark < data[j+1].carPark){
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			}
		}
	}
	
	// menampilkan 10 data teratas setelah diurutkan
	printf("Data found. Detail of data:\n");
	printf("%-15s \t %-12s \t %-6s \t %-3s \t %-3s \t %-3s \t %-8s \t %-8s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
	for(i=0; i<10; i++){
		printf("%-15s \t %-12s \t %-6d \t %-3d \t %-6d \t %-6d \t %-8s \t %-8s\n", data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathroom, data[i].carPark, data[i].type, data[i].furnish);
	}
	
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

// menu 4 -> export data
void export_data(){
	int i, row = 0;
	char file_name[100];
	
	// meminta input nama file dari user
	printf("File name: ");
	scanf("%[^\n]", file_name);
	strcat(file_name, ".csv");
	
	// membaca file
	FILE *fin = fopen("file.csv", "r");
	fscanf(fin, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n");
	while (!feof(fin)) {
    	fscanf(fin, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", data[row].location1, data[row].location2, &data[row].price, &data[row].room, &data[row].bathroom, &data[row].carPark, data[row].type, data[row].furnish);
        row++;
    }
    fclose(fin);
    
    // menulis isi file ke dalam file baru
    FILE *fout = fopen(file_name, "w");
	fprintf(fout, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
	for(i=0; i<row; i++){
		fprintf(fout, "%s,%s,%d,%d,%d,%d,%s,%s\n", data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathroom, data[i].carPark, data[i].type, data[i].furnish);
	}
	fclose(fout);
	
	printf("Data successfully written to file %s!\n", file_name);
	getchar(); getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int main(){
	
	// melakukan perulangan selama user tidak input angka 5
	while(1){
		// menerima nilai dari menu pilihan() -> berupa angka pilihan user
		int pilih = pilihan();
		
		// switch case sesuai dengan pilihan user
		// setiap pilihan akan memanggil fungsi yang berbeda sesuai dengan menu 
		switch(pilih){
			case 1:{
				display_data();	
				break;
			}
			case 2:{
				search_data();
				getchar();
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				break;
			}
			case 3:{
				sort_data();
				break;
			}
			case 4:{
				export_data();
				break;
			}
			case 5:{
				return 0;
			}
		}
	}
	
	return 0;
}
