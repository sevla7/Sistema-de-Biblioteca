#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include <vector>
#include <algorithm>

template <typename T>
class Repositorio {
protected:
    std::vector<T> dados;

public:
    Repositorio() {}
    virtual ~Repositorio() {}
    
    // Operacoes CRUD basicas
    void adicionar(const T& item) {
        dados.push_back(item);
    }
    
    void remover(const T& item) {
        dados.erase(std::remove(dados.begin(), dados.end(), item), dados.end());
    }
    
    const std::vector<T>& obterTodos() const {
        return dados;
    }
    
    int obterTotal() const {
        return dados.size();
    }
    
    bool vazio() const {
        return dados.empty();
    }
};

#endif
