// Copyright 2018 João Pedro Assis
#define CATCH_CONFIG_MAIN
#include "../../include/Fabrica.h"
#include "../include/catch.hpp"
#include "../../include/Head.h"
#include "../../include/Player.h"

TEST_CASE("Compile") {
    SECTION("Compile") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("Class Fabrica") {
    SECTION("Check inheritance") {
        Fabrica fbrc(30, 40, PEDRA);
        int x, y;
        x = fbrc.get_x();
        y = fbrc.get_y();

        fbrc.set_vida(VIDA_INICIAL_FABRICA);

        REQUIRE(x == 30);
        REQUIRE(y == 40);
        REQUIRE(fbrc.get_vida() == VIDA_INICIAL_FABRICA);

        fbrc.set_x(50);
        fbrc.set_y(60);

        x = fbrc.get_x();
        y = fbrc.get_y();

        REQUIRE(x == 50);
        REQUIRE(y == 60);
        REQUIRE(fbrc.get_vida() == 100);
    }
    SECTION("Get/Set") {
        Fabrica fbrc(30, 40, PEDRA);
        fbrc.set_nivel(10);
        fbrc.set_tempoEspera(25);

        int nivel, tempoEspera;
        nivel = fbrc.get_nivel();
        tempoEspera = fbrc.get_tempoEspera();

        REQUIRE(nivel == 10);
        REQUIRE(tempoEspera == 25);
    }
    SECTION("New Constructors") {
        Fabrica fbrc(30, 40, PEDRA);
        SECTION("Fabrica variables") {
            REQUIRE(fbrc.tipo == PEDRA);
            REQUIRE(fbrc.tempoEspera == TEMPO_ESPERA_INICIAL_FABRICA);
            REQUIRE(fbrc.nivel == 1);
            REQUIRE(fbrc.get_vida() == VIDA_INICIAL_FABRICA);
        }
        SECTION("Unidade variables") {
            REQUIRE(fbrc.vida == fbrc.nivel*10);
            REQUIRE(fbrc.dano == fbrc.nivel*5);
            REQUIRE(fbrc.velocidade == fbrc.nivel*2);
        }
    }
}

TEST_CASE("Verify upgrade") {
        Fabrica fbrc(30, 40, TESOURA);
        Player player;
    SECTION("Can Upgrade") {
        REQUIRE(fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
         player.getDinheiro()) == true);
        player.setDinheiro(100);
        /*REQUIRE(fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
         player.getDinheiro()) == false);*/
    }
}

/*
TEST_CASE("Gera Unidade") {
        Fabrica fbrc(30, 40, PEDRA);
        Unidade* unidade1 = fbrc.geraUnidade(2, 3);
        Unidade* unidade2 = fbrc.geraUnidade(2, 3);
        int din = 1000;
        unidade1 = fbrc.geraUnidade(3, 2);

    SECTION("First Gera Unidades") {
        REQUIRE(unidade1->getDano() ==fbrc.dano);
        REQUIRE(unidade1->getVida() == fbrc.vida);
        REQUIRE(unidade1->getVelocidade() == fbrc.velocidade);
        REQUIRE(unidade1->tipo == fbrc.tipo);
    }
    SECTION("Gera after Update Fabrica") {
        fbrc.upgrade_fabrica(&din);
        unidade2 = fbrc.geraUnidade(3, 2);
        REQUIRE(unidade2->getDano() == fbrc.dano);
        REQUIRE(unidade2->getVida() == fbrc.vida);
        REQUIRE(unidade2->getVelocidade() == fbrc.velocidade);
        REQUIRE(unidade2->tipo == fbrc.tipo);
         checando que a unidade1 possui valores antigos

        REQUIRE_FALSE(unidade1->getDano() ==fbrc.dano);
        REQUIRE_FALSE(unidade1->getVida() == fbrc.vida);
        REQUIRE_FALSE(unidade1->getVelocidade() == fbrc.velocidade);
    }
} */

TEST_CASE("Upgrade Fabrica") {
    Fabrica fbrc(30, 40, PEDRA);
    Player player;
    SECTION("with enough money") {
        if (fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
         player.getDinheiro())) {
            fbrc.upgrade_fabrica(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("Not enough Money") {
        player.setDinheiro(7);
        if (fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
         player.getDinheiro())) {
            fbrc.upgrade_fabrica(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("New attributes") {
        if (fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
         player.getDinheiro())) {
            fbrc.upgrade_fabrica(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
            SECTION("Life/Unidades attributes") {
                REQUIRE(fbrc.vida == fbrc.nivel*10);
                REQUIRE(fbrc.dano == fbrc.nivel*5);
                REQUIRE(fbrc.velocidade == fbrc.nivel*2);
                REQUIRE(fbrc.get_vida() == fbrc.nivel*VIDA_INICIAL_FABRICA);
            }
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("Donti ravi mônei") {
        player.setDinheiro(player.getDinheiro() + 800);
        for (int i = 0; i < 10; i++) {
            int nivel_atual = fbrc.nivel;
            int novo_nivel = fbrc.nivel+1;
            int dinheiro_atual = player.dinheiro;
            int novo_dinheiro = player.dinheiro - fbrc.custo_upgrade_fab;
            if (fbrc.can_upgrade_fabrica(fbrc.custo_upgrade_fab,
             player.getDinheiro())) {
                fbrc.upgrade_fabrica(&player.dinheiro);
                //REQUIRE(fbrc.nivel == novo_nivel);
                //REQUIRE(player.getDinheiro() == novo_dinheiro);
            } else {
                //REQUIRE(fbrc.nivel == nivel_atual);
                //REQUIRE(player.getDinheiro() == dinheiro_atual);
            }
        }
    }
}
