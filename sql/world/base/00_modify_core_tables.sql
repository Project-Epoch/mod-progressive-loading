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

-- Disables
CALL CreateColumnIfNotExists('disables', 'patch_min', 'smallint', '4125');
CALL CreateColumnIfNotExists('disables', 'patch_max', 'smallint', '12340');
ALTER TABLE disables DROP PRIMARY KEY;
ALTER TABLE disables ADD PRIMARY KEY (`sourceType`, `entry`, `patch_min`, `patch_max`);

-- Game Events
CALL CreateColumnIfNotExists('game_event', 'patch', 'smallint', '4125');
ALTER TABLE game_event DROP PRIMARY KEY;
ALTER TABLE game_event ADD PRIMARY KEY (`eventEntry`, `patch`);

-- Holiday Dates
CALL CreateColumnIfNotExists('holiday_dates', 'patch_min', 'smallint', '4125');
CALL CreateColumnIfNotExists('holiday_dates', 'patch_max', 'smallint', '12340');
CALL CreateColumnIfNotExists('holiday_dates', 'comment', 'varchar(255)', "''");
ALTER TABLE holiday_dates DROP PRIMARY KEY;
ALTER TABLE holiday_dates ADD PRIMARY KEY (`id`, `date_id`, `patch_min`, `patch_max`);

-- Area Trigger Teleport
CALL CreateColumnIfNotExists('areatrigger_teleport', 'patch', 'smallint', '4125');
ALTER TABLE areatrigger_teleport DROP PRIMARY KEY;
ALTER TABLE areatrigger_teleport ADD PRIMARY KEY (`ID`, `patch`);

-- Battleground Template
CALL CreateColumnIfNotExists('battleground_template', 'patch', 'smallint', '4125');
ALTER TABLE battleground_template DROP PRIMARY KEY;
ALTER TABLE battleground_template ADD PRIMARY KEY (`ID`, `patch`);

-- Quest Template
CALL CreateColumnIfNotExists('quest_template', 'patch', 'smallint', '4125');
ALTER TABLE quest_template DROP PRIMARY KEY;
ALTER TABLE quest_template ADD PRIMARY KEY (`ID`, `patch`);

-- Quest Mail Sender
CALL CreateColumnIfNotExists('quest_mail_sender', 'patch', 'smallint', '4125');
ALTER TABLE quest_mail_sender DROP PRIMARY KEY;
ALTER TABLE quest_mail_sender ADD PRIMARY KEY (`QuestId`, `patch`);

-- Quest Offer Reward
CALL CreateColumnIfNotExists('quest_offer_reward', 'patch', 'smallint', '4125');
ALTER TABLE quest_offer_reward DROP PRIMARY KEY;
ALTER TABLE quest_offer_reward ADD PRIMARY KEY (`ID`, `patch`);

-- Quest Request Items
CALL CreateColumnIfNotExists('quest_request_items', 'patch', 'smallint', '4125');
ALTER TABLE quest_request_items DROP PRIMARY KEY;
ALTER TABLE quest_request_items ADD PRIMARY KEY (`ID`, `patch`);

-- Quest Offer Reward
CALL CreateColumnIfNotExists('quest_offer_reward', 'patch', 'smallint', '4125');
ALTER TABLE quest_offer_reward DROP PRIMARY KEY;
ALTER TABLE quest_offer_reward ADD PRIMARY KEY (`ID`, `patch`);

-- End Script
DROP PROCEDURE IF EXISTS `CreateColumnIfNotExists`; 