
void FUN_00710810(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined8 uStack_28;
  undefined4 uStack_20;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_34;
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  piVar5 = *(int **)(param_1 + 0x30);
  local_2c = piVar5[9];
  local_30 = param_2;
  local_34 = FUN_006fec70(uVar3,"(for index)",0xb);
  puVar2 = (undefined4 *)FUN_006f9d80(uVar3);
  if (puVar2[2] == 0) {
    *puVar2 = 1;
    puVar2[2] = 1;
  }
  iVar4 = *(int *)(param_1 + 0x30);
  if (200 < *(byte *)(iVar4 + 0x32) + 1) {
    FUN_0070d7c0();
  }
  uVar1 = FUN_0070da10(param_1,local_34);
  *(undefined2 *)(iVar4 + 0xac + (uint)*(byte *)(iVar4 + 0x32) * 2) = uVar1;
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  local_34 = FUN_006fec70(uVar3,"(for limit)",0xb);
  puVar2 = (undefined4 *)FUN_006f9d80(uVar3);
  if (puVar2[2] == 0) {
    *puVar2 = 1;
    puVar2[2] = 1;
  }
  iVar4 = *(int *)(param_1 + 0x30);
  if (200 < *(byte *)(iVar4 + 0x32) + 2) {
    FUN_0070d7c0();
  }
  uVar1 = FUN_0070da10(param_1,local_34);
  *(undefined2 *)(iVar4 + 0xae + (uint)*(byte *)(iVar4 + 0x32) * 2) = uVar1;
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  local_34 = FUN_006fec70(uVar3,"(for step)",10);
  puVar2 = (undefined4 *)FUN_006f9d80(uVar3);
  if (puVar2[2] == 0) {
    *puVar2 = 1;
    puVar2[2] = 1;
  }
  iVar4 = *(int *)(param_1 + 0x30);
  if (200 < *(byte *)(iVar4 + 0x32) + 3) {
    FUN_0070d7c0();
  }
  uVar1 = FUN_0070da10(param_1,local_34);
  *(undefined2 *)(iVar4 + 0xb0 + (uint)*(byte *)(iVar4 + 0x32) * 2) = uVar1;
  iVar4 = *(int *)(param_1 + 0x30);
  if (200 < *(byte *)(iVar4 + 0x32) + 4) {
    FUN_0070d7c0();
  }
  uVar1 = FUN_0070da10(param_1,local_30);
  *(undefined2 *)(iVar4 + 0xb2 + (uint)*(byte *)(iVar4 + 0x32) * 2) = uVar1;
  if (*(int *)(param_1 + 0x10) != 0x3d) {
    piVar5 = (int *)0x3d;
    FUN_0070d750();
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar3 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar3;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  FUN_0070fc00(param_1,&uStack_28,0);
  FUN_00712630();
  iVar4 = 0x11f;
  if (*(int *)(param_1 + 0x10) != 0x2c) {
    piVar5 = (int *)&DAT_0000002c;
    FUN_0070d750();
    iVar4 = param_1;
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == iVar4) {
    uVar3 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar3;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x20) = iVar4;
  }
  FUN_0070fc00(param_1,&uStack_28,0);
  FUN_00712630();
  if (*(int *)(param_1 + 0x10) == 0x2c) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == iVar4) {
      uVar3 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(int *)(param_1 + 0x20) = iVar4;
    }
    FUN_0070fc00(param_1,&uStack_28,0);
    FUN_00712630();
  }
  else {
    uStack_28 = 0x3ff0000000000000;
    uStack_20 = 3;
    iVar4 = FUN_00712090(piVar5,&uStack_28);
    FUN_00713370((iVar4 << 8 | piVar5[9]) << 6 | 1,*(undefined4 *)(piVar5[3] + 8));
    iVar4 = piVar5[9] + 1;
    if ((int)(uint)*(byte *)(*piVar5 + 0x4b) < iVar4) {
      if (0xf9 < iVar4) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(piVar5[3],"function or expression too complex",
                     *(undefined4 *)(piVar5[3] + 0x10));
      }
      *(char *)(*piVar5 + 0x4b) = (char)iVar4;
    }
    piVar5[9] = piVar5[9] + 1;
  }
  FUN_007105b0(param_1,local_2c,param_3,1,1);
  __security_check_cookie(local_c ^ (uint)&local_34);
  return;
}

