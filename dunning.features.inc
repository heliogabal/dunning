<?php
/**
 * @file
 * dunning.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dunning_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_pet().
 */
function dunning_default_pet() {
  $items = array();
  $items['1_mahnung'] = entity_import('pet', '{
    "name" : "1_mahnung",
    "title" : "1. Mahnung",
    "subject" : "Zahlungserinnerung",
    "mail_body" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie in den n\\u00e4chsten 7 Tagen den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "mail_body_plain" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie in den n\\u00e4chsten 7 Tagen den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : ""
  }');
  $items['_cloned'] = entity_import('pet', '{
    "name" : "_cloned",
    "title" : "2. Mahnung",
    "subject" : "2. Zahlungserinnerung",
    "mail_body" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie in den n\\u00e4chsten 7 Tagen den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "mail_body_plain" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie in den n\\u00e4chsten 7 Tagen den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : ""
  }');
  $items['nutzer_sperren'] = entity_import('pet', '{
    "name" : "nutzer_sperren",
    "title" : "s\\u00e4umigen Nutzer sperren",
    "subject" : "Ihr INKOTA webshop Konto wurde deaktiviert.",
    "mail_body" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nLeider haben Sie auf unsere bisherigen Zahlungserinnerungen nicht reagiert. Wir sehen uns daher gezwungen, Ihr Konto im INKOTA webshop bis auf weiteres zu sperren.\\r\\n\\r\\nUm Ihr Konto wieder zu aktivieren, \\u00fcberweisen Sie bitte den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "mail_body_plain" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nLeider haben Sie auf unsere bisherigen Zahlungserinnerungen nicht reagiert. Wir sehen uns daher gezwungen, Ihr Konto im INKOTA webshop bis auf weiteres zu sperren.\\r\\n\\r\\nUm Ihr Konto wieder zu aktivieren, \\u00fcberweisen Sie bitte den noch offenen Betrag (Anlage Rechnungskopie) auf unser Konto bei der KD Bank. Bitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : ""
  }');
  return $items;
}
