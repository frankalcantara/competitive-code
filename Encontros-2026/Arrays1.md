## P1 — O Caixa da Casa de Contagem

A casa de contagem mantém $N$ contas num grande livro, e o mestre tem uma mania
bem conhecida: só considera quitada de imediato a conta cujo saldo é par, porque
essas ele paga em moedas duplas de dois marcos e não suporta contar moeda solta.
A cada expediente chega um ajuste $(val, idx)$ — um crédito ou um débito lançado
sobre a conta de índice $idx$ — e, logo depois de cada lançamento, o mestre quer
saber a soma de todos os saldos que naquele instante são pares.

O caixa confere conta por conta no primeiro dia. Depois do primeiro dia, para de
conferir.

### Entrada

A primeira linha contém dois inteiros $N$ e $Q$, o número de contas e o número de
ajustes. A segunda linha contém $N$ inteiros, os saldos iniciais
$A[0], A[1], \dots, A[N-1]$. Cada uma das $Q$ linhas seguintes contém dois
inteiros $val$ e $idx$, o valor do ajuste e o índice da conta, com $idx$ em base
zero.

### Saída

Imprima $Q$ linhas. Após cada ajuste, imprima a soma dos saldos que são pares
naquele momento.

### Restrições

$$1 \le N, Q \le 10^4 \qquad |A[i]| \le 10^4 \qquad |val| \le 10^4$$

### Exemplo

Entrada:

```
4 4
1 2 3 4
1 0
-3 1
-4 0
2 3
```

Saída:

```
8
6
2
4
```

No primeiro ajuste a conta $0$ passa de $1$ para $2$ e entra na soma dos pares,
que se torna $2 + 2 + 4 = 8$; o livro segue assim até o último lançamento.

---

## P2 — O Muro do Mosteiro

O mosteiro ergue um muro apoiado em $N$ pilares enfileirados, com $N$ ímpar por
tradição de ofício, e todos os pilares começam no mesmo nível do chão. Ao longo
da obra chegam $K$ ordens de serviço, cada uma na forma $A\ B$: a pedreira
assenta uma fiada de pedra sobre todos os pilares de $A$ até $B$, inclusive,
elevando cada um deles em uma unidade. Terminada a obra, o abade desconfia de
médias e pede apenas a altura do pilar do meio, aquele que, se as alturas fossem
dispostas em ordem, ocuparia a posição central.

Os pilares são numerados de $1$ a $N$, da esquerda para a direita.

### Entrada

A primeira linha contém dois inteiros $N$ e $K$, o número de pilares e o número de
ordens de serviço. Cada uma das $K$ linhas seguintes contém dois inteiros $A$ e
$B$, os extremos do trecho elevado, com $1 \le A \le B \le N$.

### Saída

Imprima um único inteiro: a altura mediana dos pilares ao fim da obra.

### Restrições

$$1 \le N \le 10^6 \ (\text{ímpar}) \qquad 1 \le K \le 25\,000$$

### Exemplo

Entrada:

```
7 4
3 5
5 5
2 4
4 6
```

Saída:

```
1
```

As alturas finais dos sete pilares são $0, 1, 2, 3, 3, 1, 0$; ordenadas, o valor
central é $1$, e é esse pilar que o abade queria.

---

## P3 — O Nível do Agrimensor

O agrimensor cravou $N$ estacas ao longo de uma vereda e anotou, para cada estaca,
a diferença de nível $nums[i]$ em relação à referência — um número que pode subir
acima dela ou descer abaixo. Antes de assentar o marco de pedra, ele procura a
primeira estaca em que a soma das diferenças à sua esquerda iguala a soma das
diferenças à sua direita; a estaca escolhida serve de apoio e não entra em
nenhuma das duas somas. Se nenhuma estaca equilibra os dois lados, não há marco a
assentar.

O agrimensor quer uma estaca que não deva nada a nenhum dos lados.

### Entrada

A primeira linha contém um inteiro $N$, o número de estacas. A segunda linha
contém $N$ inteiros $nums[0], nums[1], \dots, nums[N-1]$, as diferenças de nível
em base zero.

### Saída

Imprima o menor índice $i$ (em base zero) em que a soma à esquerda iguala a soma à
direita, ou $-1$ se não existir tal estaca.

### Restrições

$$1 \le N \le 10^4 \qquad -1000 \le nums[i] \le 1000$$

### Exemplo

Entrada:

```
6
1 7 3 6 5 6
```

Saída:

```
3
```

À esquerda da estaca $3$ somam-se $1 + 7 + 3 = 11$; à direita, $5 + 6 = 11$. A
estaca de índice $3$ é o apoio procurado.
