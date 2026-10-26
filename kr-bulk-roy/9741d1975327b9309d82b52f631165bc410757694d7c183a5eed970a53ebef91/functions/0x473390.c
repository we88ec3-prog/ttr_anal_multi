
void ** FUN_00473390(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  uint local_28;
  int local_24;
  void **local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946a5c;
  local_14 = ExceptionList;
  local_20 = &local_14;
  if (*(int *)(in_ECX + 0x250) != 0) {
    ExceptionList = local_20;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (*(byte *)(in_ECX + 0x254) < 10) {
      local_28 = DAT_00f94304 + (uint)*(byte *)(in_ECX + 0x254) * 0x210;
      local_28 = -(uint)(*(int *)(local_28 + 0x5c) != 0) & local_28;
    }
    else {
      local_28 = 0;
    }
    if ((DAT_00fb11a8 & 1) == 0) {
      DAT_00fb11a8 = DAT_00fb11a8 | 1;
      local_c = 1;
      FUN_00813890();
      _atexit((_func_4879 *)&LAB_00bccec0);
    }
    puVar1 = *(undefined4 **)(in_ECX + 0x250);
    local_20 = (void **)*puVar1;
    FUN_0082ef00(&local_20);
    if (local_24 == DAT_00fb11b0) {
      local_24 = 0;
    }
    else {
      local_24 = *(int *)(local_24 + 0x10);
    }
    local_20 = (void **)(uint)*(byte *)((int)puVar1 + 5);
    if ((local_28 != 0) && (local_24 != 0)) {
      if (local_20 == (void **)0x0) {
        ExceptionList = local_14;
        return (void **)0x0;
      }
      iVar6 = 1;
      do {
        uVar5 = 0;
        iVar3 = FUN_0081ae60();
        if (iVar3 != 0) {
          iVar3 = *(int *)(*(int *)(local_24 + 0x14) + iVar6 * 4);
          local_1c = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2;
          do {
            if ((((uVar5 < local_1c) &&
                 (iVar2 = *(int *)(*(int *)(iVar3 + 4) + uVar5 * 4), iVar2 != 0)) &&
                (*(int *)(iVar2 + 4) == 0)) &&
               (((*(int *)(iVar2 + 8) != 0 && (*(int *)(local_28 + 8) < *(int *)(iVar2 + 8))) ||
                ((*(int *)(iVar2 + 0xc) != 0 && (*(int *)(iVar2 + 0xc) < *(int *)(local_28 + 8))))))
               ) {
              ExceptionList = local_14;
              return (void **)(iVar6 + -1);
            }
            uVar5 = uVar5 + 1;
            uVar4 = FUN_0081ae60();
          } while (uVar5 < uVar4);
        }
        iVar6 = iVar6 + 1;
        if ((int)local_20 < iVar6) {
          ExceptionList = local_14;
          return local_20;
        }
      } while( true );
    }
  }
  ExceptionList = local_14;
  return (void **)((uint)local_20 & 0xffffff00);
}

