
#include <err.h>

static char *transformations[131][2] = {
    { "lozi", "loga" },
    { "lozima", "loga" },
    { "pjesi", "pjeh" },
    { "pjesima", "pjeh" },
    { "vojci", "vojka" },
    { "bojci", "bojka" },
    { "jaci", "jak" },
    { "jacima", "jak" },
    { "čajan", "čajni" },
    { "ijeran", "ijerni" },
    { "laran", "larni" },
    { "ijesan", "ijesni" },
    { "anjac", "anjca" },
    { "ajac", "ajca" },
    { "ajaca", "ajca" },
    { "ljaca", "ljca" },
    { "ljac", "ljca" },
    { "ejac", "ejca" },
    { "ejaca", "ejca" },
    { "ojac", "ojca" },
    { "ojaca", "ojca" },
    { "ajaka", "ajka" },
    { "ojaka", "ojka" },
    { "šaca", "šca" },
    { "šac", "šca" },
    { "inzima", "ing" },
    { "inzi", "ing" },
    { "tvenici", "tvenik" },
    { "tetici", "tetika" },
    { "teticima", "tetika" },
    { "nstava", "nstva" },
    { "nicima", "nik" },
    { "ticima", "tik" },
    { "zicima", "zik" },
    { "snici", "snik" },
    { "kuse", "kusi" },
    { "kusan", "kusni" },
    { "kustava", "kustva" },
    { "dušan", "dušni" },
    { "antan", "antni" },
    { "bilan", "bilni" },
    { "tilan", "tilni" },
    { "avilan", "avilni" },
    { "silan", "silni" },
    { "gilan", "gilni" },
    { "rilan", "rilni" },
    { "nilan", "nilni" },
    { "alan", "alni" },
    { "ozan", "ozni" },
    { "rave", "ravi" },
    { "stavan", "stavni" },
    { "pravan", "pravni" },
    { "tivan", "tivni" },
    { "sivan", "sivni" },
    { "atan", "atni" },
    { "cenata", "centa" },
    { "denata", "denta" },
    { "genata", "genta" },
    { "lenata", "lenta" },
    { "menata", "menta" },
    { "jenata", "jenta" },
    { "venata", "venta" },
    { "tetan", "tetni" },
    { "pletan", "pletni" },
    { "šave", "šavi" },
    { "manata", "manta" },
    { "tanata", "tanta" },
    { "lanata", "lanta" },
    { "sanata", "santa" },
    { "ačak", "ačka" },
    { "ačaka", "ačka" },
    { "ušak", "uška" },
    { "atak", "atka" },
    { "ataka", "atka" },
    { "atci", "atka" },
    { "atcima", "atka" },
    { "etak", "etka" },
    { "etaka", "etka" },
    { "itak", "itka" },
    { "itaka", "itka" },
    { "itci", "itka" },
    { "otak", "otka" },
    { "otaka", "otka" },
    { "utak", "utka" },
    { "utaka", "utka" },
    { "utci", "utka" },
    { "utcima", "utka" },
    { "eskan", "eskna" },
    { "tičan", "tični" },
    { "ojsci", "ojska" },
    { "esama", "esma" },
    { "metara", "metra" },
    { "centar", "centra" },
    { "centara", "centra" },
    { "istara", "istra" },
    { "istar", "istra" },
    { "ošću", "osti" },
    { "daba", "dba" },
    { "čcima", "čka" },
    { "čci", "čka" },
    { "mac", "mca" },
    { "maca", "mca" },
    { "naca", "nca" },
    { "nac", "nca" },
    { "voljan", "voljni" },
    { "anaka", "anki" },
    { "vac", "vca" },
    { "vaca", "vca" },
    { "saca", "sca" },
    { "sac", "sca" },
    { "naca", "nca" },
    { "nac", "nca" },
    { "raca", "rca" },
    { "rac", "rca" },
    { "aoca", "alca" },
    { "alaca", "alca" },
    { "alac", "alca" },
    { "elaca", "elca" },
    { "elac", "elca" },
    { "olaca", "olca" },
    { "olac", "olca" },
    { "olce", "olca" },
    { "njac", "njca" },
    { "njaca", "njca" },
    { "ekata", "ekta" },
    { "ekat", "ekta" },
    { "izam", "izma" },
    { "izama", "izma" },
    { "jebe", "jebi" },
    { "baci", "baci" },
    { "ašan", "ašni" }
};