<?php

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function prepareinstall_drush_command() {
  $items = array();

  $items['prepare-install'] = array(
    'description' => "Prepares a Drupal site for installation.",
    'aliases' => array('pi'),
    // No bootstrap at all.
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Implements drush_hook_COMMAND().
 *
 * The command callback is where the action takes place.
 *
 * The function name should be same as command name but with dashes turned to
 * underscores and 'drush_commandfile_' prepended, where 'commandfile' is
 * taken from the file 'commandfile.drush.inc', which in this case is
 * 'sandwich'. Note also that a simplification step is also done in instances
 * where the commandfile name is the same as the beginning of the command name,
 * "drush_example_example_foo" is simplified to just "drush_example_foo".
 * To also implement a hook that is called before your command, implement
 * "drush_hook_pre_example_foo".  For a list of all available hooks for a
 * given command, run drush in --debug mode.
 *
 * If for some reason you do not want your hook function to be named
 * after your command, you may define a 'callback' item in your command
 * object that specifies the exact name of the function that should be
 * called.
 *
 * In this function, all of Drupal's API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_prepareinstall_prepare_install() {
	$drupal_root = drush_get_context('DRUSH_DRUPAL_ROOT');
	drush_copy_dir($drupal_root . DIRECTORY_SEPARATOR . 'default.settings.php', $drupal_root . DIRECTORY_SEPARATOR . 'settings.php', TRUE);
  drush_mkdir($drupal_root . '/files');
  chmod($drupal_root . DIRECTORY_SEPARATOR . 'settings.php', 0666);
  chmod($drupal_root . DIRECTORY_SEPARATOR . 'files', 0777);
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'. This hook is optional. If a command
 * does not implement this hook, the command's description is used instead.
 *
 * This hook is also used to look up help metadata, such as help
 * category title and summary.  See the comments below for a description.
 */
function prepare_install_drush_help($section) {
  switch ($section) {
    case 'drush:prepare-install':
      return dt("This commands sets up a new settings.php with the correct permissions and ensures the file system is writeable.");
  }
}
