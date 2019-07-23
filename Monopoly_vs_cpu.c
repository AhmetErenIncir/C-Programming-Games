#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13
typedef enum block_type{start=0,property,fortune,tax,punish}b_type;
typedef enum player_type{none=-1,car,cap}player_type;

typedef struct
{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *player_name;
} player;

typedef struct block
{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
	struct block *next;
} block;

int roll_dice()
{
    int i=rand()%6+1;
    return i;
}

int random_fortune_card(){
	int i=rand()%1+1;
    return i;
}

void show_property_deed(block *board)
{
	int exit_flag=0,i,selection;
	block *iter = board;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        while(iter!=NULL) {
            if (iter->type==property){
				printf("%d -\t%s \n",iter->id,iter->name);
			}
            iter = iter -> next;
        }
		iter = board;
        printf("0 -\tExit\n");
        scanf("%d",&selection);
		for(i=0 ; i<selection ; i++){
			iter = iter -> next;
		}
        if (selection==0)
            exit_flag=1;
        else {
            if (selection > 0 && selection < 24 && iter->type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(iter->name) < 8)
                    printf("|\t\t%s\t\t|\n", iter->name);
                else
                    printf("|\t    %s\t\t|\n", iter->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", iter->rent);
                printf("|\tRent 1 H \t%d$\t|\n", iter->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", iter->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", iter->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", iter->house_price);
                printf("|\tHouse count \t%d\t|\n", iter->h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
		iter = board;
    }
}

//I converted.
void init_board(block *board)
{
	block *iter = board;
    block temp;
	player temp_player;
	temp_player.type=none;


    iter->id=0;
    iter->name="Start";
    iter->price=0;
    iter->rent=0;
    iter->rent_1=0;
    iter->rent_2=0;
    iter->rent_3=0;
    iter->owner=temp_player;
    iter->house_price=0;
    iter->h_count=0;
    iter->type=start;
    iter->next = (block*)malloc(sizeof(block));
	iter=iter->next;

	iter->id=1;
    iter->name="Esenyurt";
	iter->price=16000;
    iter->rent=800;
    iter->rent_1=4000;
    iter->rent_2=9000;
    iter->rent_3=25000;
	iter->owner=temp_player;
    iter->house_price=10000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=2;
    iter->name="Car park";
    iter->price=1500;
	iter->type=tax;
    iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=3;
	iter->name="Fortune Card";
	iter->type=fortune;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=4;
    iter->name="Tuzla";
    iter->price=16500;
    iter->rent=850;
    iter->rent_1=4250;
    iter->rent_2=9500;
    iter->rent_3=26000;
	iter->owner=temp_player;
    iter->house_price=12000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=5;
    iter->name="Arnavutkoy";
    iter->price=17000;
    iter->rent=850;
    iter->rent_1=4500;
    iter->rent_2=10000;
    iter->rent_3=28000;
	iter->owner=temp_player;
    iter->house_price=12000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=6;
	iter->name="Wait 2 turn";
	iter->price=2;
	iter->type=punish;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=7;
    iter->name="Catalca";
    iter->price=20000;
    iter->rent=1000;
    iter->rent_1=5000;
    iter->rent_2=12000;
    iter->rent_3=30000;
	iter->owner=temp_player;
    iter->house_price=13000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=8;
    iter->name="Beykoz";
    iter->price=23000;
    iter->rent=1100;
    iter->rent_1=5500;
    iter->rent_2=12500;
    iter->rent_3=33000;
	iter->owner=temp_player;
    iter->house_price=13000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=9;
	iter->name="Fortune Card";
	iter->type = fortune;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=10;
    iter->name="Car fix";
    iter->price=1750;
	iter->type=tax;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=11;
    iter->name="Maltepe";
    iter->price=30000;
    iter->rent=1350;
    iter->rent_1=7000;
    iter->rent_2=15000;
    iter->rent_3=40000;
	iter->owner=temp_player;
    iter->house_price=15000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=12;
    iter->name="Bills";
    iter->price=2000;
	iter->type=tax;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=13;
    iter->name="Sisli";
    iter->price=33000;
    iter->rent=1500;
    iter->rent_1=8000;
    iter->rent_2=16000;
    iter->rent_3=42000;
	iter->owner=temp_player;
    iter->house_price=16000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=14;
    iter->name="Oil";
    iter->price=2250;
	iter->type=tax;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=15;
	iter->name="Fortune Card";
	iter->type=fortune;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=16;
    iter->name="Atasehir";
    iter->price=35000;
    iter->rent=1600;
    iter->rent_1=8500;
    iter->rent_2=17000;
    iter->rent_3=45000;
	iter->owner=temp_player;
    iter->house_price=17000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=17;
    iter->name="Sariyer";
    iter->price=40000;
    iter->rent=1750;
    iter->rent_1=9500;
    iter->rent_2=19000;
    iter->rent_3=48000;
	iter->owner=temp_player;
    iter->house_price=19000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=18;
	iter->name="Wait 1 turn";
	iter->price=1;
	iter->type=punish;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=19;
    iter->name="Kadikoy";
    iter->price=43000;
    iter->rent=1900;
    iter->rent_1=11000;
    iter->rent_2=21500;
    iter->rent_3=55000;
	iter->owner=temp_player;
    iter->house_price=23000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=20;
    iter->name="Besiktas";
    iter->price=60000;
    iter->rent=2500;
    iter->rent_1=15000;
    iter->rent_2=28000;
    iter->rent_3=60000;
	iter->owner=temp_player;
    iter->house_price=30000;
    iter->h_count=0;
	iter->type=property;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=21;
	iter->name="Fortune Card";
	iter->type=fortune;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=22;
	iter->name="Vocation";
    iter->price=5000;
	iter->type=tax;
	iter->next = (block*)malloc(sizeof(block));
	iter = iter->next;

	iter->id=23;
    iter->name="Bebek";
    iter->price=70000;
    iter->rent=3500;
    iter->rent_1=20000;
    iter->rent_2=35500;
    iter->rent_3=65000;
	iter->owner=temp_player;
    iter->house_price=35000;
    iter->h_count=0;
	iter->type=property;
	iter->next = NULL;

}

void show_board(block *board_ll, player player_one, player player_two)
{

	//I initialized board again as array to print game board.
	block board[24];

	block temp;
	player temp_player;
	temp_player.type=none;

    temp.id=0;
    temp.name="Start";
    temp.price=0;
    temp.rent=0;
    temp.rent_1=0;
    temp.rent_2=0;
    temp.rent_3=0;
    temp.owner=temp_player;
    temp.house_price=0;
    temp.h_count=0;
    temp.type=start;
    board[temp.id]=temp;
    temp.type=tax;
    temp.name="Car park";
    temp.id=2;
    temp.price=1500;
    board[temp.id]=temp;
    temp.name="Car fix";
    temp.id=10;
    temp.price=1750;
    board[temp.id]=temp;
    temp.name="Bills";
    temp.id=12;
    temp.price=2000;
    board[temp.id]=temp;
    temp.name="Oil";
    temp.id=14;
    temp.price=2250;
    board[temp.id]=temp;
	temp.name="Vocation";
    temp.id=22;
    temp.price=5000;
    board[temp.id]=temp;

	temp.type=punish;
	temp.name="Wait 2 turn";
	temp.price=2;
    temp.id=6;
    board[temp.id]=temp;
	temp.name="Wait 1 turn";
	temp.price=1;
    temp.id=18;
    board[temp.id]=temp;


    temp.type=property;

    temp.id=1;
    temp.name="Esenyurt";
    temp.price=16000;
    temp.rent=800;
    temp.rent_1=4000;
    temp.rent_2=9000;
    temp.rent_3=25000;
    temp.house_price=10000;
    temp.h_count=0;
    board[temp.id]=temp;

    temp.id=4;
    temp.name="Tuzla";
    temp.price=16500;
    temp.rent=850;
    temp.rent_1=4250;
    temp.rent_2=9500;
    temp.rent_3=26000;
    temp.house_price=12000;
    temp.h_count=0;
    board[temp.id]=temp;

    temp.id=5;
    temp.name="Arnavutkoy";
    temp.price=17000;
    temp.rent=850;
    temp.rent_1=4500;
    temp.rent_2=10000;
    temp.rent_3=28000;
    temp.house_price=12000;
    temp.h_count=0;
    board[temp.id]=temp;

    temp.id=7;
    temp.name="Catalca";
    temp.price=20000;
    temp.rent=1000;
    temp.rent_1=5000;
    temp.rent_2=12000;
    temp.rent_3=30000;
    temp.house_price=13000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=8;
    temp.name="Beykoz";
    temp.price=23000;
    temp.rent=1100;
    temp.rent_1=5500;
    temp.rent_2=12500;
    temp.rent_3=33000;
    temp.house_price=13000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=11;
    temp.name="Maltepe";
    temp.price=30000;
    temp.rent=1350;
    temp.rent_1=7000;
    temp.rent_2=15000;
    temp.rent_3=40000;
    temp.house_price=15000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=13;
    temp.name="Sisli";
    temp.price=33000;
    temp.rent=1500;
    temp.rent_1=8000;
    temp.rent_2=16000;
    temp.rent_3=42000;
    temp.house_price=16000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=16;
    temp.name="Atasehir";
    temp.price=35000;
    temp.rent=1600;
    temp.rent_1=8500;
    temp.rent_2=17000;
    temp.rent_3=45000;
    temp.house_price=17000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=17;
    temp.name="Sariyer";
    temp.price=40000;
    temp.rent=1750;
    temp.rent_1=9500;
    temp.rent_2=19000;
    temp.rent_3=48000;
    temp.house_price=19000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=19;
    temp.name="Kadikoy";
    temp.price=43000;
    temp.rent=1900;
    temp.rent_1=11000;
    temp.rent_2=21500;
    temp.rent_3=55000;
    temp.house_price=23000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=20;
    temp.name="Besiktas";
    temp.price=60000;
    temp.rent=2500;
    temp.rent_1=15000;
    temp.rent_2=28000;
    temp.rent_3=60000;
    temp.house_price=30000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.id=23;
    temp.name="Bebek";
    temp.price=70000;
    temp.rent=3500;
    temp.rent_1=20000;
    temp.rent_2=35500;
    temp.rent_3=65000;
    temp.house_price=35000;
    temp.h_count=0;
    board[temp.id]=temp;

	temp.type=property;

	temp.id=3;
	temp.name="Fortune";
	board[temp.id]=temp;

	temp.id=9;
	temp.name="Fortune";
	board[temp.id]=temp;

	temp.id=15;
	temp.name="Fortune";
	board[temp.id]=temp;

	temp.id=21;
	temp.name="Fortune";
	board[temp.id]=temp;


	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i=0,space_flag=0;
	for (i=0;i<6;i++)
	{
        if (strlen(board[i].name)<8)
		    printf("|\t%s\t\t",board[i].name);
        else
            printf("|\t%s\t",board[i].name);
	}
	printf("|\n");
	for (i=0;i<6;i++)
	{
		if (board[i].type==property || board[i].type==tax)
		    printf("|\t%d$ \t\t",board[i].price);
		else if (strlen(board[i].name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
	}
    printf("|\n");
    for (i=0;i<6;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[i].name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Middle
    for (i=0;i<5;i++)
    {
        //Names

        if (strlen(board[23-i].name)<8)
            printf("|\t%s\t\t|",board[23-i].name);
        else
            printf("|\t%s\t|",board[23-i].name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");

        if (strlen(board[i+6].name)<8)
            printf("|\t%s\t\t|",board[i+6].name);
        else
            printf("|\t%s\t|",board[i+6].name);
        printf("\n");
        //prices
        if (board[23-i].type==property || board[23-i].type==tax)
            printf("|\t%d$ \t\t|",board[23-i].price);
        else if (strlen(board[23-i].name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t");

        if (board[6+i].type==property || board[6+i].type==tax)
            printf("|\t%d$ \t\t",board[6+i].price);
        else if (strlen(board[6+i].name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");
        //spaces

        space_flag=0;
        printf("|\t");
        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.player_name);
                space_flag = 1;
            }
            if (23 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[23-i].name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (6+i==player_one.current_block_id && 6+i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {

            if (6+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.player_name);
                space_flag=1;
            }
            if (6+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(board[6+i].name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=3) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }

    }

    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=15;i>=10;i--)
    {
        if (strlen(board[i].name)<8)
            printf("|\t%s\t\t",board[i].name);
        else
            printf("|\t%s\t",board[i].name);
    }
    printf("|\n");
    for (i=15;i>=10;i--)
    {
        if (board[i].type==property || board[i].type==tax)
            printf("|\t%d$ \t\t",board[i].price);
        else if (strlen(board[i].name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
    }
    printf("|\n");
    for (i=15;i>=10;i--)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[i].name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
}


void show_player_properties(block *board, player current_player)
{
    int i,counter=0,selection=-1,j;
	block *iter;
    while (selection!=0) {
		iter = board;
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
				for(j=0 ; j<current_player.owned_blocks[i] ; j++){
					iter = iter->next;
				}
                printf("%d - %s\n", iter->id,iter->name);
                counter++;
            }
			iter = board;
        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {

            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);
			iter = board;
			for(i=0 ; i<selection ; i++){
				iter = iter->next;
			}

            if (selection!=0) {
                if (iter->owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(iter->name) < 8)
                        printf("|\t\t%s\t\t|\n", iter->name);
                    else
                        printf("|\t    %s\t\t|\n", iter->name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", iter->rent);
                    printf("|\tRent 1 H \t%d$\t|\n", iter->rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", iter->rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", iter->rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", iter->house_price);
                    printf("|\tHouse count \t%d\t|\n", iter->h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
        }


    }

}

int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}

int count_properties(player current_player)
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}

void sell_property(block *board, player* current_player)
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0,j;
	block *iter = board;
        if (count_properties(*current_player)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
					for(j=0 ; j<current_player->owned_blocks[i] ; j++){
						iter = iter->next;
					}
                    printf("%d - %s\n", iter->id,iter->name);
                    counter++;
                }
				iter = board;
            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");
			iter = board;
            scanf("%d",&property_id);
			for(i=0; i<property_id ; i++){
				iter = iter->next;
			}
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    iter->owner.type=none;
                    if(iter->h_count==0)current_player->account+=iter->price/2;
                    if(iter->h_count==1)
                    {
                        current_player->account+=(iter->price+iter->house_price)/2;
                    }
                    if(iter->h_count==2)
                    {
                        current_player->account+=(iter->price+(2*iter->house_price))/2;
                    }
                    if(iter->h_count==3)
                    {
                        current_player->account+=(iter->price+(3*iter->house_price))/2;
                    }
                }
            }
        } else
        {
            printf("You don't have any property to sell.\n");
        }

}

int insufficient_fund(block *board, player* current_player,int required_money)
{
    int selection,flag=1;
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0 && flag==1)
    {
        if(current_player->type==car){
			printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
	        printf("1- Sell Property\n");
	        printf("2- Show my Properties\n");
	        printf("3- Show my Account\n");
	        printf("0- Back\n");
	        scanf("%d",&selection);
	        switch (selection)
	        {
	            case 1:
	                sell_property(board,current_player);
	                break;
	            case 2:
	                show_player_properties(board,*current_player);
	                break;
	            case 3:
	                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
	                break;
	            case 0:
	                flag=0;
	                break;
	            default:
	                printf("You made a wrong selection!\n");
	                break;

	        }
		}
		else if(current_player->type==cap){
			int max_price=current_player->owned_blocks[0],i;
			block *temp = board;
			for(i=1 ; i<PROPERTY_COUNT ; i++){
				if(temp->type==property && temp->id == current_player->owned_blocks[i]){
					if(current_player->owned_blocks[i]>max_price){
						max_price = current_player->owned_blocks[i];
					}
				}
				temp = temp->next;
			}
			current_player->account += max_price;
		}
    }
    return flag;

}

void pay_rent(block *board, player* current_player,player * owner)
{
    int rent=0,owned_property_count,i;
	block *iter = board;
	for(i=0 ; i<current_player->current_block_id ; i++){
		iter  = iter->next;
	}
    rent=iter->rent;
    if (iter->h_count==1)rent=iter->rent_1;
    if (iter->h_count==2)rent=iter->rent_2;
    if (iter->h_count==3)rent=iter->rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}

void add_to_owned(player* current_player)
{
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");
}

void copy_owner(player* old, player* new)
{
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}

void buy_property(block* current_block, player* current_player)
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);

        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);

    }
    else
        printf("You don't have enough money to buy this property!\n");
}

void house_dialog(block *board, player* current_player)
{
	block *iter = board;
    int house_flag=1,selection,insuf_flag=1,build_flag=1,i;
	for(i=0 ; i<current_player->current_block_id ; i++){
		iter = iter->next;
	}
    while (house_flag && build_flag) {
		if(current_player->type==car){
			printf("Do you want to build house on %s ?\n",iter->name);
	        printf("1- Yes\n");
	        printf("2- No\n");
	        scanf("%d", &selection);
	        if (selection == 1) {

	            if (current_player->account < iter->house_price) {
	                while (count_properties(*current_player)!=0 && current_player->account<iter->house_price && insuf_flag==1)
	                    insuf_flag=insufficient_fund(board,current_player,iter->house_price);
	            }
	            if (current_player->account >= iter->house_price)
	                build_flag=build_house(iter, current_player);
	            else
	                house_flag=0;


	        } else
	            house_flag=0;
		}
		else if(current_player->type == cap){
			if(current_player->account < iter->house_price){
				if(count_properties(*current_player)>=4){
					int dice = roll_dice();
					if(dice<=3 && dice>=1){
						iter->h_count++;
						current_player->account -= iter->house_price;
					}
				}
			}
		}

    }
}

void after_dice_menu(block *board, player* current_player, player* other)
{
    int selection,insuf_flag=1,i,j,select_for_house,fortune_card;
	block *iter = board;
	for(i=0 ; i<current_player->current_block_id ; i++){
		iter = iter->next;
	}

        if(iter->type == property){
			printf("%s has arrived %s \n",current_player->player_name,iter->name);
            if (iter->owner.type==none)
            {
				if(current_player->type == car){
					printf("Do you want to buy %s ?\n",iter->name);
	                printf("1- Yes\n");
	                printf("2- No\n");
	                scanf("%d",&selection);
	                if (selection==1)
	                {

	                    if (current_player->account<iter->price)
	                    {
	                        while (count_properties(*current_player)!=0 && current_player->account<iter->price && insuf_flag==1 )
	                        {
	                            insuf_flag=insufficient_fund(board,current_player,iter->price);
	                        }
	                    }
	                    buy_property(iter,current_player);
	                    if (current_player->type==iter->owner.type)
	                    {
	                        house_dialog(board,current_player);
	                    }
	                }

	            }
				else if(current_player->type == cap){
					block *temp = board;
					int sum_of_property_prices=0,counter=0;
					while(temp!=NULL){
						if(temp->type == property){
							sum_of_property_prices += temp->price;
							counter++;
						}
						temp = temp->next;
					}
					if(iter->price<(sum_of_property_prices/counter)){
						if(current_player->account > iter->price){
							current_player->account -= iter->price;
							iter->owner.type = current_player->type;
						}
					}
					else{
						int dice_com = roll_dice();
						if(dice_com>=1 && dice_com<=3){
							if(current_player->account > iter->price){
								current_player->account -= iter->price;
								iter->owner.type = current_player->type;
							}
						}
					}
				}
			}
			else{
                pay_rent(board,current_player,other);
            }
		}

        else if(iter->type == tax){
			printf("%s has arrived tax block(%s)\n",current_player->player_name,iter->name);
            while (count_properties(*current_player)!=0 && current_player->account<iter->price) {
                insuf_flag = insufficient_fund(board, current_player,iter->price);
                if (insuf_flag == 0 && current_player->account < iter->price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>iter->price)
                current_player->account=current_player->account-iter->price;
            else
            {
                current_player->account=0;
            }
		}
        else if(iter->type == punish){
			printf("%s has punished for %d turn. \n",current_player->player_name,iter->price);
            current_player->turn_to_wait+=iter->price;
		}
		else if(iter->type == fortune){
			if(current_player->type == car){
				fortune_card=random_fortune_card();
				if(fortune_card==1 && current_player->type==car){
					printf("You draw Free House Card.You can build a house on your properties\n");
					for (i = 0; i < PROPERTY_COUNT; i++) {
			            if (current_player->owned_blocks[i] != -1) {
							for(j=0 ; j<current_player->owned_blocks[i] ; j++){
								iter = iter->next;
							}
			                printf("%d - %s\n", iter->id,iter->name);
			            }
						iter = board;
			        }
					if(count_properties(*current_player)>0){
						scanf("%d",&select_for_house);
						iter = board;
						for(i=0 ; i<select_for_house ; i++){
							iter = iter->next;
						}
						if(iter->h_count<3){
							iter->h_count++;
						}
						else{
							printf("You cant build house on this property.\n");
							printf("Your reached maximum build capacity\n");
						}
						printf("House count %d after on %s\n",iter->h_count,iter->name);
					}
					else{
						printf("You dont have any property\n");
					}
				}
				else if(fortune_card==1 && current_player->type==cap){
					if(count_properties(*current_player)>0){
						iter = board;
						for(i=0 ; i<current_player->owned_blocks[0] ; i++){
							iter = iter->next;
						}
						if(iter->h_count<3){
							iter->h_count++;
						}
					}
				}
				else if(fortune_card==2){
					int dice = roll_dice();
					printf("Fortune Card 2\n");
					if(dice>=1 && dice<=3){
						printf("%s moves forward 2 block\n",current_player->player_name);
						current_player->current_block_id += 2;
					}
					else{
						printf("%s moves back 2 block\n",current_player->player_name);
						current_player->current_block_id -= 2;
					}
				}
				else if(fortune_card==3){
					printf("Fortune Card 3\n");
					printf("%s should pay 5000$ to bank\n",current_player->player_name);
					current_player->account -= 5000;
				}
				else if(fortune_card==4){
					printf("Fortune Card 4\n");
					printf("%s should pay 10000$ from %s\n",current_player->player_name,other->player_name);
					current_player->account -= 10000;
					other->account +=10000;
				}
				else if(fortune_card==5){
					printf("Fortune Card 5\n");
					printf("%s can take 20000$ from bank\n",current_player->player_name);
					current_player->account +=20000;
				}
			}
			else if(current_player->type == cap){
				fortune_card=random_fortune_card();
				if(fortune_card==1){
					printf("Computer draw Fortune Card 1\n");
					if(count_properties(*current_player)>0){
						iter = board;
						for(i=0 ; i<current_player->owned_blocks[0] ; i++){
							iter = iter->next;
						}
						if(iter->h_count<3){
							iter->h_count++;
						}
					}
				}
				else if(fortune_card==2){
					int dice = roll_dice();
					printf("Computer draw Fortune Card 2\n");
					if(dice>=1 && dice<=3){
						printf("%s moves forward 2 block\n",current_player->player_name);
						current_player->current_block_id += 2;
					}
					else{
						printf("%s moves back 2 block\n",current_player->player_name);
						current_player->current_block_id -= 2;
					}
				}
				else if(fortune_card==3){
					printf("Computer draw Fortune Card 3\n");
					printf("%s should pay 5000$ to bank\n",current_player->player_name);
					current_player->account -= 5000;
				}
				else if(fortune_card==4){
					printf("Computer draw Fortune Card 4\n");
					printf("%s should pay 10000$ from %s\n",current_player->player_name,other->player_name);
					current_player->account -= 10000;
					other->account +=10000;
				}
				else if(fortune_card==5){
					printf("Computer draw Fortune Card 5\n");
					printf("%s can take 20000$ from bank\n",current_player->player_name);
					current_player->account +=20000;
				}
			}
		}


}

void turn(block *board, player* current_player, player * other)
{
    int flag=1,next_block,i;
	block *iter = board;
	for(i=0 ; i<current_player->current_block_id ; i++){
		iter = iter->next;
	}
    while(flag)
    {
		if(current_player->type ==car){
			int selection;
	        printf("1 - Roll the dice\n");
	        printf("2 - Show my account\n");
	        printf("3 - Show my properties\n");
	        printf("4 - Show property deeds\n");
	        printf("5 - Buy Property\n");
	        printf("6 - Buy house \n");
	        printf("7 - Sell property\n");
	        printf("Please select an option to continue (%s):\n",current_player->player_name);
	        scanf("%d",&selection);
	        switch(selection)
	        {
	            case 1:
	                if (current_player->turn_to_wait==0) {
	                    next_block=(current_player->current_block_id + roll_dice());
	                    if (next_block>=20)current_player->account+=10000;
	                    current_player->current_block_id = next_block % 20;
	                    after_dice_menu(board,current_player,other);
	                    flag = 0;
	                } else
	                {
	                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
	                    current_player->turn_to_wait-=1;
	                    flag=0;
	                }
	                break;
	            case 2:
	                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
	                break;
	            case 3:
	                show_player_properties(board,*current_player);
	                break;
	            case 4:
	                show_property_deed(board);
	                break;
	            case 5:
	                if (iter->type==property && iter->owner.type==-1)
	                buy_property(iter,current_player);
	                else
	                {

	                    printf("You don't have permission to buy this block!\n");
	                }

	                break;
	            case 6:
	                if (current_player->type==iter->owner.type) {
	                    house_dialog(board,current_player);
	                }else
	                {
	                    printf("You don't have permission to build house on this block!\n");
	                }
	                break;
	            case 7:
	                sell_property(board,current_player);
	                break;
	            default:
	                printf("Wrong selection!\n");
	        }
	    }
		else if(current_player->type == cap){


	        if (current_player->turn_to_wait==0) {
	            next_block=(current_player->current_block_id + roll_dice());
	            if (next_block>=20)current_player->account+=10000;
	                current_player->current_block_id = next_block % 20;
	                after_dice_menu(board,current_player,other);
	                flag = 0;
	            } else
	            {
	                printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
	                current_player->turn_to_wait-=1;
	                flag=0;
	            }
		}
	}

}

int check_end(player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}

void play_game(block *board, player* player_one, player* player_two)
{
    int is_end=0;
    printf("Welcom to Monopoly! %s will roll the dice first.\n",player_one->player_name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
        turn(board,player_one,player_two);
        show_board(board,*player_one,*player_two);
        is_end=check_end(*player_one);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
            turn(board,player_two,player_one);
            show_board(board,*player_one,*player_two);
            is_end=check_end(*player_two);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_two->player_name,player_two->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->player_name,player_one->player_name);

    }

}

void init_owned(player* current_player)
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }

}

int main() {
    block board;
    init_board(&board);
	block *iter = &board;
    srand(time(NULL));
    player player_one,player_two;

    player_one.player_name="Computer";
	player_one.type=cap;
	player_one.current_block_id=0;
    player_one.turn_to_wait=0;
	player_one.account=100000;
    init_owned(&player_one);

	player_two.player_name="Car";
	player_two.type=car;
	player_two.current_block_id=0;
    player_two.turn_to_wait=0;
	player_two.account=100000;
    init_owned(&player_two);

	//show_property_deed(&board);
    show_board(&board,player_one,player_two);
    play_game(&board,&player_one,&player_two);

    return 0;
}
