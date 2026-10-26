
void FUN_00864100(int param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_ECX;
  undefined4 in_EDX;
  char *pcVar4;
  char *local_114;
  undefined4 local_110;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_10c + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  local_114 = __strlwr(local_10c);
  local_110 = 0;
  uVar2 = FUN_00863ac0(&local_114);
  FUN_007e2910(param_1,&local_114,uVar2);
  pcVar4 = local_114 + 0x28;
  if ((char)local_110 == '\0') {
    iVar3 = FUN_00840100(param_1 + 0x10,*(undefined4 *)pcVar4);
    FUN_00843240(iVar3,in_EDX);
    if (*(int *)(iVar3 + 0x110) != 0) goto LAB_008641d2;
  }
  else {
    iVar3 = FUN_008407e0(param_1 + 0x10);
    FUN_00843240(iVar3,in_EDX);
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_008433e0(iVar3,*(int *)(param_1 + 0x40));
  }
LAB_008641d2:
  *in_ECX = *(undefined4 *)pcVar4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

