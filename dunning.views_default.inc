<?php
/**
 * @file
 * dunning.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dunning_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'buchhaltung';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Buchhaltung';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gestellte Rechnungen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_commerce_billy_i_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_id' => 'order_id',
    'order_number' => 'order_number',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'commerce_billy_pdf_invoice_link' => 'commerce_billy_pdf_invoice_link',
    'status' => 'status',
    'commerce_order_total' => 'commerce_order_total',
    'field_commerce_billy_i_date_1' => 'field_commerce_billy_i_date_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_billy_pdf_invoice_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Bestellung: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['required'] = TRUE;
  /* Relationship: Flags: bezahlt_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Bezahlt';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bezahlt_';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Bestellung: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['label'] = 'Line items';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Bankbeleg';
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'invoiced' => 'invoiced',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  /* Filter criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';

  /* Display: Offene Rechnungen */
  $handler = $view->new_display('page', 'Offene Rechnungen', 'offene_rechnungen');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Offene Rechnungen';
  $handler->display->display_options['display_description'] = 'In dieser Ansicht werden gestellte Rechnungen angezeigt, die mit Zahlungen abgeglichen werden können.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_commerce_billy_i_date_2',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'commerce_billy_pdf_invoice_link' => 'commerce_billy_pdf_invoice_link',
    'commerce_order_total' => 'commerce_order_total',
    'order_id' => 'order_id',
    'status' => 'status',
    'field_commerce_billy_i_date_1' => 'field_commerce_billy_i_date_1',
    'flagged' => 'flagged',
    'nothing' => 'nothing',
    'field_commerce_billy_i_date_2' => 'field_commerce_billy_i_date_2',
  );
  $handler->display->display_options['style_options']['default'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_name_line' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_billy_pdf_invoice_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '<none>';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'ultrakurz',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items_1']['id'] = 'commerce_line_items_1';
  $handler->display->display_options['fields']['commerce_line_items_1']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_1']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_1']['label'] = 'Bildungsm. Anteil';
  $handler->display->display_options['fields']['commerce_line_items_1']['settings'] = array(
    'view' => 'commerce_line_item_table|block_2',
  );
  $handler->display->display_options['fields']['commerce_line_items_1']['delta_offset'] = '0';
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'SL Anteil';
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'commerce_line_item_table|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  /* Field: Commerce Belegzeile: Spendenbetrag */
  $handler->display->display_options['fields']['commerce_donate_amount']['id'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['table'] = 'field_data_commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['field'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_donate_amount']['label'] = 'Spende';
  $handler->display->display_options['fields']['commerce_donate_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items_2']['id'] = 'commerce_line_items_2';
  $handler->display->display_options['fields']['commerce_line_items_2']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_2']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_2']['label'] = 'Versandkosten';
  $handler->display->display_options['fields']['commerce_line_items_2']['settings'] = array(
    'view' => 'commerce_line_item_table|block_3',
  );
  $handler->display->display_options['fields']['commerce_line_items_2']['delta_offset'] = '0';
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['id'] = 'field_commerce_order_bankbeleg_editable';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['field'] = 'field_commerce_order_bankbeleg_editable';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['label'] = 'Bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'invoiced' => 'invoiced',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['path'] = 'admin/buchhaltung/zahlungen';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Offene Rechnungen';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-buchhaltungsmenu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Buchhaltung';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-buchhaltungsmenu';

  /* Display: Datenexport offen */
  $handler = $view->new_display('views_data_export', 'Datenexport offen', 'datenexport');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Excel-Datei Exportieren';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Rechnungen_offen_%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnr.';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'ultrakurz',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['exclude'] = TRUE;
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Betrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Bildung';
  $handler->display->display_options['fields']['commerce_line_items']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'commerce_line_item_table|block_2',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  /* Field: Bestellung: Line items */
  $handler->display->display_options['fields']['commerce_line_items_1']['id'] = 'commerce_line_items_1';
  $handler->display->display_options['fields']['commerce_line_items_1']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_1']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items_1']['label'] = 'SL';
  $handler->display->display_options['fields']['commerce_line_items_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_line_items_1']['settings'] = array(
    'view' => 'commerce_line_item_table|block_1',
  );
  $handler->display->display_options['fields']['commerce_line_items_1']['delta_offset'] = '0';
  /* Field: Commerce Belegzeile: Spendenbetrag */
  $handler->display->display_options['fields']['commerce_donate_amount']['id'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['table'] = 'field_data_commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['field'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_donate_amount']['label'] = 'Spende';
  $handler->display->display_options['fields']['commerce_donate_amount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_donate_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_donate_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Bestellung: Bankbeleg */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['id'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['field'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['element_label_colon'] = FALSE;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'invoiced' => 'invoiced',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['path'] = 'admin/zahlungen/export';
  $handler->display->display_options['displays'] = array(
    'offene_rechnungen' => 'offene_rechnungen',
    'default' => 0,
    'mahnungen' => 0,
    'bezahlte_rechnungen' => 0,
  );

  /* Display: Mahnungen */
  $handler = $view->new_display('page', 'Mahnungen', 'mahnungen');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mahnungen';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'commerce_billy_pdf_invoice_link' => 'commerce_billy_pdf_invoice_link',
    'commerce_order_total' => 'commerce_order_total',
    'order_id' => 'order_id',
    'field_commerce_billy_i_date_1' => 'field_commerce_billy_i_date_1',
    'flagged' => 'flagged',
    'field_commerce_billy_i_date_2' => 'field_commerce_billy_i_date_2',
    'mail' => 'mail',
    'field_commerce_order_bankbeleg_editable' => 'field_commerce_order_bankbeleg_editable',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_name_line' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_billy_pdf_invoice_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_order_bankbeleg_editable' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Keine Einträge vorhanden';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>Bravo! Momentan gibt es keine unbezahlten Rechnungen, die überfällig wären!</h2>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_mahnsystem' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Mahnungen verschicken',
    ),
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-Mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Bestellung: Bankbeleg */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['id'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['field'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['type'] = 'editable';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'invoiced' => 'invoiced',
    'mahnung_1' => 'mahnung_1',
    'mahnung_2' => 'mahnung_2',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  /* Filter criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator_id'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['label'] = 'Rechnungsdatum (field_commerce_billy_i_date)';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['identifier'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['label'] = 'Rechnungsdatum (field_commerce_billy_i_date)';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['identifier'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['default_date'] = '-7 days';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/buchhaltung/mahnungen';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Mahnungen';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'menu-buchhaltungsmenu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Datenexport Mahnungen */
  $handler = $view->new_display('views_data_export', 'Datenexport Mahnungen', 'views_data_export_mahnungen');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mahnungen';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'mahnungen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Excel-Datei Exportieren';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Rechnungen_Mahnungen_%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnr.';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'ultrakurz',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['exclude'] = TRUE;
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Betrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Belegzeile: Spendenbetrag */
  $handler->display->display_options['fields']['commerce_donate_amount']['id'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['table'] = 'field_data_commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['field'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_donate_amount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_donate_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_donate_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Bestellung: Bankbeleg */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['id'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['field'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['element_label_colon'] = FALSE;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'invoiced' => 'invoiced',
    'mahnung_1' => 'mahnung_1',
    'mahnung_2' => 'mahnung_2',
    'gesperrt' => 'gesperrt',
  );
  /* Filter criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['default_date'] = '-7 days';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['year_range'] = '-1:+1';
  $handler->display->display_options['path'] = 'admin/zahlungen/mahnungen/export';
  $handler->display->display_options['displays'] = array(
    'mahnungen' => 'mahnungen',
    'default' => 0,
    'offene_rechnungen' => 0,
    'bezahlte_rechnungen' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Bezahlte Rechnungen */
  $handler = $view->new_display('page', 'Bezahlte Rechnungen', 'bezahlte_rechnungen');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bezahlte Rechnungen';
  $handler->display->display_options['display_description'] = 'In dieser Ansicht werden bezahlte Rechnungen angezeigt.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'commerce_customer_billing' => 'commerce_customer_billing',
    'commerce_billy_pdf_invoice_link' => 'commerce_billy_pdf_invoice_link',
    'commerce_order_total' => 'commerce_order_total',
    'order_id' => 'order_id',
    'status' => 'status',
    'field_commerce_billy_i_date_1' => 'field_commerce_billy_i_date_1',
    'status_1' => 'status_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_billing' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_billy_pdf_invoice_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Bankbeleg';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Bestellung: Bankbeleg */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['id'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['field'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'completed' => 'completed',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['path'] = 'admin/buchhaltung/rechnungsarchiv';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Bezahlte Rechnungen';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'menu-buchhaltungsmenu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Buchhaltung';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-admin-menu';

  /* Display: Datenexport bezahlte Rechnungen */
  $handler = $view->new_display('views_data_export', 'Datenexport bezahlte Rechnungen', 'views_data_export_bezahlt');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'bezahlte Rechnungen';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'bezahlte_rechnungen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Excel-Datei Exportieren';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Bezahlte_Rechnungen_%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Rechnung als bezahlt markieren',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'ultrakurz',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['exclude'] = TRUE;
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Belegzeile: Spendenbetrag */
  $handler->display->display_options['fields']['commerce_donate_amount']['id'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['table'] = 'field_data_commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['field'] = 'commerce_donate_amount';
  $handler->display->display_options['fields']['commerce_donate_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_donate_amount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_donate_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_donate_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Bestellung: Bankbeleg */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['id'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['field'] = 'field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg']['element_label_colon'] = FALSE;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['sorts']['field_commerce_billy_i_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/zahlungen/bezahlt/export';
  $handler->display->display_options['displays'] = array(
    'bezahlte_rechnungen' => 'bezahlte_rechnungen',
    'default' => 0,
    'offene_rechnungen' => 0,
    'mahnungen' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: gesperrte NutzerInnen */
  $handler = $view->new_display('page', 'gesperrte NutzerInnen', 'gesperrt');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'gesperrte NutzerInnen';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_commerce_billy_i_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'commerce_customer_billing' => 'commerce_customer_billing',
    'commerce_billy_pdf_invoice_link' => 'commerce_billy_pdf_invoice_link',
    'commerce_order_total' => 'commerce_order_total',
    'order_id' => 'order_id',
    'status' => 'status',
    'field_commerce_billy_i_date_1' => 'field_commerce_billy_i_date_1',
    'status_1' => 'status_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_billing' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_billy_pdf_invoice_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Keine Einträge vorhanden';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>Bravo! Momentan gibt es keine unbezahlten Rechnungen, die überfällig wären!</h2>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_benutzer_entsperren' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Rechnungsnummer';
  /* Field: Commerce Kundenprofil: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Name';
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Rechnung PDF';
  /* Field: Bestellung: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Rechnungsbetrag';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Bestellnummer';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Bestellung: Rechnungsdatum */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['id'] = 'field_commerce_billy_i_date_1';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_1']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Bezahlt?';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Rechnungsdatum zur Sortierung */
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['id'] = 'field_commerce_billy_i_date_2';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['ui_name'] = 'Rechnungsdatum zur Sortierung';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date_2']['settings'] = array(
    'format_type' => 'monat',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-Mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['id'] = 'field_commerce_order_bankbeleg_editable';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['table'] = 'field_data_field_commerce_order_bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['field'] = 'field_commerce_order_bankbeleg_editable';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['label'] = 'Bankbeleg';
  $handler->display->display_options['fields']['field_commerce_order_bankbeleg_editable']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'gesperrt' => 'gesperrt',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name oder Rechnungsnummer suchen';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Suche';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['combine']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'commerce_customer_address_name_line' => 'commerce_customer_address_name_line',
    'commerce_order_total' => 'commerce_order_total',
  );
  /* Filter criterion: Bestellung: Rechnungsdatum (field_commerce_billy_i_date) */
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator_id'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['label'] = 'Rechnungsdatum (field_commerce_billy_i_date)';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['identifier'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['label'] = 'Rechnungsdatum (field_commerce_billy_i_date)';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['identifier'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['default_date'] = '-7 days';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/buchhaltung/gesperrt';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'gesperrte NutzerInnen';
  $handler->display->display_options['menu']['weight'] = '12';
  $handler->display->display_options['menu']['name'] = 'menu-buchhaltungsmenu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['buchhaltung'] = array(
    t('Master'),
    t('Gestellte Rechnungen'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Customer profile referenced by commerce_customer_billing'),
    t('Bezahlt'),
    t('Line items'),
    t('- Choose an operation -'),
    t('Rechnung als bezahlt markieren'),
    t('Rechnungsnummer'),
    t('Name'),
    t('Rechnungsdatum'),
    t('Rechnung PDF'),
    t('Rechnungsbetrag'),
    t('Bestellnummer'),
    t('Order status'),
    t('Bezahlt?'),
    t('Bankbeleg'),
    t('Name oder Rechnungsnummer suchen'),
    t('Filtere die Ansicht nach Name oder Rechnungsnummer. Die Eingabe-Taste funktioniert alternativ zum Anwenden-Button'),
    t('Suche'),
    t('Offene Rechnungen'),
    t('In dieser Ansicht werden gestellte Rechnungen angezeigt, die mit Zahlungen abgeglichen werden können.'),
    t('more'),
    t('<none>'),
    t('Bildungsm. Anteil'),
    t('SL Anteil'),
    t('Spende'),
    t('Versandkosten'),
    t('Datenexport offen'),
    t('Rechnungsnr.'),
    t('Datum'),
    t('Betrag'),
    t('Bildung'),
    t('SL'),
    t('Mahnungen'),
    t('Keine Einträge vorhanden'),
    t('<h2>Bravo! Momentan gibt es keine unbezahlten Rechnungen, die überfällig wären!</h2>'),
    t('Mahnungen verschicken'),
    t('E-Mail'),
    t('Status'),
    t('Rechnungsdatum (field_commerce_billy_i_date)'),
    t('Datenexport Mahnungen'),
    t('Spendenbetrag'),
    t('Bezahlte Rechnungen'),
    t('In dieser Ansicht werden bezahlte Rechnungen angezeigt.'),
    t('Datenexport bezahlte Rechnungen'),
    t('bezahlte Rechnungen'),
    t('gesperrte NutzerInnen'),
  );
  $export['buchhaltung'] = $view;

  return $export;
}
