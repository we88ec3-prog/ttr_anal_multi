
undefined4
FUN_0073c8e0(undefined4 param_1,short *param_2,undefined4 param_3,void *param_4,undefined4 *param_5)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_14;
  int local_10 [3];
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  psVar2 = param_2;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  iVar3 = (int)psVar2 - (int)(param_2 + 1) >> 1;
  if (param_4 != (void *)0x0) {
    _memset(param_4,0,iVar3 * 4);
  }
  local_14 = param_1;
  FUN_008438c0(&local_14);
  if ((local_10[0] != *(int *)(in_ECX + 0x3c)) && (*(int *)(local_10[0] + 0x10) != 0)) {
    FUN_0073da10(in_ECX + 0xc,*(int *)(local_10[0] + 0x10),param_2,iVar3,param_4,local_10);
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  return 1;
}

