


# Corrigindo Missing Separator no makefile

### Verificando os TABS:
> $ cat -e -t -v Makefile 

Corrigindo o problema de espaços em vez de TABs:
    http://pacman.blog.br/blog/2007/07/26/resolvendo-problemas-comuns-3-missing/

$ sed  -i 's/^\ \{8\}/\t/' Makefile
$ cat -A Makefile

#um makefile comum$
all:$
^I@echo "oi mundo"$ -> Foi corrigido
$ make
oi mundo