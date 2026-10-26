
int FUN_004c4670(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = (int)(short)param_3;
  pcVar1 = *(code **)(in_ECX + 0x5eac + iVar3 * 8);
  if (pcVar1 == (code *)0x0) {
    iVar3 = FUN_004fda30(param_1,param_2,param_3);
    return iVar3;
  }
  _strncmp(*(char **)(in_ECX + 0x5eb0 + iVar3 * 8),"PassTo",6);
  iVar2 = (*pcVar1)(param_1,param_2,param_3);
  if (iVar2 == -0x7fffbffb) {
    FUN_006edb60("Failed at %d (%s)",iVar3,*(undefined4 *)(in_ECX + 0x5eb0 + iVar3 * 8));
  }
  return iVar2;
}

