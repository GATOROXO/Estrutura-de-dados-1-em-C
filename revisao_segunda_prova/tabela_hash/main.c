 #include "tabela_hash.h"

 int main() {
     TabelaHash minha_tabela;
     tabela_hash_inicializar(&minha_tabela);
 
     // Testes básicos
     tabela_hash_inserir(&minha_tabela, 10, 100);
     tabela_hash_inserir(&minha_tabela, 20, 200);
     tabela_hash_inserir(&minha_tabela, 30, 300);
     tabela_hash_inserir(&minha_tabela, 11, 110);
 
     tabela_hash_imprimir(&minha_tabela);
 
     // Busca
     NoHash* encontrado = tabela_hash_buscar(&minha_tabela, 20);
     if(encontrado) {
         printf("\nValor encontrado: %d\n", encontrado->valor);
     }
 
     // Remoção
     int valor_removido = tabela_hash_remover(&minha_tabela, 20);
     printf("\nValor removido: %d\n", valor_removido);
 
     tabela_hash_imprimir(&minha_tabela);
     tabela_hash_destruir(&minha_tabela);
 
     return 0;
 }