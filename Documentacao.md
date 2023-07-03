# Documentação - Tabela Hash

O código fornecido implementa uma tabela hash em linguagem C. A tabela hash é uma estrutura de dados eficiente para armazenar e recuperar informações com base em uma chave única. Ele usa o método de endereçamento aberto para lidar com colisões, mais especificamente a sondagem linear.

## Estrutura de Dados

O código define uma estrutura `hash` para representar a tabela hash. A estrutura possui os seguintes campos:

- `qtd`: um inteiro que armazena a quantidade de elementos atualmente na tabela.
- `TABLE_SIZE`: um inteiro que define o tamanho da tabela hash.
- `itens`: um ponteiro para uma matriz de ponteiros para estruturas `aluno`, usada para armazenar os elementos da tabela.

## Funções

### `criaHash`

```c
Hash* criaHash(int TABLE_SIZE);
```

Esta função cria e inicializa uma nova tabela hash. Ela recebe como parâmetro o tamanho desejado para a tabela (`TABLE_SIZE`) e retorna um ponteiro para a tabela hash recém-criada (`Hash*`). A função aloca memória para a estrutura `hash` e sua matriz de itens, e inicializa os campos com valores padrão.

### `liberaHash`

```c
void liberaHash(Hash* ha);
```

Esta função libera a memória alocada para a tabela hash. Ela recebe como parâmetro um ponteiro para a tabela hash a ser liberada (`Hash*`). A função percorre a matriz de itens, liberando a memória alocada para cada item, e em seguida libera a memória alocada para a matriz e a estrutura `hash` em si.

### `chaveDivisao`

```c
int chaveDivisao(int chave, int TABLE_SIZE);
```

Esta função calcula o índice de hash para uma chave utilizando o método da divisão. Ela recebe como parâmetros a chave e o tamanho da tabela (`TABLE_SIZE`), e retorna o índice de hash calculado.

```c
int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}
```

1. **Parâmetros**:

   - `chave`: um número inteiro que representa a chave do elemento a ser inserido ou buscado na tabela hash.
   - `TABLE_SIZE`: um número inteiro que define o tamanho da tabela hash, ou seja, o número de posições disponíveis na tabela.

2. **Operação `& 0x7FFFFFFF`**:

   - A chave é submetida a uma operação `AND` bit a bit com o valor hexadecimal `0x7FFFFFFF`.
   - O valor hexadecimal `0x7FFFFFFF` possui todos os bits iguais a 1, exceto o bit mais significativo (o sinal), que é igual a 0.
   - Essa operação garante que o resultado seja sempre um número positivo, independentemente do sinal da chave.

3. **Operação `% TABLE_SIZE`**:

   - O resultado da operação anterior é dividido pelo valor `TABLE_SIZE`.
   - O operador `%` retorna o resto da divisão entre os dois operandos.
   - Essa operação calcula o índice de hash, que representa a posição onde o elemento será inserido ou buscado na tabela hash.

4. **Retorno**:
   - O resultado da operação `% TABLE_SIZE` é retornado como o índice de hash.

### `chaveMultiplicacao`

A função chaveMultiplicacao implementa o método de multiplicação para calcular o índice de hash com base em uma chave e no tamanho da tabela hash.

```c
int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;

    return (int) (TABLE_SIZE * val);
}
```

1. **Parâmetros**:

   - `chave`: um número inteiro que representa a chave do elemento a ser inserido ou buscado na tabela hash.
   - `TABLE_SIZE`: um número inteiro que define o tamanho da tabela hash, ou seja, o número de posições disponíveis na tabela.

2. **Constante A**:

   - A função utiliza uma constante `A` com o valor `0.6180339887`.
   - Essa constante deve estar dentro do intervalo `0 < A < 1` para garantir um melhor espalhamento dos elementos na tabela hash.

3. **Cálculo do valor intermediário**:

   - O valor da chave é multiplicado pela constante `A` e armazenado na variável `val`.
   - Em seguida, a parte fracionária de `val` é removida, subtraindo-se `(int) val` de `val`.

4. **Cálculo do índice de hash**:
   - O valor intermediário `val` é multiplicado pelo tamanho da tabela `TABLE_SIZE`.
   - O operador de coerção `(int)` é usado para converter `val` em um número inteiro.
   - O resultado é retornado como o índice de hash.

### `valorString`

A função `valorString` calcula um valor numérico a partir de uma string. 

```c
int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str); //desloca 10 bits para a direita
    for (i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}
```

1. **Parâmetro**:

   - `str`: um ponteiro para uma sequência de caracteres (string) que será convertida em um valor numérico.

2. **Inicialização do valor**:

   - A função inicializa uma variável `valor` com o valor 7. Essa é uma escolha arbitrária para iniciar o cálculo do valor.

3. **Cálculo do tamanho**:

   - A função utiliza a função `strlen` para determinar o tamanho da string `str`. O tamanho é armazenado na variável `tam`.
   - Esse tamanho será usado para controlar o loop de iteração posterior.

4. **Cálculo do valor numérico**:

   - A função itera sobre cada caractere da string `str` usando um loop `for`.
   - Para cada caractere, o valor numérico é calculado multiplicando o valor atual por 31 e somando o valor inteiro correspondente ao caractere. Isso é feito com a expressão `valor = 31 * valor + (int) str[i]`.
   - O cálculo é repetido para todos os caracteres da string.

5. **Retorno do valor numérico**:
   - Após o loop de iteração, o valor final calculado é retornado como o valor numérico resultante da string.

### `insereHash_SemColisao`

```c
int insereHash_SemColisao(Hash* ha, struct aluno al);
```

Esta função insere um elemento na tabela hash, sem tratamento de colisões. Ela recebe como parâmetros um ponteiro para a tabela hash (`Hash*`) e um elemento a ser inserido (`struct aluno`). A função calcula o índice de hash para a chave do elemento e insere o elemento na posição correspondente na matriz de itens.

### `buscaHash_SemColisao`

```c
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno *al);
```

Esta função busca um elemento na tabela hash, sem tratamento de colisões. Ela recebe como parâmetros um ponteiro para a tabela hash (`Hash*`), a matrícula do elemento a ser buscado e um ponteiro para uma estrutura `aluno`, onde o elemento encontrado será armazenado. A função calcula o índice de hash para a matrícula e verifica se o elemento está presente na posição correspondente na matriz de itens.

### `sondagemLinear`

```c
int sondagemLinear(int pos, int i, int TABLE_SIZE);
```

Esta função implementa a técnica de sondagem linear para tratar colisões na tabela hash. Ela recebe como parâmetros a posição inicial (`pos`), o número de iterações (`i`) e o tamanho da tabela (`TABLE_SIZE`), e retorna o novo índice calculado após a sondagem linear.
Aqui está a documentação em linguagem Markdown para as funções `sondagemQuadratica` e `duploHash`:

## Função `sondagemQuadratica`

A função `sondagemQuadratica` implementa a técnica de sondagem quadrática para tratar colisões na tabela hash. 

```c
int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {
    pos = pos + 2 * i + 5 * i * i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}
```

1. **Parâmetros**:
   - `pos`: um número inteiro que representa a posição inicial onde ocorreu uma colisão na tabela hash.
   - `i`: um número inteiro que representa o número de iterações ou tentativas de sondagem.
   - `TABLE_SIZE`: um número inteiro que define o tamanho da tabela hash.

2. **Cálculo do deslocamento quadrático**:
   - A função calcula o deslocamento quadrático adicionando um valor à posição inicial.
   - O cálculo é realizado pela expressão `pos = pos + 2 * i + 5 * i * i`, onde `i` é o número de iterações.
   - Esse cálculo de deslocamento ajuda a evitar agrupamentos de elementos na tabela hash, proporcionando uma distribuição mais uniforme.

3. **Cálculo do novo índice de hash**:
   - O novo índice de hash é obtido aplicando a operação `AND` bit a bit com o valor hexadecimal `0x7FFFFFFF` à posição calculada.
   - O valor hexadecimal `0x7FFFFFFF` possui todos os bits iguais a 1, exceto o bit mais significativo (o sinal), que é igual a 0.
   - Em seguida, o resultado da operação `AND` é dividido pelo tamanho da tabela `TABLE_SIZE` usando o operador `%`.

4. **Retorno**:
   - O novo índice de hash, após a sondagem quadrática, é retornado como o índice onde o próximo elemento deve ser inserido ou buscado na tabela hash.

## Função `duploHash`

A função `duploHash` implementa o método de duplo hash (double hashing) para tratar colisões na tabela hash. 

```c
int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE - 1) + 1;
    return ((H1 + i * H2) & 0x7FFFFFFF) % TABLE_SIZE;
}
```

1. **Parâmetros**:
   - `H1`: um número inteiro que representa o primeiro valor de hash obtido para a chave.
   - `chave`: um número inteiro que representa a chave do elemento a ser inserido ou buscado na tabela hash.
   - `i`: um número inteiro que representa o número de iterações ou tentativas de sondagem.
   - `TABLE_SIZE`: um número inteiro que define o tamanho da tabela hash.

2. **Cálculo do segundo valor de hash**:
   - A função utiliza a função `chaveDivisao` para calcular um segundo valor de hash `H2` para a chave.
   - A função `chaveDivisao` recebe a chave e `TABLE_SIZE - 1` como parâmetros para calcular o índice de hash.
   - O valor de `H2` é obtido somando-se 1 ao resultado do cálculo.

3. **Cálculo do novo índice de hash**:
   - O novo índice de hash é obtido somando-se o valor inicial de hash `H1` ao produto de `i` e `H2`.
   - Em seguida, é aplicada a operação `AND` bit a bit com o valor hexadecimal `0x7FFFFFFF` ao resultado.
   - O valor hexadecimal `0x7FFFFFFF` possui todos os bits iguais a 1, exceto o bit mais significativo (o sinal), que é igual a 0.
   - Por fim, o resultado da operação `AND` é dividido pelo tamanho da tabela `TABLE_SIZE` usando o operador `%`.

4. **Retorno**:
   - O novo índice de hash, após a aplicação do duplo hash, é retornado como o índice onde o próximo elemento deve ser inserido ou buscado na tabela hash.

Em resumo, as funções `sondagemQuadratica` e `duploHash` são utilizadas para tratar colisões na tabela hash. A `sondagemQuadratica` calcula o deslocamento quadrático a ser aplicado a partir de uma posição inicial, enquanto a `duploHash` calcula um segundo valor de hash e o combina com o valor inicial de hash para obter um novo índice. Ambas as funções garantem que os elementos sejam distribuídos de forma mais uniforme na tabela hash, evitando colisões frequentes.

### `insereHash_EnderAberto`

```c
int insereHash_EnderAberto(Hash* ha, struct aluno al);
```

Esta função insere um elemento na tabela hash utilizando o método de endereçamento aberto com sondagem linear. Ela recebe como parâmetros um ponteiro para a tabela hash (`Hash*`) e um elemento a ser inserido (`struct aluno`). A função calcula o índice de hash para a chave do elemento e realiza a sondagem linear para encontrar uma posição vazia na tabela, onde o elemento será inserido.

### `buscaHash_EnderAberto`

```c
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno *al);
```

Esta função busca um elemento na tabela hash utilizando o método de endereçamento aberto com sondagem linear. Ela recebe como parâmetros um ponteiro para a tabela hash (`Hash*`), a matrícula do elemento a ser buscado e um ponteiro para uma estrutura `aluno`, onde o elemento encontrado será armazenado. A função calcula o índice de hash para a matrícula e realiza a sondagem linear para encontrar o elemento na tabela.
