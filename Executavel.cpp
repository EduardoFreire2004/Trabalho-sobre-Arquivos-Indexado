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

void mostrar_Medico(struct Medico medico[],int cont){
	
	for(int i=0;i<cont;i++){
		cout << "\nCodigo do Medico: " << medico[i].cod;
        cout << "\tNome: " << medico[i].nome;
        cout << "\tEspecialidade: " << medico[i].cod_especialidade;
		cout << "\tEndereco: " << medico[i].endereco;
		cout << "\tTelefone: " << medico[i].telefone;
        cout << "\tCidade: " << medico[i].cod_cidade;
	}
	
	
}

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



void inclusao_Medico(struct Medico medicos[],struct Especialidade_Medica esp[],struct Cidade cidade[],struct Indice ind[],struct Indice ind_esp[],struct Indice ind_cidade[],int &cont,int cont_esp,int cont_cidade){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<"Incluir um novo Medico "<< endl;
		cout<<"Cod: ";
		cin>>medicos[cont].cod;
		cin.ignore();
		if(busca(ind,cont,medicos[cont].cod) == -1){
			cod=medicos[cont].cod;
			cout<<"Nome: ";
			getline(cin,medicos[cont].nome);
			cout<<"Codigo da Especialidade: ";
			cin>> medicos[cont].cod_especialidade;
			cin.ignore();
			int result = busca(ind_esp,cont_esp,medicos[cont].cod_especialidade);
			cout<<"Descricao: "<< esp[result].descricao <<endl;
			cout <<"Endereco : ";
			getline(cin,medicos[cont].endereco);
			cout<<"Codigo da Cidade: ";
			cin>>medicos[cont].cod_cidade;
			cin.ignore();
			result = busca(ind_cidade,cont_cidade,medicos[cont].cod_cidade);
			cout<<"Cidade: " << cidade[result].nome<< " | " << cidade[result].uf <<endl;
			cout<<"Telefone: ";
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

void inclusao_Paciente(struct Paciente pacientes[],struct Indice ind[],struct Cidade cidade[],struct Indice ind_cidade[],int &cont,int cont_cidade){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<"Incluir um novo Paciente "<< endl;
		cout<<"Cod: ";
		cin>>pacientes[cont].cod;
		cin.ignore();
		if(busca(ind,cont,pacientes[cont].cod) == -1){
			cod=pacientes[cont].cod;
			cout<<"Nome: ";
			getline(cin,pacientes[cont].nome);
			cout <<"Endereco : ";
			getline(cin,pacientes[cont].endereco);
			cout<<"Codigo da Cidade: ";
			cin>>pacientes[cont].cod_cidade;
			cin.ignore();
			int result = busca(ind_cidade,cont_cidade,pacientes[cont].cod_cidade);
			cout<<"Cidade: " << cidade[result].nome<< " | " << cidade[result].uf <<endl;
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

void mostrar_Paciente(struct Paciente pacientes[],struct Indice ind[],int cont){
	
	for(int i=0;i<cont;i++){
		int k= ind[i].endereco;
		if(pacientes[k].status == 0){
			cout << "\nCodigo do Paciente: " << pacientes[i].cod;
	        cout << "\tNome: " << pacientes[i].nome;
			cout << "\tEndereco: " << pacientes[i].endereco;
	        cout << "\tCidade: " << pacientes[i].cod_cidade;
        }

	}
}

void exclusao_Paciente(struct Paciente pacientes[],struct Indice ind[],int cont){
	int ex;
	for(int x=1;x != -1;){
		cout<<" Digite o codigo da exclusao do Paciente ";
		cin>>ex;
		int result = busca(ind,cont,ex);
		if(result != -1){
			if(pacientes[result].status != 1){
				
				cout << "\nCodigo do Paciente: " << pacientes[result].cod;
		        cout << "\nNome: " << pacientes[result].nome;
				cout << "\tEndereco: " << pacientes[result].endereco;
		        cout << "\tCidade: " << pacientes[result].cod_cidade;
		        pacientes[result].status = 1;
		        cout<<"\n\n ### Paciente Ecluido com Sucesso ### \n" <<endl;
		        x=-1;
			}
			else{
				cout<<"\n ### Paciente ja Excluido ### \n" <<endl;
			}
		}
		else{
			cout<<"\n ### Codigo nao existente ### \n" <<endl;
		}
	}	
}

int main(){

	int menu_principal=0;
	int menu_cidade=0;
	int menu_esp=0;
	int menu_medico=0;
	int menu_paciente=0;
	int menu_sair=0;
	
	Especialidade_Medica esp[z];
	int cont_esp=0;
	Indice ind_esp[z] = {{1,0},{2,1},{3,2}};
	
	Cidade cidades[z];
	int cont_cidade=0;
	Indice ind_cidade[z] = {{1,0},{2,1},{3,2}};
	
	Medico medicos[z];
	int cont_medico=0;
	Indice ind_medico[z]= {{1,0},{2,1},{3,2}};
	
	Paciente pacientes[z];
	int cont_paciente=0;
	Indice ind_paciente[z]= {{1,0},{2,1},{3,2}};
	
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
					cout<<" | 3 - Voltar		  |"<<endl;
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
							mostrar_Medico(medicos,cont_medico);
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
			
			case 4:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  PACIENTE	  |" <<endl;
					cout<<" | 1 - Cadastrar   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Excluir   	  |"<<endl;
					cout<<" | 4 - Voltar		  |"<<endl;
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
							exclusao_Paciente(pacientes,ind_paciente,cont_paciente);
							getch();
							system("cls");
							break;
						}
						
						case 4:{
							system("cls");
							break;
						}
					}
				}while(menu_paciente != 4);
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
