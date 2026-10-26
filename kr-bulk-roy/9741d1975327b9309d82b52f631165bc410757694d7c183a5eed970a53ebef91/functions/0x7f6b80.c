
void FUN_007f6b80(void)

{
  int iVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  LPCSTR lpText;
  int local_6c [13];
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092a4ac;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_6c;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x20) != 0) goto LAB_007f6d48;
  lpText = (LPCSTR)(in_ECX + 4);
  pCVar2 = lpText;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    pCVar2 = *(LPCSTR *)lpText;
  }
  local_6c[0] = in_ECX;
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_c = 0;
    FUN_00716be0(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
  }
  local_c = 0xffffffff;
  iVar1 = FUN_00716740(pCVar2);
  FUN_00718cf0();
  local_c = 1;
  if (iVar1 == 0) {
    FUN_00718fb0("*.ptc",&DAT_00c0cec8,1);
    pCVar2 = lpText;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      pCVar2 = *(LPCSTR *)lpText;
    }
    iVar1 = FUN_007197e0(pCVar2);
    if (iVar1 != 0) goto LAB_007f6c86;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      lpText = *(LPCSTR *)lpText;
    }
    MessageBoxA((HWND)0x0,lpText,&DAT_00c50ccc,0);
    *(undefined4 *)(local_6c[0] + 0x20) = 0;
  }
  else {
LAB_007f6c86:
    puVar3 = (undefined4 *)FUN_0079c590();
    if (0xf < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    if ((DAT_00fe324c & 1) == 0) {
      DAT_00fe324c = DAT_00fe324c | 1;
      local_c._0_1_ = 3;
      FUN_007cdeb0();
      _atexit((_func_4879 *)&LAB_00bd09b0);
    }
    local_c._0_1_ = 2;
    iVar4 = FUN_007ce0a0(&DAT_00fe3250,puVar3);
    local_c = CONCAT31(local_c._1_3_,1);
    if (0xf < local_24) {
      FUN_0089120c(local_38);
    }
    if (iVar4 != 0) {
      piVar5 = (int *)(iVar1 + 0x1c);
      if (0xf < *(uint *)(iVar1 + 0x30)) {
        piVar5 = (int *)*piVar5;
      }
      FUN_007cde40(piVar5);
      FUN_007edb70(piVar5);
      uVar6 = FUN_00798d00();
      FUN_007cfa70(uVar6);
      *(undefined4 *)(local_6c[0] + 0x20) = 1;
    }
  }
  FUN_00718dd0();
LAB_007f6d48:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_6c);
  return;
}

