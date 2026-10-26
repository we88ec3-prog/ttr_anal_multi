
undefined4 FUN_004f0450(undefined4 param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  undefined2 local_94 [8];
  undefined4 local_84;
  undefined2 *local_80;
  undefined4 *puStack_7c;
  undefined2 local_78 [8];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  int local_34;
  int *local_30;
  uint local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092f8c4;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(param_2 + 10) == '\0') {
    FUN_00542210();
    FUN_004d8460();
    if (local_28 != local_1c) {
      local_38 = *(undefined1 **)(param_2 + 2);
      local_34 = *(int *)(param_2 + 6);
      do {
        if (local_30 == (int *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *local_30;
        }
        uVar4 = local_28 >> 2;
        if (*(uint *)(iVar7 + 8) <= uVar4) {
          uVar4 = uVar4 - *(uint *)(iVar7 + 8);
        }
        piVar2 = *(int **)(*(int *)(*(int *)(iVar7 + 4) + uVar4 * 4) + (local_28 & 3) * 4);
        if (((undefined1 *)*piVar2 == local_38) && (piVar2[1] == local_34)) {
          local_3c = (undefined1 *)&local_60;
          local_60 = 0;
          local_5c = 0;
          if ((local_30 != (int *)0x0) && ((undefined4 *)*local_30 != (undefined4 *)0x0)) {
            local_60 = *(undefined4 *)*local_30;
          }
          local_64 = param_1;
          local_68 = 0x4f0537;
          FUN_004f08a0();
          break;
        }
        local_28 = local_28 + 1;
      } while (local_28 != local_1c);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      local_5c = 0x4f0561;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    local_5c = *(undefined4 *)(param_2 + 2);
    local_60 = 0xf4274;
    local_64 = 0x4f057e;
    FUN_0058aee0();
  }
  else if (*(char *)(param_2 + 10) == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      local_5c = 0x4f05b4;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    local_5c = 0;
    local_38 = (undefined1 *)local_78;
    puStack_7c = (undefined4 *)0x0;
    local_64 = 7;
    local_68 = 0;
    local_80 = &DAT_00bed1fc;
    local_78[0] = 0;
    local_84 = 0x4f05e7;
    FUN_00402160();
    local_c = 2;
    local_40 = 0xb5;
    puStack_7c = (undefined4 *)0x4f05fc;
    iVar7 = FUN_005854b0();
    puStack_7c = &local_40;
    local_80 = (undefined2 *)0x4f060e;
    FUN_005740f0();
    if (local_3c == *(undefined1 **)(iVar7 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    psVar8 = (short *)(local_3c + 0x10);
    if (7 < *(uint *)(local_3c + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_3c = (undefined1 *)local_94;
    local_80 = (undefined2 *)0x7;
    local_84 = 0;
    local_94[0] = 0;
    psVar6 = psVar8;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_14;
  return 0;
}

