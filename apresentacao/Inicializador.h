#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H

class Inicializador {
public:
    /**
     * Carrega dados pre-cadastrados para facilitar testes
     * Cria: 3 editoras, 5 autores, 2 livros, 2 usuarios, 1 exemplar
     */
    static void carregarDadosPrecadastrados();
    
    /**
     * Limpa todos os dados do sistema (descarregamento)
     */
    static void limparDados();
    
    /**
     * Exibe dados carregados (apenas para DEBUG)
     */
    static void exibirDadosCarregados();
};

#endif
