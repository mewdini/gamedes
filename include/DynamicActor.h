//

//

#ifndef DynamicActor_h
#define DynamicActor_h

/* Building off idea from Actor, dynamic can move the origin point. More specific models will update whatever
    they need to draw to follow the new origin
*/

class DynamicActor{

public:
    void move(float, float);
private:
    float vel;


};


#endif
