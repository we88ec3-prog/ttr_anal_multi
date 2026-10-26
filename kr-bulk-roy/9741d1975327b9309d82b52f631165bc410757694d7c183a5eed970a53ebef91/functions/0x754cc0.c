
undefined4 FUN_00754cc0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  cVar1 = FUN_007543c0(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00764bb0();
    FUN_00764810(uVar2);
    FUN_0072e0d0();
    FUN_00776320(param_1);
    FUN_007649b0(*(undefined4 *)(in_ECX + 0x154));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0x120));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0x124));
    FUN_00764b00(*(undefined1 *)(in_ECX + 200));
    return 1;
  }
  return 0;
}

