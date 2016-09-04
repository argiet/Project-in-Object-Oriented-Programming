#ifndef FCLASSES_H
#define FCLASSES_H

class System
{

    int size; //megethos

    int pos_x, pos_y; //position in map

    int age; //hlikia
    int degree; //vathmos anaptiksis
    int quantity; //posothta trofhs pou xreiazetai ana monada xronou
    int food; //posothta trofhs pou proslambanei

    char letter; //gramma me to opoio dia xwrizoume kathe kathgoria organismou


      public:
             System();

             System(char letter, int age, int size);

             System(char letter, int pos_x, int pos_y, int age);

             ~System();

             int get_pos_x();

             int get_pos_y();

             int get_size();

             void set_pos_x(int);

             void set_pos_y(int);

             void set_size(int);

             void set_age(int);

             int get_age();

             void set_degree(int);

             int get_degree();

             void set_food(int);

             int get_food();

             void set_quantity(int);

             int get_quantity();

             char get_letter();


};

class Operations : public System
{
    public:

        Operations();
        Operations(char letter, int age, int size);
        Operations(char letter, int pos_x, int pos_y, int age);
        ~Operations();

        void moving(int);

        void eating(int);

        void reproducting(int);
};

#endif


