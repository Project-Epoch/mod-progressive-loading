#
# Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
#

# Add scripts in project
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/World/StartUp.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Player/Welcome.cpp")

# Conditions
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Conditions/PatchCondition.cpp")

# Loaders
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/CreatureLoader.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/GameObjectLoader.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/ItemLoader.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/TransportLoader.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/DisablesLoader.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Loaders/GameEventLoader.cpp")

# Add scripts to script loader
AC_ADD_SCRIPT_LOADER("ModProgressiveLoading" "${CMAKE_CURRENT_LIST_DIR}/src/mod_progressive_loading_loader.h")

# Add config file
AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/mod-progressive-loading.conf.dist")
