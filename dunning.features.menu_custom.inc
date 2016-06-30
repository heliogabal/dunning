<?php
/**
 * @file
 * dunning.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dunning_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-buchhaltungsmenu.
  $menus['menu-buchhaltungsmenu'] = array(
    'menu_name' => 'menu-buchhaltungsmenu',
    'title' => 'Buchhaltungsmenu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Buchhaltungsmenu');

  return $menus;
}
