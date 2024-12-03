# Estrutura-de-dados-1-em-C-
CONFIGURANDO O AMBIENTE PARA PROGRAMAÇÃO EM C NO WINDOWS
========================================================

Este guia descreve como configurar um ambiente de programação em C no Windows, 
incluindo instalação do compilador e execução do código.

PRÉ-REQUISITOS
--------------
Antes de começar, certifique-se de ter os seguintes itens:
- Um computador com o sistema operacional Windows.
- Conexão com a internet para baixar as ferramentas necessárias.

PASSO 1: INSTALAR O MinGW
-------------------------
O MinGW (Minimalist GNU for Windows) é um ambiente popular para compilar programas em C no Windows.

1. Acesse o site oficial do MinGW: https://sourceforge.net/projects/mingw/
2. Baixe o instalador (mingw-get-setup.exe).
3. Execute o instalador e siga os passos:
   - Escolha "Basic Setup".
   - Marque os pacotes necessários: mingw32-gcc-g++ (compilador C/C++).
   - Clique em "Apply Changes" para instalar.

4. Após a instalação, adicione o caminho do MinGW ao PATH do sistema:
   - Vá ao Painel de Controle > Sistema > Configurações Avançadas do Sistema > Variáveis de Ambiente.
   - Encontre a variável `Path` em "Variáveis do Sistema" e clique em "Editar".
   - Adicione o caminho para o diretório `bin` do MinGW (exemplo: C:\MinGW\bin).

5. Verifique se o MinGW foi instalado corretamente:
   - Abra o terminal (Prompt de Comando ou PowerShell).
   - Digite: gcc --version
   - Você deve ver a versão instalada do GCC.

PASSO 2: ESCREVENDO SEU PRIMEIRO CÓDIGO EM C
-------------------------------------------
1. Crie um arquivo chamado "programa.c" em um diretório de sua escolha.
2. Abra o arquivo em um editor de texto como VS Code, Notepad++ ou o próprio Bloco de Notas.
3. Escreva o seguinte código de exemplo:

#include <stdio.h>

int main() { printf("Olá, mundo!\n"); return 0; }


PASSO 3: COMPILANDO O CÓDIGO
----------------------------
1. Abra o terminal e navegue até o diretório onde está o arquivo "programa.c". 
   Use o comando `cd` para mudar o diretório:

   cd caminho\para\o\diretorio

2. Compile o programa com o seguinte comando:

   gcc programa.c -o programa.exe

   - `gcc`: O comando do compilador GCC.
   - `programa.c`: Nome do arquivo fonte.
   - `-o programa.exe`: Especifica o nome do arquivo executável de saída.

3. Se tudo der certo, um arquivo chamado "programa.exe" será gerado no mesmo diretório.

PASSO 4: EXECUTANDO O CÓDIGO
----------------------------
1. Para executar o programa compilado, ainda no terminal, digite:

   programa.exe

2. Você verá a saída:

   Olá, mundo!

DICAS EXTRAS
------------
- EDITOR DE CÓDIGO: Instale o Visual Studio Code (https://code.visualstudio.com/) 
  e configure a extensão "C/C++" para facilitar a edição e depuração de código.
- DEPURAÇÃO: Para executar o código diretamente no VS Code, configure o launch.json 
  para suporte ao GCC.
- ATUALIZAÇÕES: Sempre mantenha o MinGW atualizado para garantir suporte às últimas 
  funcionalidades do compilador.

Com essas instruções, você está pronto para começar a programar em C no Windows! 🚀

Se tiver dúvidas ou problemas, consulte a documentação oficial do GCC (https://gcc.gnu.org/) 
ou busque ajuda em fóruns como o Stack Overflow.



