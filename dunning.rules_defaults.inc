<?php
/**
 * @file
 * dunning.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dunning_default_rules_configuration() {
  $items = array();
  $items['rules_1_mahnung_verschicken'] = entity_import('rules_config', '{ "rules_1_mahnung_verschicken" : {
      "LABEL" : "Mahnung verschicken",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "inkota" ],
      "REQUIRES" : [ "rules", "pet" ],
      "USES VARIABLES" : { "bestellung" : { "label" : "bestellung", "type" : "commerce_order" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "bestellung" ], "type" : "commerce_order" } },
        { "data_is" : { "data" : [ "bestellung:status" ], "value" : "invoiced" } }
      ],
      "DO" : [
        { "pet_action_send_pet" : {
            "pet_name" : "1_mahnung",
            "to_text" : "[bestellung:mail]",
            "to_account" : [ "" ],
            "account_subs" : [ "bestellung:owner" ],
            "node_subs" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "bestellung:status" ], "value" : "mahnung_1" } },
        { "entity_save" : { "data" : [ "bestellung" ] } }
      ]
    }
  }');
  $items['rules_2_mahnung_verschicken'] = entity_import('rules_config', '{ "rules_2_mahnung_verschicken" : {
      "LABEL" : "2. Mahnung verschicken",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "inkota" ],
      "REQUIRES" : [ "rules", "pet" ],
      "USES VARIABLES" : { "bestellung" : { "label" : "bestellung", "type" : "commerce_order" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "bestellung" ], "type" : "commerce_order" } },
        { "data_is" : { "data" : [ "bestellung:status" ], "value" : "mahnung_1" } }
      ],
      "DO" : [
        { "pet_action_send_pet" : {
            "pet_name" : "_cloned",
            "to_text" : "[bestellung:mail]",
            "to_account" : [ "" ],
            "account_subs" : [ "bestellung:owner" ],
            "node_subs" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "bestellung:status" ], "value" : "mahnung_2" } },
        { "entity_save" : { "data" : [ "bestellung" ] } }
      ]
    }
  }');
  $items['rules_benutzer_sperren'] = entity_import('rules_config', '{ "rules_benutzer_sperren" : {
      "LABEL" : "Benutzer sperren",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "inkota" ],
      "REQUIRES" : [ "rules", "pet" ],
      "USES VARIABLES" : { "bestellung" : { "label" : "bestellung", "type" : "commerce_order" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "bestellung" ], "type" : "commerce_order" } },
        { "data_is" : { "data" : [ "bestellung:status" ], "value" : "mahnung_2" } },
        { "NOT user_is_blocked" : { "account" : [ "bestellung:owner" ] } },
        { "data_is" : { "data" : [ "bestellung:changed" ], "op" : "\\u003C", "value" : "now" } }
      ],
      "DO" : [
        { "pet_action_send_pet" : {
            "pet_name" : "nutzer_sperren",
            "to_text" : "[bestellung:mail]",
            "to_account" : [ "" ],
            "account_subs" : [ "bestellung:owner" ],
            "node_subs" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "bestellung:status" ], "value" : "gesperrt" } },
        { "entity_save" : { "data" : [ "bestellung" ] } },
        { "user_block" : { "account" : [ "bestellung:owner" ] } }
      ]
    }
  }');
  $items['rules_bestellung_abschlie_en_wenn_rechnung_bezahlt'] = entity_import('rules_config', '{ "rules_bestellung_abschlie_en_wenn_rechnung_bezahlt" : {
      "LABEL" : "Bestellung abschlie\\u00dfen, wenn Rechnung bezahlt",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "inkota" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_bezahlt_" : [] },
      "DO" : [
        { "component_rules_commerce_order_status_completed" : { "order" : [ "flagged-commerce-order" ] } },
        { "entity_save" : { "data" : [ "flagged-commerce-order" ] } }
      ]
    }
  }');
  $items['rules_mahnsystem'] = entity_import('rules_config', '{ "rules_mahnsystem" : {
      "LABEL" : "Mahnsystem",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "inkota" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "bestellung" : { "label" : "Bestellung", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "component_rules_benutzer_sperren" : { "bestellung" : [ "bestellung" ] } },
        { "component_rules_2_mahnung_verschicken" : { "bestellung" : [ "bestellung" ] } },
        { "component_rules_1_mahnung_verschicken" : { "bestellung" : [ "bestellung" ] } }
      ]
    }
  }');
  return $items;
}
