/* $PostgreSQL: pgsql/contrib/dict_xsyn/uninstall_dict_xsyn.sql,v 1.3 2007/11/13 04:24:27 momjian Exp $ */

-- Adjust this setting to control where the objects get dropped.
SET search_path = public;

DROP TEXT SEARCH DICTIONARY hrstemc;

DROP TEXT SEARCH TEMPLATE hrstemc_template;

DROP FUNCTION dhrstemc_init(internal);

DROP FUNCTION dhrstemc_lexize(internal,internal,internal,internal);
