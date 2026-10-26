
undefined4 FUN_004ef7f0(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int local_28;
  uint local_20;
  undefined2 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092490c;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  local_20 = 0x10;
  puVar5 = (undefined4 *)FUN_004ef160(*(undefined4 *)(param_2 + 2),*(undefined4 *)(param_2 + 6));
  if (puVar5 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar5 + 9) = 0x101;
    puVar5[0x19] = *(undefined4 *)(param_2 + 10);
    puVar5[0x15] = 0;
    if ((uint)puVar5[0x16] < 8) {
      puVar9 = puVar5 + 0x11;
    }
    else {
      puVar9 = (undefined4 *)puVar5[0x11];
    }
    *(undefined2 *)puVar9 = 0;
    local_28 = 0;
    local_1c = (undefined2 *)(param_2 + 0x10);
    if (*(char *)(param_2 + 0xe) != '\0') {
      do {
        puVar2 = local_1c + 1;
        local_20 = local_20 + 2;
        if (param_3 < local_20) {
          FUN_006edb60(&DAT_00bf6cbc,uVar4);
        }
        if ((uint)puVar5[0x16] < 8) {
          puVar9 = puVar5 + 0x11;
        }
        else {
          puVar9 = (undefined4 *)puVar5[0x11];
        }
        iVar1 = (int)puVar9 + puVar5[0x15] * 2;
        if ((uint)puVar5[0x16] < 8) {
          puVar9 = puVar5 + 0x11;
        }
        else {
          puVar9 = (undefined4 *)puVar5[0x11];
        }
        iVar6 = 0;
        if (iVar1 != 0) {
          iVar6 = iVar1 - (int)puVar9 >> 1;
        }
        FUN_004f0b60(iVar6,1,*local_1c);
        local_28 = local_28 + 1;
        local_1c = puVar2;
      } while (local_28 < (int)(uint)*(byte *)(param_2 + 0xe));
    }
    FUN_004ef080();
    uVar8 = 0;
    if (*(char *)(param_2 + 0xf) != '\0') {
      uVar7 = local_20;
      do {
        if (param_3 <= uVar7) break;
        puVar9 = (undefined4 *)((int)local_1c + (uVar7 - local_20));
        uVar7 = uVar7 + 0xe;
        if (param_3 < uVar7) {
          FUN_006edb60(&DAT_00bf6cbc,uVar4);
        }
        puVar5[(uint)*(byte *)((int)puVar9 + 0xd) * 6 + 0x1a] = puVar9[2];
        bVar3 = *(byte *)((int)puVar9 + 0xd);
        puVar5[(uint)bVar3 * 6 + 0x1c] = *puVar9;
        puVar5[(uint)bVar3 * 6 + 0x1d] = puVar9[1];
        *(undefined1 *)(puVar5 + ((uint)*(byte *)((int)puVar9 + 0xd) * 3 + 0xf) * 2) =
             *(undefined1 *)(puVar9 + 3);
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)(uint)*(byte *)(param_2 + 0xf));
    }
    if (uVar8 != *(byte *)(param_2 + 0xf)) {
      FUN_006edb60(&DAT_00c0d3e4,uVar4);
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aee0(0xf4271,*puVar5,puVar5[1]);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4270);
  ExceptionList = local_14;
  return 0;
}

