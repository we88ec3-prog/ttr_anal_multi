
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004af530(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint local_24;
  uint local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00944e4a;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (*(short *)(param_1 + 2) != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(uVar2);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    DAT_00fab228 = 0;
    FUN_004e1070(&DAT_00fab148);
  }
  if (param_2 < 4) {
    local_24 = 0;
  }
  else {
    local_24 = (param_2 - 4) / 0x16;
  }
  if (local_24 != 0) {
    piVar4 = (int *)(param_1 + 10);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90(uVar2);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_20 = *(uint *)((int)piVar4 + -6);
      FUN_008438c0(&local_20);
      if ((local_1c == DAT_00fab14c) || (piVar3 = *(int **)(local_1c + 0x10), piVar3 == (int *)0x0))
      {
        piVar3 = (int *)FUN_00891268(0x2c);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          *piVar3 = 0;
          piVar3[1] = 0;
          piVar3[2] = 0;
          piVar3[3] = 0;
          piVar3[4] = 0;
          piVar3[5] = 0;
          piVar3[7] = 0;
          piVar3[9] = -1;
          *(undefined2 *)(piVar3 + 10) = 0;
        }
        uVar5 = DAT_00f94390 & 1;
        *piVar3 = *(int *)((int)piVar4 + -6);
        if (uVar5 == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 2;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        uVar5 = DAT_00fab22c & 1;
        piVar3[7] = (uint)(DAT_00f93930 == *piVar3);
        if (uVar5 == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 3;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        FUN_004dffb0(&DAT_00fab130);
      }
      uVar5 = DAT_00f94390 & 1;
      *piVar3 = *(int *)((int)piVar4 + -6);
      if (uVar5 == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 4;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      iVar1 = *piVar3;
      piVar3[7] = (uint)(DAT_00f93930 == iVar1);
      *(undefined1 *)(piVar3 + 8) = *(undefined1 *)((int)piVar4 + -2);
      piVar3[3] = *piVar4;
      *(undefined2 *)((int)piVar3 + 0x16) = *(undefined2 *)((int)piVar4 + 10);
      *(short *)(piVar3 + 5) = (short)piVar4[2];
      piVar3[4] = piVar4[1];
      *(short *)(piVar3 + 6) = (short)piVar4[3];
      *(byte *)(piVar3 + 10) = *(byte *)((int)piVar4 + -1) & 1;
      uVar5 = DAT_00f94390 & 1;
      *(byte *)((int)piVar3 + 0x29) = *(byte *)((int)piVar4 + -1) >> 1 & 1;
      piVar3[9] = (int)*(short *)((int)piVar4 + 0xe);
      if (uVar5 == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 5;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      if (iVar1 == DAT_00f93930) {
        uVar5 = (uint)*(ushort *)(piVar3 + 5);
        local_20 = uVar5;
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 6;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        if ((DAT_00fb1378 & 1) == 0) {
          DAT_00fb1378 = DAT_00fb1378 | 1;
          local_c = 7;
          FUN_00539c20();
          _atexit((_func_4879 *)&LAB_00bccfb0);
          local_c = 0xffffffff;
        }
        DAT_00fb7258 = FUN_0053a9d0(uVar5);
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_c = 8;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_c = 0xffffffff;
        }
        FUN_0058aad0(0xf4404);
        _DAT_00fab220 = (undefined2)local_20;
        iVar1 = piVar3[4];
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 9;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        if ((DAT_00fc7f1c & 1) == 0) {
          DAT_00fc7f1c = DAT_00fc7f1c | 1;
          local_c = 10;
          FUN_0053c300();
          _atexit(FUN_00bce1d0);
          local_c = 0xffffffff;
        }
        FUN_0053ced0(iVar1);
        _DAT_00fab224 = iVar1;
      }
      piVar4 = (int *)((int)piVar4 + 0x16);
      local_24 = local_24 - 1;
    } while (local_24 != 0);
  }
  ExceptionList = local_14;
  return 0x100;
}

