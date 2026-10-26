
undefined4 FUN_00717d50(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  iVar1 = in_ECX[1];
  if (iVar1 == 0) {
    (**(code **)*in_ECX)(1);
    return 0xfffffffe;
  }
  if (*(char *)(iVar1 + 0x5c) == 'w') {
    iVar2 = FUN_00729460(4);
    if (iVar2 == 0) {
      FUN_007296f0(*(undefined4 *)(iVar1 + 0x40));
      FUN_007296f0(*(undefined4 *)(iVar1 + 0x40));
    }
  }
  uVar3 = FUN_00728db0();
  (**(code **)*in_ECX)(1);
  return uVar3;
}

