
void FUN_007105b0(int param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  int local_14 [2];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x30);
  iVar5 = 3;
  *(char *)((int)piVar1 + 0x32) = *(char *)((int)piVar1 + 0x32) + '\x03';
  do {
    iVar2 = (uint)*(byte *)((int)piVar1 + 0x32) - iVar5;
    iVar5 = iVar5 + -1;
    *(int *)(*(int *)(*piVar1 + 0x18) + 4 + (uint)*(ushort *)((int)piVar1 + iVar2 * 2 + 0xac) * 0xc)
         = piVar1[6];
  } while (iVar5 != 0);
  if (*(int *)(param_1 + 0x10) != 0x103) {
    uVar3 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"\'%s\' expected",&DAT_00c42cd4);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,uVar3,*(undefined4 *)(param_1 + 0x10));
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
  if (param_5 == 0) {
    piVar1[8] = -1;
    iVar5 = FUN_00713370(0x7fff8016,*(undefined4 *)(piVar1[3] + 8));
    FUN_00711fe0();
  }
  else {
    iVar5 = FUN_00713370(param_2 << 6 | 0x7fff8020,*(undefined4 *)(piVar1[3] + 8));
  }
  local_14[1] = 0xffffffff;
  local_a = 0;
  local_c = *(undefined1 *)((int)piVar1 + 0x32);
  local_b = 0;
  local_14[0] = piVar1[5];
  piVar1[5] = (int)local_14;
  FUN_0070dad0();
  iVar2 = piVar1[9] + param_4;
  if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar2) {
    if (0xf9 < iVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(piVar1[3],"function or expression too complex",*(undefined4 *)(piVar1[3] + 0x10))
      ;
    }
    *(char *)(*piVar1 + 0x4b) = (char)iVar2;
  }
  piVar1[9] = piVar1[9] + param_4;
  iVar2 = *(int *)(param_1 + 0x30);
  local_1c = 0xffffffff;
  local_16 = 0;
  local_18 = *(undefined1 *)(iVar2 + 0x32);
  local_17 = 0;
  local_20 = *(undefined4 *)(iVar2 + 0x14);
  *(undefined4 **)(iVar2 + 0x14) = &local_20;
  FUN_00711b20(param_1);
  FUN_0070de40();
  FUN_0070de40();
  piVar1[7] = piVar1[6];
  FUN_00711fe0();
  if (param_5 == 0) {
    uVar3 = *(undefined4 *)(piVar1[3] + 8);
    uVar4 = (param_4 << 8 | param_2) << 6 | 0x21;
  }
  else {
    uVar3 = *(undefined4 *)(piVar1[3] + 8);
    uVar4 = param_2 << 6 | 0x7fff801f;
  }
  local_8 = FUN_00713370(uVar4,uVar3);
  *(undefined4 *)(*(int *)(*piVar1 + 0x14) + -4 + piVar1[6] * 4) = param_3;
  if (param_5 == 0) {
    piVar1[8] = -1;
    local_8 = FUN_00713370(0x7fff8016,*(undefined4 *)(piVar1[3] + 8));
    FUN_00711fe0();
  }
  iVar5 = iVar5 + 1;
  if (iVar5 == piVar1[6]) {
    piVar1[7] = piVar1[6];
    FUN_00711fe0();
    return;
  }
  FUN_00711f00(piVar1,iVar5,0xff,iVar5);
  return;
}

