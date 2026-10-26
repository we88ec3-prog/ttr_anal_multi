
undefined4 * FUN_0073cc60(undefined4 *param_1,undefined4 param_2,short *param_3,int param_4)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  int in_ECX;
  
  puVar2 = param_1;
  if (param_4 < 0) {
    psVar3 = param_3;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    param_4 = (int)psVar3 - (int)(param_3 + 1) >> 1;
  }
  param_1 = (undefined4 *)param_2;
  *puVar2 = 0;
  puVar2[1] = 0;
  FUN_008438c0(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x3c)) && (*(int *)(in_ECX + 0x10) != 0)) {
    FUN_0073da10(in_ECX + 0xc,*(int *)(in_ECX + 0x10),param_3,param_4,0,puVar2);
  }
  return puVar2;
}

