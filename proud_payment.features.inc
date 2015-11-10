<?php
/**
 * @file
 * proud_payment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function proud_payment_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function proud_payment_node_info() {
  $items = array(
    'payment' => array(
      'name' => t('Payment'),
      'base' => 'node_content',
      'description' => t('Create a new type of payment invoice (similar to a product).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
