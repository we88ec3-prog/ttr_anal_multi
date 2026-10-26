
void FUN_008653c0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_140 [78];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  if (param_5 == 0x200) {
    (**(code **)(*unaff_EDI + 0x1c))();
    iVar2 = FUN_00864e70(4,param_6);
    if (iVar2 == 0) {
      OutputDebugStringA(
                        "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                        );
      param_6 = 0x15;
    }
    local_140[0] = 0;
    iVar2 = D3DXCreateVolumeTexture
                      (unaff_EDI,param_1,param_2,param_3,param_4,0x200,param_6,0,local_140);
    if (iVar2 < 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    unaff_ESI[1] = param_1;
    *unaff_ESI = local_140[0];
    unaff_ESI[4] = param_4;
    unaff_ESI[2] = param_2;
    unaff_ESI[3] = param_3;
    unaff_ESI[6] = param_6;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 3;
    unaff_ESI[5] = 0x200;
    unaff_ESI[10] = 0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

