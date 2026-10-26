
void FUN_00865190(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  undefined1 local_24 [20];
  int local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (unaff_EDI != 0) {
    piVar1 = (int *)*unaff_ESI;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *unaff_ESI = 0;
    }
    iVar2 = D3DXGetImageInfoFromFileA(unaff_EDI,local_24);
    if (-1 < iVar2) {
      if (local_10 == 3) {
        iVar2 = D3DXCreateTextureFromFileA(param_1,unaff_EDI,unaff_ESI);
        unaff_ESI[8] = 1;
      }
      else if (local_10 == 4) {
        iVar2 = D3DXCreateVolumeTextureFromFileA(param_1,unaff_EDI,unaff_ESI);
        unaff_ESI[8] = 3;
      }
      else {
        if (local_10 != 5) goto LAB_00865227;
        iVar2 = D3DXCreateCubeTextureFromFileA(param_1,unaff_EDI,unaff_ESI);
        unaff_ESI[8] = 4;
      }
      if (iVar2 == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_00865227:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

