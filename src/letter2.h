//Downwards
//Produced and developed by CTG Empire
/*
#ifndef LETTER2_H
#define LETTER2_H

//The letter that will move around on the screen
class Letter
{
    private:
    //The X and Y offsets of the letter
    int x, y, w, h;
    
    //The velocity of the letter
    int xVel, yVel;
    
    //Checks whether the letter has been clicked
    bool clicked;
    
    unsigned randomLetter;
    
    public:
    //Initializes the variables
    Letter();
    
    void set_letters();
    
    //Takes key presses and adjusts the letter's velocity
    void handle_input();
    
    //Moves the letter
    void move();
    
    bool init(char *);
    
    //Shows the letter on the screen
    void show();
    
    //Destructor
    ~Letter();

    char *filename;
};

#endif
