#ifndef REGRASNEGOCIO_H
#define REGRASNEGOCIO_H

#include "..\Livro\Livro.h"
#include "..\Usuario\Usuario.h"
#include "..\ExemplarLivro\ExemplarLivro.h"
#include <vector>
#include <string>

class RegrasNegocio {
public:
    /**
     * Verifica se um livro pode ser removido do acervo
     * Regra: Um livro nao pode ser removido se estiver emprestado ou reservado
     */
    static bool podeRemoverLivro(Livro* livro, 
                                  const std::vector<class Emprestimo*>& emprestimos,
                                  const std::vector<class Reserva*>& reservas);
    
    /**
     * Verifica se um usuario pode realizar emprestimo
     * Regra: Um usuario em debito nao pode realizar emprestimo
     */
    static bool podeRealizarEmprestimo(Usuario* usuario);
    
    /**
     * Verifica a disponibilidade de um livro em um determinado periodo
     * Regra: Um livro esta disponivel se: exemplares disponiveis > reservas no periodo
     */
    static bool livroDisponivel(Livro* livro,
                                int dataInicio, 
                                int dataFim,
                                const std::vector<class Reserva*>& reservas);
    
    /**
     * Verifica se um exemplar esta disponivel para emprestimo
     * Regra: Um exemplar nao pode estar em emprestimo ativo
     */
    static bool exemplarDisponivel(ExemplarLivro* exemplar,
                                   const std::vector<class Emprestimo*>& emprestimos);
    
    /**
     * Valida a insercao de um exemplar em um emprestimo
     * Regra: Um exemplar nao pode estar duplicado no mesmo emprestimo
     */
    static bool exemplarNaoDuplicado(ExemplarLivro* exemplar,
                                     const std::vector<class ItemEmprestimo*>& itens);
    
    /**
     * Calcula a data prevista de devolucao baseado no tipo de usuario
     */
    static int calcularDataDevolucao(Usuario* usuario, int dataRetirada);
    
    /**
     * Conta quantas reservas um livro tem em um determinado periodo
     */
    static int contarReservasNoPeriodo(Livro* livro,
                                       int dataInicio,
                                       int dataFim,
                                       const std::vector<class Reserva*>& reservas);
    
    /**
     * NOVAS REGRAS PARA REQUISITOS ADICIONAIS
     */
    
    /**
     * Verifica se uma entidade ja existe (evita duplicacao)
     * Regra: Nao se pode cadastrar a mesma entidade duas vezes
     */
    static bool livroJaExiste(int codigo, const std::vector<Livro*>& livros);
    static bool usuarioJaExiste(int id, const std::vector<Usuario*>& usuarios);
    static bool autorJaExiste(int id, const std::vector<class Autor*>& autores);
    static bool editoraJaExiste(int id, const std::vector<class Editora*>& editoras);
    
    /**
     * Verifica se um usuario/exemplar pode ser removido
     * Regra: Nao pode ser removido se estiver em emprestimo/reserva ativo
     */
    static bool podeRemoverUsuario(Usuario* usuario,
                                   const std::vector<class Emprestimo*>& emprestimos,
                                   const std::vector<class Reserva*>& reservas);
    
    static bool podeRemoverExemplar(ExemplarLivro* exemplar,
                                    const std::vector<class Emprestimo*>& emprestimos,
                                    const std::vector<class Reserva*>& reservas);
    
    /**
     * Verifica se usuario esta em debito
     * Regra: Um emprestimo com data de devolucao vencida = debito
     */
    static bool usuarioEmDebito(Usuario* usuario,
                                const std::vector<class Emprestimo*>& emprestimos,
                                int dataAtual);
    
    /**
     * Valida todas as condicoes para criar uma reserva
     * Regra: Usuario sem debito + Exemplar disponivel no periodo
     */
    static bool podeRealizarReserva(Usuario* usuario,
                                    ExemplarLivro* exemplar,
                                    int dataRetirada,
                                    const std::vector<class Emprestimo*>& emprestimos,
                                    const std::vector<class Reserva*>& reservas,
                                    int dataAtual);
    
    /**
     * Valida todas as condicoes para criar um emprestimo
     * Regra: Usuario sem debito + Exemplar disponivel
     */
    static bool podeRealizarEmprestimoCompleto(Usuario* usuario,
                                               ExemplarLivro* exemplar,
                                               const std::vector<class Emprestimo*>& emprestimos,
                                               const std::vector<class Reserva*>& reservas,
                                               int dataAtual);
};

#endif
