
Demonstrate each Pillar of SOLID Development

SOLID Development Principles

 * Single Responsibility Principle
    - A class should only ever have one reason to change.
    - It has one job or responsibility.

    Example if you have an 'Invoice' class it should only
    handle invoice related tasks, like calculating totals
    or applying discounts.

    It should NOT manage persistance(saving to db) or user
    interface related concerns


 * Open/Closed Principle(OCP)
    Def: Software entities should be open for extension
    but closed for modification.

    You should be able to add new functionality to a class
    without altering existing code.
    Use:
        - interfaces
        - abstract classes
        - inheritance

    Reduces risk of introducing bugs.

 * Liskov Substitution Principle (LSP)
    Def: Objects of a superclass should be replaceable with
    objects of a subclass without affecting the correctness
    of the program.

    Example: 
      SuperClass: Bird {with method fly()}
      subclass: Penguin {Does not implement fly()}

      -Violates LSP because Penguin violates expected Bird
      behavior

      Solution class struct: 
         Bird{walk()} -> flyingBird{fly()}
         Bird{walk()} -> flightlessBird{}
         flyingBird ->Eagle : 
         flightlessBird -> Penguin




 * Interface Segregation Principle(ISP)
   Def: No client should be forced to depend on methods it
   does not use.

   Promote small, specific interfaces, rather than a large
   general-purpose interface.
   - Reduces dependency of classes on methods they do not
   use.
   -More modular, easier to maintain.

   Example:
      Choose:
         Interface IMachine{
            print()
            scan()
            fax()
         }
         or
         
      Seperate functionality into separate interfaces
      -This way a class implementing IPrinter does not
         need to implemnt scan() or fax() funcitonality.
         
         Interface IPrinter{}
         Interface IScanner{}
         Interface IFax{}

 * Dependency Inversion Principle(DIP)
   Def: High-level modules should not depend on 
   low-level modules. Both should depend on Abstractions.
   Additionally, abstractions should not depend on details.
   
   Details should depend on abstractions.

   - Dependency is all about hotswapability.
   - Encourages the decoupling of software modules.
   - Easier refactor, easier extend.

   Example:
   class DataProcesser{} ---Depends---> class FileStorage

   or
   class DataProcesser{} ---Depends---> IDataStorage
   FileStorage -> implements IDataStorage.

   -Allows you to switch between different storage 
   mechanisms more easily.
