#include <stdio.h>

struct Obj {
    const struct Class_in_Obj * classes;
};

struct Class_in_Obj {
	int Amount_walk;
	int Time_sleep;
    void (*Walk)(struct Obj *);
    void (*Sleep)(struct Obj *);
};

void Walk(struct Obj * self)
{
	const struct Class_in_Obj * classes = *(const void **) self;
	if((*classes).Walk)
		(*classes).Walk(self);
	else
    	printf("<Animal at %p> moved in some way\n", (void *) self);
}

//void Sleep(struct Obj * self)
//{
//    const struct Class_in_Obj * classes = *(const void **) self;
//    if (classes->Eat) 
//        classes->Eat(self); // execute Animal.Eat
//    else
//        fprintf(stderr, "Eat not implemented\n");
//}
void Animal_Walk(struct Obj * self)
{
	//const struct Class_in_Obj * classes = *(const void **) self;
	printf("<Animal at %p> moved in some way distance : %d\n", (void *) self,(*self).classes->Amount_walk);
}
void Animal_Sleep(struct Obj * self)
{
	//const struct Class_in_Obj * classes = *(const void **) self;
	printf("<Animal at %p> have sleep for : %d\n", (void *) self,self->classes->Time_sleep);
}
/* initialize class */
const struct Class_in_Obj Animal = {100,24,Animal_Walk,Animal_Sleep}; // base class does not implement Animal.Eat
//const struct Class_in_Obj people = {_Llama_eat,NULL};  // but the derived class does

int main(void)
{
   /* init objects as instance of its class */
   struct Obj animal = {& Animal};
   struct Obj *exe_Obj = & animal;
   animal.classes->Walk(& animal);
   Animal.Walk(& animal);
   exe_Obj->classes->Walk(& animal);
   Animal_Walk(& animal);
   Walk(& Animal);
   //struct Animal llama = {& Llama};
//   Move(& animal); // Animal.Move
//   Move(& llama);  // Llama.Move
//   Eat(& animal);  // cannot resolve Animal.Eat so print "Not Implemented" to stderr
//   Eat(& llama);   // resolves Llama.Eat and executes
   return 0;
}
