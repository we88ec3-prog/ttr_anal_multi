# T16-136 — KR 主線任務結構化索引（可匯出 JSON）

- **唯一內容來源**：T16-136 同時提交之原始 `Table/QuestInfo.xml`、`Table/SceneList.xml`、`Event/SceneList.xml` 直接解析記錄與來源 SHA；完整說明、BIN VA/hash、資料保真界線與任務範圍見該正式研究 Markdown。
- 本 JSON 列出 **25 筆主線及 6 筆教程獨立任務**，包含韓文原名、原始 giver/finisher/town/field/level、Demands、原始 Reward type/value、原始 Chapter/sceneIdx/funcName。缺失的 XML Action node 保留 `null`，**不能擅自填上預設值**。
- 以下是可直接另存為 `.json` 的原生索引資料；將程式區塊內內容複製到 UTF-8 `.json` 即可匯入。資料為資源讀值，不代表 T01 FULL-PASS、S00 已核准 SPEC、原版 Server 實際規則或實機測試。

```json
{
  "schema": "T16-136-kr-main-story-resource-inventory-v1",
  "disclaimer": "Static KR resource data; Chinese translation and original Server runtime pairing not claimed; source-extracted field names preserved.",
  "original_sources_sha256": {
    "Tartaros.bin": "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
    "Table.stp": "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442",
    "Event.stp": "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
  },
  "decoded_xml_sha256": {
    "Table/QuestInfo.xml": "5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60",
    "Table/QuestTalk.xml": "b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28",
    "Table/SceneList.xml": "1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037",
    "Event/SceneList.xml": "8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25"
  },
  "towns": {
    "0": {
      "name_kr": "레나르트"
    },
    "1": {
      "name_kr": "핀더스",
      "map_title": "Town_01_Phindous.dds"
    },
    "2": {
      "name_kr": "알스메르",
      "map_title": "Town_02_Alsmeer.dds"
    }
  },
  "main_quest_ids_ordered": [
    14,
    16,
    15,
    117,
    118,
    119,
    120,
    121,
    122,
    123,
    124,
    131,
    132,
    133,
    134,
    135,
    136,
    137,
    138,
    139,
    140,
    141,
    142,
    143,
    144
  ],
  "tutorial_non_linked_quest_ids": [
    1002,
    2742,
    2743,
    2744,
    2745,
    2746
  ],
  "main_quest_entries": [
    {
      "quest_id": 14,
      "quest_title_kr": "튜토리얼-이실리아",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": 18,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": {
        "type": "1"
      },
      "complete_action": {
        "type": "1"
      },
      "rewards_etc": [],
      "chapters": []
    },
    {
      "quest_id": 16,
      "quest_title_kr": "튜토리얼-핑코파파",
      "type": 2,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [
        14
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "50"
        }
      ],
      "chapters": []
    },
    {
      "quest_id": 15,
      "quest_title_kr": "핀더스 마을로",
      "type": 2,
      "subtype": 1,
      "town_id": 5,
      "field_id": 19,
      "level": 1,
      "giver_npc_id": 10338,
      "giver_name_kr": "테티스",
      "finisher_npc_id": 10338,
      "finisher_name_kr": "테티스",
      "demands": [
        16
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "2800"
        },
        {
          "type": 4,
          "value": "468"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Square_Tutorial01",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "scenario_tuto1_1",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "pindos_talkevent",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "scenario_tuto2_1",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 117,
      "quest_title_kr": "사소한 소동",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10002,
      "giver_name_kr": "라제드",
      "finisher_npc_id": 10002,
      "finisher_name_kr": "라제드",
      "demands": [
        15
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "710"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_LittleTrouble",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 118,
      "quest_title_kr": "유리와 라제드",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": 28,
      "level": 5,
      "giver_npc_id": 10047,
      "giver_name_kr": "유리",
      "finisher_npc_id": 10047,
      "finisher_name_kr": "유리",
      "demands": [
        117
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_YuriandRazed",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 119,
      "quest_title_kr": "유리와 라제드 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": 26,
      "level": 5,
      "giver_npc_id": 10047,
      "giver_name_kr": "유리",
      "finisher_npc_id": 10047,
      "finisher_name_kr": "유리",
      "demands": [
        118
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "5850"
        },
        {
          "type": 3,
          "value": "40"
        },
        {
          "type": 4,
          "value": "900"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_YuriandRazed_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Phindous_YuriandRazed_Stage",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Phindous_YuriandRazed_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Phindous_YuriandRazed_BossClear",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Phindous_YuriandRazed_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 120,
      "quest_title_kr": "세네레프 산의 귀신 나무",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": null,
      "level": 8,
      "giver_npc_id": 10008,
      "giver_name_kr": "한슨",
      "finisher_npc_id": 10008,
      "finisher_name_kr": "한슨",
      "demands": [
        119
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1,
            2,
            3
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_Senerep_TalkEvent",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Phindous_Senerep_TalkEvent2",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Phindous_Senerep_TalkEvent3",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 121,
      "quest_title_kr": "라제드 구출",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": null,
      "level": 9,
      "giver_npc_id": 10002,
      "giver_name_kr": "라제드",
      "finisher_npc_id": 10002,
      "finisher_name_kr": "라제드",
      "demands": [
        120
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_RazedSave_TalkEvent",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 122,
      "quest_title_kr": "라제드 구출 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": 27,
      "level": 8,
      "giver_npc_id": 10002,
      "giver_name_kr": "라제드",
      "finisher_npc_id": 10002,
      "finisher_name_kr": "라제드",
      "demands": [
        121
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "9686"
        },
        {
          "type": 3,
          "value": "40"
        },
        {
          "type": 4,
          "value": "918"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_RazedSave_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Phindous_RazedSave_Stage",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Phindous_RazedSave_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Phindous_RazedSave_BossClear",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Phindous_RazedSave_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 123,
      "quest_title_kr": "의식의 밤",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": null,
      "level": 9,
      "giver_npc_id": 10048,
      "giver_name_kr": "유리",
      "finisher_npc_id": 10048,
      "finisher_name_kr": "유리",
      "demands": [
        122
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_NightofRitual_Talk_Event",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 124,
      "quest_title_kr": "의식의 밤 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": 17,
      "level": 9,
      "giver_npc_id": 10048,
      "giver_name_kr": "유리",
      "finisher_npc_id": 10048,
      "finisher_name_kr": "유리",
      "demands": [
        123
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "13086"
        },
        {
          "type": 3,
          "value": "40"
        },
        {
          "type": 4,
          "value": "1440"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 1,
          "chapter_town_id": 1,
          "chapter_name_kr": "의식의 밤",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5,
            6,
            7
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_NightofRitual_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Phindous_NightofRitual_Stage",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Phindous_NightofRitual_Stage02",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Phindous_NightofRitual_Stage03",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Phindous_NightofRitual_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 6,
              "func_name": "Phindous_NightofRitual_Clear",
              "end_behavior": 0
            },
            {
              "scene_idx": 7,
              "func_name": "Phindous_NightofRitual_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 131,
      "quest_title_kr": "알스메르 마을 가는 길",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": null,
      "level": 10,
      "giver_npc_id": 10002,
      "giver_name_kr": "라제드",
      "finisher_npc_id": 10002,
      "finisher_name_kr": "라제드",
      "demands": [
        124
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_pathofAlsmeer_Talkevent",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 132,
      "quest_title_kr": "알스메르 마을 가는 길 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 1,
      "field_id": 28,
      "level": 10,
      "giver_npc_id": 10002,
      "giver_name_kr": "라제드",
      "finisher_npc_id": 10002,
      "finisher_name_kr": "라제드",
      "demands": [
        131
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "15850"
        },
        {
          "type": 3,
          "value": "40"
        },
        {
          "type": 4,
          "value": "1440"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Phindous_pathofAlsmeer_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Phindous_pathofAlsmeer_Stage",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Phindous_pathofAlsmeer_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Phindous_pathofAlsmeer_Boss_Clear",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Phindous_pathofAlsmeer_Boss_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 133,
      "quest_title_kr": "정의의 사도",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 21,
      "level": 10,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        132
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Justice_Talk01",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 134,
      "quest_title_kr": "정의의 사도 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 21,
      "level": 10,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        133
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "19210"
        },
        {
          "type": 4,
          "value": "1548"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Justice_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_Justice_Clear",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 135,
      "quest_title_kr": "살로만 족의 습격",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 29,
      "level": 12,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        134
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_SalomanAttack_Talkevent",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_SalomanAttack_Talkevent2",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 136,
      "quest_title_kr": "살로만 족의 습격 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 29,
      "level": 12,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        135
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "27690"
        },
        {
          "type": 3,
          "value": "100"
        },
        {
          "type": 4,
          "value": "1656"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_SalomanAttack_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_SalomanAttack_Clear",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 137,
      "quest_title_kr": "보리 창고 탈환",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 30,
      "level": 13,
      "giver_npc_id": 10005,
      "giver_name_kr": "케인",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        136
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Barley_TalkEvent",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 138,
      "quest_title_kr": "보리 창고 탈환 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 30,
      "level": 13,
      "giver_npc_id": 10005,
      "giver_name_kr": "케인",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        137
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "33640"
        },
        {
          "type": 3,
          "value": "150"
        },
        {
          "type": 4,
          "value": "1764"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5,
            6
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Barley_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_Barley_Stage01",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Alsmeer_Barley_Stage02",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Alsmeer_Barley_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Alsmeer_Barley_Boss_Clear",
              "end_behavior": 0
            },
            {
              "scene_idx": 6,
              "func_name": "Alsmeer_Barley_Boss_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 139,
      "quest_title_kr": "어부지리",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": null,
      "level": 14,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        138
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2,
            3
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Fish_TalkEvent1",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_Fish_TalkEvent2",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Alsmeer_Fish_TalkEvent3",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 140,
      "quest_title_kr": "어부지리 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 31,
      "level": 14,
      "giver_npc_id": 10053,
      "giver_name_kr": "쿠치",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        139
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "39210"
        },
        {
          "type": 3,
          "value": "150"
        },
        {
          "type": 4,
          "value": "1872"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2,
            3
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Fish_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_Fish_Stage01",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Alsmeer_Fish_Clear",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 141,
      "quest_title_kr": "살로만 행진곡",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": null,
      "level": 15,
      "giver_npc_id": 10005,
      "giver_name_kr": "케인",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        140
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Donjuan_Talk01",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 142,
      "quest_title_kr": "살로만 행진곡 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 20,
      "level": 15,
      "giver_npc_id": 10005,
      "giver_name_kr": "케인",
      "finisher_npc_id": 10005,
      "finisher_name_kr": "케인",
      "demands": [
        141
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "45720"
        },
        {
          "type": 3,
          "value": "150"
        },
        {
          "type": 4,
          "value": "1980"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 2,
          "chapter_town_id": 2,
          "chapter_name_kr": "복면 K",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_Donjuan_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_Donjuan_Stage01",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Alsmeer_Donjuan_Stage02",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Alsmeer_Donjuan_Stage03",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Alsmeer_Donjuan_Stage04",
              "end_behavior": 0
            },
            {
              "scene_idx": 6,
              "func_name": "Alsmeer_Donjuan_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 7,
              "func_name": "Alsmeer_Donjuan_Boss_Clear",
              "end_behavior": 0
            },
            {
              "scene_idx": 8,
              "func_name": "Alsmeer_Donjuan_Boss_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 143,
      "quest_title_kr": "로트루아 가는 길",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": null,
      "level": 15,
      "giver_npc_id": 10012,
      "giver_name_kr": "데이지",
      "finisher_npc_id": 10012,
      "finisher_name_kr": "데이지",
      "demands": [
        142
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": [
        {
          "chapter_idx": 3,
          "chapter_town_id": 3,
          "chapter_name_kr": "아델린 여신의 이야기",
          "scene_indices_ordered": [
            1
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_PathofRotrua_TalkEvent",
              "end_behavior": 0
            }
          ]
        }
      ]
    },
    {
      "quest_id": 144,
      "quest_title_kr": "로트루아 가는 길 (전투)",
      "type": 2,
      "subtype": 1,
      "town_id": 2,
      "field_id": 22,
      "level": 15,
      "giver_npc_id": 10012,
      "giver_name_kr": "데이지",
      "finisher_npc_id": 10012,
      "finisher_name_kr": "데이지",
      "demands": [
        143
      ],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "35024"
        },
        {
          "type": 3,
          "value": "150"
        },
        {
          "type": 4,
          "value": "1980"
        }
      ],
      "chapters": [
        {
          "chapter_idx": 3,
          "chapter_town_id": 3,
          "chapter_name_kr": "아델린 여신의 이야기",
          "scene_indices_ordered": [
            1,
            2,
            3,
            4,
            5
          ],
          "scenes": [
            {
              "scene_idx": 1,
              "func_name": "Alsmeer_PathofRotrua_Blank",
              "end_behavior": 0
            },
            {
              "scene_idx": 2,
              "func_name": "Alsmeer_PathofRotrua_Stage01",
              "end_behavior": 0
            },
            {
              "scene_idx": 3,
              "func_name": "Alsmeer_PathofRotrua_Stage02",
              "end_behavior": 0
            },
            {
              "scene_idx": 4,
              "func_name": "Alsmeer_PathofRotrua_Boss",
              "end_behavior": 0
            },
            {
              "scene_idx": 5,
              "func_name": "Alsmeer_PathofRotrua_After",
              "end_behavior": 0
            }
          ]
        }
      ]
    }
  ],
  "tutorial_entries": [
    {
      "quest_id": 1002,
      "quest_title_kr": "시놉시스",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [],
      "chapters": []
    },
    {
      "quest_id": 2742,
      "quest_title_kr": "튜토리얼-키보드입력",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "10"
        }
      ],
      "chapters": []
    },
    {
      "quest_id": 2743,
      "quest_title_kr": "튜토리얼-마우스입력",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "20"
        }
      ],
      "chapters": []
    },
    {
      "quest_id": 2744,
      "quest_title_kr": "튜토리얼-카메라",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "30"
        }
      ],
      "chapters": []
    },
    {
      "quest_id": 2745,
      "quest_title_kr": "튜토리얼-캐릭터선택",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "40"
        }
      ],
      "chapters": []
    },
    {
      "quest_id": 2746,
      "quest_title_kr": "튜토리얼-전투",
      "type": 3,
      "subtype": 1,
      "town_id": 0,
      "field_id": null,
      "level": 1,
      "giver_npc_id": 10027,
      "giver_name_kr": null,
      "finisher_npc_id": 10027,
      "finisher_name_kr": null,
      "demands": [],
      "accept_action": null,
      "complete_action": null,
      "rewards_etc": [
        {
          "type": 2,
          "value": "50"
        }
      ],
      "chapters": []
    }
  ],
  "scope_boundaries": {
    "enter_alsmeer_first_town2_quest": 133,
    "end_alsmeer_chapter": 142,
    "toward_next_village_quest_ids": [
      143,
      144
    ],
    "first_next_village_quest_id": 65,
    "next_village_quest65_demand": [
      144
    ]
  },
  "validation": {
    "mainline_count": 25,
    "tutorial_aux_count": 6,
    "ordered_demands_each_previous": true,
    "all_table_scenes_match_event_scene_keys": true,
    "real_gameplay_tested": false,
    "server_rule_originally_recovered": false
  }
}
```
