# Installation

This theme is based on the Radix theme. It provides out of the box SASS and JS
compilation with browsersync that is set up for use in this repository with our
Docker + Traefik setup.

## Requirements
* >= node 14

## Installation

We automatically execute these steps on composer install of the project so that
you end up with a fully functional codebase.

```
# Change into theme directory
cd web/themes/custom/theme
# Install dependencies
npm install
# Run mix (if you are just compiling)
npm run dev
# Run watch (if you are doing theme development)
npm run watch
```
