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
		printf("|          BANCO UCHÔA S.A.        |\n");  
		printf("|==================================|\n\n");	
		printf(" Você tem cadastro ? [1-S/2-N] \n\n opção: ");	
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
				// CASO O USUARIO DIGITAR MAIS 11 NÚMEROS CAIA NESSE LOP E SÓ SAI QUANDO DIGITAR  10 NUMEROS OU MENOS
				if(strlen(cpf)>11){	
					do{
						system("cls");
						printf(" Seu CPF é maior que 11 digitos.\n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)>11); 
				}
				// CASO O USUARIO DIGITAR MENOS 11 NÚMEROS CAIA NESSE LOP E SÓ SAI QUANDO DIGITAR 10 NUMEROS OU MAIS 
				else if(strlen(cpf)<11){
					do{
						system("cls");
						printf(" Seu CPF é menor que 11 digitos. \n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<11); 
				}
				else{
				}
				// CONDIÇÃO FEITA PARA QUE O USUÁRIO DIGITAR EXATAMENTE 11
			}while(strlen(cpf)<11||strlen(cpf)>11);
			printf(" Salário: ");
			scanf("%f",&salario);		
			printf(" Saldo Inicial:  ");
			scanf("%f",&saldoInicial);
			fflush(stdin);
			system("cls");
		}
		// SE DIGITAR 2 CAIA OPÇÃO CADASTRO
		else if(opCadastro==2){
			system("cls");
			printf("|==================================|\n");
			printf("|              CADASTRO            |\n");  
			printf("|==================================|\n\n");	
			printf(" Preencha o seguintes informações abaixo: \n\n");
			printf(" Nome: ");
			scanf("%s",&nome);
			fflush(stdin);
			printf(" Endereço: ");
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
				// MESMA LÓGICA QUE A DO CPF
				if(strlen(cpf)>11){	
					do{
						system("cls");
						printf(" Seu CPF é maior que 11 digitos.\n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)>11); 
				}
				//menor
				else if(strlen(cpf)<11){
					do{
						system("cls");
						printf(" Seu CPF é menor que 11 digitos. \n\n CPF: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<11); 
				}
				else{
				}
			}while((strlen(cpf)<11)||(strlen(cpf)>11));
			printf(" RG: ");
			scanf("%s",&rg);
			// MESMA LÓGICA QUE A DO CPF
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
						printf(" Seu RG é menor que 8 digitos.\n\n RG: ");
						scanf("%s",&cpf);
						fflush(stdin);
					}while(strlen(cpf)<8); 
				}
			}while((strlen(rg)<8) || (strlen(rg)>8));
			fflush(stdin);
			printf(" Salário: ");
			scanf("%f",&salario);
			// CONDIÇÃO FEITA PARA QUE O SALÁRIO NÃO SEJA MENOR OU IGUAL A 0  
			do{
				if(salario<=0){
					system("cls");
					printf(" Sálario não pode ser menor ou igual a 0 \n\n Digite o seu salário: ");
					scanf("%f",&salario);
				}
			}while(salario<=0);
			fflush(stdin);
			printf(" Saldo Inicial:  ");
			scanf("%f",&saldoInicial);	
			printf(" Tempo de serviço: ");
			scanf("%i",&tempoServico);
			system("cls");
			break;		
			} 
		else{
			system("cls");
			printf("|==================================|\n");
			printf("|      ERRRO, OPÇÃO INVALIDA       |\n");  
			printf("|==================================|\n");		
		}
	// O USUÁRIO FICA PRESO A OPÇÃO 1 E 2, E SE DIGITAR UMA LETRA ENTRA EM LOOPING
	}while(opCadastro!=1 && opCadastro!=2);
	do{
		fflush(stdin);
		printf(" |==================================|\n");
		printf(" |  BEM VINDO AO SISTEMA            |\n");  
		printf(" |==================================|\n");	
		printf(" |  ESCOLHA UMA OPCÃO ABAIXO:       |\n");  
		printf(" |==================================|\n");		
		printf("\n | *** MENU PRINCIPAL ***           |\n -----------------------------------|");
		printf("\n | (1) - CADASTRO - *** \n -----------------------------------|");
		printf("\n | (2) - DEPOSITO - *** \n -----------------------------------|");
		printf("\n | (3) - SACAR - *** \n -----------------------------------| ");
		printf("\n | (4) - CONSULTAR SALDO - *** \n -----------------------------------| ");
		printf("\n | (5) - TRANSFARÊNCIA - *** \n -----------------------------------| ");
		printf("\n | (6) - FINANCIAMENTO - *** \n -----------------------------------| ");
		printf("\n | (7) - SAIR - *** \n -----------------------------------| ");
		printf("\n\n DIGITE A OPCÃO: ");
		scanf("%i",&op);
		system("cls");	
		switch(op){
			case 1:
				//ELE NÃO VAI PREENCHER SÓ O QUE ELE ESCOLHER, E NÃO TEM PERGUNTAR PARA RETORNAR 
				system("cls");
				printf("|==================================|\n");
				printf("|            CADASTRO              |\n");  
				printf("|==================================|\n");
				printf("O que gostaria de editar ?  \n (1) Endereço \n (2) Cidade \n (3) Estado \n (4) Salário \n (5) Tempo de Serviço \n Opção: ");
				scanf("%i",&opReCadastro);
				switch(opReCadastro){
					case 1:
					system("cls");
					printf(" Endereço Atual: %s \n\n Insira um novo endereço: ",endereco);
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
					printf(" Salário atual: %s \n\n Insira uma novo salário: ",salario);
					scanf("%f",&salario);	
					salario=salario;
					system("cls");
					exit;
					fflush(stdin);
					break;
				case 5:
					system("cls");
					printf(" Tempo de serviço atual: %s \n\n Insira uma nova cidade: ",tempoServico);
					scanf("%s",&tempoServico);	
					tempoServico=tempoServico;
					system("cls");
					exit;
					fflush(stdin);
					break;
				default:
					system("cls");
					printf("Opção inválida");				
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
				printf("\n Você quer fazer outro deposito ? [1-S/2-N] \n Opção: ");
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
						// Pergunta feita para o usuário se ele quer fazer outro deposito, se digitar 1 faz mais deposito e se for 2 não faz outro deposito
						// e vai para pergunta que faz volta ao menu 
						printf("\n Você quer fazer outro deposito ? [1-S/2-N] \n Opção: ");
						scanf("%i",&condicaoDeposito);
						system("cls");		
					}
				printf(" ------------------------- \n");
				// Aqui é feita a pergunta para voltar ao menu	
				printf(" \n Obrigado \n ------------------------- \n Voltar ? \n\n [1-S/2-N] \n opção:");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 3:
				printf("|==================================|\n");
				printf("|             SACAR                |\n");  
				printf("|==================================|\n");
				// Se saldo for menor ou igual a 0 executa essa mensagem e não é tirado nada da conta
				if((saldoInicial<=0) || (saldoInicial==0)){
					printf(" Valor inválido para executar essa operação \n");
				}
			    //Se o valor sacado for maior que está no saldo da conta, aparece essa mensagem
				else if(valorSacar>saldoInicial){
					printf("Opção inválida - Saldo insulficiente");
				}
				// se valor que está na conta for maior que está na conta for maior 
				else if(saldoInicial>valorSacar){
					printf(" Seu saldo: %.2f \n ",saldoInicial);
					printf(" Valor a sacar: ");	
					scanf("%f",&valorSacar);
					saldoInicial-=valorSacar;	
					system("cls");
					printf(" ========================= \n\n OBRIGADO");
				}	
				else{
					printf(" OPERAÇÃO INVÁLIDA \n ");
				}
				// pergunta feita ao usuário para volta ao menu principal, mas se digitar 2 o programa é finalizado			
				printf("\n Voltar [1-S/2-N] \n\n opção: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 4:
				system("cls");
				printf("|==================================|\n");
				printf("|         CONSULTAR SALDO          |\n");  
				printf("|==================================|\n");
				// Aqui é só pode visualizar o saldo é mais nada 
				printf(" Seu saldo: %.2f \n",saldoInicial);
				// pergunta feita ao usuário para volta ao menu principal, mas se digitar 2 o programa é finalizado			
				printf("\n voltar ? [1-S/2-N] \n\n opção: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
				break;
			case 5:
				system("cls");
				printf("|==================================|\n");
				printf("|           TRANSIÇÕES             |\n");  
				printf("|==================================|\n");
				printf(" HISTÓRICO DE TRANSAÇÕES  \n ----------------------- \n");
				printf(" \n Nome: %s ",nomeTransferencia);
				printf(" \n  CPF: %s ",cpfTransferencia);
				printf(" \n Número: %s ",numeroTransferencia);
				printf(" \n Agência: %s ",agenciaTransferencia);
				printf(" \n Banco: %s ",bancoTransferencia);
				printf(" \n Tipo de conta: %s ",tipoDeConta);
				printf(" \n Valor transferido: %.2f ",valorTransferencia);
				printf("\n ----------------------- \n Nova transferência\n ");
				//Se saldo estiver maior pede as informações para um nova transação
				if(saldoInicial>0){
					printf(" Nome do destinatário: ");
					scanf("%s",&nomeTransferencia);
					printf(" CPF: ");
					scanf("%s",&cpfTransferencia);
					do{
					// MESMA LÓGICA QUE A DO CPF
					if(strlen(cpfTransferencia)>11){	
						do{
							system("cls");
							printf(" Seu CPF é maior que 11 digitos.\n\n CPF: ");
							scanf("%s",&cpfTransferencia);
							fflush(stdin);
						}while(strlen(cpfTransferencia)>11); 
					}
					//menor
					else if(strlen(cpfTransferencia)<11){
						do{
							system("cls");
							printf(" Seu CPF é menor que 11 digitos. \n\n CPF: ");
							scanf("%s",&cpfTransferencia);
							fflush(stdin);
						}while(strlen(cpfTransferencia)<11); 
					}
					else{
					}
					}while(strlen(cpfTransferencia)<11||strlen(cpfTransferencia)>11);
					printf(" Número: ");
					scanf("%s",&numeroTransferencia);
					printf(" Agência: ");
					scanf("%s",&agenciaTransferencia);
					printf(" Banco: ");
					scanf("%s",&bancoTransferencia);
					printf(" Tipo de Conta: ");
					scanf("%s",&tipoDeConta);
					printf(" Valor R$: ");
					scanf("%f",&valorTransferencia);
					// se saldo for menor que valor de transferência caia nessa opçao
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
					// Se o valor for menor é mostrado essa mensagem
					printf("IMPOSSÍVEL FAZER NENHUMA TRANSAÇÃO ");
				}
				printf("\n\n Seu saldo: %.2f \n",saldoInicial);
				printf("\n voltar ? [1-S/2-N] \n\n opção: ");
				scanf("%i",&op);
				system("cls");
				if(op==1){
					op=1;
				}
				else{
					printf("------------------------------- \n Até logo !");
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
				/* Aqui é um usado um array e um laço para fazer o fazer o que tamanho do array seja 
				 * do tamanho de membros de pessoas que o usuário digitar.  
				*/
				for(index=1;index<=membrosFinancimento;index++){
					printf(" Salário da pessoa %iº -  valor: ",index);
					scanf("%f",&salarioFinancimento[index]);
					totalSalarioFinaciamento+=salarioFinancimento[index];
				}
				system("cls");
				printf("|==================================|\n");
				printf("|          FINANCIAMENTO           |\n");  
				printf("|==================================|\n");	
				printf("total: %.2f",totalSalarioFinaciamento);
				do{
					printf("\n\n (1) - Financiamento de imóveis \n (2) - Financiamento de autómovel \n\n Opção: ");
					scanf("%i",&opcaoFinanciamento);
					// se for digitado 1 
					if(opcaoFinanciamento==1){
						printf(" Valor financiado: ");
						scanf("%f",&valorFinanciado);
						printf(" Valor de entrada: ");
						scanf("%f",&ValorEntrada);
						printf(" Juros: ");
						scanf("%f",&jurosAoAno);
						// Tranformando o número com casas decimais divido por 100
						valorDoJuros=jurosAoAno/100;
						printf("Tempo de financiamento: ");
						scanf("%f",&tempoFinanciamento);
						//valor total 
						valorTotalFinanciamento=valorFinanciado+(valorFinanciado-ValorEntrada)*valorDoJuros;
						valorDaParcelaFinanciamento=valorTotalFinanciamento/tempoFinanciamento; 
						// obtendo 40% do valor total do financiamento
						limiteFinanciamento=(totalSalarioFinaciamento*40)/100;
						// tempo de serviço maior ou igual 3 e valor total do financimento for menor que 40% dele é aprovado
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
						printf("Tempo de financiamento(número de mêses): ");
						scanf("%f",&tempoFinanciamento);
						valorTotalFinanciamento=valorFinanciado+(valorFinanciado-ValorEntrada)*valorDoJuros;
						valorDaParcelaFinanciamento=valorTotalFinanciamento/tempoFinanciamento; 
						limiteFinanciamento=totalSalarioFinaciamento*40/100;
						if(tempoServico==0){
							printf("\n \n Seu tempo de serviço está 0");
							printf("\n voltar ? [1-S/2-N] \n\n opção: ");
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
						printf("Opção inválida");
						system("cls");						
					}
					// o usuário fica preso as opções 1 ou 2 
				}while(opcaoFinanciamento!=1 && opcaoFinanciamento!=2);
				// pergunta para voltar ao menu
				printf("\n voltar ? [1-S/2-N] \n\n opção: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
			break;
			case 7:
				// se digitado 7 o programa é encerrado
				printf("|==================================|\n");
				printf("|   BANCO FECHADO - VOLTE SEMPRE   |\n");  
				printf("|==================================|\n");
				op=0;
			break;
			default:
				// se digitar um opção não encontrada no menu caia nessa opção
				printf("|==================================|\n");
				printf("|          OPÇÃO INVÁLIDA          |\n");  
				printf("|==================================|\n");			
				// pergunta para voltar ao menu
				printf("\n voltar ? [1-S/2-N] \n\n opção: ");
				scanf("%i",&op);
				system("cls");
				fflush(stdin);
		}
	//varivel que recebe a resposta da pergunta para voltar ao menu	
	}while(op==1);
	return 0;
}
