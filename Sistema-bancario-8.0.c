#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main(){
	setlocale(LC_ALL, "Portuguese");
	const char cpf[11],senhaCpf[11];
	int op, tempoServico, opCadastro,chancesSenha, opReCadastro, opDeposito,condicaoDeposito;
	int membrosFinancimento, indexFinanciamento, index, opcaoFinanciamento;
	char nome[20],endereco, cidade,estado,anoNascimento, rg[9], cpfTransferencia[11]=" ", bancoTransferencia[6]=" ";
	char agenciaTransferencia[4]=" ",numeroTransferencia[3]=" ", tipoDeConta[10]=" ",nomeTransferencia[10]="";
	float salario=0, deposito, valorSacar, valorTransferencia,salarioFinancimento[4],totalSalarioFinaciamento,valorFinanciado,ValorEntrada;
	float jurosAoAno,valorDoJuros,valorTotalFinanciamento,valorDaParcelaFinanciamento,tempoFinanciamento,limiteFinanciamento,saldoInicial=0;	
	do{
		printf("|==================================|\n");
		printf("|          BANCO UCH�A S.A.        |\n");  
		printf("|==================================|\n\n");	
		printf(" Voc� tem cadastro ? [1-S/2-N] \n\n op��o: ");	
		scanf("%i",&opCadastro);
		// CASO USUARIO DIGITAR 1 ELE RESPONDE A TELA DE LOGIN 
		if(opCadastro==1){
			system("cls");
			printf("|==================================|\n");
			printf("|              LOGIN               |\n");  
			printf("|==================================|\n\n");	
			printf(" Nome: ");
			scanf("%s",&nome);
			fflush(stdin);
			printf(" CPF: ");
			scanf("%s",&cpf);
			do{
				// CASO O USUARIO DIGITAR MAIS 11 N�MEROS CAIA NESSE LOP E S� SAI QUANDO DIGITAR  10 NUMEROS OU MENOS
				if(strlen(cpf)>11){	
					do{
						system("cls");
						printf(" Seu CPF � maior que 11 digitos.\n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)>11); 
				}
				// CASO O USUARIO DIGITAR MENOS 11 N�MEROS CAIA NESSE LOP E S� SAI QUANDO DIGITAR 10 NUMEROS OU MAIS 
				else if(strlen(cpf)<11){
					do{
						system("cls");
						printf(" Seu CPF � menor que 11 digitos. \n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<11); 
				}
				else{
				}
				// CONDI��O FEITA PARA QUE O USU�RIO DIGITAR EXATAMENTE 11
			}while(strlen(cpf)<11||strlen(cpf)>11);
			printf(" Sal�rio: ");
			scanf("%f",&salario);		
			printf(" Saldo Inicial:  ");
			scanf("%f",&saldoInicial);
			fflush(stdin);
			system("cls");
		}
		// SE DIGITAR 2 CAIA OP��O CADASTRO
		else if(opCadastro==2){
			system("cls");
			printf("|==================================|\n");
			printf("|              CADASTRO            |\n");  
			printf("|==================================|\n\n");	
			printf(" Preencha o seguintes informa��es abaixo: \n\n");
			printf(" Nome: ");
			scanf("%s",&nome);
			fflush(stdin);
			printf(" Endere�o: ");
			scanf("%s",&endereco);
			fflush(stdin);
			printf(" Cidade: ");
			scanf("%s",&cidade);
			fflush(stdin);
			printf(" Estado: ");
			scanf("%s",&estado);
			fflush(stdin);
			printf(" Ano de nascimento: ");
			scanf("%s",&anoNascimento);
			fflush(stdin);
			printf(" CPF: ");
			scanf("%s",&cpf);
			do{
				// MESMA L�GICA QUE A DO CPF
				if(strlen(cpf)>11){	
					do{
						system("cls");
						printf(" Seu CPF � maior que 11 digitos.\n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)>11); 
				}
				//menor
				else if(strlen(cpf)<11){
					do{
						system("cls");
						printf(" Seu CPF � menor que 11 digitos. \n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<11); 
				}
				else{
				}
			}while((strlen(cpf)<11)||(strlen(cpf)>11));
			printf(" RG: ");
			scanf("%s",&rg);
			// MESMA L�GICA QUE A DO CPF
			do{
				if(strlen(rg)>8){
					do{
						system("cls");
						printf(" Seu RG maior que 8 digitos.\n\n RG: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)>8); 
				}
				if(strlen(cpf)<8){
					do{
						system("cls");
						printf(" Seu RG � menor que 8 digitos.\n\n RG: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<8); 
				}
			}while((strlen(rg)<8) || (strlen(rg)>8));
			fflush(stdin);
			printf(" Sal�rio: ");
			scanf("%f",&salario);
			// CONDI��O FEITA PARA QUE O SAL�RIO N�O SEJA MENOR OU IGUAL A 0  
			do{
				if(salario<=0){
					system("cls");
					printf(" S�lario n�o pode ser menor ou igual a 0 \n\n Digite o seu sal�rio: ");
					scanf("%f",&salario);
				}
			}while(salario<=0);
			fflush(stdin);
			printf(" Saldo Inicial:  ");
			scanf("%f",&saldoInicial);	
			printf(" Tempo de servi�o: ");
			scanf("%i",&tempoServico);
			system("cls");
			break;		
			} 
		else{
			system("cls");
			printf("|==================================|\n");
			printf("|      ERRRO, OP��O INVALIDA       |\n");  
			printf("|==================================|\n");		
		}
	// O USU�RIO FICA PRESO A OP��O 1 E 2, E SE DIGITAR UMA LETRA ENTRA EM LOOPING
	}while(opCadastro!=1 && opCadastro!=2);
	do{
		fflush(stdin);
		printf(" |==================================|\n");
		printf(" |  BEM VINDO AO SISTEMA            |\n");  
		printf(" |==================================|\n");	
		printf(" |  ESCOLHA UMA OPC�O ABAIXO:       |\n");  
		printf(" |==================================|\n");		
		printf("\n | *** MENU PRINCIPAL ***           |\n -----------------------------------|");
		printf("\n | (1) - CADASTRO - *** \n -----------------------------------|");
		printf("\n | (2) - DEPOSITO - *** \n -----------------------------------|");
		printf("\n | (3) - SACAR - *** \n -----------------------------------| ");
		printf("\n | (4) - CONSULTAR SALDO - *** \n -----------------------------------| ");
		printf("\n | (5) - TRANSFAR�NCIA - *** \n -----------------------------------| ");
		printf("\n | (6) - FINANCIAMENTO - *** \n -----------------------------------| ");
		printf("\n | (7) - SAIR - *** \n -----------------------------------| ");
		printf("\n\n DIGITE A OPC�O: ");
		scanf("%i",&op);
		system("cls");	
		switch(op){
			case 1:
				//ELE N�O VAI PREENCHER S� O QUE ELE ESCOLHER, E N�O TEM PERGUNTAR PARA RETORNAR 
				system("cls");
				printf("|==================================|\n");
				printf("|            CADASTRO              |\n");  
				printf("|==================================|\n");
				printf("O que gostaria de editar ?  \n (1) Endere�o \n (2) Cidade \n (3) Estado \n (4) Sal�rio \n (5) Tempo de Servi�o \n Op��o: ");
				scanf("%i",&opReCadastro);
				switch(opReCadastro){
					case 1:
					system("cls");
					printf(" Endere�o Atual: %s \n\n Insira um novo endere�o: ",endereco);
					scanf("%s",&endereco);	
					endereco=endereco;
					system("cls");
					exit;
					fflush(stdin);
					break;
				case 2:
					system("cls");
					printf(" Cidade atual: %s \n\n Insira uma nova cidade: ",cidade);
					scanf("%s",&cidade);	
					system("cls");
					exit;
					cidade=cidade;
					fflush(stdin);	
					break;
				case 3:
					system("cls");
					printf(" Estado atual: %s \n\n Insira um novo estado: ",estado);
					scanf("%s",&estado);	
					estado=estado;
					system("cls");
					exit;
					fflush(stdin);	
					break;
				case 4:
					system("cls");
					printf(" Sal�rio atual: %s \n\n Insira uma novo sal�rio: ",salario);
					scanf("%f",&salario);	
					salario=salario;
					system("cls");
					exit;
					fflush(stdin);
					break;
				case 5:
					system("cls");
					printf(" Tempo de servi�o atual: %s \n\n Insira uma nova cidade: ",tempoServico);
					scanf("%s",&tempoServico);	
					tempoServico=tempoServico;
					system("cls");
					exit;
					fflush(stdin);
					break;
				default:
					system("cls");
					printf("Op��o inv�lida");				
					system("cls");
					exit;	
					fflush(stdin);
					break;
				}
				break;
			case 2:
				//Pronto
				system("cls");
				printf("|==================================|\n");
				printf("|          DEPOSITO                |\n");  
				printf("|==================================|\n");
				printf(" Saldo %.2f \n\n",saldoInicial);
				printf(" Valor a depositar: ");
				scanf("%f",&deposito);
				saldoInicial+=deposito;
				system("cls");
				printf("\n Voc� quer fazer outro deposito ? [1-S/2-N] \n Op��o: ");
				scanf("%i",&condicaoDeposito);
					// Aqui ele pergunta se ele quer fazer mais um deposito, se digitar 1 ele faz o deposito, se for 2 ele sai do loop 
					while(condicaoDeposito==1){
						if(condicaoDeposito==1){
							system("cls");
							printf(" Saldo %.2f \n\n",salario);
							printf(" Valor a depositar: ");
							scanf("%f",&deposito);
							salario+=deposito;
							system("cls");
						}
						else{
							system("cls");
							break;
						}
						// Pergunta feita para o usu�rio se ele quer fazer outro deposito, se digitar 1 faz mais deposito e se for 2 n�o faz outro deposito
						// e vai para pergunta que faz volta ao menu 
						printf("\n Voc� quer fazer outro deposito ? [1-S/2-N] \n Op��o: ");
						scanf("%i",&condicaoDeposito);
						system("cls");		
					}
				printf(" ------------------------- \n");
				// Aqui � feita a pergunta para voltar ao menu	
				printf(" \n Obrigado \n ------------------------- \n Voltar ? \n\n [1-S/2-N] \n op��o:");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 3:
				printf("|==================================|\n");
				printf("|             SACAR                |\n");  
				printf("|==================================|\n");
				// Se saldo for menor ou igual a 0 executa essa mensagem e n�o � tirado nada da conta
				if((saldoInicial<=0) || (saldoInicial==0)){
					printf(" Valor inv�lido para executar essa opera��o \n");
				}
			    //Se o valor sacado for maior que est� no saldo da conta, aparece essa mensagem
				else if(valorSacar>saldoInicial){
					printf("Op��o inv�lida - Saldo insulficiente");
				}
				// se valor que est� na conta for maior que est� na conta for maior 
				else if(saldoInicial>valorSacar){
					printf(" Seu saldo: %.2f \n ",saldoInicial);
					printf(" Valor a sacar: ");	
					scanf("%f",&valorSacar);
					saldoInicial-=valorSacar;	
					system("cls");
					printf(" ========================= \n\n OBRIGADO");
				}	
				else{
					printf(" OPERA��O INV�LIDA \n ");
				}
				// pergunta feita ao usu�rio para volta ao menu principal, mas se digitar 2 o programa � finalizado			
				printf("\n Voltar [1-S/2-N] \n\n op��o: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 4:
				system("cls");
				printf("|==================================|\n");
				printf("|         CONSULTAR SALDO          |\n");  
				printf("|==================================|\n");
				// Aqui � s� pode visualizar o saldo � mais nada 
				printf(" Seu saldo: %.2f \n",saldoInicial);
				// pergunta feita ao usu�rio para volta ao menu principal, mas se digitar 2 o programa � finalizado			
				printf("\n voltar ? [1-S/2-N] \n\n op��o: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 5:
				system("cls");
				printf("|==================================|\n");
				printf("|           TRANSI��ES             |\n");  
				printf("|==================================|\n");
				printf(" HIST�RICO DE TRANSA��ES  \n ----------------------- \n");
				printf(" \n Nome: %s ",nomeTransferencia);
				printf(" \n  CPF: %s ",cpfTransferencia);
				printf(" \n N�mero: %s ",numeroTransferencia);
				printf(" \n Ag�ncia: %s ",agenciaTransferencia);
				printf(" \n Banco: %s ",bancoTransferencia);
				printf(" \n Tipo de conta: %s ",tipoDeConta);
				printf(" \n Valor transferido: %.2f ",valorTransferencia);
				printf("\n ----------------------- \n Nova transfer�ncia\n ");
				//Se saldo estiver maior pede as informa��es para um nova transa��o
				if(saldoInicial>0){
					printf(" Nome do destinat�rio: ");
					scanf("%s",&nomeTransferencia);
					printf(" CPF: ");
					scanf("%s",&cpfTransferencia);
					do{
					// MESMA L�GICA QUE A DO CPF
					if(strlen(cpfTransferencia)>11){	
						do{
							system("cls");
							printf(" Seu CPF � maior que 11 digitos.\n\n CPF: ");
							scanf("%s",&cpfTransferencia);
							fflush(stdin);
						}while(strlen(cpfTransferencia)>11); 
					}
					//menor
					else if(strlen(cpfTransferencia)<11){
						do{
							system("cls");
							printf(" Seu CPF � menor que 11 digitos. \n\n CPF: ");
							scanf("%s",&cpfTransferencia);
							fflush(stdin);
						}while(strlen(cpfTransferencia)<11); 
					}
					else{
					}
					}while(strlen(cpfTransferencia)<11||strlen(cpfTransferencia)>11);
					printf(" N�mero: ");
					scanf("%s",&numeroTransferencia);
					printf(" Ag�ncia: ");
					scanf("%s",&agenciaTransferencia);
					printf(" Banco: ");
					scanf("%s",&bancoTransferencia);
					printf(" Tipo de Conta: ");
					scanf("%s",&tipoDeConta);
					printf(" Valor R$: ");
					scanf("%f",&valorTransferencia);
					// se saldo for menor que valor de transfer�ncia caia nessa op�ao
					if(saldoInicial<valorTransferencia){
						printf("\n VALOR INSUFICIENTE NA CONTA");
					}
					if(saldoInicial>=valorTransferencia){
						saldoInicial=saldoInicial-valorTransferencia;
						system("cls");
						printf("----------------------- \n Obrigado\n ----------------------- \n");
					}
				}
				else{
					// Se o valor for menor � mostrado essa mensagem
					printf("IMPOSS�VEL FAZER NENHUMA TRANSA��O ");
				}
				printf("\n\n Seu saldo: %.2f \n",saldoInicial);
				printf("\n voltar ? [1-S/2-N] \n\n op��o: ");
				scanf("%i",&op);
				system("cls");
				if(op==1){
					op=1;
				}
				else{
					printf("------------------------------- \n At� logo !");
				}
				fflush(stdin);
			break;
			case 6:
				system("cls");
				printf("|==================================|\n");
				printf("|          FINANCIAMENTO           |\n");  
				printf("|==================================|\n");	
				printf(" Quantidade de membros na sua casa: ");
				scanf("%i",&membrosFinancimento);
				/* Aqui � um usado um array e um la�o para fazer o fazer o que tamanho do array seja 
				 * do tamanho de membros de pessoas que o usu�rio digitar.  
				*/
				for(index=1;index<=membrosFinancimento;index++){
					printf(" Sal�rio da pessoa %i� -  valor: ",index);
					scanf("%f",&salarioFinancimento[index]);
					totalSalarioFinaciamento+=salarioFinancimento[index];
				}
				system("cls");
				printf("|==================================|\n");
				printf("|          FINANCIAMENTO           |\n");  
				printf("|==================================|\n");	
				printf("total: %.2f",totalSalarioFinaciamento);
				do{
					printf("\n\n (1) - Financiamento de im�veis \n (2) - Financiamento de aut�movel \n\n Op��o: ");
					scanf("%i",&opcaoFinanciamento);
					// se for digitado 1 
					if(opcaoFinanciamento==1){
						printf(" Valor financiado: ");
						scanf("%f",&valorFinanciado);
						printf(" Valor de entrada: ");
						scanf("%f",&ValorEntrada);
						printf(" Juros: ");
						scanf("%f",&jurosAoAno);
						// Tranformando o n�mero com casas decimais divido por 100
						valorDoJuros=jurosAoAno/100;
						printf("Tempo de financiamento: ");
						scanf("%f",&tempoFinanciamento);
						//valor total 
						valorTotalFinanciamento=valorFinanciado+(valorFinanciado-ValorEntrada)*valorDoJuros;
						valorDaParcelaFinanciamento=valorTotalFinanciamento/tempoFinanciamento; 
						// obtendo 40% do valor total do financiamento
						limiteFinanciamento=(totalSalarioFinaciamento*40)/100;
						// tempo de servi�o maior ou igual 3 e valor total do financimento for menor que 40% dele � aprovado
						if(tempoServico>=3 || valorTotalFinanciamento<=limiteFinanciamento){
							printf("\n\n Emprestimo APROVADO! \n");
							printf(" Valor total : %.2f \n",valorTotalFinanciamento);
							printf(" Valor de cada parcela : %.2f \n",valorDaParcelaFinanciamento);
							printf("\n Juros: %.2f",valorDoJuros);
						}
						else{
							// emprestimo for negado
							printf("\n\n Emprestimo REPROVADO! \n ");
							printf("Valor total : %.2f \n",valorTotalFinanciamento);
							printf(" Valor de cada parcela : %.2f \n",valorDaParcelaFinanciamento);
							printf("\n Juros: %.2f",valorDoJuros);
						}
					}
					// se for digitado 2
					else if(opcaoFinanciamento==2){
						printf("Valor financiado: ");
						scanf("%f",&valorFinanciado);
						printf("Valor de entrada: ");
						scanf("%f",&ValorEntrada);
						printf("Juros: ");
						scanf("%f",&jurosAoAno);
						valorDoJuros=(jurosAoAno/100);
						printf("Tempo de financiamento(n�mero de m�ses): ");
						scanf("%f",&tempoFinanciamento);
						valorTotalFinanciamento=valorFinanciado+(valorFinanciado-ValorEntrada)*valorDoJuros;
						valorDaParcelaFinanciamento=valorTotalFinanciamento/tempoFinanciamento; 
						limiteFinanciamento=totalSalarioFinaciamento*40/100;
						if(tempoServico==0){
							printf("\n \n Seu tempo de servi�o est� 0");
							printf("\n voltar ? [1-S/2-N] \n\n op��o: ");
							scanf("%i",&op);
							system("cls");
							break;
						}
						if(tempoServico>=3 || valorTotalFinanciamento<limiteFinanciamento){
							printf("\n\n Emprestimo APROVADO! ");
							printf("\n Valor total : %.2f \n",valorTotalFinanciamento);
							printf("\n Valor de cada parcela : %.2f \n",valorDaParcelaFinanciamento);
							printf("\n Juros: %.2f",valorDoJuros);
						}
						else if(tempoServico<3 || valorTotalFinanciamento>limiteFinanciamento){
							printf("\n\n Emprestimo REPROVADO! ");
							printf("\n Valor total : %.2f \n",valorTotalFinanciamento);
							printf("\n Valor de cada parcela : %.2f \n",valorDaParcelaFinanciamento);
							printf("\n Juros: %.2f",valorDoJuros);
						}
					}
					else{
						printf("Op��o inv�lida");
						system("cls");						
					}
					// o usu�rio fica preso as op��es 1 ou 2 
				}while(opcaoFinanciamento!=1 && opcaoFinanciamento!=2);
				// pergunta para voltar ao menu
				printf("\n voltar ? [1-S/2-N] \n\n op��o: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
			break;
			case 7:
				// se digitado 7 o programa � encerrado
				printf("|==================================|\n");
				printf("|   BANCO FECHADO - VOLTE SEMPRE   |\n");  
				printf("|==================================|\n");
				op=0;
			break;
			default:
				// se digitar um op��o n�o encontrada no menu caia nessa op��o
				printf("|==================================|\n");
				printf("|          OP��O INV�LIDA          |\n");  
				printf("|==================================|\n");			
				// pergunta para voltar ao menu
				printf("\n voltar ? [1-S/2-N] \n\n op��o: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
		}
	//varivel que recebe a resposta da pergunta para voltar ao menu	
	}while(op==1);
	return 0;
}
