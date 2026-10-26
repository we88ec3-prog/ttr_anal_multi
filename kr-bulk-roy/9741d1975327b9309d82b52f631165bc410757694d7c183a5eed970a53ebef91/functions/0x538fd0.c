
void FUN_00538fd0(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined2 *unaff_EDI;
  
  iVar1 = param_1;
  param_1 = 0;
  iVar2 = FUN_00537df0(iVar1,in_EAX);
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    return;
  }
  FUN_00539110(&param_1);
  iVar1 = *(int *)(iVar1 + 4);
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  if (param_1 != iVar1) {
    *unaff_EDI = 0;
    FUN_004026e0(param_1 + 0x28,0,0xffffffff);
    return;
  }
  *unaff_EDI = 0;
  FUN_004026e0(iVar2,0,0xffffffff);
  return;
}

