
void FUN_00709b00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  double *pdVar3;
  char *pcVar4;
  undefined1 auStack_3c [4];
  longlong local_38;
  tm local_30;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_3c;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (((puVar2 <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || ((int)puVar1[2] < 1)) {
    local_38 = __time64((__time64_t *)0x0);
    goto LAB_00709c50;
  }
  if (puVar1 < puVar2) {
    if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] != 5)) {
      if ((puVar2 <= puVar1) || ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_00709b66;
      pcVar4 = (&PTR_DAT_00c0be1c)[puVar1[2]];
      goto LAB_00709b74;
    }
  }
  else {
LAB_00709b66:
    pcVar4 = "no value";
LAB_00709b74:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar4);
    FUN_006f5da0(1);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x10;
  local_30.tm_sec = FUN_00709700(param_1,&DAT_00c43978,0);
  local_30.tm_min = FUN_00709700(param_1,&DAT_00c0fb84,0);
  local_30.tm_hour = FUN_00709700(param_1,&DAT_00c4397c,0xc);
  local_30.tm_mday = FUN_00709700(param_1,&DAT_00c43984,0xffffffff);
  local_30.tm_mon = FUN_00709700(param_1,"month",0xffffffff);
  local_30.tm_mon = local_30.tm_mon + -1;
  local_30.tm_year = FUN_00709700(param_1,&DAT_00c43990,0xffffffff);
  local_30.tm_year = local_30.tm_year + -0x76c;
  local_30.tm_isdst = FUN_00709670();
  local_38 = __mktime64(&local_30);
LAB_00709c50:
  pdVar3 = *(double **)(param_1 + 8);
  if (local_38 == -1) {
    *(undefined4 *)(pdVar3 + 1) = 0;
  }
  else {
    *(undefined4 *)(pdVar3 + 1) = 3;
    *pdVar3 = (double)local_38;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  __security_check_cookie(local_c ^ (uint)auStack_3c);
  return;
}

