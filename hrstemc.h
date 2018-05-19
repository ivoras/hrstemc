#ifndef __HRSTEMC_H__
#define __HRSTEMC_H__

void hrstemc_init(void);
void hrstemc_init_rules(void);

int hrstemc_is_stopword(char *w);
void hrstemc_istakni_slogotvorno_r(char *s);
int hrstemc_ima_samoglasnik(char *s);
void hrstemc_transformiraj(char **s);
char* hrstemc_korjenuj(char *s);
int hrstemc_endswith(char *s, char *what);

#endif