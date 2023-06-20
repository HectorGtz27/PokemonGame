#include <iostream>
using namespace std;

class pokemon {
    //Aqui se cambia a protected para que se puede acceder a los atributos =
protected:
    //Atributos
    string nombre;
    int ataque;
    int salud;
    string color;

public:

    //----------------------------------------------------------------------------------------
        //Constructor por defecto
    pokemon() {
        nombre = "Squirtle";
        ataque = 100;
        salud = 1000;
        color = "azul";

    }

    //Constructor especificos
    pokemon(string n, int a, int s, string c) {
        nombre = n;
        ataque = a;
        salud = s;
        color = c;

    }

    //----------------------------------------------------------------------------------------------
       //Metodos

       //Nombre
    string getNombre() {
        return nombre;
    }

    //Void porque no regresa nada, pero si recibe
    void setNombre(string n) {
        nombre = n;
    }

    //Ataque
    int getAtaque() {
        return ataque;
    }


    void setAtaque(int a) {
        ataque = a;
    }

    //Salud
    int getSalud() {
        return salud;
    }


    void setSalud(int s) {
        salud = s;
    }

    //Color
    string getColor() {
        return color;
    }


    void setColor(string c) {
        color = c;
    }

    //Ensenar todos los atributos

    void dameAtributos() {
        cout << "El nombre del pokemon es: " << nombre << endl;
        cout << "El color del pokemon es: " << color << endl;
        cout << "El ataque del pokemon es: " << ataque << endl;
        cout << "La salud del pokemon es: " << salud << endl;
    }

    //Sanar

    void Sanar() {
        salud = salud + 50;
    }

    //Evolucionar

    void Evolucionar(string color_pokemon) {
        nombre = "Super " + nombre;
        color = color_pokemon;
        ataque = ataque + (ataque / 5);
    }

    void saludar() {
        cout << "Hola soy: " << nombre << " te invito a que usar mis poderes " << endl;
    }

    //Funcion atacar que hereda de varias, esto es plimorfismo
    //porque hace lo mismo pero de diferente manera
    //p = propio, c = contra
    virtual void atacar(pokemon* b) {

        int var_salud;
        if (b->getSalud() > 0) {
            cout << "Con un ataque de: " << ataque << " de";
            cout << " " << nombre << " ataca a " << b->getNombre() << endl;
            var_salud = b->getSalud() - ataque;
            b->setSalud(var_salud);
            cout << b->getNombre() << " ahora tiene de salud: " << b->getSalud() << endl;
            cout << endl;

        }
        

    }

    //-----------------------------------------------------------------------------------------
        //Destrcutores
    ~pokemon() {
        cout << nombre << " fue destruido" << endl;
    }




};


//--------Clase waterPokemon-----------------------------------------------------------------------
class waterPokemon :public pokemon {
    //Cada uno de los atributos debe de tener su set y get
private:
    int maxResistent; //Cuanto tiempo aguanta en el agua 
    int submergedTime; //Cuanto tiempo lleva en el agua

public:
    //Constructor
    waterPokemon(string n, int ap, string c, int m, int s) {
        nombre = n;
        ataque = ap;
        color = c;
        maxResistent = m;
        salud = s;
        submergedTime = 0;


    }
    void setMaxResistent(int m) {
        maxResistent = m;
    }

    int getMaxResistent() {
        return maxResistent;
    }

    void setSubmergedTime(int s) {
        submergedTime = s;
    }

    int getSubmergedTime() {
        return submergedTime;
    }

    void setSalud(int s) {
        salud = s;
    }

    int getSalud() {
        return salud;
    }

    //Funcion para respirar

    void respirar() {
        cout << nombre << " ha respirado " << endl;
        submergedTime = 0;
    }

    void tirarAgua() {
        cout << " le esta lanzando un chorro de agua a ";
    }

    //Funcion heredada polimorfismo

    void atacar(pokemon* b) override {

        int var_salud;
        if (b->getSalud() > 0) {
            cout << "Con un ataque de: " << ataque << " de";
            cout << " " << nombre;
            tirarAgua();
            cout << b->getNombre() << endl;
            var_salud = b->getSalud() - ataque;
            b->setSalud(var_salud);
            cout << b->getNombre() << " ahora tiene de salud: " << b->getSalud() << endl;
            cout << endl;

        }
        

    }
};
//-----------clase bola--------------------------------------------------------------------
//Crenaod un objeto como se pedia en el reto

class bolaFuego {
private:
    float temperatura;

public:
    bolaFuego(float t) {
        temperatura = t;
    }

    void setTemperatura(float t) {
        temperatura = t;
    }
    float getTemperatura() {
        return temperatura;
    }

    void lanzarBola() {
        cout << " a una temperatura de: " << temperatura << "F a ";
    }
};

//-----clase firePokemon-----------------------------------------------------------------------

class firePokemon :public pokemon {
private:
    int maxTemperature;
    int ballTemperature;

public:
    firePokemon(string n, int ap, string c, int mt, int bt, int s) {
        nombre = n;
        ataque = ap;
        color = c;
        maxTemperature = mt;
        ballTemperature = bt;
        salud = s;

    }

    void setMaxTemperature(int mt) {
        maxTemperature = mt;

    }

    int getMaxTemperature() {
        return maxTemperature;
    }

    void setBallTemperature(int bt) {
        ballTemperature = bt;

    }

    int getBallTemperature() {
        return ballTemperature;
    }

    void setSalud(int s) {
        salud = s;
    }

    int getSalud() {
        return salud;
    }



    void lanzarBola() {
        bolaFuego bola(ballTemperature);
        cout << " le esta lanzando una bola de fuego";
        bola.lanzarBola();


    }

    //Funcion heredada polimorfismo

    void atacar(pokemon* b) override {

        int var_salud;
        if (b->getSalud() > 0) {
            cout << "Con un ataque de: " << ataque << " de";
            cout << " " << nombre;
            lanzarBola();
            cout << b->getNombre() << endl;
            var_salud = b->getSalud() - ataque;
            b->setSalud(var_salud);
            cout << b->getNombre() << " ahora tiene de salud: " << b->getSalud() << endl;
            cout << endl;

        }
       

    }

};

//-----clase earthPokemon-----------------------------------------------------------------------
class earthPokemon :public pokemon {
private:
    int maxDepth;

public:
    earthPokemon(string n, int ap, string c, int md, int s) {
        nombre = n;
        ataque = ap;
        color = c;
        maxDepth = md;
        salud = s;

    }

    void setmaxDepth(int md) {
        maxDepth = md;
    }

    int getmaxDepth() {
        return maxDepth;
    }

    void setSalud(int s) {
        salud = s;
    }

    int getSalud() {
        return salud;
    }

    //Funcion cavartubo
    void cavarTunel(int d) {
        if (d <= 100) {
            cout << nombre << " esta cavando un tunel de " << d << " metros de profundidad" << endl;
        }
        else {
            cout << nombre << " no puede cavar porque su maxima profundiad es: " << maxDepth << endl;
        }

    }

    void tirarPiedra() {
        cout << " le lanzo una piedra a ";
    }

    //Funcion heredada polimorfismo
    void atacar(pokemon* b) override {
        int var_salud;
        if (b->getSalud() > 0) {
            cout << "Con un ataque de: " << ataque << " de";
            cout << " " << nombre;
            tirarPiedra();
            cout << b->getNombre() << endl;
            var_salud = b->getSalud() - ataque;
            b->setSalud(var_salud);
            cout << b->getNombre() << " ahora tiene de salud: " << b->getSalud() << endl;
            cout << endl;

        }
        

    }



};


//funciones que permiten parametros que no sean fijos
//funcion de combate, en la cual se reciven 2 pokemones que van a pelear
//pokemon &Diglett, pokemon &Squirtle
void combate(pokemon* a, pokemon* b) {

 
    cout << "Empieza la pelea entre: " << a->getNombre() << " vs " << b->getNombre() << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Datos de cada pokemon " << endl;
    cout << "Salud de " << a->getNombre() << ": " << a->getSalud() << endl;
    cout << "Salud de " << b->getNombre() << ": " << b->getSalud() << endl;
    cout << endl;
    cout << "Ataque de " << a->getNombre() << ": " << a->getAtaque() << endl;
    cout << "Ataque de " << b->getNombre() << ": " << b->getAtaque() << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    while (a->getSalud() > 0 && b->getSalud()>0) {
        a->atacar(b);
        b->atacar(a);

        
    }

    if (a->getSalud() <= 0 && b->getSalud() <=0) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Resultado final de la batalla: " << endl;
        cout << "Empate" << endl;
        
    }
    else if (b->getSalud() <= 0) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Resultado final de la batalla: " << endl;
        cout << "Perdio " << b->getNombre() << endl;
        cout << "El ganador del combate es: " << a->getNombre() << endl;
    }
    else {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Resultado final de la batalla: " << endl;
        cout << "Perdio " << a->getNombre() << endl;
        cout << "El ganador del combate es: " << b->getNombre() << endl;
    };

    

}


void main()
{


    //                    nombre   ataque  color maxre salud
    waterPokemon Squirtle("Squirtle", 100, "auzl", 20, 300);
    Squirtle.respirar();
    //                     nombre    ataque  color  maxte balltemp salud 
    firePokemon Charmander("Charmander", 100, "naranja", 100, 50, 200);
    Charmander.lanzarBola();
    earthPokemon Diglett("Diglett", 50, "cafe", 100, 400);
    Diglett.cavarTunel(200);
    cout << endl;

    combate(&Squirtle, &Charmander);
    cout << endl;




}