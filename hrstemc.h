#ifndef __HRSTEMC_H__
#define __HRSTEMC_H__

void hrstemc_init();
void hrstemc_init_rules();

int hrstemc_is_stopword(char *w);
void hrstemc_istakni_slogotvorno_r(char *s);
int hrstemc_ima_samoglasnik(char *s);

#endif