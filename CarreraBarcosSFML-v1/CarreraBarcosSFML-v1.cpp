
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Barco.h"


using namespace std;
using namespace sf;


// BARCOS (OBJETOS)
Barco barcoJugador = Barco("Jugador");
Barco barcoNPC = Barco("NPC");

sf::Text labelInfoJugador;
sf::Text labelInfoNPC;
sf::Text labelTurno;
int turno = 0;

void actInfo() {
    int disNPC = barcoNPC.getDistancia();
    int velNPC = barcoNPC.getVelocidad();

    int  disJugador = barcoJugador.getDistancia();
    int  velJugador = barcoJugador.getVelocidad();

    labelInfoNPC.setString("NPC\n" + to_string(disNPC) + " m\n" + to_string(velNPC) + " km/h\nn: " + barcoNPC.getNitroStr());
    labelInfoJugador.setString(barcoJugador.getName() + "\n" + to_string(disJugador) + " m\n" + to_string(velJugador) + " km/h\nn: " + barcoJugador.getNitroStr());
    labelTurno.setString(to_string(turno) + "/5");

}


int main()
{
    srand(time(NULL));

    int partida = 1;
    bool ganador;

    //TEXTURAS
    sf::Texture f;
    f.loadFromFile("sprites/fondotest2.png");
    RectangleShape fondo(sf::Vector2f(1100, 400));
    fondo.setTexture(&f);
    sf::Texture b;
    b.loadFromFile("sprites/boton.png");
    sf::Texture barco1;
    barco1.loadFromFile("sprites/barco1.png");
    sf::Texture barco2;
    barco2.loadFromFile("sprites/barco2.png");
    sf::Texture sum;
    sum.loadFromFile("sprites/sumar.png");
    sf::Texture res;
    res.loadFromFile("sprites/restar.png");

    // VARIABLES CARTERA
    int cartera = 100;
    int apuesta = 0;
    int azul = 0;
    int rojo = 0;
    bool sumado = true;



    RenderWindow window(VideoMode(1100, 400), "Carrera Barcos   >_<");

    RectangleShape barco1sprite(sf::Vector2f(60, 30));
    barco1sprite.setPosition(90, 100); 
    barco1sprite.setTexture(&barco1);


    RectangleShape barco2sprite(sf::Vector2f(60, 30));
    barco2sprite.setPosition(90, 200);
    barco2sprite.setTexture(&barco2);

    sf::RectangleShape button(sf::Vector2f(100, 50));
    button.setPosition(440, 320);
    button.setTexture(&b);

    sf::RectangleShape button2(sf::Vector2f(100, 50));
    button2.setPosition(560, 320);
    button2.setTexture(&b);

    sf::RectangleShape buttonRes(sf::Vector2f(100, 50));
    buttonRes.setPosition(500, 335);
    buttonRes.setTexture(&b);


    sf::RectangleShape buttonSuma(sf::Vector2f(20, 20));
    buttonSuma.setPosition(1015, 360);
    buttonSuma.setTexture(&sum);


    sf::RectangleShape buttonResta(sf::Vector2f(20, 20));
    buttonResta.setPosition(922, 360);
    buttonResta.setTexture(&res);

    sf::Font fuente;
    if (!fuente.loadFromFile("data/terminal.ttf"))
    {
        return EXIT_FAILURE;
    }
    // TEXTOS 

    sf::Text nitro;
    nitro.setString("NITRO");
    nitro.setFont(fuente);
    nitro.setCharacterSize(27);
    nitro.setPosition(465, 325);

    sf::Text next;
    next.setString("NEXT");
    next.setFont(fuente);
    next.setCharacterSize(27);
    next.setPosition(590, 325);


    labelInfoNPC.setString("NPC\n0 km\n0 km/h\nn: si");
    labelInfoNPC.setFont(fuente);
    labelInfoNPC.setCharacterSize(22);
    labelInfoNPC.setPosition(5,70);


    labelInfoJugador.setString(barcoJugador.getName() + "\n0 km/h\n0 m\nn: si");
    labelInfoJugador.setFont(fuente);
    labelInfoJugador.setCharacterSize(22);
    labelInfoJugador.setPosition(5, 170);

    sf::Text labelAzul;
    labelAzul.setFont(fuente);
    labelAzul.setString("0");
    labelAzul.setCharacterSize(35);
    labelAzul.setPosition(860, 346);

    sf::Text labelRojo;
    labelRojo.setFont(fuente);
    labelRojo.setString("0");
    labelRojo.setCharacterSize(35);
    labelRojo.setPosition(860, 303);

    sf::Text total;
    total.setFont(fuente);
    total.setString(to_string(cartera));
    total.setCharacterSize(40);
    total.setPosition(955, 290);

    sf::Text labelApuesta;
    labelApuesta.setFont(fuente);
    labelApuesta.setString("000");
    labelApuesta.setCharacterSize(40);
    labelApuesta.setPosition(955, 340);

    sf::Text labelGanador;
    labelGanador.setFont(fuente);
    labelGanador.setCharacterSize(50);
    labelGanador.setPosition(420, 270);

    
    labelTurno.setString(to_string(turno) +"/5");
    labelTurno.setFont(fuente);
    labelTurno.setCharacterSize(35);
    labelTurno.setPosition(530, -7);
    bool buttonPressed = false;
    while (window.isOpen())
    {
        bool continuar = false;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (event.type == Event::MouseButtonPressed) {
            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
            if (!buttonPressed && button.getGlobalBounds().contains(mousePos)&& turno < 5 && barcoJugador.getNitro() == true) {
                buttonPressed = true;
                continuar = true;
                // PONER RANDOM NITRO EN FUNCION DE OBJETO
                barcoJugador.setNitro(false);
                int res = rand() % 2;
                if (res == 0)
                {
                    barcoJugador.setVelocidad(barcoJugador.getVelocidad() * 2);
                    cout << "Nitro Jugador: CORRECTO\n";
                }
                else {
                    barcoJugador.setVelocidad(barcoJugador.getVelocidad() / 2);
                    cout << "Nitro Jugador: Incorrecto\n";

                }
            }
            if (!buttonPressed && button2.getGlobalBounds().contains(mousePos) && turno < 5) {
                buttonPressed = true;
                continuar = true;
                

            }
            if (!buttonPressed && buttonSuma.getGlobalBounds().contains(mousePos) && turno == 0 ) {
                buttonPressed = true;
                if (cartera > 0) {
                    cartera -= 50;
                    apuesta += 50;
                    total.setString(to_string(cartera));
                    labelApuesta.setString(to_string(apuesta));
                }

            }
            if (!buttonPressed && buttonResta.getGlobalBounds().contains(mousePos) && turno == 0) {
                buttonPressed = true;
                if (apuesta > 0) {
                    cartera += 50;
                    apuesta -= 50;
                    total.setString(to_string(cartera));
                    labelApuesta.setString(to_string(apuesta));

                }

            }
            if (!buttonPressed && buttonRes.getGlobalBounds().contains(mousePos) && turno == 5  ) {
                buttonPressed = true;
                turno = 0;
                sumado = true;

                barcoNPC.reiniciarValores();
                barcoJugador.reiniciarValores();

                barco1sprite.setPosition(90, 100);
                barco2sprite.setPosition(90, 200);
                partida = 1;
                    
                actInfo();
            }
            if (continuar)
            {

                if (barcoNPC.getNitro() && barcoNPC.getDistancia() < barcoJugador.getDistancia() && turno > 2)
                {
                    barcoNPC.setNitro(false);
                    int res = rand() % 2;
                    if (res == 0)
                    {
                        barcoNPC.setVelocidad(barcoNPC.getVelocidad() * 2);
                        cout << "Nitro NPC: CORRECTO\n";
                    }
                    else {
                        barcoNPC.setVelocidad(barcoNPC.getVelocidad() / 2);
                        cout << "Nitro NPC: INCOORRECTO\n";

                    }
                }




                turno += 1;
                labelTurno.setString(to_string(turno) + "/5");
                

                barcoNPC.calcVelocidad();
                barcoJugador.calcVelocidad();


                barcoJugador.calcDsitancia();
                barcoNPC.calcDsitancia();


                barco1sprite.setPosition((barcoNPC.getDistancia() / 10) * 1.2 + 90, 100);
                barco2sprite.setPosition((barcoJugador.getDistancia() / 10) * 1.2 + 90, 200);

                
                actInfo();




                //barcoNPC.getParameters();
                //barcoJugador.getParameters();
                //***************************************
            }

        }
        
        if (event.type == sf::Event::MouseButtonReleased) {
            buttonPressed = false;
        }
        if (turno == 5) {
            partida = 2;
            if (barcoJugador.getDistancia() > barcoNPC.getDistancia()) {
                ganador = true;
                if (sumado) {
                    sumado = false;
                    azul += 1;

                    if (apuesta != 0) {
                        cartera +=  apuesta * 2;
                        apuesta = 0;
                        labelApuesta.setString(to_string(apuesta));
                        total.setString(to_string(cartera));

                    }

                }
                
            }
            else {
                ganador = false;
                if (sumado) {
                    sumado = false;
                    rojo += 1;
                    apuesta = 0;
                    labelApuesta.setString("000");
                }

            }
            labelAzul.setString(to_string(azul));
            labelRojo.setString(to_string(rojo));
        }
       
        
        window.clear(Color(102, 153, 255));
        window.draw(fondo);
        if (partida == 1) {
            window.draw(button2);
            next.setString("NEXT");
            if (barcoJugador.getNitro())
            {
                window.draw(button);
                window.draw(nitro);              
                next.setPosition(590, 325);
            }
            else {
                button2.setPosition(500, 320);              
                next.setPosition(530, 325);
                
            }
            window.draw(next);
        }else if(partida == 2){
            if (ganador) {
                labelGanador.setString("GANADOR: AZUL");
            }else{

                labelGanador.setString("GANADOR: ROJO");
            }

            
            window.draw(labelGanador);
            window.draw(buttonRes);
            next.setString("RESTART");
            next.setPosition(514, 338);
            window.draw(next);
        }

        // DIBUJAR INFO JUGADORES :)

        window.draw(labelInfoNPC);
        window.draw(labelInfoJugador);

        //INFO GENERAL
        window.draw(labelTurno);
        window.draw(total);
        window.draw(labelApuesta);
        window.draw(buttonSuma);
        window.draw(buttonResta);
        window.draw(barco1sprite);
        window.draw(barco2sprite);
        window.draw(labelRojo);
        window.draw(labelAzul);
        window.display();
    }

    
    return 0;
}