
undefined4 FUN_00865240(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *unaff_ESI;
  
  iVar2 = param_5;
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  if ((iVar2 == 1) || (iVar2 == 0x200)) {
    iVar3 = FUN_00864e70(3);
    if (iVar3 == 0) {
      OutputDebugStringA(
                        "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                        );
      in_EAX = 0x15;
    }
    param_5 = 0;
    iVar3 = D3DXCreateTexture(param_1,param_2,param_3,param_4,iVar2,in_EAX,0,&param_5);
    if (iVar3 < 0) {
      return 0;
    }
    *unaff_ESI = param_5;
    unaff_ESI[1] = param_2;
    unaff_ESI[2] = param_3;
    unaff_ESI[4] = param_4;
    unaff_ESI[6] = in_EAX;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 1;
    unaff_ESI[5] = iVar2;
    unaff_ESI[10] = 0;
  }
  return 1;
}

