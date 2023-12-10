/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 94 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Vítor Augusto Casemiro Dos Santos>                  <11911261>          **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>

/*
  Funcao somaDigitos(int valor): esta funcao devera receber um numero 
    inteiro como parametro (valor}). Se este numero for menor ou igual
    a zero ou maior que 99999, a funcao devera retornar o valor -1.
  Caso contrario, a funcao devera somar os digitos do numero de acordo com suas
    unidades, dezenas, centenas, milhares e dezenas de milhares e retornar esta
    soma.
  Por exemplo, para o numero 2345, deve retornar 14 que corresponde a:
    2 + 3 + 4 + 5.
	
  Parametro:
    valor - Valor inteiro a ter seus digitos somados
*/
int somaDigitos(int valor){
	int soma = 0;

  if (valor<=0 || valor > 99999){
    
    return -1;
    // if para nao executar valores que a função nao pode executar, e retornar -1
  } 
  else{
   while (valor > 0) { 
        soma += valor % 10; // soma o último dígito do número, usando o resto da divisao inteira
        valor /= 10; // remove o último dígito do número dividindo por 10
    }
    


	

	return soma; // retorna a soma correta de todos os digitos
  }
}


/*
  Funcao somaIntervalo(int inicio, int fim): esta funcao devera receber dois 
    numeros inteiro (inicio e fim).
  Se qualquer desses numeros for negativo ou nulo a funcao devera retornar -1;
  Se o valor de fim for menor do que o valor de inicio, a funcao tambem devera
    retornar -1.
  Caso contrario, a funcao devera retornar a soma de todos os numeros inteiros
    de inicio ate fim. Por exemplo, para inicio=3 e fim=4, a funcao devera
    retornar 7, valor obtido pela soma dos seguintes valores: 3 + 4.
  Ja para inicio=3 e fim=6, a funcao devera retornar 18, valor obtido pela
    soma dos seguintes valores: 3 + 4 + 5 + 6.

  Parametros:
    inicio - Valor inteiro que representa o inicio do intervalo
    fim - Valor inteiro que representa o fim do intervalo
*/
int somaIntervalo(int inicio, int fim){
  
  if(inicio<=0 || fim<=0){
    
    return -1;        // inicio e fim igual a ou menor que 0 não podem ser usados na função
  }
  if(fim<inicio){

    return -1;    // fim nao pode ser menor que inicio nesta função
  }
	
  int resultado = 0;

  for (inicio; inicio <= fim; inicio++) { // realiza o laço ate o valor inicial chegar ao fim
      
    resultado += inicio; // soma o valor de inicio ao resultado e para quando inicio chega ao fim
    
  }






  return resultado; //  retorna o resultado correto do intervalo
}
   


/*
  Funcao somaInteiros(int inicio, int limite): esta funcao devera receber
    dois numeros inteiro (inicio e limite).
  Se qualquer desses numeros for negativo ou nulo a funcao devera retornar -1;
  Se o valor de limite for menor do que o valor de inicio, a funcao tambem 
    devera retornar -1.
  Caso contrario, a funcao devera retornar o maior valor da soma dos inteiros
    consecutivos a partir de inicio, desde que esse valor seja menor ou igual
    ao valor de limite.
  Por exemplo, para inicio=3 e limite=5, a funcao devera retornar 3, valor 
    obtido apenas pelo numero inicial: 3 (pois se somarmos 3 e 4 a soma sera 7
    que e maior do que o limite).
  Ja para inicio=4 e limite=17, a funcao devera retornar 15, valor obtido pela
    soma dos seguintes valores: 4 + 5 + 6 (se, adicionalmente, somarmos 7, 
    o valor ultrapassaria o valor de limite).
	
  Parametros:
    inicio - Primeiro valor a participar da soma
    limite - Valor limitante para a soma dos inteiros (a soma devera ser menor
             ou igual a este valor)
*/
int somaInteiros(int inicio, int limite){
	int soma = 0;

  if(inicio<=0 || limite<=0){ // elimina os zeros e nulos no inicio e lim
    return -1;
  }
  if(limite<inicio){ //limite nao pode ser menor que o inicio
    return -1;
  }
     int somador = inicio; /* variavel para controlar a outra variavel inicio, e realizar a soma*/
     
      while (soma + somador  <= limite) {
        soma += somador;
        somador++;// somador adiciona o numero atual ao proximo inteiro
    }
  // o laço realiza a soma dos inteiros até estes chegarem ao limite, parando o loop
 
   
    return soma;// e retorna a soma do numero respeitando o limite dado
    }

	



/*
  Funcao dividindoPorDois(double valor, int divisoes): esta funcao devera
    receber um numero real (valor) e um numero inteiro (divisoes).
  Se o valor de divisoes for nulo ou negativo, a funcao devera retornar -1.
  Caso contrario, a funcao devera retornar o resultado de valor/2^divisoes
    (isto e, valor dividido por dois elevado a divisoes).
  Este resultado devera ser obtido a partir de sucessivas divisoes.
  Por exemplo, para valor=8 e divisoes=4, a funcao devera retornar 0.5,
    valor obtido pela seguinte conta: 8/2/2/2/2.
	
  Parametros:
    valor - Dividendo inicial da divisao (valor que sera dividido sucessivas
            vezes por 2)
    divisoes - Numero de vezes que a variavel valor sera dividida por 2

*/
double dividindoPorDois(double valor, int divisoes){
	double resultado = 0;
  int i; // variavel para o controle no laço a seguir
  
  if(divisoes<=0){
    return -1; // divisoes nao pode ser nem nulo nem negativo
    }
    else{
    resultado=valor;// coloca o resultado igual o valor para dividirmos depois
    
      for(i=0;i<divisoes;i++){
          resultado/=2;
        // o laço dividiu por 2 ate o numero de divisoes estabelecido, finalizando quando chega neste numero
      }
      }
	 return resultado;// retorna corretamente o numero dividido por 2 vezes divisoes
}


/*
  Funcao valorDePI(double limiar): Existem diversas funcoes computacionais
    para calcular valores aproximados de diferentes constantes ou funcoes.
  A funcao a seguir computa uma aproximacao para o valor de pi.
  Esta funcao recebe o numero de iteracoes e calcula o valor de pi de acordo
    com este numero (quanto maior o numero, melhor sera a aproximacao).

  void calculoDoValorDePI(int iteracoes){
    double meuPI = 4; // valor inicial de pi ("primeira iteracao")
    int sinal = -1;
    double divisor = 3;
    for (int i=2;i<=iteracoes;i++){
      meuPI += sinal * 4.0/divisor; // atualiza o valor de pi
      divisor += 2; // incrementa o valor do divisor
      sinal *= -1; // inverte o sinal da variavel sinal
    }
    printf("(%i) pi: %f\n", iteracoes, meuPI);
  }

  A funcao calculoDoValorDePI recebe como parametro o numero de iteracoes
    que serao realizadas para o calculo do valor aproximado de pi.
  Porem, neste exercicio voce deve implementar uma nova funcao: 
    double valorDePI(double limiar), baseada na ideia da funcao acima, porem
    que, ao inves de executar um numero de iteracoes passado como parametro,
    ira receber como parametro um limiar de precisao que dira quando sua funcao
    devera parar de calcular a aproximacao, de acordo com a seguinte logica:
    a cada iteracao, voce devera comparar o valor atual de pi com o valor 
    anterior (valor da iteracao anterior), enquanto essa diferenca 
    (em valor absoluto [isto e, sem sinal]) for maior do que o valor de limiar,
    sua funcao devera continuar calculando o valor de pi.
    Assim que essa diferenca for menor ou igual ao valor de limiar, sua funcao
    devera retornar o valor atual de pi.
  Observacao: se o valor do parametro limiar for menor ou igual a 0,000001 
    (um milionesimo), sua funcao devera retornar -1;
  Caso contrario devera retornar o valor aproximado de pi conforme explicado.
  Sua funcao nao devera imprimir nada na tela.

  Parametro:
    limiar - valor do limiar para conclusao do computo do valor de pi

*/	

double valorDePI(double limiar){
	double resultado = 0;

  if( limiar<= 0.000001) return -1;

  
  
	return resultado;
}






/*
	Funcao main criada apenas para seus testes.
	Voce pode adicionar novos testes se quiser.
	ESTA FUNCAO SERA IGNORADA NA CORRECAO
*/
int main() {

	int valor, ini, fim, limite, divisoes;
	double dividendo, limiar;

  /* Exemplos de testes para a funcao somaDigitos: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaDigitos #####\n\n");

	valor = -123;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 0;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 123456;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 2345;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 99999;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));


	/* Exemplos de testes para a funcao somaIntervalo: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaIntervalo #####\n\n");

	ini = -5;
	fim = 5;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 5;
	fim = 4;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 3;
	fim = 4;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 3;
	fim = 6;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 4;
	fim = 1000;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));


	/* Exemplos de testes para a funcao somaInteiros: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaInteiros #####\n\n");

	ini = -5;
	limite = 5;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 4;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 3;
	limite = 3;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 4;
	limite = 17;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 1000;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 980;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 1;
	limite = 9999;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));


	/* Exemplos de testes para a funcao dividindoPorDois: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO dividindoPorDois #####\n\n");

	dividendo = 4;
	divisoes = -5;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 5;
	divisoes = 0;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 8;
	divisoes = 4;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 1024;
	divisoes = 8;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = -4;
	divisoes = 20;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));


	/* Exemplos de testes para a funcao valorDePI: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO valorDePI #####\n\n");

	limiar = -0.2;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 1;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.1;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.001;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.000002;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

  return 0;
}

