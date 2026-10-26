
void FUN_0041e830(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931ef3;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xb;
  FUN_0082ef00(&local_1c);
  if (local_18 == (int *)*(int *)(in_ECX + 0x50)) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)((int)local_18 + 0x10);
  }
  piVar9 = (int *)(in_ECX + 0xec);
  *(undefined4 *)(in_ECX + 0x80) = uVar5;
  local_14 = 0;
  local_1c = 10000;
  do {
    local_18 = piVar9;
    FUN_00615fc0(local_1c,uVar4);
    if ((DAT_00fb72e8 & 1) == 0) {
      DAT_00fb72e8 = DAT_00fb72e8 | 1;
      DAT_00fb72ec = 0;
      DAT_00fb72f0 = 0;
      DAT_00fb72f4 = 0;
      local_8 = 1;
      FUN_0049ef70();
      _atexit(FUN_00bccff0);
      local_8 = 0xffffffff;
    }
    uVar7 = DAT_00fb72f0 - DAT_00fb72ec >> 6;
    uVar6 = 0;
    if (uVar7 != 0) {
      piVar8 = (int *)(DAT_00fb72ec + 0x3c);
      do {
        if (local_14 + 1 == *piVar8) break;
        uVar6 = uVar6 + 1;
        piVar8 = piVar8 + 0x10;
      } while (uVar6 < uVar7);
    }
    FUN_00757710();
    piVar9 = (int *)*piVar9;
    puVar1 = (undefined4 *)piVar9[0x19];
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
      }
    }
    (**(code **)(*piVar9 + 0x128))();
    local_14 = local_14 + 1;
    piVar9 = local_18 + 1;
    local_1c = local_1c + 10000;
    if (189999 < local_1c) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

