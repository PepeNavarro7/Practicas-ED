#ifndef __lista_palabras_h__
#define __lista_palabras_h__

#include <set>
#include <vector>
#include <string>

using namespace std;

struct comparador{
  bool menor(const char& c1, const char& c2) const{
    if(c1>='a'&&c1<='n'){ //c1 <ñ
      return (c2>='a'&&c2<='n')?c1<c2:true;
    } else {
      if(c1>='o'&&c1<='z') // c1 >ñ
        return (c2>='o'&&c2<='z')?c1<c2:false;
      else // c1=ñ
        return (c2>='a'&&c2<='n')?false:true;
    }
  }
  bool operator() (const string& s1, const string& s2) const{
    for(unsigned i=0; i<s1.length() && i<s2.length(); ++i){
      if(s1[i]!=s2[i]){
        return menor(s1[i],s2[i]);
      }
    }
    return (s1.length()<s2.length());
  }
};

class lista_palabras{
private:
  set<string,comparador> datos;

public:
/**
  * @brief Construye un lista_palabras vacio
  **/
  lista_palabras();

/**
  * @brief Devuelve el numero de palabras en el lista_palabras
  **/
  int size() const;

/**
  * @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
  * @param longitud la longitud de las palabras de salida
  * @return un vector con las palabras de longitud especificada en el parámetro de entrada
  **/
  vector<string> palabras_longitud(const int &longitud) const;

/**
  * @brief Indica si una palabra está en el lista_palabras o no
  * @param palabra la palabra que se quiere buscar
  * @return true si la palabra esta en el lista_palabras. false en caso contrario
  **/
  bool Esta(const string &palabra) const;

/**
  * @brief Lee de un flujo de entrada un lista_palabras
  * @param is flujo de entrada
  * @param D el objeto donde se realiza la lectura.
  * @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is, lista_palabras &D);

/**
  * @brief Escribe en un flujo de salida un lista_palabras
  * @param os flujo de salida
  * @param D el objeto lista_palabras que se escribe
  * @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const lista_palabras &D);

  class iterator {
  private:
    set<string>::iterator it;

  public:
    iterator ();
    string operator *() const;
    iterator & operator ++();
    bool operator ==(const iterator &i) const;
    bool operator !=(const iterator &i) const;
    friend class lista_palabras;
  };

  iterator begin() const;
  iterator end() const;
};
#endif
