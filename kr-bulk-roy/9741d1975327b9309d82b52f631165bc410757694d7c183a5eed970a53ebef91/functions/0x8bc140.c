
int FUN_008bc140(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = param_1;
  if (param_1 == 0) {
    return 6;
  }
  piVar3 = (int *)FUN_008baee0(param_1,0xc0,&param_1);
  if (param_1 == 0) {
    *piVar3 = iVar1;
    piVar3[0x2a] = 0x4000;
    iVar4 = FUN_008baee0(iVar1,0x4000,&param_1);
    iVar2 = param_1;
    piVar3[0x29] = iVar4;
    if (param_1 != 0) {
      FUN_008b9f80(iVar1,piVar3);
      return iVar2;
    }
    piVar3[1] = 2;
    piVar3[2] = 5;
    piVar3[3] = 3;
    piVar3[0x2f] = 1;
    *param_2 = (int)piVar3;
    param_1 = 0;
  }
  return param_1;
}

