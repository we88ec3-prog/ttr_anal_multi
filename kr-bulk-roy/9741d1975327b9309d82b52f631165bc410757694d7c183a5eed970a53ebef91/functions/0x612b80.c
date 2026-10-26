
uint FUN_00612b80(int param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e2da;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_c = 0xffffffff;
  local_20 = *(undefined4 *)(param_1 + 0x15c);
  FUN_0082ef00(&local_20);
  if (local_1c == DAT_00fb11b0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_1c + 0x10);
  }
  uVar4 = (uint)param_2;
  if (uVar4 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)) {
    iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + uVar4 * 4);
    uVar1 = *(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2;
  }
  else {
    uVar1 = 0;
  }
  uVar3 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)(*(int *)(iVar2 + 0x14) + uVar4 * 4);
    do {
      if (uVar3 < (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2)) {
        iVar5 = *(int *)(*(int *)(iVar2 + 4) + uVar3 * 4);
      }
      else {
        iVar5 = 0;
      }
      if (*(int *)(iVar5 + 4) == 0) {
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 1;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        uVar4 = DAT_00f94390 & 1;
        *(undefined1 *)(param_1 + 0x161) = *(undefined1 *)(iVar2 + 0x88);
        if (uVar4 == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 2;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
        }
        if (*(byte *)(param_1 + 0x161) < 10) {
          uVar4 = DAT_00f94304 + (uint)*(byte *)(param_1 + 0x161) * 0x210;
          ExceptionList = local_14;
          return (uint)(*(int *)(iVar5 + 8) <=
                       *(int *)((-(uint)(*(int *)(uVar4 + 0x5c) != 0) & uVar4) + 8));
        }
        ExceptionList = local_14;
        return (uint)(*(int *)(iVar5 + 8) <= iRam00000008);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  ExceptionList = local_14;
  return uVar1 & 0xffffff00;
}

