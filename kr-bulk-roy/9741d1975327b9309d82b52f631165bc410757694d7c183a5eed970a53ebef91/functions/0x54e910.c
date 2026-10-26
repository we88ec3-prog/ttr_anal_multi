
void FUN_0054e910(byte param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  
  in_ECX[1] = IS3DX::CCameraWorks::vftable;
  FUN_00797a00();
  iVar1 = in_ECX[2];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = CameraWorks::ICameraWorks::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

