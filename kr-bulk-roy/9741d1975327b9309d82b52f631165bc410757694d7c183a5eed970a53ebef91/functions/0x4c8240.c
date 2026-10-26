
undefined4 FUN_004c8240(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e3fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) != 0) {
    (**(code **)(*(int *)(*(int *)(in_ECX + 0x15c) + 8) + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc)
    ;
  }
  if (*(int *)(in_ECX + 0x364) != 0) {
    FUN_005506b0();
  }
  piVar5 = (int *)(in_ECX + 0x164);
  local_14 = 0x80;
  do {
    puVar3 = (undefined4 *)*piVar5;
    if (puVar3 != (undefined4 *)0x0) {
      if ((DAT_00fe1770 & 1) == 0) {
        DAT_00fe1770 = DAT_00fe1770 | 1;
        local_8 = 0;
        FUN_007b7da0();
        _atexit((_func_4879 *)&LAB_00bce790);
        local_8 = 0xffffffff;
      }
      iVar4 = FUN_007b8230(&DAT_00fe173c,puVar3 + 0xb);
      if (iVar4 != 0) {
        uVar1 = puVar3[3];
        uVar2 = puVar3[6];
        *(undefined4 *)(iVar4 + 0x44) = *puVar3;
        *(undefined4 *)(iVar4 + 0x48) = puVar3[1];
        *(undefined4 *)(iVar4 + 0x4c) = puVar3[2];
        *(undefined4 *)(iVar4 + 0x28) = *puVar3;
        *(undefined4 *)(iVar4 + 0x2c) = puVar3[1];
        *(undefined4 *)(iVar4 + 0x30) = puVar3[2];
        *(undefined4 *)(iVar4 + 0x58) = uVar1;
        *(undefined4 *)(iVar4 + 0x3c) = uVar1;
        *(undefined4 *)(iVar4 + 0x40) = uVar2;
        *(undefined4 *)(iVar4 + 0x18) = uVar2;
        *(undefined4 *)(iVar4 + 0x70) = 1;
        *(undefined4 *)(iVar4 + 0x6c) = 0;
        puVar3[9] = iVar4;
      }
    }
    piVar5 = piVar5 + 1;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  ExceptionList = local_10;
  return 0;
}

