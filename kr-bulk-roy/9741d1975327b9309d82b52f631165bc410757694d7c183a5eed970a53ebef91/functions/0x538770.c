
uint FUN_00538770(undefined4 param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI == 0) {
    return in_EAX & 0xffffff00;
  }
  FUN_008438c0(&param_1);
  if (in_ECX == *(int *)(unaff_ESI + 0x14)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0x10);
  }
  FUN_00538270(unaff_EDI,uVar1);
  return (uint)(*(uint *)(unaff_EDI + 4) <= *(uint *)(unaff_ESI + 0x20));
}

