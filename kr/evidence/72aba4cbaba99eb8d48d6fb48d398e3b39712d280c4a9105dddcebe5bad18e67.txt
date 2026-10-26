
int FUN_0048aad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (int)(short)param_3;
  pcVar1 = (code *)in_ECX[iVar2 * 4 + 2];
  if (pcVar1 == (code *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 0xc))(param_1,param_2,param_3);
    return iVar2;
  }
  _strncmp((char *)in_ECX[iVar2 * 4 + 4],"PassTo",6);
  iVar3 = (*pcVar1)(param_1,param_2,param_3);
  if (iVar3 == -0x7fffbffb) {
    FUN_006edb60("Failed at %d (%s)",iVar2,in_ECX[iVar2 * 4 + 4]);
  }
  return iVar3;
}

