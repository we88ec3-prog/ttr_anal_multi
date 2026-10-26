
void FUN_006699b0(undefined4 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_EDI;
  
  iVar1 = FUN_00539610(in_EAX,0);
  while (iVar1 != -1) {
    FUN_00498360(*(undefined4 *)(unaff_EDI + 0x10),param_1,0,0xffffffff);
    iVar1 = FUN_00539610(in_EAX,0);
  }
  return;
}

