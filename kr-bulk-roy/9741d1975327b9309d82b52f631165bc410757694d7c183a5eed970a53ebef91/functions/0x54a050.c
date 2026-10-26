
undefined4 FUN_0054a050(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int in_ECX;
  undefined4 local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *(int *)(in_ECX + 0x108);
  iVar2 = *(int *)(in_ECX + 0xac + iVar1 * 0x10);
  if (((iVar2 == 4) || (iVar2 == 5)) || (iVar2 == 6)) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    local_24 = *(undefined4 *)(in_ECX + 0xb0 + iVar1 * 0x10);
    FUN_0082ef00(&local_24);
    if (((local_20 != (float)DAT_00fab13c) && (iVar1 = *(int *)((int)local_20 + 0x10), iVar1 != 0))
       && ((*(int *)(iVar1 + 0x158) != 0 && (*(int *)(*(int *)(iVar1 + 0x158) + 0x34) == 0)))) {
      fVar3 = *(float *)(in_ECX + 100) - *(float *)(iVar1 + 0xa0);
      local_1c = *(float *)(in_ECX + 0x68) - *(float *)(iVar1 + 0xa4);
      local_20 = local_1c * local_1c + fVar3 * fVar3;
      if (*(float *)(in_ECX + 0x7c + *(int *)(in_ECX + 0x10c) * 0x10) < local_20) {
        *(undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x108) + 0xb) * 0x10) = 0;
        *(undefined4 *)(in_ECX + 0xac + *(int *)(in_ECX + 0x108) * 0x10) = 1;
        ExceptionList = local_14;
        return 0;
      }
      FUN_0054a790();
      ExceptionList = local_14;
      return 1;
    }
    *(undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x108) + 0xb) * 0x10) = 0;
    FUN_0054a450();
  }
  ExceptionList = local_14;
  return 0;
}

