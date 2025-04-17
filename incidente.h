// incidentes.h
#ifndef incidentes_h
#define incidentes_h

typedef struct Incidente {
    int id;
    char tipo[30];               // phishing, malware, etc.
    char dataHora[20];    //deixar data e hora separado ou junto?     
    char descricao[256];
    char severidade[20];        // baixo, médio, alto
    char estado[20];            // por tratar, em análise, resolvido
    char tecnicoResponsavel[50]; // username do técnico
    int tempoEstimado;          // em min
} Incidente;


#endif
