#
# Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
#

# Add scripts in project


# Add scripts to script loader
AC_ADD_SCRIPT_LOADER("ModProgressiveLoading" "${CMAKE_CURRENT_LIST_DIR}/src/mod_progressive_loading_loader.h")

# Add config file
AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/mod-progressive-loading.conf.dist")
