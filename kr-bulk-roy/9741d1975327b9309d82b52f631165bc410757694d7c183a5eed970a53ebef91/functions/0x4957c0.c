
void FUN_004957c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_42;
  wchar_t local_3e [10];
  undefined2 local_2a;
  char local_28 [5];
  undefined4 local_23;
  wchar_t local_1f [11];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = (**(code **)(*DAT_00fba854 + 0x18))(param_1,0x20e0,0,2);
  iVar2 = (**(code **)(*DAT_00fba854 + 0x18))(param_1,0x20de,2,2);
  if (iVar1 == 0) {
    FUN_006edb60("Failed to connect game server");
    if (iVar2 != 0) {
      (**(code **)(*DAT_00fba854 + 0x20))(2,1);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    if (iVar2 != 0) {
      if (*(int *)(unaff_ESI + 0xbf60) != 0) {
        piVar3 = (int *)FUN_0044d680();
        if ((int *)*piVar3 != (int *)0x0) {
          (**(code **)(*(int *)*piVar3 + 0x18))();
        }
        FUN_008063e0(*(undefined4 *)(unaff_ESI + 0xbf60));
        local_46 = 0x7e;
        FUN_008060d0(&local_46,2);
        *(undefined4 *)(*(int *)(unaff_ESI + 0xbf60) + 0xa0b0) = 1;
        *(undefined4 *)(unaff_ESI + 0xbf60) = 0;
      }
      Sleep(400);
      local_44 = 1;
      local_3e[0] = L'\0';
      local_3e[1] = L'\0';
      local_3e[2] = L'\0';
      local_3e[3] = L'\0';
      local_3e[4] = L'\0';
      local_3e[5] = L'\0';
      local_3e[6] = L'\0';
      local_3e[7] = L'\0';
      local_3e[8] = L'\0';
      local_3e[9] = L'\0';
      local_2a = 1;
      local_28[0] = '\0';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      local_28[4] = 0;
      local_23 = 0;
      local_1f[0] = L'\0';
      local_1f[1] = L'\0';
      local_1f[2] = L'\0';
      local_1f[3] = L'\0';
      local_1f[4] = L'\0';
      local_1f[5] = L'\0';
      local_1f[6] = L'\0';
      local_1f[7] = L'\0';
      local_1f[8] = L'\0';
      local_1f[9] = L'\0';
      iVar4 = FUN_00404ba0();
      local_42 = *(undefined4 *)(iVar4 + 0x67e0);
      iVar4 = FUN_00404ba0();
      _wcsncpy_s(local_3e,10,(wchar_t *)(iVar4 + 0x67e4),10);
      iVar4 = FUN_00404ba0();
      _wcsncpy_s(local_1f,10,(wchar_t *)(iVar4 + 0x67fa),10);
      local_2a = CONCAT11(local_2a._1_1_,1);
      iVar4 = FUN_00404ba0();
      local_2a = CONCAT11(*(undefined1 *)(iVar4 + 0x6898),(undefined1)local_2a);
      iVar4 = FUN_00404ba0();
      _strcpy_s(local_28,5,(char *)(iVar4 + 0x6899));
      iVar4 = FUN_00404ba0();
      local_23 = *(undefined4 *)(iVar4 + 0x68a0);
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_44,0x39);
      (**(code **)(*DAT_00fba854 + 0x14))(iVar1);
      (**(code **)(*DAT_00fba854 + 0x14))(iVar2);
      *(int *)(unaff_ESI + 0xbf64) = iVar1;
      *(int *)(unaff_ESI + 49000) = iVar2;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(*DAT_00fba854 + 0x20))(0,1);
  }
  FUN_006edb60("Failed to connect bridge server");
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

