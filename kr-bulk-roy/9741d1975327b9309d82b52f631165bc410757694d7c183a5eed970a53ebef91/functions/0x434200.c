
void FUN_00434200(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  unaff_ESI[1] = IS3DX::CCameraWorks::vftable;
  FUN_00797a00();
  iVar1 = unaff_ESI[2];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  *unaff_ESI = CameraWorks::ICameraWorks::vftable;
  return;
}

