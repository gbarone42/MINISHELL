# MINISHELL RESOURCES

## Contents

1. [External Functions](#external-functions)
    - [Curses Functions](#curses-functions)
        1. [tgetent](#tgetent)
        2. [tgetflag](#tgetflag)
        3. [tgetnum](#tgetnum)
        4. [tgetstr](#tgetstr)
        5. [tgoto](#tgoto)
        6. [tputs](#tputs)
    - [Termios Functions](#termios-functions)
        1. [tcsetattr](#tcsetattr)
        2. [tcgetattr](#tcgetattr)

## 1. External Functions

### Curses Functions

La libreria curses è una libreria in ambiente UNIX e sistemi simili, tra cui Linux, che fornisce una serie di funzioni per la creazione di interfacce utente testuali (TUI) avanzate. Il suo scopo principale è consentire agli sviluppatori di scrivere applicazioni che possano interagire con l'utente attraverso il terminale in modo più avanzato rispetto alla semplice scrittura di caratteri su schermo.

Ecco alcune delle caratteristiche principali della libreria curses:  
- **Gestione del cursore:** curses fornisce funzioni per spostare e posizionare il cursore sullo schermo. Questo consente di controllare in modo preciso la posizione di output.
- **Colori:** la libreria supporta il controllo dei colori del testo e dello sfondo. Questo consente di creare interfacce utente più visivamente accattivanti e informative.
- **Funzioni per la pulizia dello schermo:** è possibile pulire l'intero schermo o solo parti specifiche di esso, contribuendo a creare un'interfaccia utente più pulita e dinamica.
- **Gestione delle finestre:** curses offre la possibilità di creare e gestire finestre all'interno del terminale. Questo è utile per organizzare e suddividere l'output in modo strutturato.

- **Input non bloccante:** la libreria consente la lettura dell'input in modo non bloccante, il che significa che un programma può continuare ad eseguire altre operazioni mentre attende l'input dell'utente.

- **Gestione degli eventi:** è possibile gestire eventi come tasti premuti, ridimensionamento del terminale e altro ancora.

- **Supporto per il mouse:** curses può gestire anche l'input da mouse, consentendo agli utenti di interagire con l'applicazione tramite il mouse.

#### tgetent

Il prototipo della funzione è:

`int tgetent(char *bp, const char *name);`

La funzione serve per inizializzare la struttura di una libreria terminale `terminfo` che contiene le informazioni specifiche del terminale utilizzato. Il parametro `bp` è un buffer in cui vengono memorizzate le informazioni recuperate sul terminale e `name` è il nome del terminale per il quale si desidera ottenere le informazioni, di solito ottenuto dalla variabile di ambiente `TERM`. Questa funzione restituisce 1 se la sua esecuzione è andata a buon fine, 0 altrimenti.

#### tgetflag

Il prototipo della funzione è:

`int tgetflag(const char *capname);`

La funzione serve per recuperare le informazioni sulle flag o le capacità di un terminale specifico dal database `terminfo`. Il parametro `capname` è una stringa che rappresenta il nome della capacità del terminale in uso. La funzione restituisce 0 se la capacità non è definita o supportata.

#### tgetnum

Il prototipo della funzione è:

`int tgetnum(const char *capname);`

La funzione serve per recuperare informazioni specifiche riguardanti numeri di un terminale dal database `terminfo`. Il parametro `capname` è una stringa che rappresenta il nome dell'informazione del terminale in uso. La funzione restituisce -1 se la capacità non è definita o supportata.

#### tgetstr

Il prototipo della funzione è:

`int tgetstr(const char *capname, char **area);`

La funzione serve per recuperare stringhe specifiche dalle capacità di un terminale dal database `terminfo`. Il parametro `capname` è una stringa che rappresenta il nome della capacità del terminale in uso, e `area` è un puntatore a buffer in cui verrà memorizzata la stringa ottenuta. La funzione restituisce NULL se la capacità non è definita o supportata.

#### tgoto

#### tputs

### Termios Functions

Termios è un termine che deriva da "impostazioni I/O del terminale". Nei sistemi operativi di tipo Unix, le funzioni termios fanno parte dell'interfaccia I/O del terminale: ovvero, forniscono un modo per controllare e modificare le sue impostazioni. Queste infatti vengono utilizzate per configurare parametri come velocità di trasmissione, dimensione dei caratteri, flag di controllo e altro.

Definiamo `struct termios`:
```
struct termios {
	tcflag_t c_iflag;	/* input mode flags */
	tcflag_t c_oflag;	/* output mode flags */
	tcflag_t c_cflag;	/* control mode flags */
	tcflag_t c_lflag;	/* local mode flags */
	cc_t c_cc[NCCS];	/* control characters */
};
```

Ecco una breve descrizione dei suoi campi principali:
- `c_iflag`: Flag di modalità di input. Contiene vari indicatori di modalità per il comportamento dell'input.
- `c_oflag`: Flag di modalità di output. Contiene vari indicatori di modalità per il comportamento dell'output.
- `c_cflag`: Flag di modalità di controllo. Contiene vari indicatori di modalità per il controllo generale del terminale, come la velocità di trasmissione (baud rate) e i bit di dati.
- `c_lflag`: Flag di modalità locale. Contiene vari indicatori di modalità che influenzano il comportamento locale del terminale, come l'echo dei caratteri.
- `c_cc`: Un array di caratteri di controllo. Contiene caratteri speciali utilizzati per controllare il comportamento del terminale.

Il tipo `tcflag_t` è in realtà un tipo intero senza segno, i suoi valori sono costanti utilizzate per rappresentare diverse opzioni e modalità associate ai flag di configurazione di un terminale.

Alcune comuni costanti sono:
- `Baud Rate Constants` ad esempio `B9600` per una velocità di trasmissione di 9600 bps.
- `Input Modes` ad esempio `IGNBRK` per ignorare i break.
- `Output Modes` ad esempio `OPOST` per l'elaborazione di output.
- `Control Modes` ad esempio `CS8` per otto bit di dati.
- `Local Modes` ad esempio `ECHO` per abilitare l'echo.

#### tcsetattr

Il prototipo della funzione è:

`int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`

La funzione serve per settare la configurazione del terminale a cui fa riferimento il file descriptor `fd` (0 indica il terminale in uso). La configurazione viene impostata in base alla struttura `termios_p`; il cambiamento avviene in base a `optional_actions`.

#### tcgetattr

Il prototipo della funzione è:

`int tcgetattr(int fd, struct termios *termios_p);`

La funzione serve per leggere la configurazione del terminale a cui fa riferimento il file descriptor `fd`, che viene dunque salvata nella variabile puntata da `termios_p`.
