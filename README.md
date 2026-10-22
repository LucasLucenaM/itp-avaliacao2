# itp-avaliacao2
# Projeto individual para a segunda avaliação da matéria de ITP 2026.2

 **Aluno**: Lucas Lucena de Medeiros

## **Projeto escolhido**: Opção 1

Uma pessoa precisa registrar três notas de cada estudante e obter um resumo dos resultados
da turma.

## **O que faz o programa?**

O programa solicita a quantidade de estudantes, os nomes e as três notas de cada um

Em seguida, calcula as médias individuais e a média geral da turma, exibe o boletim com as notas e as médias e identifica os estudantes que atingiram a meta estabelecida

Por fim, imprime a maior média e os nomes dos estudantes que tiveram a maior média

## **Compilação e Execução**

É preciso criar uma pasta chamda **"ProjetoITP"** e colocar **Projeto** e **Projeto.c** dentro dela, além de ser necessário ter o GCC instalado no computador

1. Acessar a pasta do projeto

cd ~/ProjetoITP

2. Compilar o programa

gcc -Wall -Wextra Projeto.c -o Projeto

3. Executar o programa

./Projeto

## **Testes**

### **Teste 1**

**Input:**

 3
 Lucas Lucena de Medeiros
 7
 6
 5
 Pietro Freire Rocha
 10
 9
 8
 Marconi Eloi Junior
 8 
 9
 10

**Output:**

======================= BOLETIM =======================

Nome                      |     N1 |     N2 |     N3 |  Média | Situação     
--------------------------------------------------------------------------
Lucas Lucena de Medeiros  |   7.00 |   6.00 |   5.00 |   6.00 | Atingiu a meta 
Pietro Freire Rocha       |  10.00 |   9.00 |   8.00 |   9.00 | Atingiu a meta 
Marconi Eloi Junior       |   8.00 |   9.00 |  10.00 |   9.00 | Atingiu a meta 

Media geral da turma: 8.00
Maior media: 9.00
Estudante(s) com a maior media:
-> Pietro Freire Rocha
-> Marconi Eloi Junior


### **Teste 2**

**Input:**

 1
 Raimundo Antônio de Medeiros
 7.5
 6.5
 5.5

**Output:**

======================= BOLETIM =======================

Nome                      |     N1 |     N2 |     N3 |  Média | Situação     
--------------------------------------------------------------------------
Raimundo Antônio de Medeiros |   7.50 |   6.50 |   5.50 |   6.50 | Atingiu a meta 

Media geral da turma: 6.50
Maior media: 6.50
Estudante(s) com a maior media:
-> Raimundo Antônio de Medeiros


## **Link do vídeo:** 






