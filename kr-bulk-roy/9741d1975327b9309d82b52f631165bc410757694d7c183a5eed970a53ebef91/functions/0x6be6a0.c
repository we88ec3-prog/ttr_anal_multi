
void FUN_006be6a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    if (in_ECX[0x92] != -1) {
      (**(code **)(*in_ECX + 0x54))();
      iVar1 = in_ECX[0x95];
      if (iVar1 == 0) {
        iVar1 = in_ECX[0x92];
        iVar2 = in_ECX[0x93];
        piVar3 = (int *)FUN_005984f0();
        FUN_006be950(iVar1,(char)iVar2);
      }
      else {
        if (iVar1 != 1) {
          if (iVar1 != 2) {
            return;
          }
          iVar1 = in_ECX[0x92];
          piVar3 = (int *)FUN_00598670();
          if (*piVar3 != 0) {
            FUN_00463510(*piVar3,(short)iVar1);
          }
          (**(code **)(*in_ECX + 0x50))(*piVar3);
          return;
        }
        iVar1 = in_ECX[0x93];
        piVar3 = (int *)FUN_00598640();
        if (*piVar3 != 0) {
          FUN_006c9cd0(*piVar3,(char)iVar1);
          (**(code **)(*in_ECX + 0x50))(*piVar3);
          return;
        }
      }
      (**(code **)(*in_ECX + 0x50))(*piVar3);
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
    return;
  }
  return;
}

