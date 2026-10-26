
undefined4 FUN_0072e650(undefined4 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_007300a0(in_EAX);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      return uVar3;
    }
  }
  return param_1;
}

