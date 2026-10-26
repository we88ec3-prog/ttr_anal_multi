
void FUN_00863c20(int param_1,char *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_EDX;
  char *pcVar4;
  undefined1 auStack_12c [4];
  char *local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 *local_11c;
  char local_118 [268];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_12c;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_118 + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  local_120 = in_EDX;
  local_128 = __strlwr(local_118);
  local_124 = 0;
  uVar2 = FUN_00863ac0(&local_128);
  FUN_007e2910(param_1,&local_128,uVar2);
  pcVar4 = local_128 + 0x28;
  if ((char)local_124 == '\0') {
    iVar3 = FUN_0083ff20(param_1 + 0x10,*(undefined4 *)pcVar4);
    if ((iVar3 == 0) || (param_3 == (int *)0x0)) goto LAB_00863cfe;
    FUN_0085a440(iVar3);
    *(int **)(iVar3 + 4) = param_3;
    (**(code **)(*param_3 + 4))(param_3);
  }
  else {
    iVar3 = FUN_008406d0(param_1 + 0x10,pcVar4);
    if (param_3 == (int *)0x0) goto LAB_00863cfe;
    FUN_0085a440(iVar3);
    *(int **)(iVar3 + 4) = param_3;
    (**(code **)(*param_3 + 4))(param_3);
  }
  iVar3 = FUN_0085bc60(local_120);
  if (iVar3 != 0) {
    FUN_0085bae0();
  }
LAB_00863cfe:
  *local_11c = *(undefined4 *)pcVar4;
  __security_check_cookie(local_c ^ (uint)auStack_12c);
  return;
}

