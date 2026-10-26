
undefined4
FUN_008d93a0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 300);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x130);
  }
  uVar3 = 0x10000;
  uVar2 = 0x10000;
  if (iVar1 != 0) {
    uVar3 = FUN_008b7f40((uint)*(ushort *)(iVar1 + 0xc) << 6,*(undefined4 *)(param_1 + 0x130));
    uVar2 = FUN_008b7f40((uint)*(ushort *)(iVar1 + 0xe) << 6,*(undefined4 *)(param_1 + 0x130));
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar3;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = uVar2;
  }
  return 0;
}

