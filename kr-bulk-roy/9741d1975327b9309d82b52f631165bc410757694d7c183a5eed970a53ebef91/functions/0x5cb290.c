
void FUN_005cb290(undefined4 param_1)

{
  undefined4 *in_ECX;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x38) != 0) {
    FUN_00775260(*(undefined4 *)(unaff_EDI + 0x44),param_1,*in_ECX,in_ECX[1],in_ECX[2],in_ECX[3],
                 0x3f800000,0x3f800000);
    FUN_00775450();
  }
  return;
}

