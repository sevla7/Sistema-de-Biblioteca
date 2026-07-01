#include "RegrasNegocio.h"
#include "..\emp\Emprestimo.h"
#include "..\Reserva\Reserva.h"
#include "..\Reserva\ItemReserva.h"
#include "..\itemEmp\ItemEmprestimo.h"
#include "..\ExemplarLivro\StatusEmprestimo.h"
#include <iostream>

bool RegrasNegocio::podeRemoverLivro(Livro* livro,
                                     const std::vector<Emprestimo*>& emprestimos,
                                     const std::vector<Reserva*>& reservas) {
    if (livro == nullptr) return false;
    
    // Verifica se o livro esta em algum emprestimo ativo
    for (const auto& emp : emprestimos) {
        if (emp->getLivro()->getCodigo() == livro->getCodigo() && 
            emp->getDataDevolucao() == 0) { // 0 significa nao devolvido
            std::cout << "[ERRO] Livro nao pode ser removido - esta emprestado!" << std::endl;
            return false;
        }
    }
    
    // Verifica se o livro tem reservas ativas
    for (const auto& res : reservas) {
        for (const auto& item : res->getItems()) {
            if (item->getExemplar()->getLivro()->getCodigo() == livro->getCodigo()) {
                std::cout << "[ERRO] Livro nao pode ser removido - tem reservas ativas!" << std::endl;
                return false;
            }
        }
    }
    
    return true;
}

bool RegrasNegocio::podeRealizarEmprestimo(Usuario* usuario) {
    if (usuario == nullptr) return false;
    
    // Usa o metodo virtual para verificar se o usuario pode emprestar
    return usuario->podeRealizarEmprestimo();
}

bool RegrasNegocio::livroDisponivel(Livro* livro,
                                    int dataInicio,
                                    int dataFim,
                                    const std::vector<Reserva*>& reservas) {
    if (livro == nullptr || livro->getQuantidadeExemplares() <= 0) {
        return false;
    }
    
    int reservasNoPeriodo = contarReservasNoPeriodo(livro, dataInicio, dataFim, reservas);
    return livro->getQuantidadeExemplares() > reservasNoPeriodo;
}

bool RegrasNegocio::exemplarDisponivel(ExemplarLivro* exemplar,
                                       const std::vector<Emprestimo*>& emprestimos) {
    if (exemplar == nullptr) return false;
    
    // Verifica se o exemplar esta em algum emprestimo ativo
    for (const auto& emp : emprestimos) {
        // Aqui seria necessario acessar os itens de emprestimo
        // Por enquanto, verificamos pelo status
        if (exemplar->getStatus() != StatusEmprestimo::DISPONIVEL) {
            return false;
        }
    }
    
    return true;
}

bool RegrasNegocio::exemplarNaoDuplicado(ExemplarLivro* exemplar,
                                         const std::vector<ItemEmprestimo*>& itens) {
    if (exemplar == nullptr) return true;
    
    // Verifica se o exemplar ja esta nos itens
    for (const auto& item : itens) {
        if (item->getExemplar() == exemplar) {
            std::cout << "[ERRO] Este exemplar ja foi adicionado!" << std::endl;
            return false;
        }
    }
    
    return true;
}

int RegrasNegocio::calcularDataDevolucao(Usuario* usuario, int dataRetirada) {
    if (usuario == nullptr) return 0;
    
    // Usa o metodo virtual para obter os dias permitidos
    int diasPermitidos = usuario->getDiasEmprestimoPermitido();
    return dataRetirada + diasPermitidos;
}

int RegrasNegocio::contarReservasNoPeriodo(Livro* livro,
                                           int dataInicio,
                                           int dataFim,
                                           const std::vector<Reserva*>& reservas) {
    if (livro == nullptr) return 0;
    
    int contador = 0;
    
    for (const auto& res : reservas) {
        for (const auto& item : res->getItems()) {
            ExemplarLivro* exemplar = item->getExemplar();
            if (exemplar != nullptr && 
                exemplar->getLivro()->getCodigo() == livro->getCodigo()) {
                
                int dataRetirada = item->getDataDeRetirada();
                // Verifica se a data de retirada esta no periodo
                if (dataRetirada >= dataInicio && dataRetirada <= dataFim) {
                    contador++;
                }
            }
        }
    }
    
    return contador;
}

// ===== NOVAS VALIDACOES =====

bool RegrasNegocio::livroJaExiste(int codigo, const std::vector<Livro*>& livros) {
    for (const auto& livro : livros) {
        if (livro->getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool RegrasNegocio::usuarioJaExiste(int id, const std::vector<Usuario*>& usuarios) {
    for (const auto& usuario : usuarios) {
        if (usuario->getID() == id) {
            return true;
        }
    }
    return false;
}

bool RegrasNegocio::autorJaExiste(int id, const std::vector<class Autor*>& autores) {
    for (const auto& autor : autores) {
        if (autor->getCodigo() == id) {
            return true;
        }
    }
    return false;
}

bool RegrasNegocio::editoraJaExiste(int id, const std::vector<class Editora*>& editoras) {
    for (const auto& editora : editoras) {
        if (editora->getId() == id) {
            return true;
        }
    }
    return false;
}

bool RegrasNegocio::podeRemoverUsuario(Usuario* usuario,
                                       const std::vector<class Emprestimo*>& emprestimos,
                                       const std::vector<class Reserva*>& reservas) {
    if (usuario == nullptr) return false;
    
    // Verifica emprestimos ativos
    for (const auto& emp : emprestimos) {
        if (emp->getUsuario()->getID() == usuario->getID() && emp->getDataDevolucao() == 0) {
            std::cout << "[ERRO] Usuario nao pode ser removido - tem emprestimo ativo!" << std::endl;
            return false;
        }
    }
    
    // Verifica reservas ativas
    for (const auto& res : reservas) {
        if (res->getUsuario()->getID() == usuario->getID()) {
            std::cout << "[ERRO] Usuario nao pode ser removido - tem reserva ativa!" << std::endl;
            return false;
        }
    }
    
    return true;
}

bool RegrasNegocio::podeRemoverExemplar(ExemplarLivro* exemplar,
                                        const std::vector<class Emprestimo*>& emprestimos,
                                        const std::vector<class Reserva*>& reservas) {
    if (exemplar == nullptr) return false;

    // Verifica se o exemplar esta em emprestimo ativo
    for (const auto& emp : emprestimos) {
        if (emp->getLivro() == exemplar->getLivro() &&
            emp->getDataDevolucao() == 0) {
            std::cout << "[ERRO] Exemplar nao pode ser removido - esta em emprestimo ativo!" << std::endl;
            return false;
        }
    }

    // Verifica se o exemplar esta em reserva ativa
    for (const auto& res : reservas) {
        for (const auto& item : res->getItems()) {
            if (item->getExemplar() == exemplar) {
                std::cout << "[ERRO] Exemplar nao pode ser removido - esta em reserva ativa!" << std::endl;
                return false;
            }
        }
    }

    return true;
}

bool RegrasNegocio::usuarioEmDebito(Usuario* usuario,
                                    const std::vector<class Emprestimo*>& emprestimos,
                                    int dataAtual) {
    if (usuario == nullptr) return false;
    
    // Verifica se tem emprestimo com devolucao atrasada
    for (const auto& emp : emprestimos) {
        if (emp->getUsuario()->getID() == usuario->getID() && 
            emp->getDataDevolucao() == 0 && // Nao foi devolvido
            emp->getDataPrevistaDevolucao() < dataAtual) { // Prazo vencido
            std::cout << "[ERRO] Usuario em debito! Devolva o livro anterior antes de fazer nova transacao." << std::endl;
            return true;
        }
    }
    
    return false;
}

bool RegrasNegocio::podeRealizarReserva(Usuario* usuario,
                                        ExemplarLivro* exemplar,
                                        int dataRetirada,
                                        const std::vector<class Emprestimo*>& emprestimos,
                                        const std::vector<class Reserva*>& reservas,
                                        int dataAtual) {
    if (usuario == nullptr || exemplar == nullptr) return false;
    
    // Verifica se usuario esta em debito
    if (usuarioEmDebito(usuario, emprestimos, dataAtual)) {
        return false;
    }
    
    // Verifica se exemplar esta disponivel no periodo
    if (!exemplarDisponivel(exemplar, emprestimos)) {
        std::cout << "[ERRO] Exemplar nao esta disponivel!" << std::endl;
        return false;
    }
    
    return true;
}

bool RegrasNegocio::podeRealizarEmprestimoCompleto(Usuario* usuario,
                                                   ExemplarLivro* exemplar,
                                                   const std::vector<class Emprestimo*>& emprestimos,
                                                   const std::vector<class Reserva*>& reservas,
                                                   int dataAtual) {
    if (usuario == nullptr || exemplar == nullptr) return false;
    
    // Verifica se usuario pode emprestar (metodo abstrato implementado)
    if (!usuario->podeRealizarEmprestimo()) {
        std::cout << "[ERRO] Usuario nao esta habilitado para emprestimo!" << std::endl;
        return false;
    }
    
    // Verifica se esta em debito
    if (usuarioEmDebito(usuario, emprestimos, dataAtual)) {
        return false;
    }
    
    // Verifica se exemplar esta disponivel
    if (!exemplarDisponivel(exemplar, emprestimos)) {
        std::cout << "[ERRO] Exemplar nao esta disponivel para emprestimo!" << std::endl;
        return false;
    }
    
    return true;
}
