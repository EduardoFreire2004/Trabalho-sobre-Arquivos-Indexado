#include <iostream>
#include <conio.h>

namespace std;

#define t 10
struct Indice{
	int cod;
	int endereco;
};

struct Cidade{
	int cod;
	string nome;
	string uf;
};

struct Especialidade_Medica{
	int cod;
	string descricao;
};

struct Medico{
	int cod;
	string nome;
	int cod_especialidade;
	string endereco;
	string telefone;
	int cod_cidade;
};

struct Paciente{
	int cod;
	string nome;
	string endereco;
	cod_cidade;
};

struct CID {
	int cod;
	string descricao;
};

struct Medicamento{
	int cod;
	string descricao;
	int qtde_estoque;
	int estoque_minimo;
	int estoque_maximo;
	float preco_unitario;
};

struct Consulta{
	int cod;
	int cod_paciente;
	int cod_medico;
	string data;
	string horario;
	int cod_CID;
	int cod_medicamento;
	int qtde_medicamento;
};

void leitura_Cidade(struct Cidade cidade[],int &cont){
	
    int i = 0;    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo da Cidade: ";
        cin >> cidade[i].cod;
        cin.ignore();
		if (cidade[i].cod > 0){
			cout << " Nome da Cidade: ";
            getline(cin,cidade[i].nome);
		    cout << " UF da Cidade: ";
            getline(cin,cidade[i].uf);
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leitura_Especialidade(struct Especialidade esp[],int &cont){
	
    int i = 0;    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo da Especialidade: ";
        cin >> esp[i].cod;
        cin.ignore();
		if (esp[i].cod > 0){
			cout << " Descricao da Especialidade: ";
            getline(cin,esp[i].descricao);
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leitura_CID(struct CID cid[],int &cont){
	
	int i = 0;    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo do CID: ";
        cin >> cid[i].cod;
        cin.ignore();
		if (cid[i].cod > 0){
			cout << " Descricao do CID: ";
            getline(cin,cid[i].descricao);
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
	
}

void leitura_Medicamento(struct Medicamento medicamento[],int &cont){
	
	int i = 0;    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo do Medicamento: ";
        cin >> medicamento[i].cod;
        cin.ignore();
		if (medicamento[i].cod > 0){
			cout << " Descricao do Medicamento: ";
            getline(cin,medicamento[i].descricao);
            cout << " Quantidade em Estoque: ";
            cin >> medicamento[i].qtde_estoque;
            cin.ignore();
            cout << " Quantidade Minima de Estoque: ";
            cin >> medicamento[i].qtde_minima;
            cin.ignore();
            cout << " Quantidade Maxima de Estoque: ";
            cin >> medicamento[i].qtde_maxima;
            cout << " Preco Unitario do Medicamento: "
            cin >> medicamento[i].preco_unitario;
            cin.ignore();
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
}

int busca (struct indice idx[], int cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
    	return idx[m].endereco;
    }
    else return -1;
}



void inclusao_Medico(struct Medico medico[],struct Especialidade esp[],struct Cidade cidade[],struct Indice ind[],struct Indice ind_esp[],struct Indice ind_cidade[],int &cont,int cont_esp,int cont_cidade){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<"Incluir um novo Medico: "<< endl;
		cout<<"Cod: ";
		cin>>medico[cont].codigo;
		cin.ignore();
		if(busca(ind,cont,medico[cont].cod) != -1){
			cod=medico[cont].codigo;
			cout<<"Nome: ";
			getline(cin,medico[cont].cod);
			cout<<"Codigo da Especialidade: ";
			cin>> medico[cont].cod_especialidade;
			cin.ignore();
			int result = busca(ind_esp,cont_esp,medico[cont].cod_especialidade);
			cout<<"Descricao: "<< esp[result].descricao <<endl;
			cout <<"Endereco : ";
			getline(cin,medico[cont].endereco);
			cout<<"Telefone: ";
			getline(cin,medico[cont].telefone);
			result = busca(ind_cidade,cont_cidade,medico[cont].cod_cidade);
			cout<<"Cidade: " << cidade[result].nome " | " << cidade[result].uf <<endl;
			x= -1;  	
		}
		else{
			cout<<"\n Codigo ja existente " <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].codigo > cod ;i--){
		ind[i+1].codigo = ind[i].codigo;
		ind[i+1].ender = ind[i].ender;
	}
	
	ind[i+1].codigo = cod;
	ind[i+1].ender = cont;
	cont++;
}

int main(){

	Especialidade esp[t];
	int cont_esp=0;
	Indice ind_esp[t];
	
	Cidade cidades[t];
	int cont_cidade=0;
	Indice ind_cidade[t];
	
	Medico medico[t];
	int cont_medico=0;
	Indice ind_medico[t];
	
	
}
