
void FUN_004aedb0(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  ushort *puVar8;
  int *unaff_FS_OFFSET;
  uint *puVar9;
  undefined1 auStack_544 [4];
  uint uStack_540;
  uint local_53c;
  uint local_538;
  int iStack_534;
  int *local_530;
  int iStack_52c;
  int local_528;
  uint auStack_524 [4];
  undefined4 uStack_514;
  uint uStack_510;
  int aiStack_508 [40];
  float fStack_468;
  float fStack_464;
  undefined4 uStack_45c;
  int iStack_3ac;
  int iStack_198;
  undefined1 auStack_e8 [204];
  uint local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093978c;
  local_14 = *unaff_FS_OFFSET;
  local_1c = DAT_00d61f20 ^ (uint)auStack_544;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffab0;
  *unaff_FS_OFFSET = (int)&local_14;
  if (param_2 < 2) {
    uVar7 = 0;
  }
  else {
    uVar7 = (param_2 - 2) / 0x12;
  }
  if (uVar7 != 0) {
    puVar8 = (ushort *)(param_1 + 6);
    local_538 = uVar7;
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar5);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_53c = (uint)puVar8[-2];
      FUN_0082ef00(&local_53c);
      if ((local_528 != DAT_00fab13c) &&
         (local_530 = *(int **)(local_528 + 0x10), local_530 != (int *)0x0)) {
        uVar7 = ((uint)(byte)puVar8[-2] << 8 | (byte)puVar8[-1] - 1) << 0x10 | (uint)*puVar8;
        local_53c = uVar7;
        uStack_540 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        if (uStack_540 != 0) {
          FUN_004c7070(aiStack_508);
          local_c = 1;
          if ((*(float *)(puVar8 + 3) != fStack_468) || (*(float *)(puVar8 + 5) != fStack_464)) {
            fStack_468 = *(float *)(puVar8 + 3);
            fStack_464 = *(float *)(puVar8 + 5);
            uStack_45c = 1;
            (**(code **)(aiStack_508[0] + 0x38))();
          }
          if ((iStack_198 != 0) && (iStack_3ac != 0)) {
            iVar2 = *(int *)(iStack_3ac + 4);
            uVar6 = (**(code **)(aiStack_508[0] + 0x4c))();
            (**(code **)(iVar2 + 4))(uVar6);
            uVar7 = local_53c;
          }
          if ((DAT_00fdf6dc & 1) == 0) {
            DAT_00fdf6dc = DAT_00fdf6dc | 1;
            local_c._0_1_ = 2;
            FUN_00550820();
            _atexit((_func_4879 *)&LAB_00bce6b0);
            local_c = CONCAT31(local_c._1_3_,1);
          }
          uVar1 = puVar8[-2];
          FUN_00551b80(0xffffffff,0xffffffff);
          FUN_00551dd0(&DAT_00fdf680,uVar1,&fStack_468,0,0x3f800000,1);
          local_c = 0xffffffff;
          FUN_004c7b90();
        }
        uVar3 = uStack_540;
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_c = 3;
          FUN_0079cf40();
          _atexit((_func_4879 *)&LAB_00bcdb80);
          local_c = 0xffffffff;
        }
        uStack_540 = (uint)*puVar8;
        FUN_00515790(&uStack_540);
        if ((iStack_534 == DAT_00fc0e94) || (*(int *)(*(int *)(iStack_534 + 0x10) + 0x54) == 0)) {
          if (uVar3 != 0) {
            uVar3 = *(uint *)(uVar3 + 0x9c);
            if ((DAT_00fab22c & 1) == 0) {
              DAT_00fab22c = DAT_00fab22c | 1;
              local_c = 4;
              FUN_004dec90();
              _atexit((_func_4879 *)&LAB_00bcce30);
              local_c = 0xffffffff;
            }
            uStack_540 = uVar3;
            FUN_008438c0(&uStack_540);
            if (((iStack_52c != DAT_00fab14c) && (*(int *)(iStack_52c + 0x10) != 0)) &&
               (4 < *(byte *)(*(int *)(iStack_52c + 0x10) + 0x20))) {
              FUN_004b7c80(L"Load Error: [%d] Does not exist in preload list",*puVar8);
              FUN_00402250(auStack_e8);
              puVar9 = auStack_524;
              local_c = 5;
              FUN_0040f8c0(puVar9);
              FUN_004d6b30(puVar9);
              local_c = 0xffffffff;
              if (7 < uStack_510) {
                FUN_0089120c(auStack_524[0]);
              }
              uStack_510 = 7;
              uStack_514 = 0;
              auStack_524[0] = auStack_524[0] & 0xffff0000;
            }
          }
          if ((DAT_00fc0e40 & 1) == 0) {
            DAT_00fc0e40 = DAT_00fc0e40 | 1;
            local_c = 6;
            FUN_00540770();
            _atexit((_func_4879 *)&LAB_00bcdb60);
            local_c = 0xffffffff;
          }
          FUN_00541610(*puVar8);
        }
        piVar4 = local_530;
        (**(code **)(*local_530 + 0x40))(uVar7);
        (**(code **)(*piVar4 + 0x5c))(*(undefined4 *)(puVar8 + 1));
        (**(code **)(*piVar4 + 0x34))();
      }
      puVar8 = puVar8 + 9;
      local_538 = local_538 - 1;
    } while (local_538 != 0);
  }
  *unaff_FS_OFFSET = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_544);
  return;
}

