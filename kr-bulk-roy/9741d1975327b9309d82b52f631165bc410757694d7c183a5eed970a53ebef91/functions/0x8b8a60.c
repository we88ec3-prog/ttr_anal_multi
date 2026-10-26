
int FUN_008b8a60(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    return 0x23;
  }
  if ((((param_2 == (int *)0x0) || (param_2[1] < 0)) || (param_2[2] < 0)) || (4 < *param_2)) {
    iVar3 = 6;
  }
  else {
    pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x58);
    if (pcVar1 != (code *)0x0) {
      iVar2 = (*pcVar1)(*(undefined4 *)(param_1 + 0x58),param_2);
      return iVar2;
    }
    if (((*(uint *)(param_1 + 8) & 1) != 0) || ((*(uint *)(param_1 + 8) & 2) == 0)) {
      FUN_008b8800(param_1,param_2);
      return 0;
    }
    iVar3 = FUN_008b85a0(param_1,param_2,0,&param_1);
    if (iVar3 == 0) {
      iVar2 = FUN_008b8a10(iVar2,param_1);
      return iVar2;
    }
  }
  return iVar3;
}

