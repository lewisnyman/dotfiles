<?php

// You can create a local cache of all projects checked out using
// --package-handler=git_drupalorg; this can be faster for repeated
// downloads, but can be brittle. See: http://randyfay.com/node/119
$options['cache'] = TRUE;

/**
 * Enable logging and periodic upload of anonymized usage statistics. The Drush
 * maintainers use this data to learn which commands and options are most
 * See the usage-show and usage-send commands.
 */
$options['drush_usage_log'] = TRUE;
$options['drush_usage_send'] = TRUE;

// Notify user via Notification Center (OSX) or libnotify (Linux) when command
// takes more than 30 seconds. See global options for more configuration.
// $options['notify'] = 30;

// Enable verbose mode.
$options['v'] = 1;

// Set a predetermined username and password when using site-install.
$command_specific['site-install'] = array('account-name' => 'admin', 'account-pass' => 'admin');