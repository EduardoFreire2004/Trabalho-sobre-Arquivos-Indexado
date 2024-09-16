#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

#define z 10
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
	int status;
};

struct Paciente{
	int cod;
	string nome;
	string endereco;
	int cod_cidade;
	int status;
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
	int status;
};

int busca (struct Indice idx[], int cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    if(f == -1){
    	return -1;
	}
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
    	return idx[m].endereco;
    }
    else return -1;
}

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

void mostrar_Cidade(struct Cidade cidade[],int cont){

	for(int i=0;i<cont;i++){
		cout << "\nCodigo da Cidade: " << cidade[i].cod;
        cout << "\tNome: " << cidade[i].nome;
		cout << "\tEstado: " << cidade[i].uf;				
	}
}
	
void leitura_Especialidade(struct Especialidade_Medica esp[],int &cont){
	
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

void mostrar_CID(struct CID cid[],int cont){
	
	for(int i=0;i<cont;i++){
		cout << "\nCodigo do CID: " << cid[i].cod;
        cout << "\tDescricao: " << cid[i].descricao;
	}
}

void mostrar_Especialidade(struct Especialidade_Medica esp[],int cont){
	
	for(int i=0;i<cont;i++){
		cout << "\nCodigo da Especialidade: " << esp[i].cod;
        cout << "\tDescricao: " << esp[i].descricao;
	}
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
            cin >> medicamento[i].estoque_minimo;
            cin.ignore();
            cout << " Quantidade Maxima de Estoque: ";
            cin >> medicamento[i].estoque_maximo;
            cout << " Preco Unitario do Medicamento: ";
            cin >> medicamento[i].preco_unitario;
            cin.ignore();
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
}

void mostrar_Medicamento(struct Medicamento medicamentos[],struct Indice ind[],int cont){
	int med=0;
	for(int x=1;x != -1;){
		cout<<" Digite o Codigo do Medicamento: ";
		cin>>med;
		if(med == 0){
			x=-1;
		}
		else{
			if( busca(ind,cont,med) != -1){
				int i = busca(ind,cont,med);
				cout << "\nCodigo do Medicamento: " << medicamentos[i].cod;
				cout << "\tDescricao: " << medicamentos[i].descricao;
				cout << "\tQuantidade em Estoque: " << medicamentos[i].qtde_estoque;
				cout << "\tQuantidade Minima de Estoque: " << medicamentos[i].estoque_minimo;
				cout << "\tQuantidade Maxima de Estoque: " << medicamentos[i].estoque_maximo;
				cout << "\tPreco Unitario do Medicamento: " << medicamentos[i].preco_unitario;
				cout <<"\nValor Total em Estoque: "<< medicamentos[i].qtde_estoque * medicamentos[i].preco_unitario << endl;
				x=-1;
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}
	}	
}

void estoque_minimo(struct Medicamento medicamentos[],int cont){
	int compra =0,valor=0;
	for(int i=0;i<cont;i++){
		if(medicamentos[i].qtde_estoque < medicamentos[i].estoque_minimo){
			cout << "\nCodigo do Medicamento: " << medicamentos[i].cod;
			cout << "\tDescricao: " << medicamentos[i].descricao;
			cout << "\tQuantidade em Estoque: " << medicamentos[i].qtde_estoque;
			cout << "\tQuantidade Maxima de Estoque: " << medicamentos[i].estoque_maximo;
			cout << "\tPreco Unitario do Medicamento: " << medicamentos[i].preco_unitario;
			compra += medicamentos[i].estoque_maximo-medicamentos[i].qtde_estoque;
			valor += (medicamentos[i].estoque_maximo-medicamentos[i].qtde_estoque)* medicamentos[i].preco_unitario;		
		}
	}
	cout<<"\n ------------------------------"<<endl;
	cout<<" Quantidade a ser Comprada: "<< compra <<endl;
	cout<<"\n ------------------------------"<<endl;
	cout<<" Valor Total da Compra: "<< valor<<endl;
}

void inclusao_Medico(struct Medico medicos[],struct Especialidade_Medica esp[],struct Cidade cidade[],struct Indice ind[],struct Indice ind_esp[],struct Indice ind_cidade[],int &cont,int cont_esp,int cont_cidade){
	int cod=0;
		
	for(int x=1;x != -1;){
		cout<<" Incluir um novo Medico "<< endl;
		cout<<" Cod: ";
		cin>>medicos[cont].cod;
		cin.ignore();
		if(busca(ind,cont,medicos[cont].cod) == -1){
			cod=medicos[cont].cod;
			cout<<" Nome: ";
			getline(cin,medicos[cont].nome);
			cout<<" Codigo da Especialidade: ";
			cin>> medicos[cont].cod_especialidade;
			cin.ignore();
			int result = busca(ind_esp,cont_esp,medicos[cont].cod_especialidade);
			cout<<" Descricao: "<< esp[result].descricao <<endl;
			cout <<" Endereco : ";
			getline(cin,medicos[cont].endereco);
			cout<<" Codigo da Cidade: ";
			cin>>medicos[cont].cod_cidade;
			cin.ignore();
			result = busca(ind_cidade,cont_cidade,medicos[cont].cod_cidade);
			cout<<" Cidade: " << cidade[result].nome<< " | " << cidade[result].uf <<endl;
			cout<<" Telefone: ";
			getline(cin,medicos[cont].telefone);
			cout<<"\n### Medico Cadastrado com sucesso### "<<endl;
			medicos[cont].status = 0;
			x= -1;  	
		}
		else{
			cout<<"\n ### Codigo ja existente ### \n" <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].cod > cod ;i--){
		ind[i+1].cod = ind[i].cod;
		ind[i+1].endereco = ind[i].endereco;
		
	}
	
	ind[i+1].cod = cod;
	ind[i+1].endereco = cont;
	cont++;
}

void exclusao_Medico(struct Medico medicos[],struct Indice ind[],int cont,struct Indice ind_consulta[],int cont_consulta){
	int ex;
	for(int x=1;x != -1;){
		cout<<" Digite o codigo da exclusao do Medico: ";
		cin>>ex;
		if(ex == 0){
			x=-1;
		}
		else{
			int result = busca(ind,cont,ex);
			if(result != -1){
				if(busca(ind_consulta,cont_consulta,medicos[result].cod) == -1){
					if(medicos[result].status != 1){
						cout << "\n Codigo do Medico: " << medicos[result].cod; 
					    cout << "\n Nome: " << medicos[result].nome;
					    medicos[result].status = 1;
					    cout<<"\n\n ### Medico Excluido com Sucesso ### \n" <<endl;
					    x=-1;
					}
					else{
						cout<<"\n ### Medico ja Excluido ### \n" <<endl;
					}
				}	
				else{
					cout<<"\n ### Nao foi possivel concluir a operacao ### " <<endl;
					cout<<"\n Medico esta cadastrado em uma consulta \n" <<endl;
				}
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}	
	}	
}

void mostrar_Medico(struct Medico medico[],struct Indice ind[],int cont){
	
	for(int i=0;i<cont;i++){
		int k= ind[i].endereco;
		if(medico[k].status ==0 ){
			cout << "\nCodigo do Medico: " << medico[k].cod;
	        cout << "\tNome: " << medico[k].nome;
	        cout << "\tEspecialidade: " << medico[k].cod_especialidade;
			cout << "\tEndereco: " << medico[k].endereco;
			cout << "\tTelefone: " << medico[k].telefone;
	        cout << "\tCidade: " << medico[k].cod_cidade;
        }
	}
}

void mostrar_Consulta(struct Consulta consultas[],struct Indice ind[],int cont){
	int con=0;
	for(int x=1;x != -1;){
		cout<<" Digite o Codigo da Consulta: ";
		cin>>con;
		if(con == 0 ){
			x=-1;
		}
		else{
		
			if( busca(ind,cont,con) != -1){
				int i = busca(ind,cont,con);
				cout << "\n Codigo da Consulta: " << consultas[i].cod<<endl;
				cout << " Codigo Paciente: " << consultas[i].cod_paciente<<endl;
				cout << " Codigo Medico: " << consultas[i].cod_medico<<endl;
				cout << " Data: " << consultas[i].data<<endl;
				cout << " Horario: " << consultas[i].horario<<endl;
				cout << " Codigo CID: " << consultas[i].cod_CID<<endl;
				cout << " Codigo Medicamento: " << consultas[i].cod_medicamento<<endl;
				cout << " Quantidade de Medicamento: " << consultas[i].qtde_medicamento<<endl;
				x=-1;
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}
	}	
}

void inclusao_Paciente(struct Paciente pacientes[],struct Indice ind[],struct Cidade cidade[],struct Indice ind_cidade[],int &cont,int cont_cidade){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<" Incluir um novo Paciente "<< endl;
		cout<<" Cod: ";
		cin>>pacientes[cont].cod;
		cin.ignore();
		if(busca(ind,cont,pacientes[cont].cod) == -1){
			cod=pacientes[cont].cod;
			cout<<" Nome: ";
			getline(cin,pacientes[cont].nome);
			cout <<" Endereco : ";
			getline(cin,pacientes[cont].endereco);
			cout<<" Codigo da Cidade: ";
			cin>>pacientes[cont].cod_cidade;
			cin.ignore();
			int result = busca(ind_cidade,cont_cidade,pacientes[cont].cod_cidade);
			cout<<" Cidade: " << cidade[result].nome<< " | " << cidade[result].uf <<endl;
			pacientes[cont].status =0;
			cout<<"\n### Paciente Cadastrado com sucesso ###"<<endl;
			x= -1;  	
		}
		else{
			cout<<"\n ### Codigo ja existente ### \n" <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].cod > cod ;i--){
		ind[i+1].cod = ind[i].cod;
		ind[i+1].endereco = ind[i].endereco;
	}
	
	ind[i+1].cod = cod;
	ind[i+1].endereco = cont;
	cont++;
}

void reorganizacao_paciente (struct Indice idx[], struct Paciente pacientes[], int &cont){
    struct Paciente novo_paciente[cont];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (pacientes[i].status == 0){
            j++;
            novo_paciente[j] = pacientes[i];
            idx[j].cod = novo_paciente[j].cod;
            idx[j].endereco = j;
        }
    }
    cont = j+1;
    
	for (int k = 0; k < cont; k++){
    	int i = idx[k].endereco;
    	pacientes[k] = novo_paciente[i];
	}
	cout<<"\n## Pacientes reorganizado ### "<<endl;
	
}

void mostrar_Paciente(struct Paciente pacientes[],struct Indice ind[],int cont){
	
	for(int i=0;i<cont;i++){
		int k= ind[i].endereco;
		if(pacientes[k].status == 0){
			cout << "\nCodigo do Paciente: " << pacientes[k].cod;
	        cout << "\tNome: " << pacientes[k].nome;
			cout << "\tEndereco: " << pacientes[k].endereco;
	        cout << "\tCidade: " << pacientes[k].cod_cidade;
        }

	}
}

void exclusao_Paciente(struct Paciente pacientes[],struct Indice ind[],int cont,struct Indice ind_consulta[],int cont_consulta){
	int ex;
	for(int x=1;x != -1;){
		cout<<" Digite o codigo da exclusao do Paciente: ";
		cin>>ex;
		if(ex ==0 ){
			x=-1;
		}
		else{
			int result = busca(ind,cont,ex);
			if(result != -1){
				if(busca(ind_consulta,cont_consulta,pacientes[result].cod) == -1){
					if(pacientes[result].status != 1){
						cout << "\n Paciente: " << pacientes[result].cod << " -- " << pacientes[result].nome<<endl;
					    pacientes[result].status = 1;
					    cout<<"\n\n ### Paciente Ecluido com Sucesso ### \n" <<endl;
					    x=-1;
					}
					else{
						cout<<"\n ### Paciente ja Excluido ### \n" <<endl;
					}
				}	
				else{
					cout<<"\n ### Nao foi possivel concluir a operacao ### " <<endl;
					cout<<"\n Paciente esta cadastrado em uma consulta \n" <<endl;
				}
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}

	}	
}

void agendar_Consulta(struct Consulta consultas[],struct Indice ind[],int &cont,struct Paciente pacientes[],struct Indice ind_paciente[],struct Indice ind_pacientesConsulta[],int cont_paciente,struct Medico medicos[],struct Indice ind_medico[],int cont_medico,struct Indice ind_medConsulta[],struct Cidade cidade[],struct Indice ind_cidade[],int cont_cidade,struct CID cid[],struct Indice ind_cid[],int cont_cid,struct Medicamento medicamentos[],struct Indice ind_medicamento[],int cont_medicamento,struct Especialidade_Medica esp[],struct Indice ind_esp[],int cont_esp){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<" Agendar uma nova Consulta "<< endl;
		cout<<" Cod da Consulta: ";
		cin>>consultas[cont].cod;
		cin.ignore();
		if(busca(ind,cont,consultas[cont].cod) == -1){
			cod=consultas[cont].cod;
			cout<<" Codigo do Paciente: ";
			cin>>consultas[cont].cod_paciente;
			cin.ignore();
			int result_paciente = busca(ind_paciente,cont_paciente,consultas[cont].cod_paciente);
			int result_cidade = busca(ind_cidade,cont_cidade,pacientes[result_paciente].cod_cidade);
			cout<<" Nome Paciente: "<<pacientes[result_paciente].nome<<endl;
			cout<<" Cidade: " << cidade[result_cidade].nome<< " | " << cidade[result_cidade].uf <<endl;
			cout<<" Codigo do Medico: ";
			cin>>consultas[cont].cod_medico;
			cin.ignore();
			int result_medico = busca(ind_medico,cont_medico,consultas[cont].cod_medico);
			int result_esp = busca(ind_esp,cont_esp,medicos[result_medico].cod_especialidade);
			cout<<" Nome Medico: "<< medicos[result_medico].nome<<endl;
			cout<<" Especialidade: "<< esp[result_esp].descricao<<endl;
			cout<<" Codigo Cid: ";
			cin>>consultas[cont].cod_CID;
			cin.ignore();
			int result_cid = busca(ind_cid,cont_cid,consultas[cont].cod_CID);
			cout<<" CID: "<< cid[result_cid].descricao<<endl;
			cout<<" Data da Consulta: ";
			getline(cin,consultas[cont].data);
			cout<<" Horario da Consulta: ";
			getline(cin,consultas[cont].horario);
			cout<<" Codigo do Medicamento: ";
			cin>>consultas[cont].cod_medicamento;
			cin.ignore();
			int result_medicamento = busca(ind_medicamento,cont_medicamento,consultas[cont].cod_medicamento);
			cout<<" Medicamento: "<< medicamentos[result_medicamento].descricao<<endl;
			for(int m=1; m != -1;){
				cout<<" Quantidade de Medicamento: ";
				cin>>consultas[cont].qtde_medicamento;
				if(medicamentos[result_medicamento].qtde_estoque  < consultas[cont].qtde_medicamento){
					cout<<"\n### Nao possui esta quantidade em estoque ###"<<endl;
					cout<<" Quantidade em estoque: "<<medicamentos[result_medicamento].qtde_estoque<<endl;
				}
				else{
					medicamentos[result_medicamento].qtde_estoque = medicamentos[result_medicamento].qtde_estoque - consultas[cont].qtde_medicamento;
					m= -1;
				}
			}
			consultas[cont].status=0;
			cout<<"\n### Agendamento Cadastrado com sucesso ###"<<endl;
			x= -1;  	
		}
		else{
			cout<<"\n ### Codigo ja existente ### \n" <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].cod > cod ;i--){
		ind[i+1].cod = ind[i].cod;
		ind[i+1].endereco = ind[i].endereco;
		ind_medConsulta[i+1].cod = consultas[i].cod_medico;
		ind_medConsulta[i+1].endereco = ind[i].endereco;
		ind_pacientesConsulta[i+1].cod = consultas[i].cod_paciente;
		ind_pacientesConsulta[i+1].endereco = ind[i].endereco; 
	}
	
	
	ind_medConsulta[i+1].cod = consultas[cont].cod_medico;
	ind_medConsulta[i+1].endereco = cont; 
	ind_pacientesConsulta[i+1].cod = consultas[cont].cod_paciente;
	ind_pacientesConsulta[i+1].endereco = cont;
	ind[i+1].cod = cod;
	ind[i+1].endereco = cont;
	cont++;
}

void valor_total(struct Consulta consultas[],int cont,struct Medicamento medicamento[],struct Indice ind_medicamento[],int cont_medicamento){
	int total= cont*100;
	int soma=0;
	for(int i=0;i<cont;i++){
		int result = busca(ind_medicamento,cont_medicamento,consultas[i].cod_medicamento);
		soma += consultas[i].qtde_medicamento * medicamento[result].preco_unitario;
	}
	cout<<"\n Valor Arecadado: "<<total+soma<<endl;	
}

int main(){

	int menu_principal=0;
	int menu_cidade=0;
	int menu_esp=0;
	int menu_medico=0;
	int menu_paciente=0;
	int menu_cid=0;
	int menu_medicamento=0;
	int menu_consulta=0;
	int menu_sair=0;
	
	Especialidade_Medica esp[z];
	int cont_esp=0;
	Indice ind_esp[z] = {{1,0},{2,1},{3,2}};
	
	Cidade cidades[z];
	int cont_cidade=0;
	Indice ind_cidade[z] = {{1,0},{2,1},{3,2}};
	
	Medico medicos[z];
	int cont_medico=0;
	Indice ind_medico[z];
	Indice ind_medConsulta[z];
	
	Paciente pacientes[z];
	int cont_paciente=0;
	Indice ind_paciente[z];
	Indice ind_pacientesConsulta[z];
	
	CID cid[z];
	int cont_cid=0;
	Indice ind_cid[z]= {{1,0},{2,1},{3,2}};
	
	Medicamento medicamentos[z];
	int cont_medicamento=0;
	Indice ind_medicamento[z];
	
	Consulta consultas[z];
	int cont_consulta=0;
	Indice ind_consulta[z]={{1,0},{2,1},{3,2}};
	
	do{
		cout<<"  ________________________"<<endl;
		cout<<" |  MENU  PRINCIPAL 	  |" <<endl;
		cout<<" | 1 - Cidade		  |"<<endl;
		cout<<" | 2 - Especialidade	  |"<<endl;
		cout<<" | 3 - Medico		  |"<<endl;
		cout<<" | 4 - Paciente 	  |"<<endl;
		cout<<" | 5 - CID 		  |"<<endl;
		cout<<" | 6 - Medicamento	  |"<<endl;
		cout<<" | 7 - Consulta	  	  |"<<endl;
		cout<<" | 8 - Encerrar	  	  |"<<endl;
		cout<<" |________________________|"<<endl;
		cout<<"\n Digite uma opcao: ";
		cin>>menu_principal;
		system("cls");
		
		switch(menu_principal){
			case 1:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  CIDADE	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_cidade;
				
					switch(menu_cidade){
						case 1:{
							leitura_Cidade(cidades,cont_cidade);
							
							system("cls");
							break;
						}
						case 2:{
							mostrar_Cidade(cidades,cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(menu_cidade != 3);
				break;
			}
			
			case 2:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  ESPECIALIDADE	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_esp;
				
					switch(menu_esp){
						case 1:{
							leitura_Especialidade(esp,cont_esp);
							system("cls");
							break;
						}
						case 2:{
							mostrar_Especialidade(esp,cont_esp);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(menu_esp != 3);
				break;
			}
			case 3:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  MEDICO	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Excluir   	  |"<<endl;
					cout<<" | 4 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_medico;
				
					switch(menu_medico){
						case 1:{
							inclusao_Medico(medicos,esp,cidades,ind_medico,ind_esp,ind_cidade,cont_medico,cont_esp,cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 2:{
							mostrar_Medico(medicos,ind_medico,cont_medico);
							getch();
							system("cls");
							break;
						}
						case 3:{
							exclusao_Medico(medicos,ind_medico,cont_medico,ind_medConsulta,cont_consulta);
							getch();
							system("cls");
							break;
						}
						case 4:{
							system("cls");
							break;
						}
					}
				}while(menu_medico != 4);
				break;
			}
			
			case 4:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  PACIENTE	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Reorganizar   	  |"<<endl;
					cout<<" | 4 - Excluir   	  |"<<endl;
					cout<<" | 5 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_paciente;
				
					switch(menu_paciente){
						case 1:{
							inclusao_Paciente(pacientes,ind_paciente,cidades,ind_cidade,cont_paciente,cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 2:{
							mostrar_Paciente(pacientes,ind_paciente,cont_paciente);
							getch();
							system("cls");
							break;
						}
						case 3:{
							reorganizacao_paciente(ind_paciente,pacientes,cont_paciente);
							
							for(int i=0;i<cont_paciente;i++){
								cout<<"\nIndice atualizado: "<<endl;
								cout<<" Cod: "<< ind_paciente[i].cod<<endl;
								cout<<" Endereco: " << ind_paciente[i].endereco<<endl;
							}
							getch();
							system("cls");
							break;
						}
						case 4:{
							exclusao_Paciente(pacientes,ind_paciente,cont_paciente,ind_pacientesConsulta,cont_consulta);
							getch();
							system("cls");
							break;
						}
						case 5:{
							system("cls");
							break;
						}
					}
				}while(menu_paciente != 5);
				break;
			}
			
			case 5:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  	MENU  CID	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_cid;
				
					switch(menu_cid){
						case 1:{
							leitura_CID(cid,cont_cid);
							system("cls");
							break;
						}
						case 2:{
							mostrar_CID(cid,cont_cid);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(menu_cid != 3);
				break;
			}
			
			case 6:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU MEDICAMENTO 	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar    	  |"<<endl;
					cout<<" | 3 - Estoque Minimo     |"<<endl;
					cout<<" | 4 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_medicamento;
				
					switch(menu_medicamento){
						case 1:{
							leitura_Medicamento(medicamentos,cont_medicamento);
							system("cls");
							break;
						}
						case 2:{
							mostrar_Medicamento(medicamentos,ind_medicamento,cont_medicamento);
							getch();
							system("cls");
							break;
						}
						case 3:{
							estoque_minimo(medicamentos,cont_medicamento);
							getch();
							system("cls");
							break;
						}
						case 4:{
							system("cls");
							break;
						}
					}
				}while(menu_medicamento != 4);
				break;
			}
			
			case 7:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU CONSULTA 	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Valor Total   	  |"<<endl;
					cout<<" | 4 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_consulta;
				
					switch(menu_consulta){
						case 1:{      
							agendar_Consulta(consultas,ind_consulta,cont_consulta,pacientes,ind_paciente,ind_pacientesConsulta,cont_paciente,medicos,ind_medico,cont_medico,ind_medConsulta,cidades,ind_cidade,cont_cidade,cid,ind_cid,cont_cid,medicamentos,ind_medicamento,cont_medicamento,esp,ind_esp,cont_esp);
							getch();
							system("cls");
							break;
						}
						case 2:{
							mostrar_Consulta(consultas,ind_consulta,cont_consulta);
							getch();
							system("cls");
							break;
						}
						case 3:{
							valor_total(consultas,cont_consulta,medicamentos,ind_medicamento,cont_medicamento);
							getch();
							system("cls");
							break;
						}
						case 4:{
							system("cls");
							break;
						}
					}
				}while(menu_consulta != 4);
				break;
			}
			
            case 8:{
				cout<<"  _______________________"<<endl;
				cout<<" |  ENCERRAR O PROGRAMA  |" <<endl;
				cout<<" | 1 - Sim   		 |"<<endl;
				cout<<" | 2 - Nao	  	 |"<<endl;
				cout<<" |_______________________|"<<endl;
				cout<<"\n Digite uma opcao: ";
				cin>>menu_sair;
				
				switch(menu_sair){
					case 1:{
						system("cls");
						menu_principal=8;
						break;
					}
            		case 2:{
            			menu_principal=0;
						system("cls");
						break;
					}
				}
				break;
			}
			default:{
			cout<<" Opcao Invalida\n"<<endl;
        	getch();
        	system("cls");
			break;
			}
	
		}
	
	}while(menu_principal != 8);
}
