
void FUN_00796e90(byte param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = IS3DX::CCameraWorks::vftable;
  FUN_00797a00();
  iVar1 = in_ECX[1];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

