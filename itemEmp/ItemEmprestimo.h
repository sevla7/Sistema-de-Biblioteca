#pragma once

class ExemplarLivro; // Declaracao antecipada para evitar dependencia circular
class Emprestimo; 

class ItemEmprestimo {
    private:
       int dataParaDevolucao;
       int dataQueFoiDevolvido;  
       Emprestimo* emprestimo; // Associacao com a classe Emprestimo
       ExemplarLivro* exemplar; // Associacao com a classe ExemplarLivro

    public:
        ItemEmprestimo(int dataParaDevolucao, int dataQueFoiDevolvido, ExemplarLivro *exemplar, Emprestimo *emprestimo);
        ItemEmprestimo();

        int getDataParaDevolucao() const;
        int getDataQueFoiDevolvido() const;
        ExemplarLivro* getExemplar() const;
        Emprestimo* getEmprestimo() const;

        void setDataParaDevolucao(const int dataParaDevolucao);
        void setDataQueFoiDevolvido(const int dataQueFoiDevolvido);
        void setExemplar(ExemplarLivro* exemplar);
        void setEmprestimo(Emprestimo* emprestimo);

        void exibirInformacoes();
};  