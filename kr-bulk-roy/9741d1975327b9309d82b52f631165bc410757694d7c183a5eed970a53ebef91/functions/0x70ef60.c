
void FUN_0070ef60(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int local_24c [145];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_0070dfb0(param_1);
  *(int *)(local_24c[0] + 0x3c) = param_4;
  if (*(int *)(param_1 + 0x10) != 0x28) {
    FUN_0070d750();
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar5 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar5;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  if (param_3 != 0) {
    uVar5 = *(undefined4 *)(param_1 + 0x34);
    uVar3 = FUN_006fec70(uVar5,&DAT_00c43fc8,4);
    puVar4 = (undefined4 *)FUN_006f9d80(uVar5);
    if (puVar4[2] == 0) {
      *puVar4 = 1;
      puVar4[2] = 1;
    }
    iVar6 = *(int *)(param_1 + 0x30);
    if (200 < *(byte *)(iVar6 + 0x32) + 1) {
      FUN_0070d7c0();
    }
    uVar2 = FUN_0070da10(param_1,uVar3);
    *(undefined2 *)(iVar6 + 0xac + (uint)*(byte *)(iVar6 + 0x32) * 2) = uVar2;
    piVar1 = *(int **)(param_1 + 0x30);
    *(char *)((int)piVar1 + 0x32) = *(char *)((int)piVar1 + 0x32) + '\x01';
    *(int *)(*(int *)(*piVar1 + 0x18) + 4 +
            (uint)*(ushort *)((int)piVar1 + (uint)*(byte *)((int)piVar1 + 0x32) * 2 + 0xaa) * 0xc) =
         piVar1[6];
  }
  FUN_0070ed10();
  iVar6 = 0x11f;
  if (*(int *)(param_1 + 0x10) != 0x29) {
    FUN_0070d750();
    iVar6 = param_1;
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == iVar6) {
    uVar5 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar5;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x20) = iVar6;
  }
  FUN_00711b20(param_1);
  *(undefined4 *)(local_24c[0] + 0x40) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x10) == 0x106) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == iVar6) {
      uVar5 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar5;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(int *)(param_1 + 0x20) = iVar6;
    }
    FUN_0070e110(param_1);
    FUN_0070dea0(param_1,local_24c,param_2);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_4 == *(int *)(param_1 + 4)) {
    uVar5 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"\'%s\' expected",&DAT_00c42cc0);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,uVar5,*(undefined4 *)(param_1 + 0x10));
  }
  uVar5 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),
                       "\'%s\' expected (to close \'%s\' at line %d)",&DAT_00c42cc0,"function",
                       param_4);
                    /* WARNING: Subroutine does not return */
  FUN_006ff130(param_1,uVar5,*(undefined4 *)(param_1 + 0x10));
}

