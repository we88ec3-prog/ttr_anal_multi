
void FUN_0073a110(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  FUN_0073b090(unaff_ESI);
  *unaff_ESI = Graphics::CRenderTargetTexture::vftable;
  unaff_ESI[1] = Graphics::CRenderTargetTexture::vftable;
  unaff_ESI[2] = Graphics::CRenderTargetTexture::vftable;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x26] = param_2;
  unaff_ESI[0x12] = 0x1a;
  unaff_ESI[0x25] = 1;
  unaff_ESI[0x27] = param_3;
  iVar1 = 1;
  do {
    iVar1 = iVar1 * 2;
  } while (iVar1 < unaff_EDI);
  unaff_ESI[3] = iVar1;
  iVar1 = 1;
  do {
    iVar1 = iVar1 * 2;
  } while (iVar1 < param_1);
  unaff_ESI[4] = iVar1;
  return;
}

