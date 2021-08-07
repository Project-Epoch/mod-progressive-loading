DROP PROCEDURE IF EXISTS `CreateColumnIfNotExists`;

DELIMITER $$

CREATE PROCEDURE `CreateColumnIfNotExists` (`@TABLE` VARCHAR(100), `@COLUMN` VARCHAR(100), `@TYPE` VARCHAR(100), `@DEFAULT` VARCHAR(100))
`CreateColumnIfNotExists`: BEGIN
    DECLARE `@EXISTS` INT UNSIGNED DEFAULT 0;

    SELECT COUNT(*) INTO `@EXISTS`
    FROM `information_schema`.`columns`
    WHERE (
        `TABLE_SCHEMA` = DATABASE()
        AND `TABLE_NAME` = `@TABLE`
        AND `COLUMN_NAME` = `@COLUMN`
    );

    IF (`@EXISTS` < 1) THEN
        SET @SQL = CONCAT(
            'ALTER TABLE `', 
            `@TABLE`, 
            '` ADD ', 
            `@COLUMN`, 
            ' ',
            `@TYPE`,
            ' DEFAULT ',
            `@DEFAULT`,
            ';'
        );

        PREPARE query FROM @SQL;
        EXECUTE query;
    END IF;
END $$

DELIMITER ;

-- Forbidden Items
DROP TABLE IF EXISTS `forbidden_items`;
CREATE TABLE `forbidden_items` (
  `entry` mediumint(8) NOT NULL,
  `patch` smallint(5) DEFAULT 4125,
  `after_or_before` tinyint(1) DEFAULT 0,
  PRIMARY KEY (`entry`, `after_or_before`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Creature Template
CALL CreateColumnIfNotExists('creature_template', 'patch', 'smallint', '4125');
ALTER TABLE creature_template DROP PRIMARY KEY;
ALTER TABLE creature_template ADD PRIMARY KEY (`entry`, `patch`);

-- Creature Template Addon
CALL CreateColumnIfNotExists('creature_template_addon', 'patch', 'smallint', '4125');
ALTER TABLE creature_template_addon DROP PRIMARY KEY;
ALTER TABLE creature_template_addon ADD PRIMARY KEY (`entry`, `patch`);

-- Creature Template Spells
CALL CreateColumnIfNotExists('creature_template_spell', 'patch', 'smallint', '4125');
ALTER TABLE creature_template_spell DROP PRIMARY KEY;
ALTER TABLE creature_template_spell ADD PRIMARY KEY (`CreatureID`, `Index`, `patch`);

-- Creature Template Resistance
CALL CreateColumnIfNotExists('creature_template_resistance', 'patch', 'smallint', '4125');
ALTER TABLE creature_template_resistance DROP PRIMARY KEY;
ALTER TABLE creature_template_resistance ADD PRIMARY KEY (`CreatureID`, `School`, `patch`);

-- Creature Equip Template
CALL CreateColumnIfNotExists('creature_equip_template', 'patch', 'smallint', '4125');
ALTER TABLE creature_equip_template DROP PRIMARY KEY;
ALTER TABLE creature_equip_template ADD PRIMARY KEY (`CreatureID`, `ID`, `patch`);

-- Creature
CALL CreateColumnIfNotExists('creature', 'patch_min', 'smallint', '4125');
CALL CreateColumnIfNotExists('creature', 'patch_max', 'smallint', '12340');

-- Creature Addon
CALL CreateColumnIfNotExists('creature_addon', 'patch', 'smallint', '4125');
ALTER TABLE creature_addon DROP PRIMARY KEY;
ALTER TABLE creature_addon ADD PRIMARY KEY (`guid`, `patch`);

-- Game Object Template
CALL CreateColumnIfNotExists('gameobject_template', 'patch', 'smallint', '4125');
ALTER TABLE gameobject_template DROP PRIMARY KEY;
ALTER TABLE gameobject_template ADD PRIMARY KEY (`entry`, `patch`);

-- Game Object Template Addon
CALL CreateColumnIfNotExists('gameobject_template_addon', 'patch', 'smallint', '4125');
ALTER TABLE gameobject_template_addon DROP PRIMARY KEY;
ALTER TABLE gameobject_template_addon ADD PRIMARY KEY (`entry`, `patch`);

-- Game Object
CALL CreateColumnIfNotExists('gameobject', 'patch_min', 'smallint', '4125');
CALL CreateColumnIfNotExists('gameobject', 'patch_max', 'smallint', '12340');

-- Game Object Addon
CALL CreateColumnIfNotExists('gameobject_addon', 'patch', 'smallint', '4125');
ALTER TABLE gameobject_addon DROP PRIMARY KEY;
ALTER TABLE gameobject_addon ADD PRIMARY KEY (`guid`, `patch`);

-- Item Template
CALL CreateColumnIfNotExists('item_template', 'patch', 'smallint', '4125');
ALTER TABLE item_template DROP PRIMARY KEY;
ALTER TABLE item_template ADD PRIMARY KEY (`entry`, `patch`);

-- Transports
CALL CreateColumnIfNotExists('transports', 'patch', 'smallint', '4125');

-- End Script
DROP PROCEDURE IF EXISTS `CreateColumnIfNotExists`; 