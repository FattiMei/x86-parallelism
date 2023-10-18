# x86-parallelism
Indagine sul parallelismo all'interno di un core x86


## Obiettivi dell'indagine
Comprendere come un singolo core di una cpu moderna x86 implementa il parallelismo.


## Cos'è il parallelismo
Una definizione operativa: il processore in un ciclo di clock esegue più istruzioni contemporaneamente.


## Principio dell'indagine
Misuro il numero di cicli impiegati per eseguire una sequenza di $n$ istruzioni semplici (per il momento limitate a operazione aritmetiche tra registri). Se il core implementa il parallelismo in qualche forma il numero di cicli impiegati dovrebbe essere $m < n$


### Misura dei cicli vs. misura del tempo
Alcune cpu implementano il [frequency scaling](https://en.wikipedia.org/wiki/Frequency_scaling), quindi la misura del tempo di esecuzione sarebbe falsata dalla frequenza di clock decisa dal sistema in quel momento. Il numero di cicli impiegati invece è indipendente dalla frequenza di clock


### Perché x86?
I processori x86 dispongono di un contatore, il time stamp counter (TSC), che viene incrementato per ogni ciclo di clock. L'istruzione rdtsc permette di leggere il valore del contatore, per maggiori informazioni si consulti [questo](https://www.felixcloutier.com/x86/rdtsc) link

La procedura di test di una sequenza di istruzioni diventa:

1. leggi il TSC
2. esegui le istruzioni
3. leggi il TSC

Il numero di cicli impiegati è la differenza delle due misure


## Cosa rende complessa l'analisi
