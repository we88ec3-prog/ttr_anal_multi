
void FUN_0074eb80(int *param_1)

{
  int *in_EAX;
  int iVar1;
  int unaff_ESI;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(unaff_ESI + 0x13c4) == 0) {
    return;
  }
  if (*(int *)(unaff_ESI + 0x13f0) != 0) {
    FUN_00748740(in_EAX,param_1,*(undefined4 *)(unaff_ESI + 0xa8),*(undefined4 *)(unaff_ESI + 0xac),
                 &PTR_vftable_00f7ad2c);
  }
  iVar1 = *in_EAX;
  if (iVar1 == 0) {
    iVar1 = FUN_00761010();
    if ((iVar1 == 0) || ((*(uint *)(iVar1 + 0x28) >> 0xd & 1) == 0)) {
      uVar3 = *(undefined4 *)(unaff_ESI + 0xac);
      uVar2 = *(undefined4 *)(unaff_ESI + 0xa8);
    }
    else {
      uVar3 = *(undefined4 *)(unaff_ESI + 0xac);
      uVar2 = *(undefined4 *)(unaff_ESI + 0xa8);
    }
    FUN_00748740(in_EAX,param_1,uVar2,uVar3,&PTR_vftable_00f7ad2c);
    iVar1 = *in_EAX;
    if (iVar1 == 0) goto LAB_0074ec4d;
  }
  if (iVar1 == *(int *)(unaff_ESI + 0x13c4)) {
    *in_EAX = 0;
  }
  else {
    if ((*(byte *)(iVar1 + 0x28) & 0x10) == 0) {
      if (*(int *)(iVar1 + 0x60) == 0) goto LAB_0074ec4d;
      iVar1 = FUN_00745c20();
    }
    if ((iVar1 != 0) && (iVar1 = FUN_0074a1c0(), iVar1 != 0)) {
      *in_EAX = iVar1;
    }
  }
LAB_0074ec4d:
  if (*param_1 != 0) {
    if (*param_1 == *(int *)(unaff_ESI + 0x13c4)) {
      *param_1 = 0;
      return;
    }
    iVar1 = FUN_00745c40();
    *param_1 = iVar1;
  }
  return;
}

