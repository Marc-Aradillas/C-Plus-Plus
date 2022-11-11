#include <iostream>

class Project1 // A recipe used to tell the compiler how to build our object.
{
    private:                // Private data can only be accessed by the methods in the class.
        int Hours24;        // This is the data, the purpose of the class.
        int Minutes;        // The class encapsulates the data and the methods to access
        int Seconds;        // the data in a single unit.
        int numberOfYears;  // 

        // bool
        //  https://www.w3schools.com/cpp/cpp_booleans.asp
        // Pass by reference (&)
        //  https://www.w3schools.com/cpp/cpp_function_reference.asp
        // If you know how to use a constructor
        // Optional (for project 1) constructor
        int  CalcHour12(bool &am_pm) {your code here};
        void AddHour(void) {your code here};
        void AddMinute(void) {your code here};
        void AddSecond(void) {your code here};
        void DisplayTime(void) {your code here};
        void DisplayMenu(void) {your code here};

    public: // Interface (API) - These methods can be accessed using object_name.function()
        void ClearScreen(void) {your code here};    // object_name.ClearScreen()
        void Display(void) {your code here};        // object_name.Display()
        bool ReadUserInput(void) {your code here};  // object_name.ReadUserInput()

       void Init(int Hour, int Minute, int Second) {your code here}; // Used to init the data
};

int main(void)
{
    Project1 project1; // Tell the compiler to build our object based on the class recipe.

    project1.Init(21,30,0); // To access a function in the object, we use the object_name.method_name

    while(1)
    {
        project1.ClearScreen(); // Call the functions in the object
        project1.Display();
        if(ReadUserInput())
            break;              // Exit main()
    }
}
