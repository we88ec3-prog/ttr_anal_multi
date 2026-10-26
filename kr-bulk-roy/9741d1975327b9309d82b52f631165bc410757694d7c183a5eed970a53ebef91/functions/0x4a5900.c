
void FUN_004a5900(uint param_1)

{
  int iVar1;
  uint in_EAX;
  int in_ECX;
  int unaff_EDI;
  
  if (param_1 == 0) {
    param_1 = in_EAX & 0xffff;
    iVar1 = *(int *)(unaff_EDI + 0x108);
    FUN_004a4cc0(&param_1);
    if (in_ECX != *(int *)(iVar1 + 4)) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    }
    FUN_004a5520(unaff_EDI);
  }
  param_1 = CONCAT22(param_1._2_2_,0xf2);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,2);
  }
  return;
}

