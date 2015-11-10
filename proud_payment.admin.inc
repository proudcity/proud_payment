<?php

/**
 * @file
 * Administration functions for the proud_payment module.
 */

/**
 * Menu callback: map settings
 */
function proud_payment_admin_form() {
  $form = array();

  $form['proud_payment_provider'] = array(
    '#type' => 'radios',
    '#title' => t('Payment provider'),
    '#options' => array(
      'stripe' => l('Stripe', 'http://stripe.com', array('attributes' => array('target' => '_blank'))),
      'external' => t('External link'),
    ),
    '#default_value' => variable_get('proud_payment_provider', 'stripe'),
  );

  $form['proud_payment_invoice_api'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Payment invoice api'),
    // @todo: document https://github.com/proudcity/proud/issues/101
    '#default_value' => variable_get('proud_payment_invoice_api', 'http://my.getproudcity.com/api/proudcity/invoice-example'),
  );


  $form['stripe'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stripe settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('You can get your keys from the !link', array('!link' => l('Stripe dashboard', 'https://dashboard.stripe.com/account'))),
    // @todo: make states work here...
    '#states' => array(
      'checked' => array(
        'input[value=stripe]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['stripe']['stripe_status'] = array(
    '#type' => 'radios',
    '#title' => t('Stripe status'),
    '#options' => array(
      'test' => t('Test'),
      'live' => t('Live'),
    ),
    '#default_value' => variable_get('stripe_status', 'test'),
  );

  $form['stripe']['stripe_test_secret'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Test secret key'),
    '#default_value' => variable_get('stripe_test_secret', ''),
  );

  $form['stripe']['stripe_test_publishable'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Test publishable key'),
    '#default_value' => variable_get('stripe_test_publishable', ''),
  );

  $form['stripe']['stripe_live_secret'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Live secret key'),
    '#default_value' => variable_get('stripe_live_secret', ''),
  );

  $form['stripe']['stripe_live_publishable'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Live publishable key'),
    '#default_value' => variable_get('stripe_live_publishable', ''),
  );



  return system_settings_form($form);
}
