<?php
/**
 * @file
 * dunning.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dunning_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-buchhaltungsmenu_bezahlte-rechnungen:admin/buchhaltung/rechnungsarchiv.
  $menu_links['menu-buchhaltungsmenu_bezahlte-rechnungen:admin/buchhaltung/rechnungsarchiv'] = array(
    'menu_name' => 'menu-buchhaltungsmenu',
    'link_path' => 'admin/buchhaltung/rechnungsarchiv',
    'router_path' => 'admin/buchhaltung/rechnungsarchiv',
    'link_title' => 'Bezahlte Rechnungen',
    'options' => array(
      'identifier' => 'menu-buchhaltungsmenu_bezahlte-rechnungen:admin/buchhaltung/rechnungsarchiv',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'menu-buchhaltungsmenu_buchhaltung:admin/buchhaltung',
  );
  // Exported menu link: menu-buchhaltungsmenu_mahnungen:admin/buchhaltung/mahnungen.
  $menu_links['menu-buchhaltungsmenu_mahnungen:admin/buchhaltung/mahnungen'] = array(
    'menu_name' => 'menu-buchhaltungsmenu',
    'link_path' => 'admin/buchhaltung/mahnungen',
    'router_path' => 'admin/buchhaltung/mahnungen',
    'link_title' => 'Mahnungen',
    'options' => array(
      'icon' => array(
        'icon' => '',
        'position' => 'title_before',
        'title_wrapper_element' => 'span',
        'title_wrapper_class' => 'title',
        'breadcrumb' => 0,
        'title_wrapper' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-buchhaltungsmenu_mahnungen:admin/buchhaltung/mahnungen',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-buchhaltungsmenu_offene-rechnungen:admin/buchhaltung/zahlungen.
  $menu_links['menu-buchhaltungsmenu_offene-rechnungen:admin/buchhaltung/zahlungen'] = array(
    'menu_name' => 'menu-buchhaltungsmenu',
    'link_path' => 'admin/buchhaltung/zahlungen',
    'router_path' => 'admin/buchhaltung/zahlungen',
    'link_title' => 'Offene Rechnungen',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'icon' => array(
        'icon' => '',
        'position' => 'title_before',
        'title_wrapper_element' => 'span',
        'title_wrapper_class' => 'title',
        'breadcrumb' => 0,
        'title_wrapper' => 0,
      ),
      'identifier' => 'menu-buchhaltungsmenu_offene-rechnungen:admin/buchhaltung/zahlungen',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bezahlte Rechnungen');
  t('Mahnungen');
  t('Offene Rechnungen');

  return $menu_links;
}
