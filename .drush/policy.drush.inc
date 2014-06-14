<?php
/**
 * Implement of drush_hook_COMMAND_validate().
 *
 * Prevent overwriting live or production databases.
 *
 * This file should be local to the machine that initiates the sql-sync command.
 * This also relies on using either the 'live' or 'production' naming convention
 * within drush aliases.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if (strpos($destination, 'live') || strpos($destination, 'production')) {
    return drush_set_error('POLICY_DENY', dt('Per examples/policy.drush.inc, you may never overwrite the production database.'));
  }
}