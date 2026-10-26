
void FUN_00790010(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = in_EAX;
  while( true ) {
    iVar1 = iVar2 * 2;
    iVar2 = iVar1 + 2;
    if (param_1 <= iVar2) break;
    if (*(int *)(unaff_EDI + 0x14 + iVar2 * 0x3c) < *(int *)(unaff_EDI + -0x28 + iVar2 * 0x3c)) {
      iVar2 = iVar1 + 1;
    }
    FUN_00789f20();
  }
  if (iVar2 == param_1) {
    FUN_00789f20();
  }
  FUN_00790810(in_EAX,param_2,param_3);
  return;
}

