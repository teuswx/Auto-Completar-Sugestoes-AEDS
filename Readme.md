> Status Development: finished :heavy_check_mark:

# Sistema de Sujestão de Palavras
## Objetivo 🎯
Foi proposto pelo professor [Michel Pires Da Silva](https://www.linkedin.com/in/michelpiressilva/?originalSubdomain=br) na disciplina de Algoritmos e Estrutura de Dados, um trabalho no qual o objetivo era desenvolver uma ferramenta ou programa que, tendo como entrada uma palavra específica chamada "busca" e um texto, seja capaz de gerar sugestões para a próxima palavra que provavelmente seguiria a palavra de "busca". Essas sugestões serão derivadas de uma análise das palavras mais frequentes presentes no texto. Para alcançar esse objetivo, construiremos sobre o trabalho prévio realizado [Top K Elementos](https://github.com/teuswx/Top-K-Elementos-Aeds)  e aprimoraremos a funcionalidade existente.

## Leitura de arquivos :file_folder:
Os arquivos devem estar na pasta "dataset" e possuir a seguinte estrutura "inputN.txt", onde N é o índice do arquivo. Para realizar a leitura dos arquivos, a váriavel N deve ser definida com a quantidade necessária de arquivos a serem lidos na classe "algoritmo.hpp". no exemplo a seguir, são lidos 6 arquivos:

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/7adea603-32b0-466b-b1b0-fa8aead16475)

Além disso, existem os seguintes arquivos:

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/35c6eade-739c-4e0d-a0b3-77036cd85276)

**pesquisa.txt:** seu conteúdo deve ser representado pelas 
palavras a serem pesquisadas, e deve estar no seguinte formato:

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/237a84e4-9c8f-48c1-ada6-a54a41666251)

**pontuação.txt:** seu conteúdo deve ser representado pelas pontuações a serem retiradas no texto, e deve estar no seguinte formato:

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/a0f6d778-36b9-48d9-814a-0682f4b01b89)

**stopwords.txt:** seu conteúdo deve ser representado pelas stopwords a serem removidas no texto, e deve conter o seguinte formato: 

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/8422278f-2a27-4802-b36b-9211074df62c)

Ao final do processo, o programa produzirá um arquivo chamado "output.txt". Esse arquivo conterá informações essenciais, incluindo a identificação do "inputN.txt" que foi processado, a palavra-alvo pesquisada nos N textos, sua frequência de ocorrência, bem como as palavras mais relevantes identificadas, juntamente com suas respectivas frequências e valores. Essas informações estarão organizadas em pré-ordem em relação a cada estrutura de dados empregada no projeto.

## Lógica :bulb:
Após a leitura de arquivos realizada pelo método "Algoritmo::lerArquivo()" o sistema está pronto para iniciar o processo de busca das palavras-chave indicadas e suas respetivas sugestões.

Inicialmente, o programa abre o primeiro arquivo de entrada disponíveis para pesquisa. Caso uma palavra-chave não esteja presente no arquivo em específico, o algoritmo não executa os passos posteirores e pula para o próximo arquivo.

Contudo, quando o sistema encontra uma palavra de pesquisa em um arquivo de entrada, prossegue com a etapa de busca das K palavras mais relevantes dentro do contexto. As palavras são fragmentadas em unidades individuais e, em seguida, armazenadas em um MinHeap, uma estrutura de dados especializada. Isso é essencial para o registro e cálculo das frequências de ocorrência de cada palavra no texto analisado.

Após a identificação das K palavras mais relevantes, estas são catalogadas em três diferentes tipos de árvores binárias. Por fim, concluído o processo de busca, análise e armazenamento de sugestões de palavras, o sistema cria um arquivo de saída denominado "output.txt".



<ul>
<li> <strong>Árvore Binária:</strong> Uma árvore binária é uma estrutura de dados hierárquica em que cada nó tem, no máximo, dois filhos: um filho esquerdo e um filho direito. As árvores binárias são amplamente usadas na ciência da computação para organizar dados de forma eficiente e hierárquica, permitindo operações de busca, inserção e exclusão eficazes. Elas são a base de estruturas mais avançadas, como árvores de busca binária (BST) e árvores AVL, que otimizam a busca e a inserção de dados em ordem específica e mantêm o equilíbrio da árvore para um desempenho ideal.<br><br>
<li> <strong>Árvore Binária:</strong> é uma estrutura de dados em forma de árvore binária balanceada, na qual a diferença de altura entre as subárvores esquerda e direita de qualquer nó (conhecida como fator de balanceamento) é mantida em no máximo 1. Essa característica de balanceamento garante que as operações de busca, inserção e exclusão tenham um desempenho eficiente, com tempo médio logarítmico. As árvores AVL são amplamente utilizadas para implementar estruturas de dados de busca eficientes, sendo uma extensão das árvores binárias com equilíbrio automático, proporcionando alto desempenho em diversas aplicações computacionais.<br><br>
<li> <strong>Árvore de Huffman:</strong> é uma estrutura de dados usada para codificar dados de forma eficiente, principalmente em compressão de dados. Ela é construída a partir de uma lista de símbolos e suas frequências, atribuindo códigos binários mais curtos aos símbolos mais frequentes. A Árvore de Huffman é uma árvore binária onde os símbolos são armazenados nas folhas e os caminhos da raiz até as folhas representam os códigos de compressão. Isso garante que os símbolos mais frequentes tenham códigos mais curtos, economizando espaço.
</ul>

## Exemplo de execução :hammer:

![image](https://github.com/teuswx/Auto-Completar-Sugestoes-AEDS/assets/102326098/3bda4c48-c790-4fc8-ae1d-ba2cc15f297e)

## Conclusão :ballot_box_with_check:

Durante o desenvolvimento do projeto, tivemos a oportunidade de explorar e aplicar estruturas de dados avançadas, como as árvores binárias, que desempenharam um papel fundamental no armazenamento e na análise dos principais K itens. À medida que o algoritmo foi concluído, uma compreensão mais profunda da estrutura das árvores binárias surgiu, revelando como elas eficientemente gerenciam conjuntos de elementos. A principal finalidade de uma árvore binária é permitir buscas rápidas e eficazes de dados, uma funcionalidade que se mostrou essencial ao longo do projeto.

Essa experiência proporcionou um aprendizado valioso sobre técnicas de otimização de código, que podem ser aplicadas em projetos futuros.


## Compilação e Execução :electric_plug:

O programa foi feito de acordo com a proposta e possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Portanto, temos as seguintes diretrizes de execução:
| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

