
void FUN_007b5980(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  int local_6c;
  undefined1 local_68 [4];
  int local_64;
  undefined1 local_5d;
  int local_5c;
  int local_58;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 *local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932419;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = param_1;
  local_64 = in_ECX;
  local_18 = uVar2;
  if (*(int *)(param_1 + 0xa4) != 0) {
    pcVar9 = (char *)(in_ECX + 0x10);
    if (0xf < *(uint *)(in_ECX + 0x24)) {
      pcVar9 = *(char **)pcVar9;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    pcVar3 = pcVar9;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar9,(int)pcVar3 - (int)(pcVar9 + 1));
    iVar11 = local_58;
    local_8 = 0;
    local_6c = FUN_007b6f30(local_34);
    if ((local_6c == *(int *)(iVar11 + 0xa0)) || (cVar1 = FUN_0049ae30(), cVar1 != '\0')) {
      local_5c = *(int *)(iVar11 + 0xa0);
      piVar6 = &local_5c;
    }
    else {
      piVar6 = &local_6c;
    }
    iVar4 = *piVar6;
    local_8 = 0xffffffff;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    if (iVar4 != *(int *)(iVar11 + 0xa0)) {
      if (*(int *)(*(int *)(iVar4 + 0x28) + 0x20) == 0) {
        piVar6 = *(int **)(iVar11 + 0xac);
        piVar10 = (int *)*piVar6;
        local_5c = iVar11 + 0xac;
        if (piVar10 != piVar6) {
          do {
            cVar1 = FUN_006ddb50();
            if (cVar1 != '\0') {
              FUN_00719b20(&local_64,piVar10);
              goto LAB_007b5ad0;
            }
            piVar10 = (int *)*piVar10;
          } while (piVar10 != piVar6);
          piVar6 = (int *)(*(int *)(iVar4 + 0x28) + 0x20);
          *piVar6 = *piVar6 + 1;
          goto LAB_007b5c64;
        }
      }
LAB_007b5ad0:
      piVar6 = (int *)(*(int *)(iVar4 + 0x28) + 0x20);
      *piVar6 = *piVar6 + 1;
      goto LAB_007b5c64;
    }
  }
  iVar11 = local_64;
  pcVar9 = (char *)(local_64 + 0x10);
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8 = 1;
    FUN_007d0fb0(&local_5d);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    local_8 = 0xffffffff;
  }
  iVar4 = FUN_007d0920(0);
  if (iVar4 != 0) {
    if ((*(int *)(iVar11 + 0xc) != 0) && (*(int *)(iVar4 + 0xdc) - *(int *)(iVar4 + 0xd8) >> 2 != 0)
       ) {
      iVar5 = FUN_00434740(uVar2);
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x44));
      local_64 = FUN_00891268(0xe8);
      local_8 = 2;
      if (local_64 == 0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)FUN_0077ebb0();
      }
      local_8 = 0xffffffff;
      (**(code **)(*piVar6 + 0x40))(iVar4);
      iVar4 = FUN_00434740();
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x44));
    }
    puVar7 = (undefined4 *)FUN_00891268(0x24);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7[1] = 0;
      *puVar7 = 0;
      InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(puVar7 + 2),4000);
      puVar7[8] = 0;
    }
    FUN_007db4a0();
    puVar7[8] = 1;
    if (0xf < *(uint *)(iVar11 + 0x24)) {
      pcVar9 = *(char **)pcVar9;
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54[0] = local_54[0] & 0xffffff00;
    pcVar3 = pcVar9;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar9,(int)pcVar3 - (int)(pcVar9 + 1));
    iVar11 = local_58 + 0x9c;
    local_8 = 3;
    local_38 = puVar7;
    uVar8 = FUN_00552de0(local_54);
    FUN_007e2910(iVar11,local_68,uVar8);
    if (0xf < local_40) {
      FUN_0089120c(local_54[0]);
    }
  }
LAB_007b5c64:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

