#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Endereco {
    private:
        string rua;
        int numero;
        string bairro;
        string cidade;
        string estado;
        string cep;
    
    public:
        Endereco(const string& rua, const int& id, const string& bairro, const string& cidade, const string& estado, const string& cep);
        Endereco();

        string getRua() const;
        int getNumero() const;
        string getBairro() const;
        string getCidade() const; 
        string getEstado() const;
        string getCep() const;

        void setRua(const string& rua);
        void setNumero(const int& numero);
        void setBairro(const string& bairro);
        void setCidade(const string& cidade);
        void setEstado(const string& estado);
        void setCep(const string& cep);
        
};
