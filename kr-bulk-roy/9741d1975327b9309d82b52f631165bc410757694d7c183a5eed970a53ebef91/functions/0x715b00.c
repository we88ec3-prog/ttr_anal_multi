
void FUN_00715b00(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (*(undefined4 **)(unaff_EDI + 0x118) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x118))(1);
    *(undefined4 *)(unaff_EDI + 0x118) = 0;
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(unaff_EDI + 0x124) + 4));
  *(int *)(*(int *)(unaff_EDI + 0x124) + 4) = *(int *)(unaff_EDI + 0x124);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 0x124) = *(undefined4 *)(unaff_EDI + 0x124);
  *(int *)(*(int *)(unaff_EDI + 0x124) + 8) = *(int *)(unaff_EDI + 0x124);
  *(undefined4 *)(unaff_EDI + 0x128) = 0;
  if (*(int *)(unaff_EDI + 0x138) != 0) {
    (**(code **)**(undefined4 **)(*(int *)(unaff_EDI + 0x138) + 0x24))(0);
    iVar1 = *(int *)(unaff_EDI + 0x138);
    if (iVar1 != 0) {
      FUN_007185a0(iVar1);
      FUN_0089120c(iVar1);
      *(undefined4 *)(unaff_EDI + 0x138) = 0;
    }
  }
  return;
}

