
undefined4 FUN_00865300(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar2 = param_3;
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  if ((iVar2 == 1) || (iVar2 == 0x200)) {
    iVar3 = FUN_00864e70(5,param_4);
    if (iVar3 == 0) {
      OutputDebugStringA(
                        "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                        );
      param_4 = 0x15;
    }
    param_3 = 0;
    iVar3 = D3DXCreateCubeTexture(param_1,unaff_EDI,param_2,iVar2,unaff_ESI[6],0,&param_3);
    if (iVar3 < 0) {
      return 0;
    }
    unaff_ESI[4] = param_2;
    *unaff_ESI = param_3;
    unaff_ESI[1] = unaff_EDI;
    unaff_ESI[2] = unaff_EDI;
    unaff_ESI[6] = param_4;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 4;
    unaff_ESI[5] = iVar2;
    unaff_ESI[10] = 0;
  }
  return 1;
}

