
void FUN_00714c50(char *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  char local_10c;
  undefined1 local_10b [259];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _strcpy_s(&local_10c,0x104,param_1);
  puVar1 = (undefined1 *)FUN_007170d0(&local_10c);
  if (puVar1 == (undefined1 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *puVar1 = 0;
  if ((int)(puVar1 + 1) - (int)&local_10c == 1) {
    FUN_00714c50(local_10b,1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  piVar3 = (int *)**(int **)(in_ECX + 0x104);
  if (piVar3 != *(int **)(in_ECX + 0x104)) {
    do {
      iVar2 = __stricmp((char *)(piVar3 + 2),&local_10c);
      if (iVar2 == 0) {
        if ((piVar3[0x42] == 0) || (iVar2 = FUN_007155b0(), iVar2 == 0)) {
          FUN_00714c50(puVar1 + 1,1);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        break;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(in_ECX + 0x104));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

