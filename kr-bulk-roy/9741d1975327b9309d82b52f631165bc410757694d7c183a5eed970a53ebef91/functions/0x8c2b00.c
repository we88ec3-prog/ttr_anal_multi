
undefined4
FUN_008c2b00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_008c2ad0();
  if (iVar1 != 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(iVar1 + 0xc);
    }
    uVar2 = FUN_008b97e0(param_3,*(undefined4 *)(iVar1 + 8));
    return uVar2;
  }
  return 0x8e;
}

