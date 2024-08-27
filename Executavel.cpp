#include <iostream>
#include <conio.h>

struct Cidade{
	int cod_cidade;
	string nome;
	string uf;
};

struct Especialidade_Medica{
	int cod_especialidade;
	string descricao;
};

struct Medico{
	int cod_medico;
	string nome;
	int cod_especialidade;
	string endereco;
	string telefone;
	int cod_cidade;
};

struct Paciente{
	int cod_paciente;
	string nome;
	string endereco;
	cod_cidade;
};

struct CID {
	int cod_CID;
	string descricao;
};

struct Medicamento{
	int cod_medicamento;
	string descricao;
	int qtde_estoque;
	int estoque_minimo;
	int estoque_maximo;
	float preco_unitario;
};
