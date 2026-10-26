
void FUN_0047dc50(void)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  undefined2 *unaff_EDI;
  
  if ((*(int *)(in_ECX + 0x14) - *(uint *)(in_ECX + 0x10) < *(uint *)(in_EAX + 0x10)) &&
     (*(uint *)(in_ECX + 0x10) <= *(int *)(in_EAX + 0x14) - *(uint *)(in_EAX + 0x10))) {
    uVar1 = FUN_004481f0(0,in_ECX,0);
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    FUN_00402800(uVar1);
    return;
  }
  uVar1 = FUN_004041f0(in_EAX,0,0xffffffff);
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  FUN_00402800(uVar1);
  return;
}

