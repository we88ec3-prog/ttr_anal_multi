
void FUN_0071b910(int *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined1 local_50 [72];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *(int *)(param_4 + 0x28) = param_2;
  if (param_3 == 0) {
    param_1[2] = 0;
    *param_1 = 0;
    param_1[1] = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_5c = *(undefined4 *)(param_4 + 0x20);
  local_58 = *(undefined4 *)(param_4 + 0x24);
  local_54 = 0;
  cVar1 = *(char *)(param_3 + -1 + param_2);
  *(undefined1 *)(param_3 + -1 + param_2) = 0;
  iVar2 = __setjmp3(local_50,0);
  if (iVar2 == 0) {
    FUN_0071b390(&local_5c,param_4,0x377,cVar1);
  }
  if (local_54 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = local_54 - param_2;
  }
  if (param_4 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)(param_4 + 0x20);
  }
  *puVar3 = local_5c;
  puVar3[1] = local_58;
  if ((iVar2 == 0) && (cVar1 == '<')) {
    param_1[2] = 0;
    *param_1 = 5;
    param_1[1] = param_3;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_1 = iVar2;
  param_1[1] = param_2;
  param_1[2] = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

