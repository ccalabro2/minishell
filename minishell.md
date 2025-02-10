PULIRE IL CODICE:
fare delle struct per read
vedere che le funzioni non superino i 25
norminettare

FINIRE IL TOKENIZE:
$
pipe

DA FARE 11/02
risolvere la questione apici per heredoc
andare avanti
















ordine di come funziona mini:
read: apre un prompt nella shell(visivamente abbiamo il nostro terminale "minishell > ...")
    dopo aver aperto il prompt inizia minishell; due scenari:
    1)classica gestione degli operatori (tokenize, parse ecc...)
    2)heredoc: in questo caso utilizzeremo readline fino a quando non troverermo il del. il contenuto dell'heredoc verrá eseguito in base al comando che lo precede (es. cat, echo ecc...)
