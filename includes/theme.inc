<?php

/**
 * @file
 * Custom theme hooks.
 */

/**
 * Implements hook_library_info_build().
 *
 * Automatically creates components libraries (Not visible in theme's
 * libraries.yml file). You can directly use the component name as a library,
 * f.x {{ attach_library('project_theme/block') }}.
 *
 * @return array<mixed>
 *   An array of library definitions to register, keyed by library ID. The
 *   library ID will be prefixed with the module name automatically.
 *
 * @see core.libraries.yml
 * @see hook_library_info_alter()
 */
function project_theme_library_info_build(): array {
  $extensions = ['css', 'js'];
  $directory = 'themes/custom/project_theme/build/components';
  $extensions = array_map('preg_quote', $extensions);
  $extensions = implode('|', $extensions);
  if (!is_dir($directory)) {
    return [];
  }
  $file_scan = \Drupal::service('file_system')->scanDirectory($directory, "/{$extensions}$/");
  $libraries = [];
  foreach ($file_scan as $file) {
    $parts = explode('.', $file->filename);
    $extension = end($parts);
    switch ($extension) {
      case 'css':
        $libraries[$file->name][$extension] = [
          'component' => [
            '/' . $file->uri => [],
          ],
        ];
        break;

      case 'js':
        $libraries[$file->name][$extension] = [
          '/' . $file->uri => [],
        ];
        break;
    }
  }
  return $libraries;
}
