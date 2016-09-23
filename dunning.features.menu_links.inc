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

  // Exported menu link: menu-buchhaltungsmenu_buchhaltung:admin/buchhaltung/zahlungen.
  $menu_links['menu-buchhaltungsmenu_buchhaltung:admin/buchhaltung/zahlungen'] = array(
    'menu_name' => 'menu-buchhaltungsmenu',
    'link_path' => 'admin/buchhaltung/zahlungen',
    'router_path' => 'admin/buchhaltung/zahlungen',
    'link_title' => 'Buchhaltung',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'icon' => array(
        'bundle' => 'fontawesome_fontello',
        'icon' => 'icon-euro',
        'position' => 'title_before',
        'breadcrumb' => 0,
        'title_wrapper' => 0,
        'title_wrapper_element' => 'span',
        'title_wrapper_class' => 'title',
      ),
      'identifier' => 'menu-buchhaltungsmenu_buchhaltung:admin/buchhaltung/zahlungen',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
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
    'hidden' => 0,
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
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Buchhaltung');
  t('Mahnungen');
  t('Offene Rechnungen');

  return $menu_links;
}
