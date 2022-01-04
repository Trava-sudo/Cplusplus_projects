// This project uses a library from a past professor, creating object and simulating their movement in a 2D space, which
// should represent the solar system. 


#include "passe_par_tout.h"

class Pianeta{

double funzione(double*);

public:

double radius; 
double mass;
double angle; 	
double semiax;          
double ecc;   
double velocity;
double AngularVelocity;
double Momentum;         
double Costant;  

void setAngle(double);
void setRadius(double);
void setMass(double);
void setSemiax(double);
void setEcc(double);
void setVelocity(double);

double getAngularVelocity(double, double);
double getMomentum(double, double, double);
double getCostant(double, double, double, double);		
double Runge_Kutta(double *, double *, double);
};


void Pianeta::setRadius(double r){ radius = r;}
void Pianeta::setMass(double m){ mass = m;}
void Pianeta::setSemiax(double a){ semiax = a;}
void Pianeta::setEcc(double e){ ecc = e;}
void Pianeta::setVelocity(double v){ velocity= v;}
void Pianeta::setAngle(double q){angle = q;}
double Pianeta::getAngularVelocity(double velocity, double radius)
						{AngularVelocity=(velocity)/(radius); return AngularVelocity;}
double Pianeta::getMomentum(double AngularVelocity, double radius, double mass)
						{Momentum = mass * AngularVelocity * (pow(radius,2)); return Momentum;}
double Pianeta::getCostant(double Momentum, double ecc, double mass, double semiax)
						{Costant = Momentum/(mass * (pow(semiax, 2)) * ( pow(1-(pow(ecc, 2)),2))); return Costant;}
double Pianeta::Runge_Kutta(double *radius, double *angle, double dt) {
  double k1, k2, k3, k4;

	k1 = funzione(angle);
	double fantoccio1 = *angle + (dt / 2.0) * k1;
	k2 = funzione(&fantoccio1);
	double fantoccio2 = *angle + (dt / 2.0) * k2;
	k3 = funzione(&fantoccio2);
	double fantoccio3 = *angle + (dt / 2.0) * k3;
	k4 = funzione(&fantoccio3);

  return *angle += dt * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;

  return *radius = (semiax * (1-pow(ecc,2))) / (1+(ecc * cos(*angle)));
}

double Pianeta::funzione(double *angle) {return (Costant * (( 1 + ecc * pow((cos(*angle)),2))));}

int main(){  

char
*u=const_cast<char *>(""),
*file= const_cast<char *>("film");
//*file1= const_cast<char *>("francescotravaglinifilm");
char *montaggio= const_cast<char *>("montaggio");
double xmin = -180; 
double ymin = -180;
double G;  
double rgb[]={0.099, 0.099, 0.43}, rgb_mercurio[]={0.502, 0.502, 0.502},
 rgb_venere[]={0.62745, 0.3215, 0.176}, rgb_terra[]={0.1176, 0.565, 1},
 rgb_marte[]={0.957, 0.643, 0.3921}, rgb_giove[]={0, 0.4706, 0.5098},
 rgb_saturno[]={1, 0.92157, 0.8039}, rgb_urano[]={0.941176, 1, 1},
 rgb_nettuno[]={0.5098, 0.4314, 0.863};
double xmax = 180 ;  
double ymax = 180 ; 
int H, M= 800, N= 800, j, i;
m_startg(u, &M, &N);
int U;
M = N = 99;
m_window(&M, &N);
M=1, N=m_new_color(rgb, rgb+1, rgb+2);
m_use_as_pixmap(&M, &N);

m_frame(&xmin, &ymin, &xmax, &ymax);
int 
colore_mercurio =m_new_color(rgb_mercurio ,rgb_mercurio+1, rgb_mercurio+2), 
colore_venere =m_new_color(rgb_venere, rgb_venere+1, rgb_venere+2),
colore_terra =m_new_color(rgb_terra, rgb_terra+1, rgb_terra+2),
colore_marte =m_new_color(rgb_marte ,rgb_marte+1, rgb_marte+2),
colore_giove =m_new_color(rgb_giove ,rgb_giove+1, rgb_giove+2),
colore_saturno =m_new_color(rgb_saturno ,rgb_saturno+1, rgb_saturno+2),
colore_urano =m_new_color(rgb_urano ,rgb_urano+1, rgb_urano+2),
colore_nettuno =m_new_color(rgb_nettuno ,rgb_nettuno+1, rgb_nettuno+2);

double sole_coor[2], mercurio_coor[2], venere_coor[2], terra_coor[2], marte_coor[2], 
		giove_coor[2], saturno_coor[2], urano_coor[2], nettuno_coor[2];

	Pianeta Venere;
		Venere.setMass(4.8675e24);
		Venere.setRadius(1.0748e8);
		Venere.setAngle(0);
		Venere.setSemiax(1.0821e8);
		Venere.setEcc(0.0067);
		Venere.setVelocity(35.26);
		Venere.getAngularVelocity(Venere.velocity, Venere.radius);
		Venere.getMomentum(Venere.AngularVelocity, Venere.radius, Venere.mass);
		Venere.getCostant(Venere.Momentum, Venere.ecc, Venere.mass, Venere.semiax);
	Pianeta Mercurio;
		Mercurio.setRadius(4.6e7);
		Mercurio.setAngle(0);
		Mercurio.setSemiax(5.791e7);
		Mercurio.setMass(3.3011e23);
		Mercurio.setEcc(0.2056);
		Mercurio.setVelocity(58.98);
		Mercurio.getAngularVelocity(Mercurio.velocity, Mercurio.radius);
		Mercurio.getMomentum(Mercurio.AngularVelocity, Mercurio.radius, Mercurio.mass);
		Mercurio.getCostant(Mercurio.Momentum, Mercurio.ecc, Mercurio.mass, Mercurio.semiax);
 	Pianeta Terra;
		Terra.setMass(5.9726e24);
		Terra.setRadius(147098074);
		Terra.setAngle(0);
		Terra.setSemiax(149597887.5);
		Terra.setEcc(0.016710219);
		Terra.setVelocity(30.287);
		Terra.getAngularVelocity(Terra.velocity, Terra.radius);
		Terra.getMomentum(Terra.AngularVelocity, Terra.radius, Terra.mass);
		Terra.getCostant(Terra.Momentum, Terra.ecc, Terra.mass, Terra.semiax);
	Pianeta Marte;
		Marte.setMass(6.4185e23);
		Marte.setRadius(206644545);
		Marte.setAngle(0);
		Marte.setSemiax(227936637);
		Marte.setEcc(0.09341233);
		Marte.setVelocity(26.499);
		Marte.getAngularVelocity(Marte.velocity, Marte.radius);
		Marte.getMomentum(Marte.AngularVelocity, Marte.radius, Marte.mass);
		Marte.getCostant(Marte.Momentum, Marte.ecc, Marte.mass, Marte.semiax);
	Pianeta Giove;
		Giove.setMass(1.8986e27);
		Giove.setRadius(740742598);
		Giove.setAngle(0);
		Giove.setSemiax(778412027);
		Giove.setEcc(0.04839266);
		Giove.setVelocity(13.712);
		Giove.getAngularVelocity(Giove.velocity, Giove.radius);
		Giove.getMomentum(Giove.AngularVelocity, Giove.radius, Giove.mass);
		Giove.getCostant(Giove.Momentum, Giove.ecc, Giove.mass, Giove.semiax);
	Pianeta Saturno;
		Saturno.setMass(5.6834e26);
		Saturno.setRadius(135255e4);
		Saturno.setAngle(0);
		Saturno.setSemiax(143353e4);
		Saturno.setEcc(0.0565);
		Saturno.setVelocity(10.18);		
		Saturno.getAngularVelocity(Saturno.velocity, Saturno.radius);
		Saturno.getMomentum(Saturno.AngularVelocity, Saturno.radius, Saturno.mass);
		Saturno.getCostant(Saturno.Momentum, Saturno.ecc, Saturno.mass, Saturno.semiax);
	Pianeta Urano;
		Urano.setMass(86.813e24);
		Urano.setRadius(2741.3e6);
		Urano.setAngle(0);
		Urano.setSemiax(2872.46e6);
		Urano.setEcc(0.0457);
		Urano.setVelocity(7.11);
		Urano.getAngularVelocity(Urano.velocity, Urano.radius);
		Urano.getMomentum(Urano.AngularVelocity, Urano.radius, Urano.mass);
		Urano.getCostant(Urano.Momentum, Urano.ecc, Urano.mass, Urano.semiax);
	Pianeta Nettuno;
		Nettuno.setMass(1.0243e26);
		Nettuno.setRadius(4459631496);
		Nettuno.setAngle(0);
		Nettuno.setSemiax(4498252900);
		Nettuno.setEcc(0.00858587);
		Nettuno.setVelocity(5.479);
		Nettuno.getAngularVelocity(Nettuno.velocity, Nettuno.radius);
		Nettuno.getMomentum(Nettuno.AngularVelocity, Nettuno.radius, Nettuno.mass);
		Nettuno.getCostant(Nettuno.Momentum, Nettuno.ecc, Nettuno.mass, Nettuno.semiax);



// In these next lines I used for the radii of the planets new values because the values entered before made it
// so that the 2D simulation failed, with the new values the simulation work even though scales are not proportional to
// reality.


double dt=406880;   //secondi in 5,... giorni, cioè il tempo per cui Mercurio compia 15 gradi sulla sua orbita 

mercurio_coor[0] = /*Mercurio.radius*/5 * cos(Mercurio.angle);
mercurio_coor[1] = /*Mercurio.radius*/5 * sin(Mercurio.angle);
venere_coor[0] = /*Venere.radius*/16 * cos(Venere.angle);
venere_coor[1] = /*Venere.radius*/16 * sin(Venere.angle);
terra_coor[0] = /*Terra.radius*/23 * cos(Terra.angle);
terra_coor[1] = /*Terra.radius*/23 * sin(Terra.angle);
marte_coor[0] = /*Marte.radius*/40 * cos(Marte.angle);
marte_coor[1] = /*Marte.radius*/40 * sin(Marte.angle);
giove_coor[0] = /*Giove.radius*/55 * cos(Giove.angle);
giove_coor[1] = /*Giove.radius*/55 * sin(Giove.angle);
saturno_coor[0] = /*Saturno.radius*/75 * cos(Saturno.angle);
saturno_coor[1] = /*Saturno.radius*/75 * sin(Saturno.angle);
urano_coor[0] = /*Urano.radius*/105 * cos(Urano.angle);
urano_coor[1] = /*Urano.radius*/105 * sin(Urano.angle);
nettuno_coor[0] = /*Nettuno.radius*/160 * cos(Nettuno.angle);
nettuno_coor[1] = /*Nettuno.radius*/160 * sin(Nettuno.angle);

H=3; double dimensioni[8]={0.9, 1.11, 1.13, 0.98, 2.2, 1.94, 1.53, 1.5};

for(i=1; i<=1000; i++)
{

M = 1, N = -1,
m_clear_pixmap(&M, &N);
m_reset_size_symbol();

mercurio_coor[0] = /*Mercurio.radius*/5 * cos(Mercurio.angle);
mercurio_coor[1] = /*Mercurio.radius*/5 * sin(Mercurio.angle);
venere_coor[0] = /*Venere.radius*/16 * cos(Venere.angle);
venere_coor[1] = /*Venere.radius*/16 * sin(Venere.angle);
terra_coor[0] = /*Terra.radius*/23 * cos(Terra.angle);
terra_coor[1] = /*Terra.radius*/23 * sin(Terra.angle);
marte_coor[0] = /*Marte.radius*/40 * cos(Marte.angle);
marte_coor[1] = /*Marte.radius*/40 * sin(Marte.angle);
giove_coor[0] = /*Giove.radius*/55 * cos(Giove.angle);
giove_coor[1] = /*Giove.radius*/55 * sin(Giove.angle);
saturno_coor[0] = /*Saturno.radius*/75 * cos(Saturno.angle);
saturno_coor[1] = /*Saturno.radius*/75 * sin(Saturno.angle);
urano_coor[0] = /*Urano.radius*/105 * cos(Urano.angle);
urano_coor[1] = /*Urano.radius*/105 * sin(Urano.angle);
nettuno_coor[0] = /*Nettuno.radius*/160 * cos(Nettuno.angle);
nettuno_coor[1] = /*Nettuno.radius*/160 * sin(Nettuno.angle);

m_symbol(&H);
m_size_symbol(&dimensioni[0]);
//M=m_new_color(rgb_mercurio, rgb_mercurio+1, rgb_mercurio+2);
m_color(&colore_mercurio);
m_point(mercurio_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[1]);
m_color(&colore_venere);
m_point(venere_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[2]);
m_color(&colore_terra);
m_point(terra_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[3]);
m_color(&colore_marte);
m_point(marte_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[4]);
m_color(&colore_giove);
m_point(giove_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[5]);
m_color(&colore_saturno);
m_point(saturno_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[6]);
m_color(&colore_urano);
m_point(urano_coor);
m_reset_size_symbol();

m_symbol(&H);
m_size_symbol(&dimensioni[7]);
m_color(&colore_nettuno);
m_point(nettuno_coor);
m_reset_size_symbol();

Mercurio.Runge_Kutta(&Mercurio.radius, &Mercurio.angle, dt );
Venere.Runge_Kutta(&Venere.radius, &Venere.angle, dt );
Terra.Runge_Kutta(&Terra.radius, &Terra.angle, dt );
Marte.Runge_Kutta(&Marte.radius, &Marte.angle, dt );
Giove.Runge_Kutta(&Giove.radius, &Giove.angle, dt );
Saturno.Runge_Kutta(&Saturno.radius, &Saturno.angle, dt);
Urano.Runge_Kutta(&Urano.radius, &Urano.angle, dt );
Nettuno.Runge_Kutta(&Nettuno.radius, &Nettuno.angle, dt );

m_move(mercurio_coor);
m_move(venere_coor);
m_move(terra_coor);
m_move(marte_coor);
m_move(giove_coor);
m_move(saturno_coor);
m_move(urano_coor);
m_move(nettuno_coor);

M = -1, N = 'a',
m_flush(  ),
M = 0,
m_redraw(&M),
m_write_owned_photogram(&M, file, &i);

}
int *ph = (int *)NULL;
m_mount_owned_film(file, montaggio, ph);

M=0, N=-1;
m_loop_for_events(&M, &N);
m_endg();

}
