
void FUN_008654c0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_24 [3];
  int local_18;
  int local_14;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  if ((param_3 != 1) && (param_3 != 0x200)) {
LAB_008655c9:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar2 = FUN_00864e70(3,param_4);
  if (iVar2 == 0) {
    OutputDebugStringA(
                      "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                      );
    param_4 = 0x15;
  }
  iVar2 = (**(code **)(*unaff_EDI + 0xc0))();
  if (-1 < iVar2) {
    uVar3 = FUN_008fed10();
    uVar4 = FUN_008fed10();
    local_24[0] = 0;
    iVar2 = D3DXCreateTexture(unaff_EDI,uVar3,uVar4,1,param_3,param_4,0,local_24);
    if (-1 < iVar2) {
      unaff_ESI[0xb] = param_1;
      *unaff_ESI = local_24[0];
      unaff_ESI[0xc] = param_2;
      unaff_ESI[1] = local_18;
      unaff_ESI[2] = local_14;
      unaff_ESI[4] = 1;
      unaff_ESI[6] = param_4;
      unaff_ESI[7] = 0;
      unaff_ESI[8] = 1;
      unaff_ESI[5] = param_3;
      unaff_ESI[10] = 1;
      goto LAB_008655c9;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

