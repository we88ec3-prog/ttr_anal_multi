
void FUN_007bdf90(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int in_ECX;
  int local_3c;
  int local_38;
  int *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918ab6;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = *(int **)(in_ECX + 4);
  local_38 = in_ECX;
  local_14 = uVar5;
  if (local_34 != *(int **)(in_ECX + 8)) {
    do {
      iVar2 = *local_34;
      if ((DAT_00fe1770 & 1) == 0) {
        DAT_00fe1770 = DAT_00fe1770 | 1;
        local_8 = 0;
        FUN_007b7da0(uVar5);
        _atexit((_func_4879 *)&LAB_00bce790);
        local_8 = 0xffffffff;
      }
      iVar4 = DAT_00fe173c;
      pcVar3 = *(char **)(iVar2 + 4);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar6 = pcVar3;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));
      local_8 = 1;
      FUN_007b86f0(&local_3c,local_30);
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      if ((local_3c != *(int *)(iVar4 + 4)) && (*(int **)(local_3c + 0x24) != (int *)0x0)) {
        uVar7 = (**(code **)(**(int **)(local_3c + 0x24) + 0x10))();
        *(undefined4 *)(iVar2 + 8) = uVar7;
      }
      if (*(int *)(iVar2 + 8) == 0) {
        MessageBoxA((HWND)0x0,"Effect Element Not Exist!",*(LPCSTR *)(iVar2 + 4),0);
      }
      local_34 = local_34 + 1;
      in_ECX = local_38;
    } while (local_34 != *(int **)(local_38 + 8));
  }
  FUN_007be150(in_ECX);
  *(undefined4 *)(in_ECX + 0x74) = 1;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

