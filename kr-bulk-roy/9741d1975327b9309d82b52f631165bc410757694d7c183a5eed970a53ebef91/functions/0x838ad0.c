
undefined4 FUN_00838ad0(uint param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  undefined4 uVar5;
  
  piVar3 = param_2;
  *param_2 = 0;
  param_2 = (int *)0x0;
  if ((uint)in_ECX[3] < param_1) {
    pcVar1 = *(code **)(*in_ECX + 8);
    in_ECX[3] = param_1;
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      return 0;
    }
  }
  piVar2 = (int *)in_ECX[2];
  if (piVar2 != (int *)0x0) {
    uVar5 = 0x1800;
    if ((in_ECX[4] == 0) || ((uint)in_ECX[3] < in_ECX[4] + param_1)) {
      in_ECX[4] = 0;
      uVar5 = 0x2800;
    }
    iVar4 = (**(code **)(*piVar2 + 0x2c))(piVar2,in_ECX[4],param_1,&param_2,uVar5);
    if (iVar4 == 0) {
      in_ECX[5] = 1;
      *piVar3 = in_ECX[4];
      in_ECX[4] = in_ECX[4] + param_1;
    }
  }
  return param_2;
}

