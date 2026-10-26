
void FUN_00863590(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  int in_EDX;
  char *pcVar4;
  char *local_11c;
  undefined4 local_118;
  char local_114 [268];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_114 + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  local_11c = __strlwr(local_114);
  local_118 = 0;
  uVar3 = FUN_00863ac0(&local_11c);
  FUN_007e2910(in_EDX,&local_11c,uVar3);
  pcVar4 = local_11c + 0x28;
  if ((char)local_118 == '\0') {
    FUN_0083eb10();
  }
  else {
    FUN_00840590(in_EDX + 0x10,pcVar4);
  }
  FUN_00865120();
  *in_ECX = *(undefined4 *)pcVar4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

