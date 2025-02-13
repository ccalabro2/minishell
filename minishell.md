ordine di come funziona mini:
read: apre un prompt nella shell(visivamente abbiamo il nostro terminale "minishell > ...")
    dopo aver aperto il prompt inizia minishell; due scenari:
    1)classica gestione degli operatori (tokenize, parse ecc...)
    2)heredoc: in questo caso utilizzeremo readline fino a quando non troverermo il del. il contenuto dell'heredoc verrá eseguito in base al comando che lo precede (es. cat, echo ecc...)

(heredoc espande tutto tranne quando gli passasiamo un $env tra singoli apici es."$USER" -> "gd-auria" '$USER'-> '$USER')

info:
quando troviamo una pipe l'output del comando prima diventa l'imput del comando dopo







13/02
abbiamo splittato per pipe la stringa iniziale e poi abbiamo passato la matrice generata da pipe_splitter a tokenize 