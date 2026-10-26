
bool FUN_008658f0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  unaff_ESI[3] = param_2;
  unaff_ESI[4] = param_3;
  unaff_ESI[6] = param_5;
  unaff_ESI[5] = param_4;
  unaff_ESI[1] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[7] = param_6;
  unaff_ESI[2] = 1;
  unaff_ESI[8] = unaff_EDI;
  iVar2 = (**(code **)(*param_1 + 0x70))(param_1,param_2,param_3,param_4,param_5,param_6);
  return -1 < iVar2;
}

