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
 * Implements hook_flag_default_flags().
 */
function dunning_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bezahlt?".
  $flags['bezahlt_'] = array(
    'entity_type' => 'commerce_order',
    'title' => 'Bezahlt?',
    'global' => 1,
    'types' => array(
      0 => 'commerce_order',
    ),
    'flag_short' => 'Als bezahlt markieren',
    'flag_long' => '',
    'flag_message' => 'bezahlt',
    'unflag_short' => 'Als unbezahlt markieren',
    'unflag_long' => 'unbezahlt',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'administrator' => 0,
      'customer' => 0,
      'backoffice' => 0,
      'pdf' => 0,
      'canceled' => 0,
      'checkout_pane' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'dunning',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

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
    "mail_body" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie innerhalb von 7 Arbeitstagen den noch \\u003Cb\\u003Eoffenen Betrag von [commerce-order:commerce_order_total]\\u003C\\/b\\u003E f\\u00fcr die \\u003Cb\\u003ERechnungsnummer [commerce-order:order-id]\\u003C\\/b\\u003E auf unser Konto:\\r\\n\\u003Cb\\u003EKD-Bank\\r\\nINKOTA-netzwerk e.V.\\r\\nIBAN DE06 3506 0190 1555 0000 10\\r\\nBIC GENODED1DKD\\r\\n\\r\\nBitte vergessen Sie nicht die Angabe Ihrer \\u003Cb\\u003ERechnungsnummer ([commerce-order:order-id])\\u003C\\/b\\u003E. Bitte haben Sie Verst\\u00e4ndnis daf\\u00fcr, dass wir uns nach Ablauf der Frist den R\\u00fccktritt vom Vertrag vorbehalten werden.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift. Sie k\\u00f6nnen Sich auch unter https:\\/\\/webshop.inkota.de\\/user anmelden und Ihre Rechnung noch einmal ansehen.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
    "mail_body_plain" : "Sehr geehrte\\/r [user:field-user-anrede] [user:field-user-nachname],\\r\\n\\r\\nsicher haben Sie es \\u00fcbersehen, dass Sie Ihre Rechnung noch nicht bezahlt haben, und wir m\\u00f6chten Sie auf diesem Wege noch einmal daran erinnern.\\r\\n\\r\\nBitte begleichen Sie innerhalb von 7 Arbeitstagen den noch offenen Betrag von [commerce-order:commerce_order_total] f\\u00fcr die Rechnungsnummer [commerce-order:order-id] auf unser Konto:\\r\\nKD-Bank\\r\\nINKOTA-netzwerk e.V.\\r\\nIBAN DE06 3506 0190 1555 0000 10\\r\\nBIC GENODED1DKD\\r\\n\\r\\nBitte vergessen Sie nicht die Angabe Ihrer Rechnungsnummer ([commerce-order:order-id]). Bitte haben Sie Verst\\u00e4ndnis daf\\u00fcr, dass wir uns nach Ablauf der Frist den R\\u00fccktritt vom Vertrag vorbehalten werden.\\r\\n\\r\\nSollte die Zahlung bereits unter einer anderen Angabe als Ihrer Rechnungsnummer erfolgt sein, bitten wir zur weiteren Kl\\u00e4rung um eine kurze Benachrichtigung per Email an hirschel@inkota.de oder o.g. Anschrift. Sie k\\u00f6nnen Sich auch unter https:\\/\\/webshop.inkota.de\\/user anmelden und Ihre Rechnung noch einmal ansehen.\\r\\n\\r\\nMit freundlichen Gr\\u00fc\\u00dfen\\r\\nInkota netzwerk e.V.\\r\\nMonika Hirschel",
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
