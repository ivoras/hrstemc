/* contrib/dict_hrstemc/dict_hrstemc--unpackaged--1.0.sql */

ALTER EXTENSION dict_hrstemc ADD function dhrstemc_init(internal);
ALTER EXTENSION dict_hrstemc ADD function dhrstemc_lexize(internal,internal,internal,internal);
ALTER EXTENSION dict_hrstemc ADD text search template hrstemc_template;
ALTER EXTENSION dict_hrstemc ADD text search dictionary hrstemc;
