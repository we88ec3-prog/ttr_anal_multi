
undefined4 FUN_0053a0a0(int param_1,uint param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  ushort *puVar5;
  int local_20;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ffac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined2 *)FUN_0053a960(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar2 != (undefined2 *)0x0) {
    if (*(int *)(param_1 + 4) != 0) {
      FUN_00797a00();
    }
    if (param_2 < 8) {
      local_1c = 0;
    }
    else {
      local_1c = (param_2 - 8) / 9;
    }
    param_2 = 0;
    local_20 = 0;
    FUN_00404ba0();
    if (local_1c != 0) {
      puVar5 = (ushort *)(param_1 + 0xe);
      do {
        piVar3 = (int *)FUN_00539690(*(undefined4 *)(puVar5 + -3));
        *(byte *)(piVar3 + 1) = (byte)puVar5[-1];
        *(byte *)((int)piVar3 + 5) = *(byte *)((int)puVar5 + -1);
        *(byte *)((int)piVar3 + 7) = (byte)*puVar5 >> 7;
        *(byte *)(piVar3 + 2) = *(byte *)((int)puVar5 + 1) & 1;
        *(byte *)((int)piVar3 + 9) = (byte)(*puVar5 >> 9) & 1;
        *(byte *)((int)piVar3 + 0xb) = (byte)puVar5[1];
        if ((*(char *)((int)piVar3 + 6) == '\0') || ((*puVar5 & 1) == 0)) {
          uVar1 = *puVar5;
          if (((uVar1 & 2) == 0) || ((uVar1 & 0x20) == 0)) {
            *(bool *)((int)piVar3 + 6) = (uVar1 & 2) != 0;
          }
          else {
            local_20 = *piVar3;
            *(undefined1 *)((int)piVar3 + 6) = 1;
          }
        }
        else {
          param_2 = *piVar3;
          *(undefined1 *)((int)piVar3 + 6) = 0;
        }
        uVar1 = *puVar5;
        if ((uVar1 & 4) == 0) {
          if ((uVar1 & 0x40) == 0) {
            if ((uVar1 & 8) == 0) goto LAB_0053a215;
            FUN_0053ace0(*puVar2);
          }
          else {
            FUN_0053b100();
          }
          FUN_00539810();
        }
        else {
          iVar4 = FUN_00404ba0();
          if (*(int *)(puVar5 + -3) == *(int *)(iVar4 + 0x5f50)) {
            FUN_0053b750(*(undefined2 *)(param_1 + 2));
          }
          FUN_0053aaa0(*puVar2);
        }
LAB_0053a215:
        puVar5 = (ushort *)((int)puVar5 + 9);
        local_1c = local_1c - 1;
      } while (local_1c != 0);
      if ((local_20 != 0) || (param_2 != 0)) {
        FUN_0053b2c0(local_20);
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_8 = 0;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_8 = 0xffffffff;
        }
        FUN_0058aad0(0xf4405);
      }
    }
    FUN_005398e0(puVar2);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4404);
  }
  ExceptionList = local_10;
  return 0;
}

