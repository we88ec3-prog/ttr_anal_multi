
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f2460(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined2 local_1c;
  undefined4 local_1a;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092488c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_1a = *(undefined4 *)(param_1 + 6);
  local_1c = 0xbcd;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_1c,6,uVar4);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x5ecc);
  if ((puVar1 == (undefined4 *)0x0) || (puVar1[2] == 0)) {
    piVar2 = *(int **)(in_ECX + 0x5ed0);
    uVar4 = *(int *)(in_ECX + 0x5ed4) - (int)piVar2 >> 2;
    uVar5 = 0;
    if (uVar4 != 0) {
      piVar6 = piVar2;
      do {
        if (*(int *)(*piVar6 + 8) == *(int *)(param_1 + 6)) {
          *(undefined4 *)piVar2[uVar5] = *(undefined4 *)(param_1 + 2);
          if (*(int *)(param_1 + 2) == 0) {
            uVar3 = 10;
          }
          else {
            uVar3 = *(undefined1 *)(*(int *)(*(int *)(local_14 + 0x5ed0) + uVar5 * 4) + 0x12);
          }
          *(undefined1 *)(*(int *)(*(int *)(local_14 + 0x5ed0) + uVar5 * 4) + 0x12) = uVar3;
          break;
        }
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar5 < uVar4);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    uVar7 = 1;
  }
  else {
    *puVar1 = *(undefined4 *)(param_1 + 2);
    if (*(int *)(param_1 + 2) == 0) {
      uVar3 = 10;
    }
    else {
      uVar3 = *(undefined1 *)(*(int *)(in_ECX + 0x5ecc) + 0x12);
    }
    uVar4 = DAT_00faadd4 & 1;
    *(undefined1 *)(*(int *)(in_ECX + 0x5ecc) + 0x12) = uVar3;
    if (uVar4 == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    uVar7 = 0;
  }
  FUN_0058ac30(0xf4253,*(undefined4 *)(param_1 + 6),uVar7);
  ExceptionList = local_10;
  return 0;
}

